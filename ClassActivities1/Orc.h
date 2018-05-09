#pragma once
#include "Monster.h"

#ifndef Orc_HPP
#define Orc_HPP
class Orc :
	public Monster
{
public:
	Orc();
	Orc(Monster *base);
	virtual ~Orc();
};
#endif
