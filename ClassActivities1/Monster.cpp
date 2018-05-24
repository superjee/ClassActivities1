#include "Monster.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <memory>

Monster::Monster()
{
}
Monster::~Monster()
{
}

void Monster::initiation(shared_ptr<ReadInFo_Monster> _ReadInFo_Monster)
{
	std::cout << "ReadInFo_Monster >> From >> Monster Class";
}

void Monster::AddDamageToPlayer()
{
	std::cout << "TakeFromMonsterClass";
}

void Monster::set_HP(int input_hp)
{
	hp = input_hp;
}

int Monster::get_HP()
{
	return hp;
}

void Monster::set_Atk(int input_atk, int input_swing)
{
	atkLast = input_atk;
	atk = input_atk;
	atkSwing = input_swing;
	atkMax = atk + atkSwing;
	atkMin = atk - atkSwing;
	if (atkMin < 0)
	{
		atkMin = 0;
	}
}

int Monster::get_Atk()
{
	//������ rand() % ((37 + 1) - 23) + 23; ������ 23 �֧ 37
	int r = rand() % ((atkMax+1)- atkMin) + atkMin;
	atkLast = r;
	return atkLast;
}

int Monster::get_criticalHit()
{
	atkLast *= criticalMultiplier;
	return atkLast;
}

/*monsterGetDamaged return hp*/
int Monster::monsterGetDamaged(int damage)
{
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
	return hp;
}

void Monster::set_MonsterType(int Type)
{
	monsterType = Type;
}

int Monster::get_MonsterType()
{
	return monsterType;
}

void Monster::set_MonsterSymbolic(int symbolic)
{
	monsterSymbolic = symbolic;
}

int Monster::get_MonsterSymbolic()
{
	return monsterSymbolic;
}

void Monster::set_Pos(int x, int y)
{
	pos_X = x;
	pos_Y = y;
}

int Monster::get_Pos(int xy)
{
	if (xy == X)
	{
		return pos_X;
	}
	else if (xy == Y)
	{
		return pos_Y;
	}
	else
	return 0;
}

void Monster::printPos()
{
	std::cout << " Position ( " << pos_X << " , " << pos_Y << " )";
}

void Monster::printType()
{
	std::cout << "   *Type Error*  ";
}

int Monster::get_atkLast()
{
	return atkLast;
}
