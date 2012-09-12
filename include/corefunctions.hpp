#ifndef _BOBAT_COREFUNC_
#define _BOBAT_COREFUNC_

#include "types.h"

namespace core
{
	//function to get the squareroot of value (recursivly implemented)
template <class T>
T sqroot(T value, T xn = 0)
{
	if (xn == 0)
		xn = value;
		
	if (xn*xn-value <= 0)
		return value;
	else
		return sqroot(value,0.5f*(xn+value/xn));
}

}; // namespace core

#endif // Header
