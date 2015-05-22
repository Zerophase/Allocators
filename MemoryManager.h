//
// Created by zerophase on 5/21/15.
//

#ifndef ALLOCATORS_MEMORYMANAGER_H
#define ALLOCATORS_MEMORYMANAGER_H

#include "Singleton.h"
#include "Types.h"
#include "DoubleEndedLinearAllocator.h"


#define MEM_SIZE 16384  //1048576000

class MemoryManager : private Singleton<MemoryManager>
{
private:
	static MemoryManager *memoryManager;

	void *memoryLinearAllocator;

	DoubleEndedLinearAllocator *linearAllocator;

public:
	MemoryManager();
	~MemoryManager();

	void StartUp() override;
	void ShutDown() override;

	MemoryManager *Get() override;

	DoubleEndedLinearAllocator &GetDoubleEndedLinearAllocator();
	void CreateDoubleEndedLinearAllocator();
	void DestroyDoubleEndedLinearAllocator();
	void *AllocateDoubleEndedLinearAllocator(u32 sizeBytes, u8 alignment);
	void ClearDoubleEndedLinearAllocator();
};


#endif //ALLOCATORS_MEMORYMANAGER_H
