#include "Orc.h"
#include <iostream>

Orc::Orc()
{
	std::cout << " !!Orc!! ";
	set_Atk(30, 7);
	set_HP(300);
	//std::cout << "Attack = " << this->get_Atk() << " " << std::endl;
	//free(this);
}

Orc::Orc(Monster *base)
{
	std::cout << " !!Orc!! ";
	base->set_Atk(30, 7);
	base->set_HP(300);
	//free(this);
}

Orc::~Orc()
{
}
