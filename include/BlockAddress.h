#ifndef BLOCK_ADDRESS_H_GUARD
#define BLOCK_ADDRESS_H_GUARD

#include <stdio.h>
#include <string>

struct BlockAddress
{
	BlockAddress(int32_t dimid = 0, int32_t ax = 0, int32_t ay = 0, int32_t az = 0) : dimension(dimid), x(ax), y(ay), z(az)
	{
		
		lx = x & 15;
		if(lx < 0) lx += 16; // if x is negative, add 16 to get non negative chunk local coords (0-15)
		
		lz = z & 15;
		if(lz < 0) lz += 16; // same as above
		
		ly = y & 15; // section local
		if(ly < 0) ly += 16; // same as above
		
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
	
	const std::string toString()
	{
		char str[2048];
		snprintf(str, 2047, "BlockAddress(%p: dim:%i x:%i y:%i z:%i lx:%i lz:%i section:%i ly:%i idx:%i)",
			this, dimension, x, y, z, lx, lz, section, ly, idx
		);
		return str;
	}
};

#endif /* BLOCK_ADDRESS_H_GUARD */
