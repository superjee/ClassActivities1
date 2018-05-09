#include "Orc.h"
#include <iostream>

Orc::Orc(Monster *base)
{
	std::cout << " !!Orc!! ";
	base->set_Atk(30, 7);
	//free(this);
}

Orc::~Orc()
{
}
