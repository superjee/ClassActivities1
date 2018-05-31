#include "Engine.h"

EngineState Engine::m_EngingState = EngineState::Invalid;

Engine::Engine()
{
	m_EngingState = EngineState::Constructing;
}
Engine::~Engine()
{
	m_EngingState = EngineState::Destroying;
}
//public Methods
int Engine::runLoop()
{
	if (!this->intialize())
		return 1;

	srand(GetTickCount());

	m_EngingState = EngineState::Running;
	while (m_EngingState == EngineState::Running)
	{
		this->update();
		this->draw();
	}

	if (!this->shutDown())
		return 1;

	return 0;
}

//Private Methods
int Engine::intialize()
{
	m_EngingState = EngineState::Initializing;
	return true;
}

int Engine::draw()
{
	return true;
}

int Engine::update()
{
	std::cout << "update" << std::endl;

	return true;
}

int Engine::shutDown()
{
	m_EngingState = EngineState::ShuttingDown;
	return true;
}
