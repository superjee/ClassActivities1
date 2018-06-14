#pragma once
#include "Grid2D.h"

class MoveableObject
{
public:
	MoveableObject();
	~MoveableObject();
	void set_Pos(int x, int y);
	int get_Pos(int xROy);
	void moveUP(std::shared_ptr<Grid2D> &p_Grid2D);
	void moveDOWN(std::shared_ptr<Grid2D> &p_Grid2D);
	void moveLEFT(std::shared_ptr<Grid2D> &p_Grid2D);
	void moveRIGHT(std::shared_ptr<Grid2D> &p_Grid2D);
	void objMove(int currentX, int currentY, int nextX, int nextY, std::shared_ptr<Grid2D> &p_Grid2D);
	void autoMove(std::shared_ptr<Grid2D> &p_Grid2D);
	enum MOVE_DI{ UP=1,RIGHT,DOWN,LEFT};
private:
	int pos_X;
	int pos_Y;
	int old_X = -1;
	int old_Y = -1;
	std::vector<int> canMove;
	std::vector<int> canMoveback;
};

