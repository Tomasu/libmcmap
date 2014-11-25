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
	"Slime", // 165
	"Barrier", // 166
	"Iron Trapdoor", // 167
	"Prismarine", // 168
	"Sea Lantern", // 169
	"Hay Block", // 170
	"Carpet", // 171
	"Hardened Clay", // 172
	"Coal Block", // 173
	"Packed Ice", // 174
	"Double Plant", // 175
	"Standing Banner", // 176
	"Wall Banner", // 177
	"Daylight Detector Inverted", // 178
	"Red Sandstone", // 179
	"Red Sandstone Stairs", // 180
	"Double Stone Slab2", // 181
	"Slab2", // 182
	"Spruce Fence Gate", // 183
	"Birch Fence Gate", // 184
	"Jungle Fence Gate", // 185
	"Dark Oak Fence Gate", // 186
	"Acacia Fence Gate", // 187
	"Spruce Fence", // 188
	"Birch Fence", // 189
	"Jungle Fence", // 190
	"Dark Oak Fence", // 191
	"Acacia Fence", // 192
	"Spruce Door", // 193
	"Birch Door", // 194
	"Jungle Door", // 195
	"Acacia Door", // 196
	"Dark Oak Door", // 197
};

const char *BlockStateNames[BLOCK_COUNT] = {
	"air", // 0
	"stone", // 1
	"grass", // 2
	"dirt", // 3
	"cobblestone", // 4
	"planks", // 5
	"sapling", // 6
	"bedrock", // 7
	"flowing_water", // 8
	"water", // 9
	"flowing_lava", // 10
	"lava", // 11
	"sand", // 12
	"gravel", // 13
	"gold_ore", // 14
	"iron_ore", // 15
	"coal_ore", // 16
	"log", // 17
	"leaves", // 18
	"sponge", // 19
	"glass", // 20
	"lapis_ore", // 21
	"lapis_block", // 22
	"dispenser", // 23
	"sandstone", // 24
	"noteblock", // 25
	"bed", // 26
	"golden_rail", // 27
	"detector_rail", // 28
	"sticky_piston", // 29
	"web", // 30
	"tallgrass", // 31
	"deadbush", // 32
	"piston", // 33
	"piston_head", // 34
	"wool", // 35
	"piston_extension", // 36
	"yellow_flower", // 37
	"red_flower", // 38
	"brown_mushroom", // 39
	"red_mushroom", // 40
	"gold_block", // 41
	"iron_block", // 42
	"double_stone_slab", // 43
	"stone_slab", // 44
	"brick_block", // 45
	"tnt", // 46
	"bookshelf", // 47
	"mossy_cobblestone", // 48
	"obsidian", // 49
	"torch", // 50
	"fire", // 51
	"mob_spawner", // 52
	"oak_stairs", // 53
	"chest", // 54
	"redstone_wire", // 55
	"diamond_ore", // 56
	"diamond_block", // 57
	"crafting_table", // 58
	"wheat", // 59
	"farmland", // 60
	"furnace", // 61
	"lit_furnace", // 62
	"standing_sign", // 63
	"wooden_door", // 64
	"ladder", // 65
	"rail", // 66
	"stone_stairs", // 67
	"wall_sign", // 68
	"lever", // 69
	"stone_pressure_plate", // 70
	"iron_door", // 71
	"wooden_pressure_plate", // 72
	"redstone_ore", // 73
	"lit_redstone_ore", // 74
	"unlit_redstone_torch", // 75
	"redstone_torch", // 76
	"stone_button", // 77
	"snow_layer", // 78
	"ice", // 79
	"snow", // 80
	"cactus", // 81
	"clay", // 82
	"reeds", // 83
	"jukebox", // 84
	"fence", // 85
	"pumpkin", // 86
	"netherrack", // 87
	"soul_sand", // 88
	"glowstone", // 89
	"portal", // 90
	"lit_pumpkin", // 91
	"cake", // 92
	"unpowered_repeater", // 93
	"powered_repeater", // 94
	"stained_glass", // 95
	"trapdoor", // 96
	"monster_egg", // 97
	"stonebrick", // 98
	"brown_mushroom_block", // 99
	"red_mushroom_block", // 100
	"iron_bars", // 101
	"glass_pane", // 102
	"melon_block", // 103
	"pumpkin_stem", // 104
	"melon_stem", // 105
	"vine", // 106
	"fence_gate", // 107
	"brick_stairs", // 108
	"stone_brick_stairs", // 109
	"mycelium", // 110
	"waterlily", // 111
	"nether_brick", // 112
	"nether_brick_fence", // 113
	"nether_brick_stairs", // 114
	"nether_wart", // 115
	"enchanting_table", // 116
	"brewing_stand", // 117
	"cauldron", // 118
	"end_portal", // 119
	"end_portal_frame", // 120
	"end_stone", // 121
	"dragon_egg", // 122
	"redstone_lamp", // 123
	"lit_redstone_lamp", // 124
	"double_wooden_slab", // 125
	"wooden_slab", // 126
	"cocoa", // 127
	"sandstone_stairs", // 128
	"emerald_ore", // 129
	"ender_chest", // 130
	"tripwire_hook", // 131
	"tripwire", // 132
	"emerald_block", // 133
	"spruce_stairs", // 134
	"birch_stairs", // 135
	"jungle_stairs", // 136
	"command_block", // 137
	"beacon", // 138
	"cobblestone_wall", // 139
	"flower_pot", // 140
	"carrots", // 141
	"potatoes", // 142
	"wooden_button", // 143
	"skull", // 144
	"anvil", // 145
	"trapped_chest", // 146
	"light_weighted_pressure_plate", // 147
	"heavy_weighted_pressure_plate", // 148
	"unpowered_comparator", // 149
	"powered_comparator", // 150
	"daylight_detector", // 151
	"redstone_block", // 152
	"quartz_ore", // 153
	"hopper", // 154
	"quartz_block", // 155
	"quartz_stairs", // 156
	"activator_rail", // 157
	"dropper", // 158
	"stained_hardened_clay", // 159
	"stained_glass_pane", // 160
	"leaves2", // 161
	"log2", // 162
	"acacia_stairs", // 163
	"dark_oak_stairs", // 164
	"slime", // 165
	"barrier", // 166
	"iron_trapdoor", // 167
	"prismarine", // 168
	"sea_lantern", // 169
	"hay_block", // 170
	"carpet", // 171
	"hardened_clay", // 172
	"coal_block", // 173
	"packed_ice", // 174
	"double_plant", // 175
	"standing_banner", // 176
	"wall_banner", // 177
	"daylight_detector_inverted", // 178
	"red_sandstone", // 179
	"red_sandstone_stairs", // 180
	"double_stone_slab2", // 181
	"stone_slab2", // 182
	"spruce_fence_gate", // 183
	"birch_fence_gate", // 184
	"jungle_fence_gate", // 185
	"dark_oak_fence_gate", // 186
	"acacia_fence_gate", // 187
	"spruce_fence", // 188
	"birch_fence", // 189
	"jungle_fence", // 190
	"dark_oak_fence", // 191
	"acacia_fence", // 192
	"spruce_door", // 193
	"birch_door", // 194
	"jungle_door", // 195
	"acacia_door", // 196
	"dark_oak_door", // 197
};

