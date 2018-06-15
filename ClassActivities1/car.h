#pragma once
#include "MoveableObject.h"
#include <iostream>
class car : public MoveableObject
{
public:
	car();
	~car();
	void init(int p_dataID, std::string p_name, int p_fuel, std::string p_shape);
	bool canUseOneFuelForMove();
private:
	int fuel;


};

