#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>     
#include <crtdbg.h>
#include <iostream>
#include "Engine.h"
#include "Logger.h"

using namespace std;

std::vector<char> readBMP(const std::string &file)
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

	std::cout << "fileSize: " << fileSize << std::endl;
	std::cout << "dataOffset: " << dataOffset << std::endl;
	std::cout << "width: " << width << std::endl;
	std::cout << "height: " << height << std::endl;
	std::cout << "depth: " << depth << "-bit" << std::endl;

	std::vector<char> img(dataOffset - HEADER_SIZE);
	bmp.read(img.data(), img.size());

	auto dataSize = ((width * 3 + 3) & (~3)) * height;
	img.resize(dataSize);
	bmp.read(img.data(), img.size());

	char temp = 0;
	int num = 0;
	std::cout << std::endl << dataSize;
	for (auto i = 0; i < dataSize-2; i+=3)
	{
		temp = img[i];
		img[i] = img[i + 2];
		img[i + 2] = temp;
		num++;
		//std::cout<<  num << " R : " << int(img[i] & 0xff) << "G : " << int(img[i+1] & 0xff) << "B : " << int(img[i+2] & 0xff) << endl;
	}
	return img;
}

int main()
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//WorldClock worldClock;

	//auto pEngine = std::make_shared<Engine>();
	//int result = pEngine->runLoop(worldClock,System::GamePlay);//GamePlay

	std::vector<char> testimg = readBMP("testIMG.bmp");
	Grid2D test;
	cout << endl;
	test.initiation(20, 20);
	test.testGrid();
	
	//test.drawBox(0, 15);


	for (int j = 0; j < test.getLength(Grid2D::GRID::GRID_Y); j++)
	{
		for (int i = 0; i < test.getLength(Grid2D::GRID::GRID_X); i++)
		{
			int dummy = ((i + (j*test.getLength(Grid2D::GRID::GRID_Y))) * 3);

			if(testimg[dummy] == 0
				&& testimg[dummy +1] == 0
				&& testimg[dummy +2] == 0)
				test.setDataInGrid(i, j, 0);
			else
				test.setDataInGrid(i, j, 1);//testimg.size()-*/

			//test.setDataInGrid(i, j, ((i + (j*test.getLength(Grid2D::GRID::GRID_Y)))*3));

		}
	}

	for (int j = 19; j >= 0; j--)
	{
		for (int i = 0; i < test.getLength(Grid2D::GRID::GRID_X); i++)
		{
			std::cout << " "<< test.getDataInGrid(i,j);
		}
		std::cout << std::endl;
	}



	/*Grid2D test;
	test.testGrid();
	test.initiation(5, 10);
	test.drawBox(0, 15);


	cout << endl << test.getDataInGrid(2, 2);
	test.setDataInGrid(2,2,100);
	cout << endl << test.getDataInGrid(2, 2);

	nlohmann::json tt;
	Utility::ReadInfo_json("car_properties.json",tt);
	std::cout << endl << tt.dump();

	Utility::ReadInfo_json("car_properties.json", tt);
	std::cout << endl << tt.dump();

	std::vector<std::string> sss;
	Utility::ReadInfo_Text("testIMG.bmp",sss);
	cout << endl;
	int testtt = atoi(sss[0].c_str());

	cout << testtt;*/

	/*for (int i = 0; i < sss.size(); i++)
	{
		cout << sss[i] << endl;
	}*/

	/*vector<string> t;

	t.push_back("sdsdsd");
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << endl;
	}


	Utility::ReadInfo_Text("track01.csv",t);
	cout << endl;
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << endl;
	}*/


	
	//cout << endl;
	//Logger::Get().log("this is my data");
	//Logger::Get().log("this is my data");
	//cout << endl << "clock : " <<a.getDeltaTimeInMilliseconds();
	getchar();
	//return result;
	return 0;
}
