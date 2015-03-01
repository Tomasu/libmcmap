#ifndef CHUNK_SECTION_H_GUARD
#define CHUNK_SECTION_H_GUARD

#include <stdint.h>

struct BlockInfo;
struct BlockAddress;

class NBT_Tag_Compound;
class NBT_Tag_Byte_Array;

class ChunkSection
{
	public:
		ChunkSection();
		~ChunkSection();
		
		bool init(int32_t id, NBT_Tag_Compound *section);
		
		int32_t y() const { return y_off; }
		int32_t getIdx() const { return idx; }
		
		bool getBlockInfo(const BlockAddress &addr, BlockInfo *info) const;
		
	private:
		int32_t idx;
		int32_t y_off;
		
		NBT_Tag_Byte_Array *block_ids_nbt;
		NBT_Tag_Byte_Array *block_add_nbt;
		NBT_Tag_Byte_Array *block_data_nbt;
		
		NBT_Tag_Compound *nbt;
};

#endif /* CHUNK_SECTION_H_GUARD */
