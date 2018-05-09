#pragma once
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
private:
	static const int x = 30;
	static const int y = 30;
	int worldMap[y][x];
	char Monster1 = 11;
	char Monster2 = 12;
};

