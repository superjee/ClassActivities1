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
#include "Monster.h"
#include "Player.h"
#include "WorldMap.h"
#include "ReadInFo_Monster.h"
#include "SpawnPoint.h"

#define MAX_NUMBER_OF_MONSTER 100
#define MAX_TYPE_OF_MONSTER 2
#define RandomTypeMonster rand() % MAX_TYPE_OF_MONSTER + 1
#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27
#define KB_W 119
#define KB_A 97
#define KB_S 115
#define KB_D 100

#define MAP_ID 0
#define PLAYER_ID 999
#define BATTLE_ID 1000
#define START_HP 500
#define START_ATK 75
#define START_SWING 7
const int INFO_MONSTER_ID = 0;

#define MONSTER_STATUS_POS 40

std::vector<WorldMap*> Map;
std::vector<std::shared_ptr<Player>> player;
std::vector<std::shared_ptr<ReadInFo_Monster>> readInFo_Monster;
std::vector<std::shared_ptr<SpawnPoint>> spawnPoint;
std::vector<std::shared_ptr<Monster>> monster;


int ran = -1;
int ranX = -1;
int ranY = -1;
int startGame = 0;
int input;
bool QuitGame = false;
bool isInput = false;
int KB_code = 0;
bool isBattle = false;
int battleTick = 0;
// function prototypes
void gotoxy(int x, int y);
void moveUP();
void moveDOWN();
void moveLEFT();
void moveRIGHT();
void playerMove(int currentX, int currentY, int nextX, int nextY);
void printStartGame();
void printPlayerStatus(bool start = false);
void playerInput();
void keyboardInput();
void initGame(bool start = true);
void printMonsterStatus(bool start = false);
void deleteMonsterStatus();

void clearScreen()
{
	static HANDLE hStdout = NULL;
	static CONSOLE_SCREEN_BUFFER_INFO csbi;
	const COORD startCoords = { 0,0 };
	DWORD dummy;

	if (!hStdout)
	{
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdout, &csbi);
	}

	FillConsoleOutputCharacter(hStdout,
		' ',
		csbi.dwSize.X * csbi.dwSize.Y,
		startCoords,
		&dummy);
	gotoxy(0, 0);
	/*HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	///Get the number of cells in the current buffer 
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	// Fill the entire buffer with spaces 
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	// Fill the entire buffer with the current colors and attributes 
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	// Move the cursor home 
	SetConsoleCursorPosition(hStdOut, homeCoords);*/
}
bool quitButtonPressed()
{
	input = _getch();
	if (input == 27)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void updateGame()
{
	startGame++;
	//clearScreen();
	//gotoxy(47, 0);
	//std::cout << "       ";
	//gotoxy(34, 0);
	//std::cout << "TIME : " << startGame << " | "<< KB_code;

	if (isInput)
	{
		isInput = false;
		printPlayerStatus();
	}

	if (isBattle)
	{
		battleTick++;
		if (battleTick >= 10)
		{
			//Battle
			battleTick = 0;
			if (monster[Map[MAP_ID]->getOldObj()]->monsterGetDamaged(player[0]->get_Atk()) <= 0)
			{
				isBattle = false;
				Map[MAP_ID]->setObjInMap(player[0]->get_Pos(WorldMap_X), player[0]->get_Pos(WorldMap_Y), PLAYER_ID);
				Map[MAP_ID]->drawObjInMap(player[0]->get_Pos(WorldMap_X), player[0]->get_Pos(WorldMap_Y), PLAYER_ID, player[0]->get_PlayerSymbolic());
				playerMove(player[0]->get_Pos(WorldMap_X), player[0]->get_Pos(WorldMap_Y), 
					player[0]->get_Pos(WorldMap_X), player[0]->get_Pos(WorldMap_Y));

				
			}
			else if (player[0]->getDamaged(monster[Map[MAP_ID]->getOldObj()]->get_Atk()) <= 0)
			{
				//Game Over
				isBattle = false;
				clearScreen();
				initGame(false);
			}
			printPlayerStatus();
			printMonsterStatus();
		}
	}
	else
	{
		battleTick = 0;
		deleteMonsterStatus();
	}

	Sleep(50);
	KB_code = NULL;
}

int main()
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//LoadData
	readInFo_Monster.push_back(std::make_shared<ReadInFo_Monster>());

	//SetSpawn
	spawnPoint.push_back(make_shared<SpawnTo<Monster>>());
	spawnPoint.push_back(make_shared<SpawnTo<zombie>>());
	spawnPoint.push_back(make_shared<SpawnTo<Orc>>());

	initGame();
	while (!QuitGame)
	{
		keyboardInput();
		updateGame();
	}

	delete Map[MAP_ID];
	return 0;
}

void gotoxy(int x, int y)
{
	static HANDLE hStdout = NULL;
	COORD coord;

	coord.X = (short)x;
	coord.Y = (short)y;

	if (!hStdout)
	{
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	SetConsoleCursorPosition(hStdout, coord);
}

void moveUP()
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
}

