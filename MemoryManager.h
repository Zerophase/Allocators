//
// Created by zerophase on 5/21/15.
//

#ifndef ALLOCATORS_MEMORYMANAGER_H
#define ALLOCATORS_MEMORYMANAGER_H

#include "Singleton.h"
#include "Types.h"
#include "DoubleEndedLinearAllocator.h"


#define MEM_SIZE 262144

class MemoryManager : private Singleton<MemoryManager>
{
private:
	static MemoryManager *memoryManager;

	void *memoryLinearAllocator;

	DoubleEndedLinearAllocator *doubleEndedLinearAllocator;
	Allocator *usedAllocator;



public:
	template<class T> T *New()
	{
		return  new(usedAllocator->Allocate(sizeof(T), alignof(T)))T;
	}

	MemoryManager();
	~MemoryManager();


	void SetAllocatorUsedToDoubleLinearAllocator();
	void StartUp() override;
	void ShutDown() override;

	MemoryManager *Get() override;


	DoubleEndedLinearAllocator &GetDoubleEndedLinearAllocator();
	void CreateDoubleEndedLinearAllocator();
	void DestroyDoubleEndedLinearAllocator();
	void *AllocateDoubleEndedLinearAllocator(u32 sizeBytes, u8 alignment);
	void ClearDoubleEndedLinearAllocator();
	void SwitchToBottom();
	void SwitchToTop();
};


#endif //ALLOCATORS_MEMORYMANAGER_H
