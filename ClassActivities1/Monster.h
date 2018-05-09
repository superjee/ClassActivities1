#pragma once
#include <string>
#ifndef Monster_HPP
#define Monster_HPP
class Monster
{
public:
	Monster();
	Monster(int atk, int swing);
	~Monster();
	void initiation(int type,int index, Monster *base[]);
	void AddDamageToPlayer();
	void set_HP(int);
	int get_HP();
	void set_Atk(int AttackDamage, int swing);
	int get_Atk();
	int get_criticalHit();
	int monsterGetDamaged(int damage);
	void set_MonsterType(int Type);
	int get_MonsterType();
	void set_Pos(int x, int y);
	int get_Pos(int xy);

	void printPos();
	//void printAtk();

private:
	int HP = -1;
	int Atk = -1;
	int AtkSwing = -1;
	int AtkMax = -1;
	int AtkMin = -1;
	int AtkLast = -1;
	int MonsterType = -1;
	//Monster position
	int Pos_X = -1;
	int Pos_Y = -1;
};
#endif
