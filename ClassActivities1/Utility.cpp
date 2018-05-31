#include "Utility.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
Utility::Utility()
{
}

Utility::~Utility()
{
}

int Utility::KeyboardInput()
{
	if (_kbhit())
	{
		int KB_code = _getch();
		return KB_code;
	}
	return false;
}

void Utility::GoToXY(int x, int y)
{
	static HANDLE hStdout = NULL;
	COORD coord;

	coord.X = (short)x;
	coord.Y = (short)y;

	if (!hStdout)
	{
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	SetConsoleCursorPosition(hStdout, coord);
}
