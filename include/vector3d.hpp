#ifndef _BOBAT_VECTOR3D_
#define _BOBAT_VECTOR3D_

#include <string.h>
#include "corefunctions.hpp"

//defines mathematical standart 3D Vector
template <class T>
class vector3d
{
	T comp[3];
public:
	vector3d(T x,T y,T z) { comp[0] = x; comp[1] = y; comp[2] = z; }
	vector3d() { memset((void*)&comp,T(),sizeof(T)*3); }
	//vector3d(vector3d<T> &other) { memcpy((void*)&comp,(void*)other.getComp(),sizeof(T)*3); }

	T getX() { return comp[0]; }
	T getY() { return comp[1]; }
	T getZ() { return comp[2]; }
	
	T* getComp() { return comp; }

	vector3d<T> &operator&()
	{
		return this;
	}
	vector3d<T> operator+ (vector3d<T> &other)
	{
		return vector3d<T>(comp[0]+other.getX(),
			comp[1]+other.getY(),
			comp[2]+other.getZ());
	}

	vector3d<T> operator- (vector3d<T> &other)
	{
		return vector3d<T>(comp[0]-other.getComp()[0],
			comp[1]-other.getComp()[1],
			comp[2]-other.getComp()[2]);
	}
	vector3d<T> &operator+= (vector3d<T> &other)
	{
		comp[0]+=other.getComp()[0];
		comp[1]+=other.getComp()[1];
		comp[2]+=other.getComp()[2];
		return *this;
	}
	vector3d<T> &operator-= (vector3d<T> &other)
	{
		comp[0]-=other.getComp()[0];
		comp[1]-=other.getComp()[1];
		comp[2]-=other.getComp()[2];
		return *this;
	}
	template<class U>
	vector3d<T> operator* (U scalar)
	{
		return vector3d<T>(comp[0]*scalar,
			comp[1]*scalar,
			comp[2]*scalar);
	}
	template<class U>
	vector3d<T> &operator*= (U scalar)
	{
		comp[0]*=scalar;
		comp[1]*=scalar;
		comp[2]*=scalar;
		return *this;
	}
};

template <class U,class T>
vector3d<T> operator*(U scalar, vector3d<T> &other) { return other*scalar; }

#endif // Header
