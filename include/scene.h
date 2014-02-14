/*
 * scene.h
 *
 *  Created on: 20.09.2012
 *      Author: julian
 */

#ifndef BOBAT_SCENE_
#define BOBAT_SCENE_

#include "primitiv.hpp"
#include "array.hpp"
#include <iostream>
#include <cmath>
#include <fstream>

class scene
{
protected:
	std::string readline(std::ifstream file)
	{
		char Buffer;
		std::string strBuffer;
		while(file.good())
		{
			file.read(&Buffer, 1);
			if (Buffer == '\n')
				break;

			strBuffer += Buffer;
		}

		return strBuffer;
	}

	u64 readInt(const std::string &str)
	{
		u64 buffer;

		bool neg = str[0] == '-';
		if (neg)
			str.erase(str.begin());



		return buffer;
	}
public:
	core::array<primitiv*> Plist;
	renderProp props;
	color<f32> backgroundColor;

	scene(renderProp p, primitiv * primitivlist[], u32 lenght): props(p) {Plist.allocate(lenght); for (u32 i = 0; i < lenght; i++) Plist.push_back(primitivlist[i]); }
	scene(renderProp p, core::array<primitiv*> list): props(p) { Plist = list; }
	scene(renderProp p): props(p) { Plist.clear(); }
	scene() {Plist.clear();}

	void getCollision(ray3df * ray)
	{
		if (!ray)
			return;

		ray->setColor(backgroundColor);

		f32 t = INFINITY;
		ray3df successor(*ray);
		ray3df copy(*ray);

		for (u32 i = 0; i < Plist.getSize(); i++)
		{
			f32 u = Plist[i]->getCollision(&copy);

			if (u != 0 && u < t)
			{
				u = t;
				successor = copy;
			}
		}

		*ray = successor;
	}

	void loadFromFile(std::ifstream * f)
	{
		std::string Header = readline(*f);

		if (Header != "ply")
			return;

		std::string buffer = "";
		u64 numElements = 0;

		while(f->good())
		{
			buffer = readline(*f);
			u64 position = 0;

			if ((position = buffer.find("element vertex")) != std::string::npos)
			{
				// found the number of elements
				numElements =
			}
		}

		return;
	}
};


#endif /* SCENE_H_ */
