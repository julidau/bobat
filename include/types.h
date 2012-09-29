#ifndef _BOBAT_TYPES_
#define _BOBAT_TYPES_

// redefine standart types for simpler use
typedef char 			i8;
typedef short			i16;
typedef int				i32;
typedef long			i64;

typedef unsigned char 	u8;
typedef unsigned short 	u16;
typedef unsigned int 	u32;
typedef unsigned long 	u64;

typedef float			f32;
typedef double			f64;
typedef long double		f128;

template <class T>
struct returnStruct
{
	bool isReturn;
	T returnValue;
};

struct renderProp
{
	u32 width, height;
	renderProp(u32 w, u32 h): width(w),height(h) {}
	renderProp():width(0), height(0) {}
};

//define Debug break
#ifdef _DEBUG
#include "assert.h"
#define _DEBUG_BREAK_IF( _CONDITION_ ) assert( !(_CONDITION_) );
#else
#define _DEBUG_BREAK_IF( _CONDITION_ )
#endif

#endif
