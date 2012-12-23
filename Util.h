#ifndef UTIL_H_GUARD
#define UTIL_H_GUARD

inline uint32_t swap_uint32( uint32_t val )
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

#endif /* UTIL_H_GUARD */
