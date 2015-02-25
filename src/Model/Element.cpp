#include "Model/Element.h"
#include "Model/Variant.h"
#include "NBT_Debug.h"

namespace Model {

bool Element::loadFaces(Variant *variant, rapidjson::Value &v)
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
			if(!faces[Face::FACE_UP].load(variant, Face::FACE_UP, it->value))
				return false;
			
			face_count++;
		}
		else if(it->name == "down")
		{
			if(!faces[Face::FACE_DOWN].load(variant, Face::FACE_DOWN, it->value))
				return false;
			
			face_count++;
		}
		else if(it->name == "north")
		{
			if(!faces[Face::FACE_NORTH].load(variant, Face::FACE_NORTH, it->value))
				return false;
			
			face_count++;
		}
		else if(it->name == "east")
		{
			if(!faces[Face::FACE_EAST].load(variant, Face::FACE_EAST, it->value))
				return false;
			
			face_count++;
		}
		else if(it->name == "south")
		{
			if(!faces[Face::FACE_SOUTH].load(variant, Face::FACE_SOUTH, it->value))
				return false;
			
			face_count++;
		}
		else if(it->name == "west")
		{
			if(!faces[Face::FACE_WEST].load(variant, Face::FACE_WEST, it->value))
				return false;
			
			face_count++;
		}
	}
	
	// FIXME: needs to be handled properly...
	if(rotation.shouldRotate())
		rotate(); // rotates from/to coords.
	
	// TODO: think about moving this vertex building out of libmcmap
	vertex_count = face_count * 6;
	vertices = new CustomVertex[vertex_count];
	vidx = 0;
	
	POINT_MAP pmap_ = POINT_MAP(from, to);
	
	NBT_Debug("got %i faces, need %i vertices", face_count, vertex_count);
	
	if(faces[Face::FACE_UP].direction == Face::FACE_UP)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_UP].uv);
		
		vertices[vidx++] = CustomVertex(pmap_.to3(), uv.p3());
		vertices[vidx++] = CustomVertex(pmap_.from4(), uv.p2());
		vertices[vidx++] = CustomVertex(pmap_.from3(), uv.p1());
		
		vertices[vidx++] = CustomVertex(pmap_.to3(), uv.p3());
		vertices[vidx++] = CustomVertex(pmap_.to4(), uv.p4());
		vertices[vidx++] = CustomVertex(pmap_.from4(), uv.p2());
	}
	
	if(faces[Face::FACE_SOUTH].direction == Face::FACE_SOUTH)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_SOUTH].uv);
		
		vertices[vidx++] = CustomVertex(pmap_.to2(), uv.p1());
		vertices[vidx++] = CustomVertex(pmap_.to4(), uv.p3());
		vertices[vidx++] = CustomVertex(pmap_.to1(), uv.p2());
		
		vertices[vidx++] = CustomVertex(pmap_.to1(), uv.p2());
		vertices[vidx++] = CustomVertex(pmap_.to4(), uv.p3());
		vertices[vidx++] = CustomVertex(pmap_.to3(), uv.p4());
	}
	
	if(faces[Face::FACE_WEST].direction == Face::FACE_WEST)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_WEST].uv);
		
		vertices[vidx++] = CustomVertex(pmap_.from2(), uv.p1());
		vertices[vidx++] = CustomVertex(pmap_.to4(), uv.p4());
		vertices[vidx++] = CustomVertex(pmap_.to2(), uv.p2());
		
		vertices[vidx++] = CustomVertex(pmap_.from2(), uv.p1());
		vertices[vidx++] = CustomVertex(pmap_.from4(), uv.p3());
		vertices[vidx++] = CustomVertex(pmap_.to4(), uv.p4());
	}
	
	if(faces[Face::FACE_NORTH].direction == Face::FACE_NORTH)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_NORTH].uv);
		
		vertices[vidx++] = CustomVertex(pmap_.from1(), uv.p1());
		vertices[vidx++] = CustomVertex(pmap_.from3(), uv.p3());
		vertices[vidx++] = CustomVertex(pmap_.from2(), uv.p2());
		
		vertices[vidx++] = CustomVertex(pmap_.from2(), uv.p2());
		vertices[vidx++] = CustomVertex(pmap_.from3(), uv.p3());
		vertices[vidx++] = CustomVertex(pmap_.from4(), uv.p4());
	}
	
	if(faces[Face::FACE_EAST].direction == Face::FACE_EAST)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_EAST].uv);
		
		vertices[vidx++] = CustomVertex(pmap_.from1(), uv.p2());
		vertices[vidx++] = CustomVertex(pmap_.to1(), uv.p1());
		vertices[vidx++] = CustomVertex(pmap_.from3(), uv.p4());
		
		vertices[vidx++] = CustomVertex(pmap_.to1(), uv.p1());
		vertices[vidx++] = CustomVertex(pmap_.to3(), uv.p3());
		vertices[vidx++] = CustomVertex(pmap_.from3(), uv.p4());
	}
	
	if(faces[Face::FACE_DOWN].direction == Face::FACE_DOWN)
	{
		UV_MAP uv = UV_MAP(faces[Face::FACE_DOWN].uv);
		
		vertices[vidx++] = CustomVertex(pmap_.to1(), uv.p1());
		vertices[vidx++] = CustomVertex(pmap_.from1(), uv.p3());
		vertices[vidx++] = CustomVertex(pmap_.from2(), uv.p4());
		
		vertices[vidx++] = CustomVertex(pmap_.to1(), uv.p1());
		vertices[vidx++] = CustomVertex(pmap_.from2(), uv.p4());
		vertices[vidx++] = CustomVertex(pmap_.to2(), uv.p2());
	}
	
	NBT_Debug("wanted verts: %i, got %i", vertex_count, vidx);
	
	return true;
}

void Element::rotate()
{
	// FIXME: don't use allegro here, or somehow delay vertex generation till we have a chance to 
	/*
	ALLEGRO_TRANSFORM rot;
	al_identity_transform(&rot);
	al_translate_transform_3d(&rot, -(rotation.origin.f1/2), -(rotation.origin.f2/2), -(rotation.origin.f3/2));
	
	if(rotation.axis == Rotation::AXIS_X)
		al_rotate_transform_3d(&rot, 1.0, 0.0, 0.0, rotation.angle);
	else if(rotation.axis == Rotation::AXIS_Y)
		al_rotate_transform_3d(&rot, 0.0, 1.0, 0.0, rotation.angle);
	else if(rotation.axis == Rotation::AXIS_Z)
		al_rotate_transform_3d(&rot, 0.0, 0.0, 1.0, rotation.angle);
	
	al_translate_transform_3d(&rot, (rotation.origin.f1/2), (rotation.origin.f2/2), (rotation.origin.f3/2));
	
	al_transform_coordinates_3d(&rot, &(from.f1), &(from.f2), &(from.f3));
	al_transform_coordinates_3d(&rot, &(to.f1), &(to.f2), &(to.f3));
	*/
}

bool Element::load(Variant *variant, rapidjson::Value &v)
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
			if(!loadFaces(variant, it->value))
			{
				NBT_Debug("failed to load faces");
				return false;
			}
		}
	}
	
	return true;
}
	
}
