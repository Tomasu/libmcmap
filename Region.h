#ifndef REGION_H_GUARD
#define REGION_H_GUARD

#include <vector>
#include <string>
#include <cstdio>

class Chunk;
class NBT_File;

#define SECTOR_SIZE 4096

class Region
{
	public:
		Region(int x, int z);
		Region(const std::string &path);
		~Region();
		
		bool load();
      void unload();

		bool save();
		bool save(const std::string &file);
		
      const std::string &filePath() { return file_path; }
		int x() { return x_pos; }
		int z() { return z_pos; }
		
		bool exists() { return file_exists; }
		bool isOldFormat() { return old_format; }
		
		std::vector <Chunk *> &chunks() { return data; }
		uint32_t chunkCount() { return chunk_count; }
		bool chunkExists(int x, int z);
		
		void deleteChunk(Chunk *chunk);
		
	private:
		int x_pos;
		int z_pos;
		bool file_exists;
		bool old_format;
		uint32_t chunk_count;
		std::string file_path;
		NBT_File *fh;
		
		std::vector <Chunk *> data;
};

#endif /* REGION_H_GUARD */
