#ifndef _BOBAT_SQUAREROOT_
#define _BOBAT_SQUAREROOT_

#include "types.h"

namespace bobcat
{
	namespace core
	{
		template <class T>
		T sqroot(T start, T right = 0, T grenz = 0.f)
		{
			if (right == 0)
				right = start;
				
			if (right*right-start < grenz)
				return right;
			else
				return sqroot(start,0.5f*(right+start/right));
		}
	};
};

#endif // Header
