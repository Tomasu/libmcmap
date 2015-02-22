#ifndef LEVEL_H_GUARD
#define LEVEL_H_GUARD

#include <string>
#include <vector>
#include <unordered_map>
#include "rapidjson/document.h"

class NBT;
class NBT_Tag_Compound;

class Map;
class Player;
class Level
{
	public:
		Level();
		~Level();
		
		bool load(const std::string &path);
		
		std::string levelName();
		
		std::vector<Map *> &maps() { return maps_; }
		std::vector<Player *> &players() { return players_; }
		std::vector<Player *> dimensionPlayers(int32_t dim);
		
		// TODO: add getBlockState, getBlockAddress, getBlockInfo, etc
		//  probably move blockstate resolution/parsing to mcmap from mctools-viewer.
		//  might even move all of the model loading, and geometry generation here too.
		
		rapidjson::Document *getJson(const std::string &name);
		
	private:
		std::string path_;
		NBT *level_nbt;
		std::vector<Map *> maps_;
		std::vector<Player *> players_;
		
		std::unordered_map<std::string, rapidjson::Document*> jsonDocCache_;
		
		// TODO: add blockstate map...
		
		bool dimensionScan(const std::string &path);
};

#endif /* LEVEL_H_GUARD */
