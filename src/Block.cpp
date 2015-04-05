#include <cstdint>
#include <sstream>
#include <vector>
#include <utility>
#include <stdio.h>

#include "Block.h"
#include "BlockMaps.h"
#include "Debug.h"

static void printBlockError(uint32_t id, uint32_t data)
{
	if(MCMAP_DEBUG)
	{
		std::stringstream sstr;
		std::vector<std::pair<uint8_t, uint8_t>> ranges;
		
		uint8_t cur_range_start = 0, cur_range_end = 0;
		for(uint32_t i = 0; i < subBlockRange[id].num; i++)
		{
			if(SubBlockNames[subBlockRange[id].start+i][0] != 0)
			{
				cur_range_end = i;
			}
			else
			{
				if(i != cur_range_end)
					ranges.push_back(std::make_pair(cur_range_start, cur_range_end));

				cur_range_start = i;
			}
		}
		
		if(cur_range_end != 15)
			ranges.push_back(std::make_pair(cur_range_start, cur_range_end));
		
		for(uint32_t i = 0; i < ranges.size(); i++)
		{
			auto &range = ranges[i];
			if(i)
				sstr << ", ";
			
			sstr << range.first << "-" << range.second;
		}
		
		std::string str = sstr.str();
		NBT_Debug("invalid block %i data: %i must be: %s", id, data, str.c_str());
	}
}

bool BlockIsValid(uint32_t id, uint32_t data)
{
	// I would normally invert this check to: id >= BLOCK_COUNT
	// but I suspect it's ever so slightly more efficient to check the common case
	// rather than the exception so we only jump in the rare case
	if(id < BLOCK_COUNT)
	{
		// block is within block id range, not totally validated yet
		
		// blocks without data are probably more common (air, etc)
		if(!subBlockRange[id].num)
			return true;
		
		if(data < subBlockRange[id].num)
		{
			if(SubBlockNames[subBlockRange[id].start+data][0] != 0)
			{
				return true;
			}
			else
			{
				printBlockError(id, data);
				return false;
			}
		}
		else
		{
			printBlockError(id, data);
			return false;
		}
		
		return true;
	}
	
	printBlockError(id, data);
	return false;
}

// ignores data parameter if a given block doesn't have any sub blocks
const char *BlockName(uint32_t id, uint32_t data)
{
	//static char buff[1024];
	if(id == 0)
		return "Air";
	
	// check the common case here, I normally prefer to check for the exception first
	// but this code is run so often, its best to avoid the jump when we can
	// assuming the compiler doesn't invert it on us?
	if(subBlockRange[id].num)
	{
		if(data < subBlockRange[id].num)
		{
			return SubBlockNames[subBlockRange[id].start+data];
		}
		else
		{
			return "Unknown";
		}
	}
	
	return BlockNames[id];
}

const char *BlockStateName(uint32_t id, uint32_t d)
{
	if(id == 0)
		return "air";
	
	if(subBlockRange[id].num)
	{
		if(d < subBlockRange[id].num)
		{
			return SubBlockStateNames[subBlockRange[id].start+d];
		}
		else
		{
			return "unknown";
		}
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
