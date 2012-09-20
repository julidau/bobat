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

struct scene
{
public:
	core::array<primitiv*> Plist;
	renderProp props;

	scene(renderProp p, primitiv * primitivlist[], u32 lenght): props(p) {Plist.allocate(lenght); for (u32 i = 0; i < lenght; i++) Plist.push_back(primitivlist[i]); }
	scene(renderProp p, core::array<primitiv*> list): props(p) { Plist = list; }
	scene(renderProp p): props(p) { Plist.clear(); }
	scene() {Plist.clear();}

};


#endif /* SCENE_H_ */
