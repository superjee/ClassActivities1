#pragma once
#include "Monster.h"
#ifndef zombie_HPP
#define zombie_HPP
class zombie :
	public Monster
{
public:
	zombie();
	virtual ~zombie();
	void printType();
	void initiation(shared_ptr<ReadInFo_Monster> _ReadInFo_Monster);
};
#endif
