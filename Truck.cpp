//
// Created by zerophase on 5/21/15.
//

#include "Truck.h"

Truck::Truck()
{
	sound = "Hunk Hunk";
}

Truck::~Truck()
{

}

std::string Truck::SoundMade()
{
	return sound;
}
