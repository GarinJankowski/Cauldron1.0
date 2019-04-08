#pragma once
#ifndef MAP_H
#define MAP_H
/*
#include "Character.h"
#include "Room.h"
#include "InputBoard.h"
*/

#include "Character.h"
#include "InputBoard.h"
#include "Room.h"

class InputBoard;

class Map
{
public:
	Map(bool inf, int itier, int iFloor);
	~Map();

	int numIce = 0;
	int numTreasure = 0;
	int numForest = 0;
	int numLava = 0;
	int numWasteland = 0;
	int numFog = 0;

	bool infinite;
	int infiniteTier;
	int infiniteFloor;

	vector<Room> roomList;
	const char* terrainGridInfinite[13][4];
	const char* terrainGrid[26][8];

	void PrintWholeMap(Character &guy);
	void PrintMapNoUpdate(Character &guy);
	void generateSingleTerrain(const char* terrain);
	int generateSurroundingTerrain(int x, int y);
	void generateCity();
	void generateCity(int px, int py);
	void generateTerrain();
	void UpdateMap(Character &guy);
	void checkPosition(Character &guy, InputBoard &board);
	char getTier(int posx, int posy);
	Room at(int i);
};

#endif //MAP_H
