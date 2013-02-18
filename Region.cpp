#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <cstdint>
#include <algorithm>

#include "NBT_File.h"
#include "NBT_Debug.h"
#include "Region.h"
#include "Chunk.h"
#include "Util.h"

Region::Region(int x, int z) : x_pos(x), z_pos(z), file_exists(false), old_format(false)
{
	
}

Region::Region(const std::string &path) : x_pos(0), z_pos(0), file_exists(false), old_format(false)
{
	const char *c_path = path.c_str();
	
	const char *ptr = c_path+path.length();
	const char *ext_str = 0;
	const char *z_str = 0;
	const char *x_str = 0;
	
	while(ptr > c_path)
	{
		if(*ptr == '.')
		{
			if(!ext_str)
			{
				ext_str = ptr+1;
				if(strcmp(ext_str, "mca") != 0)
				{
					if(strcmp(ext_str, "mcr") == 0)
					{
						//fprintf(stderr, "found old region file: %s\n", path.c_str());
						old_format = true;
					}
					else
						return;
				}
			}
			else if(!z_str)
			{
				z_str = ptr+1;
				z_pos = strtol(z_str, 0, 10);
			}
			else if(!x_str)
			{
				x_str = ptr+1;
				x_pos = strtol(x_str, 0, 10);
			}
		}
		
		ptr--;
	}
	
	file_exists = true;
	file_path = path;
}

Region::~Region()
{
   if(fh)
      fclose(fh);

   fh = 0;

   for(auto &chunk: data)
   {
      delete chunk;
   }

   data.clear();
}

static int chunk_timestamp_compare(Chunk *a, Chunk *b)
{
	return a->offset() < b->offset();
}

bool Region::load()
{
	if(!file_exists)
	{
		fprintf(stderr, "chunk %ix%i doesn't have a file!'\n", x_pos, z_pos);
		return false;
	}
	
	if(old_format)
	{
		fprintf(stderr, "chunk %ix%i is in pre anvil format, not loading.\n", x_pos, z_pos);
		return false;
	}
	
	fh = new NBT_File(file_path);

	if(fh->open()))
	{
		fprintf(stderr, "failed to open chunk file: %s: %s\n", file_path.c_str(), strerror(errno));
		return false;
	}
	
	fh->fseek(0, SEEK_END);
	int file_length = fh->tell();
	fh->seek(0, SEEK_SET);
	
	printf("region file length: %i bytes\n", file_length);
	
	std::vector<Chunk *> temp_list;
	
	for(int i = 0; i < SECTOR_SIZE/4; i++)
	{
		uint32_t loc = 0;
		if(!fh->read(&loc))
		{
			NBT_Debug("failed to read chunk %i location", i);
			fh->close();
			return false;
		}
		
		uint32_t offset = loc >> 8;
		uint8_t len = loc & 0xff;//(loc >> 24) & 0xff;
		
		if(!offset || !len)
		{
			// missing chunk
			//fprintf(stderr, "chunk empty %i %i!\n", offset, len);
			continue;
		}
		
		Chunk *chunk = new Chunk(0, offset, len);
		temp_list.push_back(chunk);
	}
	
	for(int i = 0; i < SECTOR_SIZE/4; i++)
	{
		uint32_t timestamp = 0;
		
		if(!fh->read(&timestamp))
		{
			NBT_Debug("failed to read chunk %i timestamp", i);
			fh->close();
			return false;
		}
		
		temp_list[i].setTimestamp(timestamp);
	}
	
	std::sort(temp_list.begin(), temp_list.end(), &chunk_timestamp_compare);
	
	std::vector<Chunk *>::iterator chunk_iterator;
	
	for(chunk_iterator = temp_list.begin(); chunk_iterator != temp_list.end(); chunk_iterator++)
	{
		Chunk *chunk = *chunk_iterator;
		
		if(!fh->seek(chunk->offset() * SECTOR_SIZE, SEEK_SET))
		{
			break;
		}
		
		if(!chunk->load(fh))
		{
			delete chunk;
			break;
		}
		
      delete chunk_data;

		this->data.push_back(chunk);
		
		//printf("chunk offset at %i 4k sectors %i sectors long\n", offset, len);
	}
	
   fh->close();
   fh = 0;

	printf("region: loaded %li chunks from %s\n", this->data.size(), file_path.c_str());
	
	return true;
}

void Region::unload()
{
   for(auto &chunk: data)
   {
      delete chunk;
   }

   data.clear();
}


// save: a chunk's header data is in a position in the header relative to its x/z coords.
// 4 * ((x mod 32) + (z mod 32) * 32)




