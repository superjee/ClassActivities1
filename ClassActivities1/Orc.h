#pragma once
#include "Monster.h"

#ifndef Orc_HPP
#define Orc_HPP
class Orc :
	public Monster
{
public:
	Orc(Monster *base);
	virtual ~Orc();
};
#endif
