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

	auto pEngine = std::make_shared<Engine>();
	int result = pEngine->runLoop(worldClock,System::GamePlay);//GamePlay

	//Grid2D test;
	//test.testGrid();

	/*vector<string> t;

	t.push_back("sdsdsd");
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << endl;
	}


	Utility::ReadInfo_Text("track01.csv",t);
	cout << endl;
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << endl;
	}*/


	
	//cout << endl;
	//Logger::Get().log("this is my data");
	//Logger::Get().log("this is my data");
	//cout << endl << "clock : " <<a.getDeltaTimeInMilliseconds();
	getchar();
	return result;
}
