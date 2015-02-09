#ifndef CHUNK_SECTION_H_GUARD
#define CHUNK_SECTION_H_GUARD

struct BlockInfo;
struct BlockAddress;

class NBT_Tag_Compound;
class NBT_Tag_ByteArray;

class ChunkSection
{
	public:
		ChunkSection() : idx(-1), y_off(-1), block_ids_nbt(nullptr), block_add_nbt(nullptr), block_data_nbt(nullptr) { }
		~ChunkSection() { }
		
		bool init(int32_t id, NBT_Tag_Compound *section);
		
		int32_t y() const { return y_off; }
		int32_t getIdx() const { return idx_; }
		
		bool getBlockInfo(const BlockAddress &addr, BlockInfo *info) const;
		
	private:
		int32_t idx;
		int32_t y_off;
		
		NBT_Tag_ByteArray *block_ids_nbt;
		NBT_Tag_ByteArray *block_add_nbt;
		NBT_Tag_ByteArray *block_data_nbt;
		
		NBT_Tag_Compound *nbt;
};

#endif /* CHUNK_SECTION_H_GUARD */
