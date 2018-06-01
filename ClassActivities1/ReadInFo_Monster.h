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
	//infoNumber 1 = Symbolic
	//infoNumber 2 = HP
	//infoNumber 3 = Attack
	//infoNumber 4 = Attack_Swing
	//infoNumber 5 = TapSpeed
	//infoNumber 6 = TapFrequency
	string get_InFo_Monster(int type,int variance, int infoNumber);

	int get_MaxVariance(int type);

private:
	static const int NUMBER_OF_INFO = 7;
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
