#include "pch.h"
#include "Room.h"


//five rooms types:
//First
	//starting room
//Combat
	//fight an enemy
//Addition
	//obtain a boss card
//Gear
	//get gear
//Empty
	//room has been cleared, choose which room to go to next
//Boss
	//last room

//color stuff
int combat_ice = 30;
int boss_ice = 31;
int gear_ice = 32;
int cauldron_ice = 33;
int shop_ice = 34;

int combat_treasure = 35;
int boss_treasure = 36;
int gear_treasure = 37;
int cauldron_treasure = 38;
int shop_treasure = 39;

int combat_forest = 40;
int boss_forest = 41;
int gear_forest = 42;
int cauldron_forest = 43;
int shop_forest = 44;

int combat_Lava = 45;
int boss_Lava = 46;
int gear_Lava = 47;
int cauldron_Lava = 48;
int shop_Lava = 49;

int combat_wasteland = 50;
int boss_wasteland = 51;
int gear_wasteland = 52;
int cauldron_wasteland = 53;
int shop_wasteland = 54;

int combat_fog = 55;
int boss_fog = 56;
int gear_fog = 57;
int cauldron_fog = 58;
int shop_fog = 59;

int forge_ice = 60;
int forge_treasure = 61;
int forge_forest = 62;
int forge_Lava = 63;
int forge_wasteland = 64;
int forge_fog = 65;

int Lava = 66;
int wasteland = 67;
int fog = 68;

int combat_city = 76;
int boss_city = 77;
int gear_city = 78;
int cauldron_city = 79;
int shop_city = 80;
int forge_city = 81;

Room::Room() {
	RoomType = "";
	clear = FALSE;
	posx = 0;
	posy = 0;
}
Room::Room(const char *type, int x, int y, bool inf):RoomType(type), infinite(inf)
{
	RoomType = type;
	clear = FALSE;
	posx = x;
	posy = y;
}


Room::~Room()
{
}

void Room::getTileColor() {

}

