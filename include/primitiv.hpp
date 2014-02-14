/*
 * Primitiv.hpp
 *
 *  Created on: 19.09.2012
 *      Author: julian
 */

#ifndef _BOBAT_PRIMITIV_
#define _BOBAT_PRIMITIV_

#include "vector3d.hpp"
#include "ray3d.hpp"
#include "array.hpp"

class primitiv
{
public:
	virtual ~primitiv() {}
	virtual f32 getCollision(ray3df * ray) = 0;

	virtual color<f32> getColorAt(f32 u, f32 v) { return color<f32>(1,1,1,1); }
};

class polygon : public primitiv
{
	vector3df points[3];
	vector3df normal;

	color<f32> myColor;

public:
	polygon(vector3df a, vector3df b, vector3df c):
		myColor(1,1,1,1)
	{
		points[0] = a; points[1] = b; points[2] = c;
		recalculateNormal();
	}

	polygon(vector3df*  pointArray):
		myColor(1,1,1,1)
	{
		core::memcopy(points, pointArray, 3);
		recalculateNormal();
	}

	~polygon() {}

	void recalculateNormal()
	{
		normal = (points[1]-points[0]).crossProd(points[2]-points[0]);
	}
	/* returns 3 values:
	 * X := t of the ray
	 * Y := u on the plane
	 * Z := v on the plane
	 */
	f32 getCollision(ray3df * ray);

	void setColor(color<f32> newColor) { myColor = newColor; }
	// TODO: reimplement color grab method
	color<f32> getColorAt(f32 u, f32 v)
	{
		return myColor;
	}
};

class npolygon : virtual primitiv
{
	core::array<polygon> polys;
public:
	npolygon(core::array<vector3df> points);
	npolygon(core::array<polygon> polys);

	~npolygon();

	/* get first collision with ray
	 * returns:
	 * 	X := t of ray
	 * 	Y := u of plane
	 * 	Z := v of plane
	 * */
	f32 getCollision(ray3df * ray);

	/* get all collisions with ray and npoly */
	core::array<vector3df> getCollisions(ray3df * ray);
};

#endif /* PRIMITIV_HPP_ */
