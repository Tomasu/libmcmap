#ifndef MCMODEL_COORDS_H_GUARD
#define MCMODEL_COORDS_H_GUARD

#include "rapidjson/document.h"

namespace MCModel {
	
struct Coord3f {
	float f1, f2, f3;
	
	Coord3f(float f1_ = 0.0, float f2_ = 0.0, float f3_ = 0.0) : f1(f1_), f2(f2_), f3(f3_) { }
	
	bool load(rapidjson::Value &v)
	{
		if(v.IsNull() || !v.IsArray())
			return false;
		
		f1 = v[0u].GetDouble() / 16.0;
		f2 = v[1u].GetDouble() / 16.0;
		f3 = v[2u].GetDouble() / 16.0;
		
		return true;
	}
};

struct Coord2f {
	float f1, f2;
	
	Coord2f(float f1_ = 0.0, float f2_ = 0.0) : f1(f1_), f2(f2_) { }
	
	bool load(rapidjson::Value &v)
	{
		if(v.IsNull() || !v.IsArray())
			return false;
		
		f1 = v[0u].GetDouble() / 16.0;
		f2 = v[1u].GetDouble() / 16.0;
		
		return true;
	}
};

struct Coord4f {
	float f1, f2, f3, f4;
	
	Coord4f(float f1_ = 0.0, float f2_ = 0.0, float f3_ = 0.0, float f4_ = 0.0) : f1(f1_), f2(f2_), f3(f3_), f4(f4_) { }
	
	bool load(rapidjson::Value &v)
	{
		if(v.IsNull() || !v.IsArray())
			return false;
		
		f1 = v[0u].GetDouble() / 16.0;
		f2 = v[1u].GetDouble() / 16.0;
		f3 = v[2u].GetDouble() / 16.0;
		f4 = v[3u].GetDouble() / 16.0;
		
		return true;
	}
};

}

#endif /* MCMODEL_COORDS_H_GUARD */
