/*
 * polygon.cpp
 *
 *  Created on: 19.09.2012
 *      Author: julian
 */

#include "../include/primitiv.hpp"

bool polygon::getCollision(ray3df ray, f32 &u, vector3df &point)
{
	if (s1.lenghtSQ() == 0 || s1.lenghtSQ() == 0) return false;

	const f32 oben = (a-ray.getStart()).scalProd(normal);
	const f32 unten = ray.getDirection().scalProd(normal);

	if (oben == unten || unten == 0) return false;
	u = oben/unten;

	point = ray.getPoint(u);
	// calculate x,y on Plane
	/*const f32 x = (point-a).scalProd(s1) /s1.lenght();
	const f32 y = (point-a).scalProd(s2) /s2.lenght();*/

	const f32 x = (point-a).scalProd(s1) / s1.lenghtSQ() *s1.lenght();
	const f32 y = (point-a).scalProd(s2) / s2.lenghtSQ() *s2.lenght();

	if (x >= 0 && x <= 1 && y >= 0 && y <= 1 && x+y >= 0 && x+y <= 1) return true;

	return false;
}
