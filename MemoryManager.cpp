//
// Created by zerophase on 5/21/15.
//

#include "MemoryManager.h"
#include "DoubleEndedLinearAllocator.h"
#include <cstdlib>

MemoryManager *MemoryManager::memoryManager = nullptr;

MemoryManager::MemoryManager()
{

}

MemoryManager::~MemoryManager()
{

}

void MemoryManager::StartUp()
{
	memoryManager = new MemoryManager();

	memoryManager->memoryLinearAllocator = malloc(MEM_SIZE);
	memoryManager->CreateDoubleEndedLinearAllocator();
}

void MemoryManager::ShutDown()
{
	memoryManager->DestroyDoubleEndedLinearAllocator();

	delete memoryManager;
}

MemoryManager *MemoryManager::Get()
{
	return memoryManager;
}

DoubleEndedLinearAllocator &MemoryManager::GetDoubleEndedLinearAllocator()
{
	return *linearAllocator;
}

void MemoryManager::CreateDoubleEndedLinearAllocator()
{
	linearAllocator = new DoubleEndedLinearAllocator(MEM_SIZE, memoryLinearAllocator);
}

void MemoryManager::DestroyDoubleEndedLinearAllocator()
{
	delete linearAllocator;
}

void *MemoryManager::AllocateDoubleEndedLinearAllocator(u32 sizeBytes, u8 alignment)
{
	return linearAllocator->Allocate(sizeBytes, alignment);
}

void MemoryManager::ClearDoubleEndedLinearAllocator()
{
	linearAllocator->Clear();
}