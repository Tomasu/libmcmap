#ifndef BLOCKMAPS_H_GUARD
#define BLOCKMAPS_H_GUARD

#include <cstdint>

#define BLOCK_COUNT 198
extern const char *BlockNames[BLOCK_COUNT];
extern const char *BlockStateNames[BLOCK_COUNT];
struct SubBlockRange { uint32_t start; uint32_t num; };
extern SubBlockRange subBlockRange[BLOCK_COUNT];
#define SUBBLOCKNAME_COUNT 907
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
#define BLOCK_PLANKS_DATA_ACACIA 4
#define BLOCK_PLANKS_DATA_DARK_OAK 5
#define BLOCK_SAPLING 6
#define BLOCK_SAPLING_DATA_OAK 0
#define BLOCK_SAPLING_DATA_SPRUCE 1
#define BLOCK_SAPLING_DATA_BIRCH 2
#define BLOCK_SAPLING_DATA_JUNGLE 3
#define BLOCK_SAPLING_DATA_ACACIA 4
#define BLOCK_SAPLING_DATA_DARK_OAK 5
#define BLOCK_BEDROCK 7
#define BLOCK_FLOWING_WATER 8
#define BLOCK_WATER 9
#define BLOCK_FLOWING_LAVA 10
#define BLOCK_LAVA 11
#define BLOCK_SAND 12
#define BLOCK_SAND_DATA_NORMAL 0
#define BLOCK_SAND_DATA_RED 1
#define BLOCK_GRAVEL 13
#define BLOCK_GOLD_ORE 14
#define BLOCK_IRON_ORE 15
#define BLOCK_COAL_ORE 16
#define BLOCK_LOG 17
#define BLOCK_LOG_DATA_OAK 0
#define BLOCK_LOG_DATA_SPRUCE 1
#define BLOCK_LOG_DATA_BIRCH 2
#define BLOCK_LOG_DATA_JUNGLE 3
#define BLOCK_LOG_DATA_OAK_EW 4
#define BLOCK_LOG_DATA_SPRUCE_EW 5
#define BLOCK_LOG_DATA_BIRCH_EW 6
#define BLOCK_LOG_DATA_JUNGLE_EW 7
#define BLOCK_LOG_DATA_OAK_NS 8
#define BLOCK_LOG_DATA_SPRUCE_NS 9
#define BLOCK_LOG_DATA_BIRCH_NS 10
#define BLOCK_LOG_DATA_JUNGLE_NS 11
#define BLOCK_LOG_DATA_OAK_BARK 12
#define BLOCK_LOG_DATA_SPRUCE_BARK 13
#define BLOCK_LOG_DATA_BIRCH_BARK 14
#define BLOCK_LOG_DATA_JUNGLE_BARK 15
#define BLOCK_LEAVES 18
#define BLOCK_LEAVES_DATA_OAK 0
#define BLOCK_LEAVES_DATA_SPRUCE 1
#define BLOCK_LEAVES_DATA_BIRCH 2
#define BLOCK_LEAVES_DATA_JUNGLE 3
#define BLOCK_SPONGE 19
#define BLOCK_GLASS 20
#define BLOCK_LAPIS_ORE 21
#define BLOCK_LAPIS_BLOCK 22
#define BLOCK_DISPENSER 23
#define BLOCK_DISPENSER_DATA_DOWN 0
#define BLOCK_DISPENSER_DATA_UP 1
#define BLOCK_DISPENSER_DATA_NORTH 2
#define BLOCK_DISPENSER_DATA_SOUTH 3
#define BLOCK_DISPENSER_DATA_WEST 4
#define BLOCK_DISPENSER_DATA_EAST 5
#define BLOCK_SANDSTONE 24
#define BLOCK_SANDSTONE_DATA_NORMAL 0
#define BLOCK_SANDSTONE_DATA_CHISELED 1
#define BLOCK_SANDSTONE_DATA_SMOOTH 2
#define BLOCK_NOTEBLOCK 25
#define BLOCK_BED 26
#define BLOCK_BED_DATA_SOUTH 0
#define BLOCK_BED_DATA_WEST 1
#define BLOCK_BED_DATA_NORTH 2
#define BLOCK_BED_DATA_EAST 3
#define BLOCK_BED_DATA_SOUTH_OCCUPIED 4
#define BLOCK_BED_DATA_WEST_OCCUPIED 5
#define BLOCK_BED_DATA_NORTH_OCCUPIED 6
#define BLOCK_BED_DATA_EAST_OCCUPIED 7
#define BLOCK_BED_DATA_SOUTH_HEAD 8
#define BLOCK_BED_DATA_WEST_HEAD 9
#define BLOCK_BED_DATA_NORTH_HEAD 10
#define BLOCK_BED_DATA_EAST_HEAD 11
#define BLOCK_BED_DATA_SOUTH_OCCUPIED_HEAD 12
#define BLOCK_BED_DATA_WEST_OCCUPIED_HEAD 13
#define BLOCK_BED_DATA_NORTH_OCCUPIED_HEAD 14
#define BLOCK_BED_DATA_EAST_OCCUPIED_HEAD 15
#define BLOCK_GOLDEN_RAIL 27
#define BLOCK_GOLDEN_RAIL_DATA_FLAT_NS 0
#define BLOCK_GOLDEN_RAIL_DATA_FLAT_EW 1
#define BLOCK_GOLDEN_RAIL_DATA_ASC_EAST 2
#define BLOCK_GOLDEN_RAIL_DATA_ASC_WEST 3
#define BLOCK_GOLDEN_RAIL_DATA_ASC_NORTH 4
#define BLOCK_GOLDEN_RAIL_DATA_ASC_SOUTH 5
#define BLOCK_GOLDEN_RAIL_DATA_CORNER_NW 6
#define BLOCK_GOLDEN_RAIL_DATA_CORNER_NE 7
#define BLOCK_GOLDEN_RAIL_DATA_CORNER_SE_POWERED 8
#define BLOCK_GOLDEN_RAIL_DATA_CORNER_SW_POWERED 9
#define BLOCK_GOLDEN_RAIL_DATA_ASC_EAST_POWERED 10
#define BLOCK_GOLDEN_RAIL_DATA_ASC_WEST_POWERED 11
#define BLOCK_GOLDEN_RAIL_DATA_ASC_NORTH_POWERED 12
#define BLOCK_GOLDEN_RAIL_DATA_ASC_SOUTH_POWERED 13
#define BLOCK_GOLDEN_RAIL_DATA_CORNER_NW_POWERED 14
#define BLOCK_GOLDEN_RAIL_DATA_CORNER_NE_POWERED 15
#define BLOCK_DETECTOR_RAIL 28
#define BLOCK_STICKY_PISTON 29
#define BLOCK_WEB 30
#define BLOCK_TALLGRASS 31
#define BLOCK_TALLGRASS_DATA_SHRUB 0
#define BLOCK_TALLGRASS_DATA_GRASS 1
#define BLOCK_TALLGRASS_DATA_FERN 2
#define BLOCK_TALLGRASS_DATA_SHRUB2 3
#define BLOCK_DEADBUSH 32
#define BLOCK_PISTON 33
#define BLOCK_PISTON_DATA_DOWN 0
#define BLOCK_PISTON_DATA_UP 1
#define BLOCK_PISTON_DATA_NORTH 2
#define BLOCK_PISTON_DATA_SOUTH 3
#define BLOCK_PISTON_DATA_WEST 4
#define BLOCK_PISTON_DATA_EAST 5
#define BLOCK_PISTON_DATA_DOWN_EXTENDED 8
#define BLOCK_PISTON_DATA_UP_EXTENDED 9
#define BLOCK_PISTON_DATA_NORTH_EXTENDED 10
#define BLOCK_PISTON_DATA_SOUTH_EXTENDED 11
#define BLOCK_PISTON_DATA_WEST_EXTENDED 12
#define BLOCK_PISTON_DATA_EAST_EXTENDED 13
#define BLOCK_PISTON_HEAD 34
#define BLOCK_WOOL 35
#define BLOCK_WOOL_DATA_WHITE 0
#define BLOCK_WOOL_DATA_ORANGE 1
#define BLOCK_WOOL_DATA_MAGENTA 2
#define BLOCK_WOOL_DATA_LIGHT_BLUE 3
#define BLOCK_WOOL_DATA_YELLOW 4
#define BLOCK_WOOL_DATA_LIME 5
#define BLOCK_WOOL_DATA_PINK 6
#define BLOCK_WOOL_DATA_GRAY 7
#define BLOCK_WOOL_DATA_LIGHT_GRAY 8
#define BLOCK_WOOL_DATA_CYAN 9
#define BLOCK_WOOL_DATA_PURPLE 10
#define BLOCK_WOOL_DATA_BLUE 11
#define BLOCK_WOOL_DATA_BROWN 12
#define BLOCK_WOOL_DATA_GREEN 13
#define BLOCK_WOOL_DATA_RED 14
#define BLOCK_WOOL_DATA_BLACK 15
#define BLOCK_PISTON_EXTENSION 36
#define BLOCK_PISTON_EXTENSION_DATA_DOWN 0
#define BLOCK_PISTON_EXTENSION_DATA_UP 1
#define BLOCK_PISTON_EXTENSION_DATA_NORTH 2
#define BLOCK_PISTON_EXTENSION_DATA_SOUTH 3
#define BLOCK_PISTON_EXTENSION_DATA_WEST 4
#define BLOCK_PISTON_EXTENSION_DATA_EAST 5
#define BLOCK_PISTON_EXTENSION_DATA_DOWN_STICKY 8
#define BLOCK_PISTON_EXTENSION_DATA_UP_STICKY 9
#define BLOCK_PISTON_EXTENSION_DATA_NORTH_STICKY 10
#define BLOCK_PISTON_EXTENSION_DATA_SOUTH_STICKY 11
#define BLOCK_PISTON_EXTENSION_DATA_WEST_STICKY 12
#define BLOCK_PISTON_EXTENSION_DATA_EAST_STICKY 13
#define BLOCK_YELLOW_FLOWER 37
#define BLOCK_YELLOW_FLOWER_DATA_DANDELION 0
#define BLOCK_RED_FLOWER 38
#define BLOCK_RED_FLOWER_DATA_POPPY 0
#define BLOCK_RED_FLOWER_DATA_BLUE_ORCHID 1
#define BLOCK_RED_FLOWER_DATA_ALLIUM 2
#define BLOCK_RED_FLOWER_DATA_AZURE_BLUET 3
#define BLOCK_RED_FLOWER_DATA_RED_TULIP 4
#define BLOCK_RED_FLOWER_DATA_ORANGE_TULIP 5
#define BLOCK_RED_FLOWER_DATA_WHITE_TULIP 6
#define BLOCK_RED_FLOWER_DATA_PINK_TULIP 7
#define BLOCK_RED_FLOWER_DATA_OXEYE_DAISY 8
#define BLOCK_BROWN_MUSHROOM 39
#define BLOCK_RED_MUSHROOM 40
#define BLOCK_GOLD_BLOCK 41
#define BLOCK_IRON_BLOCK 42
#define BLOCK_DOUBLE_STONE_SLAB 43
#define BLOCK_DOUBLE_STONE_SLAB_DATA_STONE 0
#define BLOCK_DOUBLE_STONE_SLAB_DATA_SANDSTONE 1
#define BLOCK_DOUBLE_STONE_SLAB_DATA_WOOD 2
#define BLOCK_DOUBLE_STONE_SLAB_DATA_COBBLESTONE 3
#define BLOCK_DOUBLE_STONE_SLAB_DATA_BRICK 4
#define BLOCK_DOUBLE_STONE_SLAB_DATA_STONE_BRICK 5
#define BLOCK_DOUBLE_STONE_SLAB_DATA_NETHER_BRICK 6
#define BLOCK_DOUBLE_STONE_SLAB_DATA_QUARTZ 7
#define BLOCK_DOUBLE_STONE_SLAB_DATA_STONE_DOUBLE 8
#define BLOCK_DOUBLE_STONE_SLAB_DATA_SANDSTONE_DOUBLE 9
#define BLOCK_DOUBLE_STONE_SLAB_DATA_QUARTZ_DOUBLE 15
#define BLOCK_STONE_SLAB 44
#define BLOCK_STONE_SLAB_DATA_STONE 0
#define BLOCK_STONE_SLAB_DATA_SANDSTONE 1
#define BLOCK_STONE_SLAB_DATA_WOOD 2
#define BLOCK_STONE_SLAB_DATA_COBBLESTONE 3
#define BLOCK_STONE_SLAB_DATA_BRICK 4
#define BLOCK_STONE_SLAB_DATA_STONE_BRICK 5
#define BLOCK_STONE_SLAB_DATA_NETHER_BRICK 6
#define BLOCK_STONE_SLAB_DATA_QUARTZ 7
#define BLOCK_STONE_SLAB_DATA_STONE_DOUBLE 8
#define BLOCK_STONE_SLAB_DATA_SANDSTONE_DOUBLE 9
#define BLOCK_STONE_SLAB_DATA_QUARTZ_DOUBLE 15
#define BLOCK_BRICK_BLOCK 45
#define BLOCK_TNT 46
#define BLOCK_BOOKSHELF 47
#define BLOCK_MOSSY_COBBLESTONE 48
#define BLOCK_OBSIDIAN 49
#define BLOCK_TORCH 50
#define BLOCK_TORCH_DATA_FLOOR 0
#define BLOCK_TORCH_DATA_EAST 1
#define BLOCK_TORCH_DATA_WEST 2
#define BLOCK_TORCH_DATA_SOUTH 3
#define BLOCK_TORCH_DATA_NORTH 4
#define BLOCK_FIRE 51
#define BLOCK_MOB_SPAWNER 52
#define BLOCK_OAK_STAIRS 53
#define BLOCK_OAK_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_OAK_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_OAK_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_OAK_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_CHEST 54
#define BLOCK_CHEST_DATA_NORTH 2
#define BLOCK_CHEST_DATA_SOUTH 3
#define BLOCK_CHEST_DATA_WEST 4
#define BLOCK_CHEST_DATA_EAST 5
#define BLOCK_REDSTONE_WIRE 55
#define BLOCK_REDSTONE_WIRE_DATA_0 0
#define BLOCK_REDSTONE_WIRE_DATA_1 1
#define BLOCK_REDSTONE_WIRE_DATA_2 2
#define BLOCK_REDSTONE_WIRE_DATA_3 3
#define BLOCK_REDSTONE_WIRE_DATA_4 4
#define BLOCK_REDSTONE_WIRE_DATA_5 5
#define BLOCK_REDSTONE_WIRE_DATA_6 6
#define BLOCK_REDSTONE_WIRE_DATA_7 7
#define BLOCK_REDSTONE_WIRE_DATA_8 8
#define BLOCK_REDSTONE_WIRE_DATA_9 9
#define BLOCK_REDSTONE_WIRE_DATA_10 10
#define BLOCK_REDSTONE_WIRE_DATA_11 11
#define BLOCK_REDSTONE_WIRE_DATA_12 12
#define BLOCK_REDSTONE_WIRE_DATA_13 13
#define BLOCK_REDSTONE_WIRE_DATA_14 14
#define BLOCK_REDSTONE_WIRE_DATA_15 15
#define BLOCK_DIAMOND_ORE 56
#define BLOCK_DIAMOND_BLOCK 57
#define BLOCK_CRAFTING_TABLE 58
#define BLOCK_WHEAT 59
#define BLOCK_FARMLAND 60
#define BLOCK_FARMLAND_DATA_DRY 0
#define BLOCK_FARMLAND_DATA_WET_1 1
#define BLOCK_FARMLAND_DATA_WET_2 2
#define BLOCK_FARMLAND_DATA_WET_3 3
#define BLOCK_FARMLAND_DATA_WET_4 4
#define BLOCK_FARMLAND_DATA_WET_5 5
#define BLOCK_FARMLAND_DATA_WET_6 6
#define BLOCK_FARMLAND_DATA_WET_7 7
#define BLOCK_FARMLAND_DATA_WET_8 8
#define BLOCK_FURNACE 61
#define BLOCK_FURNACE_DATA_NORTH 2
#define BLOCK_FURNACE_DATA_SOUTH 3
#define BLOCK_FURNACE_DATA_WEST 4
#define BLOCK_FURNACE_DATA_EAST 5
#define BLOCK_LIT_FURNACE 62
#define BLOCK_LIT_FURNACE_DATA_NORTH 2
#define BLOCK_LIT_FURNACE_DATA_SOUTH 3
#define BLOCK_LIT_FURNACE_DATA_WEST 4
#define BLOCK_LIT_FURNACE_DATA_EAST 5
#define BLOCK_STANDING_SIGN 63
#define BLOCK_STANDING_SIGN_DATA_SOUTH 0
#define BLOCK_STANDING_SIGN_DATA_SOUTH_SOUTHWEST 1
#define BLOCK_STANDING_SIGN_DATA_SOUTHWEST 2
#define BLOCK_STANDING_SIGN_DATA_WEST_SOUTHWEST 3
#define BLOCK_STANDING_SIGN_DATA_WEST 4
#define BLOCK_STANDING_SIGN_DATA_WEST_NORTHWEST 5
#define BLOCK_STANDING_SIGN_DATA_NORTHWEST 6
#define BLOCK_STANDING_SIGN_DATA_NORTH_NORTHWEST 7
#define BLOCK_STANDING_SIGN_DATA_NORTH 8
#define BLOCK_STANDING_SIGN_DATA_NORTH_NORTHEAST 9
#define BLOCK_STANDING_SIGN_DATA_NORTHEAST 10
#define BLOCK_STANDING_SIGN_DATA_EAST_NORTHEAST 11
#define BLOCK_STANDING_SIGN_DATA_EAST 12
#define BLOCK_STANDING_SIGN_DATA_EAST_SOUTHEAST 13
#define BLOCK_STANDING_SIGN_DATA_SOUTHEAST 14
#define BLOCK_STANDING_SIGN_DATA_SOUTH_SOUTHEAST 15
#define BLOCK_WOODEN_DOOR 64
#define BLOCK_WOODEN_DOOR_DATA_BOTTOM_WEST_CLOSED 0
#define BLOCK_WOODEN_DOOR_DATA_BOTTOM_NORTH_CLOSED 1
#define BLOCK_WOODEN_DOOR_DATA_BOTTOM_EAST_CLOSED 2
#define BLOCK_WOODEN_DOOR_DATA_BOTTOM_SOUTH_CLOSED 3
#define BLOCK_WOODEN_DOOR_DATA_BOTTOM_WEST_OPEN 4
#define BLOCK_WOODEN_DOOR_DATA_BOTTOM_NORTH_OPEN 5
#define BLOCK_WOODEN_DOOR_DATA_BOTTOM_EAST_OPEN 6
#define BLOCK_WOODEN_DOOR_DATA_BOTTOM_SOUTH_OPEN 7
#define BLOCK_WOODEN_DOOR_DATA_TOP_RIGHT 8
#define BLOCK_WOODEN_DOOR_DATA_TOP_LEFT 9
#define BLOCK_LADDER 65
#define BLOCK_LADDER_DATA_NORTH 2
#define BLOCK_LADDER_DATA_SOUTH 3
#define BLOCK_LADDER_DATA_WEST 4
#define BLOCK_LADDER_DATA_EAST 5
#define BLOCK_RAIL 66
#define BLOCK_RAIL_DATA_FLAT_NS 0
#define BLOCK_RAIL_DATA_FLAT_EW 1
#define BLOCK_RAIL_DATA_ASC_EAST 2
#define BLOCK_RAIL_DATA_ASC_WEST 3
#define BLOCK_RAIL_DATA_ASC_NORTH 4
#define BLOCK_RAIL_DATA_ASC_SOUTH 5
#define BLOCK_RAIL_DATA_CORNER_NW 6
#define BLOCK_RAIL_DATA_CORNER_NE 7
#define BLOCK_RAIL_DATA_CORNER_SE 8
#define BLOCK_RAIL_DATA_CORNER_SW 9
#define BLOCK_STONE_STAIRS 67
#define BLOCK_STONE_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_STONE_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_STONE_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_STONE_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_WALL_SIGN 68
#define BLOCK_WALL_SIGN_DATA_NORTH 2
#define BLOCK_WALL_SIGN_DATA_SOUTH 3
#define BLOCK_WALL_SIGN_DATA_WEST 4
#define BLOCK_WALL_SIGN_DATA_EAST 5
#define BLOCK_LEVER 69
#define BLOCK_LEVER_DATA_CEILING_EAST_OFF 0
#define BLOCK_LEVER_DATA_EAST_OFF 1
#define BLOCK_LEVER_DATA_WEST_OFF 2
#define BLOCK_LEVER_DATA_SOUTH_OFF 3
#define BLOCK_LEVER_DATA_NORTH_OFF 4
#define BLOCK_LEVER_DATA_GROUND_SOUTH_OFF 5
#define BLOCK_LEVER_DATA_GROUND_EAST_OFF 6
#define BLOCK_LEVER_DATA_CEILING_SOUTH_OFF 7
#define BLOCK_LEVER_DATA_CEILING_EAST_ON 8
#define BLOCK_LEVER_DATA_EAST_ON 9
#define BLOCK_LEVER_DATA_WEST_ON 10
#define BLOCK_LEVER_DATA_SOUTH_ON 11
#define BLOCK_LEVER_DATA_NORTH_ON 12
#define BLOCK_LEVER_DATA_GROUND_SOUTH_ON 13
#define BLOCK_LEVER_DATA_GROUND_EAST_ON 14
#define BLOCK_LEVER_DATA_CEILING_SOUTH_ON 15
#define BLOCK_STONE_PRESSURE_PLATE 70
#define BLOCK_STONE_PRESSURE_PLATE_DATA_NORMAL 0
#define BLOCK_STONE_PRESSURE_PLATE_DATA_PRESSED 1
#define BLOCK_IRON_DOOR 71
#define BLOCK_IRON_DOOR_DATA_BOTTOM_WEST_CLOSED 0
#define BLOCK_IRON_DOOR_DATA_BOTTOM_NORTH_CLOSED 1
#define BLOCK_IRON_DOOR_DATA_BOTTOM_EAST_CLOSED 2
#define BLOCK_IRON_DOOR_DATA_BOTTOM_SOUTH_CLOSED 3
#define BLOCK_IRON_DOOR_DATA_BOTTOM_WEST_OPEN 4
#define BLOCK_IRON_DOOR_DATA_BOTTOM_NORTH_OPEN 5
#define BLOCK_IRON_DOOR_DATA_BOTTOM_EAST_OPEN 6
#define BLOCK_IRON_DOOR_DATA_BOTTOM_SOUTH_OPEN 7
#define BLOCK_IRON_DOOR_DATA_TOP_RIGHT 8
#define BLOCK_IRON_DOOR_DATA_TOP_LEFT 9
#define BLOCK_WOODEN_PRESSURE_PLATE 72
#define BLOCK_WOODEN_PRESSURE_PLATE_DATA_NORMAL 0
#define BLOCK_WOODEN_PRESSURE_PLATE_DATA_PRESSED 1
#define BLOCK_REDSTONE_ORE 73
#define BLOCK_LIT_REDSTONE_ORE 74
#define BLOCK_UNLIT_REDSTONE_TORCH 75
#define BLOCK_REDSTONE_TORCH 76
#define BLOCK_STONE_BUTTON 77
#define BLOCK_STONE_BUTTON_DATA_EAST 1
#define BLOCK_STONE_BUTTON_DATA_WEST 2
#define BLOCK_STONE_BUTTON_DATA_SOUTH 3
#define BLOCK_STONE_BUTTON_DATA_NORTH 4
#define BLOCK_STONE_BUTTON_DATA_UP 5
#define BLOCK_STONE_BUTTON_DATA_EAST_PRESSED 9
#define BLOCK_STONE_BUTTON_DATA_WEST_PRESSED 10
#define BLOCK_STONE_BUTTON_DATA_SOUTH_PRESSED 11
#define BLOCK_STONE_BUTTON_DATA_NORTH_PRESSED 12
#define BLOCK_STONE_BUTTON_DATA_UP_PRESSED 13
#define BLOCK_SNOW_LAYER 78
#define BLOCK_SNOW_LAYER_DATA_0 0
#define BLOCK_SNOW_LAYER_DATA_1 1
#define BLOCK_SNOW_LAYER_DATA_2 2
#define BLOCK_SNOW_LAYER_DATA_3 3
#define BLOCK_SNOW_LAYER_DATA_4 4
#define BLOCK_SNOW_LAYER_DATA_5 5
#define BLOCK_SNOW_LAYER_DATA_6 6
#define BLOCK_SNOW_LAYER_DATA_7 7
#define BLOCK_ICE 79
#define BLOCK_SNOW 80
#define BLOCK_CACTUS 81
#define BLOCK_CACTUS_DATA_0 0
#define BLOCK_CACTUS_DATA_1 1
#define BLOCK_CACTUS_DATA_2 2
#define BLOCK_CACTUS_DATA_3 3
#define BLOCK_CACTUS_DATA_4 4
#define BLOCK_CACTUS_DATA_5 5
#define BLOCK_CACTUS_DATA_6 6
#define BLOCK_CACTUS_DATA_7 7
#define BLOCK_CACTUS_DATA_8 8
#define BLOCK_CACTUS_DATA_9 9
#define BLOCK_CACTUS_DATA_10 10
#define BLOCK_CACTUS_DATA_11 11
#define BLOCK_CACTUS_DATA_12 12
#define BLOCK_CACTUS_DATA_13 13
#define BLOCK_CACTUS_DATA_14 14
#define BLOCK_CACTUS_DATA_15 15
#define BLOCK_CLAY 82
#define BLOCK_REEDS 83
#define BLOCK_REEDS_DATA_0 0
#define BLOCK_REEDS_DATA_1 1
#define BLOCK_REEDS_DATA_2 2
#define BLOCK_REEDS_DATA_3 3
#define BLOCK_REEDS_DATA_4 4
#define BLOCK_REEDS_DATA_5 5
#define BLOCK_REEDS_DATA_6 6
#define BLOCK_REEDS_DATA_7 7
#define BLOCK_REEDS_DATA_8 8
#define BLOCK_REEDS_DATA_9 9
#define BLOCK_REEDS_DATA_10 10
#define BLOCK_REEDS_DATA_11 11
#define BLOCK_REEDS_DATA_12 12
#define BLOCK_REEDS_DATA_13 13
#define BLOCK_REEDS_DATA_14 14
#define BLOCK_REEDS_DATA_15 15
#define BLOCK_JUKEBOX 84
#define BLOCK_JUKEBOX_DATA_EMPTY 0
#define BLOCK_JUKEBOX_DATA_13 1
#define BLOCK_JUKEBOX_DATA_CAT 2
#define BLOCK_JUKEBOX_DATA_BLOCKS 3
#define BLOCK_JUKEBOX_DATA_CHIRP 4
#define BLOCK_JUKEBOX_DATA_FAR 5
#define BLOCK_JUKEBOX_DATA_MALL 6
#define BLOCK_JUKEBOX_DATA_MELLOHI 7
#define BLOCK_JUKEBOX_DATA_STAL 8
#define BLOCK_JUKEBOX_DATA_STRAD 9
#define BLOCK_JUKEBOX_DATA_WARD 10
#define BLOCK_JUKEBOX_DATA_11 11
#define BLOCK_JUKEBOX_DATA_WAIT 12
#define BLOCK_FENCE 85
#define BLOCK_PUMPKIN 86
#define BLOCK_PUMPKIN_DATA_SOUTH 0
#define BLOCK_PUMPKIN_DATA_WEST 1
#define BLOCK_PUMPKIN_DATA_NORTH 2
#define BLOCK_PUMPKIN_DATA_EAST 3
#define BLOCK_PUMPKIN_DATA_ 4
#define BLOCK_NETHERRACK 87
#define BLOCK_SOUL_SAND 88
#define BLOCK_GLOWSTONE 89
#define BLOCK_PORTAL 90
#define BLOCK_LIT_PUMPKIN 91
#define BLOCK_LIT_PUMPKIN_DATA_SOUTH 0
#define BLOCK_LIT_PUMPKIN_DATA_WEST 1
#define BLOCK_LIT_PUMPKIN_DATA_NORTH 2
#define BLOCK_LIT_PUMPKIN_DATA_EAST 3
#define BLOCK_LIT_PUMPKIN_DATA_ 4
#define BLOCK_CAKE 92
#define BLOCK_CAKE_DATA_0 0
#define BLOCK_CAKE_DATA_1 1
#define BLOCK_CAKE_DATA_2 2
#define BLOCK_CAKE_DATA_3 3
#define BLOCK_CAKE_DATA_4 4
#define BLOCK_CAKE_DATA_5 5
#define BLOCK_UNPOWERED_REPEATER 93
#define BLOCK_UNPOWERED_REPEATER_DATA_NORTH 0
#define BLOCK_UNPOWERED_REPEATER_DATA_EAST 1
#define BLOCK_UNPOWERED_REPEATER_DATA_SOUTH 2
#define BLOCK_UNPOWERED_REPEATER_DATA_WEST 3
#define BLOCK_UNPOWERED_REPEATER_DATA_NORTH_2_TICK 4
#define BLOCK_UNPOWERED_REPEATER_DATA_EAST_2_TICK 5
#define BLOCK_UNPOWERED_REPEATER_DATA_SOUTH_2_TICK 6
#define BLOCK_UNPOWERED_REPEATER_DATA_WEST_2_TICK 7
#define BLOCK_UNPOWERED_REPEATER_DATA_NORTH_4_TICK 8
#define BLOCK_UNPOWERED_REPEATER_DATA_EAST_4_TICK 9
#define BLOCK_UNPOWERED_REPEATER_DATA_SOUTH_4_TICK 10
#define BLOCK_UNPOWERED_REPEATER_DATA_WEST_4_TICK 11
#define BLOCK_POWERED_REPEATER 94
#define BLOCK_POWERED_REPEATER_DATA_NORTH 0
#define BLOCK_POWERED_REPEATER_DATA_EAST 1
#define BLOCK_POWERED_REPEATER_DATA_SOUTH 2
#define BLOCK_POWERED_REPEATER_DATA_WEST 3
#define BLOCK_POWERED_REPEATER_DATA_NORTH_2_TICK 4
#define BLOCK_POWERED_REPEATER_DATA_EAST_2_TICK 5
#define BLOCK_POWERED_REPEATER_DATA_SOUTH_2_TICK 6
#define BLOCK_POWERED_REPEATER_DATA_WEST_2_TICK 7
#define BLOCK_POWERED_REPEATER_DATA_NORTH_4_TICK 8
#define BLOCK_POWERED_REPEATER_DATA_EAST_4_TICK 9
#define BLOCK_POWERED_REPEATER_DATA_SOUTH_4_TICK 10
#define BLOCK_POWERED_REPEATER_DATA_WEST_4_TICK 11
#define BLOCK_STAINED_GLASS 95
#define BLOCK_STAINED_GLASS_DATA_WHITE 0
#define BLOCK_STAINED_GLASS_DATA_ORANGE 1
#define BLOCK_STAINED_GLASS_DATA_MAGENTA 2
#define BLOCK_STAINED_GLASS_DATA_LIGHT_BLUE 3
#define BLOCK_STAINED_GLASS_DATA_YELLOW 4
#define BLOCK_STAINED_GLASS_DATA_LIME 5
#define BLOCK_STAINED_GLASS_DATA_PINK 6
#define BLOCK_STAINED_GLASS_DATA_GRAY 7
#define BLOCK_STAINED_GLASS_DATA_LIGHT_GRAY 8
#define BLOCK_STAINED_GLASS_DATA_CYAN 9
#define BLOCK_STAINED_GLASS_DATA_PURPLE 10
#define BLOCK_STAINED_GLASS_DATA_BLUE 11
#define BLOCK_STAINED_GLASS_DATA_GREEN 12
#define BLOCK_STAINED_GLASS_DATA_RED 13
#define BLOCK_STAINED_GLASS_DATA_BLACK 14
#define BLOCK_TRAPDOOR 96
#define BLOCK_TRAPDOOR_DATA_SOUTH_CLOSED_BOTTOM 0
#define BLOCK_TRAPDOOR_DATA_NORTH_CLOSED_BOTTOM 1
#define BLOCK_TRAPDOOR_DATA_EAST_CLOSED_BOTTOM 2
#define BLOCK_TRAPDOOR_DATA_WEST_CLOSED_BOTTOM 3
#define BLOCK_TRAPDOOR_DATA_SOUTH_OPEN_BOTTOM 4
#define BLOCK_TRAPDOOR_DATA_NORTH_OPEN_BOTTOM 5
#define BLOCK_TRAPDOOR_DATA_EAST_OPEN_BOTTOM 6
#define BLOCK_TRAPDOOR_DATA_WEST_OPEN_BOTTOM 7
#define BLOCK_TRAPDOOR_DATA_SOUTH_CLOSED_TOP 8
#define BLOCK_TRAPDOOR_DATA_NORTH_CLOSED_TOP 9
#define BLOCK_TRAPDOOR_DATA_EAST_CLOSED_TOP 10
#define BLOCK_TRAPDOOR_DATA_WEST_CLOSED_TOP 11
#define BLOCK_TRAPDOOR_DATA_SOUTH_OPEN_TOP 12
#define BLOCK_TRAPDOOR_DATA_NORTH_OPEN_TOP 13
#define BLOCK_TRAPDOOR_DATA_EAST_OPEN_TOP 14
#define BLOCK_TRAPDOOR_DATA_WEST_OPEN_TOP 15
#define BLOCK_MONSTER_EGG 97
#define BLOCK_MONSTER_EGG_DATA_STONE 0
#define BLOCK_MONSTER_EGG_DATA_COBBLESTONE 1
#define BLOCK_MONSTER_EGG_DATA_STONE_BRICK 2
#define BLOCK_MONSTER_EGG_DATA_MOSSY_STONE_BRICK 3
#define BLOCK_MONSTER_EGG_DATA_CRACKED_STONE_BRICK 4
#define BLOCK_MONSTER_EGG_DATA_CHISELED_STONE_BRICK 5
#define BLOCK_STONEBRICK 98
#define BLOCK_STONEBRICK_DATA_STONE 0
#define BLOCK_STONEBRICK_DATA_MOSSY 1
#define BLOCK_STONEBRICK_DATA_CRACKED 2
#define BLOCK_STONEBRICK_DATA_CHISELED 3
#define BLOCK_BROWN_MUSHROOM_BLOCK 99
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_PORES 0
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_CAP_TWN 1
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_CAP_TN 2
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_CAP_TNE 3
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_CAP_TW 4
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_CAP_T 5
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_CAP_TE 6
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_CAP_TSW 7
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_CAP_TS 8
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_CAP_TES 9
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_STEM_PORES_TB 10
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_CAP_ALL 14
#define BLOCK_BROWN_MUSHROOM_BLOCK_DATA_STEM_ALL 15
#define BLOCK_RED_MUSHROOM_BLOCK 100
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_PORES 0
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_CAP_TWN 1
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_CAP_TN 2
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_CAP_TNE 3
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_CAP_TW 4
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_CAP_T 5
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_CAP_TE 6
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_CAP_TSW 7
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_CAP_TS 8
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_CAP_TES 9
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_STEM_PORES_TB 10
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_CAP_ALL 14
#define BLOCK_RED_MUSHROOM_BLOCK_DATA_STEM_ALL 15
#define BLOCK_IRON_BARS 101
#define BLOCK_GLASS_PANE 102
#define BLOCK_MELON_BLOCK 103
#define BLOCK_PUMPKIN_STEM 104
#define BLOCK_PUMPKIN_STEM_DATA_0 0
#define BLOCK_PUMPKIN_STEM_DATA_1 1
#define BLOCK_PUMPKIN_STEM_DATA_2 2
#define BLOCK_PUMPKIN_STEM_DATA_3 3
#define BLOCK_PUMPKIN_STEM_DATA_4 4
#define BLOCK_PUMPKIN_STEM_DATA_5 5
#define BLOCK_PUMPKIN_STEM_DATA_6 6
#define BLOCK_PUMPKIN_STEM_DATA_7 7
#define BLOCK_MELON_STEM 105
#define BLOCK_MELON_STEM_DATA_0 0
#define BLOCK_MELON_STEM_DATA_1 1
#define BLOCK_MELON_STEM_DATA_2 2
#define BLOCK_MELON_STEM_DATA_3 3
#define BLOCK_MELON_STEM_DATA_4 4
#define BLOCK_MELON_STEM_DATA_5 5
#define BLOCK_MELON_STEM_DATA_6 6
#define BLOCK_MELON_STEM_DATA_7 7
#define BLOCK_VINE 106
#define BLOCK_VINE_DATA_S 2
#define BLOCK_VINE_DATA_W 4
#define BLOCK_VINE_DATA_WS 6
#define BLOCK_VINE_DATA_N 8
#define BLOCK_VINE_DATA_NS 10
#define BLOCK_VINE_DATA_NSW 12
#define BLOCK_VINE_DATA_E 16
#define BLOCK_VINE_DATA_ES 18
#define BLOCK_VINE_DATA_ESW 20
#define BLOCK_VINE_DATA_ESWN 24
#define BLOCK_FENCE_GATE 107
#define BLOCK_FENCE_GATE_DATA_SOUTH_CLOSED 0
#define BLOCK_FENCE_GATE_DATA_WEST_CLOSED 1
#define BLOCK_FENCE_GATE_DATA_NORTH_CLOSED 2
#define BLOCK_FENCE_GATE_DATA_EAST_CLOSED 3
#define BLOCK_FENCE_GATE_DATA_SOUTH_OPEN 4
#define BLOCK_FENCE_GATE_DATA_WEST_OPEN 5
#define BLOCK_FENCE_GATE_DATA_NORTH_OPEN 6
#define BLOCK_FENCE_GATE_DATA_EAST_OPEN 7
#define BLOCK_BRICK_STAIRS 108
#define BLOCK_BRICK_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_BRICK_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_BRICK_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_BRICK_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_STONE_BRICK_STAIRS 109
#define BLOCK_STONE_BRICK_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_STONE_BRICK_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_STONE_BRICK_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_STONE_BRICK_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_MYCELIUM 110
#define BLOCK_WATERLILY 111
#define BLOCK_NETHER_BRICK 112
#define BLOCK_NETHER_BRICK_FENCE 113
#define BLOCK_NETHER_BRICK_STAIRS 114
#define BLOCK_NETHER_BRICK_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_NETHER_BRICK_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_NETHER_BRICK_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_NETHER_BRICK_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_NETHER_WART 115
#define BLOCK_NETHER_WART_DATA_0 0
#define BLOCK_NETHER_WART_DATA_1 1
#define BLOCK_NETHER_WART_DATA_2 2
#define BLOCK_NETHER_WART_DATA_3 3
#define BLOCK_ENCHANTING_TABLE 116
#define BLOCK_BREWING_STAND 117
#define BLOCK_BREWING_STAND_DATA_E 2
#define BLOCK_BREWING_STAND_DATA_SW 4
#define BLOCK_BREWING_STAND_DATA_SWE 6
#define BLOCK_BREWING_STAND_DATA_NW 8
#define BLOCK_BREWING_STAND_DATA_NWE 10
#define BLOCK_BREWING_STAND_DATA_NWESW 12
#define BLOCK_CAULDRON 118
#define BLOCK_CAULDRON_DATA_EMPTY 0
#define BLOCK_CAULDRON_DATA_13 1
#define BLOCK_CAULDRON_DATA_23 2
#define BLOCK_CAULDRON_DATA_FULL 3
#define BLOCK_END_PORTAL 119
#define BLOCK_END_PORTAL_FRAME 120
#define BLOCK_END_PORTAL_FRAME_DATA_SOUTH_EMPTY 0
#define BLOCK_END_PORTAL_FRAME_DATA_WEST_EMPTY 1
#define BLOCK_END_PORTAL_FRAME_DATA_NORTH_EMPTY 2
#define BLOCK_END_PORTAL_FRAME_DATA_EAST_EMPTY 3
#define BLOCK_END_PORTAL_FRAME_DATA_SOUTH_FULL 4
#define BLOCK_END_PORTAL_FRAME_DATA_WEST_FULL 5
#define BLOCK_END_PORTAL_FRAME_DATA_NORTH_FULL 6
#define BLOCK_END_PORTAL_FRAME_DATA_EAST_FULL 7
#define BLOCK_END_STONE 121
#define BLOCK_DRAGON_EGG 122
#define BLOCK_REDSTONE_LAMP 123
#define BLOCK_LIT_REDSTONE_LAMP 124
#define BLOCK_DOUBLE_WOODEN_SLAB 125
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_OAK 0
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_SPRUCE 1
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_BIRCH 2
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_JUNGLE 3
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_ACACIA 4
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_DARK_OAK 5
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_OAK_TOP 9
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_SPRUCE_TOP 10
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_BIRCH_TOP 11
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_JUNGLE_TOP 12
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_ACACIA_TOP 13
#define BLOCK_DOUBLE_WOODEN_SLAB_DATA_DARK_OAK_TOP 14
#define BLOCK_WOODEN_SLAB 126
#define BLOCK_WOODEN_SLAB_DATA_OAK 0
#define BLOCK_WOODEN_SLAB_DATA_SPRUCE 1
#define BLOCK_WOODEN_SLAB_DATA_BIRCH 2
#define BLOCK_WOODEN_SLAB_DATA_JUNGLE 3
#define BLOCK_WOODEN_SLAB_DATA_ACACIA 4
#define BLOCK_WOODEN_SLAB_DATA_DARK_OAK 5
#define BLOCK_WOODEN_SLAB_DATA_OAK_TOP 9
#define BLOCK_WOODEN_SLAB_DATA_SPRUCE_TOP 10
#define BLOCK_WOODEN_SLAB_DATA_BIRCH_TOP 11
#define BLOCK_WOODEN_SLAB_DATA_JUNGLE_TOP 12
#define BLOCK_WOODEN_SLAB_DATA_ACACIA_TOP 13
#define BLOCK_WOODEN_SLAB_DATA_DARK_OAK_TOP 14
#define BLOCK_COCOA 127
#define BLOCK_COCOA_DATA_NORTH_SMALL 0
#define BLOCK_COCOA_DATA_EAST_SMALL 1
#define BLOCK_COCOA_DATA_SOUTH_SMALL 2
#define BLOCK_COCOA_DATA_WEST_SMALL 3
#define BLOCK_COCOA_DATA_NORTH_MEDIUM 4
#define BLOCK_COCOA_DATA_EAST_MEDIUM 5
#define BLOCK_COCOA_DATA_SOUTH_MEDIUM 6
#define BLOCK_COCOA_DATA_WEST_MEDIUM 7
#define BLOCK_COCOA_DATA_NORTH_LARGE 8
#define BLOCK_COCOA_DATA_EAST_LARGE 9
#define BLOCK_COCOA_DATA_SOUTH_LARGE 10
#define BLOCK_COCOA_DATA_WEST_LARGE 11
#define BLOCK_COCOA_DATA_NORTH_EX 12
#define BLOCK_COCOA_DATA_EAST_EX 13
#define BLOCK_COCOA_DATA_SOUTH_EX 14
#define BLOCK_COCOA_DATA_WEST_EX 15
#define BLOCK_SANDSTONE_STAIRS 128
#define BLOCK_SANDSTONE_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_SANDSTONE_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_SANDSTONE_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_SANDSTONE_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_EMERALD_ORE 129
#define BLOCK_ENDER_CHEST 130
#define BLOCK_ENDER_CHEST_DATA_NORTH 2
#define BLOCK_ENDER_CHEST_DATA_SOUTH 3
#define BLOCK_ENDER_CHEST_DATA_WEST 4
#define BLOCK_ENDER_CHEST_DATA_EAST 5
#define BLOCK_TRIPWIRE_HOOK 131
#define BLOCK_TRIPWIRE_HOOK_DATA_SOUTH_NC 0
#define BLOCK_TRIPWIRE_HOOK_DATA_WEST_NC 1
#define BLOCK_TRIPWIRE_HOOK_DATA_NORTH_NC 2
#define BLOCK_TRIPWIRE_HOOK_DATA_EAST_NC 3
#define BLOCK_TRIPWIRE_HOOK_DATA_SOUTH_C 4
#define BLOCK_TRIPWIRE_HOOK_DATA_WEST_C 5
#define BLOCK_TRIPWIRE_HOOK_DATA_NORTH_C 6
#define BLOCK_TRIPWIRE_HOOK_DATA_EAST_C 7
#define BLOCK_TRIPWIRE_HOOK_DATA_SOUTH_A 8
#define BLOCK_TRIPWIRE_HOOK_DATA_WEST_A 9
#define BLOCK_TRIPWIRE_HOOK_DATA_NORTH_A 10
#define BLOCK_TRIPWIRE_HOOK_DATA_EAST_A 11
#define BLOCK_TRIPWIRE_HOOK_DATA_SOUTH_CA 12
#define BLOCK_TRIPWIRE_HOOK_DATA_WEST_CA 13
#define BLOCK_TRIPWIRE_HOOK_DATA_NORTH_CA 14
#define BLOCK_TRIPWIRE_HOOK_DATA_EAST_CA 15
#define BLOCK_TRIPWIRE 132
#define BLOCK_TRIPWIRE_DATA_UA 0
#define BLOCK_TRIPWIRE_DATA_LA 2
#define BLOCK_TRIPWIRE_DATA_FA 16
#define BLOCK_EMERALD_BLOCK 133
#define BLOCK_SPRUCE_STAIRS 134
#define BLOCK_SPRUCE_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_SPRUCE_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_SPRUCE_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_SPRUCE_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_BIRCH_STAIRS 135
#define BLOCK_BIRCH_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_BIRCH_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_BIRCH_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_BIRCH_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_JUNGLE_STAIRS 136
#define BLOCK_JUNGLE_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_JUNGLE_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_JUNGLE_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_JUNGLE_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_COMMAND_BLOCK 137
#define BLOCK_BEACON 138
#define BLOCK_COBBLESTONE_WALL 139
#define BLOCK_COBBLESTONE_WALL_DATA_NORMAL 0
#define BLOCK_COBBLESTONE_WALL_DATA_MOSSY 1
#define BLOCK_FLOWER_POT 140
#define BLOCK_FLOWER_POT_DATA_EMPTY 0
#define BLOCK_FLOWER_POT_DATA_POPPY 1
#define BLOCK_FLOWER_POT_DATA_DANDELION 2
#define BLOCK_FLOWER_POT_DATA_OAK 3
#define BLOCK_FLOWER_POT_DATA_SPRUCE 4
#define BLOCK_FLOWER_POT_DATA_BIRCH 5
#define BLOCK_FLOWER_POT_DATA_JUNGLE 6
#define BLOCK_FLOWER_POT_DATA_RED_MUSHROOM 7
#define BLOCK_FLOWER_POT_DATA_BROWN_MUSHROOM 8
#define BLOCK_FLOWER_POT_DATA_CACTUS 9
#define BLOCK_FLOWER_POT_DATA_DEAD_BUSH 10
#define BLOCK_FLOWER_POT_DATA_FERN 11
#define BLOCK_FLOWER_POT_DATA_ACACIA 12
#define BLOCK_FLOWER_POT_DATA_DARK_OAK 13
#define BLOCK_CARROTS 141
#define BLOCK_POTATOES 142
#define BLOCK_WOODEN_BUTTON 143
#define BLOCK_WOODEN_BUTTON_DATA_EAST 1
#define BLOCK_WOODEN_BUTTON_DATA_WEST 2
#define BLOCK_WOODEN_BUTTON_DATA_SOUTH 3
#define BLOCK_WOODEN_BUTTON_DATA_NORTH 4
#define BLOCK_WOODEN_BUTTON_DATA_UP 5
#define BLOCK_WOODEN_BUTTON_DATA_EAST_PRESSED 9
#define BLOCK_WOODEN_BUTTON_DATA_WEST_PRESSED 10
#define BLOCK_WOODEN_BUTTON_DATA_SOUTH_PRESSED 11
#define BLOCK_WOODEN_BUTTON_DATA_NORTH_PRESSED 12
#define BLOCK_WOODEN_BUTTON_DATA_UP_PRESSED 13
#define BLOCK_SKULL 144
#define BLOCK_SKULL_DATA_FLOOR 1
#define BLOCK_SKULL_DATA_NORTH 2
#define BLOCK_SKULL_DATA_SOUTH 3
#define BLOCK_SKULL_DATA_EAST 4
#define BLOCK_SKULL_DATA_WEST 5
#define BLOCK_ANVIL 145
#define BLOCK_ANVIL_DATA_NORTH_SOUTH_NO_DAMAGE 0
#define BLOCK_ANVIL_DATA_EAST_WEST_NO_DAMAGE 1
#define BLOCK_ANVIL_DATA_NORTH_SOUTH_SLIGHTLY_DAMAGED 4
#define BLOCK_ANVIL_DATA_EAST_WEST_SLIGHTLY_DAMAGED 5
#define BLOCK_ANVIL_DATA_NORTH_SOUTH_VERY_DAMAGED 8
#define BLOCK_ANVIL_DATA_EAST_WEST_VERY_DAMAGED 9
#define BLOCK_TRAPPED_CHEST 146
#define BLOCK_TRAPPED_CHEST_DATA_NORTH 2
#define BLOCK_TRAPPED_CHEST_DATA_SOUTH 3
#define BLOCK_TRAPPED_CHEST_DATA_WEST 4
#define BLOCK_TRAPPED_CHEST_DATA_EAST 5
#define BLOCK_LIGHT_WEIGHTED_PRESSURE_PLATE 147
#define BLOCK_LIGHT_WEIGHTED_PRESSURE_PLATE_DATA_NORMAL 0
#define BLOCK_LIGHT_WEIGHTED_PRESSURE_PLATE_DATA_PRESSED 1
#define BLOCK_HEAVY_WEIGHTED_PRESSURE_PLATE 148
#define BLOCK_HEAVY_WEIGHTED_PRESSURE_PLATE_DATA_NORMAL 0
#define BLOCK_HEAVY_WEIGHTED_PRESSURE_PLATE_DATA_PRESSED 1
#define BLOCK_UNPOWERED_COMPARATOR 149
#define BLOCK_UNPOWERED_COMPARATOR_DATA_NORTH_COMPARISON 0
#define BLOCK_UNPOWERED_COMPARATOR_DATA_EAST_COMPARISON 1
#define BLOCK_UNPOWERED_COMPARATOR_DATA_SOUTH_COMPARISON 2
#define BLOCK_UNPOWERED_COMPARATOR_DATA_WEST_COMPARISON 3
#define BLOCK_UNPOWERED_COMPARATOR_DATA_NORTH_SUBTRACTION 4
#define BLOCK_UNPOWERED_COMPARATOR_DATA_EAST_SUBTRACTION 5
#define BLOCK_UNPOWERED_COMPARATOR_DATA_SOUTH_SUBTRACTION 6
#define BLOCK_UNPOWERED_COMPARATOR_DATA_WEST_SUBTRACTION 7
#define BLOCK_UNPOWERED_COMPARATOR_DATA_NORTH_COMPARISON_POWERED 8
#define BLOCK_UNPOWERED_COMPARATOR_DATA_EAST_COMPARISON_POWERED 9
#define BLOCK_UNPOWERED_COMPARATOR_DATA_SOUTH_COMPARISON_POWERED 10
#define BLOCK_UNPOWERED_COMPARATOR_DATA_WEST_COMPARISON_POWERED 11
#define BLOCK_UNPOWERED_COMPARATOR_DATA_NORTH_SUBTRACTION_POWERED 12
#define BLOCK_UNPOWERED_COMPARATOR_DATA_EAST_SUBTRACTION_POWERED 13
#define BLOCK_UNPOWERED_COMPARATOR_DATA_SOUTH_SUBTRACTION_POWERED 14
#define BLOCK_UNPOWERED_COMPARATOR_DATA_WEST_SUBTRACTION_POWERED 15
#define BLOCK_POWERED_COMPARATOR 150
#define BLOCK_POWERED_COMPARATOR_DATA_NORTH_COMPARISON 0
#define BLOCK_POWERED_COMPARATOR_DATA_EAST_COMPARISON 1
#define BLOCK_POWERED_COMPARATOR_DATA_SOUTH_COMPARISON 2
#define BLOCK_POWERED_COMPARATOR_DATA_WEST_COMPARISON 3
#define BLOCK_POWERED_COMPARATOR_DATA_NORTH_SUBTRACTION 4
#define BLOCK_POWERED_COMPARATOR_DATA_EAST_SUBTRACTION 5
#define BLOCK_POWERED_COMPARATOR_DATA_SOUTH_SUBTRACTION 6
#define BLOCK_POWERED_COMPARATOR_DATA_WEST_SUBTRACTION 7
#define BLOCK_POWERED_COMPARATOR_DATA_NORTH_COMPARISON_POWERED 8
#define BLOCK_POWERED_COMPARATOR_DATA_EAST_COMPARISON_POWERED 9
#define BLOCK_POWERED_COMPARATOR_DATA_SOUTH_COMPARISON_POWERED 10
#define BLOCK_POWERED_COMPARATOR_DATA_WEST_COMPARISON_POWERED 11
#define BLOCK_POWERED_COMPARATOR_DATA_NORTH_SUBTRACTION_POWERED 12
#define BLOCK_POWERED_COMPARATOR_DATA_EAST_SUBTRACTION_POWERED 13
#define BLOCK_POWERED_COMPARATOR_DATA_SOUTH_SUBTRACTION_POWERED 14
#define BLOCK_POWERED_COMPARATOR_DATA_WEST_SUBTRACTION_POWERED 15
#define BLOCK_DAYLIGHT_DETECTOR 151
#define BLOCK_REDSTONE_BLOCK 152
#define BLOCK_QUARTZ_ORE 153
#define BLOCK_HOPPER 154
#define BLOCK_HOPPER_DATA_DOWN 0
#define BLOCK_HOPPER_DATA_UP 1
#define BLOCK_HOPPER_DATA_NORTH 2
#define BLOCK_HOPPER_DATA_SOUTH 3
#define BLOCK_HOPPER_DATA_WEST 4
#define BLOCK_HOPPER_DATA_EAST 5
#define BLOCK_QUARTZ_BLOCK 155
#define BLOCK_QUARTZ_BLOCK_DATA_NORMAL 0
#define BLOCK_QUARTZ_BLOCK_DATA_CHISELED 1
#define BLOCK_QUARTZ_BLOCK_DATA_VERTICAL_PILLAR 2
#define BLOCK_QUARTZ_BLOCK_DATA_NS_PILLAR 3
#define BLOCK_QUARTZ_BLOCK_DATA_EW_PILLAR 4
#define BLOCK_QUARTZ_STAIRS 156
#define BLOCK_QUARTZ_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_QUARTZ_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_QUARTZ_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_QUARTZ_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_ACTIVATOR_RAIL 157
#define BLOCK_DROPPER 158
#define BLOCK_DROPPER_DATA_DOWN 0
#define BLOCK_DROPPER_DATA_UP 1
#define BLOCK_DROPPER_DATA_NORTH 2
#define BLOCK_DROPPER_DATA_SOUTH 3
#define BLOCK_DROPPER_DATA_WEST 4
#define BLOCK_DROPPER_DATA_EAST 5
#define BLOCK_STAINED_HARDENED_CLAY 159
#define BLOCK_STAINED_HARDENED_CLAY_DATA_WHITE 0
#define BLOCK_STAINED_HARDENED_CLAY_DATA_ORANGE 1
#define BLOCK_STAINED_HARDENED_CLAY_DATA_MAGENTA 2
#define BLOCK_STAINED_HARDENED_CLAY_DATA_LIGHT_BLUE 3
#define BLOCK_STAINED_HARDENED_CLAY_DATA_YELLOW 4
#define BLOCK_STAINED_HARDENED_CLAY_DATA_LIME 5
#define BLOCK_STAINED_HARDENED_CLAY_DATA_PINK 6
#define BLOCK_STAINED_HARDENED_CLAY_DATA_GRAY 7
#define BLOCK_STAINED_HARDENED_CLAY_DATA_LIGHT_GRAY 8
#define BLOCK_STAINED_HARDENED_CLAY_DATA_CYAN 9
#define BLOCK_STAINED_HARDENED_CLAY_DATA_PURPLE 10
#define BLOCK_STAINED_HARDENED_CLAY_DATA_BLUE 11
#define BLOCK_STAINED_HARDENED_CLAY_DATA_GREEN 12
#define BLOCK_STAINED_HARDENED_CLAY_DATA_RED 13
#define BLOCK_STAINED_HARDENED_CLAY_DATA_BLACK 14
#define BLOCK_STAINED_GLASS_PANE 160
#define BLOCK_STAINED_GLASS_PANE_DATA_WHITE 0
#define BLOCK_STAINED_GLASS_PANE_DATA_ORANGE 1
#define BLOCK_STAINED_GLASS_PANE_DATA_MAGENTA 2
#define BLOCK_STAINED_GLASS_PANE_DATA_LIGHT_BLUE 3
#define BLOCK_STAINED_GLASS_PANE_DATA_YELLOW 4
#define BLOCK_STAINED_GLASS_PANE_DATA_LIME 5
#define BLOCK_STAINED_GLASS_PANE_DATA_PINK 6
#define BLOCK_STAINED_GLASS_PANE_DATA_GRAY 7
#define BLOCK_STAINED_GLASS_PANE_DATA_LIGHT_GRAY 8
#define BLOCK_STAINED_GLASS_PANE_DATA_CYAN 9
#define BLOCK_STAINED_GLASS_PANE_DATA_PURPLE 10
#define BLOCK_STAINED_GLASS_PANE_DATA_BLUE 11
#define BLOCK_STAINED_GLASS_PANE_DATA_GREEN 12
#define BLOCK_STAINED_GLASS_PANE_DATA_RED 13
#define BLOCK_STAINED_GLASS_PANE_DATA_BLACK 14
#define BLOCK_LEAVES2 161
#define BLOCK_LEAVES2_DATA_ACACIA 0
#define BLOCK_LEAVES2_DATA_DARK_OAK 1
#define BLOCK_LOG2 162
#define BLOCK_LOG2_DATA_ACACIA 0
#define BLOCK_LOG2_DATA_DARK_OAK 1
#define BLOCK_LOG2_DATA_ACACIA_PH 2
#define BLOCK_LOG2_DATA_DARK_OAK_PH 3
#define BLOCK_LOG2_DATA_ACACIA_EW 4
#define BLOCK_LOG2_DATA_DARK_OAK_EW 5
#define BLOCK_LOG2_DATA_ACACIA_EW_PH 6
#define BLOCK_LOG2_DATA_DARK_OAK_EW_PH 7
#define BLOCK_LOG2_DATA_ACACIA_NS 8
#define BLOCK_LOG2_DATA_DARK_OAK_NS 9
#define BLOCK_LOG2_DATA_ACACIA_NS_PH 10
#define BLOCK_LOG2_DATA_DARK_OAK_NS_PH 11
#define BLOCK_LOG2_DATA_ACACIA_BARK 12
#define BLOCK_LOG2_DATA_DARK_OAK_BARK 13
#define BLOCK_LOG2_DATA_ACACIA_BARK_PH 14
#define BLOCK_LOG2_DATA_DARK_OAK_BARK_PH 15
#define BLOCK_ACACIA_STAIRS 163
#define BLOCK_ACACIA_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_ACACIA_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_ACACIA_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_ACACIA_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_DARK_OAK_STAIRS 164
#define BLOCK_DARK_OAK_STAIRS_DATA_EAST_UPSIDE_DOWN 4
#define BLOCK_DARK_OAK_STAIRS_DATA_WEST_UPSIDE_DOWN 5
#define BLOCK_DARK_OAK_STAIRS_DATA_SOUTH_UPSIDE_DOWN 6
#define BLOCK_DARK_OAK_STAIRS_DATA_NORTH_UPSIDE_DOWN 7
#define BLOCK_SLIME 165
#define BLOCK_BARRIER 166
#define BLOCK_IRON_TRAPDOOR 167
#define BLOCK_PRISMARINE 168
#define BLOCK_SEA_LANTERN 169
#define BLOCK_HAY_BLOCK 170
#define BLOCK_CARPET 171
#define BLOCK_CARPET_DATA_WHITE 0
#define BLOCK_CARPET_DATA_ORANGE 1
#define BLOCK_CARPET_DATA_MAGENTA 2
#define BLOCK_CARPET_DATA_LIGHT_BLUE 3
#define BLOCK_CARPET_DATA_YELLOW 4
#define BLOCK_CARPET_DATA_LIME 5
#define BLOCK_CARPET_DATA_PINK 6
#define BLOCK_CARPET_DATA_GRAY 7
#define BLOCK_CARPET_DATA_LIGHT_GRAY 8
#define BLOCK_CARPET_DATA_CYAN 9
#define BLOCK_CARPET_DATA_PURPLE 10
#define BLOCK_CARPET_DATA_BLUE 11
#define BLOCK_CARPET_DATA_GREEN 12
#define BLOCK_CARPET_DATA_RED 13
#define BLOCK_CARPET_DATA_BLACK 14
#define BLOCK_HARDENED_CLAY 172
#define BLOCK_COAL_BLOCK 173
#define BLOCK_PACKED_ICE 174
#define BLOCK_DOUBLE_PLANT 175
#define BLOCK_DOUBLE_PLANT_DATA_SUNFLOWER 0
#define BLOCK_DOUBLE_PLANT_DATA_LILAC 1
#define BLOCK_DOUBLE_PLANT_DATA_DOUBLE_TALLGRASS 2
#define BLOCK_DOUBLE_PLANT_DATA_LARGE_FERN 3
#define BLOCK_DOUBLE_PLANT_DATA_ROSE_BUSH 4
#define BLOCK_DOUBLE_PLANT_DATA_PEONY 5
#define BLOCK_DOUBLE_PLANT_DATA_TOP 8
#define BLOCK_STANDING_BANNER 176
#define BLOCK_WALL_BANNER 177
#define BLOCK_DAYLIGHT_DETECTOR_INVERTED 178
#define BLOCK_RED_SANDSTONE 179
#define BLOCK_RED_SANDSTONE_STAIRS 180
#define BLOCK_DOUBLE_STONE_SLAB2 181
#define BLOCK_STONE_SLAB2 182
#define BLOCK_SPRUCE_FENCE_GATE 183
#define BLOCK_BIRCH_FENCE_GATE 184
#define BLOCK_JUNGLE_FENCE_GATE 185
#define BLOCK_DARK_OAK_FENCE_GATE 186
#define BLOCK_ACACIA_FENCE_GATE 187
#define BLOCK_SPRUCE_FENCE 188
#define BLOCK_BIRCH_FENCE 189
#define BLOCK_JUNGLE_FENCE 190
#define BLOCK_DARK_OAK_FENCE 191
#define BLOCK_ACACIA_FENCE 192
#define BLOCK_SPRUCE_DOOR 193
#define BLOCK_BIRCH_DOOR 194
#define BLOCK_JUNGLE_DOOR 195
#define BLOCK_ACACIA_DOOR 196
#define BLOCK_DARK_OAK_DOOR 197

extern const char *SubBlockStateNames[SUBBLOCKNAME_COUNT];


#endif
