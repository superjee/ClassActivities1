#include "ReadInFo_Monster.h"

ReadInFo_Monster::ReadInFo_Monster()
{
	markTypeIndex.push_back(0);
	markTypeEnd.push_back(0);
	int type = 0;
	ifstream myfile("monster_conf.csv");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (line == newMonster)
			{
				markTypeIndex.push_back(type);
			}
			else if (line == endMonster)
			{
				markTypeEnd.push_back(type);
			}
			else
			{
				allinfo += line +",";
				info.push_back(line);
				++type;
			}	
		}
		myfile.close();
		string input = allinfo;
		istringstream ss(input);
		string token;
		while (getline(ss, token, ',')) {
			useinfo.push_back(token);
		}


	}
	else cout << "Unable to open file";


	/*for (int i = 0; i < markTypeIndex.size(); i++)
	{
		cout << "markTypeIndex " << i << " :  " << markTypeIndex[i] << endl;
	}
	for (int i = 0; i < markTypeEnd.size(); i++)
	{
		cout << "markTypeEnd " << i << " :  " << markTypeEnd[i] << endl;
	}
	for (int i = 0; i < info.size(); i++)
	{
		cout << "info " << i << " :  " << info[i] << endl;
	}
	for (int i = 0; i < useinfo.size(); i++)
	{
		cout << "useinfo " << i << " :  " << useinfo[i] << endl;
	}
	cout << endl << allinfo;
	cout << endl;
	cout << endl;*/
}


ReadInFo_Monster::~ReadInFo_Monster()
{
}


string ReadInFo_Monster::get_InFo_Monster(int type, int variance,int infoNumber)
{
	string output = useinfo[(markTypeIndex[type]* NUMBER_OF_INFO)+ (variance*NUMBER_OF_INFO)+ infoNumber];
	return output;
}

int ReadInFo_Monster::get_MaxVariance(int type)
{
	return markTypeEnd[type] - markTypeIndex[type];
}
