#pragma once
#ifndef ROOM_H
#define ROOM_H

#include "InputBoard.h"

class Room
{
public:
	Room();
	Room(const char *type, int x, int y);
	~Room();
	
	const char *RoomType;
	int posx;
	int posy;
	bool clear;
	char tier;

	void setXY(int x, int y);
	bool checkXY(int x, int y);
	Room getXY(int x, int y);
	void PrintRoom(bool gray);
	void ActivateRoom(InputBoard board);
};

#endif //ROOM_H