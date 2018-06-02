#include "WorldClock.hpp"

WorldClock::WorldClock()
{
	t1 = Clock::now();
}

WorldClock::~WorldClock()
{
}

void WorldClock::setDeltaTime() {
	t2 = Clock::now();
}

void WorldClock::setfristTime()
{
	t1 = Clock::now();
}

int WorldClock::getDeltaTimeInMilliseconds() {
	return static_cast<int>(std::chrono::duration_cast<elapsed_resolution>(t2 - t1).count());
	
}
