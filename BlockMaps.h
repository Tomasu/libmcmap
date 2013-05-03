#ifndef BLOCKMAPS_H_GUARD
#define BLOCKMAPS_H_GUARD

#include <cstdint>

#define BLOCK_COUNT 159
extern const char *BlockNames[BLOCK_COUNT];
struct SubBlockRange { uint32_t start; uint32_t num; };
extern SubBlockRange subBlockRange[BLOCK_COUNT];
#define SUBBLOCKNAME_COUNT 54
extern const char *SubBlockNames[SUBBLOCKNAME_COUNT];

#define BLOCK_AIR 0
#define BLOCK_STONE 1
#define BLOCK_GRASS 2
#define BLOCK_DIRT 3
#define BLOCK_COBBLESTONE 4
#define BLOCK_PLANKS 5
#define BLOCK_PLANKS_DATA_OAK 0
#define BLOCK_PLANKS_DATA_SPRUCE 1
#define BLOCK_PLANKS_DATA_BIRCH 2
#define BLOCK_PLANKS_DATA_JUNGLE 3
#define BLOCK_SAPLING 6
#define BLOCK_BEDROCK 7
#define BLOCK_MOVING_WATER 8
#define BLOCK_STILL_WATER 9
#define BLOCK_MOVING_LAVA 10
#define BLOCK_STILL_LAVA 11
#define BLOCK_SAND 12
#define BLOCK_GRAVEL 13
#define BLOCK_GOLD_ORE 14
#define BLOCK_IRON_ORE 15
#define BLOCK_COAL_ORE 16
#define BLOCK_WOOD 17
#define BLOCK_WOOD_DATA_OAK 0
#define BLOCK_WOOD_DATA_SPRUCE 1
#define BLOCK_WOOD_DATA_BIRCH 2
#define BLOCK_WOOD_DATA_JUNGLE 3
#define BLOCK_LEAVES 18
#define BLOCK_SPONGE 19
#define BLOCK_GLASS 20
#define BLOCK_LAPIS_ORE 21
#define BLOCK_LAPIS_BLOCK 22
#define BLOCK_DISPENSER 23
#define BLOCK_SAND_STONE 24
#define BLOCK_MUSIC 25
#define BLOCK_BED 26
#define BLOCK_POWERED_RAIL 27
#define BLOCK_DETECTOR_RAIL 28
#define BLOCK_PISTON_STICKY_BASE 29
#define BLOCK_WEB 30
#define BLOCK_TALL_GRASS 31
#define BLOCK_DEAD_BUSH 32
#define BLOCK_PISTON_BASE 33
#define BLOCK_PISTON_EXTENSION 34
#define BLOCK_CLOTH 35
#define BLOCK_CLOTH_DATA_WHITE 0
#define BLOCK_CLOTH_DATA_ORANGE 1
#define BLOCK_CLOTH_DATA_MAGENTA 2
#define BLOCK_CLOTH_DATA_LIGHT BLUE 3
#define BLOCK_CLOTH_DATA_YELLOW 4
#define BLOCK_CLOTH_DATA_LIME 5
#define BLOCK_CLOTH_DATA_PINK 6
#define BLOCK_CLOTH_DATA_GRAY 7
#define BLOCK_CLOTH_DATA_LIGHT GRAY 8
#define BLOCK_CLOTH_DATA_CYAN 9
#define BLOCK_CLOTH_DATA_PURPLE 10
#define BLOCK_CLOTH_DATA_BLUE 11
#define BLOCK_CLOTH_DATA_BROWN 12
#define BLOCK_CLOTH_DATA_GREEN 13
#define BLOCK_CLOTH_DATA_RED 14
#define BLOCK_CLOTH_DATA_BLACK 15
#define BLOCK_PISTON_MOVING 36
#define BLOCK_YELLOW_PLANT 37
#define BLOCK_RED_PLANT 38
#define BLOCK_BROWN_MUSHROOM 39
#define BLOCK_RED_MUSHROOM 40
#define BLOCK_GOLD_BLOCK 41
#define BLOCK_IRON_BLOCK 42
#define BLOCK_DOUBLESLAB 43
#define BLOCK_DOUBLESLAB_DATA_STONE 0
#define BLOCK_DOUBLESLAB_DATA_SAND 1
#define BLOCK_DOUBLESLAB_DATA_WOOD 2
#define BLOCK_DOUBLESLAB_DATA_COBBLE 3
#define BLOCK_DOUBLESLAB_DATA_BRICK 4
#define BLOCK_DOUBLESLAB_DATA_SMOOTH_STONE_BRICK 5
#define BLOCK_DOUBLESLAB_DATA_NETHER_BRICK 6
#define BLOCK_DOUBLESLAB_DATA_QUARTZ 7
#define BLOCK_SINGLESLAB 44
#define BLOCK_SINGLESLAB_DATA_STONE 0
#define BLOCK_SINGLESLAB_DATA_SAND 1
#define BLOCK_SINGLESLAB_DATA_WOOD 2
#define BLOCK_SINGLESLAB_DATA_COBBLE 3
#define BLOCK_SINGLESLAB_DATA_BRICK 4
#define BLOCK_SINGLESLAB_DATA_SMOOTH_STONE_BRICK 5
#define BLOCK_SINGLESLAB_DATA_NETHER_BRICK 6
#define BLOCK_SINGLESLAB_DATA_QUARTZ 7
#define BLOCK_BRICK 45
#define BLOCK_TNT 46
#define BLOCK_BOOK_SHELF 47
#define BLOCK_COBBLESTONE_MOSSY 48
#define BLOCK_OBSIDIAN 49
#define BLOCK_WOOD_TORCH 50
#define BLOCK_FIRE 51
#define BLOCK_MOB_SPAWNER 52
#define BLOCK_WOOD_OAK_STAIRS 53
#define BLOCK_CHEST 54
#define BLOCK_REDSTONE_WIRE 55
#define BLOCK_DIAMOND_ORE 56
#define BLOCK_DIAMOND_BLOCK 57
#define BLOCK_WORKBENCH 58
#define BLOCK_CROPS 59
#define BLOCK_TILLED_FIELD 60
#define BLOCK_FURNACE_IDLE 61
#define BLOCK_FURNACE_BURNING 62
#define BLOCK_SIGN_POST 63
#define BLOCK_WOOD_DOOR 64
#define BLOCK_LADDER 65
#define BLOCK_RAIL 66
#define BLOCK_COBBLESTONE_STAIRS 67
#define BLOCK_SIGN_WALL 68
#define BLOCK_LEVER 69
#define BLOCK_PRESSURE_PLATE_STONE 70
#define BLOCK_IRON_DOOR 71
#define BLOCK_PRESSURE_PLATE_PLANKS 72
#define BLOCK_REDSTONE_ORE 73
#define BLOCK_REDSTONE_GLOWING_ORE 74
#define BLOCK_REDSTONE_IDLE_TORCH 75
#define BLOCK_REDSTONE_ACTIVE_TORCH 76
#define BLOCK_STONE_BUTTON 77
#define BLOCK_SNOW 78
#define BLOCK_ICE 79
#define BLOCK_SNOW_BLOCK 80
#define BLOCK_CACTUS 81
#define BLOCK_CLAY_BLOCK 82
#define BLOCK_REED 83
#define BLOCK_JUKEBOX 84
#define BLOCK_FENCE 85
#define BLOCK_PUMPKIN 86
#define BLOCK_NETHERRACK 87
#define BLOCK_SLOW_SAND 88
#define BLOCK_GLOW_STONE 89
#define BLOCK_PORTAL 90
#define BLOCK_PUMPKIN_LANTERN 91
#define BLOCK_CAKE 92
#define BLOCK_REDSTONE_REPEATER_IDLE 93
#define BLOCK_REDSTONE_REPEATER_ACTIVE 94
#define BLOCK_LOCKED_CHEST 95
#define BLOCK_TRAPDOOR 96
#define BLOCK_SILVERFISH 97
#define BLOCK_SILVERFISH_DATA_STONE 0
#define BLOCK_SILVERFISH_DATA_COBBLE 1
#define BLOCK_SILVERFISH_DATA_BRICK 2
#define BLOCK_STONE_BRICK 98
#define BLOCK_MUSHROOM_CAP_BROWN 99
#define BLOCK_MUSHROOM_CAP_RED 100
#define BLOCK_FENCE_IRON 101
#define BLOCK_THIN_GLASS 102
#define BLOCK_MELON 103
#define BLOCK_PUMPKIN_STEM 104
#define BLOCK_MELON_STEM 105
#define BLOCK_VINE 106
#define BLOCK_FENCE_GATE 107
#define BLOCK_BRICK_STAIRS 108
#define BLOCK_STONE_BRICK_STAIRS 109
#define BLOCK_MYCELIUM 110
#define BLOCK_WATERLILY 111
#define BLOCK_NETHER_BRICK 112
#define BLOCK_NETHER_FENCE 113
#define BLOCK_NETHER_BRICK_STAIRS 114
#define BLOCK_NETHER_STALK 115
#define BLOCK_ENCHANTMENT_TABLE 116
#define BLOCK_BREWING_STAND 117
#define BLOCK_CAULDRON 118
#define BLOCK_END_PORTAL 119
#define BLOCK_END_PORTAL_FRAME 120
#define BLOCK_WHITE_STONE 121
#define BLOCK_DRAGON_EGG 122
#define BLOCK_REDSTONE_LAMP_IDLE 123
#define BLOCK_REDSTONE_LAMP_ACTIVE 124
#define BLOCK_WOODDOUBLE_SLAB 125
#define BLOCK_WOODDOUBLE_SLAB_DATA_OAK 0
#define BLOCK_WOODDOUBLE_SLAB_DATA_SPRUCE 1
#define BLOCK_WOODDOUBLE_SLAB_DATA_BIRCH 2
#define BLOCK_WOODDOUBLE_SLAB_DATA_JUNGLE 3
#define BLOCK_WOODSINGLE_SLAB 126
#define BLOCK_WOODSINGLE_SLAB_DATA_OAK 0
#define BLOCK_WOODSINGLE_SLAB_DATA_SPRUCE 1
#define BLOCK_WOODSINGLE_SLAB_DATA_BIRCH 2
#define BLOCK_WOODSINGLE_SLAB_DATA_JUNGLE 3
#define BLOCK_COCOA_PLANT 127
#define BLOCK_SAND_STONE_STAIRS 128
#define BLOCK_EMERALD_ORE 129
#define BLOCK_ENDER_CHEST 130
#define BLOCK_TRIP_WIRE_SOURCE 131
#define BLOCK_TRIP_WIRE 132
#define BLOCK_EMERALD_BLOCK 133
#define BLOCK_WOOD_SPRUCE_STAIRS 134
#define BLOCK_WOOD_BIRCH_STAIRS 135
#define BLOCK_WOOD_JUNGLE_STAIRS 136
#define BLOCK_COMMAND_BLOCK 137
#define BLOCK_BEACON 138
#define BLOCK_COBBLESTONE_WALL 139
#define BLOCK_FLOWER_POT 140
#define BLOCK_CARROT 141
#define BLOCK_POTATO 142
#define BLOCK_WOODEN_BUTTON 143
#define BLOCK_SKULL 144
#define BLOCK_ANVIL 145
#define BLOCK_CHEST_TRAPPED 146
#define BLOCK_PRESSURE_PLATE_GOLD 147
#define BLOCK_PRESSURE_PLATE_IRON 148
#define BLOCK_REDSTONE_COMPARATOR_IDLE 149
#define BLOCK_REDSTONE_COMPARATOR_ACTIVE 150
#define BLOCK_DAYLIGHT_SENSOR 151
#define BLOCK_REDSTONE_BLOCK 152
#define BLOCK_NETHER_QUARTZ_ORE 153
#define BLOCK_HOPPER_BLOCK 154
#define BLOCK_NETHER_QUARTZ_BLOCK 155
#define BLOCK_NETHER_QUARTZ_BLOCK_DATA_DEFAULT 0
#define BLOCK_NETHER_QUARTZ_BLOCK_DATA_CHISELED 1
#define BLOCK_NETHER_QUARTZ_BLOCK_DATA_LINES 2
#define BLOCK_NETHER_QUARTZ_STAIRS 156
#define BLOCK_ACTIVATOR_RAIL 157
#define BLOCK_DROPPER 158

#endif
