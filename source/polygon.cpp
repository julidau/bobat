/*
 * polygon.cpp
 *
 *  Created on: 19.09.2012
 *      Author: julian
 */

#include "../include/primitiv.hpp"
#include <iostream>

vector3df polygon::getCollision(ray3df ray) const
{
	vector3df side1 = points[1] - points[0], side2 = points[2]-points[0];
	const vector3df R0 = ray.getStart() - points[0];

	const vector3df P = ray.getDirection().crossProd(side2);
	const vector3df Q = R0.crossProd(side1);

	const f32 De = P.scalProd(side1);

	/* check if ray collides with polygon */
	if (De == 0)
		return vector3df(0,0,0);

	// calc u,v on the plane
	const f32 u = P.scalProd(R0)/De;
	const f32 v = Q.scalProd(ray.getDirection())/De;

	/* check if point is on the triangle of the polygon */
	if (u < 0 || u > 1) return vector3df(0,0,0);
	if (v < 0 || v > 1) return vector3df(0,0,0);

	if (u+v < 0 || u+v > 1) return vector3df(0,0,0);


	// calcs where ray collides
	const f32 t = R0.crossProd(side1).scalProd(side2)/De;

	return vector3df(t,u,v);
}
