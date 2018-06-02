//#pragma once
#include <iostream>
#include <string>


class Logger
{
public:
	Logger();
	~Logger();
	void log(const std::string& msg);
	static Logger& Get();
private:
	int m_count = 0;
	static Logger *instance;
	 
};

