#ifndef _BOBAT_COLOR_
#define _BOBAT_COLOR_

// Stores color information in rgb and alpha 
template <class T>
class color
{
public:
	T rgba[4];

	color(T R,T G,T B,T A) { rgba[0] = R; rgba[1] = G; rgba[2] = B; rgba[3] = A; }
	color() { core::memset<T>(&rgba[0],4,T()); }
	color(const color<T> &other) { if (this != &other) for (u8 i = 0; i < 4; i++) rgba[i] = other.rgba[i]; }

	void setR(T v)
	{
		rgba[0] = v;
	}
	void setG(T v)
	{
		rgba[1] = v;
	}
	void setB(T v)
	{
		rgba[2] = v;
	}
	void setA(T v)
	{
		rgba[3] = v;
	}

	T &getR()
	{
		return rgba[0];
	}
	T &getG()
	{
		return rgba[1];
	}
	T &getB()
	{
		return rgba[2];
	}
	T &getA()
	{
		return rgba[3];
	}

	void setRGB(T r, T g, T b)
	{
		rgba[0] = r;
		rgba[1] = g;
		rgba[2] = b;
		rgba[3] = 0;
	}

	void setRGBA(T r, T g, T b, T a)
	{
		setRGB(r,g,b);
		rgba[3] = a;
	}
};

typedef color<u8> coloru8;

#endif
