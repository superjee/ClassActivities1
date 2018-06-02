#pragma once
#include<chrono>
#include<iostream>

typedef std::chrono::high_resolution_clock Clock;
using elapsed_resolution = std::chrono::milliseconds;

class WorldClock
{
private:
	std::chrono::steady_clock::time_point t1, t2;
public:
	WorldClock();
	~WorldClock();
	void setDeltaTime();
	void setfristTime();
	int getDeltaTimeInMilliseconds();
};

