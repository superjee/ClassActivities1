#include "AutonomousCar.h"
using namespace my_cargame;
void AutonomousCar::test()
{
	num++;
	std::cout << num << " AutonomousCar test" << std::endl;
	BMP_Data t1;
	Utility::ReadBMP("track_3.bmp", t1);
	Grid2D test;
	test.initiation(t1.width, t1.height); //14,20
	test.drawBox(0, 1);
	for (int j = 0; j < test.getLength(Grid2D::GRID::GRID_Y); j++)
	{
		for (int i = 0; i < test.getLength(Grid2D::GRID::GRID_X); i++)
		{
			int dummy = ((i + (j*test.getLength(Grid2D::GRID::GRID_X))) * 3);

			if (t1.data[dummy] == 0
				&& t1.data[dummy + 1] == 0
				&& t1.data[dummy + 2] == 0)
				test.setDataInGrid(i, j, 1);
			else
				test.setDataInGrid(i, j, 0);//testimg.size()-

			//test.setDataInGrid(i, j, ((i + (j*test.getLength(Grid2D::GRID::GRID_X))) * 3));
		}
	}
	int dummy = 0;
	for (int j = test.getLength(Grid2D::GRID::GRID_Y) - 1; j >= 0; j--)
	{
		Utility::GoToXY(1, 2 + dummy);
		for (int i = 0; i < test.getLength(Grid2D::GRID::GRID_X); i++)
		{
			std::cout << " " << test.getDataInGrid(i, j);
		}
		dummy++;
		std::cout << std::endl;
	}
}

void my_cargame::AutonomousCar::init(bool start)
{
	//test();
	if (start)
	{
		loadAllTracks();
	}
	
	while (true)
	{
		cout << "\nSelect Track (1 - " << TracksCount <<") : ";
		cin >> playerSelectTrack;
		playerSelectTrack -= 1;
		if (playerSelectTrack >= 0 && playerSelectTrack < TracksCount)
		{
			Utility::ClearScreen();
			_Grid2D->initiation(tracks_data[playerSelectTrack].width, tracks_data[playerSelectTrack].height);
			setTrackStart();
			drawTrack();
			_Grid2D->drawBox(startPosX, startPosY);

			cout << "Pickup Truck : w" << endl;
			cout << "Truck        : a" << endl;
			cout << "Sport Car    : s" << endl;
			cout << "Van          : d" << endl;
			cout << "StartPos     : " << startX << " | " << startY << endl;
			//////
			_MoveableObject.push_back(make_shared<MoveableObject>());
			_MoveableObject[0]->set_Pos(startX, startY);
			
			_MoveableObject[0]->autoMove(_Grid2D);
			//_Grid2D->setDataInGrid(startX, startY, 9);
			//_Grid2D->drawObj(startX, startY,9,'%');

			break;
		}
	}
}

void my_cargame::AutonomousCar::update()
{
	_MoveableObject[0]->autoMove(_Grid2D);
	Sleep(100);
}

void my_cargame::AutonomousCar::getInput(int p_input)
{
	switch (p_input)
	{
	case KeyboardInput::KB_W:
		//init(false);
		break;
	case KeyboardInput::KB_A:
	
		break;
	case KeyboardInput::KB_S:
	
		break;
	case KeyboardInput::KB_D:
		//_MoveableObject[0]->moveRIGHT(_Grid2D);
		//_MoveableObject[0]->autoMove(_Grid2D);
		break;
	case KeyboardInput::KB_1:

		break;
	case KeyboardInput::KB_2:

		break;
	case KeyboardInput::KB_3:

		break;
	case KeyboardInput::KB_4:

		break;
	}
}

