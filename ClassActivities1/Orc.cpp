#include "Orc.h"
#include <iostream>

const static int TYPE = 2;

Orc::Orc()
{
	set_MonsterType(TYPE);
	set_MonsterVariance(NULL);
}

Orc::Orc(int variance)
{
	set_MonsterType(TYPE);
	set_MonsterVariance(variance);
}

Orc::~Orc()
{

}
