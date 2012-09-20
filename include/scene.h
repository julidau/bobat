/*
 * scene.h
 *
 *  Created on: 20.09.2012
 *      Author: julian
 */

#ifndef SCENE_H_
#define SCENE_H_

#include "primitiv.hpp"
#include <vector>

struct scene
{
public:
	std::vector<primitiv*> Plist;
	renderProp props;

	scene(renderProp p, primitiv * primitivlist[], u32 lenght): props(p) { for (u32 i = 0; i < lenght; i++) Plist.push_back(primitivlist[i]); }
	scene(renderProp p, std::vector<primitiv*> list): props(p) { Plist = list; }
	scene(renderProp p): props(p) { Plist.clear(); }
	scene() {Plist.clear();}

};


#endif /* SCENE_H_ */
