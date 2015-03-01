#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>

#include "Level.h"
#include "Map.h"
#include "Player.h"
#include "NBT_Debug.h"
#include "NBT.h"
#include "NBT_Tag_Compound.h"

Level::Level() : level_nbt(0) { }

Level::~Level()
{
	delete level_nbt;
	level_nbt = 0;

	for(auto &map: maps_)
	{
		delete map;
	}

	maps_.clear();
}

bool Level::load(const std::string &path)
{
	path_ = path;

	if(!dimensionScan(path))
		return false;

	for(auto &map: maps_)
	{
		if(!map->load())
		{
			//NBT_Error("failed to load dimension at %s", map->mapPath().c_str());
		}
	}

	return true;
}

Map *Level::getMap(int id)
{
	for(auto map: maps_)
	{
		if(map->dimension() == id)
			return map;
	}

	return nullptr;
}

Map *Level::getMap(const std::string &name)
{
	for(auto map: maps_)
	{
		if(map->mapName() == name)
			return map;
	}

	return nullptr;
}


struct DirPair
{
	DirPair(const std::string &name, const std::string &path, DIR *dh) : name(name), path(path), dh(dh) { }
	std::string name;
	std::string path;
	DIR *dh;
};

NBT *find_level_dat(const std::string &path)
{
	NBT *nbt = 0;

	int i = 2;
	size_t pos = path.size();
	while(i--)
	{
		pos = path.find_last_of("/\\", pos-1);
		//NBT_Debug("pos:%i", pos);
		if(pos == std::string::npos)
		{
			//NBT_Debug("delim not found");
			break;
		}

		std::string level_dat_path = path.substr(0, pos+1) + "level.dat";
		NBT_Debug("trying to load %s", level_dat_path.c_str());

		NBT *new_nbt = new NBT();
		if(new_nbt->load(level_dat_path))
		{
			NBT_Debug("OK!");
			printf("dump:\n%s\n", new_nbt->serialize().c_str());
			nbt = new_nbt;
			break;
		}
	}

	return nbt;
}

bool Level::dimensionScan(const std::string &path)
{
	DIR *dh = opendir(path.c_str());
	if(!dh)
	{
		NBT_Error("failed to open level directory for dimension scan.");
		delete level_nbt;
		return false;
	}

	struct dirent *ent = 0;
	std::vector<DirPair> dir_queue;

	// complicated shenanigans to locate all dimensions
	// various server mods like bukkit don't agree on dimension locations
	// instead of hardcoding support for layouts, just do a breadth first search
	// for .mca files.

	DirPair dp("unk", path, dh);
	bool load_players = false;
	Map *curMap = 0;
	std::string mapName;

	while(1)
	{
		ent = readdir(dp.dh);
		while(!ent)
		{
			if(!dir_queue.empty())
			{
				load_players = false;
				dp = dir_queue.back();
				dir_queue.pop_back();
				ent = readdir(dp.dh);

				if(dp.name != "region")
				{
					curMap = 0;
					delete level_nbt;
					level_nbt = 0;
				}
				//NBT_Debug("back to %s", dp.path.c_str());
			}
			else
				// escape if the queue is empty
				goto ESCAPE;
		}

		// skip hidden files
		if(ent->d_name[0] == '.')
			continue;

		struct stat st;

		std::string fpath = dp.path;
		fpath += "/";
		fpath += ent->d_name;

		//NBT_Debug("scan: %s", fpath.c_str());

		if(stat(fpath.c_str(), &st) != 0)
		{	// skip entries we can't stat
			continue;
		}

		if(S_ISDIR(st.st_mode))
		{
			DIR *sub_dh = opendir(fpath.c_str());
			// skip if we can't list it
			if(!sub_dh)
				continue;

			if(strcasecmp(ent->d_name, "players") == 0)
				load_players = true;

			dir_queue.push_back(dp);
			dp.dh = sub_dh;
			dp.path = fpath;
			dp.name = ent->d_name;
			//NBT_Debug("entering %s", fpath.c_str());
		}
		else
		{
			char *ext = strrchr(ent->d_name, '.');

			if(load_players)
			{
				if(ext && strcasecmp(ext, ".dat") == 0)
				{
					//NBT_Debug("found player at %s", fpath.c_str());
					Player *player = new Player(fpath);
					if(!player->load())
					{
						NBT_Error("failed to load player nbt data at %s", fpath.c_str());
						continue;
					}

					players_.push_back(player);
				}
			}
			else
			{
				if(ext && strcasecmp(ext, ".mca") == 0)
				{
					DirPair parent_dp = dir_queue.back();
					std::string level_name;

					NBT *level_dat = find_level_dat(dp.path);

					size_t dimpos = dp.path.find("DIM");
					if(dimpos != std::string::npos)
					{
						size_t epos = dp.path.find_first_of("/\\", dimpos);
						size_t spos = dp.path.find_last_of("/\\", dimpos);
						level_name = dp.path.substr(spos+1, epos-spos-1);
					}
					else
					{
						level_name = dp.name;
						if(level_dat)
						{
							level_name = level_dat->getString("LevelName");
						}
					}

					Map *map = curMap = new Map(dp.path, level_name, level_dat);
					maps_.push_back(map);

					dp = parent_dp;
					dir_queue.pop_back();
					continue;
				}
				else if(!level_nbt && strcasecmp(ent->d_name, "level.dat") == 0)
				{
					/*level_nbt = new NBT();
					if(!level_nbt->load(fpath))
					{
						//NBT_Error("failed to load level nbt data.");
						//return false;
						continue;
					}

					mapName = level_nbt->getString("LevelName");
					if(curMap)
						curMap->setName(mapName);
					*/
				}
			}
		}
	}

ESCAPE:

	return true;
}

std::string Level::levelName()
{
	return level_nbt->getString("LevelName");
}

std::vector<Player *> Level::dimensionPlayers(int32_t dim)
{
	std::vector<Player *> list;

	for(auto &player: players_)
	{
		if(player->dimension() == dim)
			list.push_back(player);
	}

	return list;
}
