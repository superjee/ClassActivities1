#pragma once
#ifndef SpawnPoint_HPP
#define SpawnPoint_HPP
#include "Monster.h"

class SpawnPoint
{
public:
	SpawnPoint();
	virtual ~SpawnPoint();
	virtual std::shared_ptr<Monster> spawn(int variance) = 0;
};

template <class T>
class SpawnTo : public SpawnPoint {
public:
	std::shared_ptr<Monster> spawn(int variance)
	{
		return make_shared<T>(variance);
	}
};
#endif

