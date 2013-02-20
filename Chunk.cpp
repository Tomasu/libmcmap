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
	uint32_t length = 0;
	uint8_t compression_type = 0;
	
	//NBT_Debug("begin");
	
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
	
	//NBT_Debug("chunk offset: %i, length: %i sectors, %i bytes, type: %s\n", chunk_offset, chunk_len, length, compression_type == 1 ? "GZip" : "Zlib");
	
	if(compression_type == 1)
	{
		NBT_Warn("gzip compression type unsupported!\n");
		return false;
	}
	
	if(!fh->readCompressedMode(length))
	{
		NBT_Error("failed to enter compressed mode");
		return false;
	}
	
	nbt_data = (NBT_Tag_Compound *)nbt_data->readTag(fh);
	if(!nbt_data)
	{
		NBT_Error("failed to load root tag");
	}
	
	if(!fh->endCompressedMode())
	{
		NBT_Error("failed to end compressed mode");
		return false;
	}
	
	//NBT_Debug("end");
	
	return nbt_data != 0;
}
