#ifndef MCMODEL_ROTATION_H_GUARD
#define MCMODEL_ROTATION_H_GUARD

#include "rapidjson/document.h"

#include "MCModel/Coords.h"

namespace MCModel {
	
	struct Rotation {
		enum Axis {
			AXIS_NONE = 0,
			AXIS_Y,
			AXIS_Z, 
			AXIS_X
		};
		//"origin": [ 8, 8, 8 ], "axis": "y", "angle": 45, "rescale": true
		Coord3f origin;
		Axis axis;
		float angle;
		bool rescale;
		
		bool load(rapidjson::Value &v);
	};

}

#endif /* MCMODEL_ROTATION_H_GUARD */
