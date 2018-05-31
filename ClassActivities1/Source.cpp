#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>     
#include <crtdbg.h>
#include <iostream>
#include "Engine.h"

int main()
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	auto pEngine = std::make_shared<Engine>();
	int result = pEngine->runLoop();
	return result;
}
