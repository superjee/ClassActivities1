#include "car.h"



car::car()
{
}


car::~car()
{
}

void car::init(int p_dataID, std::string p_name, int p_fuel, std::string p_shape)
{
	dataID = p_dataID;
	name = p_name;
	fuel = p_fuel;
	shape = p_shape;
}

bool car::canUseOneFuelForMove()
{
	fuel--;
	if (fuel <= 0)
	{
		fuel = 0;
		return false;
	}
	return true;
}
