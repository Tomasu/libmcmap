#ifndef MAP_H_GUARD
#define MAP_H_GUARD

#include <vector>
#include <string>

class Region;
class NBT;

class Map
{	
	public:
		Map(const std::string &path, const std::string &name, NBT *level_nbt);
		~Map();
		
		bool load();
		bool save();
		bool saveTo(const std::string &path);
		
		Region *firstRegion();
		Region *nextRegion();
		
		int numRegions() { return data.size(); }
		
		std::string mapPath() const { return map_path; }
		std::string mapName() const { return map_name; }
		
		int32_t dimension() { return dimension_id; }
		
		void setName(const std::string &name) { map_name = name; }
		
		int32_t spawnX();
		int32_t spawnZ();
		int32_t spawnY();
		
	private:
		const std::string map_path;
		std::string map_name;
      uint32_t iterator_pos;
		int32_t dimension_id;
		NBT *level_nbt;
		
		std::vector< Region * > data;
};

#endif /* MAP_H_GUARD */
