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

void MemoryManager::SetAllocatorUsedToDoubleLinearAllocator()
{
	usedAllocator = doubleEndedLinearAllocator;
}

MemoryManager *MemoryManager::Get()
{
	return memoryManager;
}

DoubleEndedLinearAllocator &MemoryManager::GetDoubleEndedLinearAllocator()
{
	return *doubleEndedLinearAllocator;
}

void MemoryManager::CreateDoubleEndedLinearAllocator()
{
	doubleEndedLinearAllocator = new DoubleEndedLinearAllocator(MEM_SIZE, memoryLinearAllocator);
}

void MemoryManager::DestroyDoubleEndedLinearAllocator()
{
	delete doubleEndedLinearAllocator;
}

void *MemoryManager::AllocateDoubleEndedLinearAllocator(u32 sizeBytes, u8 alignment)
{
	return doubleEndedLinearAllocator->Allocate(sizeBytes, alignment);
}

void MemoryManager::ClearDoubleEndedLinearAllocator()
{
	doubleEndedLinearAllocator->Clear();
}

void MemoryManager::SwitchToBottom()
{
	doubleEndedLinearAllocator->SwitchToBottom();
}

void MemoryManager::SwitchToTop()
{
	doubleEndedLinearAllocator->SwitchToTop();
}
