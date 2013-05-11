#include <cstdio>
#include <dirent.h>
#include <cstring>
#include <cassert>
#include <cerrno>
#include <sstream>
#include <string>

#include "Map.h"
#include "Region.h"

Map::Map(const std::string &path) : map_path(path), iterator_pos(0)
{
	
}

Map::~Map()
{
   for(auto &region: data)
   {
      delete region;
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
		Region *new_region = new Region(ent_path);
		//printf("found region: %ix%i\n", new_region->x(), new_region->z());
		data.push_back(new_region);
		
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
	Region *region = firstRegion();
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

Region *Map::firstRegion()
{
	iterator_pos = 0;
	return data[iterator_pos++];
}

Region *Map::nextRegion()
{
	//assert((iterator_pos < data.size));
   if(iterator_pos >= data.size())
   {
      printf("Map::nextRegion: iterator_pos == %i BAIL\n", iterator_pos);
      return 0;
   }
	return data[iterator_pos++];
}
