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
	currentPositionTop = PointerMath::Add(currentPositionBottom, size - 1);
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

	u8 adjustment;
	if( isTop )
		adjustment = PointerMath::AlignBackwardAdjustment(positionAssignedTo, alignment);
	else
		adjustment = PointerMath::AlignForwardAdjustment( positionAssignedTo, alignment );

	if((usedMemory + adjustment + size) > this->size)
		return nullptr;
	assert(currentPositionBottom < midAddress);

	uptr alignedAddress;
	if( isTop )
		alignedAddress = (uptr)positionAssignedTo - adjustment - size;
	else
		alignedAddress = (uptr)positionAssignedTo + adjustment;

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

void DoubleEndedLinearAllocator::allocateTop(uptr alignedAddress, u32 usedBytes)
{
	currentPositionTop = (void *)alignedAddress;
}

void DoubleEndedLinearAllocator::allocateBottom( uptr alignedAddress, u32 usedBytes )
{
	currentPositionBottom = (void*)(alignedAddress + usedBytes);
}

void DoubleEndedLinearAllocator::SwitchToTop()
{
	isTop = true;
	positionAssignedTo = currentPositionTop;
	DoubleEndedLinearAllocator::allocateAt = &DoubleEndedLinearAllocator::allocateTop;
}

void DoubleEndedLinearAllocator::SwitchToBottom()
{
	isTop = false;
	positionAssignedTo = currentPositionBottom;
	DoubleEndedLinearAllocator::allocateAt = &DoubleEndedLinearAllocator::allocateBottom;
}
