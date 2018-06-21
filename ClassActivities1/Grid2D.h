#pragma once
#ifndef _GRID2D_H
#define _GRID2D_H
#include "Utility.h"

class Grid2D
{
public:
	Grid2D();
	~Grid2D();
	void testGrid()
	{
		int num = 0;
		for (int j = 0; j < Y; j++)
		{
			for (int i = 0; i < X; i++)
			{
				gridX.push_back(num);
				num++;
			}
			gridY.push_back(gridX);
			gridX.clear();
		}

		/*for (int j = 0; j < Y; j++)
		{
			for (int i = 0; i < X; i++)
			{
				std::cout << gridY[j][i] << " ";
			}
			std::cout << std::endl;
		}*/
		
	}
	void initiation(int set_x,int set_y);
	int getDataInGrid(int x, int y);
	void setDataInGrid(int x,int y,int data);
	void drawBox(int startPosX, int startPosY);
	void drawObj(int x,int y,int obj, char sym = 0);
	int getLength(int xORy);
	//void setOldData(int )
	enum GRID{ GRID_X , GRID_Y };
	int saveX = 0;
	int saveY = 0;
private:
	int X;
	int Y;
	int oldData;
	int m_startPosX;
	int m_startPosY;
	std::vector<int> gridX;
	std::vector<std::vector<int>> gridY;

};
#endif