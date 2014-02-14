#ifndef _BOBAT_RAY3D_
#define _BOBAT_RAY3D_

#include "vector3d.hpp"
#include "color.hpp"

template <class T>
class ray3d
{
protected:
	vector3d<T> start,direction;
	color<f32> myColor;

public:
	ray3d(vector3d<T> Start = vector3d<T>(), vector3d<T> Dir = vector3d<T>()) : start(Start),direction(Dir) {}
	ray3d(ray3d<T> &other) :start(other.start), direction(other.direction), myColor(other.myColor) {}

	vector3d<T> getStart() { return start; }
	vector3d<T> getDirection() { return direction; }

	vector3d<T> getPoint(f32 u) {
		return start+(direction*u);
	}

	color<f32> getColor() { return myColor; }
	void setColor(color<f32> newColor) { myColor = newColor; }
};

typedef ray3d<f32> ray3df;
#endif
