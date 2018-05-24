#include "zombie.h"
#include <iostream>

#define TYPE 1
#define SYMBOLIC 11
#define HP 100
#define ATK_BASE 10
#define ATK_SWING 3

zombie::zombie()
{
	/*set_MonsterType(TYPE);
	set_MonsterSymbolic(SYMBOLIC);
	set_Atk(ATK_BASE, ATK_SWING);
	set_HP(HP);*/

}

zombie::~zombie()
{

}

void zombie::printType()
{
	std::cout << "zombie";
}

void zombie::initiation(shared_ptr<ReadInFo_Monster> _ReadInFo_Monster)
{
	std::cout << "get_InFo_Monster(TYPE1, 0, 0) = " << _ReadInFo_Monster->get_InFo_Monster(TYPE, 0, 0) << std::endl;
	std::cout << "get_InFo_Monster(TYPE1, 0, 2) = " << _ReadInFo_Monster->get_InFo_Monster(TYPE, 0, 2) << std::endl;
	std::cout << "get_InFo_Monster(TYPE2, 0, 0) = " << _ReadInFo_Monster->get_InFo_Monster(TYPE+1, 0, 0) << std::endl;
}
