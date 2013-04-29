#ifndef MAP_H_GUARD
#define MAP_H_GUARD

#include <vector>
#include <string>

class Region;

class Map
{	
	public:
		Map(const std::string &path);
		~Map();
		
		bool load();
		bool save();
		bool saveTo(const std::string &path);
		
		Region *firstRegion();
		Region *nextRegion();
		
		int numRegions() { return data.size(); }
		
	private:
		const std::string map_path;
      uint32_t iterator_pos;
		
		std::vector< Region * > data;
};

#endif /* MAP_H_GUARD */
