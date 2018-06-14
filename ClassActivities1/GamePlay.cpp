#include "GamePlay.h"
using namespace my_game;
GamePlay::GamePlay()
{
	//initGame();
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
	pUtility.GoToXY(0,0);
}

void my_game::GamePlay::update()
{
	gametime++;

	pUtility.GoToXY(34, 0);
	std::cout << "        ";
	pUtility.GoToXY(36, 0);
	std::cout << day << " | " << hour;

	// OneGameStep
	if (gametime % 20 == 0) 
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

		tapGameEnd();

		printPlayerStatus();
	}

	if (isBattle)
	{
		oneTimes = true;

		tapGameStart();

		battleTick++;
		if (battleTick >= 10)
		{
			int speed = monster[Map[MAP_ID]->getOldObj()]->get_tapSpeed();
			int frequency = monster[Map[MAP_ID]->getOldObj()]->get_tapFrequency();
			//AddTapNote
			ran = rand() % 4;
			switch (ran) {
			case direction::LEFT:
				tapBattle_LEFT.push_back(make_shared<TapBattle>(ran, 0, speed, tapStartPosY + 28));
				break;
			case direction::UP:
				tapBattle_UP.push_back(make_shared<TapBattle>(ran, 0, speed, tapStartPosY + 28));
				break;
			case direction::DOWN:
				tapBattle_DOWN.push_back(make_shared<TapBattle>(ran, 0, speed, tapStartPosY + 28));
				break;
			case direction::RIGHT:
				tapBattle_RIGHT.push_back(make_shared<TapBattle>(ran, 0, speed, tapStartPosY + 28));
				break;
			}

			//Battle
			ran = rand() % 5+1;
			battleTick -= frequency*ran;

			printPlayerStatus();
			printMonsterStatus();
		}
	}
	else
	{
		if (oneTimes)
		{
			oneTimes = false;
			battleTick = 0;

			tapGameEnd();

			deleteMonsterStatus();
			pUtility.GoToXY(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY());
			cout << "End Tap Battle";
			//delete tap type (miss good cool perfect)
			pUtility.GoToXY(67, 8);
			std::cout << "       ";
			pUtility.GoToXY(68, 9);
			//Utility::GoToXY(68,9); edit 2/6/61
			std::cout << "        ";
		}
	}

	Sleep(25);
}

