#include "zombie.h"
#include <iostream>

#define TYPE 1
#define HP 3
#define ATK_BASE 10
#define ATK_SWING 3

zombie::zombie()
{
	set_MonsterType(TYPE);
	std::cout << " !!zombie!! ";
	set_Atk(ATK_BASE, ATK_SWING);
	set_HP(HP);

}

zombie::~zombie()
{

}
