//
// Created by zerophase on 5/21/15.
//

#ifndef ALLOCATORS_LINEARALLOCATOR_H
#define ALLOCATORS_LINEARALLOCATOR_H

#include "Types.h"
#include "Allocator.h"

typedef u32 Marker;

class DoubleEndedLinearAllocator : public Allocator
{
public:
	DoubleEndedLinearAllocator(u32 sizeBytes, void *start);
	~DoubleEndedLinearAllocator();

	void *Allocate(u32 size, u8 alignment) override;
	void Deallocate(void *p) override;

	void Clear();

	void SwitchToTop();
	void SwitchToBottom();

private:
	DoubleEndedLinearAllocator(DoubleEndedLinearAllocator const&) = delete;
	DoubleEndedLinearAllocator &operator=(DoubleEndedLinearAllocator const&) = delete;

	void *currentPositionTop;
	void *currentPositionBottom;
	void *positionAssignedTo;
	void *midAddress;

	bool isTop;

	void (DoubleEndedLinearAllocator::*allocateAt)(uptr alignedAddress, u32 size);
	void allocateTop(uptr alignedAddress, u32 size);
	void allocateBottom(uptr alignedAddress, u32 size);

	Marker marker;
};


#endif //ALLOCATORS_LINEARALLOCATOR_H
