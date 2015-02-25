#include "ChunkSection.h"
#include "BlockInfo.h"

#include "NBT_Debug.h"
#include "NBT_Tag_Compound.h"
#include "NBT_Tag_Byte_Array.h"

bool ChunkSection::init(int32_t idx, NBT_Tag_Compound *section) 
{
	nbt = section;
	
	y_off = nbt->getByte("Y");
	
	idx = idx;
	
	block_ids_nbt = nbt->getByteArray("Blocks");
	if(!block_ids_nbt)
	{
		NBT_Debug("missing Blocks data in section %i", idx);
		return false;
	}
	
	block_add_nbt = nbt->getByteArray("Add");
	if(!block_add_nbt)
	{
		//NBT_Debug("missing Add data in section %i", idx);
	}
	
	block_data_nbt = nbt->getByteArray("Data");
	if(!block_data_nbt)
	{
		NBT_Debug("missing Data data in section %i", idx);
	}
	
	return true;
}

bool ChunkSection::getBlockInfo(const BlockAddress &addr, BlockInfo *info) const
{
	uint8_t *add_data = block_add_nbt ? block_add_nbt->data() : nullptr;
	uint8_t *sub_data = block_data_nbt ? block_data_nbt->data() : nullptr;
	
	int32_t bid = BlockInfo::ID(block_ids_nbt->data(), add_data, addr.idx);
	int32_t sid = BlockInfo::SID(sub_data, addr.idx);
	
	*info = BlockInfo(addr, bid, sid, BIOME_UNCALCULATED);
	info->state_name = BlockStateName(bid, sid);
	
	return true;
}
