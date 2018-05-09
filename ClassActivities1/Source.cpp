#include <iostream>
//#include <conio.h>
//#include <stdio.h>
#include <windows.h>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Monster.h"
//#include "zombie.h"
//#include "Orc.h"
#include "WorldMap.h"

using namespace std;
//Test up in Visual // can not push by Visual??? ,but can push by GitHub Desktop.

const int MaxNumberOfMonster = 100; //ค่าคงที่
//const int x_World = 30;
//const int y_World = 30;

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

int main()
{	
	//int WorldMap[x_World][y_World];
	/*HANDLE a;
	DWORD b;
	INPUT_RECORD c[1];
	if (HANDLE(a = GetStdHandle(0xfffffff6)) == INVALID_HANDLE_VALUE)
		return 1;
	while (1) {
		if (!ReadConsoleInput(a, c, 1, &b))
			return 1;
		for (DWORD i = 0; i<b; i++)
			if (c[i].EventType == 2) {
				if (c[i].Event.MouseEvent.dwButtonState & 0x0001)
					cout << "Left click\n";
				if (c[i].Event.MouseEvent.dwButtonState & 0x0002)
					cout << "Right click\n";
			}

		ClearScreen();
	}*/

	WorldMap *Map01 = new WorldMap();
	Map01->initiation();

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

	Monster *monster[MaxNumberOfMonster];

	for (int i = 0; i < MaxNumberOfMonster; i++)
	{
		ran = rand() % 2 + 1;
		monster[i]->initiation(ran, i, monster);
		do {
			ranX = rand() % Map01->getLength(0);
			ranY = rand() % Map01->getLength(1);
		} while (Map01->getObjInMap(ranX, ranY) != -1);
		Map01->setObjInMap(ranX, ranY, ran);
		monster[i]->set_Pos(ranX, ranY);
		monster[i]->printPos();
		cout << endl;
	}
	cout << endl;
	Map01->drawMap();
	cout << endl;
	cout << "Enter.....For Deal Damage To All Monster By 1 Point";
	int startGame = 0;
	while (true)
	{
		getchar();
		ClearScreen();
		if (startGame <= 0)
		{
			for (int i = 0; i < MaxNumberOfMonster; i++)
			{
				if (monster[i]->monsterGetDamaged(1) <= 0) // Monster HP - 1
				{
					Map01->setObjInMap(monster[i]->get_Pos(0), monster[i]->get_Pos(1), -1);

					monster[i]->initiation(monster[i]->get_MonsterType(), i, monster);
					do {
						ranX = rand() % Map01->getLength(0);
						ranY = rand() % Map01->getLength(1);
					} while (Map01->getObjInMap(ranX, ranY) != -1);
					Map01->setObjInMap(ranX, ranY, monster[i]->get_MonsterType());
					monster[i]->set_Pos(ranX, ranY);
					monster[i]->printPos();
					cout << endl;

				}
			}
		}
		cout << endl;
		Map01->drawMap();
		startGame -= 1;
		cout << endl;
		cout << "Enter.....For Deal Damage To All Monster By 1 Point";
	}





	return 0;
}

