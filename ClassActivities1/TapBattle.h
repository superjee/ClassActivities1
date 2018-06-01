#pragma once
class TapBattle
{
public:
	TapBattle(int p_direction,int p_tapType, int p_taptime, int p_tapY);
	~TapBattle();
	void TapUpdate();
	int Getdirection();
	int GetSym();
	int tapY = 0;
	enum symbolic { LEFT = 27, UP = 24, DOWN = 25,RIGHT = 26 };
private:
	int direction = 0; //0 1 2 3
	int tapType = 0;//0 1
	int taptime = 0;
	int timeCount = 0;
	int sym = 0;
};

