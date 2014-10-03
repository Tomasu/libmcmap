#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <cstdint>
#include <algorithm>

#include "NBT_File.h"
#include "NBT_Debug.h"
#include "MCRegion.h"
#include "Chunk.h"
#include "Util.h"


MCRegion::MCRegion(int x, int z) : x_pos(x), z_pos(z), file_exists(false), old_format(false), chunk_count(0)
{
	fh = 0;
}

MCRegion::MCRegion(const std::string &path) : x_pos(0), z_pos(0), file_exists(false), old_format(false), chunk_count(0)
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
					//else
					//	return;
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
	
	NBT_Debug("create region %ix%i %s", x_pos, z_pos, path.c_str());
	file_exists = true;
	file_path = path;
	fh = 0;
}

MCRegion::~MCRegion()
{
   if(fh)
      delete fh;

   fh = 0;

   for(auto &chunk: data)
   {
      delete chunk.second;
   }

   data.clear();
}

/*static int chunk_timestamp_compare(Chunk *a, Chunk *b)
{
	return a->offset() < b->offset();
}*/

bool MCRegion::load()
{
	if(data.size())
		return true;
	
	if(!file_exists)
	{
		fprintf(stderr, "region %ix%i doesn't have a file!'\n", x_pos, z_pos);
		return false;
	}
	
	if(old_format)
	{
		fprintf(stderr, "region %ix%i is in pre anvil format, not loading.\n", x_pos, z_pos);
		return false;
	}
	
	NBT_Debug("load region %s", file_path.c_str());
	fh = new NBT_File(file_path);

	if(!fh->open())
	{
		fprintf(stderr, "failed to open region file: %s: %s\n", file_path.c_str(), strerror(errno));
		return false;
	}
	
	//fh->seek(0, SEEK_END);
	//int file_length = fh->tell();
	//fh->seek(0, SEEK_SET);
	
	//NBT_Debug("region file length: %i bytes", file_length);
	
	uint32_t loc_header[1024];
	uint32_t ts_header[1024];
	
	if(!fh->read(loc_header, 1024))
	{
		NBT_Error("failed to read chunk location header");
		fh->close();
		return false;
	}
	
	if(!fh->read(ts_header, 1024))
	{
		NBT_Error("failed to read chunk timestamp header");
		fh->close();
		return false;
	}
	
	bool ret = true;
	for(int i = 0; i < 1024; i++)
	{
		uint32_t offset = loc_header[i] >> 8;
		uint8_t len = loc_header[i] & 255;
		
		if(!offset || !len)
		{
			// missing chunk
			//fprintf(stderr, "chunk empty %i %i!\n", offset, len);
			continue;
		}
		
		uint32_t x = i % 32;
		uint32_t z = i / 32;
		
		x += this->x() * 32;
		z += this->z() * 32;
		
		Chunk *chunk = new Chunk(ts_header[i], 0xdeadbeef, 0xdeadbeef, offset, len);
		//NBT_Debug("new chunk: i:%i offset:%i %i len:%i x:%i z:%i idx:%i", i, offset, chunk->offset(), len, x, z, x + z * 32);
		
		if(!fh->seek(chunk->offset() * SECTOR_SIZE, SEEK_SET))
		{
			NBT_Error("failed to seek to chunk offset");
			ret = false;
			break;
		}
		
		if(!chunk->load(fh))
		{
			NBT_Error("failed to load chunk");
			delete chunk;
			ret = false;
			break;
		}
		
		//NBT_Debug("new chunk: i:%i offset:%i %i len:%i x:%i z:%i idx:%i", i, offset, chunk->offset(), len, x, z, x + z * 32);
		
		data.emplace(chunk->key(), chunk);
		
		// check to see if chunk is in the right location
		int cx = chunk->x() % 32;
		int cz = chunk->z() % 32;
		
		if(cx < 0)
			cx = 32 - -cx;
		if(cz < 0)
			cz = 32 - -cz;
		
		int chunk_idx = (cx + cz * 32);
		
		if(i != chunk_idx)
		{
			NBT_Warn("chunk %ix%i in wrong location? expected %i got %i", chunk->x(), chunk->z(), i, chunk_idx);
		}
		
		// check to see if chunk belongs in this region
		int chunk_regionx = ceil((double)(chunk->x()+1) / 32.0 - 1);
		int chunk_regionz = ceil((double)(chunk->z()+1) / 32.0 - 1);
		
		if(x_pos != chunk_regionx || z_pos != chunk_regionz)
		{
			NBT_Warn("chunk %ix%i in wrong region? expected %ix%i got %ix%i", x_pos, z_pos, chunk_regionx, chunk_regionz);
		}
//		NBT_Debug("region %ix%i: chunk[%i] %ix%i claims region %ix%i", x_pos, z_pos, i, chunk->x(), chunk->z(), chunk_regionx, chunk_regionz);
		
		chunk_count++;
	}
	
	//std::sort(temp_list.begin(), temp_list.end(), &chunk_timestamp_compare);
	
	//NBT_Debug("got %i chunks", chunk_count);
	
   delete fh;
	fh = 0;

	//NBT_Debug("region: loaded %li chunks from %s\n", this->data.size(), file_path.c_str());
	
	return ret;
}

