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
	"Flowing Water", // 8
	"Water", // 9
	"Flowing Lava", // 10
	"Lava", // 11
	"Sand", // 12
	"Gravel", // 13
	"Gold Ore", // 14
	"Iron Ore", // 15
	"Coal Ore", // 16
	"Log", // 17
	"Leaves", // 18
	"Sponge", // 19
	"Glass", // 20
	"Lapis Ore", // 21
	"Lapis Block", // 22
	"Dispenser", // 23
	"Sandstone", // 24
	"Noteblock", // 25
	"Bed", // 26
	"Golden Rail", // 27
	"Detector Rail", // 28
	"Sticky Piston", // 29
	"Web", // 30
	"Tallgrass", // 31
	"Deadbush", // 32
	"Piston", // 33
	"Piston Head", // 34
	"Wool", // 35
	"Piston Extension", // 36
	"Yellow Flower", // 37
	"Red Flower", // 38
	"Brown Mushroom", // 39
	"Red Mushroom", // 40
	"Gold Block", // 41
	"Iron Block", // 42
	"Double Stone Slab", // 43
	"Slab", // 44
	"Brick Block", // 45
	"Tnt", // 46
	"Bookshelf", // 47
	"Mossy Cobblestone", // 48
	"Obsidian", // 49
	"Torch", // 50
	"Fire", // 51
	"Mob Spawner", // 52
	"Oak Stairs", // 53
	"Chest", // 54
	"Redstone Wire", // 55
	"Diamond Ore", // 56
	"Diamond Block", // 57
	"Crafting Table", // 58
	"Wheat", // 59
	"Farmland", // 60
	"Furnace", // 61
	"Lit Furnace", // 62
	"Standing Sign", // 63
	"Wooden Door", // 64
	"Ladder", // 65
	"Rail", // 66
	"Stone Stairs", // 67
	"Wall Sign", // 68
	"Lever", // 69
	"Stone Pressure Plate", // 70
	"Iron Door", // 71
	"Wooden Pressure Plate", // 72
	"Redstone Ore", // 73
	"Lit Redstone Ore", // 74
	"Unlit Redstone Torch", // 75
	"Redstone Torch", // 76
	"Stone Button", // 77
	"Snow Layer", // 78
	"Ice", // 79
	"Snow", // 80
	"Cactus", // 81
	"Clay", // 82
	"Reeds", // 83
	"Jukebox", // 84
	"Fence", // 85
	"Pumpkin", // 86
	"Netherrack", // 87
	"Soul Sand", // 88
	"Glowstone", // 89
	"Portal", // 90
	"Lit Pumpkin", // 91
	"Cake", // 92
	"Unpowered Repeater", // 93
	"Powered Repeater", // 94
	"Stained Glass", // 95
	"Trapdoor", // 96
	"Monster Egg", // 97
	"Stonebrick", // 98
	"Brown Mushroom Block", // 99
	"Red Mushroom Block", // 100
	"Iron Bars", // 101
	"Glass Pane", // 102
	"Melon Block", // 103
	"Pumpkin Stem", // 104
	"Melon Stem", // 105
	"Vine", // 106
	"Fence Gate", // 107
	"Brick Stairs", // 108
	"Stone Brick Stairs", // 109
	"Mycelium", // 110
	"Waterlily", // 111
	"Nether Brick", // 112
	"Nether Brick Fence", // 113
	"Nether Brick Stairs", // 114
	"Nether Wart", // 115
	"Enchanting Table", // 116
	"Brewing Stand", // 117
	"Cauldron", // 118
	"End Portal", // 119
	"End Portal Frame", // 120
	"End Stone", // 121
	"Dragon Egg", // 122
	"Redstone Lamp", // 123
	"Lit Redstone Lamp", // 124
	"Double Wooden Slab", // 125
	"Wooden Slab", // 126
	"Cocoa", // 127
	"Sandstone Stairs", // 128
	"Emerald Ore", // 129
	"Ender Chest", // 130
	"Tripwire Hook", // 131
	"Tripwire", // 132
	"Emerald Block", // 133
	"Spruce Stairs", // 134
	"Birch Stairs", // 135
	"Jungle Stairs", // 136
	"Command Block", // 137
	"Beacon", // 138
	"Cobblestone Wall", // 139
	"Flower Pot", // 140
	"Carrots", // 141
	"Potatoes", // 142
	"Wooden Button", // 143
	"Skull", // 144
	"Anvil", // 145
	"Trapped Chest", // 146
	"Light Weighted Pressure Plate", // 147
	"Heavy Weighted Pressure Plate", // 148
	"Unpowered Comparator", // 149
	"Powered Comparator", // 150
	"Daylight Detector", // 151
	"Redstone Block", // 152
	"Quartz Ore", // 153
	"Hopper", // 154
	"Quartz Block", // 155
	"Quartz Stairs", // 156
	"Activator Rail", // 157
	"Dropper", // 158
	"Stained Hardened Clay", // 159
	"Stained Glass Pane", // 160
	"Leaves2", // 161
	"Log2", // 162
	"Acacia Stairs", // 163
	"Dark Oak Stairs", // 164
	"", // 165
	"", // 166
	"", // 167
	"", // 168
	"", // 169
	"Hay Block", // 170
	"Carpet", // 171
	"Hardened Clay", // 172
	"Coal Block", // 173
	"Packed Ice", // 174
	"Double Plant", // 175
};

