#include "zombie.h"
#include <iostream>

const static int TYPE = 1;

zombie::zombie()
{
	set_MonsterType(TYPE);
	set_MonsterVariance(NULL);
}

zombie::zombie(int variance)
{
	set_MonsterType(TYPE);
	set_MonsterVariance(variance);
}

zombie::~zombie()
{

}


