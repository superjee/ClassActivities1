#pragma once
#ifndef _UTILITY_H
#define _UTILITY_H

enum KeyboardInput
{
	EXIT = 27,
	KB_W = 119,
	KB_A = 97,
	KB_S = 115,
	KB_D = 100,
	KB_UP = 72,
	KB_DOWN = 80,
	KB_LEFT = 75,
	KB_RIGHT = 77
};

class Utility final
{
public:
	Utility();
	~Utility();
	static int KeyboardInput();
	static void GoToXY(int x, int y);
};
#endif //_UTILITY_H
