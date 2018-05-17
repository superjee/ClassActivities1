#include "zombie.h"
#include <iostream>

#define TYPE 1
#define SYMBOLIC 11
#define HP 100
#define ATK_BASE 10
#define ATK_SWING 3

zombie::zombie()
{
	set_MonsterType(TYPE);
	set_MonsterSymbolic(SYMBOLIC);
	set_Atk(ATK_BASE, ATK_SWING);
	set_HP(HP);

}

zombie::~zombie()
{

}
