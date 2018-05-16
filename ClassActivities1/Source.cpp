#include <iostream>
#include <windows.h>
#include <vector>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <crtdbg.h>
#include <memory>
#include "Monster.h"
#include "WorldMap.h"

#define MAX_NUMBER_OF_MONSTER 100
#define MAX_TYPE_OF_MONSTER 2
#define RandomTypeMonster rand() % MAX_TYPE_OF_MONSTER + 1

std::vector<WorldMap*> Map;
std::vector<std::shared_ptr<Monster>> monster;

int ran = -1;
int ranX = -1;
int ranY = -1;
int startGame = 0;

void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
void printStartGame()
{
	std::cout << "///////////        Links To Fantasy        ////////////" << std::endl;
	std::cout << "/                 by Tanapat Yatana                   /" << std::endl;
	std::cout << "/                                                     /" << std::endl;
	std::cout << "/    Zombie base Attack  : 7 - 13  (10,3)  HP : 3     /" << std::endl;
	std::cout << "/    Orc    base Attack  : 23 - 37 (30,7)  HP : 5     /" << std::endl;
	std::cout << "/                                                     /" << std::endl;
	std::cout << "///////////        Links To Fantasy        ////////////" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
void initGame()
{
	srand(time(NULL));

	Map.push_back(new WorldMap());
	Map[0]->initiation();
	
	printStartGame();

	//ADD Monster
	for (int i = 0; i < MAX_NUMBER_OF_MONSTER; i++)
	{
		monster.push_back(std::make_shared<Monster>());
	}
		
	for (int i = 0; i < MAX_NUMBER_OF_MONSTER; i++)
	{
		ran = RandomTypeMonster;
		monster[i]->initiation(ran, i, monster);
		do {
			ranX = rand() % Map[0]->getLength(WorldMap_X);
			ranY = rand() % Map[0]->getLength(WorldMap_Y);
		} while (Map[0]->getObjInMap(ranX, ranY) != Map[0]->OBJ_empty);
		Map[0]->setObjInMap(ranX, ranY, ran);
		monster[i]->set_Pos(ranX, ranY);
		monster[i]->printPos();
		std::cout << std::endl;
	}

	std::cout << std::endl;
	Map[0]->drawMap();
	std::cout << std::endl;
	std::cout << "Enter.....For Deal Damage To All Monster By 1 Point";

}
int main()
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	initGame();

	while (true)
	{
		getchar();
		clearScreen();
		if (startGame <= 0)
		{
			for (int i = 0; i < MAX_NUMBER_OF_MONSTER; i++)
			{
				if (monster[i]->monsterGetDamaged(1) <= 0) // Monster HP - 1
				{
					Map[0]->setObjInMap(monster[i]->get_Pos(WorldMap_X), monster[i]->get_Pos(WorldMap_Y), -1);

					monster[i]->initiation(monster[i]->get_MonsterType(), i, monster);
					do {
						ranX = rand() % Map[0]->getLength(WorldMap_X);
						ranY = rand() % Map[0]->getLength(WorldMap_Y);
					} while (Map[0]->getObjInMap(ranX, ranY) != Map[0]->OBJ_empty);
					Map[0]->setObjInMap(ranX, ranY, monster[i]->get_MonsterType());
					monster[i]->set_Pos(ranX, ranY);
					monster[i]->printPos();
					std::cout << std::endl;

				}
			}
		}
		std::cout << std::endl;
		Map[0]->drawMap();
		std::cout << std::endl;
		std::cout << "Enter.....For Deal Damage To All Monster By 1 Point";
		startGame -= 1;
	}

	delete Map[0];
	return 0;
}

