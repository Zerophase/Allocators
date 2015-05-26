//
// Created by zerophase on 5/21/15.
//

#ifndef ALLOCATORS_POINTERMATH_H
#define ALLOCATORS_POINTERMATH_H

#include <stddef.h>
#include "Types.h"

namespace PointerMath
{
	inline void  *Add(void *p, size_t x)
	{
		return (void *) (reinterpret_cast<uptr>(p) + x);
	}

	inline u8 AlignForwardAdjustment(const void *address, u8 alignment)
	{
		if( alignment <= 1 )
			return 0;

		u8 adjustment = 0;
		std::uintptr_t ptr = (std::uintptr_t)address;
		return alignment - (ptr % alignment);
	}

	inline void *AlignForward( void *address, u8 alignment )
	{
		return (u8 *)address + AlignForwardAdjustment( address, alignment );
	}

	inline u8 AlignBackwardAdjustment( const void * address, u8 alignment )
	{
		if( alignment <= 1 )
			return 0;

		std::uintptr_t ptr = (std::uintptr_t)address;
		return ptr % alignment;
	}
}

#endif //ALLOCATORS_POINTERMATH_H
