#include "Grid2D.h"

Grid2D::Grid2D()
{
}


Grid2D::~Grid2D()
{
}

void Grid2D::initiation(int set_x, int set_y)
{
	gridX.clear();
	gridY.clear();
	X = set_x;
	Y = set_y;
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
}

int Grid2D::getDataInGrid(int x, int y)
{
	return gridY[y][x];
}

void Grid2D::setDataInGrid(int x, int y, int data)
{
	gridY[y][x] = data;
}

void Grid2D::drawBox(int startPosX, int startPosY)
{
	Utility::GoToXY(startPosX, startPosY);
	for (int loop = 0; loop < (X * 2) + 3; loop++)
	{
		std::cout << "=";
	}
	Utility::GoToXY(startPosX, startPosY + Y + 1);
	for (int loop = 0; loop < (X * 2) + 3; loop++)
	{
		std::cout << "=";
	}
	for (int loop = 1; loop < Y + 1; loop++)
	{
		Utility::GoToXY(startPosX, startPosY + loop);
		std::cout << "|";
		Utility::GoToXY(startPosX + (X * 2) + 2, startPosY + loop);
		std::cout << "|";
	}
}

int Grid2D::getLength(int xORy)
{
	if (xORy == GRID::GRID_X)
	{
		return X;
	}
	else if (xORy == GRID::GRID_Y)
	{
		return Y;
	}
	else
	{
		std::cout << std::endl << "Grid2D::getLength Error" << std::endl;
		return -1;
	}

}
