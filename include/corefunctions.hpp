#ifndef _BOBAT_COREFUNC_
#define _BOBAT_COREFUNC_

#include "types.h"

namespace core
{
	//function to get the squareroot of value (recursivly implemented)
template <class T>
T sqrt(T value, T xn = 0)
{
	if (xn == 0)
		xn = value;
		
	if (xn*xn-value <= 0)
		return xn;
	else
		return sqrt(value,(T)(0.5f*(xn+value/xn)));
}

template<class T>
void memset(T* ptr,u64 num, const T &value)
{
	for (u64 i = 0; i < num; i++)
	{
		*ptr = value;
		ptr++;
	}
}

template<class T>
void memcopy(T*dest, T*from, u64 howMany, u64 offset = 0)
{
	for (u64 i = howMany-1; i>offset; i--)
		dest[i] = from[i];

	dest[offset] = from[offset];
}

}; // namespace core

#endif // Header
