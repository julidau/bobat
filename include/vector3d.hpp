#ifndef _BOBCAT_VECTOR3D_
#define _BOBCAT_VECTOR3D_

#include <string>
#include "corefunctions.hpp"

template <class T>
class vector3d
{
	T comp[3];
public:
	vector3d(T x,T y,T z) { comp[0] = x; comp[1] = y; comp[2] = z; }
	vector3d() { memset((void*)&comp,T(),sizeof(T)*3); }

	T getX() { return comp[0]; }
	T getY() { return comp[1]; }
	T getZ() { return comp[2]; }
	
	T* getComp() { return comp; }
	vector3d<T> operator+ (vector3d<T> &other)
	{
		return vector3d<T>(comp[0]+other.
	}
	vector3d<T> operator- (vector3d<T> &other)
	vector3d<T> &operator+= (vector3d<T> &other)
	vector3d<T> &operator-= (vector3d<T> &other)
	
	T operator* (vector3d<T> &other)
	vector3d<T> &operator*= (T &scalar)
};

#endif // Header
