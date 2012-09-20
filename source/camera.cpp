/*
 * camera.cpp
 *
 *  Created on: 20.09.2012
 *      Author: julian
 */

#include "../include/camera.hpp"
#include <iostream>

core::array<coloru8> camera::render (const scene &curScene)
{
	Objektiv.U = Point + Rot;
	Objektiv.s1 = vector3df(1,0,0);
	Objektiv.s2 = vector3df(0,0,-1);

	core::array<coloru8> image(curScene.props.width*curScene.props.height);

	f32 Ix = 0, Iy = 0;
	const f32 sx = 1.f/(f32)curScene.props.width;
	const f32 sy = 1.f/(f32)curScene.props.height;

	for (u32 x = 0; x < curScene.props.width; x++ )
	{
		Iy = 0;
		for (u32 y = 0; y < curScene.props.height; y++ )
		{
			//core::array<f32> Us;
			ray3df ray(Point,Objektiv.getPoint(x*sx,y*sy));

			for (u32 O = 0; O < curScene.Plist.getSize(); O++)
			{
				f32 u; vector3df p;
				if (curScene.Plist.at(O)->getCollision(ray,u,p))
				{
					image.push_back(coloru8(255,0,0,0));

				}
				else
				{
					image.push_back(coloru8(0,0,0,0));
					std::cout << "no coll:" << Ix << ";" << Iy<<  std::endl;
				}
			}
			Iy++;
		}
		Ix++;
	}
	return image;
}


