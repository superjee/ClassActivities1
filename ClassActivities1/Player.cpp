#include "Player.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


Player::Player()
{
}


Player::~Player()
{
}

void Player::initiation(int input_hp, int input_atk, int input_swing)
{
	hp = input_hp;
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

int Player::get_HP()
{
	return hp;
}

int Player::get_Atk()
{
	int r = rand() % ((atkMax + 1) - atkMin) + atkMin;
	atkLast = r;
	return atkLast;
}

int Player::get_PlayerSymbolic()
{
	return playerSymbolic;
}

void Player::set_Pos(int x, int y)
{
	pos_X = x;
	pos_Y = y;
}

int Player::get_Pos(int xy)
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

void Player::printPos()
{
	std::cout << "  " << static_cast<char>(playerSymbolic) <<" Player Position ( " << pos_X << " , " << pos_Y << " )";
}

int Player::get_AtkMin()
{
	return atkMin;
}

int Player::get_AtkMax()
{
	return atkMax;
}
