#ifndef REGION_H_GUARD
#define REGION_H_GUARD

#include <vector>
#include <string>
#include <cstdio>

class Chunk;

#define SECTOR_SIZE 4096

class Region
{
	public:
		Region(int x, int z);
		Region(const std::string &path);
		~Region();
		
		bool load();
      void unload();

      const std::string &filePath() { return file_path; }
		int x() { return x_pos; }
		int z() { return z_pos; }
		
		bool exists() { return file_exists; }
		bool isOldFormat() { return old_format; }
		
		const std::vector <Chunk *> &chunks() { return data; }
		
	private:
		int x_pos;
		int z_pos;
		bool file_exists;
		bool old_format;
		std::string file_path;
		FILE *fh;
		
		std::vector <Chunk *> data;
};

#endif /* REGION_H_GUARD */
