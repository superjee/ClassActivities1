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
#include "TapBattle.h"
#include "Utility.h"

namespace my_game {
#define MAX_NUMBER_OF_MONSTER 100
#define MAX_TYPE_OF_MONSTER 2
#define RandomTypeMonster rand() % MAX_TYPE_OF_MONSTER + 1

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
		std::vector<std::shared_ptr<TapBattle>> tapBattle_LEFT;
		std::vector<std::shared_ptr<TapBattle>> tapBattle_UP;
		std::vector<std::shared_ptr<TapBattle>> tapBattle_DOWN;
		std::vector<std::shared_ptr<TapBattle>> tapBattle_RIGHT;
		//
		int ran = -1;
		int ranX = -1;
		int ranY = -1;
		int gametime = 0;
		bool isInput = false;
		bool isBattle = false;
		int battleTick = 0;
		int day = 1;
		int hour = 0;
		int tapStartPosX = 66;
		int tapStartPosY = 10;
		int tapDistance = 3;
		int timeToShowInfoTap = 25;
		int timeToShow = 0;

		bool oneTimes = false;
		Utility pUtility;
		enum direction { LEFT = 0, UP = 1, DOWN = 2, RIGHT = 3 };
		// function prototypes
		void clearScreen();
		void updateGame();
		void initGame(bool start = true);
		void loadData();
		void declareVariableOneTime();
		void drawGame();
		void printStartGame();
		void printPlayerStatus(bool start = true);
		void printMonsterStatus(bool start = false);
		void deleteMonsterStatus();
		void monsterGetStronger();
		void playerMove(int currentX, int currentY, int nextX, int nextY);
		void moveUP();
		void moveDOWN();
		void moveLEFT();
		void moveRIGHT();
		void getInput(int p_input);
		void playerTakeDamage();
		void monsterTakeDamage();
		void tapGameUpdate(std::vector<std::shared_ptr<TapBattle>> &p_tapBattle);
		void tapGameUpdateEnd(std::vector<std::shared_ptr<TapBattle>> &p_tapBattle);
		void tapGameStart();
		void tapGameEnd();
		void tapDelete(std::vector<std::shared_ptr<TapBattle>> &p_tapBattle , int &p_i);
		void tapKey(int di);
		void tapKey_calculate(std::vector<std::shared_ptr<TapBattle>> &p_tapBattle,int num);
	};
}