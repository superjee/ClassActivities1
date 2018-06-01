#include "TapBattle.h"



TapBattle::TapBattle(int p_direction, int p_tapType, int p_taptime, int p_tapY)
{
	direction = p_direction;
	tapType = p_tapType;
	taptime = p_taptime;
	tapY = p_tapY;

	switch (p_direction) {
	case 0:
		sym = symbolic::LEFT;
		break;
	case 1:
		sym = symbolic::UP;
		break;
	case 2:
		sym = symbolic::DOWN;
		break;
	case 3:
		sym = symbolic::RIGHT;
		break;
	default:
		sym = 119; // debug symbolic =  "w"
		break;
	}


}


TapBattle::~TapBattle()
{
}

void TapBattle::TapUpdate()
{
	timeCount++;
	if (timeCount >= taptime)
	{
		timeCount = 0;
		tapY -= 1;
	}
}

int TapBattle::Getdirection()
{
	return direction;
}

int TapBattle::GetSym()
{
	return sym;
}
