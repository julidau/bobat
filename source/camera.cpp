/*
 * camera.cpp
 *
 *  Created on: 20.09.2012
 *      Author: julian
 */

#include "../include/camera.hpp"
#include <iostream>

camera::camera(vector3df center, vector3df lookat, vector3df up)
{
	_DEBUG_BREAK_IF(lookat==up)

	Center = center;
	Objektiv = plane3df(lookat, up, up.crossProd(lookat));
	Objektiv.normalize();
}

core::array<coloru8> camera::render (const scene &curScene)
{
	std::cout << Objektiv.getPoint(0,0).toString() << std::endl;
	/*Objektiv.U = P
	Objektiv.s1 = vector3df(0,1,0);
	Objektiv.s2 = vector3df(0,0,-1);*/

	core::array<coloru8> image(curScene.props.width*curScene.props.height);


	const f32 sx = 1.f/(f32)curScene.props.width;
	const f32 sy = 1.f/(f32)curScene.props.height;

	for (u32 x = 0; x < curScene.props.width; x++ )
	{
		for (u32 y = 0; y < curScene.props.height; y++ )
		{
			ray3df ray(Center,Objektiv.getPoint(x*sx-0.5f,y*sy-0.5f));

			for (u32 i = 0; i < curScene.Plist.getSize(); i++)
			{
				if (curScene.Plist.at(i)->getCollision(ray).getX() > 0)
				{
					image.push_back(color<u8>(255,0,0,0));
					std::cout << "col" << std::endl;
				}
				else
				{
					image.push_back(coloru8(0,0,0,0));
					//std::cout << "no coll:" << Ix << ";" << Iy<<  std::endl;
				}
			}
		}
	}
	return image;
}


