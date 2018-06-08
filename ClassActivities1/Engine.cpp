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
int Engine::runLoop(WorldClock &p_clock, int system)
{
	if (!this->intialize(system))
		return 1;

	m_EngingState = EngineState::Running;
	while (m_EngingState == EngineState::Running)
	{
		p_clock.setfristTime();
		this->update(system);
		p_clock.setDeltaTime();
		/*pUtility->GoToXY(0, 45);
		cout << "                           ";
		pUtility->GoToXY(0, 45);
		cout << endl << "clock : " << p_clock.getDeltaTimeInMilliseconds();*/

		//this->draw();
	}

	if (!this->shutDown())
		return 1;

	
	return 0;
}

//Private Methods
int Engine::intialize(int system)
{
	m_EngingState = EngineState::Initializing;

	switch (system)
	{
	case System::GamePlay:
		my_game::GamePlay::instance().initGame();
		break;
	case System::AutonomousCar:

		break;
	}

	return true;
}

int Engine::draw()
{
	return true;
}

int Engine::update(int system)
{
	int keyCode = Utility::KeyboardInput();
	if (keyCode == KeyboardInput::EXIT)
	{
		m_EngingState = EngineState::ShuttingDown;
	}
	else
	{
		switch (system)
		{
		case System::GamePlay:
			my_game::GamePlay::instance().getInput(keyCode);
			break;
		case System::AutonomousCar:

			break;
		}
	}

	switch (system)
	{
	case System::GamePlay:
		my_game::GamePlay::instance().updateGame();
		break;
	case System::AutonomousCar:

		break;
	}
	

	return true;
}

int Engine::shutDown()
{
	m_EngingState = EngineState::ShuttingDown;
	Utility::ClearScreen();

	return true;
}
