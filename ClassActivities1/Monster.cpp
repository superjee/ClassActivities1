#include "Monster.h"

#include "zombie.h"
#include "Orc.h"

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


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
}

void Monster::initiation(int type,int index)
{
	switch (type) {
	case 1:
		cout << "Monster index : " << index << " ";
		new zombie(this);
		cout << "Attack = " << this->get_Atk() << " " << endl;
		break;
	case 2:
		cout << "Monster index : " << index << " ";
		new Orc(this);
		cout << "Attack = " << this->get_Atk() << " " << endl;
		break;
	default:
		cout << "error Monster::init >>> type not match" << endl;
	}

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
	int r = rand() % AtkMax + AtkMin;
	return r;
}
