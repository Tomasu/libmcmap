#include "MCModel/Rotation.h"
#include "Util.h"

namespace MCModel {
	
	bool Rotation::load(rapidjson::Value &v)
	{
		if(v.IsNull() || !v.IsObject())
			return false;
		
		for(auto it = v.MemberBegin(); it != v.MemberEnd(); it++)
		{
			if(it->name == "origin")
			{
				if(!origin.load(it->value))
					return false;
			}
			else if(it->name == "axis")
			{
				rapidjson::Value &v = it->value;
				
				if(v.IsNull() || !v.IsString())
					return false;
				
				if(v == "x")
					axis = AXIS_X;
				else if(v == "y")
					axis = AXIS_Y;
				else if(v == "z")
					axis = AXIS_Z;
				else
					axis = AXIS_NONE;
			}
			else if(it->name == "angle")
			{
				double angledeg = it->value.GetDouble();
				angle = DEG_TO_RAD(angledeg);
			}
			else if(it->name == "rescale")
			{
				rescale = it->value.GetBool();
			}
		}
		
		return true;
	}
}
