#include "Monster.h"
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

void Monster::init()
{
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		monsterA[i] = rand() % 2;
		if (monsterA[i] == 0)
		{
			cout << "Zombie";
		}
		else if (monsterA[i] == 1)
		{
			cout << "Orc";
		}

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
	/* initialize random seed: */
	srand(time(NULL));
	int r = rand() % AtkMax + AtkMin;
	return 0;
}
