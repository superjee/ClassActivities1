#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>     
#include <crtdbg.h>
#include <iostream>
#include "Engine.h"
#include "Logger.h"

using namespace std;

int main()
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	WorldClock worldClock;

	auto _GamePlay = std::make_shared<my_game::GamePlay>();
	auto _AutonomousCar = std::make_shared<my_cargame::AutonomousCar>();

	auto pEngine = std::make_shared<Engine>();
	int result = pEngine->runLoop(worldClock, _AutonomousCar);//GamePlay
	
	/*nlohmann::json tt;
	Utility::ReadInfo_json("car_properties.json",tt);
	std::cout << endl << tt.dump();

	Utility::ReadInfo_json("car_properties.json", tt);
	std::cout << endl << tt.dump();*/
	//cout << endl;
	//Logger::Get().log("this is my data");
	//Logger::Get().log("this is my data");
	//cout << endl << "clock : " <<a.getDeltaTimeInMilliseconds();
	getchar();
	return result;

}
