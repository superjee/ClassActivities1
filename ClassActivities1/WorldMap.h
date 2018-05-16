#pragma once

#define WorldMap_X 0
#define WorldMap_Y 1

class WorldMap
{
public:
	WorldMap();
	virtual ~WorldMap();
	void initiation();
	void drawMap();
	int getLength(int xy);
	int getObjInMap(int x, int y);
	void setObjInMap(int x, int y, int Obj);
	enum objInMap { OBJ_empty = -1, OBJ_ZOMBIE = 1, OBJ_ORC };
	enum symbolic { SYM_empty, SYM_ZOMBIE = 11, SYM_ORC };
private:
	static const int X = 30;
	static const int Y = 30;
	static const int OBJ_MONSTER = 3;
	int worldMap[Y][X];

};

