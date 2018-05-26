#pragma once
#include "Monster.h"
#ifndef zombie_HPP
#define zombie_HPP
class zombie :
	public Monster
{
public:
	zombie();
	zombie(int variance);
	virtual ~zombie();
	zombie(const zombie& other) = default;
	zombie& operator= (zombie& other) = default;
};
#endif
