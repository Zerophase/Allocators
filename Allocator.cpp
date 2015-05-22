//
// Created by zerophase on 5/21/15.
//

#include "Allocator.h"
#include <assert.h>

Allocator::Allocator(u32 sizeBytes, void *start)
{
	this->start = start;
	this->size = sizeBytes;

	usedMemory = 0;
	numAllocations = 0;
}

Allocator::~Allocator()
{
	assert(numAllocations == 0 && usedMemory == 0);

	start = nullptr;
	size = 0;
}

void *Allocator::GetStart() const
{
	return start;
}

u32 Allocator::GetSize() const
{
	return size;
}

u32 Allocator::GetUsedMemory() const
{
	return usedMemory;
}

u32 Allocator::GetNumAllocations() const
{
	return numAllocations;
}
