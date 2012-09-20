/*
 * plane.hpp
 *
 *  Created on: 20.09.2012
 *      Author: julian
 */

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "vector3d.hpp"

template <class T>
class plane3d
{
public:
	vector3d<T> U, s1, s2;
	plane3d(vector3d<T> U, vector3d<T> s1, vector3d<T> s2) : U(U), s1(s1), s2(s2) {}
	plane3d(void){ U = vector3d<T>(); s1 = vector3d<T>(); s2 = vector3d<T>(); }

	vector3df getPoint(T x, T y)
	{
		return U+s1*x+s2*y;
	}

	void normalize()
	{
		s1.normalize();
		s2.normalize();
	}
};

typedef plane3d<f32> plane3df;

#endif /* PLANE_HPP_ */
