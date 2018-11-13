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

	vector<Room> roomList;

	void PrintWholeMap(Character &guy, InputBoard &board);
	void UpdateMap(Character &guy, InputBoard &board);
	void checkPosition(Character &guy, InputBoard &board);
	char getTier(int posx, int posy);
	Room at(int i);
};

#endif //MAP_H
