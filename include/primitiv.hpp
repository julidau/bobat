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

class primitiv
{
public:
	virtual bool getCollision(ray3df ray, f32 &u, vector3df &point) = 0;
};

class polygon : public primitiv
{
	vector3df points[3];
	vector3df normal;
public:
	polygon(vector3df a, vector3df b, vector3df c) {normal = (b-a).crossProd(c-a); points[0] = a; points[1] = b; points[2] = c;}

	bool getCollision(ray3df ray, f32 &u, vector3df &point);
};

#endif /* PRIMITIV_HPP_ */
