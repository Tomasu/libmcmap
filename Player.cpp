#include "Player.h"
#include "NBT_Debug.h"
#include "NBT.h"
#include "NBT_Tag_List.h"
#include "NBT_Tag_Double.h"

Player::~Player()
{
	delete nbt;
}

bool Player::load()
{
	nbt = new NBT();
	if(!nbt->load(path))
	{
		NBT_Error("failed to load player nbt data.");
		return false;
	}
	
	NBT_Tag_List *pos = nbt->getList("Pos");
	if(!pos)
	{
		NBT_Error("player data is missing position info");
		return false;
	}
	
	x_pos = ((NBT_Tag_Double *)pos->itemAt(0))->value();
	y_pos = ((NBT_Tag_Double *)pos->itemAt(1))->value();
	z_pos = ((NBT_Tag_Double *)pos->itemAt(2))->value();
	
	return true;
}

double Player::spawnX()
{
	return nbt->getInt("SpawnX");
}

double Player::spawnZ()
{
	return nbt->getInt("SpawnZ");
}

double Player::spawnY()
{
	return nbt->getInt("SpawnY");
}

int32_t Player::dimension()
{
	return nbt->getInt("Dimension");
}