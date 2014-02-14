/*
 * camera.cpp
 *
 *  Created on: 20.09.2012
 *      Author: julian
 */

#include "../include/camera.hpp"
#include <iostream>
#include <SDL2/SDL.h>

camera::camera(vector3df center, vector3df lookat, vector3df up)
{
	_DEBUG_BREAK_IF(lookat==up)

	Center = center;
	Objektiv = plane3df(lookat, up, up.crossProd(lookat));
	Objektiv.normalize();
}

color<u8> convertColor(const color<f32> &input)
{
	return color<u8>(0xFF * input.rgba[0],
			0xFF * input.rgba[1],
			0xFF * input.rgba[2],
			0xFF * input.rgba[3]);
}

u8 * camera::render (scene &curScene, u64 * timeNeeded = NULL)
{
	u64 startTime = SDL_GetTicks();

	/*Objektiv.U = P
	Objektiv.s1 = vector3df(0,1,0);
	Objektiv.s2 = vector3df(0,0,-1);*/

	u8 * image = new u8[curScene.props.width*curScene.props.height*4];
	u8 * iterator = image;

	const f32 sx = 1.f/(f32)curScene.props.width;
	const f32 sy = 1.f/(f32)curScene.props.height;

	for (u32 y = 0; y < curScene.props.height; y++ )
	{
		for (u32 x = 0; x < curScene.props.width; x++ )
		{
			ray3df ray(Center,Objektiv.getPoint(x*sx-0.5f,y*sy-0.5f));
			curScene.getCollision(&ray);
			color<u8> c = convertColor(ray.getColor());
			*iterator = c.getR(); iterator++;
			*iterator = c.getG(); iterator++;
			*iterator = c.getB(); iterator++;

			*iterator = c.getA(); iterator++;
		}
	}
	u64 endTime = SDL_GetTicks();

	if (timeNeeded)
		*timeNeeded = endTime-startTime;

	return image;
}


