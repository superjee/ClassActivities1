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
int Engine::runLoop(WorldClock &p_clock)
{
	if (!this->intialize())
		return 1;

	//srand((unsigned int)time(NULL));//srand(GetTickCount());

	m_EngingState = EngineState::Running;
	while (m_EngingState == EngineState::Running)
	{
		p_clock.setfristTime();
		this->update();
		p_clock.setDeltaTime();
		pUtility->GoToXY(0, 45);
		cout << "                           ";
		pUtility->GoToXY(0, 45);
		cout << endl << "clock : " << p_clock.getDeltaTimeInMilliseconds();
		//this->draw();
	}

	if (!this->shutDown())
		return 1;

	
	return 0;
}

//Private Methods
int Engine::intialize()
{
	m_EngingState = EngineState::Initializing;
	//
	Engine::pUtility = std::make_shared<Utility>();
	Engine::pGamePlay = std::make_shared<my_game::GamePlay>();

	return true;
}

int Engine::draw()
{
	return true;
}

int Engine::update()
{
	int keyCode = pUtility->KeyboardInput();
	if (keyCode == KeyboardInput::EXIT)
	{
		m_EngingState = EngineState::ShuttingDown;
	}
	else
	{
		Engine::pGamePlay->getInput(keyCode);
	}
	Engine::pGamePlay->updateGame();
	

	return true;
}

int Engine::shutDown()
{
	m_EngingState = EngineState::ShuttingDown;
	return true;
}
