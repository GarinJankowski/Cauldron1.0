#pragma once
#ifndef ROOM_H
#define ROOM_H

/*
#include "InputBoard.h"
*/

#include "InputBoard.h"

class InputBoard;

class Room
{
public:
	Room();
	Room(const char *type, int x, int y, bool inf);
	~Room();
	
	const char *RoomType;
	const char *Terrain;
	int posx;
	int posy;
	bool clear;
	char tier;
	bool fogged = TRUE;
	bool amnesia = FALSE;

	bool infinite;

	void getTileColor();
	void setXY(int x, int y);
	bool checkXY(int x, int y);
	Room getXY(int x, int y);
	void PrintRoom(bool gray);
	void ActivateRoom(InputBoard board);
};

#endif //ROOM_H