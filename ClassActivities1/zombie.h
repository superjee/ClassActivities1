#pragma once
#include "Monster.h"
#ifndef zombie_HPP
#define zombie_HPP
class zombie :
	public Monster
{
public:
	zombie();
	zombie(Monster *base);
	virtual ~zombie();
};
#endif
