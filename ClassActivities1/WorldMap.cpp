#include "WorldMap.h"
#include <iostream>
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
	for (int i = 0; i < Y; i++)
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



