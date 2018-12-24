#pragma once
#ifndef MAP_H
#define MAP_H
#include "Room.h"
#include "InputBoard.h"

class Map
{
public:
	Map();
	~Map();

	int numIce = 0;
	int numTreasure = 0;
	int numForest = 0;
	int numMagma = 0;
	int numWasteland = 0;
	int numFog = 0;

	vector<Room> roomList;
	const char* terrainGrid[26][8];

	void PrintWholeMap(Character &guy, InputBoard &board);
	void generateSingleTerrain(const char* terrain);
	int generateSurroundingTerrain(int x, int y);
	void generateCity();
	void generateCity(int px, int py);
	void generateTerrain();
	void UpdateMap(Character &guy, InputBoard &board);
	void checkPosition(Character &guy, InputBoard &board);
	char getTier(int posx, int posy);
	Room at(int i);
};

#endif //MAP_H
