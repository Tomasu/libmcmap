#ifndef LEVEL_H_GUARD
#define LEVEL_H_GUARD

#include <string>
#include <vector>

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
		
	private:
		std::string path_;
		NBT *level_nbt;
		std::vector<Map *> maps_;
		std::vector<Player *> players_;
		
		bool dimensionScan(const std::string &path);
};

#endif /* LEVEL_H_GUARD */
