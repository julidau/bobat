#ifndef _BOBAT_COLOR_
#define _BOBAT_COLOR_

// Stores color information in rgb and alpha 
template <class T>
class color
{
	T rgba[4];
public:
	color(T R,T G,T B,T A) { rgba[0] = R; rgba[1] = G; rgba[2] = B; rgba[3] = A; }
	color() { memset((void*)&rgba,T(),sizeof(T)*4); }
};
typedef color<u8> coloru8;
#endif
