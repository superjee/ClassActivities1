#pragma once
#ifndef _AUTONOMOUS_CAR_H
#define _AUTONOMOUS_CAR_H
#include <iostream>
#include "Engine.h"
#include "MoveableObject.h"
#include "car.h"

namespace my_cargame {
	class AutonomousCar : public SystemBase
	{
	public:
		AutonomousCar();
		virtual ~AutonomousCar();
		void test();

		void init(bool start = true) override;
		void update() override;
		void getInput(int) override;

		void loadAllTracks();
		void setTrackStart();
		void drawTrack();
		void spawnCar(std::string name);

		std::shared_ptr<Grid2D> _Grid2D = make_shared<Grid2D>();
		std::vector<std::shared_ptr<car>> _car;
		nlohmann::json json_data;
	private:
		int playerSelectTrack = -1;
		int numOfCar = -1;
		int TracksCount = 0;
		int startX = -1;
		int startY = -1;

		int startPosX = 0;
		int startPosY = 1;

		std::vector<BMP_Data> tracks_data;
	};
}
#endif
