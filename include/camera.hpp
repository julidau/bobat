/*
 * camera.hpp
 *
 *  Created on: 20.09.2012
 *      Author: julian
 */

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "plane.hpp"
#include "vector3d.hpp"
#include "color.hpp"
#include "scene.h"

class camera
{
public:
	plane3df Objektiv;
	vector3df Point;
	vector3df Rot;

	camera(vector3df p, vector3df rot) : Point(p), Rot(rot) {}
	coloru8 render(const scene &CurScene);

};


#endif /* CAMERA_HPP_ */
