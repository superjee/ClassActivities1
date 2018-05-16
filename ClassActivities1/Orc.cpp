#include "Orc.h"
#include <iostream>

#define TYPE 2
#define HP 5
#define ATK_BASE 30
#define ATK_SWING 7

Orc::Orc()
{
	set_MonsterType(TYPE);
	std::cout << " !!Orc!! ";
	set_Atk(ATK_BASE, ATK_SWING);
	set_HP(HP);
}


Orc::~Orc()
{

}