void Room::PrintRoom(bool gray) {
	/*init_pair(1, COLOR_YELLOW, COLOR_BLACK);

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
	init_pair(6, COLOR_BLUE, COLOR_BLACK);*/
	if (clear)
		gray = TRUE;
	else
		gray = FALSE;

	int inf = 0;
	int inf2 = 0;
	if (infinite) {
		inf = 2;
		inf2 = 7;
	}
	
	if (RoomType == "First") {
		if (gray)
			attron(COLOR_PAIR(8));
		mvprintw(13 - posy - inf, 1 + posx + inf2, " "); // i want this --> ∩ <-- eventually
	}
	else if (RoomType == "Combat") {
		if (gray)
			attron(COLOR_PAIR(8));
		else {
			if (Terrain == "Ice") {
				attron(COLOR_PAIR(combat_ice));
			}
			else if (Terrain == "Treasure") {
				attron(COLOR_PAIR(combat_treasure));
			}
			else if (Terrain == "Forest") {
				attron(COLOR_PAIR(combat_forest));
			}
			else if (Terrain == "Lava") {
				attron(COLOR_PAIR(combat_Lava));
			}
			else if (Terrain == "Wasteland") {
				attron(COLOR_PAIR(combat_wasteland));
			}
			else if (Terrain == "City") {
				attron(COLOR_PAIR(combat_city));
			}
			else if (Terrain == "Fog") {
				if (fogged)
					attron(COLOR_PAIR(fog));
				else
					attron(COLOR_PAIR(combat_fog));
			}
			else
				attron(COLOR_PAIR(5));
		}
		mvprintw(13 - posy - inf, 1 + posx + inf2, "!");
	}
	else if (RoomType == "Gear Head") {
		if (gray)
			attron(COLOR_PAIR(8));
		else {
			if (Terrain == "Ice") {
				attron(COLOR_PAIR(gear_ice));
			}
			else if (Terrain == "Treasure") {
				attron(COLOR_PAIR(gear_treasure));
			}
			else if (Terrain == "Forest") {
				attron(COLOR_PAIR(gear_forest));
			}
			else if (Terrain == "Lava") {
				attron(COLOR_PAIR(gear_Lava));
			}
			else if (Terrain == "Wasteland") {
				attron(COLOR_PAIR(gear_wasteland));
			}
			else if (Terrain == "City") {
				attron(COLOR_PAIR(gear_city));
			}
			else if (Terrain == "Fog") {
				if (fogged)
					attron(COLOR_PAIR(fog));
				else
					attron(COLOR_PAIR(gear_fog));
			}
			else
				attron(COLOR_PAIR(2));
		}
		mvprintw(13 - posy - inf, 1 + posx + inf2, "^");
	}
	else if (RoomType == "Gear Body") {
		if (gray)
			attron(COLOR_PAIR(8));
		else {
			if (Terrain == "Ice") {
				attron(COLOR_PAIR(gear_ice));
			}
			else if (Terrain == "Treasure") {
				attron(COLOR_PAIR(gear_treasure));
			}
			else if (Terrain == "Forest") {
				attron(COLOR_PAIR(gear_forest));
			}
			else if (Terrain == "Lava") {
				attron(COLOR_PAIR(gear_Lava));
			}
			else if (Terrain == "Wasteland") {
				attron(COLOR_PAIR(gear_wasteland));
			}
			else if (Terrain == "City") {
				attron(COLOR_PAIR(gear_city));
			}
			else if (Terrain == "Fog") {
				if(fogged)
					attron(COLOR_PAIR(fog));
				else
					attron(COLOR_PAIR(gear_fog));
			}
			else
				attron(COLOR_PAIR(2));
		}
		mvprintw(13 - posy - inf, 1 + posx + inf2, "#");
	}
	else if (RoomType == "Gear Hands") {
		if (gray)
			attron(COLOR_PAIR(8));
		else {
			if (Terrain == "Ice") {
				attron(COLOR_PAIR(gear_ice));
			}
			else if (Terrain == "Treasure") {
				attron(COLOR_PAIR(gear_treasure));
			}
			else if (Terrain == "Forest") {
				attron(COLOR_PAIR(gear_forest));
			}
			else if (Terrain == "Lava") {
				attron(COLOR_PAIR(gear_Lava));
			}
			else if (Terrain == "Wasteland") {
				attron(COLOR_PAIR(gear_wasteland));
			}
			else if (Terrain == "City") {
				attron(COLOR_PAIR(gear_city));
			}
			else if (Terrain == "Fog") {
				if (fogged)
					attron(COLOR_PAIR(fog));
				else
					attron(COLOR_PAIR(gear_fog));
			}
			else
				attron(COLOR_PAIR(2));
		}
		mvprintw(13 - posy - inf, 1 + posx + inf2, "/");
	}
	else if (RoomType == "Mod") {
		if (gray)
			attron(COLOR_PAIR(8));
		else {
			if (Terrain == "Ice") {
				attron(COLOR_PAIR(forge_ice));
			}
			else if (Terrain == "Treasure") {
				attron(COLOR_PAIR(forge_treasure));
			}
			else if (Terrain == "Forest") {
				attron(COLOR_PAIR(forge_forest));
			}
			else if (Terrain == "Lava") {
				attron(COLOR_PAIR(forge_Lava));
			}
			else if (Terrain == "Wasteland") {
				attron(COLOR_PAIR(forge_wasteland));
			}
			else if (Terrain == "City") {
				attron(COLOR_PAIR(forge_city));
			}
			else if (Terrain == "Fog") {
				if (fogged)
					attron(COLOR_PAIR(fog));
				else
					attron(COLOR_PAIR(forge_fog));
			}
			else
				attron(COLOR_PAIR(6));
		}
		mvprintw(13 - posy - inf, 1 + posx + inf2, "=");
	}
	else if (RoomType == "Shop") {
		if (gray)
			attron(COLOR_PAIR(8));
		else {
			if (Terrain == "Ice") {
				attron(COLOR_PAIR(shop_ice));
			}
			else if (Terrain == "Treasure") {
				attron(COLOR_PAIR(shop_treasure));
			}
			else if (Terrain == "Forest") {
				attron(COLOR_PAIR(shop_forest));
			}
			else if (Terrain == "Lava") {
				attron(COLOR_PAIR(shop_Lava));
			}
			else if (Terrain == "Wasteland") {
				attron(COLOR_PAIR(shop_wasteland));
			}
			else if (Terrain == "City") {
				attron(COLOR_PAIR(shop_city));
			}
			else if (Terrain == "Fog") {
				if (fogged)
					attron(COLOR_PAIR(fog));
				else
					attron(COLOR_PAIR(shop_fog));
			}
			else
				attron(COLOR_PAIR(10));
		}
		mvprintw(13 - posy - inf, 1 + posx + inf2, "$");
	}
	else if (RoomType == "Cauldron") {
		if (gray)
			attron(COLOR_PAIR(8));
		else {
			if (Terrain == "Ice") {
				attron(COLOR_PAIR(cauldron_ice));
			}
			else if (Terrain == "Treasure") {
				attron(COLOR_PAIR(cauldron_treasure));
			}
			else if (Terrain == "Forest") {
				attron(COLOR_PAIR(cauldron_forest));
			}
			else if (Terrain == "Lava") {
				attron(COLOR_PAIR(cauldron_Lava));
			}
			else if (Terrain == "Wasteland") {
				attron(COLOR_PAIR(cauldron_wasteland));
			}
			else if (Terrain == "City") {
				attron(COLOR_PAIR(cauldron_city));
			}
			else if (Terrain == "Fog") {
				if(fogged)
					attron(COLOR_PAIR(fog));
				else
					attron(COLOR_PAIR(cauldron_fog));
			}
			else
				attron(COLOR_PAIR(3));
		}
		mvprintw(13 - posy - inf, 1 + posx + inf2, "+");
	}
	else if (RoomType == "Boss") {
		if (gray)
			attron(COLOR_PAIR(8));
		else {
			if (Terrain == "Ice") {
				attron(COLOR_PAIR(boss_ice));
			}
			else if (Terrain == "Treasure") {
				attron(COLOR_PAIR(boss_treasure));
			}
			else if (Terrain == "Forest") {
				attron(COLOR_PAIR(boss_forest));
			}
			else if (Terrain == "Lava") {
				attron(COLOR_PAIR(boss_Lava));
			}
			else if (Terrain == "Wasteland") {
				attron(COLOR_PAIR(boss_wasteland));
			}
			else if (Terrain == "City") {
				attron(COLOR_PAIR(boss_city));
			}
			else if (Terrain == "Fog") {
				if (fogged)
					attron(COLOR_PAIR(fog));
				else
					attron(COLOR_PAIR(boss_fog));
			}
			else
				attron(COLOR_PAIR(7));
		}
		mvprintw(13 - posy - inf, 1 + posx + inf2, "o");
	}
	else if (RoomType == "Final Boss") {
		if (gray)
			attron(COLOR_PAIR(8));
		else
			attron(COLOR_PAIR(7));
		mvprintw(13 - posy - inf, 1 + posx + inf2, "&");
	}
	else if (RoomType == "Empty") {
		if (gray)
			attron(COLOR_PAIR(8));
		else
			standend();
		if(infinite)
			mvprintw(13 - posy - inf, 1 + posx + inf2, "o");
		else
			mvprintw(13 - posy - inf, 1 + posx + inf2, ".");
	}

	standend();

	if (amnesia && !clear) {
		if (infinite)
			mvprintw(13 - posy - inf, 1 + posx + inf2, "?");
		else
			mvprintw(13 - posy - inf, 1 + posx + inf2, "?");
	}

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
