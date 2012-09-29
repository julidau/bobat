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
	vector3df Center, Up, Lookat;

	camera(vector3df center, vector3df lookat, vector3df up = vector3df(0,1,0));
	core::array<coloru8> render(const scene &CurScene);
	coloru8 render(const scene &CurScene, u32 x, u32 y);

};


#endif /* CAMERA_HPP_ */
