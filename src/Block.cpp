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
		snprintf(buff, sizeof(buff)-1, "%s %s", BlockNames[id], SubBlockNames[subBlockRange[id].start+data]);
		return buff;
	}
	
	return BlockNames[id];
}

const char *BlockTexName(uint32_t id, uint32_t)
{
	return BlockTexNames[id];
}

