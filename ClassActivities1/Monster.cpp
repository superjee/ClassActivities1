#include "Monster.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <memory>

Monster::Monster()
{
}
Monster::Monster(int variance)
{
	monsterVariance = variance;
}
Monster::~Monster()
{
}

void Monster::initiation(shared_ptr<ReadInFo_Monster> _ReadInFo_Monster)
{
	string info_name = _ReadInFo_Monster->get_InFo_Monster(monsterType, monsterVariance, INFO_NAME);
	int info_symbolic = atoi(_ReadInFo_Monster->get_InFo_Monster(monsterType, monsterVariance, INFO_SYMBOLIC).c_str());
	int info_hp = atoi(_ReadInFo_Monster->get_InFo_Monster(monsterType, monsterVariance, INFO_HP).c_str());
	int info_attack = atoi(_ReadInFo_Monster->get_InFo_Monster(monsterType, monsterVariance, INFO_ATTACK).c_str());
	int info_attack_swing = atoi(_ReadInFo_Monster->get_InFo_Monster(monsterType, monsterVariance, INFO_ATTACK_SWING).c_str());
	int info_tapSpeed = atoi(_ReadInFo_Monster->get_InFo_Monster(monsterType, monsterVariance, INFO_TAP_SPEED).c_str());
	int info_tapFrequency = atoi(_ReadInFo_Monster->get_InFo_Monster(monsterType, monsterVariance, INFO_TAP_FREQUNECY).c_str());


	set_name(info_name);
	set_MonsterSymbolic(info_symbolic);
	set_HP(info_hp);
	set_Atk(info_attack, info_attack_swing);
	tapSpeed = info_tapSpeed;
	tapFrequency = info_tapFrequency;
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
	//ถ้าใส่ rand() % ((37 + 1) - 23) + 23; จะได้ค่า 23 ถึง 37
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

void Monster::set_MonsterVariance(int variance)
{
	monsterVariance = variance;
}

int Monster::get_MonsterVariance()
{
	return monsterVariance;
}

void Monster::set_MonsterSymbolic(int symbolic)
{
	monsterSymbolic = symbolic;
}

int Monster::get_MonsterSymbolic()
{
	return monsterSymbolic;
}

void Monster::set_name(string nametext)
{
	name = nametext;
}

string Monster::get_name()
{
	return name;
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
	std::cout << get_name();
}

int Monster::get_atkLast()
{
	return atkLast;
}

int Monster::get_tapSpeed()
{
	return tapSpeed;
}

int Monster::get_tapFrequency()
{
	return tapFrequency;
}

void Monster::monsters_stronger(int percent)
{
	int currentHP = hp;
	currentHP *= percent;
	int addHP = currentHP / 100;
	hp += addHP;

}
