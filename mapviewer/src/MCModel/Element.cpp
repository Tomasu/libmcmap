#include "MCModel/Element.h"
#include "MCModel/Variant.h"

#include "Resource/Manager.h"

namespace MCModel {

bool Element::loadFaces(Variant *variant, rapidjson::Value &v, ResourceManager *rm)
{
	if(v.IsNull() || !v.IsObject())
	{
		NBT_Debug("faces is null or not an object?");
		return false;
	}
	
	int32_t face_count = 0;
	for(auto it = v.MemberBegin(); it != v.MemberEnd(); it++)
	{
		if(it->name == "up")
		{
			if(!faces[Face::FACE_UP].load(variant, Face::FACE_UP, it->value, rm))
				return false;
			
			face_count++;
		}
		else if(it->name == "down")
		{
			if(!faces[Face::FACE_DOWN].load(variant, Face::FACE_DOWN, it->value, rm))
				return false;
			
			face_count++;
		}
		else if(it->name == "north")
		{
			if(!faces[Face::FACE_NORTH].load(variant, Face::FACE_NORTH, it->value, rm))
				return false;
			
			face_count++;
		}
		else if(it->name == "east")
		{
			if(!faces[Face::FACE_EAST].load(variant, Face::FACE_EAST, it->value, rm))
				return false;
			
			face_count++;
		}
		else if(it->name == "south")
		{
			if(!faces[Face::FACE_SOUTH].load(variant, Face::FACE_SOUTH, it->value, rm))
				return false;
			
			face_count++;
		}
		else if(it->name == "west")
		{
			if(!faces[Face::FACE_WEST].load(variant, Face::FACE_WEST, it->value, rm))
				return false;
			
			face_count++;
		}
	}
	
	vertex_count = face_count * 6;
	vertices = new CUSTOM_VERTEX[vertex_count];
	vidx = 0;
	
	POINT_MAP pmap_ = POINT_MAP(from, to);
	
	NBT_Debug("got %i faces, need %i vertices", face_count, vertex_count);
	
	if(faces[Face::FACE_UP].direction == Face::FACE_UP)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_UP].uv);
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to3(), uv.p3());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from4(), uv.p2());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from3(), uv.p1());
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to3(), uv.p3());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to4(), uv.p4());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from4(), uv.p2());
	}
	
	if(faces[Face::FACE_SOUTH].direction == Face::FACE_SOUTH)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_SOUTH].uv);
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to2(), uv.p1());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to4(), uv.p3());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to1(), uv.p2());
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to1(), uv.p2());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to4(), uv.p3());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to3(), uv.p4());
	}
	
	if(faces[Face::FACE_WEST].direction == Face::FACE_WEST)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_WEST].uv);
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from2(), uv.p1());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to4(), uv.p4());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to2(), uv.p2());
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from2(), uv.p1());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from4(), uv.p3());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to4(), uv.p4());
	}
	
	if(faces[Face::FACE_NORTH].direction == Face::FACE_NORTH)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_NORTH].uv);
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from1(), uv.p1());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from3(), uv.p3());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from2(), uv.p2());
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from2(), uv.p2());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from3(), uv.p3());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from4(), uv.p4());
	}
	
	if(faces[Face::FACE_EAST].direction == Face::FACE_EAST)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_EAST].uv);
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from1(), uv.p2());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to1(), uv.p1());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from3(), uv.p4());
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to1(), uv.p1());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to3(), uv.p3());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from3(), uv.p4());
	}
	
	if(faces[Face::FACE_DOWN].direction == Face::FACE_DOWN)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_DOWN].uv);
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to1(), uv.p1());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from1(), uv.p3());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from2(), uv.p4());
		
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to1(), uv.p1());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.from2(), uv.p4());
		vertices[vidx++] = CUSTOM_VERTEX(pmap_.to2(), uv.p2());
	}
	
	NBT_Debug("wanted verts: %i, got %i", vertex_count, vidx);
	
	return true;
}

bool Element::load(Variant *variant, rapidjson::Value &v, ResourceManager *rm)
{
	if(v.IsNull() || !v.IsObject())
	{
		NBT_Debug("Element is not valid?");
		return false;
	}
	
	for(auto it = v.MemberBegin(); it != v.MemberEnd(); it++)
	{
		if(it->name == "from")
		{
			if(!from.load(it->value))
				return false;
		}
		else if(it->name == "to")
		{
			if(!to.load(it->value))
				return false;
		}
		else if(it->name == "rotation")
		{
			if(!rotation.load(it->value))
				return false;
		}
		else if(it->name == "shade")
		{
			shade = it->value.GetBool();
		}
		else if(it->name == "faces")
		{
			if(!loadFaces(variant, it->value, rm))
			{
				NBT_Debug("failed to load faces");
				return false;
			}
		}
	}
	
	return true;
}
	
}
