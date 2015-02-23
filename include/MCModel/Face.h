#ifndef MCMODEL_FACE_H_GUARD
#define MCMODEL_FACE_H_GUARD

#include "rapidjson/document.h"
#include "Resource/Resource.h"

#include "MCModel/Coords.h"

class ResourceManager;

namespace MCModel {

struct Variant;

struct Face {
	const static uint32_t MAX_FACES = 6;
	enum CullFace {
		CULL_NONE = 0,
		CULL_UP,
		CULL_DOWN,
		CULL_NORTH,
		CULL_EAST,
		CULL_SOUTH,
		CULL_WEST
	};
	
	enum FaceDirection {
		FACE_NONE = -1,
		FACE_UP = 0,
		FACE_DOWN,
		FACE_NORTH,
		FACE_EAST,
		FACE_SOUTH,
		FACE_WEST
	};
	
	FaceDirection direction;
	Coord4f uv;
	std::string texname;
	Resource::ID tex_res;
	uint32_t tex_page;
	CullFace cull;
	int32_t tintindex;
	float rotation;
	
	Face() : direction(FACE_NONE), uv(), texname(), cull(CULL_NONE), tintindex(-1) { }
	// TODO: putBitmap for texture?
	
	bool load(Variant *variant, FaceDirection dir, rapidjson::Value &v, ResourceManager *rm);
};

}

#endif /* MCMODEL_FACE_H_GUARD */
