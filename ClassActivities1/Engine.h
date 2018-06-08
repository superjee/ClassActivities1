#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H

#include <Windows.h>
#include <memory>
#include <iostream>
#include "Utility.h"
#include "WorldClock.hpp"
#include "Grid2D.h"

#include "GamePlay.h"
#include "AutonomousCar.h"

enum EngineState
{
	Invalid,
	Constructing,
	Initializing,
	Running,
	ShuttingDown,
	Destroying
};
enum System
{
	GamePlay,
	AutonomousCar
};
class Engine final
{
public:
	Engine();
	~Engine();
	int runLoop(WorldClock &p_clock,int system);
	static EngineState GetEngineState() { return m_EngingState; }

	//std::shared_ptr<my_game::GamePlay> pGamePlay;

private:
	int intialize(int system);
	int draw();
	int update(int system);
	int shutDown();

	static EngineState m_EngingState;

};
#endif //_ENGINE_H
