#ifndef PLAYER_H_GUARD
#define PLAYER_H_GUARD

#include <string>

class NBT;
class Player
{
	public:
		Player(const std::string &path) : path(path) {}
		~Player();
		
		bool load();
		
		double xPos() { return x_pos; }
		double zPos() { return z_pos; }
		double yPos() { return y_pos; }
		
		double spawnX();
		double spawnZ();
		double spawnY();
		
		int32_t dimension();
		
	private:
		const std::string path;
		double x_pos, z_pos, y_pos;
		
		NBT *nbt;
};

#endif /* PLAYER_H_GUARD */
