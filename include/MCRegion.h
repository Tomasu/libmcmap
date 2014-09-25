#ifndef REGION_H_GUARD
#define REGION_H_GUARD

#include <vector>
#include <string>
#include <cstdio>
#include <unordered_map>

#include "PairHash.h"

class Chunk;
class NBT_File;

#define SECTOR_SIZE 4096

class MCRegion
{
	public:
		typedef std::pair<int32_t, int32_t> Key;
		
		MCRegion(int x, int z);
		MCRegion(const std::string &path);
		~MCRegion();
		
		bool load();
      void unload();

		bool save();
		bool save(const std::string &file);
		
      const std::string &filePath() { return file_path; }
		int x() { return x_pos; }
		int z() { return z_pos; }
		
		bool exists() { return file_exists; }
		bool isOldFormat() { return old_format; }
		
		std::vector <Chunk *> chunks();
		uint32_t chunkCount() { return chunk_count; }
		bool chunkExists(int x, int z);
		
		void deleteChunk(Chunk *chunk);
		
		bool containsChunk(int32_t x, int32_t z);
		
		Key key() { return Key(x_pos, z_pos); }
		
		Chunk *getChunkRel(int32_t x, int32_t z);
		Chunk *getChunkAbs(int32_t x, int32_t z);
		
	private:
		int x_pos;
		int z_pos;
		bool file_exists;
		bool old_format;
		uint32_t chunk_count;
		std::string file_path;
		NBT_File *fh;
		
		std::unordered_map<Key, Chunk *> data;
};

#endif /* REGION_H_GUARD */