SubBlockRange subBlockRange[BLOCK_COUNT] = {
	{ 0, 0 },
	{ 0, 0 }, // 1
	{ 0, 0 }, // 2
	{ 0, 0 }, // 3
	{ 0, 0 }, // 4
	{ 0, 6 }, // 5
	{ 6, 6 }, // 6
	{ 12, 0 }, // 7
	{ 12, 0 }, // 8
	{ 12, 0 }, // 9
	{ 12, 0 }, // 10
	{ 12, 0 }, // 11
	{ 12, 2 }, // 12
	{ 14, 0 }, // 13
	{ 14, 0 }, // 14
	{ 14, 0 }, // 15
	{ 14, 0 }, // 16
	{ 14, 16 }, // 17
	{ 30, 4 }, // 18
	{ 34, 0 }, // 19
	{ 34, 0 }, // 20
	{ 34, 0 }, // 21
	{ 34, 0 }, // 22
	{ 34, 6 }, // 23
	{ 40, 3 }, // 24
	{ 43, 0 }, // 25
	{ 43, 16 }, // 26
	{ 59, 16 }, // 27
	{ 75, 0 }, // 28
	{ 75, 0 }, // 29
	{ 75, 0 }, // 30
	{ 75, 4 }, // 31
	{ 79, 0 }, // 32
	{ 79, 14 }, // 33
	{ 93, 0 }, // 34
	{ 93, 16 }, // 35
	{ 109, 14 }, // 36
	{ 123, 1 }, // 37
	{ 124, 8 }, // 38
	{ 132, 0 }, // 39
	{ 132, 0 }, // 40
	{ 132, 0 }, // 41
	{ 132, 0 }, // 42
	{ 132, 16 }, // 43
	{ 148, 16 }, // 44
	{ 164, 0 }, // 45
	{ 164, 0 }, // 46
	{ 164, 0 }, // 47
	{ 164, 0 }, // 48
	{ 164, 0 }, // 49
	{ 164, 5 }, // 50
	{ 169, 0 }, // 51
	{ 169, 0 }, // 52
	{ 169, 8 }, // 53
	{ 177, 6 }, // 54
	{ 183, 16 }, // 55
	{ 199, 0 }, // 56
	{ 199, 0 }, // 57
	{ 199, 0 }, // 58
	{ 199, 0 }, // 59
	{ 199, 9 }, // 60
	{ 208, 6 }, // 61
	{ 214, 6 }, // 62
	{ 220, 16 }, // 63
	{ 236, 10 }, // 64
	{ 246, 6 }, // 65
	{ 252, 10 }, // 66
	{ 262, 8 }, // 67
	{ 270, 6 }, // 68
	{ 276, 16 }, // 69
	{ 292, 2 }, // 70
	{ 294, 10 }, // 71
	{ 304, 2 }, // 72
	{ 306, 0 }, // 73
	{ 306, 0 }, // 74
	{ 306, 0 }, // 75
	{ 306, 0 }, // 76
	{ 306, 14 }, // 77
	{ 320, 8 }, // 78
	{ 328, 0 }, // 79
	{ 328, 0 }, // 80
	{ 328, 16 }, // 81
	{ 344, 0 }, // 82
	{ 344, 16 }, // 83
	{ 360, 13 }, // 84
	{ 373, 0 }, // 85
	{ 373, 5 }, // 86
	{ 378, 0 }, // 87
	{ 378, 0 }, // 88
	{ 378, 0 }, // 89
	{ 378, 0 }, // 90
	{ 378, 5 }, // 91
	{ 383, 6 }, // 92
	{ 389, 12 }, // 93
	{ 401, 12 }, // 94
	{ 413, 15 }, // 95
	{ 428, 16 }, // 96
	{ 444, 6 }, // 97
	{ 450, 4 }, // 98
	{ 454, 16 }, // 99
	{ 470, 16 }, // 100
	{ 486, 0 }, // 101
	{ 486, 0 }, // 102
	{ 486, 0 }, // 103
	{ 486, 8 }, // 104
	{ 494, 8 }, // 105
	{ 502, 25 }, // 106
	{ 527, 8 }, // 107
	{ 535, 8 }, // 108
	{ 543, 8 }, // 109
	{ 551, 0 }, // 110
	{ 551, 0 }, // 111
	{ 551, 0 }, // 112
	{ 551, 0 }, // 113
	{ 551, 8 }, // 114
	{ 559, 4 }, // 115
	{ 563, 0 }, // 116
	{ 563, 13 }, // 117
	{ 576, 4 }, // 118
	{ 580, 0 }, // 119
	{ 580, 8 }, // 120
	{ 588, 0 }, // 121
	{ 588, 0 }, // 122
	{ 588, 0 }, // 123
	{ 588, 0 }, // 124
	{ 588, 15 }, // 125
	{ 603, 15 }, // 126
	{ 618, 16 }, // 127
	{ 634, 8 }, // 128
	{ 642, 0 }, // 129
	{ 642, 6 }, // 130
	{ 648, 16 }, // 131
	{ 664, 17 }, // 132
	{ 681, 0 }, // 133
	{ 681, 8 }, // 134
	{ 689, 8 }, // 135
	{ 697, 8 }, // 136
	{ 705, 0 }, // 137
	{ 705, 0 }, // 138
	{ 705, 2 }, // 139
	{ 707, 14 }, // 140
	{ 721, 0 }, // 141
	{ 721, 0 }, // 142
	{ 721, 14 }, // 143
	{ 735, 6 }, // 144
	{ 741, 10 }, // 145
	{ 751, 6 }, // 146
	{ 757, 2 }, // 147
	{ 759, 2 }, // 148
	{ 761, 16 }, // 149
	{ 777, 16 }, // 150
	{ 793, 0 }, // 151
	{ 793, 0 }, // 152
	{ 793, 0 }, // 153
	{ 793, 6 }, // 154
	{ 799, 5 }, // 155
	{ 804, 8 }, // 156
	{ 812, 0 }, // 157
	{ 812, 6 }, // 158
	{ 818, 15 }, // 159
	{ 833, 15 }, // 160
	{ 848, 2 }, // 161
	{ 850, 16 }, // 162
	{ 866, 8 }, // 163
	{ 874, 8 }, // 164
	{ 882, 0 }, // 165
	{ 882, 0 }, // 166
	{ 882, 0 }, // 167
	{ 882, 0 }, // 168
	{ 882, 0 }, // 169
	{ 882, 0 }, // 170
	{ 882, 15 }, // 171
	{ 897, 0 }, // 172
	{ 897, 0 }, // 173
	{ 897, 0 }, // 174
	{ 897, 6 }, // 175
	{ 903, 0 }, // 176
	{ 903, 0 }, // 177
	{ 903, 0 }, // 178
	{ 903, 0 }, // 179
	{ 903, 0 }, // 180
	{ 903, 0 }, // 181
	{ 903, 0 }, // 182
	{ 903, 0 }, // 183
	{ 903, 0 }, // 184
	{ 903, 0 }, // 185
	{ 903, 0 }, // 186
	{ 903, 0 }, // 187
	{ 903, 0 }, // 188
	{ 903, 0 }, // 189
	{ 903, 0 }, // 190
	{ 903, 0 }, // 191
	{ 903, 0 }, // 192
	{ 903, 0 }, // 193
	{ 903, 0 }, // 194
	{ 903, 0 }, // 195
	{ 903, 0 }, // 196
	{ 903, 0 }, // 197
};