void MCRegion::unload()
{
   for(auto &chunk: data)
   {
      delete chunk.second;
   }

   data.clear();
	
	if(fh)
		delete fh;
	
	fh = 0;
	
	chunk_count = 0;
}


// save: a chunk's header data is in a position in the header relative to its x/z coords.
// 4 * ((x mod 32) + (z mod 32) * 32)

bool MCRegion::save()
{
	return save(file_path);
}

bool MCRegion::save(const std::string &file_name)
{
	bool ret = true;
	
	if(fh)
	{
		NBT_Error("region file already open?");
		return false;
	}
	
	fh = new NBT_File(file_name, false); // open for writing
	if(!fh->open())
	{
		NBT_Error("failed to open region file :(");
		return false;
	}
	
	uint32_t chunk_locs[1024];
	uint32_t chunk_timestamps[1024];
	
	memset(chunk_locs, 0, sizeof(chunk_locs));
	memset(chunk_timestamps, 0, sizeof(chunk_timestamps));
	
	uint32_t chunk_off = 2;
	
	// TODO: think about sorting, or saving by x,z?
	//  this seeks around quite a bit...
	
	uint32_t i = 0;
	
	for(auto &it: data)
	{
		Chunk *chunk = it.second;
		
		if(!chunk)
			continue;
		
		uint32_t loc = 0;
		
		int x = chunk->x() % 32;
		int z = chunk->z() % 32;
		
		if(x < 0)
			x = 31 - -x;
		if(z < 0)
			z = 31 - -z;
		
		//chunk_idx = (x + z * 32);

		//NBT_Debug("%i/%i/%i %ix%i/%ix%i orig offset:%i new offset:%i", chunk->getIdx(), chunk_idx, i, chunk->x(), chunk->z(), x, z, chunk->offset(), chunk_off);
		
		if(!fh->seek(chunk_off * SECTOR_SIZE))
		{
			NBT_Error("failed to seek to chunk location");
			ret = false;
			goto out;
		}
		
		if(!chunk->save(fh))
		{
			NBT_Error("failed to save chunk");
			ret = false;
			goto out;
		}
		
		uint32_t sector_count = chunk->len();
		
		//NBT_Debug("sector_loc: %i, sector_count: %i", sector_loc, sector_count);
		loc = (chunk_off << 8) | (sector_count & 0xff);
		
		//NBT_Debug("x: %i/%i, z: %i/%i, chunk_idx: %i/%i", x, chunk->x(), z, chunk->z(), chunk->getIdx(), chunk_idx);
		chunk_locs[i] = loc;
		chunk_timestamps[i] = chunk->getTimestamp();
		
		i++;
		
		chunk_off += sector_count;
	}
	
	fh->seek(0);
	
	//NBT_Debug("writing headers: %i bytes", sizeof(chunk_locs)+sizeof(chunk_timestamps));
	fh->write(chunk_locs, 1024);
	fh->write(chunk_timestamps, 1024);
	
out:
	fh->close();
	delete fh;
	fh = 0;

	return ret;
}

void MCRegion::deleteChunk(Chunk *chunk)
{
	data.erase(chunk->key());
	chunk_count--;
}

bool MCRegion::chunkExists(int x, int z)
{
	if(data.count(Chunk::Key(x, z)) < 1)
		return false;
	
	auto it = data.find(Chunk::Key(x, z));
	if(it == data.end() || it->second == nullptr)
		return false;
	
	return true;
}

bool MCRegion::containsChunk(int32_t x, int32_t z)
{
	if((x >> 5) != x_pos)
	{
		NBT_File("x out of range: %i vs %i", x >> 5, x_pos);
		return false;
	}
	
	if((z >> 5) != z_pos)
	{
		NBT_File("z out of range: %i vs %i", z >> 5, z_pos);
		return false;
	}
	
	return true;
}

std::vector< Chunk* > MCRegion::chunks()
{
	std::vector<Chunk *> vec;
	
	for(auto &it: data)
	{
		vec.push_back(it.second);
	}
	
	return vec;
}

Chunk* MCRegion::getChunkAbs(int32_t x, int32_t z)
{
	if(!containsChunk(x, z))
	{
		NBT_Debug("region %ix%i does not contain chunk %ix%i", x_pos, z_pos, x, z);
		return nullptr;
	}
	
	return getChunkRel(x, z);
}

Chunk* MCRegion::getChunkRel(int32_t x, int32_t z)
{
	auto it = data.find(Chunk::Key(x, z));
	if(it == data.end() || it->second == nullptr)
	{
		NBT_Debug("itend: %i, second:%p", it == data.end(), it != data.end() ? it->second : nullptr);
		return nullptr;
	}
	
	return it->second;
}


