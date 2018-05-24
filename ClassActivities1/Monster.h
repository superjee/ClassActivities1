#pragma once
#include <string>
#include <vector>
#include <memory>
#ifndef Monster_HPP
#define Monster_HPP
class Monster
{
public:
	Monster();
	~Monster();
	//void initiation(int type,int index, std::vector<std::shared_ptr<Monster>> monster);
	void AddDamageToPlayer();
	void set_HP(int);
	int get_HP();
	void set_Atk(int AttackDamage, int swing);
	int get_Atk();
	int get_criticalHit();
	//monsterGetDamaged(int damage)
	//input damage
	//return hp
	int monsterGetDamaged(int damage);
	void set_MonsterType(int Type);
	int get_MonsterType();
	void set_MonsterSymbolic(int symbolic);
	int get_MonsterSymbolic();
	void set_Pos(int x, int y);
	int get_Pos(int xy);
	void printPos();
	virtual void printType();
	int get_atkLast();
private:
	static const int X = 0;
	static const int Y = 1;

	int hp = -1;
	int atk = -1;
	int atkSwing = -1;
	int atkMax = -1;
	int atkMin = -1;
	int atkLast = -1;
	int criticalMultiplier = 2;
	int monsterSymbolic = 0;
	int monsterType = -1;
	//Monster position
	int pos_X = -1;
	int pos_Y = -1;

};
#include "zombie.h"
#include "Orc.h"
#endif
