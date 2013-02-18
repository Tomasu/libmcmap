#include <cstdio>
#include <cassert>
#include "Region.h"
#include "Chunk.h"
#include "Util.h"

#include "NBT.h"
#include "NBT_Debug.h"
#include "NBT_File.h"

#include <zlib.h>

Chunk::Chunk(int t, int co, int cl) : timestamp(t), chunk_offset(co), chunk_len(cl)
{
	
}

Chunk::~Chunk()
{
	 if(nbt_data)
		  delete nbt_data;

	 nbt_data = 0;
}

// TODO: move decompression code into NBT_Buffer

#define DEST_BUFFER_SIZE (SECTOR_SIZE * 8)
bool Chunk::load(NBT_File *fh)
{
	uint32_t length = swap_uint32(*((uint32_t *)data));
	uint8_t compression_type = ((uint8_t *)data)[4];
	
	if(!fh->read(&length))
	{
		NBT_Error("failed to read compressed chunk data length");
		return false;
	}
	
	if(!fh->read(&compression_type))
	{
		NBT_Error("failed to read chunk compression type");
		return false;
	}
	
	//printf("chunk offset: %i, length: %i sectors, %i bytes, type: %s\n", chunk_offset, chunk_len, length, compression_type == 1 ? "GZip" : "Zlib");
	
	if(compression_type == 1)
	{
		NBT_Warn("gzip compression type unsupported!\n");
		return false;
	}
	
	
	nbt_data = new NBT();
	bool load_ret = nbt_data->decode(dest_buffer, dest_buffer_pos);
	
	free(dest_buffer);
	
	return load_ret;
}
