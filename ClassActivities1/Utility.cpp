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

void Utility::ReadBMP(const std::string & file, BMP_Data & t)
{
	static constexpr size_t HEADER_SIZE = 54;

	std::ifstream bmp(file, std::ios::binary);

	std::array<char, HEADER_SIZE> header;
	bmp.read(header.data(), header.size());

	auto fileSize = *reinterpret_cast<uint32_t *>(&header[2]);
	auto dataOffset = *reinterpret_cast<uint32_t *>(&header[10]);
	auto width = *reinterpret_cast<uint32_t *>(&header[18]);
	auto height = *reinterpret_cast<uint32_t *>(&header[22]);
	auto depth = *reinterpret_cast<uint16_t *>(&header[28]);

	t.height = height;
	t.width = width;

	//std::cout << "fileSize: " << fileSize << std::endl;
	//std::cout << "dataOffset: " << dataOffset << std::endl;
	//std::cout << "width: " << width << std::endl;
	//std::cout << "height: " << height << std::endl;
	//std::cout << "depth: " << depth << "-bit" << std::endl;

	std::vector<char> img(dataOffset - HEADER_SIZE);
	bmp.read(img.data(), img.size());

	auto dataSize = ((width * 3 + 3) & (~3)) * height;//(width*height)*3;//
	img.resize(dataSize);
	bmp.read(img.data(), img.size());

	char temp = 0;
	int num = 0;
	//std::cout << std::endl << dataSize;
	for (auto i = 0; i < dataSize - 2; i += 3)
	{
		temp = img[i];
		img[i] = img[i + 2];
		img[i + 2] = temp;
		num++;
		//std::cout<<  num << " R : " << int(img[i] & 0xff) << "G : " << int(img[i+1] & 0xff) << "B : " << int(img[i+2] & 0xff) << endl;
	}

	t.data = img;
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