void my_cargame::AutonomousCar::loadAllTracks()
{
	bool getFile = true;
	while (getFile)
	{
		string checkFile = "track_";
		checkFile += to_string(TracksCount + 1)+".bmp";
		ifstream f;
		f.open(checkFile);
		getFile = f.is_open();
		f.close();
		if (getFile == false)
		{
			break;
		}
		else
		{
			tracks_data.push_back(BMP_Data());
		}
		cout << "Loading.." << checkFile << endl;
		Utility::ReadBMP(checkFile, tracks_data[TracksCount]);
		TracksCount++;
	}
	cout << "Loading..complete" << endl;
}

void my_cargame::AutonomousCar::setTrackStart()
{
	for (int j = 0; j < _Grid2D->getLength(Grid2D::GRID::GRID_Y); j++)
	{
		for (int i = 0; i < _Grid2D->getLength(Grid2D::GRID::GRID_X); i++)
		{
			/*int dummy = ((i + (j*_Grid2D->getLength(Grid2D::GRID::GRID_X))) * 3);

			if (tracks_data[playerSelectTrack].data[dummy] == 0
				&& tracks_data[playerSelectTrack].data[dummy + 1] == 0
				&& tracks_data[playerSelectTrack].data[dummy + 2] == 0)
				_Grid2D->setDataInGrid(i, j, 1);
			else
				_Grid2D->setDataInGrid(i, j, 0);*/ //

			int dummy = tracks_data[playerSelectTrack].data.size() - 
				((((_Grid2D->getLength(Grid2D::GRID::GRID_X) - 1) - i) + 
				(j*_Grid2D->getLength(Grid2D::GRID::GRID_X))) * 3);

			if (tracks_data[playerSelectTrack].data[dummy - 3] == 0
				&& tracks_data[playerSelectTrack].data[dummy - 2] == 0
				&& tracks_data[playerSelectTrack].data[dummy - 1] == 0)
				_Grid2D->setDataInGrid(i, j, 1);
			else
				_Grid2D->setDataInGrid(i, j, 0);

			//_Grid2D->setDataInGrid(i, j, tracks_data[playerSelectTrack].data.size() - ((((_Grid2D->getLength(Grid2D::GRID::GRID_X)-1)-i) + (j*_Grid2D->getLength(Grid2D::GRID::GRID_X))) * 3));
			//***_Grid2D->setDataInGrid(i, j, tracks_data[playerSelectTrack].data.size() - ((i + (j*_Grid2D->getLength(Grid2D::GRID::GRID_X))) * 3));
		}
	}

	/*int dummy = 0;
	for (int j = 0; j < _Grid2D->getLength(Grid2D::GRID::GRID_Y); j++)//for (int j = _Grid2D->getLength(Grid2D::GRID::GRID_Y) - 1; j >= 0; j--)
	{
		Utility::GoToXY(1, 2 + j);
		for (int i = 0; i < _Grid2D->getLength(Grid2D::GRID::GRID_X); i++)
		{
			std::cout << " " << _Grid2D->getDataInGrid(i, j);
		}
		dummy++;
		std::cout << std::endl;
	}*/
}

void my_cargame::AutonomousCar::drawTrack()
{
	startX = -1;
	startY = -1;
	for (int j = 0; j < _Grid2D->getLength(Grid2D::GRID::GRID_Y); j++)//for (int j = _Grid2D->getLength(Grid2D::GRID::GRID_Y) - 1; j >= 0; j--)
	{
		Utility::GoToXY(startPosX+1, startPosY+1 + j);
		for (int i = 0; i < _Grid2D->getLength(Grid2D::GRID::GRID_X); i++)
		{
			switch (_Grid2D->getDataInGrid(i, j))
			{
			case 0:
				std::cout << "  ";
				if (startX == -1 && startY == -1)
				{
					startX = i;
					startY = j;
				}
				break;
			case 1:
				std::cout << " =";
				break;
			}
			//std::cout << " " << _Grid2D->getDataInGrid(i, j);
		}
		std::cout << std::endl;
	}
}

AutonomousCar::AutonomousCar()
{

}
AutonomousCar::~AutonomousCar()
{
}
