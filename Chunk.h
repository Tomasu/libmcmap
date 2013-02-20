#ifndef CHUNK_H_GUARD
#define CHUNK_H_GUARD

#include <cstdint>

class NBT_Tag_Compound;
class NBT_File;

class Chunk
{
	public:
		Chunk(int t, int co, int cl);
		~Chunk();
		
		bool load(NBT_File *fh);
		bool save(NBT_File *buff);
		
		int x() { return x_pos; }
		int z() { return z_pos; }
		
		void setTimestamp(uint32_t timestamp) { this->timestamp = timestamp; }
		int getTimestamp() { return timestamp; }
		
		uint32_t offset() { return chunk_offset; }
		uint32_t len() { return chunk_len; }

      NBT_Tag_Compound *nbt() { return nbt_data; }

	private:
		int x_pos;
		int z_pos;
		int timestamp;
		
		uint32_t chunk_offset;
		uint32_t chunk_len;
		
      NBT_Tag_Compound *nbt_data;
};

#endif /* CHUNK_H_GUARD */
