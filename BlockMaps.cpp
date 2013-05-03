#include "BlockMaps.h"

const char *BlockNames[BLOCK_COUNT] = {
	"Air", // 0
	"Stone", // 1
	"Grass", // 2
	"Dirt", // 3
	"Cobblestone", // 4
	"Planks", // 5
	"Sapling", // 6
	"Bedrock", // 7
	"Moving Water", // 8
	"Still Water", // 9
	"Moving Lava", // 10
	"Still Lava", // 11
	"Sand", // 12
	"Gravel", // 13
	"Gold Ore", // 14
	"Iron Ore", // 15
	"Coal Ore", // 16
	"Wood", // 17
	"Leaves", // 18
	"Sponge", // 19
	"Glass", // 20
	"Lapis Ore", // 21
	"Lapis Block", // 22
	"Dispenser", // 23
	"Sand Stone", // 24
	"Music", // 25
	"Bed", // 26
	"Powered Rail", // 27
	"Detector Rail", // 28
	"Piston Sticky Base", // 29
	"Web", // 30
	"Tall Grass", // 31
	"Dead Bush", // 32
	"Piston Base", // 33
	"Piston Extension", // 34
	"Wool", // 35
	"Piston Moving", // 36
	"Yellow Plant", // 37
	"Red Plant", // 38
	"Brown Mushroom", // 39
	"Red Mushroom", // 40
	"Gold Block", // 41
	"Iron Block", // 42
	"Double Slab", // 43
	"Single Slab", // 44
	"Brick", // 45
	"Tnt", // 46
	"Book Shelf", // 47
	"Cobblestone Mossy", // 48
	"Obsidian", // 49
	"Wood Torch", // 50
	"Fire", // 51
	"Mob Spawner", // 52
	"Wood Oak Stairs", // 53
	"Chest", // 54
	"Redstone Wire", // 55
	"Diamond Ore", // 56
	"Diamond Block", // 57
	"Workbench", // 58
	"Crops", // 59
	"Tilled Field", // 60
	"Furnace Idle", // 61
	"Furnace Burning", // 62
	"Sign Post", // 63
	"Wood Door", // 64
	"Ladder", // 65
	"Rail", // 66
	"Cobblestone Stairs", // 67
	"Sign Wall", // 68
	"Lever", // 69
	"Pressure Plate Stone", // 70
	"Iron Door", // 71
	"Pressure Plate Planks", // 72
	"Redstone Ore", // 73
	"Redstone Glowing Ore", // 74
	"Redstone Idle Torch", // 75
	"Redstone Active Torch", // 76
	"Stone Button", // 77
	"Snow", // 78
	"Ice", // 79
	"Snow Block", // 80
	"Cactus", // 81
	"Clay Block", // 82
	"Reed", // 83
	"Jukebox", // 84
	"Fence", // 85
	"Pumpkin", // 86
	"Netherrack", // 87
	"Slow Sand", // 88
	"Glow Stone", // 89
	"Portal", // 90
	"Pumpkin Lantern", // 91
	"Cake", // 92
	"Redstone Repeater Idle", // 93
	"Redstone Repeater Active", // 94
	"Locked Chest", // 95
	"Trapdoor", // 96
	"Silverfish", // 97
	"Stone Brick", // 98
	"Mushroom Cap Brown", // 99
	"Mushroom Cap Red", // 100
	"Fence Iron", // 101
	"Thin Glass", // 102
	"Melon", // 103
	"Pumpkin Stem", // 104
	"Melon Stem", // 105
	"Vine", // 106
	"Fence Gate", // 107
	"Brick Stairs", // 108
	"Stone Brick Stairs", // 109
	"Mycelium", // 110
	"Waterlily", // 111
	"Nether Brick", // 112
	"Nether Fence", // 113
	"Nether Brick Stairs", // 114
	"Nether Stalk", // 115
	"Enchantment Table", // 116
	"Brewing Stand", // 117
	"Cauldron", // 118
	"End Portal", // 119
	"End Portal Frame", // 120
	"White Stone", // 121
	"Dragon Egg", // 122
	"Redstone Lamp Idle", // 123
	"Redstone Lamp Active", // 124
	"Wood Double Slab", // 125
	"Wood Single Slab", // 126
	"Cocoa Plant", // 127
	"Sand Stone Stairs", // 128
	"Emerald Ore", // 129
	"Ender Chest", // 130
	"Trip Wire Source", // 131
	"Trip Wire", // 132
	"Emerald Block", // 133
	"Wood Spruce Stairs", // 134
	"Wood Birch Stairs", // 135
	"Wood Jungle Stairs", // 136
	"Command Block", // 137
	"Beacon", // 138
	"Cobblestone Wall", // 139
	"Flower Pot", // 140
	"Carrot", // 141
	"Potato", // 142
	"Wooden Button", // 143
	"Skull", // 144
	"Anvil", // 145
	"Chest Trapped", // 146
	"Pressure Plate Gold", // 147
	"Pressure Plate Iron", // 148
	"Redstone Comparator Idle", // 149
	"Redstone Comparator Active", // 150
	"Daylight Sensor", // 151
	"Redstone Block", // 152
	"Nether Quartz Ore", // 153
	"Hopper Block", // 154
	"Nether Quartz Block", // 155
	"Nether Quartz Stairs", // 156
	"Activator Rail", // 157
	"Dropper", // 158
};

SubBlockRange subBlockRange[BLOCK_COUNT] = {
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 4 }, // 5
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
	{ 4, 4 }, // 17
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
	{ 8, 16 }, // 35
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 24, 8 }, // 43
	{ 32, 8 }, // 44
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
	{ 40, 3 }, // 97
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
	{ 43, 4 }, // 125
	{ 47, 4 }, // 126
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
	{ 51, 3 }, // 155
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
};

const char *SubBlockNames[SUBBLOCKNAME_COUNT] = {
	"Oak", // 5:0
	"Spruce", // 5:1
	"Birch", // 5:2
	"Jungle", // 5:3
	"Oak", // 17:0
	"Spruce", // 17:1
	"Birch", // 17:2
	"Jungle", // 17:3
	"White", // 35:0
	"Orange", // 35:1
	"Magenta", // 35:2
	"Light Blue", // 35:3
	"Yellow", // 35:4
	"Lime", // 35:5
	"Pink", // 35:6
	"Gray", // 35:7
	"Light Gray", // 35:8
	"Cyan", // 35:9
	"Purple", // 35:10
	"Blue", // 35:11
	"Brown", // 35:12
	"Green", // 35:13
	"Red", // 35:14
	"Black", // 35:15
	"Stone", // 43:0
	"Sand", // 43:1
	"Wood", // 43:2
	"Cobble", // 43:3
	"Brick", // 43:4
	"Smooth Stone Brick", // 43:5
	"Nether Brick", // 43:6
	"Quartz", // 43:7
	"Stone", // 44:0
	"Sand", // 44:1
	"Wood", // 44:2
	"Cobble", // 44:3
	"Brick", // 44:4
	"Smooth Stone Brick", // 44:5
	"Nether Brick", // 44:6
	"Quartz", // 44:7
	"Stone", // 97:0
	"Cobble", // 97:1
	"Brick", // 97:2
	"Oak", // 125:0
	"Spruce", // 125:1
	"Birch", // 125:2
	"Jungle", // 125:3
	"Oak", // 126:0
	"Spruce", // 126:1
	"Birch", // 126:2
	"Jungle", // 126:3
	"Default", // 155:0
	"Chiseled", // 155:1
	"Lines", // 155:2
};