void moveDOWN()
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
}

void moveLEFT()
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
}

void moveRIGHT()
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
}

void playerMove(int currentX, int currentY, int nextX, int nextY)
{
	if (isBattle && Map[MAP_ID]->getObjInMap(nextX, nextY) == Map[MAP_ID]->OBJ_empty) // เดินออกไปช่องว่างขณะสู้อยู่
	{
		isBattle = false;
		Map[MAP_ID]->setObjInMap(currentX, currentY, Map[MAP_ID]->getOldObj());
		Map[MAP_ID]->drawObjInMap(currentX, currentY, Map[MAP_ID]->getOldObj(),monster[Map[MAP_ID]->getOldObj()]->get_MonsterSymbolic());

		Map[MAP_ID]->setObjInMap(nextX, nextY, PLAYER_ID);
		Map[MAP_ID]->drawObjInMap(nextX, nextY, PLAYER_ID, player[0]->get_PlayerSymbolic());

		player[0]->set_Pos(nextX, nextY);
	}
	else if (isBattle && Map[MAP_ID]->getObjInMap(nextX, nextY) != Map[MAP_ID]->OBJ_empty  && Map[MAP_ID]->getObjInMap(nextX, nextY) != PLAYER_ID) // เดินออกไปหามอนอีกตัวขณะสู้อยู่
	{
		//HIT MONSTER
		isBattle = true;
		Map[MAP_ID]->setObjInMap(currentX, currentY, Map[MAP_ID]->getOldObj());
		Map[MAP_ID]->drawObjInMap(currentX, currentY, Map[MAP_ID]->getOldObj(), monster[Map[MAP_ID]->getOldObj()]->get_MonsterSymbolic());
		Map[MAP_ID]->setOldObj(Map[MAP_ID]->getObjInMap(nextX, nextY));
		////////////
		Map[MAP_ID]->setObjInMap(nextX, nextY, BATTLE_ID);
		Map[MAP_ID]->drawObjInMap(nextX, nextY, BATTLE_ID, Map[MAP_ID]->OBJ_BATTLE);

		player[0]->set_Pos(nextX, nextY);
		printMonsterStatus(true);
	}
	else if (Map[MAP_ID]->getObjInMap(nextX, nextY) == Map[MAP_ID]->OBJ_empty)
	{
		isBattle = false;
		Map[MAP_ID]->setObjInMap(currentX, currentY, Map[MAP_ID]->OBJ_empty);
		Map[MAP_ID]->drawObjInMap(currentX, currentY, Map[MAP_ID]->OBJ_empty);

		Map[MAP_ID]->setObjInMap(nextX, nextY, PLAYER_ID);
		Map[MAP_ID]->drawObjInMap(nextX, nextY, PLAYER_ID, player[0]->get_PlayerSymbolic());

		player[0]->set_Pos(nextX, nextY);
	}
	else if (Map[MAP_ID]->getObjInMap(nextX, nextY) != Map[MAP_ID]->OBJ_empty && Map[MAP_ID]->getObjInMap(nextX, nextY) != PLAYER_ID)
	{
		//HIT MONSTER
		isBattle = true;
		Map[MAP_ID]->setObjInMap(currentX, currentY, Map[MAP_ID]->OBJ_empty);
		Map[MAP_ID]->drawObjInMap(currentX, currentY, Map[MAP_ID]->OBJ_empty);
		Map[MAP_ID]->setOldObj(Map[MAP_ID]->getObjInMap(nextX, nextY));
		////////////
		Map[MAP_ID]->setObjInMap(nextX, nextY, BATTLE_ID);
		Map[MAP_ID]->drawObjInMap(nextX, nextY, BATTLE_ID, Map[MAP_ID]->OBJ_BATTLE);

		player[0]->set_Pos(nextX, nextY);
		printMonsterStatus(true);
	}
}

void printStartGame()
{
	std::cout << "/////////////                                                    //////////////" << std::endl;
	std::cout << "/                                                                             /" << std::endl;
	std::cout << "/                              Links To Fantasy                               /" << std::endl;
	std::cout << "/                             by Tanapat Yatana                               /" << std::endl;
	std::cout << "/                Zombie base Attack  : 7 - 13  (10,3)  HP : 100               /" << std::endl;
	std::cout << "/                Orc    base Attack  : 23 - 37 (30,7)  HP : 500               /" << std::endl;
	std::cout << "/                                                                             /" << std::endl;
	std::cout << "///////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
}

