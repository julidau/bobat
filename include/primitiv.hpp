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
	virtual vector3df getCollision(ray3df ray) const = 0;
};

class polygon : public primitiv
{
	vector3df points[3];
	vector3df normal;
public:
	polygon(vector3df a, vector3df b, vector3df c) {normal = (b-a).crossProd(c-a); points[0] = a; points[1] = b; points[2] = c;}
	~polygon() {}

	/* returns 3 values:
	 * X := t of the ray
	 * Y := u on the plane
	 * Z := v on the plane
	 */
	vector3df getCollision(ray3df ray) const;
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
	vector3df getCollision(ray3df ray) const;

	/* get all collisions with ray and npoly */
	core::array<vector3df> getCollisions(ray3df ray);
};

#endif /* PRIMITIV_HPP_ */
