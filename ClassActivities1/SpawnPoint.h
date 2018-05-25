#pragma once
#ifndef SpawnPoint_HPP
#define SpawnPoint_HPP
#include "Monster.h"

class SpawnPoint //: public Monster
{
public:
	SpawnPoint();
	virtual ~SpawnPoint();
	//virtual Monster* spawn(int variance) = 0;
	//virtual Monster* spawn() = 0;
	virtual std::shared_ptr<Monster> spawn(int variance) = 0;
	//virtual Monster* reSpawn(Monster *obj, int variance) = 0;
};

template <class T>
class SpawnTo : public SpawnPoint {
public:
	/*Monster * spawn(int variance) {
		return new T(variance);
	}*/
	/*Monster * spawn() {
		return new T();

	}*/
	std::shared_ptr<Monster> spawn(int variance)
	{
		return make_shared<T>(variance);
	}
	/*Monster* reSpawn(Monster *obj, int variance)
	{
		delete obj;
		return new T(variance);
	}*/
	
};

#endif

