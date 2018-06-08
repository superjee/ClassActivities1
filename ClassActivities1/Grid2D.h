#pragma once
#ifndef _GRID2D_H
#define _GRID2D_H
#include "Engine.h"

class Grid2D
{
public:
	Grid2D();
	~Grid2D();
	void testGrid()
	{
		int num = 0;
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				gridX.push_back(num);
				num++;
			}
			gridY.push_back(gridX);
			gridX.clear();
		}

		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				std::cout << gridY[j][i] << " ";
			}
			std::cout << std::endl;
		}
		
	}
private:
	int X;
	int Y;
	std::vector<int> gridX;
	std::vector<std::vector<int>> gridY;
};
#endif
