#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>     
#include <crtdbg.h>
#include <iostream>
#include "Engine.h"
#include "Logger.h"
#include "Vec2i.hpp"

using namespace std;
using namespace math;

int main()
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	WorldClock worldClock;

	auto _GamePlay = std::make_shared<my_game::GamePlay>();
	auto _AutonomousCar = std::make_shared<my_cargame::AutonomousCar>();

	auto pEngine = std::make_shared<Engine>();
	int result = pEngine->runLoop(worldClock, _AutonomousCar);
	return result;
															  
	//Debug
	/*nlohmann::json tt;
	Utility::ReadInfo_json("car_properties.json",tt);
	std::cout << endl << tt.dump();*/
	//cout << endl;
	//Logger::Get().log("this is my data");
	//Logger::Get().log("this is my data");
	//cout << endl << "clock : " <<a.getDeltaTimeInMilliseconds();
	/*
	Vec2i v1(-12 ,16);
	Vec2i v2(12, 9);
	Vec2i v3(2, 2);
	Vec2i v4(4, 4);
	v1.print();
	v2.print();
	v3.print();
	//v3.normalized();
	v3.print();
	v4.print();
	//v3.multiply(2);
	//v3.print();
	cout << "angle between v3(2, 2): v4(4, 4) = " <<v3.angle(v4) << endl;
	//cout << v1.dot(v2) << endl;
	//cout << Vec2i::dot(v1, v2) <<endl;

	*/
	



	getchar();
	return 0;
}
