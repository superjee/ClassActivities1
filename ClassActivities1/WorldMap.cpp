#include "WorldMap.h"
#include <iostream>


WorldMap::WorldMap()
{
}



WorldMap::~WorldMap()
{
	//delete(this);
}

void WorldMap::initiation()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			worldMap[i][j] = -1;
		}
	}
}

void WorldMap::drawMap()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (worldMap[i][j] == -1)
			{
				std::cout << " =";
			}
			else if (worldMap[i][j] == 1)
			{
				std::cout << " " << Monster1;//<< worldMap[i][j] << "";
			}
			else if (worldMap[i][j] == 2)
			{
				std::cout << " " << Monster2;//<< worldMap[i][j] << "";
			}
		}
		std::cout << std::endl;
	}
}

int WorldMap::getLength(int xy)
{
	if (xy == 0)
	{
		return x;
	}
	else if (xy == 1)
	{
		return y;
	}
	else
	{
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



