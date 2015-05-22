//
// Created by zerophase on 5/21/15.
//

#include "Car.h"

Car::Car()
{
	sound = "Honk";
}

Car::~Car()
{

}

std::string Car::SoundMade()
{
	return sound;
}
