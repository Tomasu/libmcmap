#include <cstdio>
#include <cassert>
#include <cmath>
#include "Region.h"
#include "Chunk.h"
#include "Util.h"

#include "NBT.h"
#include "NBT_Debug.h"
#include "NBT_File.h"

#include <zlib.h>

Chunk::Chunk(int t, int x, int z, int co, int cl) : x_pos(x), z_pos(z), timestamp(t), chunk_offset(co), chunk_len(cl), nbt_data(0)
{
	
}

Chunk::~Chunk()
{
	 if(nbt_data)
		  delete nbt_data;

	 nbt_data = 0;
}

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
	
	uint32_t swapped = swap_uint32(length);
	//NBT_Debug("chunk offset: %i, length: %i sectors, %i bytes (%u), type: %s", chunk_offset, chunk_len, length, swapped, compression_type == 1 ? "GZip" : "Zlib");
	
	if(compression_type == 1)
	{
		NBT_Warn("gzip compression type unsupported!\n");
		return false;
	}
	
	if(!fh->readCompressedMode(length-1))
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

bool Chunk::save(NBT_File *fh)
{
	if(!fh->writeCompressedMode())
	{
		NBT_Error("failed to enter compressed mode");
		return false;
	}
	
	if(!nbt_data->writeTag(fh))
	{
		NBT_Error("failed to write nbt tag");
		fh->clearCompressedMode();
		return false;
	}
	
	chunk_len = ceil((double)fh->tell() / (double)SECTOR_SIZE);
	
	if(!fh->endCompressedMode())
	{
		NBT_Error("failed to end compressed mode");
		fh->clearCompressedMode();
		return false;
	}
	
	return true;
}


