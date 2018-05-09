#include "zombie.h"
#include <iostream>


zombie::zombie(Monster *base)
{
	std::cout << " !!zombie!! ";
	base->set_Atk(10, 3);
	//free(this);
}


zombie::~zombie()
{
	
}
