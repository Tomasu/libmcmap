#ifndef MCMODEL_ELEMENT_H_GUARD
#define MCMODEL_ELEMENT_H_GUARD

#include "Model/Coords.h"
#include "Model/Rotation.h"
#include "Model/Face.h"

#include "CustomVertex.h"

#include "rapidjson/document.h"

class ResourceManager;

namespace Model {

struct Variant;

struct Element {
	private:
		struct UV_MAP
		{
			UV_MAP() : uv() { }
			
			UV_MAP(const Coord4f &uvd) : uv(uvd) { }
			
			VF2 p3() { return VF2(uv.f1, uv.f2); }
			VF2 p4() { return VF2(uv.f3, uv.f2); }
			VF2 p1() { return VF2(uv.f1, uv.f4); }
			VF2 p2() { return VF2(uv.f3, uv.f4); }
			
			Coord4f uv;
		};
		
		struct POINT_MAP
		{
			POINT_MAP() { }
			POINT_MAP(const Coord3f &from, const Coord3f &to) : from_(from), to_(to)
			{ }
			
			VF3 from1() { return VF3(from_.f1, from_.f2, from_.f3); }
			VF3 from2() { return VF3(to_.f1,   from_.f2, from_.f3); }
			VF3 from3() { return VF3(from_.f1, to_.f2,   from_.f3); }
			VF3 from4() { return VF3(to_.f1,   to_.f2,   from_.f3); }
			
			VF3 to1() { return VF3(from_.f1, from_.f2, to_.f3); }
			VF3 to2() { return VF3(to_.f1,   from_.f2, to_.f3); }
			VF3 to3() { return VF3(from_.f1, to_.f2,  to_.f3); }
			VF3 to4() { return VF3(to_.f1,   to_.f2,  to_.f3); }
			
			Coord3f from_, to_;
		};
		
	public:
		Coord3f from, to;
		Rotation rotation;
		bool shade;
		Face faces[Face::MAX_FACES];
		
		uint32_t vertex_count;
		uint32_t vidx;
		CustomVertex *vertices;
		
		bool loadFaces(Variant *variant, rapidjson::Value &v);
		bool load(Variant *variant, rapidjson::Value &v);
		
		void rotate();
};

}
		
#endif /* MCMODEL_ELEMENT_H_GUARD */
