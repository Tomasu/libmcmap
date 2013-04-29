#include <cstdint>

#include "Block.h"
#include "BlockMaps.h"

// ignores data parameter if a given block doesn't have any sub blocks
const char *BlockName(uint32_t id, uint32_t data)
{
	if(subBlockRange[id].num)
	{
		return SubBlockNames[subBlockRange[id].start+data];
	}
	
	return BlockNames[id];
}

