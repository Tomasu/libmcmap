#ifndef BLOCKMAPS_H_GUARD
#define BLOCKMAPS_H_GUARD

#include <cstdint>

#define BLOCK_COUNT 146
extern const char *BlockNames[BLOCK_COUNT];
struct SubBlockRange { uint32_t start; uint32_t num; };
extern SubBlockRange subBlockRange[BLOCK_COUNT];
#define SUBBLOCKNAME_COUNT 55
extern const char *SubBlockNames[SUBBLOCKNAME_COUNT];

#endif
