#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H

#include <Windows.h>
#include <memory>
#include <iostream>
#include "Utility.h"
#include "GamePlay.h"

enum EngineState
{
	Invalid,
	Constructing,
	Initializing,
	Running,
	ShuttingDown,
	Destroying
};

class Engine final
{
public:
	Engine();
	~Engine();
	int runLoop();
	static EngineState GetEngineState() { return m_EngingState; }

	std::shared_ptr<Utility> pUtility;
	std::shared_ptr<my_game::GamePlay> pGamePlay;

private:
	int intialize();
	int draw();
	int update();
	int shutDown();

	static EngineState m_EngingState;

};
#endif //_ENGINE_H
