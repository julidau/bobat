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

class polygon : primitiv
{
	vector3df a,s1,s2;
	vector3df normal;
public:
	polygon(vector3df a, vector3df b, vector3df c) : a(a) , s1(b-a), s2(c-a) {normal = s1.crossProd(s2); }

	bool getCollision(ray3df ray, f32 &u, vector3df &point);

};

#endif /* PRIMITIV_HPP_ */
