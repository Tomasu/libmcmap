#include <cstdio>
#include <cassert>
#include <cmath>
#include "MCRegion.h"
#include "Chunk.h"
#include "Util.h"

#include "NBT.h"
#include "NBT_Debug.h"
#include "NBT_File.h"

#include "ChunkSection.h"
#include "BlockAddress.h"
#include "BlockInfo.h"

#include <zlib.h>

Chunk::Chunk(int t, int x, int z, int co, int cl) : x_pos(x), z_pos(z), timestamp(t), chunk_offset(co), chunk_len(cl), nbt_data(0)
{
	memset(sections, 0, sizeof(sections));
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
	
	nbt_data = (NBT_Tag_Compound *)NBT_Tag::LoadTag(fh);
	if(!nbt_data)
	{
		NBT_Error("failed to load root tag");
	}
	
	if(!fh->endCompressedMode())
	{
		NBT_Error("failed to end compressed mode");
		return false;
	}
	
	if(nbt_data)
	{
		NBT_Tag_Compound *level_tag = nbt_data->getCompound("Level");
		if(!level_tag)
		{
			NBT_Error("chunk is missing Level tag");
			goto chunk_load_bail;
		}
		
		x_pos = level_tag->getInt("xPos");
		z_pos = level_tag->getInt("zPos");
		
		NBT_Tag_Compound *sections_tag = level_tag->getCompound("Sections");
		if(!sections_tag)
		{
			NBT_Error("chunk is missing Sections tag");
			goto chunk_load_bail;
		}
		
		for(uint32_t section_id = 0; section_id < sections_tag->count(); section_id++)
		{
			NBT_Tag_Compound *section_tag = (NBT_Tag_Compound*)section_tag->childAt(section_id);
			
			ChunkSection *rcs = new ChunkSection();
			if(!rcs->init(section_id, section_tag))
			{
				NBT_Debug("failed to initialize ChunkSection(%i)", section_id);
				delete rcs;
				goto chunk_load_bail;
			}
			
			sections[rcs->y()] = rcs;
		}
		
	}
	
	//NBT_Debug("end");
	
	return nbt_data != 0;
	
chunk_load_bail:
	for(int i = 0; i < MAX_SECTIONS; i++)
		delete sections[i];
	
	if(nbt_data)
		delete nbt_data;
}

bool Chunk::save(NBT_File *fh)
{
	if(!fh->writeCompressedMode())
	{
		NBT_Error("failed to enter compressed mode");
		return false;
	}
	
	//uint32_t begin_pos = fh->tell();
	if(!nbt_data->writeTag(fh))
	{
		NBT_Error("failed to write nbt tag");
		fh->clearCompressedMode();
		return false;
	}
	
	if(!fh->endCompressedMode())
	{
		NBT_Error("failed to end compressed mode");
		fh->clearCompressedMode();
		return false;
	}

	//uint32_t end_pos = fh->tell();
	
	chunk_len = ceil((double)fh->lastWriteBufferLen() / (double)SECTOR_SIZE);
	
	//NBT_Debug("save chunk: begin_pos:%i, end_pos:%i, num chunks:%i (%i)", begin_pos, end_pos, chunk_len, fh->lastWriteBufferLen());
	
	
	return true;
}

bool Chunk::getBlockAddress(int32_t x, int32_t y, int32_t z, BlockAddress *addr)
{
	if((x / 16) != x_pos || (z_pos / 16) != z_pos)
		// not in this chunk.
		return false;
	
	*addr = BlockAddress(x, y, z);
	
	return true;
}

bool Chunk::getBlockInfo(const BlockAddress &addr, BlockInfo *info)
{
	if(addr.section < 0 || addr.section > MAX_SECTIONS)
		return false;
	
	ChunkSection *section = sections[addr.section];
	
	return section->getBlockInfo(addr, info);
}

//BlockState &Chunk::getBlockState(const BlockInfo &info)
//{
//	return 
//}
