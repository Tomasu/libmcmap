#ifndef CHUNK_H_GUARD
#define CHUNK_H_GUARD

#include <cstdint>

class NBT;

class Chunk
{
	public:
		Chunk(int t, int co, int cl);
		~Chunk();
		
		bool load(void *data);
		
		int x() { return x_pos; }
		int z() { return z_pos; }
		int getTimestamp() { return timestamp; }
		
		uint32_t offset() { return chunk_offset; }
		uint32_t len() { return chunk_len; }

      NBT *nbt() { return nbt_data; }

	private:
		int x_pos;
		int z_pos;
		int timestamp;
		
		uint32_t chunk_offset;
		uint32_t chunk_len;
		
      NBT *nbt_data;
};

#endif /* CHUNK_H_GUARD */
