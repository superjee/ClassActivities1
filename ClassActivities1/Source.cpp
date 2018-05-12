#include <iostream>
#include <windows.h>
#include <vector>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
//add 12/05/61
#include <crtdbg.h>
#include <memory>
#include "Monster.h"
#include "WorldMap.h"
using namespace std;
//Test up in Visual // can not push by Visual??? ,but can push by GitHub Desktop.

const int MaxNumberOfMonster = 100;

void ClearScreen()
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

//void print()

int main()
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::vector<WorldMap*> Map01;
	Map01.push_back(new WorldMap());
	Map01[0]->initiation();

	cout << "///////////        Links To Fantasy        ////////////" << endl;
	cout << "/                 by Tanapat Yatana                   /" << endl;
	cout << "/                                                     /" << endl;
	cout << "/    Zombie base Attack  : 7 - 13  (10,3)  HP : 3     /" << endl;
	cout << "/    Orc    base Attack  : 23 - 37 (30,7)  HP : 5     /" << endl;
	cout << "/                                                     /" << endl;
	cout << "///////////        Links To Fantasy        ////////////" << endl;
	cout << endl;
	cout << endl;

	srand(time(NULL));
	int ran = -1;
	int ranX = -1;
	int ranY = -1;

	//Monster *monster[MaxNumberOfMonster];
	//auto m = std::make_shared<Monster[MaxNumberOfMonster]>();
	std::vector<std::shared_ptr<Monster>> monster;
	for(int i = 0; i<MaxNumberOfMonster;i++)
		monster.push_back(std::make_shared<Monster>()); //loop 100

	for (int i = 0; i < MaxNumberOfMonster; i++)
	{
		ran = rand() % 2 + 1;
		monster[i]->initiation(ran, i, monster);
		do {
			ranX = rand() % Map01[0]->getLength(0);
			ranY = rand() % Map01[0]->getLength(1);
		} while (Map01[0]->getObjInMap(ranX, ranY) != -1);
		Map01[0]->setObjInMap(ranX, ranY, ran);
		monster[i]->set_Pos(ranX, ranY);
		monster[i]->printPos();
		cout << endl;
	}
	cout << endl;
	Map01[0]->drawMap();
	cout << endl;
	cout << "Enter.....For Deal Damage To All Monster By 1 Point";
	int startGame = 0;
	//while (true)
	{
		//getchar();
		ClearScreen();
		if (startGame <= 0)
		{
			for (int i = 0; i < MaxNumberOfMonster; i++)
			{
				if (monster[i]->monsterGetDamaged(1) <= 0) // Monster HP - 1
				{
					Map01[0]->setObjInMap(monster[i]->get_Pos(0), monster[i]->get_Pos(1), -1);

					monster[i]->initiation(monster[i]->get_MonsterType(), i, monster);
					do {
						ranX = rand() % Map01[0]->getLength(0);
						ranY = rand() % Map01[0]->getLength(1);
					} while (Map01[0]->getObjInMap(ranX, ranY) != -1);
					Map01[0]->setObjInMap(ranX, ranY, monster[i]->get_MonsterType());
					monster[i]->set_Pos(ranX, ranY);
					monster[i]->printPos();
					cout << endl;

				}
			}
		}
		cout << endl;
		Map01[0]->drawMap();
		cout << endl;
		cout << "Enter.....For Deal Damage To All Monster By 1 Point";
		startGame -= 1;
	}

	delete Map01[0];
	return 0;
}

