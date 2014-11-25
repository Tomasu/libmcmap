#include <cstdint>
#include <stdio.h>

#include "Block.h"
#include "BlockMaps.h"

// ignores data parameter if a given block doesn't have any sub blocks
const char *BlockName(uint32_t id, uint32_t data)
{
	static char buff[1024];
	
	if(subBlockRange[id].num)
	{
		return SubBlockNames[subBlockRange[id].start+data];
//		snprintf(buff, sizeof(buff)-1, "%s %s", BlockNames[id], SubBlockNames[subBlockRange[id].start+data]);
//		return buff;
	}
	
	return BlockNames[id];
}

const char *BlockStateName(uint32_t id, uint32_t d)
{
	if(subBlockRange[id].num)
	{
		return SubBlockStateNames[subBlockRange[id].start+d];
	}
	
	return BlockStateNames[id];
}

