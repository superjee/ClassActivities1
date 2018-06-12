#include "Utility.h"
using namespace std;

Utility::Utility()
{
}

Utility::~Utility()
{
}

int Utility::KeyboardInput()
{
	if (_kbhit())
	{
		int KB_code = _getch();
		return KB_code;
	}
	return false;
}

void Utility::GoToXY(int x, int y)
{
	static HANDLE hStdout = NULL;
	COORD coord;

	coord.X = (short)x;
	coord.Y = (short)y;

	if (!hStdout)
	{
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	SetConsoleCursorPosition(hStdout, coord);
}

void Utility::ClearScreen()
{
	static HANDLE hStdout = NULL;
	static CONSOLE_SCREEN_BUFFER_INFO csbi;
	const COORD startCoords = { 0,0 };
	DWORD dummy;

	if (!hStdout)
	{
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdout, &csbi);
	}

	FillConsoleOutputCharacter(hStdout,
		' ',
		csbi.dwSize.X * csbi.dwSize.Y,
		startCoords,
		&dummy);
	Utility::GoToXY(0, 0);
}

void Utility::ReadInfo_Text(std::string textfile,std::vector<std::string> & p_info)
{
	p_info.clear();
	ifstream myfile(textfile);
	if (myfile.is_open())
	{
		string line;
		while (getline(myfile, line))
		{
			p_info.push_back(line);
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
}

void Utility::ReadInfo_json(std::string jsonfile, nlohmann::json &p_info)
{
	std::ifstream ifs(jsonfile);
	p_info.clear();
	p_info = nlohmann::json::parse(ifs);
}
