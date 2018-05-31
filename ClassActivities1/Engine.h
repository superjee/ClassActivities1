#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H

#include <Windows.h>
#include <iostream>

enum EngineState
{
	Invalid,
	Constructing,
	Initializing,
	Running,
	ShuttingDown,
	Destroying
};

class Engine
{
public:
	Engine();
	~Engine();
	int runLoop();
	static EngineState GetEngineState() { return m_EngingState; }

private:

	int intialize();
	int draw();
	int update();
	int shutDown();


	static EngineState m_EngingState;

};
#endif //_ENGINE_H