SubBlockRange subBlockRange[BLOCK_COUNT] = {
	{ 0, 0 }, // 0
	{ 0, 0 }, // 1
	{ 0, 4 }, // 2
	{ 4, 0 }, // 3
	{ 4, 0 }, // 4
	{ 4, 6 }, // 5
	{ 10, 6 }, // 6
	{ 16, 0 }, // 7
	{ 16, 0 }, // 8
	{ 16, 0 }, // 9
	{ 16, 0 }, // 10
	{ 16, 0 }, // 11
	{ 16, 2 }, // 12
	{ 18, 0 }, // 13
	{ 18, 0 }, // 14
	{ 18, 0 }, // 15
	{ 18, 2 }, // 16
	{ 20, 16 }, // 17
	{ 36, 4 }, // 18
	{ 40, 0 }, // 19
	{ 40, 0 }, // 20
	{ 40, 0 }, // 21
	{ 40, 0 }, // 22
	{ 40, 6 }, // 23
	{ 46, 3 }, // 24
	{ 49, 0 }, // 25
	{ 49, 16 }, // 26
	{ 65, 16 }, // 27
	{ 81, 0 }, // 28
	{ 81, 0 }, // 29
	{ 81, 0 }, // 30
	{ 81, 0 }, // 31
	{ 81, 0 }, // 32
	{ 81, 14 }, // 33
	{ 95, 0 }, // 34
	{ 95, 16 }, // 35
	{ 111, 14 }, // 36
	{ 125, 1 }, // 37
	{ 126, 8 }, // 38
	{ 134, 0 }, // 39
	{ 134, 0 }, // 40
	{ 134, 0 }, // 41
	{ 134, 0 }, // 42
	{ 134, 16 }, // 43
	{ 150, 16 }, // 44
	{ 166, 0 }, // 45
	{ 166, 0 }, // 46
	{ 166, 0 }, // 47
	{ 166, 0 }, // 48
	{ 166, 0 }, // 49
	{ 166, 5 }, // 50
	{ 171, 0 }, // 51
	{ 171, 0 }, // 52
	{ 171, 8 }, // 53
	{ 179, 6 }, // 54
	{ 185, 16 }, // 55
	{ 201, 0 }, // 56
	{ 201, 0 }, // 57
	{ 201, 0 }, // 58
	{ 201, 0 }, // 59
	{ 201, 9 }, // 60
	{ 210, 6 }, // 61
	{ 216, 6 }, // 62
	{ 222, 16 }, // 63
	{ 238, 10 }, // 64
	{ 248, 6 }, // 65
	{ 254, 10 }, // 66
	{ 264, 8 }, // 67
	{ 272, 6 }, // 68
	{ 278, 16 }, // 69
	{ 294, 2 }, // 70
	{ 296, 10 }, // 71
	{ 306, 2 }, // 72
	{ 308, 0 }, // 73
	{ 308, 0 }, // 74
	{ 308, 0 }, // 75
	{ 308, 0 }, // 76
	{ 308, 14 }, // 77
	{ 322, 8 }, // 78
	{ 330, 0 }, // 79
	{ 330, 0 }, // 80
	{ 330, 16 }, // 81
	{ 346, 0 }, // 82
	{ 346, 16 }, // 83
	{ 362, 13 }, // 84
	{ 375, 0 }, // 85
	{ 375, 5 }, // 86
	{ 380, 0 }, // 87
	{ 380, 0 }, // 88
	{ 380, 0 }, // 89
	{ 380, 0 }, // 90
	{ 380, 5 }, // 91
	{ 385, 6 }, // 92
	{ 391, 12 }, // 93
	{ 403, 12 }, // 94
	{ 415, 15 }, // 95
	{ 430, 16 }, // 96
	{ 446, 6 }, // 97
	{ 452, 4 }, // 98
	{ 456, 16 }, // 99
	{ 472, 16 }, // 100
	{ 488, 0 }, // 101
	{ 488, 0 }, // 102
	{ 488, 0 }, // 103
	{ 488, 8 }, // 104
	{ 496, 8 }, // 105
	{ 504, 25 }, // 106
	{ 529, 8 }, // 107
	{ 537, 8 }, // 108
	{ 545, 8 }, // 109
	{ 553, 0 }, // 110
	{ 553, 0 }, // 111
	{ 553, 0 }, // 112
	{ 553, 0 }, // 113
	{ 553, 8 }, // 114
	{ 561, 4 }, // 115
	{ 565, 0 }, // 116
	{ 565, 13 }, // 117
	{ 578, 4 }, // 118
	{ 582, 0 }, // 119
	{ 582, 8 }, // 120
	{ 590, 0 }, // 121
	{ 590, 0 }, // 122
	{ 590, 0 }, // 123
	{ 590, 0 }, // 124
	{ 590, 15 }, // 125
	{ 605, 15 }, // 126
	{ 620, 16 }, // 127
	{ 636, 8 }, // 128
	{ 644, 0 }, // 129
	{ 644, 6 }, // 130
	{ 650, 16 }, // 131
	{ 666, 17 }, // 132
	{ 683, 0 }, // 133
	{ 683, 8 }, // 134
	{ 691, 8 }, // 135
	{ 699, 8 }, // 136
	{ 707, 0 }, // 137
	{ 707, 0 }, // 138
	{ 707, 2 }, // 139
	{ 709, 14 }, // 140
	{ 723, 0 }, // 141
	{ 723, 0 }, // 142
	{ 723, 14 }, // 143
	{ 737, 6 }, // 144
	{ 743, 10 }, // 145
	{ 753, 6 }, // 146
	{ 759, 2 }, // 147
	{ 761, 2 }, // 148
	{ 763, 16 }, // 149
	{ 779, 16 }, // 150
	{ 795, 0 }, // 151
	{ 795, 0 }, // 152
	{ 795, 0 }, // 153
	{ 795, 6 }, // 154
	{ 801, 5 }, // 155
	{ 806, 8 }, // 156
	{ 814, 0 }, // 157
	{ 814, 6 }, // 158
	{ 820, 15 }, // 159
	{ 835, 15 }, // 160
	{ 850, 2 }, // 161
	{ 852, 16 }, // 162
	{ 868, 8 }, // 163
	{ 876, 8 }, // 164
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 884, 0 }, // 170
	{ 884, 15 }, // 171
	{ 899, 0 }, // 172
	{ 899, 0 }, // 173
	{ 899, 0 }, // 174
	{ 899, 6 }, // 175
};

