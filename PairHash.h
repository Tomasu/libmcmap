#ifndef PAIRHASH_H_GUARD
#define PAIRHASH_H_GUARD

#include <functional>

namespace std {
template <>
    struct hash < std::pair< int,int> >{
    public :
        size_t operator()(const pair< int, int> &x ) const;
    };
}

#endif /* PAIRHASH_H_GUARD */
