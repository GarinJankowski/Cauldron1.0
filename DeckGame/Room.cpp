#include "pch.h"
#include "Room.h"


//five rooms types:
//First
	//starting room
//Combat
	//fight an enemy
//Addition
	//obtain a special card
//Gear
	//get gear
//Empty
	//room has been cleared, choose which room to go to next
//Boss
	//last room

Room::Room() {
	RoomType = "";
	clear = FALSE;
	posx = 0;
	posy = 0;
}
Room::Room(const char *type, int x, int y):RoomType(type)
{
	RoomType = type;
	clear = FALSE;
	posx = x;
	posy = y;
}


Room::~Room()
{
}

void Room::PrintRoom(bool gray) {
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);

	init_color(COLOR_RED, 800, 0, 0);
	init_pair(5, COLOR_RED, COLOR_BLACK);

	init_pair(2, COLOR_CYAN, COLOR_BLACK);

	init_color(COLOR_MAGENTA, 800, 0, 800);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);

	init_color(COLOR_GREEN, 500, 1000, 200);
	init_pair(7, COLOR_GREEN, COLOR_BLACK);
	
	//init_color(COLOR_WHITE, 200, 200, 200);
	init_pair(8, COLOR_BLACK, COLOR_WHITE);

	init_color(COLOR_BLUE, 200, 400, 1000);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);

	if (RoomType == "First") {
		if (gray)
			attron(COLOR_PAIR(8));
		mvprintw(13 - posy, 1 + posx, " "); // i want this --> ∩ <-- eventually
	}
	else if (RoomType == "Combat") {
		if (gray)
			attron(COLOR_PAIR(8));
		else
			attron(COLOR_PAIR(5));
		mvprintw(13 - posy, 1 + posx, "!");
	}
	else if (RoomType == "Gear Head") {
		if (gray)
			attron(COLOR_PAIR(8));
		else
			attron(COLOR_PAIR(2));
		mvprintw(13 - posy, 1 + posx, "^");
	}
	else if (RoomType == "Gear Body") {
		if (gray)
			attron(COLOR_PAIR(8));
		else
			attron(COLOR_PAIR(2));
		mvprintw(13 - posy, 1 + posx, "#");
	}
	else if (RoomType == "Gear Hands") {
		if (gray)
			attron(COLOR_PAIR(8));
		else
			attron(COLOR_PAIR(2));
		mvprintw(13 - posy, 1 + posx, "/");
	}
	else if (RoomType == "Cauldron") {
		if (gray)
			attron(COLOR_PAIR(8));
		else
			attron(COLOR_PAIR(3));
		mvprintw(13 - posy, 1 + posx, "+");
	}
	else if (RoomType == "Boss") {
		if (gray)
			attron(COLOR_PAIR(8));
		else
			attron(COLOR_PAIR(7));
		mvprintw(13 - posy, 1 + posx, "o");
	}
	else if (RoomType == "Final Boss") {
		if (gray)
			attron(COLOR_PAIR(8));
		else
			attron(COLOR_PAIR(7));
		mvprintw(13 - posy, 1 + posx, "&");
	}
	else if (RoomType == "Empty") {
		if (gray)
			attron(COLOR_PAIR(8));
		else
			standend();
		mvprintw(13 - posy, 1 + posx, ".");
	}
	standend();
	//init_color(COLOR_WHITE, 700, 700, 700);
}

void Room::setXY(int x, int y) {
	posx = x;
	posy = y;
}

bool Room::checkXY(int x, int y) {
	if (posx == x && posy == y)
		return TRUE;
	else
		return FALSE;
}

void Room::ActivateRoom(InputBoard board) {
}
