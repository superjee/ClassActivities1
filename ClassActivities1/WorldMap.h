#pragma once
#define WorldMap_X 0
#define WorldMap_Y 1
#include "Utility.h"
class WorldMap
{
public:
	Utility pUtility;
	WorldMap();
	virtual ~WorldMap();
	void initiation();
	void drawMap();
	void drawObjInMap(int x,int y,int Obj, int sym = 0);
	void drawMapBox();
	int getLength(int xy);
	int getObjInMap(int x, int y);
	void setObjInMap(int x, int y, int Obj);
	int getEndPosY();
	void setOldObj(int inputID);
	int getOldObj();

	WorldMap(const WorldMap& other) = default;
	WorldMap& operator= (WorldMap& other) = default;

	enum objInMap { OBJ_empty = -1, OBJ_BATTLE = 15 };
	enum symbolic { SYM_empty, SYM_ZOMBIE = 11, SYM_ORC };
private:
	static const int X = 30;
	static const int Y = 30;
	static const int OBJ_MONSTER = 3;
	int worldMap[X][Y];
	int oldObjID = -1;
	int startPosX = 0;
	int startPosY = 8;
	int endPosY = startPosY + Y + 3;
};

