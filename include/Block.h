#ifndef BLOCK_H_GUARD
#define BLOCK_H_GUARD

#include "BlockMaps.h"

struct BlockAddress
{
	BlockAddress(int32_t dimid = 0, int32_t ax = 0, int32_t ay = 0, int32_t az = 0) : dimension(dimid), x(ax), y(ay), z(az)
	{
		
		lx = x & 15;
		if(lx < 0) lx += 16; // if x is negative, add 16 to get non negative chunk local coords (0-15)
		
		lz = z & 15;
		if(lz < 0) lz += 16; // same as above
		
		ly = y & 15; // section local
		
		section = y / 16;
		
		idx = ly * 16 * 16 + lz * 16 + lx;
	}
	
	BlockAddress(const BlockAddress &addr)
	{
		dimension = addr.dimension;
		x = addr.x;
		y = addr.y;
		z = addr.z;
		lx = addr.lx;
		ly = addr.ly;
		lz = addr.lz;
		idx = addr.idx;
		section = addr.section;
	}
	
	bool isSane() const
	{
		return dimension >= -1 && dimension <= 1000 /* yay for arbitrary values */ && 
			lx >= 0 && lx < 16 &&
			ly >= 0 && ly < 16 &&
			lz >= 0 && lz < 16 &&
			idx >= 0 && idx < 4096 &&
			section >= 0 && section < 16;
	}
	
	BlockAddress &operator=(const BlockAddress &rhs)
	{
		dimension = rhs.dimension;
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		lx = rhs.lx;
		ly = rhs.ly;
		lz = rhs.lz;
		idx = rhs.idx;
		section = rhs.section;
		
		return *this;
	}
	
	bool operator==(const BlockAddress &rhs)
	{
		return isSane() && rhs.isSane() &&
			dimension == rhs.dimension && // if we ever want to compare two addresses between dimensions, we need to remove this check
			x == rhs.x && y == rhs.y && z == rhs.y;
	}
	
	BlockAddress up(uint32_t off = 1)
	{
		return BlockAddress(x, y + off, z);
	}
	
	int32_t dimension;
	int32_t x, y, z;
	
	// lx,lz are chunk local
	int32_t lx, lz;
	
	// ly is section local
	int32_t section, ly;
	
	// cache for chunk "Data" index
	int32_t idx;
};

struct BlockInfo
{
	BlockInfo() : addr(), id(BLOCK_AIR), data(0) { }
	
	BlockInfo(const BlockAddress &baddr, int32_t bid, int32_t bdata)
		: addr(baddr), id(bid), data(bdata) { }
	
	BlockInfo(const BlockInfo &b)
	{
		addr = b.addr;
		id = b.id;
		data = b.data;
	}
	
	BlockAddress addr;
	int32_t id, data;

	static uint8_t SID(const uint8_t *data, uint32_t idx)
	{
		return Nibble4(data, idx);
	}
	
	static uint32_t ID(const uint8_t *data, const uint8_t *add, uint32_t idx)
	{
		uint32_t blkid_a = data[idx];
		uint32_t blkid_b = Nibble4(add, idx);
		uint32_t blkid = blkid_a + (blkid_b << 8);
		
		return blkid;
	}
	
	private:
		static uint8_t Nibble4(const uint8_t *arr, uint32_t index) { if(!arr) return 0; return index % 2 == 0 ? arr[index / 2] & 0x0F : (arr[index / 2] >> 4) & 0x0F; }
};



#include "BlockMaps.h"
const char *BlockName(uint32_t id, uint32_t data = 0);
const char *BlockStateName(uint32_t id, uint32_t data = 0);

enum BiomeID {
	BIOME_UNKNOWN = -2,
	BIOME_UNCALCULATED = -1,
	BIOME_OCEAN = 0,
	BIOME_PLAINS = 1,
	BIOME_DESERT = 2,
	BIOME_EXTREME_HILLS = 3,
	BIOME_FOREST = 4,
	BIOME_TAIGA = 5,
	BIOME_SWAMPLAND = 6,
	BIOME_RIVER = 7,
	BIOME_NETHER = 8,
	BIOME_END = 9,
	BIOME_FROZEN_OCEAN = 10,
	BIOME_FROZEN_RIVER = 11,
	BIOME_ICE_PLAINS = 12,
	BIOME_ICE_MOUNTAINS = 13,
	BIOME_MUSHROOM_ISLAND = 14,
	BIOME_MUSHROOM_ISLAND_SHORE = 15,
	BIOME_BEACH = 16,
	BIOME_DESERT_HILLS = 17,
	BIOME_FOREST_HILLS = 18,
	BIOME_TAIGA_HILLS = 19,
	BIOME_EXTREME_HILLS_EDGE = 20,
	BIOME_JUNGLE = 21,
	BIOME_JUNGLE_HILLS = 22,
	BIOME_JUNGLE_EDGE = 23,
	BIOME_DEEP_OCEAN = 24,
	BIOME_STONE_BEACH = 25,
	BIOME_COLD_BEACH = 26,
	BIOME_BIRCH_FOREST = 27,
	BIOME_BIRCH_FOREST_HILLS = 28,
	BIOME_ROOFED_FOREST = 29,
	BIOME_COLD_TAIGA = 30,
	BIOME_COLD_TAIGA_HILLS = 31,
	BIOME_MEGA_TAIGA = 32,
	BIOME_MEGA_TAIGA_HILLS = 33,
	BIOME_EXTREME_HILLS_PLUS = 34,
	BIOME_SAVANA = 35,
	BIOME_SAVANA_PLATEAU = 36,
	BIOME_MESA = 37,
	BIOME_MESA_PLATEAU_F = 38,
	BIOME_MESA_PLATEAU = 39,
	// gap in biomes
	BIOME_SUNFLOWER_PLAINS = 129,
	BIOME_DESERT_M = 130,
	BIOME_EXTREME_HILLS_M = 131,
	BIOME_FLOWER_FOREST = 132,
	BIOME_TAIGA_M = 133,
	BIOME_SWAMPLAND_M = 134,
	BIOME_ICE_PLAINS_SPIKES = 140,
	BIOME_JUNGLE_M = 149,
	BIOME_JUNGLE_EDGE_M = 151,
	BIOME_BIRCH_FOREST_M = 155,
	BIOME_BIRCH_FOREST_HILLS_M = 156,
	BIOME_ROOFED_FOREST_M = 157,
	BIOME_COLD_TAIGA_M = 158,
	BIOME_MEGA_SPRUCE_TAIGA = 160,
	BIOME_REDWOOD_TAIGA_HILLS_M = 161,
	BIOME_EXTREME_HILLS_PLUS_M = 162,
	BIOME_SAVANA_M = 163,
	BIOME_SAVANA_PLATEAU_M = 164,
	BIOME_MESA_BRYCE = 165,
	BIOME_MESA_PLATEAU_F_M = 166,
	BIOME_MESA_PLATEAU_M = 167,
	BIOME_LAST = BIOME_MESA_PLATEAU_M
};

const char *BiomeName(BiomeID id);

#endif /* BLOCK_H_GUARD */
