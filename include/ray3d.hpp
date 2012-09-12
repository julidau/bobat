#ifndef _BOBAT_RAY3D_
#define _BOBAT_RAY3D_

#include "vector3d.hpp"

template <class T>
class ray3d
{
	vector3d<T> start,direction;
public:
	ray3d(vector3d<T> Start, vector3d<T> Dir) : start(Start),direction(Dir) {}

	vector3d<T> getStart() { return start; }
	vector3d<T> getDirection() { return direction; }

	vector3d<T> getPoint(f32 r) {
		vector3d<T> test = r*direction;
		return start+test;
	}
};

#endif
