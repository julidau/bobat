#ifndef _BOBAT_VECTOR3D_
#define _BOBAT_VECTOR3D_

#include "corefunctions.hpp"

//defines mathematical standart 3D Vector
template <class T>
class vector3d
{
public:
	T comp[3];

	vector3d(T x,T y,T z) { comp[0] = x; comp[1] = y; comp[2] = z; }
	vector3d() { for (u32 i = 0; i < 3; i++) comp[i] = 0; }
	// copy
	vector3d(const vector3d<T> &other) { for (u8 i = 0; i < 3; i++) comp[i] = other.comp[i]; }

	T getX() { return comp[0]; }
	T getY() { return comp[1]; }
	T getZ() { return comp[2]; }



	vector3d<T> &operator&()
	{
		return this;
	}
	vector3d<T> operator+ (const vector3d<T> &other) const
	{
		return vector3d<T>(comp[0]+other.comp[0],
			comp[1]+other.comp[1],
			comp[2]+other.comp[2]);
	}

	vector3d<T> operator- (const vector3d<T> &other) const
	{
		return vector3d<T>(comp[0]-other.comp[0],
			comp[1]-other.comp[1],
			comp[2]-other.comp[2]);
	}
	vector3d<T> &operator+= (const vector3d<T> &other) const
	{
		comp[0]+=other.comp[0];
		comp[1]+=other.comp[1];
		comp[2]+=other.comp[2];
		return *this;
	}
	vector3d<T> &operator-= (const vector3d<T> &other) const
	{
		comp[0]-=other.comp[0];
		comp[1]-=other.comp[1];
		comp[2]-=other.comp[2];
		return *this;
	}
	template<class U>
	vector3d<T> operator* (const U &scalar) const
	{
		return vector3d<T>(comp[0]*scalar,
			comp[1]*scalar,
			comp[2]*scalar);
	}

	template<class U>
	vector3d<T> &operator*= (const U &scalar) const
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
