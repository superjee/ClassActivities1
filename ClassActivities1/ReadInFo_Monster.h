#pragma once
#ifndef ReadInFo_Monster_HPP
#define ReadInFo_Monster_HPP
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
using namespace std;


class ReadInFo_Monster final
{
public:
	ReadInFo_Monster();
	~ReadInFo_Monster();
	//get_InFo_Monster(int type,int variance, int infoNumber)
	//infoNumber 0 = Name
	//infoNumber 1 = HP
	//infoNumber 2 = Attack
	//infoNumber 3 = Attack_Swing
	string get_InFo_Monster(int type,int variance, int infoNumber);
private:
	static const int NUMBER_OF_INFO = 4;
	string line;
	string newMonster = "NEW";
	string endMonster = "END";
	vector<string> info;
	vector<string> useinfo;
	string allinfo;
	vector<int> markTypeIndex;
	vector<int> markTypeEnd;
};
#endif
