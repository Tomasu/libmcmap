#include "BlockMaps.h"

const char *BlockNames[BLOCK_COUNT] = {
	"Air", // 0
	"Stone", // 1
	"Grass", // 2
	"Dirt", // 3
	"Cobblestone", // 4
	"Wooden Plank", // 5
	"Sapling", // 6
	"Adminium", // 7
	"Water", // 8
	"Stationary Water", // 9
	"Lava", // 10
	"Stationary Lava", // 11
	"Sand", // 12
	"Gravel", // 13
	"Gold Ore", // 14
	"Iron ore", // 15
	"Coal Ore", // 16
	"Wood", // 17
	"Leaves", // 18
	"Sponge", // 19
	"Glass", // 20
	"Lapis Lazuli Ore", // 21
	"Lapis Lazuli Block", // 22
	"Dispenser", // 23
	"Sandstone", // 24
	"Note Block", // 25
	"Bed", // 26
	"Powered Rail", // 27
	"Detector Rail", // 28
	"Sticky Piston", // 29
	"Cobweb", // 30
	"Grass", // 31
	"Dead Bush", // 32
	"Piston", // 33
	"Piston Extension", // 34
	"Wool", // 35
	"Block Moved By Piston", // 36
	"Yellow Flower", // 37
	"Red Flower", // 38
	"Brown Mushroom", // 39
	"Red Mushroom", // 40
	"Gold Block", // 41
	"Iron Block", // 42
	"Double Slabs", // 43
	"Stone Slab", // 44
	"Brick", // 45
	"TNT", // 46
	"Bookshelf", // 47
	"Moss Stone", // 48
	"Obsidian", // 49
	"Torch", // 50
	"Fire", // 51
	"Monster Spawner", // 52
	"Wooden Stairs", // 53
	"Chest", // 54
	"Redstone Wire", // 55
	"Diamond Ore", // 56
	"Diamond Block", // 57
	"Workbench", // 58
	"Wheat", // 59
	"Soil", // 60
	"Furnace", // 61
	"Burning Furnace", // 62
	"Signpost", // 63
	"Wooden Door", // 64
	"Ladder", // 65
	"Minecart Track", // 66
	"Cobblestone Stairs", // 67
	"Wall Sign", // 68
	"Lever", // 69
	"Stone Pressure Plate", // 70
	"Iron Door", // 71
	"Wooden Pressure Plate", // 72
	"Redstone Ore", // 73
	"Glowing Redstone Ore", // 74
	"Redstone Torch (Off)", // 75
	"Redstone Torch (On)", // 76
	"Stone Button", // 77
	"Snow", // 78
	"Ice", // 79
	"Snow Block", // 80
	"Cactus", // 81
	"Clay", // 82
	"Sugar Cane", // 83
	"Jukebox", // 84
	"Fence", // 85
	"Pumpkin", // 86
	"Netherrack", // 87
	"Soul Sand", // 88
	"Glowstone", // 89
	"Portal", // 90
	"Jack-O-Lantern", // 91
	"Cake", // 92
	"Repeater (off)", // 93
	"Repeater (on)", // 94
	"Locked Chest", // 95
	"Trapdoor", // 96
	"Monster Egg", // 97
	"Stone Brick", // 98
	"Huge brown mushroom", // 99
	"Huge Red Mushroom", // 100
	"Iron Bars", // 101
	"Glass Pane", // 102
	"Melon", // 103
	"Pumpkin Stem", // 104
	"Melon Stem", // 105
	"Vines", // 106
	"Fence Gate", // 107
	"Brick Stairs", // 108
	"Stone Brick Stairs", // 109
	"Mycelium", // 110
	"Lily Pad", // 111
	"Nether Brick", // 112
	"Nether Brick Fence", // 113
	"Nether Brick Stairs", // 114
	"Nether Wart", // 115
	"Enchantment Table", // 116
	"Brewing Stand", // 117
	"Cauldron", // 118
	"End Portal", // 119
	"End Portal Block", // 120
	"End Stone", // 121
	"Dragon Egg", // 122
	"Redstone Lamp (off)", // 123
	"Redstone Lamp (on)", // 124
	"Wooden Double Slab", // 125
	"Wooden Slab", // 126
	"Cocoa Plant", // 127
	"Sandstone Stairs", // 128
	"Emerald Ore", // 129
	"Ender Chest", // 130
	"Tripwire Hook", // 131
	"Tripwire", // 132
	"Block of Emerald", // 133
	"Spruce Wood Stairs", // 134
	"Birch Wood Stairs", // 135
	"Jungle Wood Stairs", // 136
	"Command Block", // 137
	"Beacon", // 138
	"Cobblestone Wall", // 139
	"Flower Pot", // 140
	"Carrots", // 141
	"Potatoes", // 142
	"Wooden Button", // 143
	"Mob Head", // 144
	"Anvil", // 145
};

