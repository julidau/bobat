#ifndef _BOBAT_VECTOR3D_
#define _BOBAT_VECTOR3D_

#include "corefunctions.hpp"
#include <sstream>

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


	// operators
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

	bool operator== (const vector3d<T> &other)
	{
		return (comp[0] == other.comp[0] && comp[1] == other.comp[1] && comp[2] == other.comp[2]);
	}

	bool operator!= (const vector3d<T> &other)
	{
		return !(*this==other);
	}

	// Vector Products
	T scalProd(const vector3d<T> &other) const
	{
		return comp[0]*other.comp[0]+comp[1]*other.comp[1]+comp[2]*other.comp[2];
	}

	vector3d<T> crossProd (const vector3d<T> &other) const
	{
		return vector3d<T>(comp[1]*other.comp[2]-comp[2]*other.comp[1],
				comp[2]*other.comp[0]-comp[0]*other.comp[2],
				comp[0]*other.comp[1]-comp[1]*other.comp[0]);
	}

	// get ABS
	T lenghtSQ()
	{
		return comp[0]*comp[0]+comp[1]*comp[1]+comp[2]*comp[2];
	}
	T lenght()
	{
		return core::sqrt<T>(lenghtSQ());
	}

	void normalize()
	{
		if (lenghtSQ() != 0)
		{
			const f32 l = lenght();
			for (u8 i = 0; i < 3; i++) comp[i] /= l;
		}
	}

	char * toString ()
	{
		std::stringstream buffer;
		for (u8 i = 0; i < 3; i++)
		{
			buffer << comp[i] << "; ";
		}
		char * bu = new char[20];

		buffer.get(bu,20);
		return bu;
	}
};

template <class U,class T>
vector3d<T> operator*(U scalar, vector3d<T> &other) { return other*scalar; }

typedef vector3d<f32> vector3df;

#endif // Header
