#pragma once
#ifndef _UTILITY_H
#define _UTILITY_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include "Include\nlohmann\json.hpp"
enum KeyboardInput
{
	EXIT = 27,
	KB_W = 119,
	KB_A = 97,
	KB_S = 115,
	KB_D = 100,
	KB_UP = 72,
	KB_DOWN = 80,
	KB_LEFT = 75,
	KB_RIGHT = 77,
	KB_1 = 49,
	KB_2,
	KB_3,
	KB_4,
	KB_5,
	KB_6,
	KB_7,
	KB_8,
	KB_9
};
struct BMP_Data {
	std::vector<char> data;
	int width;
	int height;
};
class Utility final
{
public:
	Utility();
	~Utility();
	static int KeyboardInput();
	static void GoToXY(int x, int y);
	static void ClearScreen();
	static void ReadBMP(const std::string &file, BMP_Data &t);
	static void ReadInfo_Text(std::string textfile,std::vector<std::string> &p_info);
	static void ReadInfo_json(std::string jsonfile ,nlohmann::json &p_info);
};
#endif //_UTILITY_H
