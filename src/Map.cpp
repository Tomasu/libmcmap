#include <cstdio>
#include <dirent.h>
#include <cstring>
#include <cassert>
#include <cerrno>
#include <sstream>
#include <string>

#include "NBT_Debug.h"
#include "NBT.h"
#include "Map.h"
#include "MCRegion.h"
#include "PairHash.h"

Map::Map(const std::string &path, const std::string &name, NBT *level_nbt) : map_path(path), map_name(name), dimension_id(0), level_nbt(level_nbt)
{
	size_t pos = map_name.find_first_of("-0123456789");
	//NBT_Debug("pos: %i", pos);
	if(pos != std::string::npos)
	{
		std::string num = map_name.substr(pos);
		//NBT_Debug("num: %s", num.c_str());
		dimension_id = strtol(num.c_str(), 0, 0);
	}
	NBT_Debug("create map %s dimid:%i", map_name.c_str(), dimension_id);
}

Map::~Map()
{
   for(auto &region: data)
   {
      delete region.second;
   }

   data.clear();
}

bool Map::load()
{
	DIR *save_dir = opendir(map_path.c_str());
	if(!save_dir)
	{
		fprintf(stderr, "failed to load map: %s\n", strerror(errno));
		return false;
	}
	
	NBT_Debug("load map %s dimid:%i", map_name.c_str(), dimension_id);
	
	struct dirent *e;
	//int limit = 0;
	while((e = readdir(save_dir)))
	{
		// skip hidden files
		if(e->d_name[0] == '.')
			continue;
		
		
		std::string ent_path = map_path;
		
		ent_path.append("/");
		ent_path.append(e->d_name);
		
		size_t pos = ent_path.rfind(".mca", std::string::npos);
		NBT_Debug("ent_path: %s pos:%i", ent_path.c_str(), pos);
		
		if(pos == std::string::npos)
			continue;
		
		MCRegion *new_region = new MCRegion(ent_path);
		//printf("found region: %ix%i\n", new_region->x(), new_region->z());
		data.emplace(new_region->key(), new_region);
		
		//if(limit > 400)
		//	break;
		
		//limit++;
	}
	
	closedir(save_dir);
	
	return true;
}

bool Map::save()
{
	return saveTo(map_path);
}

bool Map::saveTo(const std::string &path)
{
	MCRegion *region = firstRegion();
	while(region != 0)
	{
		std::ostringstream fstr;
		fstr << path << "/" << "r." << region->x() << "." << region->z() << ".mca";
		std::string fpath = fstr.str();
		
		if(!region->save(fpath))
		{
			printf("failed to save region file: %s\n", fpath.c_str());
		}
		
		region = nextRegion();
	}
	
	return true;
}

MCRegion *Map::firstRegion()
{
	dataIterator_ = data.begin();
	return dataIterator_->second;
}

MCRegion *Map::nextRegion()
{
	//assert((iterator_pos < data.size));
	dataIterator_++;
	
   if(dataIterator_ == data.end())
   {
      //printf("Map::nextRegion: iterator_pos == %i BAIL\n", iterator_pos);
      return 0;
   }
	return dataIterator_->second;
}

MCRegion* Map::getRegion(int32_t x, int32_t z)
{
	auto it = data.find(MCRegion::Key(x, z));
	if(it == data.end() || it->second == nullptr)
	{
		NBT_Debug("region @ %ix%i not found in map", x, z);
		return nullptr;
	}
	
	return it->second;
}

MCRegion* Map::getRegionForChunk(int32_t x, int32_t z)
{
	return getRegion(x >> 5, z >> 5);
}

Chunk* Map::getChunk(int32_t x, int32_t z)
{
	MCRegion *region = getRegionForChunk(x, z);
	if(!region)
	{
		NBT_Debug("region not found");
		return nullptr;
	}
	
	if(!region->load())
	{
		NBT_Debug("region failed to load");
		return nullptr;
	}
	
	return region->getChunk(x, z);
}


int32_t Map::spawnX() { return level_nbt ? level_nbt->getInt("SpawnX") : 0; }
int32_t Map::spawnZ() { return level_nbt ? level_nbt->getInt("SpawnZ") : 0; }
int32_t Map::spawnY() { return level_nbt ? level_nbt->getInt("SpawnY") : 0; }
