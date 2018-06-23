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

	/*WorldClock worldClock;

	auto _GamePlay = std::make_shared<my_game::GamePlay>();
	auto _AutonomousCar = std::make_shared<my_cargame::AutonomousCar>();

	auto pEngine = std::make_shared<Engine>();
	int result = pEngine->runLoop(worldClock, _AutonomousCar);
	return result;*/
															  
	//Debug
	/*nlohmann::json tt;
	Utility::ReadInfo_json("car_properties.json",tt);
	std::cout << endl << tt.dump();*/
	//cout << endl;
	//Logger::Get().log("this is my data");
	//Logger::Get().log("this is my data");
	//cout << endl << "clock : " <<a.getDeltaTimeInMilliseconds();
	
	Vec2i v1(1 ,1);
	Vec2i v2(2, 2);
	Vec2i v3(3, 3);
	Vec2i v4(4, 4);
	v1.print();
	v2.print();
	v3.print();
	v4.print();
	cout << "angle between v3(3, 3): v4(4, 4) = " <<v3.angle(v4) << endl;
	v3.multiply(2);
	cout << "v3.multiply(2) = "; v3.print();
	v3.divide(2);
	cout << "v3.divide(2) = "; v3.print();
	cout << "v1.dot(v2) = " << v1.dot(v2) << endl;
	v2.normalized();
	cout << "v2.normalized() = "; v2.print();
	cout << endl << "=====================" << endl;
	Vec3 u1(1, 1,1);
	Vec3 u2(2, 2,2);
	Vec3 u3(3, 3,3);
	Vec3 u4(4, 4,4);
	u1.print();
	u2.print();
	u3.print();
	u4.print();
	cout << "u1.add(u1) = ";
	u1.add(u1); u1.print();
	cout << "u4.add(v1) = ";
	u4.add(v1); u4.print();
	cout << "v1.add(u3) = ";
	v1.add(u3); v1.print();

	getchar();
	return 0;
}
