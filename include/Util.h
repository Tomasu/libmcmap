#ifndef UTIL_H_GUARD
#define UTIL_H_GUARD

#include <cstdint>

inline uint32_t swap_uint32( uint32_t val )
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

#include <cmath>
#define DEG_TO_RAD(angle) ((angle) * 180.0 / M_PI)

#endif /* UTIL_H_GUARD */
