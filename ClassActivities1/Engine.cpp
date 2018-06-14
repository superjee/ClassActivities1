#include "Engine.h"

EngineState Engine::m_EngingState = EngineState::Invalid;

int num = 0;

Engine::Engine()
{
	m_EngingState = EngineState::Constructing;
}
Engine::~Engine()
{
	m_EngingState = EngineState::Destroying;
}
//public Methods
int Engine::runLoop(WorldClock &p_clock, std::shared_ptr<SystemBase> system)
{
	if (!this->intialize(system))
		return 1;

	m_EngingState = EngineState::Running;
	while (m_EngingState == EngineState::Running)
	{
		p_clock.setfristTime();
		this->update(system);
		p_clock.setDeltaTime();
		/*Utility::GoToXY(0, 0);
		std::cout << "                           ";
		Utility::GoToXY(0, 0);
		std::cout << "" << p_clock.getDeltaTimeInMilliseconds();
		*/
		//this->draw();
	}

	if (!this->shutDown())
		return 1;

	
	return 0;
}

//Private Methods
int Engine::intialize(std::shared_ptr<SystemBase> system)
{
	m_EngingState = EngineState::Initializing;
	//system.push_back
	system->init(true);
	return true;
}

int Engine::draw()
{
	return true;
}

int Engine::update(std::shared_ptr<SystemBase> system)
{
	int keyCode = Utility::KeyboardInput();
	if (keyCode == KeyboardInput::EXIT)
	{
		m_EngingState = EngineState::ShuttingDown;
	}
	else
	{
		system->getInput(keyCode);
	}
	system->update();
	return true;
}

int Engine::shutDown()
{
	m_EngingState = EngineState::ShuttingDown;
	//Utility::ClearScreen();

	return true;
}

void SystemBase::Exit()
{
	Engine::EngineEND();
}
