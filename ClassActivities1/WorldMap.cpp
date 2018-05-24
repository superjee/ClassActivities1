#include "WorldMap.h"
#include <iostream>
#include <windows.h>
void gotoxyWM(int x, int y)
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

WorldMap::WorldMap()
{
}
WorldMap::~WorldMap()
{
}
void WorldMap::initiation()
{
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			worldMap[i][j] = -1;
		}
	}
}

void WorldMap::drawMap()
{
	/*for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (worldMap[i][j] == OBJ_empty)
			{
				std::cout << " " << static_cast<char>(SYM_empty);;
			}
			else if (worldMap[i][j] == OBJ_ZOMBIE)
			{
				std::cout << " " << static_cast<char>(SYM_ZOMBIE);
			}
			else if (worldMap[i][j] == OBJ_ORC)
			{
				std::cout << " " << static_cast<char>(SYM_ORC);
			}
		}
		std::cout << std::endl;
	}*/
}

void WorldMap::drawObjInMap(int x, int y, int Obj, int sym)
{
	int newX = (startPosX + 1) +x;
	int newY = (startPosX + 1);
	gotoxyWM(x + newX, y + newY);
	if (Obj == OBJ_empty)
	{
		std::cout << " " << static_cast<char>(SYM_empty);;
	}
	else if (worldMap[x][y] == Obj)
	{
		std::cout << " " << static_cast<char>(sym);
	}
	else if (worldMap[x][y] != Obj && Obj == NULL)
	{
		std::cout << "WorldMap::drawObjInMap Error" << std::endl;
	}

}

void WorldMap::drawMapBox()
{
	int newX = startPosX;
	int newY = startPosY;
	gotoxyWM(newX, newY);
	for (int loop = 0; loop < (X * 2) + 3; loop++)
	{
		std::cout << "=";
	}
	gotoxyWM(newX, newY +Y+1);
	for (int loop = 0; loop < (X * 2) + 3; loop++)
	{
		std::cout << "=";
	}
	for (int loop = 1; loop < Y+1; loop++)
	{
		gotoxyWM(newX, newY + loop);
		std::cout << "|";
		gotoxyWM(newX + (X * 2) + 2, newY + loop);
		std::cout << "|";
	}
}

int WorldMap::getLength(int xy)
{
	if (xy == WorldMap_X)
	{
		return X;
	}
	else if (xy == WorldMap_Y)
	{
		return Y;
	}
	else
	{
		std::cout << std::endl << "WorldMap::getLength Error" << std::endl;
		return -1;
	}
}

int WorldMap::getObjInMap(int x, int y)
{
	return worldMap[x][y];
}

void WorldMap::setObjInMap(int x, int y, int Obj)
{
	worldMap[x][y] = Obj;
}

int WorldMap::getEndPosY()
{
	return endPosY;
}

void WorldMap::setOldObj(int inputID)
{
	oldObjID = inputID;
}

int WorldMap::getOldObj()
{
	return oldObjID;
}



