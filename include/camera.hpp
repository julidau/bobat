/*
 * camera.hpp
 *
 *  Created on: 20.09.2012
 *      Author: julian
 */

#ifndef BOBAT_CAMERA_
#define BOBAT_CAMERA_

#include "plane.hpp"
#include "vector3d.hpp"
#include "color.hpp"
#include "scene.h"
#include "array.hpp"

class camera
{
public:
	plane3df Objektiv;
	vector3df Point;
	vector3df Rot;

	camera(vector3df p, vector3df rot) : Point(p), Rot(rot) {}
	core::array<coloru8> render(const scene &CurScene);

};


#endif /* CAMERA_HPP_ */
