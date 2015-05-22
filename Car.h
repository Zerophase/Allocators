//
// Created by zerophase on 5/21/15.
//

#ifndef ALLOCATORS_CAR_H
#define ALLOCATORS_CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	~Car();

	std::string SoundMade() override;
};


#endif //ALLOCATORS_CAR_H
