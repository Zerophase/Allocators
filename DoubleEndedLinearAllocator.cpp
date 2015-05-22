//
// Created by zerophase on 5/21/15.
//

#include "DoubleEndedLinearAllocator.h"
#include <assert.h>
#include <sys/types.h>
#include "PointerMath.h"

DoubleEndedLinearAllocator::DoubleEndedLinearAllocator(u32 sizeBytes, void *start)
	:Allocator(sizeBytes, start), currentPositionBottom(start)
{
	assert(size > 0);
	marker = size / 2;
	currentPositionTop = PointerMath::Add(currentPositionBottom, size);
	midAddress = PointerMath::Add(currentPositionBottom, marker);
	SwitchToBottom();
}

DoubleEndedLinearAllocator::~DoubleEndedLinearAllocator()
{
	positionAssignedTo = nullptr;
	currentPositionTop = nullptr;
	currentPositionBottom = nullptr;
	midAddress = nullptr;
	allocateAt = nullptr;
//	uptr alignedAddress = (uptr) positionAssignedTo + 0;
//	(this->*allocateAt)(alignedAddress, 32);
}

void *DoubleEndedLinearAllocator::Allocate(u32 size, u8 alignment)
{

	assert(size != 0);

	u8 adjustment = PointerMath::AlignForwardAdjustment(positionAssignedTo, alignment);

	if((usedMemory + adjustment + size) > this->size)
		return nullptr;
	assert(currentPositionBottom < midAddress);

	uptr alignedAddress = (uptr) positionAssignedTo + adjustment;
	(this->*allocateAt)(alignedAddress, size);
	//allocateBottom(alignedAddress, size);
	usedMemory += size + adjustment;
	numAllocations++;

	return (void*)alignedAddress;
}

void DoubleEndedLinearAllocator::Deallocate(void *p)
{
	assert(false && "Use Clear() instead");
}


void DoubleEndedLinearAllocator::Clear()
{
	numAllocations = 0;
	usedMemory = 0;

	currentPositionTop = start;
	currentPositionBottom = start;
}

void DoubleEndedLinearAllocator::allocateTop(uptr alignedAddress, u32 size)
{
	currentPositionTop = (void*) (alignedAddress - size);
}

void DoubleEndedLinearAllocator::allocateBottom(uptr alignedAddress, u32 size)
{
	currentPositionBottom = (void*) (alignedAddress + size);
}

void DoubleEndedLinearAllocator::SwitchToTop()
{
	positionAssignedTo = currentPositionTop;
	DoubleEndedLinearAllocator::allocateAt = &DoubleEndedLinearAllocator::allocateTop;
}

void DoubleEndedLinearAllocator::SwitchToBottom()
{
	positionAssignedTo = currentPositionBottom;
	DoubleEndedLinearAllocator::allocateAt = &DoubleEndedLinearAllocator::allocateBottom;
}