void my_game::GamePlay::init(bool start)
{
	gametime = 0;
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

void my_game::GamePlay::printStartGame()
{
	std::cout << "/////////////                                                    //////////////" << std::endl;
	std::cout << "/                                                                             /" << std::endl;
	std::cout << "/                              Links To Fantasy                               /" << std::endl;
	std::cout << "/                             by Tanapat Yatana                               /" << std::endl;
	std::cout << "/                                                                             /" << std::endl;
	std::cout << "/                                 TapBattle                                   /" << std::endl;
	std::cout << "/                                                                             /" << std::endl;
	std::cout << "///////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;

	pUtility.GoToXY(tapStartPosX, tapStartPosY);
	std::cout << static_cast<char>(TapBattle::symbolic::LEFT);
	pUtility.GoToXY(tapStartPosX+3, tapStartPosY);
	std::cout << static_cast<char>(TapBattle::symbolic::UP);
	pUtility.GoToXY(tapStartPosX+6, tapStartPosY);
	std::cout << static_cast<char>(TapBattle::symbolic::DOWN);
	pUtility.GoToXY(tapStartPosX+9, tapStartPosY);
	std::cout << static_cast<char>(TapBattle::symbolic::RIGHT);


	pUtility.GoToXY(tapStartPosX - 2, tapStartPosY + 1);
	std::cout << ">            <";
	pUtility.GoToXY(tapStartPosX-2, tapStartPosY + 2);
	std::cout << "> ---------- <";
	pUtility.GoToXY(tapStartPosX - 2, tapStartPosY + 3);
	std::cout << ">            <";
}

void my_game::GamePlay::printPlayerStatus(bool start)
{
	int setX = 22;
	int setY = Map[MAP_ID]->getEndPosY();
	pUtility.GoToXY(NULL, setY);
	if (start)
	{
		pUtility.GoToXY(setX, Map[MAP_ID]->getEndPosY());
		std::cout << "           ";
	}
	pUtility.GoToXY(NULL, setY);
	if (start)
		std::cout << "  " << static_cast<char>(player[0]->get_PlayerSymbolic()) << " Player Position ";
	pUtility.GoToXY(setX, setY);
	std::cout << "(" << player[0]->get_Pos(WorldMap_X) << "," << player[0]->get_Pos(WorldMap_Y) << ")";

	setY++;
	pUtility.GoToXY(NULL, setY);
	if (start)
	{
		pUtility.GoToXY(setX, setY);
		std::cout << "          ";
	}
	pUtility.GoToXY(NULL, setY);
	if (start)
		std::cout << "  " << static_cast<char>(player[0]->get_PlayerSymbolic()) << " HP";
	pUtility.GoToXY(setX, setY);
	std::cout << player[0]->get_HP();

	setY++;
	if (start)
	{
		pUtility.GoToXY(NULL, setY);
		std::cout << "  " << static_cast<char>(player[0]->get_PlayerSymbolic()) << " ATK";
		pUtility.GoToXY(setX, setY);
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
	pUtility.GoToXY(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY());
	std::cout << "HIT MONSTER ID " << Map[MAP_ID]->getOldObj() << "  "; monster[Map[MAP_ID]->getOldObj()]->printType();
	pUtility.GoToXY(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 1);
	std::cout << "                                       ";
	pUtility.GoToXY(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 1);
	std::cout << "HP " << monster[Map[MAP_ID]->getOldObj()]->get_HP();
	pUtility.GoToXY(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 2);
	std::cout << "                                       ";
	if (start == false)
	{
		pUtility.GoToXY(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 2);
		std::cout << "ATK " << monster[Map[MAP_ID]->getOldObj()]->get_atkLast();
	}

}

void my_game::GamePlay::deleteMonsterStatus()
{
	pUtility.GoToXY(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY());
	std::cout << "                                       ";
	pUtility.GoToXY(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 1);
	std::cout << "                                       ";
	pUtility.GoToXY(MONSTER_STATUS_POS, Map[MAP_ID]->getEndPosY() + 2);
	std::cout << "                                       ";
}

void my_game::GamePlay::moveUP()
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

void my_game::GamePlay::moveDOWN()
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

void my_game::GamePlay::moveLEFT()
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

void my_game::GamePlay::moveRIGHT()
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

void my_game::GamePlay::getInput(int p_input)
{
	switch (p_input)
	{
	case KeyboardInput::KB_LEFT:
		tapKey(direction::LEFT);
		break;
	case KeyboardInput::KB_RIGHT:
		tapKey(direction::RIGHT);
		break;
	case KeyboardInput::KB_UP:
		tapKey(direction::UP);
		break;
	case KeyboardInput::KB_DOWN:
		tapKey(direction::DOWN);
		break;
	case KeyboardInput::KB_W:
		isInput = true;
		moveUP();
		break;
	case KeyboardInput::KB_A:
		isInput = true;
		moveLEFT();
		break;
	case KeyboardInput::KB_S:
		isInput = true;
		moveDOWN();
		break;
	case KeyboardInput::KB_D:
		isInput = true;
		moveRIGHT();
		break;
	}
}

void my_game::GamePlay::playerTakeDamage()
{
	if (player[0]->getDamaged(monster[Map[MAP_ID]->getOldObj()]->get_Atk()) <= 0)
	{
		//Game Over
		isBattle = false;
		clearScreen();
		init(false);
	}
}

void my_game::GamePlay::monsterTakeDamage()
{
	if (monster[Map[MAP_ID]->getOldObj()]->monsterGetDamaged(player[0]->get_Atk()) <= 0)
	{
		isBattle = false;
		Map[MAP_ID]->setObjInMap(player[0]->get_Pos(WorldMap_X), player[0]->get_Pos(WorldMap_Y), PLAYER_ID);
		Map[MAP_ID]->drawObjInMap(player[0]->get_Pos(WorldMap_X), player[0]->get_Pos(WorldMap_Y), PLAYER_ID, player[0]->get_PlayerSymbolic());
		playerMove(player[0]->get_Pos(WorldMap_X), player[0]->get_Pos(WorldMap_Y),
			player[0]->get_Pos(WorldMap_X), player[0]->get_Pos(WorldMap_Y));
	}
}

void my_game::GamePlay::tapGameUpdate(std::vector<std::shared_ptr<TapBattle>> &p_tapBattle)
{
	for (int i = 0; i < static_cast<int>(p_tapBattle.size()); i++)
	{
		//reset
		pUtility.GoToXY(tapStartPosX + (p_tapBattle[i]->Getdirection()*tapDistance), p_tapBattle[i]->tapY);
		if (p_tapBattle[i]->tapY == tapStartPosY + 2)
		{
			cout << "-";
		}
		else
		{
			cout << " ";
		}
		//update
		p_tapBattle[i]->TapUpdate();

		//miss
		if (p_tapBattle[i]->tapY == tapStartPosY)
		{
			timeToShow = timeToShowInfoTap;
			pUtility.GoToXY(67, 8);
			std::cout << "       ";
			pUtility.GoToXY(69, 8);
			std::cout << "miss";
			p_tapBattle.erase(p_tapBattle.begin());
			i--;
			playerTakeDamage();
		}
		else
		{
			pUtility.GoToXY(tapStartPosX + (p_tapBattle[i]->Getdirection()*tapDistance), p_tapBattle[i]->tapY);
			cout << static_cast<char>(p_tapBattle[i]->GetSym());
		}
	}
}

void my_game::GamePlay::tapGameUpdateEnd(std::vector<std::shared_ptr<TapBattle>>& p_tapBattle)
{
	for (int i = 0; i < static_cast<int>(p_tapBattle.size()); i++)
	{
		tapDelete(p_tapBattle,i);
	}
}

void my_game::GamePlay::tapGameStart()
{
	tapGameUpdate(tapBattle_LEFT);
	tapGameUpdate(tapBattle_UP);
	tapGameUpdate(tapBattle_DOWN);
	tapGameUpdate(tapBattle_RIGHT);

	timeToShow -= 1;
	if (timeToShow <= 0)
	{
		timeToShow = timeToShowInfoTap;
		pUtility.GoToXY(67, 8);
		std::cout << "       ";
		pUtility.GoToXY(68, 9);
		std::cout << "        ";
	}

}

void my_game::GamePlay::tapGameEnd()
{
	tapGameUpdateEnd(tapBattle_LEFT);
	tapGameUpdateEnd(tapBattle_UP);
	tapGameUpdateEnd(tapBattle_DOWN);
	tapGameUpdateEnd(tapBattle_RIGHT);
	pUtility.GoToXY(tapStartPosX - 2, tapStartPosY + 2);
	std::cout << "> ---------- <";
}

void my_game::GamePlay::tapDelete(std::vector<std::shared_ptr<TapBattle>>& p_tapBattle, int &p_i)
{
	pUtility.GoToXY(tapStartPosX + (p_tapBattle[p_i]->Getdirection()*tapDistance), p_tapBattle[p_i]->tapY);
	cout << " ";
	p_tapBattle.erase(p_tapBattle.begin());
	p_i--;
}

void my_game::GamePlay::tapKey(int p_direction)
{
	if (isBattle)
	{
		switch (p_direction) {
		case direction::LEFT:
			tapKey_calculate(tapBattle_LEFT, direction::LEFT);
			break;
		case direction::UP:
			tapKey_calculate(tapBattle_UP, direction::UP);
			break;
		case direction::DOWN:
			tapKey_calculate(tapBattle_DOWN, direction::DOWN);
			break;
		case direction::RIGHT:
			tapKey_calculate(tapBattle_RIGHT, direction::RIGHT);
			break;
		}
	}
}

void my_game::GamePlay::tapKey_calculate(std::vector<std::shared_ptr<TapBattle>>& p_tapBattle,int num)
{
	if (static_cast<int>(p_tapBattle.size()) == 0)
	{
		//miss
		pUtility.GoToXY(67, 8);
		std::cout << "       ";
		pUtility.GoToXY(69, 8);
		std::cout << "miss";

		playerTakeDamage();

		timeToShow = timeToShowInfoTap;
	}
	else
	for (int i = 0; i < static_cast<int>(p_tapBattle.size()); i++)
	{
		if (p_tapBattle[i]->tapY == tapStartPosY + 1)
		{
			//cool
			pUtility.GoToXY(67, 8);
			std::cout << "       ";
			pUtility.GoToXY(69, 8);
			std::cout << "cool";
			tapDelete(p_tapBattle, i);

			monsterTakeDamage();

			pUtility.GoToXY(68, 9);
			std::cout << "        ";
			pUtility.GoToXY(68, 9);
			std::cout << "HP " << monster[Map[MAP_ID]->getOldObj()]->get_HP();

			timeToShow = timeToShowInfoTap;
			break;
		}
		else if (p_tapBattle[i]->tapY == tapStartPosY + 2)
		{
			//perfect
			pUtility.GoToXY(67, 8);
			std::cout << "       ";
			pUtility.GoToXY(67, 8);
			std::cout << "perfect";
			tapDelete(p_tapBattle, i);
			pUtility.GoToXY(tapStartPosX + (num*tapDistance), tapStartPosY + 2);
			cout << "-";

			monsterTakeDamage();

			pUtility.GoToXY(68, 9);
			std::cout << "        ";
			pUtility.GoToXY(68, 9);
			std::cout << "HP " << monster[Map[MAP_ID]->getOldObj()]->get_HP();

			timeToShow = timeToShowInfoTap;
			break;
		}
		else if (p_tapBattle[i]->tapY == tapStartPosY + 3)
		{
			//good
			pUtility.GoToXY(67, 8);
			std::cout << "       ";
			pUtility.GoToXY(69, 8);
			std::cout << "good";
			tapDelete(p_tapBattle, i);

			monsterTakeDamage();

			pUtility.GoToXY(68, 9);
			std::cout << "        ";
			pUtility.GoToXY(68, 9);
			std::cout << "HP " << monster[Map[MAP_ID]->getOldObj()]->get_HP();



			timeToShow = timeToShowInfoTap;
			break;
		}
		else if (p_tapBattle[i]->tapY == tapStartPosY + 4)
		{
			//bad
			pUtility.GoToXY(67, 8);
			std::cout << "       ";
			pUtility.GoToXY(69, 8);
			std::cout << "bad";
			tapDelete(p_tapBattle, i);

			timeToShow = timeToShowInfoTap;
			break;
		}
		else if (p_tapBattle[i]->tapY == tapStartPosY + 5)
		{
			//miss
			pUtility.GoToXY(67, 8);
			std::cout << "       ";
			pUtility.GoToXY(69, 8);
			std::cout << "miss";
			tapDelete(p_tapBattle, i);

			playerTakeDamage();

			timeToShow = timeToShowInfoTap;
			break;
		}
		else
		{
			//miss
			pUtility.GoToXY(67, 8);
			std::cout << "       ";
			pUtility.GoToXY(69, 8);
			std::cout << "miss";

			playerTakeDamage();

			timeToShow = timeToShowInfoTap;
		}
	}


}
