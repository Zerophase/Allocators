//
// Created by zerophase on 5/21/15.
//

#ifndef ALLOCATORS_ALLOCATIONSCHEMAS_H
#define ALLOCATORS_ALLOCATIONSCHEMAS_H

#include <type_traits>
#include "Allocator.h"
#include <cstddef>

template<class T> T *New(Allocator &allocator)
{
	return  new(allocator.Allocate(sizeof(T), alignof(T)))T;
}

#endif //ALLOCATORS_ALLOCATIONSCHEMAS_H
