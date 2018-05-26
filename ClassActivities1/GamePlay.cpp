#include "GamePlay.h"
using namespace my_game;
GamePlay::GamePlay()
{
}


GamePlay::~GamePlay()
{
}

void my_game::GamePlay::clearScreen()
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
}

void my_game::GamePlay::updateGame()
{
	startGame++;

	gotoxy(45, 0);
	std::cout << "       ";
	gotoxy(34, 0);
	std::cout << "Day : " << day << " | " << hour;

	// OneGameStep
	if (startGame % 10 == 0) 
	{
		hour++;
		if (hour >= 24)
		{
			hour = 0;
			day++;
			monsterGetStronger();
		}
	}

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

void my_game::GamePlay::initGame(bool start)
{
	startGame = 0;
	if (start) {
		srand((unsigned int)time(NULL));
		loadData();
		declareVariableOneTime();
	}
	//Map initiation
	Map[MAP_ID]->initiation();
	//Player initiation
	player[0]->initiation(START_HP, START_ATK, START_SWING);
	ranX = rand() % Map[MAP_ID]->getLength(WorldMap_X);
	ranY = rand() % Map[MAP_ID]->getLength(WorldMap_Y);
	Map[MAP_ID]->setObjInMap(ranX, ranY, PLAYER_ID);
	player[0]->set_Pos(ranX, ranY);
	//Monster initiation
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

	drawGame();
}

void my_game::GamePlay::loadData()
{
	readInFo_Monster.push_back(std::make_shared<ReadInFo_Monster>());
}

void my_game::GamePlay::declareVariableOneTime()
{
	//Map
	Map.push_back(make_shared<WorldMap>());//new WorldMap()
	//SpawnPoint
	spawnPoint.push_back(make_shared<SpawnTo<Monster>>());
	spawnPoint.push_back(make_shared<SpawnTo<zombie>>());
	spawnPoint.push_back(make_shared<SpawnTo<Orc>>());
	//Player
	player.push_back(std::make_shared<Player>());
}

void my_game::GamePlay::drawGame()
{
	printStartGame();
	printPlayerStatus(true);
	//drawMapBox
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

void my_game::GamePlay::gotoxy(int x, int y)
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

void my_game::GamePlay::printStartGame()
{
	std::cout << "/////////////                                                    //////////////" << std::endl;
	std::cout << "/                                                                             /" << std::endl;
	std::cout << "/                              Links To Fantasy                               /" << std::endl;
	std::cout << "/                             by Tanapat Yatana                               /" << std::endl;
	//std::cout << "/                Zombie base Attack  : 7 - 13  (10,3)  HP : 100               /" << std::endl;
	//std::cout << "/                Orc    base Attack  : 23 - 37 (30,7)  HP : 500               /" << std::endl;
	std::cout << "/                                                                             /" << std::endl;
	std::cout << "/                                                                             /" << std::endl;
	std::cout << "/                                                                             /" << std::endl;
	std::cout << "///////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
}

void my_game::GamePlay::printPlayerStatus(bool start)
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
	std::cout << "(" << player[0]->get_Pos(WorldMap_X) << "," << player[0]->get_Pos(WorldMap_Y) << ")";

	setY++;
	gotoxy(NULL, setY);
	if (!start)
	{
		gotoxy(setX, setY);
		std::cout << "          ";
	}
	gotoxy(NULL, setY);
	if (start)
		std::cout << "  " << static_cast<char>(player[0]->get_PlayerSymbolic()) << " HP";
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

void my_game::GamePlay::monsterGetStronger()
{
	for (int i = 0; i < MAX_NUMBER_OF_MONSTER; i++)
	{
		if (monster[i]->get_HP() > 0)
		{
			monster[i]->monsters_stronger();
		}
	}
}

void my_game::GamePlay::playerMove(int currentX, int currentY, int nextX, int nextY)
{
	if (isBattle && Map[MAP_ID]->getObjInMap(nextX, nextY) == Map[MAP_ID]->OBJ_empty) // เดินออกไปช่องว่างขณะสู้อยู่
	{
		isBattle = false;
		Map[MAP_ID]->setObjInMap(currentX, currentY, Map[MAP_ID]->getOldObj());
		Map[MAP_ID]->drawObjInMap(currentX, currentY, Map[MAP_ID]->getOldObj(), monster[Map[MAP_ID]->getOldObj()]->get_MonsterSymbolic());

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

void my_game::GamePlay::printMonsterStatus(bool start)
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

void my_game::GamePlay::deleteMonsterStatus()
{
	gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY());
	std::cout << "                                       ";
	gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 1);
	std::cout << "                                       ";
	gotoxy(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 2);
	std::cout << "                                       ";
}