#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H

#include <Windows.h>
#include <memory>
#include <iostream>
#include "Utility.h"
#include "WorldClock.hpp"
#include "Grid2D.h"

class SystemBase
{
public:
	virtual void init(bool) { std::cout << "SystemBase init\n"; Exit(); }
	virtual void update() { std::cout << "SystemBase update\n"; Exit(); }
	virtual void getInput(int) { std::cout << "SystemBase getInput\n"; Exit(); }
private:
	void Exit();
};

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
	int runLoop(WorldClock &p_clock,std::shared_ptr<SystemBase> system);
	static EngineState GetEngineState() { return m_EngingState; }
	static void EngineEND() { m_EngingState = EngineState::ShuttingDown;}
private:
	int intialize(std::shared_ptr<SystemBase> system);
	int draw();
	int update(std::shared_ptr<SystemBase> system);
	int shutDown();

	static EngineState m_EngingState;

};
#endif //_ENGINE_H