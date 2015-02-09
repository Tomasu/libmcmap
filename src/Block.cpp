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

static const char UNKNOWNBIOME[] = "Unknown";

static const char *BiomeNames[BIOME_LAST+1] = 
{
	UNKNOWNBIOME,
	"Uncalculated",
	"Ocean",
	"Plains",
	"Desert",
	"Extreme Hills",
	"Forest",
	"Taiga",
	"Swampland",
	"River",
	"Nether",
	"End",
	"Frozen Ocean",
	"Frozen River",
	"Ice Plains",
	"Ice Mountains",
	"Mushroom Island",
	"Mushroom Island Shore",
	"Beach",
	"Desert Hills",
	"Forest Hills",
	"Taiga Hills",
	"Extreme Hills Edge",
	"Jungle",
	"Jungle Hills",
	"Jungle Edge",
	"Deep Ocean",
	"Stone Beach",
	"Cold Beach",
	"Birch Forest",
	"Birch Forest Hills",
	"Roofed Forest",
	"Cold Taiga",
	"Cold Taiga Hills",
	"Mega Taiga",
	"Mega Taiga Hills",
	"Extreme Hills+",
	"Savanna",
	"Savanna Plateau",
	"Mesa",
	"Mesa Plateau F",
	"Mesa Plateau",
	
	// 40-128
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, 
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, 
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, 
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, 
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, 
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, 
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, 
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, 
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME,

	// 129-134
	"Sunflower Plains",
	"Desert M",
	"Extreme Hills M",
	"Flower Forest",
	"Taiga M",
	"Swampland M",
	
	// 135-139
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME,

	// 140
	"Ice Plains Spikes",

	// 149
	"Jungle M",
	
	// 150
	UNKNOWNBIOME,

	// 151
	"JungleEdge M",

	// 152-154
	UNKNOWNBIOME, UNKNOWNBIOME, UNKNOWNBIOME,
	
	// 155-158
	"Birch Forest M",
	"Birch Forest Hills M",
	"Roofed Forest M",
	"Cold Taiga M",

	// 159
	UNKNOWNBIOME,
	
	// 160-167
	"Mega Spruce Taiga",
	"Redwood Taiga Hills M",
	"Extreme Hills+ M",
	"Savanna M",
	"Savanna Plateau M",
	"Mesa (Bryce)",
	"Mesa Plateau F M",
	"Mesa Plateau M"
};

const char *BiomeName(BiomeID id)
{
	if(id < 0 || id >= BIOME_LAST)
		return nullptr;
	
	return BiomeNames[id+2];
}
