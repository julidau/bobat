/*
 * polygon.cpp
 *
 *  Created on: 19.09.2012
 *      Author: julian
 */

#include "../include/primitiv.hpp"

bool polygon::getCollision(ray3df ray, f32 &u, vector3df &point)
{
	for (u32 p = 0; p < 3; p++) if(points[p].lenghtSQ() == 0) return false;

	const f32 oben = (points[0]-ray.getStart()).scalProd(normal);
	const f32 unten = ray.getDirection().scalProd(normal);

	if (oben == unten || unten == 0) return false;
	u = oben/unten;

	if (u < 0)
		return false;

	point = ray.getPoint(u);

	// calculate x,y on Plane
	/*const f32 c1 = point.comp[0]-a.comp[0];
	const f32 c2 = point.comp[1]-a.comp[1];
	const f32 D = s1.comp[0]*s2.comp[1]-s2.comp[0]*s1.comp[1];

	if (D == 0)
		return false;

	const f32 x = (c1*s2.comp[1]-c2*s1.comp[0])/(D);
	const f32 y = (c2*s1.comp[0]-c1*s1.comp[1])/(D);*/

	bool neg;
	for (u32 side = 1; side < 3; side++)
	{
		const f32 t = (points[side]-points[side-1]).scalProd(point-points[side-1]);
		if (t < 0 && !neg)
			neg = true;
		else
			if (neg) return false;
	}

	return true;
}
