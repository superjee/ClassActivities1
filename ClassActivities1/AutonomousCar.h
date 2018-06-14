#pragma once
#ifndef _AUTONOMOUS_CAR_H
#define _AUTONOMOUS_CAR_H
#include <iostream>
#include "Engine.h"
#include "MoveableObject.h"

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

		std::shared_ptr<Grid2D> _Grid2D = make_shared<Grid2D>();
		std::vector<std::shared_ptr<MoveableObject>> _MoveableObject;

	private:
		int playerSelectTrack = -1;
		int num = 0;
		int TracksCount = 0;
		int startX = -1;
		int startY = -1;

		int startPosX = 0;
		int startPosY = 1;

		std::vector<BMP_Data> tracks_data;
	};
}
#endif
