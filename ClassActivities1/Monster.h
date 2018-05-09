#pragma once
#include <string>
#ifndef Monster_HPP
#define Monster_HPP
class Monster
{
public:
	int monsterA[100];//
	Monster();
	Monster(int atk, int swing);
	~Monster();
	void initiation(int type,int index);
	void AddDamageToPlayer();
	void set_HP(int);
	int get_HP();
	void set_Atk(int AttackDamage, int swing);
	int get_Atk();
private:
	
	int HP = -1;
	int Atk = -1;
	int AtkSwing = -1;
	int AtkMax = -1;
	int AtkMin = -1;

};
#endif
