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

	inline void *AlignForward(void *address, u8 alignment)
	{
		return (void *) ((reinterpret_cast<uptr>(address) + static_cast<uptr>(alignment - 1))
		& static_cast<uptr>(~(alignment - 1)));
	}

	inline u8 AlignForwardAdjustment(const void *address, u8 alignment)
	{
		u8 adjustment = alignment - (reinterpret_cast<uptr>(address) & static_cast<uptr>(alignment - 1));
		if(adjustment == alignment)
			return 0;
		return adjustment;
	}
}

#endif //ALLOCATORS_POINTERMATH_H
