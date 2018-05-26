#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
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

namespace my_game {
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
#define MONSTER_STATUS_POS 40

const int INFO_MONSTER_ID = 0;

	class GamePlay
	{
	public:
		GamePlay();
		~GamePlay();
		std::vector<std::shared_ptr<WorldMap>> Map;
		std::vector<std::shared_ptr<Player>> player;
		std::vector<std::shared_ptr<ReadInFo_Monster>> readInFo_Monster;
		std::vector<std::shared_ptr<SpawnPoint>> spawnPoint;
		std::vector<std::shared_ptr<Monster>> monster;
		//

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
		int day = 1;
		int hour = 0;

		// function prototypes
		void clearScreen();
		void updateGame();
		void initGame(bool start = true);
		void loadData();
		void declareVariableOneTime();
		void drawGame();
		void gotoxy(int x, int y);
		void printStartGame();
		void printPlayerStatus(bool start = true);
		void printMonsterStatus(bool start = false);
		void deleteMonsterStatus();
		void monsterGetStronger();
		void playerMove(int currentX, int currentY, int nextX, int nextY);
	};
}