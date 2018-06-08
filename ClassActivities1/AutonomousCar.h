#pragma once
#ifndef _AUTONOMOUS_CAR_H
#define _AUTONOMOUS_CAR_H
#include <iostream>
#include "Engine.h"

class AutonomousCar
{
public:
	~AutonomousCar();
	static AutonomousCar& instance() 
	{ 
		static AutonomousCar instance_;
		return instance_; 
	}
	void test();
private:
	AutonomousCar();
	int num = 0;
	//static AutonomousCar instance_;
};
#endif
