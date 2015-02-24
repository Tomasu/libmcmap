#ifndef MCMODEL_ROTATION_H_GUARD
#define MCMODEL_ROTATION_H_GUARD

#include "rapidjson/document.h"

#include "Model/Coords.h"

namespace Model {
	
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
		
		Rotation() : origin(), axis(AXIS_NONE), angle(0.0), rescale(0.0) { }
		
		bool load(rapidjson::Value &v);
		
		bool shouldRotate() { return angle != 0.0; }
	};

}

#endif /* MCMODEL_ROTATION_H_GUARD */
