#include "MoveableObject.h"

MoveableObject::MoveableObject()
{
}

MoveableObject::~MoveableObject()
{
}

void MoveableObject::set_Pos(int x, int y)
{
	pos_X = x;
	pos_Y = y;
}

int MoveableObject::get_Pos(int xROy)
{
	if (xROy == Grid2D::GRID::GRID_X)
	{
		return pos_X;
	}
	else if (xROy == Grid2D::GRID::GRID_Y)
	{
		return pos_Y;
	}
	else
		return 0;
}

void MoveableObject::moveUP(std::shared_ptr<Grid2D> &p_Grid2D)
{
	int currentX = this->get_Pos(Grid2D::GRID::GRID_X);
	int currentY = this->get_Pos(Grid2D::GRID::GRID_Y);
	int nextX = currentX;
	int nextY = currentY - 1;
	if (nextY < NULL)
	{
		nextY = currentY;
	}
	objMove(currentX, currentY, nextX, nextY, p_Grid2D);
}

void MoveableObject::moveDOWN(std::shared_ptr<Grid2D> &p_Grid2D)
{
	int currentX = this->get_Pos(Grid2D::GRID::GRID_X);
	int currentY = this->get_Pos(Grid2D::GRID::GRID_Y);
	int nextX = currentX;
	int nextY = currentY + 1;
	if (nextY >= p_Grid2D->getLength(Grid2D::GRID::GRID_Y))
	{
		nextY = currentY;
	}
	objMove(currentX, currentY, nextX, nextY, p_Grid2D);
}

void MoveableObject::moveLEFT(std::shared_ptr<Grid2D> &p_Grid2D)
{
	int currentX = this->get_Pos(Grid2D::GRID::GRID_X);
	int currentY = this->get_Pos(Grid2D::GRID::GRID_Y);
	int nextX = currentX - 1;
	int nextY = currentY;
	if (nextX < NULL)
	{
		nextX = currentX;
	}
	objMove(currentX, currentY, nextX, nextY, p_Grid2D);
}

void MoveableObject::moveRIGHT(std::shared_ptr<Grid2D> &p_Grid2D)
{
	int currentX = this->get_Pos(Grid2D::GRID::GRID_X);
	int currentY = this->get_Pos(Grid2D::GRID::GRID_Y);
	int nextX = currentX + 1;
	int nextY = currentY;
	if (nextX >= p_Grid2D->getLength(Grid2D::GRID::GRID_X))
	{
		nextX = currentX;
	}
	objMove(currentX, currentY, nextX, nextY, p_Grid2D);
}

void MoveableObject::objMove(int currentX, int currentY, int nextX, int nextY, std::shared_ptr<Grid2D> &p_Grid2D)
{
	if (p_Grid2D->getDataInGrid(nextX, nextY) == 0)
	{
		p_Grid2D->setDataInGrid(currentX, currentY, 0);
		p_Grid2D->drawObj(currentX, currentY, 0);

		p_Grid2D->setDataInGrid(nextX, nextY, dataID);
		const char *cstr = shape.c_str();
		char dummy = *cstr;
		p_Grid2D->drawObj(nextX, nextY, dataID, dummy);

		pos_X = nextX;
		pos_Y = nextY;
		old_X = currentX;
		old_Y = currentY;
	}
}

void MoveableObject::autoMove(std::shared_ptr<Grid2D> &p_Grid2D)
{
	int can_UP = pos_Y - 1;
	int can_DOWN = pos_Y + 1;
	int can_RIGHT = pos_X + 1;
	int can_LEFT = pos_X - 1;
	canMove.clear();
	canMoveback.clear();
	if (can_UP >= 0)
		if (p_Grid2D->getDataInGrid(pos_X, can_UP) == 0)
		{
			if(can_UP != old_Y)
				canMove.push_back(MOVE_DI::UP);
			else
				canMoveback.push_back(MOVE_DI::UP);
		}

	if (can_RIGHT < p_Grid2D->getLength(Grid2D::GRID::GRID_X))
		if (p_Grid2D->getDataInGrid(can_RIGHT, pos_Y) == 0)
		{
			if (can_RIGHT != old_X)
				canMove.push_back(MOVE_DI::RIGHT);
			else
				canMoveback.push_back(MOVE_DI::RIGHT);
		}

	if (can_DOWN < p_Grid2D->getLength(Grid2D::GRID::GRID_Y))
		if (p_Grid2D->getDataInGrid(pos_X, can_DOWN) == 0)
		{
			if (can_DOWN != old_Y)
				canMove.push_back(MOVE_DI::DOWN);
			else
				canMoveback.push_back(MOVE_DI::DOWN);
		}

	if (can_LEFT >= 0)
		if (p_Grid2D->getDataInGrid(can_LEFT, pos_Y) == 0)
		{
			if (can_LEFT != old_X)
				canMove.push_back(MOVE_DI::LEFT);
			else
				canMoveback.push_back(MOVE_DI::LEFT);
		}
	
	int ran = -1;
	if (canMove.size() == 0)
	{
		if(canMoveback.size() != 0)
		switch (canMoveback[0])
		{
		case MOVE_DI::UP:
			this->moveUP(p_Grid2D);
			break;
		case MOVE_DI::RIGHT:
			this->moveRIGHT(p_Grid2D);
			break;
		case MOVE_DI::DOWN:
			this->moveDOWN(p_Grid2D);
			break;
		case MOVE_DI::LEFT:
			this->moveLEFT(p_Grid2D);
			break;
		}
	}
	else
	{
		if (canMove.size() == 1)
			ran = 0;
		else if (canMove.size() > 1)
			ran = rand() % canMove.size();

		if (canMove.size() != 0)
		switch (canMove[ran])
		{
		case MOVE_DI::UP:
			this->moveUP(p_Grid2D);
			break;
		case MOVE_DI::RIGHT:
			this->moveRIGHT(p_Grid2D);
			break;
		case MOVE_DI::DOWN:
			this->moveDOWN(p_Grid2D);
			break;
		case MOVE_DI::LEFT:
			this->moveLEFT(p_Grid2D);
			break;
		}
	}
	
	canMove.clear();
	canMoveback.clear();
}
