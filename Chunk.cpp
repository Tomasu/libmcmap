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
	
	z_stream strm;
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = 0;
	strm.next_in = 0;
	
	int ret = inflateInit(&strm);
	if(ret != Z_OK)
	{
		fprintf(stderr, "ERROR: failed to initialize zlib\n");
		return false;
	}
	
	uint32_t dest_buffer_size = DEST_BUFFER_SIZE;
	uint32_t dest_buffer_pos = 0;
	uint8_t *dest_buffer = (uint8_t *)malloc(DEST_BUFFER_SIZE);
	
	strm.avail_in = length;
	strm.next_in = (Bytef *)data+5;
	
	do {
		bool force_resize = true;
		
		strm.avail_out = dest_buffer_size - dest_buffer_pos;
		strm.next_out = dest_buffer + dest_buffer_pos;
		
		//printf("size: %i pos: %i\n", dest_buffer_size, dest_buffer_pos);
		
		ret = inflate(&strm, Z_NO_FLUSH);
		assert(ret != Z_STREAM_ERROR);
		
		switch(ret)
		{
			case Z_NEED_DICT:
				ret = Z_DATA_ERROR;
			case Z_DATA_ERROR:
			case Z_MEM_ERROR:
				(void)inflateEnd(&strm);
				fprintf(stderr, "ERROR: decompression error: %s\n", zError(ret));
				free(dest_buffer);
				return false;
		}
		
		if(ret != Z_BUF_ERROR)
		{
			int have = (dest_buffer_size - dest_buffer_pos) - strm.avail_out;
			dest_buffer_pos += have;
			//printf("got %i bytes : (%i - %i) < %i av:%i\n", have, dest_buffer_size, dest_buffer_pos, DEST_BUFFER_SIZE, strm.avail_out);
			//dest_buffer += have;
			force_resize = false;
		}
		else
		{
			//printf("not enough space in dest_buffer. resize!\n");
		}
		
		if(force_resize || dest_buffer_pos + DEST_BUFFER_SIZE < dest_buffer_size)
		{
			dest_buffer_size *= 2;
			dest_buffer = (uint8_t *)realloc(dest_buffer, dest_buffer_size);
			if(!dest_buffer)
			{
				fprintf(stderr, "ERROR: failed to allocate memory for decompressed chunk data\n");
				(void)inflateEnd(&strm);
				return false;
			}
			
			//dest_buffer = dest_buffer_orig + dest_buffer_pos;
			//printf("reallocated decompression buffer to %i bytes\n", dest_buffer_size);
		}
		
	} while (strm.avail_out == 0);
	
	inflateEnd(&strm);
	
	nbt_data = new NBT();
	bool load_ret = nbt_data->decode(dest_buffer, dest_buffer_pos);
	
	free(dest_buffer);
	
	return load_ret;
}
