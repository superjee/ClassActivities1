#include "zombie.h"
#include <iostream>


zombie::zombie()
{
	std::cout << " !!zombie!! ";
	set_Atk(10, 3);
	set_HP(100);
	//std::cout << "Attack = " << this->get_Atk() << " " << std::endl;
	//free(this);
}


zombie::zombie(Monster *base)
{
	std::cout << " !!zombie!! ";
	base->set_Atk(10, 3);
	base->set_HP(100);
	//free(this);
}


zombie::~zombie()
{
	
}