SubBlockRange subBlockRange[BLOCK_COUNT] = {
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 4 }, // 5
	{ 4, 4 }, // 6
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 8, 4 }, // 17
	{ 12, 4 }, // 18
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 16, 3 }, // 24
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 19, 3 }, // 31
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 22, 16 }, // 35
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 38, 7 }, // 44
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 45, 4 }, // 98
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 49, 4 }, // 126
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 53, 2 }, // 139
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
};

const char *SubBlockNames[SUBBLOCKNAME_COUNT] = {
	"Wooden Plank", // 5:0
	"Wooden Plank (Pine)", // 5:1
	"Wooden Plank (Birch)", // 5:2
	"Wooden Plank (Jungle)", // 5:3
	"Sapling", // 6:0
	"Sapling (Spruce)", // 6:1
	"Sapling (Birch)", // 6:2
	"Sapling (Jungle)", // 6:3
	"Wood", // 17:0
	"Wood (Pine)", // 17:1
	"Wood (Birch)", // 17:2
	"Wood (Jungle)", // 17:3
	"Leaves", // 18:0
	"Leaves (Pine)", // 18:1
	"Leaves (Birch)", // 18:2
	"Leaves (Jungle)", // 18:3
	"Sandstone", // 24:0
	"Sandstone (Decorative)", // 24:1
	"Sandstone (Smooth)", // 24:2
	"Tall Grass (Shrub)", // 31:0
	"Tall Grass (Grass)", // 31:1
	"Tall Grass (Fern)", // 31:2
	"Wool", // 35:0
	"Orange Wool", // 35:1
	"Magenta Wool", // 35:2
	"Light Blue Wool", // 35:3
	"Yellow Wool", // 35:4
	"Light Green Wool", // 35:5
	"Pink Wool", // 35:6
	"Gray Wool", // 35:7
	"Light Gray Wool", // 35:8
	"Cyan Wool", // 35:9
	"Purple Wool", // 35:10
	"Blue Wool", // 35:11
	"Brown Wool", // 35:12
	"Dark Green Wool", // 35:13
	"Red Wool", // 35:14
	"Black Wool", // 35:15
	"Stone Slab", // 44:0
	"Sandstone Slab", // 44:1
	"Wooden Slab", // 44:2
	"Cobblestone Slab", // 44:3
	"Brick Slab", // 44:4
	"Stone Brick Slab", // 44:5
	"Alternative Stone Slab", // 44:6
	"Stone Brick", // 98:0
	"Cracked Stone Brick", // 98:1
	"Missy Stone Brick", // 98:2
	"Chiseled Stone Brick", // 98:3
	"Oak-Wood Slab", // 126:0
	"Spruce-Wood Slab", // 126:1
	"Birch-Wood Slab", // 126:2
	"Jungle-Wood Slab", // 126:3
	"Cobblestone Wall", // 139:0
	"Mossy Cobblestone Wall", // 139:1
};