const char *SubBlockNames[SUBBLOCKNAME_COUNT] = {
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
	"Normal", // 12:0
	"Red", // 12:1
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
	"Spruce", // 18:1
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
	"Shrub", // 31:0
	"Grass", // 31:1
	"Fern", // 31:2
	"Shrub2", // 31:3
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
	"Ceiling East Off", // 69:0
	"East Off", // 69:1
	"West Off", // 69:2
	"South Off", // 69:3
	"North Off", // 69:4
	"Ground South Off", // 69:5
	"Ground East Off", // 69:6
	"Ceiling South Off", // 69:7
	"Ceiling East On", // 69:8
	"East On", // 69:9
	"West On", // 69:10
	"South On", // 69:11
	"North On", // 69:12
	"Ground South On", // 69:13
	"Ground East On", // 69:14
	"Ceiling South On", // 69:15
	"Normal", // 70:0
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
	"Normal", // 72:0
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
	"White", // 95:0
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
	"Normal", // 139:0
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
	"Normal", // 147:0
	"Pressed", // 147:1
	"Normal", // 148:0
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
	"Normal", // 155:0
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
	"White", // 159:0
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
	"White", // 160:0
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
	"White", // 171:0
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

const char *SubBlockStateNames[SUBBLOCKNAME_COUNT] = {
	"oak_planks", // 5:0
	"spruce_planks", // 5:1
	"birch_planks", // 5:2
	"jungle_planks", // 5:3
	"acacia_planks", // 5:4
	"dark_oak_planks", // 5:5
	"oak_sapling", // 6:0
	"spruce_sapling", // 6:1
	"birch_sapling", // 6:2
	"jungle_sapling", // 6:3
	"acacia_sapling", // 6:4
	"dark_oak_sapling", // 6:5
	"sand", // 12:0
	"red_sand", // 12:1
	"oak_log", // 17:0
	"spruce_log", // 17:1
	"birch_log", // 17:2
	"jungle_log", // 17:3
	"oak_log", // 17:4
	"spruce_log", // 17:5
	"birch_log", // 17:6
	"jungle_log", // 17:7
	"oak_log", // 17:8
	"spruce_log", // 17:9
	"birch_log", // 17:10
	"jungle_log", // 17:11
	"oak_log", // 17:12
	"spruce_log", // 17:13
	"birch_log", // 17:14
	"jungle_log", // 17:15
	"oak_leaves", // 18:0
	"spruce_leaves", // 18:1
	"birch_leaves", // 18:2
	"jungle_leaves", // 18:3
	"dispenser", // 23:0
	"dispenser", // 23:1
	"dispenser", // 23:2
	"dispenser", // 23:3
	"dispenser", // 23:4
	"dispenser", // 23:5
	"sandstone", // 24:0
	"chiseled_sandstone", // 24:1
	"smooth_sandstone", // 24:2
	"bed", // 26:0
	"bed", // 26:1
	"bed", // 26:2
	"bed", // 26:3
	"bed", // 26:4
	"bed", // 26:5
	"bed", // 26:6
	"bed", // 26:7
	"bed", // 26:8
	"bed", // 26:9
	"bed", // 26:10
	"bed", // 26:11
	"bed", // 26:12
	"bed", // 26:13
	"bed", // 26:14
	"bed", // 26:15
	"golden_rail", // 27:0
	"golden_rail", // 27:1
	"golden_rail", // 27:2
	"golden_rail", // 27:3
	"golden_rail", // 27:4
	"golden_rail", // 27:5
	"golden_rail", // 27:6
	"golden_rail", // 27:7
	"golden_rail", // 27:8
	"golden_rail", // 27:9
	"golden_rail", // 27:10
	"golden_rail", // 27:11
	"golden_rail", // 27:12
	"golden_rail", // 27:13
	"golden_rail", // 27:14
	"golden_rail", // 27:15
	"dead_bush", // 31:0
	"tall_grass", // 31:1
	"fern", // 31:2
	"tallgrass", // 31:3
	"piston", // 33:0
	"piston", // 33:1
	"piston", // 33:2
	"piston", // 33:3
	"piston", // 33:4
	"piston", // 33:5
	"piston", // 33:6
	"piston", // 33:7
	"piston", // 33:8
	"piston", // 33:9
	"piston", // 33:10
	"piston", // 33:11
	"piston", // 33:12
	"piston", // 33:13
	"white_wool", // 35:0
	"orange_wool", // 35:1
	"magenta_wool", // 35:2
	"light_blue_wool", // 35:3
	"yellow_wool", // 35:4
	"lime_wool", // 35:5
	"pink_wool", // 35:6
	"gray_wool", // 35:7
	"light_gray_wool", // 35:8
	"cyan_wool", // 35:9
	"purple_wool", // 35:10
	"blue_wool", // 35:11
	"green_wool", // 35:12
	"red_wool", // 35:13
	"black_wool", // 35:14
	"wool", // 35:15
	"piston_extension", // 36:0
	"piston_extension", // 36:1
	"piston_extension", // 36:2
	"piston_extension", // 36:3
	"piston_extension", // 36:4
	"piston_extension", // 36:5
	"piston_extension", // 36:6
	"piston_extension", // 36:7
	"piston_extension", // 36:8
	"piston_extension", // 36:9
	"piston_extension", // 36:10
	"piston_extension", // 36:11
	"piston_extension", // 36:12
	"piston_extension", // 36:13
	"dandelion", // 37:0
	"poppy", // 38:0
	"blue_orchid", // 38:1
	"allium", // 38:2
	"azure_bluet", // 38:3
	"red_tulip", // 38:4
	"white_tulip", // 38:5
	"pink_tulip", // 38:6
	"oxeye_daisy", // 38:7
	"stone_double_slab", // 43:0
	"sandstone_double_slab", // 43:1
	"wood_old_double_slab", // 43:2
	"cobblestone_double_slab", // 43:3
	"brick_double_slab", // 43:4
	"stone_brick_double_slab", // 43:5
	"nether_brick_double_slab", // 43:6
	"quartz_double_slab", // 43:7
	"stone_double_slab", // 43:8
	"sandstone_double_slab", // 43:9
	"quartz_double_slab", // 43:10
	"double_stone_slab", // 43:11
	"double_stone_slab", // 43:12
	"double_stone_slab", // 43:13
	"double_stone_slab", // 43:14
	"double_stone_slab", // 43:15
	"stone_slab", // 44:0
	"sandstone_slab", // 44:1
	"wood_old_slab", // 44:2
	"cobblestone_slab", // 44:3
	"brick_slab", // 44:4
	"stone_brick_slab", // 44:5
	"nether_brick_slab", // 44:6
	"quartz_slab", // 44:7
	"stone_slab", // 44:8
	"sandstone_slab", // 44:9
	"wood_old_slab", // 44:10
	"cobblestone_slab", // 44:11
	"brick_slab", // 44:12
	"stone_brick_slab", // 44:13
	"nether_brick_slab", // 44:14
	"quartz_slab", // 44:15
	"torch", // 50:0
	"torch", // 50:1
	"torch", // 50:2
	"torch", // 50:3
	"torch", // 50:4
	"oak_stairs", // 53:0
	"oak_stairs", // 53:1
	"oak_stairs", // 53:2
	"oak_stairs", // 53:3
	"oak_stairs", // 53:4
	"oak_stairs", // 53:5
	"oak_stairs", // 53:6
	"oak_stairs", // 53:7
	"chest", // 54:0
	"chest", // 54:1
	"chest", // 54:2
	"chest", // 54:3
	"chest", // 54:4
	"chest", // 54:5
	"redstone_wire", // 55:0
	"redstone_wire", // 55:1
	"redstone_wire", // 55:2
	"redstone_wire", // 55:3
	"redstone_wire", // 55:4
	"redstone_wire", // 55:5
	"redstone_wire", // 55:6
	"redstone_wire", // 55:7
	"redstone_wire", // 55:8
	"redstone_wire", // 55:9
	"redstone_wire", // 55:10
	"redstone_wire", // 55:11
	"redstone_wire", // 55:12
	"redstone_wire", // 55:13
	"redstone_wire", // 55:14
	"redstone_wire", // 55:15
	"farmland", // 60:0
	"farmland", // 60:1
	"farmland", // 60:2
	"farmland", // 60:3
	"farmland", // 60:4
	"farmland", // 60:5
	"farmland", // 60:6
	"farmland", // 60:7
	"farmland", // 60:8
	"furnace", // 61:0
	"furnace", // 61:1
	"furnace", // 61:2
	"furnace", // 61:3
	"furnace", // 61:4
	"furnace", // 61:5
	"lit_furnace", // 62:0
	"lit_furnace", // 62:1
	"lit_furnace", // 62:2
	"lit_furnace", // 62:3
	"lit_furnace", // 62:4
	"lit_furnace", // 62:5
	"standing_sign", // 63:0
	"standing_sign", // 63:1
	"standing_sign", // 63:2
	"standing_sign", // 63:3
	"standing_sign", // 63:4
	"standing_sign", // 63:5
	"standing_sign", // 63:6
	"standing_sign", // 63:7
	"standing_sign", // 63:8
	"standing_sign", // 63:9
	"standing_sign", // 63:10
	"standing_sign", // 63:11
	"standing_sign", // 63:12
	"standing_sign", // 63:13
	"standing_sign", // 63:14
	"standing_sign", // 63:15
	"wooden_door", // 64:0
	"wooden_door", // 64:1
	"wooden_door", // 64:2
	"wooden_door", // 64:3
	"wooden_door", // 64:4
	"wooden_door", // 64:5
	"wooden_door", // 64:6
	"wooden_door", // 64:7
	"wooden_door", // 64:8
	"wooden_door", // 64:9
	"ladder", // 65:0
	"ladder", // 65:1
	"ladder", // 65:2
	"ladder", // 65:3
	"ladder", // 65:4
	"ladder", // 65:5
	"rail", // 66:0
	"rail", // 66:1
	"rail", // 66:2
	"rail", // 66:3
	"rail", // 66:4
	"rail", // 66:5
	"rail", // 66:6
	"rail", // 66:7
	"rail", // 66:8
	"rail", // 66:9
	"stone_stairs", // 67:0
	"stone_stairs", // 67:1
	"stone_stairs", // 67:2
	"stone_stairs", // 67:3
	"stone_stairs", // 67:4
	"stone_stairs", // 67:5
	"stone_stairs", // 67:6
	"stone_stairs", // 67:7
	"wall_sign", // 68:0
	"wall_sign", // 68:1
	"wall_sign", // 68:2
	"wall_sign", // 68:3
	"wall_sign", // 68:4
	"wall_sign", // 68:5
	"lever", // 69:0
	"lever", // 69:1
	"lever", // 69:2
	"lever", // 69:3
	"lever", // 69:4
	"lever", // 69:5
	"lever", // 69:6
	"lever", // 69:7
	"lever", // 69:8
	"lever", // 69:9
	"lever", // 69:10
	"lever", // 69:11
	"lever", // 69:12
	"lever", // 69:13
	"lever", // 69:14
	"lever", // 69:15
	"stone_pressure_plate", // 70:0
	"stone_pressure_plate", // 70:1
	"iron_door", // 71:0
	"iron_door", // 71:1
	"iron_door", // 71:2
	"iron_door", // 71:3
	"iron_door", // 71:4
	"iron_door", // 71:5
	"iron_door", // 71:6
	"iron_door", // 71:7
	"iron_door", // 71:8
	"iron_door", // 71:9
	"wooden_pressure_plate", // 72:0
	"wooden_pressure_plate", // 72:1
	"stone_button", // 77:0
	"stone_button", // 77:1
	"stone_button", // 77:2
	"stone_button", // 77:3
	"stone_button", // 77:4
	"stone_button", // 77:5
	"stone_button", // 77:6
	"stone_button", // 77:7
	"stone_button", // 77:8
	"stone_button", // 77:9
	"stone_button", // 77:10
	"stone_button", // 77:11
	"stone_button", // 77:12
	"stone_button", // 77:13
	"snow_layer", // 78:0
	"snow_layer", // 78:1
	"snow_layer", // 78:2
	"snow_layer", // 78:3
	"snow_layer", // 78:4
	"snow_layer", // 78:5
	"snow_layer", // 78:6
	"snow_layer", // 78:7
	"cactus", // 81:0
	"cactus", // 81:1
	"cactus", // 81:2
	"cactus", // 81:3
	"cactus", // 81:4
	"cactus", // 81:5
	"cactus", // 81:6
	"cactus", // 81:7
	"cactus", // 81:8
	"cactus", // 81:9
	"cactus", // 81:10
	"cactus", // 81:11
	"cactus", // 81:12
	"cactus", // 81:13
	"cactus", // 81:14
	"cactus", // 81:15
	"reeds", // 83:0
	"reeds", // 83:1
	"reeds", // 83:2
	"reeds", // 83:3
	"reeds", // 83:4
	"reeds", // 83:5
	"reeds", // 83:6
	"reeds", // 83:7
	"reeds", // 83:8
	"reeds", // 83:9
	"reeds", // 83:10
	"reeds", // 83:11
	"reeds", // 83:12
	"reeds", // 83:13
	"reeds", // 83:14
	"reeds", // 83:15
	"jukebox", // 84:0
	"jukebox", // 84:1
	"jukebox", // 84:2
	"jukebox", // 84:3
	"jukebox", // 84:4
	"jukebox", // 84:5
	"jukebox", // 84:6
	"jukebox", // 84:7
	"jukebox", // 84:8
	"jukebox", // 84:9
	"jukebox", // 84:10
	"jukebox", // 84:11
	"jukebox", // 84:12
	"pumpkin", // 86:0
	"pumpkin", // 86:1
	"pumpkin", // 86:2
	"pumpkin", // 86:3
	"pumpkin", // 86:4
	"lit_pumpkin", // 91:0
	"lit_pumpkin", // 91:1
	"lit_pumpkin", // 91:2
	"lit_pumpkin", // 91:3
	"lit_pumpkin", // 91:4
	"cake", // 92:0
	"cake", // 92:1
	"cake", // 92:2
	"cake", // 92:3
	"cake", // 92:4
	"cake", // 92:5
	"unpowered_repeater", // 93:0
	"unpowered_repeater", // 93:1
	"unpowered_repeater", // 93:2
	"unpowered_repeater", // 93:3
	"unpowered_repeater", // 93:4
	"unpowered_repeater", // 93:5
	"unpowered_repeater", // 93:6
	"unpowered_repeater", // 93:7
	"unpowered_repeater", // 93:8
	"unpowered_repeater", // 93:9
	"unpowered_repeater", // 93:10
	"unpowered_repeater", // 93:11
	"powered_repeater", // 94:0
	"powered_repeater", // 94:1
	"powered_repeater", // 94:2
	"powered_repeater", // 94:3
	"powered_repeater", // 94:4
	"powered_repeater", // 94:5
	"powered_repeater", // 94:6
	"powered_repeater", // 94:7
	"powered_repeater", // 94:8
	"powered_repeater", // 94:9
	"powered_repeater", // 94:10
	"powered_repeater", // 94:11
	"white_stained_glass", // 95:0
	"orange_stained_glass", // 95:1
	"magenta_stained_glass", // 95:2
	"light_blue_stained_glass", // 95:3
	"yellow_stained_glass", // 95:4
	"lime_stained_glass", // 95:5
	"pink_stained_glass", // 95:6
	"gray_stained_glass", // 95:7
	"light_gray_stained_glass", // 95:8
	"cyan_stained_glass", // 95:9
	"purple_stained_glass", // 95:10
	"blue_stained_glass", // 95:11
	"green_stained_glass", // 95:12
	"red_stained_glass", // 95:13
	"black_stained_glass", // 95:14
	"trapdoor", // 96:0
	"trapdoor", // 96:1
	"trapdoor", // 96:2
	"trapdoor", // 96:3
	"trapdoor", // 96:4
	"trapdoor", // 96:5
	"trapdoor", // 96:6
	"trapdoor", // 96:7
	"trapdoor", // 96:8
	"trapdoor", // 96:9
	"trapdoor", // 96:10
	"trapdoor", // 96:11
	"trapdoor", // 96:12
	"trapdoor", // 96:13
	"trapdoor", // 96:14
	"trapdoor", // 96:15
	"stone_monster_egg", // 97:0
	"cobblestone_monster_egg", // 97:1
	"stone_brick_monster_egg", // 97:2
	"cracked_brick_monster_egg", // 97:3
	"chiseled_brick_monster_egg", // 97:4
	"monster_egg", // 97:5
	"stonebrick", // 98:0
	"stonebrick", // 98:1
	"stonebrick", // 98:2
	"stonebrick", // 98:3
	"brown_mushroom_block", // 99:0
	"brown_mushroom_block", // 99:1
	"brown_mushroom_block", // 99:2
	"brown_mushroom_block", // 99:3
	"brown_mushroom_block", // 99:4
	"brown_mushroom_block", // 99:5
	"brown_mushroom_block", // 99:6
	"brown_mushroom_block", // 99:7
	"brown_mushroom_block", // 99:8
	"brown_mushroom_block", // 99:9
	"brown_mushroom_block", // 99:10
	"brown_mushroom_block", // 99:11
	"brown_mushroom_block", // 99:12
	"brown_mushroom_block", // 99:13
	"brown_mushroom_block", // 99:14
	"brown_mushroom_block", // 99:15
	"red_mushroom_block", // 100:0
	"red_mushroom_block", // 100:1
	"red_mushroom_block", // 100:2
	"red_mushroom_block", // 100:3
	"red_mushroom_block", // 100:4
	"red_mushroom_block", // 100:5
	"red_mushroom_block", // 100:6
	"red_mushroom_block", // 100:7
	"red_mushroom_block", // 100:8
	"red_mushroom_block", // 100:9
	"red_mushroom_block", // 100:10
	"red_mushroom_block", // 100:11
	"red_mushroom_block", // 100:12
	"red_mushroom_block", // 100:13
	"red_mushroom_block", // 100:14
	"red_mushroom_block", // 100:15
	"pumpkin_stem", // 104:0
	"pumpkin_stem", // 104:1
	"pumpkin_stem", // 104:2
	"pumpkin_stem", // 104:3
	"pumpkin_stem", // 104:4
	"pumpkin_stem", // 104:5
	"pumpkin_stem", // 104:6
	"pumpkin_stem", // 104:7
	"melon_stem", // 105:0
	"melon_stem", // 105:1
	"melon_stem", // 105:2
	"melon_stem", // 105:3
	"melon_stem", // 105:4
	"melon_stem", // 105:5
	"melon_stem", // 105:6
	"melon_stem", // 105:7
	"vine", // 106:0
	"vine", // 106:1
	"vine", // 106:2
	"vine", // 106:3
	"vine", // 106:4
	"vine", // 106:5
	"vine", // 106:6
	"vine", // 106:7
	"vine", // 106:8
	"vine", // 106:9
	"vine", // 106:10
	"vine", // 106:11
	"vine", // 106:12
	"vine", // 106:13
	"vine", // 106:14
	"vine", // 106:15
	"vine", // 106:16
	"vine", // 106:17
	"vine", // 106:18
	"vine", // 106:19
	"vine", // 106:20
	"vine", // 106:21
	"vine", // 106:22
	"vine", // 106:23
	"vine", // 106:24
	"fence_gate", // 107:0
	"fence_gate", // 107:1
	"fence_gate", // 107:2
	"fence_gate", // 107:3
	"fence_gate", // 107:4
	"fence_gate", // 107:5
	"fence_gate", // 107:6
	"fence_gate", // 107:7
	"brick_stairs", // 108:0
	"brick_stairs", // 108:1
	"brick_stairs", // 108:2
	"brick_stairs", // 108:3
	"brick_stairs", // 108:4
	"brick_stairs", // 108:5
	"brick_stairs", // 108:6
	"brick_stairs", // 108:7
	"stone_brick_stairs", // 109:0
	"stone_brick_stairs", // 109:1
	"stone_brick_stairs", // 109:2
	"stone_brick_stairs", // 109:3
	"stone_brick_stairs", // 109:4
	"stone_brick_stairs", // 109:5
	"stone_brick_stairs", // 109:6
	"stone_brick_stairs", // 109:7
	"nether_brick_stairs", // 114:0
	"nether_brick_stairs", // 114:1
	"nether_brick_stairs", // 114:2
	"nether_brick_stairs", // 114:3
	"nether_brick_stairs", // 114:4
	"nether_brick_stairs", // 114:5
	"nether_brick_stairs", // 114:6
	"nether_brick_stairs", // 114:7
	"nether_wart", // 115:0
	"nether_wart", // 115:1
	"nether_wart", // 115:2
	"nether_wart", // 115:3
	"brewing_stand", // 117:0
	"brewing_stand", // 117:1
	"brewing_stand", // 117:2
	"brewing_stand", // 117:3
	"brewing_stand", // 117:4
	"brewing_stand", // 117:5
	"brewing_stand", // 117:6
	"brewing_stand", // 117:7
	"brewing_stand", // 117:8
	"brewing_stand", // 117:9
	"brewing_stand", // 117:10
	"brewing_stand", // 117:11
	"brewing_stand", // 117:12
	"cauldron", // 118:0
	"cauldron", // 118:1
	"cauldron", // 118:2
	"cauldron", // 118:3
	"end_portal_frame", // 120:0
	"end_portal_frame", // 120:1
	"end_portal_frame", // 120:2
	"end_portal_frame", // 120:3
	"end_portal_frame", // 120:4
	"end_portal_frame", // 120:5
	"end_portal_frame", // 120:6
	"end_portal_frame", // 120:7
	"oak_double_slab", // 125:0
	"spruce_double_slab", // 125:1
	"birch_double_slab", // 125:2
	"jungle_double_slab", // 125:3
	"acacia_double_slab", // 125:4
	"dark_oak_double_slab", // 125:5
	"double_wooden_slab", // 125:6
	"double_wooden_slab", // 125:7
	"double_wooden_slab", // 125:8
	"double_wooden_slab", // 125:9
	"double_wooden_slab", // 125:10
	"double_wooden_slab", // 125:11
	"double_wooden_slab", // 125:12
	"double_wooden_slab", // 125:13
	"double_wooden_slab", // 125:14
	"oak_wooden_slab", // 126:0
	"spruce_wooden_slab", // 126:1
	"birch_wooden_slab", // 126:2
	"jungle_wooden_slab", // 126:3
	"acacia_wooden_slab", // 126:4
	"dark_oak_wooden_slab", // 126:5
	"wooden_slab", // 126:6
	"wooden_slab", // 126:7
	"oak_wooden_slab", // 126:8
	"spruce_wooden_slab", // 126:9
	"birch_wooden_slab", // 126:10
	"jungle_wooden_slab", // 126:11
	"acacia_wooden_slab", // 126:12
	"dark_oak_wooden_slab", // 126:13
	"wooden_slab", // 126:14
	"cocoa", // 127:0
	"cocoa", // 127:1
	"cocoa", // 127:2
	"cocoa", // 127:3
	"cocoa", // 127:4
	"cocoa", // 127:5
	"cocoa", // 127:6
	"cocoa", // 127:7
	"cocoa", // 127:8
	"cocoa", // 127:9
	"cocoa", // 127:10
	"cocoa", // 127:11
	"cocoa", // 127:12
	"cocoa", // 127:13
	"cocoa", // 127:14
	"cocoa", // 127:15
	"sandstone_stairs", // 128:0
	"sandstone_stairs", // 128:1
	"sandstone_stairs", // 128:2
	"sandstone_stairs", // 128:3
	"sandstone_stairs", // 128:4
	"sandstone_stairs", // 128:5
	"sandstone_stairs", // 128:6
	"sandstone_stairs", // 128:7
	"ender_chest", // 130:0
	"ender_chest", // 130:1
	"ender_chest", // 130:2
	"ender_chest", // 130:3
	"ender_chest", // 130:4
	"ender_chest", // 130:5
	"tripwire_hook", // 131:0
	"tripwire_hook", // 131:1
	"tripwire_hook", // 131:2
	"tripwire_hook", // 131:3
	"tripwire_hook", // 131:4
	"tripwire_hook", // 131:5
	"tripwire_hook", // 131:6
	"tripwire_hook", // 131:7
	"tripwire_hook", // 131:8
	"tripwire_hook", // 131:9
	"tripwire_hook", // 131:10
	"tripwire_hook", // 131:11
	"tripwire_hook", // 131:12
	"tripwire_hook", // 131:13
	"tripwire_hook", // 131:14
	"tripwire_hook", // 131:15
	"tripwire", // 132:0
	"tripwire", // 132:1
	"tripwire", // 132:2
	"tripwire", // 132:3
	"tripwire", // 132:4
	"tripwire", // 132:5
	"tripwire", // 132:6
	"tripwire", // 132:7
	"tripwire", // 132:8
	"tripwire", // 132:9
	"tripwire", // 132:10
	"tripwire", // 132:11
	"tripwire", // 132:12
	"tripwire", // 132:13
	"tripwire", // 132:14
	"tripwire", // 132:15
	"tripwire", // 132:16
	"spruce_stairs", // 134:0
	"spruce_stairs", // 134:1
	"spruce_stairs", // 134:2
	"spruce_stairs", // 134:3
	"spruce_stairs", // 134:4
	"spruce_stairs", // 134:5
	"spruce_stairs", // 134:6
	"spruce_stairs", // 134:7
	"birch_stairs", // 135:0
	"birch_stairs", // 135:1
	"birch_stairs", // 135:2
	"birch_stairs", // 135:3
	"birch_stairs", // 135:4
	"birch_stairs", // 135:5
	"birch_stairs", // 135:6
	"birch_stairs", // 135:7
	"jungle_stairs", // 136:0
	"jungle_stairs", // 136:1
	"jungle_stairs", // 136:2
	"jungle_stairs", // 136:3
	"jungle_stairs", // 136:4
	"jungle_stairs", // 136:5
	"jungle_stairs", // 136:6
	"jungle_stairs", // 136:7
	"cobblestone_wall", // 139:0
	"mossy_cobblestone_wall", // 139:1
	"flower_pot", // 140:0
	"flower_pot", // 140:1
	"flower_pot", // 140:2
	"flower_pot", // 140:3
	"flower_pot", // 140:4
	"flower_pot", // 140:5
	"flower_pot", // 140:6
	"flower_pot", // 140:7
	"flower_pot", // 140:8
	"flower_pot", // 140:9
	"flower_pot", // 140:10
	"flower_pot", // 140:11
	"flower_pot", // 140:12
	"flower_pot", // 140:13
	"wooden_button", // 143:0
	"wooden_button", // 143:1
	"wooden_button", // 143:2
	"wooden_button", // 143:3
	"wooden_button", // 143:4
	"wooden_button", // 143:5
	"wooden_button", // 143:6
	"wooden_button", // 143:7
	"wooden_button", // 143:8
	"wooden_button", // 143:9
	"wooden_button", // 143:10
	"wooden_button", // 143:11
	"wooden_button", // 143:12
	"wooden_button", // 143:13
	"skull", // 144:0
	"skull", // 144:1
	"skull", // 144:2
	"skull", // 144:3
	"skull", // 144:4
	"skull", // 144:5
	"anvil", // 145:0
	"anvil", // 145:1
	"anvil", // 145:2
	"anvil", // 145:3
	"anvil", // 145:4
	"anvil", // 145:5
	"anvil", // 145:6
	"anvil", // 145:7
	"anvil", // 145:8
	"anvil", // 145:9
	"trapped_chest", // 146:0
	"trapped_chest", // 146:1
	"trapped_chest", // 146:2
	"trapped_chest", // 146:3
	"trapped_chest", // 146:4
	"trapped_chest", // 146:5
	"light_weighted_pressure_plate", // 147:0
	"light_weighted_pressure_plate", // 147:1
	"heavy_weighted_pressure_plate", // 148:0
	"heavy_weighted_pressure_plate", // 148:1
	"unpowered_comparator", // 149:0
	"unpowered_comparator", // 149:1
	"unpowered_comparator", // 149:2
	"unpowered_comparator", // 149:3
	"unpowered_comparator", // 149:4
	"unpowered_comparator", // 149:5
	"unpowered_comparator", // 149:6
	"unpowered_comparator", // 149:7
	"unpowered_comparator", // 149:8
	"unpowered_comparator", // 149:9
	"unpowered_comparator", // 149:10
	"unpowered_comparator", // 149:11
	"unpowered_comparator", // 149:12
	"unpowered_comparator", // 149:13
	"unpowered_comparator", // 149:14
	"unpowered_comparator", // 149:15
	"powered_comparator", // 150:0
	"powered_comparator", // 150:1
	"powered_comparator", // 150:2
	"powered_comparator", // 150:3
	"powered_comparator", // 150:4
	"powered_comparator", // 150:5
	"powered_comparator", // 150:6
	"powered_comparator", // 150:7
	"powered_comparator", // 150:8
	"powered_comparator", // 150:9
	"powered_comparator", // 150:10
	"powered_comparator", // 150:11
	"powered_comparator", // 150:12
	"powered_comparator", // 150:13
	"powered_comparator", // 150:14
	"powered_comparator", // 150:15
	"hopper", // 154:0
	"hopper", // 154:1
	"hopper", // 154:2
	"hopper", // 154:3
	"hopper", // 154:4
	"hopper", // 154:5
	"quartz_block", // 155:0
	"chiseled_quartz_block", // 155:1
	"quartz_column", // 155:2
	"quartz_column", // 155:3
	"quartz_column", // 155:4
	"quartz_stairs", // 156:0
	"quartz_stairs", // 156:1
	"quartz_stairs", // 156:2
	"quartz_stairs", // 156:3
	"quartz_stairs", // 156:4
	"quartz_stairs", // 156:5
	"quartz_stairs", // 156:6
	"quartz_stairs", // 156:7
	"dropper", // 158:0
	"dropper", // 158:1
	"dropper", // 158:2
	"dropper", // 158:3
	"dropper", // 158:4
	"dropper", // 158:5
	"white_stained_hardened_clay", // 159:0
	"orange_stained_hardened_clay", // 159:1
	"magenta_stained_hardened_clay", // 159:2
	"light_blue_stained_hardened_clay", // 159:3
	"yellow_stained_hardened_clay", // 159:4
	"lime_stained_hardened_clay", // 159:5
	"pink_stained_hardened_clay", // 159:6
	"gray_stained_hardened_clay", // 159:7
	"light_gray_stained_hardened_clay", // 159:8
	"cyan_stained_hardened_clay", // 159:9
	"purple_stained_hardened_clay", // 159:10
	"blue_stained_hardened_clay", // 159:11
	"green_stained_hardened_clay", // 159:12
	"red_stained_hardened_clay", // 159:13
	"black_stained_hardened_clay", // 159:14
	"white_stained_glass_pane", // 160:0
	"orange_stained_glass_pane", // 160:1
	"magenta_stained_glass_pane", // 160:2
	"light_blue_stained_glass_pane", // 160:3
	"yellow_stained_glass_pane", // 160:4
	"lime_stained_glass_pane", // 160:5
	"pink_stained_glass_pane", // 160:6
	"gray_stained_glass_pane", // 160:7
	"light_gray_stained_glass_pane", // 160:8
	"cyan_stained_glass_pane", // 160:9
	"purple_stained_glass_pane", // 160:10
	"blue_stained_glass_pane", // 160:11
	"green_stained_glass_pane", // 160:12
	"red_stained_glass_pane", // 160:13
	"black_stained_glass_pane", // 160:14
	"acacia_leaves", // 161:0
	"dark_oak_leaves", // 161:1
	"acacia_log", // 162:0
	"dark_oak_log", // 162:1
	"acacia_log", // 162:2
	"dark_oak_log", // 162:3
	"acacia_log", // 162:4
	"dark_oak_log", // 162:5
	"acacia_log", // 162:6
	"dark_oak_log", // 162:7
	"acacia_log", // 162:8
	"dark_oak_log", // 162:9
	"acacia_log", // 162:10
	"dark_oak_log", // 162:11
	"acacia_log", // 162:12
	"dark_oak_log", // 162:13
	"acacia_log", // 162:14
	"dark_oak_log", // 162:15
	"acacia_stairs", // 163:0
	"acacia_stairs", // 163:1
	"acacia_stairs", // 163:2
	"acacia_stairs", // 163:3
	"acacia_stairs", // 163:4
	"acacia_stairs", // 163:5
	"acacia_stairs", // 163:6
	"acacia_stairs", // 163:7
	"dark_oak_stairs", // 164:0
	"dark_oak_stairs", // 164:1
	"dark_oak_stairs", // 164:2
	"dark_oak_stairs", // 164:3
	"dark_oak_stairs", // 164:4
	"dark_oak_stairs", // 164:5
	"dark_oak_stairs", // 164:6
	"dark_oak_stairs", // 164:7
	"white_carpet", // 171:0
	"orange_carpet", // 171:1
	"magenta_carpet", // 171:2
	"light_blue_carpet", // 171:3
	"yellow_carpet", // 171:4
	"lime_carpet", // 171:5
	"pink_carpet", // 171:6
	"gray_carpet", // 171:7
	"light_gray_carpet", // 171:8
	"cyan_carpet", // 171:9
	"purple_carpet", // 171:10
	"blue_carpet", // 171:11
	"green_carpet", // 171:12
	"red_carpet", // 171:13
	"black_carpet", // 171:14
	"sunflower", // 175:0
	"syringa", // 175:1
	"double_grass", // 175:2
	"double_fern", // 175:3
	"double_rose", // 175:4
	"peony", // 175:5
};
