//
// Created by zerophase on 5/21/15.
//

#ifndef ALLOCATORS_VEHICLE_H
#define ALLOCATORS_VEHICLE_H


#include <string>

class Vehicle
{
public:
	virtual std::string SoundMade() = 0;

protected:
	std::string sound;
};


#endif //ALLOCATORS_CAR_H
