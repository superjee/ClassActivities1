#include "Logger.h"
using namespace std;

Logger::Logger():m_count(0)
{
}

Logger::~Logger()
{
}
Logger* Logger::instance = nullptr;

Logger & Logger::Get()
{
	if (instance == nullptr)
	{
		instance = new Logger();
	}

	return *instance;
}

void Logger::log(const std::string& msg)
{
	m_count++;
	std::cout << m_count << " times," << msg << std::endl;
}
