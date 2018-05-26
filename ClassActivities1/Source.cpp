#include <iostream>
#include <windows.h>
#include <vector>
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <crtdbg.h>
#include <memory>

// function prototypes

void moveUP();
void moveDOWN();
void moveLEFT();
void moveRIGHT();

void keyboardInput();

int main()
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	/*initGame();
	while (!QuitGame)
	{
		keyboardInput();
		updateGame();
	}
	//getchar();
	delete Map[MAP_ID];*/
	return 0;
}


/*void moveUP()
{
	int currentX = player[0]->get_Pos(WorldMap_X);
	int currentY = player[0]->get_Pos(WorldMap_Y);
	int nextX = currentX;
	int nextY = currentY - 1;
	if (nextY < NULL)
	{
		nextY = currentY;
	}
	playerMove(currentX, currentY, nextX, nextY);
}*/

/*void moveDOWN()
{
	int currentX = player[0]->get_Pos(WorldMap_X);
	int currentY = player[0]->get_Pos(WorldMap_Y);
	int nextX = currentX;
	int nextY = currentY + 1;
	if (nextY >= Map[MAP_ID]->getLength(WorldMap_Y))
	{
		nextY = currentY;
	}
	playerMove(currentX, currentY, nextX, nextY);
}*/

/*void moveLEFT()
{
	int currentX = player[0]->get_Pos(WorldMap_X);
	int currentY = player[0]->get_Pos(WorldMap_Y);
	int nextX = currentX - 1;
	int nextY = currentY;
	if (nextX < NULL)
	{
		nextX = currentX;
	}
	playerMove(currentX, currentY, nextX, nextY);
}*/

/*void moveRIGHT()
{
	int currentX = player[0]->get_Pos(WorldMap_X);
	int currentY = player[0]->get_Pos(WorldMap_Y);
	int nextX = currentX + 1;
	int nextY = currentY;
	if (nextX >= Map[MAP_ID]->getLength(WorldMap_X))
	{
		nextX = currentX;
	}
	playerMove(currentX, currentY, nextX, nextY);
}*/

/*void keyboardInput()
{
	if (_kbhit())// && isInput == false)
	{
		KB_code = _getch();

		switch (KB_code)
		{
		case KB_ESCAPE:
			QuitGame = true;
			break;
		case KB_LEFT:
			startGame = 0;
			break;
		case KB_RIGHT:
			startGame = 0;
			break;
		case KB_UP:
			startGame = 0;
			break;
		case KB_DOWN:
			startGame = 0;
			break;
		case KB_W:
			isInput = true;
			moveUP();
			break;
		case KB_A:
			isInput = true;
			moveLEFT();
			break;
		case KB_S:
			isInput = true;
			moveDOWN();
			break;
		case KB_D:
			isInput = true;
			moveRIGHT();
			break;
		}

	}

}*/
