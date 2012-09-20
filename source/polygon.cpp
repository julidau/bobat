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


	for (u32 side = 1; side < 3; side++)
	{
		const f32 t = (points[side]-points[side-1]).crossProd(point-points[side-1]).scalProd(normal);
		if (t < 0)
			return false;
	}

	return true;
}
