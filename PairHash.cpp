#include "PairHash.h"

namespace std {
    size_t hash<pair<int,int>>::operator()(const pair< int, int> &x ) const
    {
        size_t h =   std::hash<int>()(x.first) ^ std::hash<int>()(x.second);
        return  h ;
    }
}