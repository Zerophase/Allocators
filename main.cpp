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

	for (int i = 0; i < MAX_ARRAYSIZE; i++)
	{
		if(i % 2 == 0)
		{
			memoryManager.Get()->GetDoubleEndedLinearAllocator().SwitchToBottom();
			vehicles[i] = New<Car>(memoryManager.Get()->GetDoubleEndedLinearAllocator());
		}
		else
		{
			memoryManager.Get()->GetDoubleEndedLinearAllocator().SwitchToTop();
			vehicles[i] = New<Truck>(memoryManager.Get()->GetDoubleEndedLinearAllocator());
		}
	}

	Update();

	memoryManager.Get()->ClearDoubleEndedLinearAllocator();

	memoryManager.ShutDown();
	return 0;
}

void Update()
{
	uint iterations = 0;
	while(iterations < 100)
	{
		iterations++;
		for (int i = 0; i < MAX_ARRAYSIZE ; i++)
		{
			std::cout << vehicles[i]->SoundMade() << std::endl;
		}
	}

}
