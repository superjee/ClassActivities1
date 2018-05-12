#include "Monster.h"

#include "zombie.h"
#include "Orc.h"

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <memory>
using namespace std;


Monster::Monster()
{
}

Monster::Monster(int atk, int swing)
{
	Atk = atk;
	AtkSwing = swing;
	AtkMax = Atk + AtkSwing;
	AtkMin = Atk - AtkSwing;
	if (AtkMin < 0)
	{
		AtkMin = 0;
	}
}

Monster::~Monster()
{
	//free(this);
}

void Monster::initiation(int type,int index, std::vector<std::shared_ptr<Monster>> monster)//Monster *base[]
{
	
	cout << "Monster index : " << index << " ";

	switch (type) {
	case 1:
		monster.push_back(std::make_shared<zombie>());//base[index] = new zombie();
		break;
	case 2:
		monster.push_back(std::make_shared<Orc>());//base[index] = new Orc();
		break;
	default:
		cout << "error Monster::init >>> type not match" << endl;
	}

	cout << "Attack = " << monster[index]->get_Atk() << " ";//cout << "Attack = " << base[index]->get_Atk() << " ";

}

void Monster::AddDamageToPlayer()
{
	cout << "TakeFromMonsterClass";
}

void Monster::set_HP(int hp)
{
	HP = hp;
}

int Monster::get_HP()
{
	return HP;
}

void Monster::set_Atk(int atk, int swing)
{
	AtkLast = atk;
	Atk = atk;
	AtkSwing = swing;
	AtkMax = Atk + AtkSwing;
	AtkMin = Atk - AtkSwing;
	if (AtkMin < 0)
	{
		AtkMin = 0;
	}
}

int Monster::get_Atk()
{
	//ถ้าใส่ rand() % ((37 + 1) - 23) + 23; จะได้ค่า 23 ถึง 37
	int r = rand() % ((AtkMax+1)- AtkMin) + AtkMin;
	AtkLast = r;
	return AtkLast;
}

int Monster::get_criticalHit()
{
	AtkLast *= 2;
	return AtkLast;
}

int Monster::monsterGetDamaged(int damage)
{
	HP -= damage;
	return HP;
}

void Monster::set_MonsterType(int Type)
{
	MonsterType = Type;
}

int Monster::get_MonsterType()
{
	return MonsterType;
}

void Monster::set_Pos(int x, int y)
{
	Pos_X = x;
	Pos_Y = y;
}

int Monster::get_Pos(int xy)
{
	if (xy == 0)
	{
		return Pos_X;
	}
	else if (xy == 1)
	{
		return Pos_Y;
	}
	else
	return 0;
}

void Monster::printPos()
{
	cout << " Position ( " << Pos_X << " , " << Pos_Y << " )";
}
