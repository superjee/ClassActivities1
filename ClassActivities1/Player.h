#pragma once

#ifndef Player_HPP
#define Player_HPP
class Player
{
public:
	Player();
	virtual ~Player();
	void initiation(int input_hp, int input_atk,int input_swing);
	int get_HP();
	int get_Atk();
	int get_PlayerSymbolic();
	void set_Pos(int x, int y);
	int get_Pos(int xy);
	void printPos();
	int get_AtkMin();
	int get_AtkMax();
private:
	static const int X = 0;
	static const int Y = 1;

	int hp = -1;
	int atk = -1;
	int atkSwing = -1;
	int atkMax = -1;
	int atkMin = -1;
	int atkLast = -1;
	int criticalMultiplier = 2;
	int playerSymbolic = 3;
	//Player position
	int pos_X = -1;
	int pos_Y = -1;
};
#endif
