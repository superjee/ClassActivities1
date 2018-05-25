#pragma once
#ifndef Monster_HPP
#define Monster_HPP
#include <string>
#include <vector>
#include <memory>
#include "ReadInFo_Monster.h"
#include "Define_Monster.h"
class Monster
{
public:
	Monster();
	Monster(int variance);
	~Monster();
	void initiation(shared_ptr<ReadInFo_Monster> _ReadInFo_Monster);//(ReadInFo_Monster _ReadInFo_Monster);virtual 
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
	void set_MonsterVariance(int variance);
	int get_MonsterVariance();
	void set_MonsterSymbolic(int symbolic);
	int get_MonsterSymbolic();
	void set_name(string nametext);
	string get_name();
	void set_Pos(int x, int y);
	int get_Pos(int xy);
	void printPos();
    void printType();
	int get_atkLast();

	void monsters_stronger(int percent = 1);
private:
	static const int X = 0;
	static const int Y = 1;
	string name = "UN_KNOW";
	int hp = -1;
	int atk = -1;
	int atkSwing = -1;
	int atkMax = -1;
	int atkMin = -1;
	int atkLast = -1;
	int criticalMultiplier = 2;
	int monsterSymbolic = 0;
	int monsterType = -1;
	int monsterVariance = -1;
	//Monster position
	int pos_X = -1;
	int pos_Y = -1;
protected:
	static const int INFO_NAME = 0;
	static const int INFO_SYMBOLIC = 1;
	static const int INFO_HP = 2;
	static const int INFO_ATTACK = 3;
	static const int INFO_ATTACK_SWING = 4;
};
#include "zombie.h"
#include "Orc.h"
#endif
