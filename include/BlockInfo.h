#ifndef BLOCK_INFO_H_GUARD
#define BLOCK_INFO_H_GUARD

#include "BlockAddress.h"
#include "Block.h"

struct BlockInfo
{
	BlockInfo() : addr(), id(BLOCK_AIR), data(0), biome(BIOME_UNCALCULATED) { }
	
	BlockInfo(const BlockAddress &baddr, int32_t bid, int32_t bdata, int32_t b)
		: addr(baddr), id(bid), data(bdata), biome(b) { }
	
	BlockInfo(const BlockInfo &b)
	{
		addr = b.addr;
		id = b.id;
		biome = b.biome;
		data = b.data;
	}
	
	BlockAddress addr;
	int32_t id, data, biome;
	char *state_name;

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

#endif /* BLOCK_INFO_H_GUARD */