const char *SubBlockNames[SUBBLOCKNAME_COUNT] = {
	"Shrub", // 2:0
	"Grass", // 2:1
	"Fern", // 2:2
	"Grass", // 2:3
	"Oak", // 5:0
	"Spruce", // 5:1
	"Birch", // 5:2
	"Jungle", // 5:3
	"Acacia", // 5:4
	"Dark Oak", // 5:5
	"Oak", // 6:0
	"Spruce", // 6:1
	"Birch", // 6:2
	"Jungle", // 6:3
	"Acacia", // 6:4
	"Dark Oak", // 6:5
	"Sand", // 12:0
	"Red Sand", // 12:1
	"Coal", // 16:0
	"Charcoal", // 16:1
	"Oak", // 17:0
	"Spruce", // 17:1
	"Birch", // 17:2
	"Jungle", // 17:3
	"Oak E/W", // 17:4
	"Spruce E/W", // 17:5
	"Birch E/W", // 17:6
	"Jungle E/W", // 17:7
	"Oak N/S", // 17:8
	"Spruce N/S", // 17:9
	"Birch N/S", // 17:10
	"Jungle N/S", // 17:11
	"Oak Bark", // 17:12
	"Spruce Bark", // 17:13
	"Birch Bark", // 17:14
	"Jungle Bark", // 17:15
	"Oak", // 18:0
	"Pine/Spruce", // 18:1
	"Birch", // 18:2
	"Jungle", // 18:3
	"Down", // 23:0
	"Up", // 23:1
	"North", // 23:2
	"South", // 23:3
	"West", // 23:4
	"East", // 23:5
	"Normal", // 24:0
	"Chiseled", // 24:1
	"Smooth", // 24:2
	"South", // 26:0
	"West", // 26:1
	"North", // 26:2
	"East", // 26:3
	"South Occupied", // 26:4
	"West Occupied", // 26:5
	"North Occupied", // 26:6
	"East Occupied", // 26:7
	"South Head", // 26:8
	"West Head", // 26:9
	"North Head", // 26:10
	"East Head", // 26:11
	"South Occupied Head", // 26:12
	"West Occupied Head", // 26:13
	"North Occupied Head", // 26:14
	"East Occupied Head", // 26:15
	"Flat N/S", // 27:0
	"Flat E/W", // 27:1
	"Asc East", // 27:2
	"Asc West", // 27:3
	"Asc North", // 27:4
	"Asc South", // 27:5
	"Corner N/W", // 27:6
	"Corner N/E", // 27:7
	"Corner S/E Powered", // 27:8
	"Corner S/W Powered", // 27:9
	"Asc East Powered", // 27:10
	"Asc West Powered", // 27:11
	"Asc North Powered", // 27:12
	"Asc South Powered", // 27:13
	"Corner N/W Powered", // 27:14
	"Corner N/E Powered", // 27:15
	"Down", // 33:0
	"Up", // 33:1
	"North", // 33:2
	"South", // 33:3
	"West", // 33:4
	"East", // 33:5
	"", // 33:6
	"", // 33:7
	"Down Extended", // 33:8
	"Up Extended", // 33:9
	"North Extended", // 33:10
	"South Extended", // 33:11
	"West Extended", // 33:12
	"East Extended", // 33:13
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
	"Down", // 36:0
	"Up", // 36:1
	"North", // 36:2
	"South", // 36:3
	"West", // 36:4
	"East", // 36:5
	"", // 36:6
	"", // 36:7
	"Down Sticky", // 36:8
	"Up Sticky", // 36:9
	"North Sticky", // 36:10
	"South Sticky", // 36:11
	"West Sticky", // 36:12
	"East Sticky", // 36:13
	"Dandelion", // 37:0
	"Poppy", // 38:0
	"Blue Orchid", // 38:1
	"Allium", // 38:2
	"Azure Bluet", // 38:3
	"Red Tulip", // 38:4
	"White Tulip", // 38:5
	"Pink Tulip", // 38:6
	"Oxeye Daisy", // 38:7
	"Stone", // 43:0
	"Sandstone", // 43:1
	"Wood", // 43:2
	"Cobblestone", // 43:3
	"Brick", // 43:4
	"Stone Brick", // 43:5
	"Nether Brick", // 43:6
	"Quartz", // 43:7
	"Stone Double", // 43:8
	"Sandstone Double", // 43:9
	"", // 43:10
	"", // 43:11
	"", // 43:12
	"", // 43:13
	"", // 43:14
	"Quartz Double", // 43:15
	"Stone", // 44:0
	"Sandstone", // 44:1
	"Wood", // 44:2
	"Cobblestone", // 44:3
	"Brick", // 44:4
	"Stone Brick", // 44:5
	"Nether Brick", // 44:6
	"Quartz", // 44:7
	"Stone Double", // 44:8
	"Sandstone Double", // 44:9
	"", // 44:10
	"", // 44:11
	"", // 44:12
	"", // 44:13
	"", // 44:14
	"Quartz Double", // 44:15
	"Floor", // 50:0
	"East", // 50:1
	"West", // 50:2
	"South", // 50:3
	"North", // 50:4
	"", // 53:0
	"", // 53:1
	"", // 53:2
	"", // 53:3
	"East Upside Down", // 53:4
	"West Upside Down", // 53:5
	"South Upside Down", // 53:6
	"North Upside Down", // 53:7
	"", // 54:0
	"", // 54:1
	"North", // 54:2
	"South", // 54:3
	"West", // 54:4
	"East", // 54:5
	"0", // 55:0
	"1", // 55:1
	"2", // 55:2
	"3", // 55:3
	"4", // 55:4
	"5", // 55:5
	"6", // 55:6
	"7", // 55:7
	"8", // 55:8
	"9", // 55:9
	"10", // 55:10
	"11", // 55:11
	"12", // 55:12
	"13", // 55:13
	"14", // 55:14
	"15", // 55:15
	"Dry", // 60:0
	"Wet 1", // 60:1
	"Wet 2", // 60:2
	"Wet 3", // 60:3
	"Wet 4", // 60:4
	"Wet 5", // 60:5
	"Wet 6", // 60:6
	"Wet 7", // 60:7
	"Wet 8", // 60:8
	"", // 61:0
	"", // 61:1
	"North", // 61:2
	"South", // 61:3
	"West", // 61:4
	"East", // 61:5
	"", // 62:0
	"", // 62:1
	"North", // 62:2
	"South", // 62:3
	"West", // 62:4
	"East", // 62:5
	"South", // 63:0
	"South-Southwest", // 63:1
	"Southwest", // 63:2
	"West-Southwest", // 63:3
	"West", // 63:4
	"West-Northwest", // 63:5
	"Northwest", // 63:6
	"North-Northwest", // 63:7
	"North", // 63:8
	"North-Northeast", // 63:9
	"Northeast", // 63:10
	"East-Northeast", // 63:11
	"East", // 63:12
	"East-Southeast", // 63:13
	"Southeast", // 63:14
	"South-Southeast", // 63:15
	"Bottom West Closed", // 64:0
	"Bottom North Closed", // 64:1
	"Bottom East Closed", // 64:2
	"Bottom South Closed", // 64:3
	"Bottom West Open", // 64:4
	"Bottom North Open", // 64:5
	"Bottom East Open", // 64:6
	"Bottom South Open", // 64:7
	"Top Right", // 64:8
	"Top Left", // 64:9
	"", // 65:0
	"", // 65:1
	"North", // 65:2
	"South", // 65:3
	"West", // 65:4
	"East", // 65:5
	"Flat N/S", // 66:0
	"Flat E/W", // 66:1
	"Asc East", // 66:2
	"Asc West", // 66:3
	"Asc North", // 66:4
	"Asc South", // 66:5
	"Corner N/W", // 66:6
	"Corner N/E", // 66:7
	"Corner S/E", // 66:8
	"Corner S/W", // 66:9
	"", // 67:0
	"", // 67:1
	"", // 67:2
	"", // 67:3
	"East Upside Down", // 67:4
	"West Upside Down", // 67:5
	"South Upside Down", // 67:6
	"North Upside Down", // 67:7
	"", // 68:0
	"", // 68:1
	"North", // 68:2
	"South", // 68:3
	"West", // 68:4
	"East", // 68:5
	"East Off", // 69:0
	"East Off", // 69:1
	"West Off", // 69:2
	"South Off", // 69:3
	"North Off", // 69:4
	"South Off", // 69:5
	"East Off", // 69:6
	"South Off", // 69:7
	"East On", // 69:8
	"East On", // 69:9
	"West On", // 69:10
	"South On", // 69:11
	"North On", // 69:12
	"South On", // 69:13
	"East On", // 69:14
	"South On", // 69:15
	"", // 70:0
	"Pressed", // 70:1
	"Bottom West Closed", // 71:0
	"Bottom North Closed", // 71:1
	"Bottom East Closed", // 71:2
	"Bottom South Closed", // 71:3
	"Bottom West Open", // 71:4
	"Bottom North Open", // 71:5
	"Bottom East Open", // 71:6
	"Bottom South Open", // 71:7
	"Top Right", // 71:8
	"Top Left", // 71:9
	"", // 72:0
	"Pressed", // 72:1
	"", // 77:0
	"East", // 77:1
	"West", // 77:2
	"South", // 77:3
	"North", // 77:4
	"Up", // 77:5
	"", // 77:6
	"", // 77:7
	"", // 77:8
	"East Pressed", // 77:9
	"West Pressed", // 77:10
	"South Pressed", // 77:11
	"North Pressed", // 77:12
	"Up Pressed", // 77:13
	"0", // 78:0
	"1", // 78:1
	"2", // 78:2
	"3", // 78:3
	"4", // 78:4
	"5", // 78:5
	"6", // 78:6
	"7", // 78:7
	"0", // 81:0
	"1", // 81:1
	"2", // 81:2
	"3", // 81:3
	"4", // 81:4
	"5", // 81:5
	"6", // 81:6
	"7", // 81:7
	"8", // 81:8
	"9", // 81:9
	"10", // 81:10
	"11", // 81:11
	"12", // 81:12
	"13", // 81:13
	"14", // 81:14
	"15", // 81:15
	"0", // 83:0
	"1", // 83:1
	"2", // 83:2
	"3", // 83:3
	"4", // 83:4
	"5", // 83:5
	"6", // 83:6
	"7", // 83:7
	"8", // 83:8
	"9", // 83:9
	"10", // 83:10
	"11", // 83:11
	"12", // 83:12
	"13", // 83:13
	"14", // 83:14
	"15", // 83:15
	"Empty", // 84:0
	"13", // 84:1
	"Cat", // 84:2
	"sBlock", // 84:3
	"Chirp", // 84:4
	"Far", // 84:5
	"Mall", // 84:6
	"Mellohi", // 84:7
	"Stal", // 84:8
	"Strad", // 84:9
	"Ward", // 84:10
	"11", // 84:11
	"Wait", // 84:12
	"South", // 86:0
	"West", // 86:1
	"North", // 86:2
	"East", // 86:3
	"", // 86:4
	"South", // 91:0
	"West", // 91:1
	"North", // 91:2
	"East", // 91:3
	"", // 91:4
	"0", // 92:0
	"1", // 92:1
	"2", // 92:2
	"3", // 92:3
	"4", // 92:4
	"5", // 92:5
	"North", // 93:0
	"East", // 93:1
	"South", // 93:2
	"West", // 93:3
	"North 2 Tick", // 93:4
	"East 2 Tick", // 93:5
	"South 2 Tick", // 93:6
	"West 2 Tick", // 93:7
	"North 4 Tick", // 93:8
	"East 4 Tick", // 93:9
	"South 4 Tick", // 93:10
	"West 4 Tick", // 93:11
	"North", // 94:0
	"East", // 94:1
	"South", // 94:2
	"West", // 94:3
	"North 2 Tick", // 94:4
	"East 2 Tick", // 94:5
	"South 2 Tick", // 94:6
	"West 2 Tick", // 94:7
	"North 4 Tick", // 94:8
	"East 4 Tick", // 94:9
	"South 4 Tick", // 94:10
	"West 4 Tick", // 94:11
	"Regular", // 95:0
	"Orange", // 95:1
	"Magenta", // 95:2
	"Light Blue", // 95:3
	"Yellow", // 95:4
	"Lime", // 95:5
	"Pink", // 95:6
	"Gray", // 95:7
	"Light Gray", // 95:8
	"Cyan", // 95:9
	"Purple", // 95:10
	"Blue", // 95:11
	"Green", // 95:12
	"Red", // 95:13
	"Black", // 95:14
	"South Closed Bottom", // 96:0
	"North Closed Bottom", // 96:1
	"East Closed Bottom", // 96:2
	"West Closed Bottom", // 96:3
	"South Open Bottom", // 96:4
	"North Open Bottom", // 96:5
	"East Open Bottom", // 96:6
	"West Open Bottom", // 96:7
	"South Closed Top", // 96:8
	"North Closed Top", // 96:9
	"East Closed Top", // 96:10
	"West Closed Top", // 96:11
	"South Open Top", // 96:12
	"North Open Top", // 96:13
	"East Open Top", // 96:14
	"West Open Top", // 96:15
	"Stone", // 97:0
	"Cobblestone", // 97:1
	"Stone Brick", // 97:2
	"Mossy Stone Brick", // 97:3
	"Cracked Stone Brick", // 97:4
	"Chiseled Stone Brick", // 97:5
	"Stone", // 98:0
	"Mossy", // 98:1
	"Cracked", // 98:2
	"Chiseled", // 98:3
	"Pores", // 99:0
	"Cap T+W+N", // 99:1
	"Cap T+N", // 99:2
	"Cap T+N+E", // 99:3
	"Cap T+W", // 99:4
	"Cap T", // 99:5
	"Cap T+E", // 99:6
	"Cap T+S+W", // 99:7
	"Cap T+S", // 99:8
	"Cap T+E+S", // 99:9
	"Stem + Pores T+B", // 99:10
	"", // 99:11
	"", // 99:12
	"", // 99:13
	"Cap All", // 99:14
	"Stem All", // 99:15
	"Pores", // 100:0
	"Cap T+W+N", // 100:1
	"Cap T+N", // 100:2
	"Cap T+N+E", // 100:3
	"Cap T+W", // 100:4
	"Cap T", // 100:5
	"Cap T+E", // 100:6
	"Cap T+S+W", // 100:7
	"Cap T+S", // 100:8
	"Cap T+E+S", // 100:9
	"Stem + Pores T+B", // 100:10
	"", // 100:11
	"", // 100:12
	"", // 100:13
	"Cap All", // 100:14
	"Stem All", // 100:15
	"0", // 104:0
	"1", // 104:1
	"2", // 104:2
	"3", // 104:3
	"4", // 104:4
	"5", // 104:5
	"6", // 104:6
	"7", // 104:7
	"0", // 105:0
	"1", // 105:1
	"2", // 105:2
	"3", // 105:3
	"4", // 105:4
	"5", // 105:5
	"6", // 105:6
	"7", // 105:7
	"", // 106:0
	"", // 106:1
	"S", // 106:2
	"", // 106:3
	"W", // 106:4
	"", // 106:5
	"W+S", // 106:6
	"", // 106:7
	"N", // 106:8
	"", // 106:9
	"N+S", // 106:10
	"", // 106:11
	"N+S+W", // 106:12
	"", // 106:13
	"", // 106:14
	"", // 106:15
	"E", // 106:16
	"", // 106:17
	"E+S", // 106:18
	"", // 106:19
	"E+S+W", // 106:20
	"", // 106:21
	"", // 106:22
	"", // 106:23
	"E+S+W+N", // 106:24
	"South Closed", // 107:0
	"West Closed", // 107:1
	"North Closed", // 107:2
	"East Closed", // 107:3
	"South Open", // 107:4
	"West Open", // 107:5
	"North Open", // 107:6
	"East Open", // 107:7
	"", // 108:0
	"", // 108:1
	"", // 108:2
	"", // 108:3
	"East Upside Down", // 108:4
	"West Upside Down", // 108:5
	"South Upside Down", // 108:6
	"North Upside Down", // 108:7
	"", // 109:0
	"", // 109:1
	"", // 109:2
	"", // 109:3
	"East Upside Down", // 109:4
	"West Upside Down", // 109:5
	"South Upside Down", // 109:6
	"North Upside Down", // 109:7
	"", // 114:0
	"", // 114:1
	"", // 114:2
	"", // 114:3
	"East Upside Down", // 114:4
	"West Upside Down", // 114:5
	"South Upside Down", // 114:6
	"North Upside Down", // 114:7
	"0", // 115:0
	"1", // 115:1
	"2", // 115:2
	"3", // 115:3
	"", // 117:0
	"", // 117:1
	"E", // 117:2
	"", // 117:3
	"SW", // 117:4
	"", // 117:5
	"SW+E", // 117:6
	"", // 117:7
	"NW", // 117:8
	"", // 117:9
	"NW+E", // 117:10
	"", // 117:11
	"NW+E+SW", // 117:12
	"Empty", // 118:0
	"1/3", // 118:1
	"2/3", // 118:2
	"Full", // 118:3
	"South Empty", // 120:0
	"West Empty", // 120:1
	"North Empty", // 120:2
	"East Empty", // 120:3
	"South Full", // 120:4
	"West Full", // 120:5
	"North Full", // 120:6
	"East Full", // 120:7
	"Oak", // 125:0
	"Spruce", // 125:1
	"Birch", // 125:2
	"Jungle", // 125:3
	"Acacia", // 125:4
	"Dark Oak", // 125:5
	"", // 125:6
	"", // 125:7
	"", // 125:8
	"Oak Top", // 125:9
	"Spruce Top", // 125:10
	"Birch Top", // 125:11
	"Jungle Top", // 125:12
	"Acacia Top", // 125:13
	"Dark Oak Top", // 125:14
	"Oak", // 126:0
	"Spruce", // 126:1
	"Birch", // 126:2
	"Jungle", // 126:3
	"Acacia", // 126:4
	"Dark Oak", // 126:5
	"", // 126:6
	"", // 126:7
	"", // 126:8
	"Oak Top", // 126:9
	"Spruce Top", // 126:10
	"Birch Top", // 126:11
	"Jungle Top", // 126:12
	"Acacia Top", // 126:13
	"Dark Oak Top", // 126:14
	"North Small", // 127:0
	"East Small", // 127:1
	"South Small", // 127:2
	"West Small", // 127:3
	"North Medium", // 127:4
	"East Medium", // 127:5
	"South Medium", // 127:6
	"West Medium", // 127:7
	"North Large", // 127:8
	"East Large", // 127:9
	"South Large", // 127:10
	"West Large", // 127:11
	"North EX", // 127:12
	"East EX", // 127:13
	"South EX", // 127:14
	"West EX", // 127:15
	"", // 128:0
	"", // 128:1
	"", // 128:2
	"", // 128:3
	"East Upside Down", // 128:4
	"West Upside Down", // 128:5
	"South Upside Down", // 128:6
	"North Upside Down", // 128:7
	"", // 130:0
	"", // 130:1
	"North", // 130:2
	"South", // 130:3
	"West", // 130:4
	"East", // 130:5
	"South NC", // 131:0
	"West NC", // 131:1
	"North NC", // 131:2
	"East NC", // 131:3
	"South C", // 131:4
	"West C", // 131:5
	"North C", // 131:6
	"East C", // 131:7
	"South A", // 131:8
	"West A", // 131:9
	"North A", // 131:10
	"East A", // 131:11
	"South CA", // 131:12
	"West CA", // 131:13
	"North CA", // 131:14
	"East CA", // 131:15
	"UA", // 132:0
	"", // 132:1
	"LA", // 132:2
	"", // 132:3
	"", // 132:4
	"", // 132:5
	"", // 132:6
	"", // 132:7
	"", // 132:8
	"", // 132:9
	"", // 132:10
	"", // 132:11
	"", // 132:12
	"", // 132:13
	"", // 132:14
	"", // 132:15
	"FA", // 132:16
	"", // 134:0
	"", // 134:1
	"", // 134:2
	"", // 134:3
	"East Upside Down", // 134:4
	"West Upside Down", // 134:5
	"South Upside Down", // 134:6
	"North Upside Down", // 134:7
	"", // 135:0
	"", // 135:1
	"", // 135:2
	"", // 135:3
	"East Upside Down", // 135:4
	"West Upside Down", // 135:5
	"South Upside Down", // 135:6
	"North Upside Down", // 135:7
	"", // 136:0
	"", // 136:1
	"", // 136:2
	"", // 136:3
	"East Upside Down", // 136:4
	"West Upside Down", // 136:5
	"South Upside Down", // 136:6
	"North Upside Down", // 136:7
	"Plain", // 139:0
	"Mossy", // 139:1
	"Empty", // 140:0
	"Poppy", // 140:1
	"Dandelion", // 140:2
	"Oak", // 140:3
	"Spruce", // 140:4
	"Birch", // 140:5
	"Jungle", // 140:6
	"Red Mushroom", // 140:7
	"Brown Mushroom", // 140:8
	"Cactus", // 140:9
	"Dead Bush", // 140:10
	"Fern", // 140:11
	"Acacia", // 140:12
	"Dark Oak", // 140:13
	"", // 143:0
	"East", // 143:1
	"West", // 143:2
	"South", // 143:3
	"North", // 143:4
	"Up", // 143:5
	"", // 143:6
	"", // 143:7
	"", // 143:8
	"East Pressed", // 143:9
	"West Pressed", // 143:10
	"South Pressed", // 143:11
	"North Pressed", // 143:12
	"Up Pressed", // 143:13
	"", // 144:0
	"Floor", // 144:1
	"North", // 144:2
	"South", // 144:3
	"East", // 144:4
	"West", // 144:5
	"North-South No Damage", // 145:0
	"East-West No Damage", // 145:1
	"", // 145:2
	"", // 145:3
	"North-South Slightly Damaged", // 145:4
	"East-West Slightly Damaged", // 145:5
	"", // 145:6
	"", // 145:7
	"North-South Very Damaged", // 145:8
	"East-West Very Damaged", // 145:9
	"", // 146:0
	"", // 146:1
	"North", // 146:2
	"South", // 146:3
	"West", // 146:4
	"East", // 146:5
	"", // 147:0
	"Pressed", // 147:1
	"", // 148:0
	"Pressed", // 148:1
	"North Comparison", // 149:0
	"East Comparison", // 149:1
	"South Comparison", // 149:2
	"West Comparison", // 149:3
	"North Subtraction", // 149:4
	"East Subtraction", // 149:5
	"South Subtraction", // 149:6
	"West Subtraction", // 149:7
	"North Comparison Powered", // 149:8
	"East Comparison Powered", // 149:9
	"South Comparison Powered", // 149:10
	"West Comparison Powered", // 149:11
	"North Subtraction Powered", // 149:12
	"East Subtraction Powered", // 149:13
	"South Subtraction Powered", // 149:14
	"West Subtraction Powered", // 149:15
	"North Comparison", // 150:0
	"East Comparison", // 150:1
	"South Comparison", // 150:2
	"West Comparison", // 150:3
	"North Subtraction", // 150:4
	"East Subtraction", // 150:5
	"South Subtraction", // 150:6
	"West Subtraction", // 150:7
	"North Comparison Powered", // 150:8
	"East Comparison Powered", // 150:9
	"South Comparison Powered", // 150:10
	"West Comparison Powered", // 150:11
	"North Subtraction Powered", // 150:12
	"East Subtraction Powered", // 150:13
	"South Subtraction Powered", // 150:14
	"West Subtraction Powered", // 150:15
	"Down", // 154:0
	"Up", // 154:1
	"North", // 154:2
	"South", // 154:3
	"West", // 154:4
	"East", // 154:5
	"Plain", // 155:0
	"Chiseled", // 155:1
	"Vertical Pillar", // 155:2
	"N/S Pillar", // 155:3
	"E/W Pillar", // 155:4
	"", // 156:0
	"", // 156:1
	"", // 156:2
	"", // 156:3
	"East Upside Down", // 156:4
	"West Upside Down", // 156:5
	"South Upside Down", // 156:6
	"North Upside Down", // 156:7
	"Down", // 158:0
	"Up", // 158:1
	"North", // 158:2
	"South", // 158:3
	"West", // 158:4
	"East", // 158:5
	"Regular", // 159:0
	"Orange", // 159:1
	"Magenta", // 159:2
	"Light Blue", // 159:3
	"Yellow", // 159:4
	"Lime", // 159:5
	"Pink", // 159:6
	"Gray", // 159:7
	"Light Gray", // 159:8
	"Cyan", // 159:9
	"Purple", // 159:10
	"Blue", // 159:11
	"Green", // 159:12
	"Red", // 159:13
	"Black", // 159:14
	"Regular", // 160:0
	"Orange", // 160:1
	"Magenta", // 160:2
	"Light Blue", // 160:3
	"Yellow", // 160:4
	"Lime", // 160:5
	"Pink", // 160:6
	"Gray", // 160:7
	"Light Gray", // 160:8
	"Cyan", // 160:9
	"Purple", // 160:10
	"Blue", // 160:11
	"Green", // 160:12
	"Red", // 160:13
	"Black", // 160:14
	"Acacia", // 161:0
	"Dark Oak", // 161:1
	"Acacia", // 162:0
	"Dark Oak", // 162:1
	"Acacia PH", // 162:2
	"Dark Oak PH", // 162:3
	"Acacia E/W", // 162:4
	"Dark Oak E/W", // 162:5
	"Acacia E/W PH", // 162:6
	"Dark Oak E/W PH", // 162:7
	"Acacia N/S", // 162:8
	"Dark Oak N/S", // 162:9
	"Acacia N/S PH", // 162:10
	"Dark Oak N/S PH", // 162:11
	"Acacia Bark", // 162:12
	"Dark Oak Bark", // 162:13
	"Acacia Bark PH", // 162:14
	"Dark Oak Bark PH", // 162:15
	"", // 163:0
	"", // 163:1
	"", // 163:2
	"", // 163:3
	"East Upside Down", // 163:4
	"West Upside Down", // 163:5
	"South Upside Down", // 163:6
	"North Upside Down", // 163:7
	"", // 164:0
	"", // 164:1
	"", // 164:2
	"", // 164:3
	"East Upside Down", // 164:4
	"West Upside Down", // 164:5
	"South Upside Down", // 164:6
	"North Upside Down", // 164:7
	"Regular", // 171:0
	"Orange", // 171:1
	"Magenta", // 171:2
	"Light Blue", // 171:3
	"Yellow", // 171:4
	"Lime", // 171:5
	"Pink", // 171:6
	"Gray", // 171:7
	"Light Gray", // 171:8
	"Cyan", // 171:9
	"Purple", // 171:10
	"Blue", // 171:11
	"Green", // 171:12
	"Red", // 171:13
	"Black", // 171:14
	"Sunflower", // 175:0
	"Lilac", // 175:1
	"Double Tallgrass", // 175:2
	"Large Fern", // 175:3
	"Rose Bush", // 175:4
	"Peony", // 175:5
};
