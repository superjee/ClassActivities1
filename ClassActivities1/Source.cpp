#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>     
#include <crtdbg.h>
#include <iostream>
#include "Engine.h"
#include "Logger.h"
#include "Vec2i.hpp"
//#include "Vec3.hpp"
//#include "Vec4.hpp"
#include "Mat4.h"

using namespace std;
using namespace mymath;

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
	
	/*Vec2<float> v1(1 ,1);
	Vec2<float> v2(2, 2);
	Vec2<float> v3(3, 3);
	Vec2<float> v4(4, 4);
	v1.print();
	v2.print();
	v3.print();
	v4.print();
	v3.add(v3); cout << "v3.add(v3) = "; v3.print();
	v3.subtract(Vec2<float>(3,3)); cout << "v3.subtract(Vec2<int>(3,3)) = "; v3.print();
	v3.multiply(2); cout << "v3.multiply(2) = "; v3.print();
	v3.divide(2); cout << "v3.divide(2) = "; v3.print();
	Vec2<float> v5 = v1+v2; cout << "v1+v2 = "; v5.print();
	Vec2<float> v6 = v2 - v1; cout << "v2-v1 = "; v6.print();
	cout << "angle between (0, 5): (5, 0) = " << Vec2<int>(0,5).angle(Vec2<int>(5, 0)) << endl;
	cout << "angle between (3, 3): (4, 4) = " << Vec2<float>(3, 3).angle(Vec2<float>(4, 4)) << endl;
	Vec2<float> v7(7, 7);
	Vec2<float> v8(8, 8);
	cout << "(7, 7)dot(8, 8) = " << v7.dot(v8) << endl;
	cout << "(7, 7)dot(8, 8) = " << Vec2<float>::dot(v7,v8) << endl;
	Vec2<float> v9(7, 7);
	Vec2<float> v10(7, 8);
	if (v7 == v9)
	{
		cout << "if ((7, 7) == (7, 7)) : true" << endl;
	}
	if (v7 != v10)
	{
		cout << "if ((7, 7) != (7, 8)) : true" << endl;
	}
	v9.normalized();
	cout << "v9.normalized()"; v9.print();

	///////////////////////////////////////
	
	Vec3<float> v3_1(1, 1,1);
	Vec3<float> v3_2(2, 2,2);
	Vec3<float> v3_3(3, 3,3);
	Vec3<float> v3_4(4, 4,4);
	v3_1.print();
	v3_2.print();
	v3_3.print();
	v3_4.print();
	v3_3.add(v3_3); cout << "v3_3.add(v3_3) = "; v3_3.print();
	v3_3.subtract(Vec3<float>(3, 3,3)); cout << "v3_3.subtract(Vec3<int>(3,3,3)) = "; v3_3.print();
	v3_3.multiply(2); cout << "v3_3.multiply(2) = "; v3_3.print();
	v3_3.divide(2); cout << "v3_3.divide(2) = "; v3_3.print();
	Vec3<float> v3_5 = v3_1 + v3_2; cout << "v3_1+v3_2 = "; v3_5.print();
	Vec3<float> v3_6 = v3_2 - v3_1; cout << "v3_2-v3_1 = "; v3_6.print();
	Vec3<float> v3_7(7, 7,7);
	Vec3<float> v3_8(8, 8,8);
	cout << "(7, 7,7)dot(8, 8,8) = " << v3_7.dot(v3_8) << endl;
	cout << "(7, 7,7)dot(8, 8,8) = " << Vec3<float>::dot(v3_7, v3_8) << endl;
	Vec3<float> v3_9(7, 7,7);
	Vec3<float> v3_10(7, 8,8);
	if (v3_7 == v3_9)
	{
		cout << "if ((7, 7,7) == (7, 7,7)) : true" << endl;
	}
	if (v3_7 != v3_10)
	{
		cout << "if ((7, 7,7) != (7, 8,8)) : true" << endl;
	}
	Vec3<float> v3_11(2, 3, 4);
	cout << "(2, 3,4)cross(5, 6,7) = "; v3_11.cross(Vec3<float>(5,6,7)); v3_11.print();
	v3_9.normalized();
	cout << "v3_9.normalized()"; v3_9.print();
	cout << "angle between (2, -4,-1): (0, 5,2) = " << Vec3<float>(2, -4,-1).angle(Vec3<float>(0, 5, 2))<< endl;
	///////////////////////////////////////
	Vec4<float> v4_1(1, 1, 1,1);
	Vec4<float> v4_2(2, 2, 2,2);
	Vec4<float> v4_3(3, 3, 3,3);
	Vec4<float> v4_4(4, 4, 4,4);
	v4_1.print();
	v4_2.print();
	v4_3.print();
	v4_4.print();
	v4_3.add(v4_3); cout << "v4_3.add(v4_3) = "; v4_3.print();
	v4_3.subtract(Vec4<float>(3, 3, 3,3)); cout << "v4_3.subtract(Vec4<int>(3,3,3,3)) = "; v4_3.print();
	v4_3.multiply(2); cout << "v3_3.multiply(2) = "; v4_3.print();
	v4_3.divide(2); cout << "v4_3.divide(2) = "; v4_3.print();
	Vec4<float> v4_5 = v4_1 + v4_2; cout << "v4_1+v4_2 = "; v4_5.print();
	Vec4<float> v4_6 = v4_2 - v4_1; cout << "v4_2-v4_1 = "; v4_6.print();
	Vec4<float> v4_7(7, 7, 7,7);
	Vec4<float> v4_8(8, 8, 8,8);
	cout << "(7, 7,7,7)dot(8, 8,8,8) = " << v4_7.dot(v4_8) << endl;
	cout << "(7, 7,7,7)dot(8, 8,8,8) = " << Vec4<float>::dot(v4_7, v4_8) << endl;
	Vec4<float> v4_9(7, 7, 7,7);
	Vec4<float> v4_10(7, 8, 8,8);
	if (v4_7 == v4_9)
	{
		cout << "if ((7, 7,7,7) == (7, 7,7,7)) : true" << endl;
	}
	if (v4_7 != v4_10)
	{
		cout << "if ((7, 7,7,7) != (7, 8,8,8)) : true" << endl;
	}
	v4_9.print();
	v4_9.normalized();
	cout << "v4_9.normalized()"; v4_9.print();*/

	Vec4<float> v4_1(1.0f, 2.0f, 3.0f, 4.0f);
	Vec4<float> v4_2(5, 6, 7, 8);
	Vec4<float> v4_3(9, 10, 11, 12);
	Vec4<float> v4_4(13, 14, 15, 16);

	float* a;
	float b = 10;
	a = &b;
	Mat4 testMat(v4_1, v4_2, v4_3, v4_4);
	Mat4 testMat2(v4_4, v4_3, v4_2, v4_1);
	cout << "Mat1" << endl;
	testMat.print();
	cout << "Mat2" << endl;
	testMat2.print();
	cout << "Mat1 = Mat1 *  Mat1" << endl;
	testMat *= testMat;
	testMat.print();
	Mat4 testMat3(v4_1, v4_2, v4_3, v4_4);
	cout << "Mat *  Vec3<float>(1, 2, 3)" << endl;
	//Vec3<float> v3_M = testMat3.Multiply(Vec3<float>(1, 2, 3));
	Vec3<float> v3_M = testMat3*Vec3<float>(1, 2, 3);
	v3_M.print();
	cout << "Mat *  Vec4<float>(1, 2, 3, 4)" << endl;
	Vec4<float> v4_M = testMat3.Multiply(Vec4<float>(1, 2, 3,0));
	v4_M.print();
	testMat = testMat2;
	testMat.print();
	cout << "testMat = Mat4::Identity()" << endl;
	testMat = Mat4::Identity();
	testMat.print();
	cout << "testMat4 = Mat4::Transpose(testMat4);" << endl;
	Mat4 testMat4(v4_1, v4_2, v4_3, v4_4);
	testMat4 = Mat4::Transpose(testMat4);
	testMat4.print();
	cout << "testMat4 = Mat4::Rotate(90,Vec3<float>(1,0,0));" << endl;
	testMat4 = Mat4::Rotate(90,Vec3<float>(1,0,0));
	testMat4.print();
	cout << "testMat4 = Mat4::Translate(Vec3<float>(100, 0, 0));" << endl;
	testMat4 = testMat;
	testMat4 = Mat4::Translate(Vec3<float>(100, 0, 0));
	testMat4.print();

	getchar();
	return 0;
}