void initGame(bool start)
{
	startGame = 0;
	if (start)srand((unsigned int)time(NULL));
	if (start)Map.push_back(new WorldMap());
	Map[MAP_ID]->initiation();

	printStartGame();
	//ADD Player
	if (start)player.push_back(std::make_shared<Player>());
	player[0]->initiation(START_HP, START_ATK, START_SWING);
	ranX = rand() % Map[MAP_ID]->getLength(WorldMap_X);
	ranY = rand() % Map[MAP_ID]->getLength(WorldMap_Y);
	Map[MAP_ID]->setObjInMap(ranX, ranY, PLAYER_ID);
	player[0]->set_Pos(ranX, ranY);

	printPlayerStatus(true);

	//ADD Monster
	for (int i = 0; i < MAX_NUMBER_OF_MONSTER; i++)
	{
		ran = RandomTypeMonster;
		switch (ran) {
		case df_mon::Mon_ZOMBIE:
			ran = rand() % readInFo_Monster[INFO_MONSTER_ID]->get_MaxVariance(df_mon::Mon_ZOMBIE);
			monster.push_back(spawnPoint[df_mon::Mon_ZOMBIE]->spawn(ran));
			monster[i]->initiation(readInFo_Monster[INFO_MONSTER_ID]);
			break;
		case df_mon::Mon_ORC:
			ran = rand() % readInFo_Monster[INFO_MONSTER_ID]->get_MaxVariance(df_mon::Mon_ORC);
			monster.push_back(spawnPoint[df_mon::Mon_ORC]->spawn(ran));
			monster[i]->initiation(readInFo_Monster[INFO_MONSTER_ID]);
			break;
		default:
			std::cout << "error Monster::init >>> type not match" << std::endl;
		}
		do {
			ranX = rand() % Map[MAP_ID]->getLength(WorldMap_X);
			ranY = rand() % Map[MAP_ID]->getLength(WorldMap_Y);
		} while (Map[MAP_ID]->getObjInMap(ranX, ranY) != Map[MAP_ID]->OBJ_empty);
		Map[MAP_ID]->setObjInMap(ranX, ranY, i);
		monster[i]->set_Pos(ranX, ranY);
	}

	Map[MAP_ID]->drawMapBox();
	//drawPlayer
	Map[MAP_ID]->drawObjInMap(player[0]->get_Pos(WorldMap_X),
		player[0]->get_Pos(WorldMap_Y),
		PLAYER_ID,
		player[0]->get_PlayerSymbolic());
	//drawMonster
	for (int i = 0; i < MAX_NUMBER_OF_MONSTER; i++)
	{
		Map[MAP_ID]->drawObjInMap(monster[i]->get_Pos(WorldMap_X),
			monster[i]->get_Pos(WorldMap_Y),
			i,
			monster[i]->get_MonsterSymbolic());
	}

}

void playerInput()
{
	if (input == 0 || input == 224)
	{
		switch (_getch())
		{
		case 72: //Up Arrow
			std::cout << "\n UP";
			break;
		case 80: //Down Arrow
			std::cout << "\n DOWN";
			break;
		case 75: //Left Arrow
			std::cout << "\n LEFT";
			break;
		case 77: //Right Arrow
			std::cout << "\n RIGHT";
			break;
		}
	}
}

void keyboardInput()
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

}

void printPlayerStatus(bool start)
{
	int setX = 22;
	int setY = Map[MAP_ID]->getEndPosY();
	gotoxy(NULL, setY);
	if (!start)
	{
		gotoxy(setX, Map[MAP_ID]->getEndPosY());
		std::cout << "          ";
	}
	gotoxy(NULL, setY);
	if (start)
	std::cout << "  " << static_cast<char>(player[0]->get_PlayerSymbolic()) << " Player Position ";
	gotoxy(setX, setY);
	std::cout <<"(" << player[0]->get_Pos(WorldMap_X) << "," << player[0]->get_Pos(WorldMap_Y) << ")";

	setY++;
	gotoxy(NULL, setY);
	if (!start)
	{
		gotoxy(setX, setY);
		std::cout << "          ";
	}
	gotoxy(NULL, setY);
	if (start)
	std::cout << "  " << static_cast<char>(player[0]->get_PlayerSymbolic()) <<" HP";
	gotoxy(setX, setY);
	std::cout << player[0]->get_HP();

	setY++;
	if (start)
	{
		gotoxy(NULL, setY);
		std::cout << "  " << static_cast<char>(player[0]->get_PlayerSymbolic()) << " ATK";
		gotoxy(setX, setY);
		std::cout << player[0]->get_AtkMin() << " - " << player[0]->get_AtkMax();
	}

}

void printMonsterStatus(bool start)
{
	gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY());
	std::cout << "HIT MONSTER ID " << Map[MAP_ID]->getOldObj() << "  "; monster[Map[MAP_ID]->getOldObj()]->printType();
	gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 1);
	std::cout << "                                       ";
	gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 1);
	std::cout << "HP " << monster[Map[MAP_ID]->getOldObj()]->get_HP();
	gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 2);
	std::cout << "                                       ";
	if (start == false)
	{
		gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 2);
		std::cout << "ATK " << monster[Map[MAP_ID]->getOldObj()]->get_atkLast();
	}

}

void deleteMonsterStatus()
{
	gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY());
	std::cout << "                                       ";
	gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY()+1);
	std::cout << "                                       ";
	gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY()+2);
	std::cout << "                                       ";
}