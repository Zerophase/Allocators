//
// Created by zerophase on 5/21/15.
//

#ifndef ALLOCATORS_TRUCK_H
#define ALLOCATORS_TRUCK_H


#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	Truck();
	~Truck();

	std::string SoundMade() override;
};


#endif //ALLOCATORS_TRUCK_H
