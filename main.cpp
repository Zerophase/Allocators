#include <iostream>
#include "main.h"
#include "MemoryManager.h"
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "AllocationSchemas.h"

MemoryManager memoryManager;

#define MAX_ARRAYSIZE 300
Vehicle *vehicles[MAX_ARRAYSIZE];

int main()
{

	memoryManager.StartUp();
	memoryManager.Get()->SetAllocatorUsedToDoubleLinearAllocator();
	for (int i = 0; i < MAX_ARRAYSIZE; i++)
	{
		if(i % 2 == 0)
		{
			memoryManager.Get()->SwitchToBottom();
			vehicles[i] = memoryManager.Get()->New<Car>();
		}
		else
		{
			memoryManager.Get()->SwitchToTop();
			vehicles[i] = memoryManager.Get()->New<Truck>();
		}
	}

	Update();

	memoryManager.Get()->ClearDoubleEndedLinearAllocator();

	memoryManager.ShutDown();
	return 0;
}

void Update()
{
	unsigned int iterations = 0;
	while(iterations < 100)
	{
		iterations++;
		for (int i = 0; i < MAX_ARRAYSIZE ; i++)
		{
			std::cout << vehicles[i]->SoundMade() << std::endl;
		}
	}

}
