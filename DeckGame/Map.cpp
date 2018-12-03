#include "pch.h"
#include "Map.h"


Map::Map()
{
	int cauldron = 12;
	int gearbody = 30;
	int gearhands = 30;
	int gearhead = 15;
	int boss = 10;

	int cauldronCounter = 0;
	for (int x = 0; x < 26; x++) {
		for (int y = 0; y < 8; y++) {
			if (x == 0 && y == 0) {
				Room start("First", 0, 0);
				roomList.push_back(start);
			}
			else if (x == 25 && y == 7) {
				Room fboss("Final Boss", 25, 7);
				roomList.push_back(fboss);
			}
			else {
				int rng;
				if(getTier(x, y) == 'A'){
					//combat, hands, body
					rng = rand() % 14;
					Room a;
					if (rng == 0 || rng == 1) {
						a = Room("Gear Hands", x, y);
					}
					else if (rng == 2 || rng == 3) {
						a = Room("Gear Body", x, y);
					}
					else if (rng == 4 || rng == 5) {
						a = Room("Gear Head", x, y);
					}
					else if (rng == 6) {
						a = Room("Cauldron", x, y);
					}
					else if (rng > 7 && rng <= 8) {
						a = Room("Mod", x, y);
						cauldronCounter++;
					}
					else {
						a = Room("Combat", x, y);
					}
					roomList.push_back(a);
				}
				else if (getTier(x, y) == 'B' || getTier(x, y) == 'C' || getTier(x, y) == 'D') {
					//combat, hands, body, head, cauldron, boss(very small chance)
					rng = rand() % 26;
					Room bcd;
					if (rng == 0) {
						bcd = Room("Gear Head", x, y);
					}
					else if (cauldronCounter < 12 && rng > 1 && rng <= 4) {
						bcd = Room("Cauldron", x, y);
						cauldronCounter++;
					}
					else if (rng > 4 && rng <= 8) {
						bcd = Room("Gear Body", x, y);
					}
					else if (rng > 9 && rng <= 13) {
						bcd = Room("Gear Hands", x, y);
					}
					else if (rng > 14 && rng <= 16) {
						bcd = Room("Mod", x, y);
					}
					else if (rng == 25) {
						bcd = Room("Boss", x, y);
					}
					else {
						bcd = Room("Combat", x, y);
					}
					roomList.push_back(bcd);
				}
				else if (getTier(x, y) == 'E') {
					//combat, hands, body, head, cauldron, boss
					rng = rand() % 22;
					Room e;
					if (cauldronCounter < 18 && (rng == 0 || rng == 21 || rng == 22)) {
						e = Room("Cauldron", x, y);
						cauldronCounter++;
					}
					else if (rng > 0 && rng <= 3) {
						e = Room("Gear Hands", x, y);
					}
					else if (rng > 3 && rng <= 6) {
						e = Room("Gear Body", x, y);
					}
					else if (rng > 6 && rng <= 7) {
						e = Room("Mod", x, y);
					}
					else if (rng > 16 && rng <= 18) {
						e = Room("Boss", x, y);
					}
					else {
						e = Room("Combat", x, y);
					}
					roomList.push_back(e);
				}
				else if (getTier(x, y) == 'F') {
					//combat, boss
					rng = rand() % 21;
					Room f;
					if (rng == 0 && cauldronCounter < 22) {
						f = Room("Cauldron", x, y);
						cauldronCounter++;
					}
					else if (rng > 0 && rng <= 4) {
						f = Room("Boss", x, y);
					}
					else {
						f = Room("Combat", x, y);
					}
					roomList.push_back(f);
				}
			}
		}
	}
}


Map::~Map()
{
}

Room Map::at(int i) {
	return roomList.at(i);
}

void Map::checkPosition(Character &guy, InputBoard &board) {
	for (int i = 0; i < roomList.size(); i++) {
		if (roomList.at(i).checkXY(guy.posx, guy.posy)) {
			board.RoomType = roomList.at(i).RoomType;
		}
	}
}

void Map::PrintWholeMap(Character &guy, InputBoard &board) {
	init_pair(9, COLOR_BLACK, COLOR_WHITE);
	guy.RoomUp = FALSE;
	guy.RoomRight = FALSE;

	//put procgen here
	for (int x = 0; x < 26; x++) {
		for (int y = 0; y < 8; y++) {
			for (int i = 0; i < roomList.size(); i++) {
				if (roomList.at(i).checkXY(x, y)) {
					roomList.at(i).PrintRoom(FALSE);
				}
				if (roomList.at(i).posx == guy.posx && roomList.at(i).posy == guy.posy)
					roomList.at(i).clear = TRUE;
				
				if (roomList.at(i).checkXY(guy.posx, guy.posy + 1)) {
					guy.RoomUp = TRUE;
				}
				if (roomList.at(i).checkXY(guy.posx + 1, guy.posy)) {
					guy.RoomRight = TRUE;
				}
			}
		}
	}
	checkPosition(guy, board);

	attron(COLOR_PAIR(9));
	mvprintw(13 - guy.posy, 1 + guy.posx, "@");
	attroff(COLOR_PAIR(9));
	standend();
}

char Map::getTier(int posx, int posy) {
	char tier = ' ';
	if (posy == 0) {
		if (posx > 0 && posx < 7)
			tier = 'A';
		else if (posx >= 7 && posx < 12)
			tier = 'B';
		else if (posx >= 12 && posx < 16)
			tier = 'C';
		else if (posx >= 16 && posx < 21)
			tier = 'D';
		else
			tier = 'E';
	}
	else if (posy == 1) {
		if (posx < 6)
			tier = 'A';
		else if (posx >= 6 && posx < 11)
			tier = 'B';
		else if (posx >= 11 && posx < 15)
			tier = 'C';
		else if (posx >= 15 && posx < 20)
			tier = 'D';
		else if (posx >= 20 && posx < 25)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 2) {
		if (posx < 5)
			tier = 'A';
		else if (posx >= 5 && posx < 10)
			tier = 'B';
		else if (posx >= 10 && posx < 14)
			tier = 'C';
		else if (posx >= 14 && posx < 19)
			tier = 'D';
		else if (posx >= 19 && posx < 24)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 3) {
		if (posx < 4)
			tier = 'A';
		else if (posx >= 4 && posx < 9)
			tier = 'B';
		else if (posx >= 9 && posx < 13)
			tier = 'C';
		else if (posx >= 13 && posx < 18)
			tier = 'D';
		else if (posx >= 18 && posx < 23)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 4) {
		if (posx < 3)
			tier = 'A';
		else if (posx >= 3 && posx < 8)
			tier = 'B';
		else if (posx >= 8 && posx < 12)
			tier = 'C';
		else if (posx >= 12 && posx < 17)
			tier = 'D';
		else if (posx >= 17 && posx < 22)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 5) {
		if (posx < 2)
			tier = 'A';
		else if (posx >= 2 && posx < 7)
			tier = 'B';
		else if (posx >= 7 && posx < 11)
			tier = 'C';
		else if (posx >= 11 && posx < 16)
			tier = 'D';
		else if (posx >= 16 && posx < 21)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 6) {
		if (posx < 1)
			tier = 'A';
		else if (posx >= 1 && posx < 6)
			tier = 'B';
		else if (posx >= 6 && posx < 10)
			tier = 'C';
		else if (posx >= 10 && posx < 15)
			tier = 'D';
		else if (posx >= 15 && posx < 20)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 7) {
		if (posx < 5)
			tier = 'B';
		else if (posx >= 5 && posx < 9)
			tier = 'C';
		else if (posx >= 9 && posx < 14)
			tier = 'D';
		else if (posx >= 14 && posx < 19)
			tier = 'E';
		else
			tier = 'F';
	}
	
	return tier;
}

void Map::UpdateMap(Character &guy, InputBoard &board) {
	checkPosition(guy, board);
	attron(COLOR_PAIR(9));
	mvprintw(13 - guy.posy, 1 + guy.posx, "@");
	attroff(COLOR_PAIR(9));

	for (int i = 0; i < roomList.size(); i++) {
		if (roomList.at(i).checkXY(guy.posxBefore, guy.posyBefore)) {
			roomList.at(i).PrintRoom(TRUE);
			//mvprintw(5, 60, "%i, %i", guy.posxBefore, guy.posyBefore);
			//mvprintw(6, 60, "%i, %i", guy.posx, guy.posy);
		}
	}
	standend();
}


/*generation ideas

--map difficulty gradient--

eeeeeeffffffgggggghhhhhhh&
deeeeeeeffffffgggggghhhhhh
dddeeeeeeeefffffgggggghhhh
ddddddeeeeeeefffffggggghhh
cccddddddeeeeeefffffgggghh
bbbcccddddddeeeeefffffgggg
aabbbbccccddddeeeeefffffgg
#aaabbbbbccccddddeeefffffg


  11111 222222222 33333333333  &
  111111 222222222 33333333333
  1111111 222222222 3333333333
  11111111 222222222 333333333
  111111111 222222222 33333333
  1111111111 222222222 3333333
  11111111111 222222222 333333
@  11111111111 222222222 33333


CURRENT GRID
 bbbbb cccc ddddd eeeee fffffff
a bbbbb cccc ddddd eeeee ffffff
aa bbbbb cccc ddddd eeeee fffff
aaa bbbbb cccc ddddd eeeee ffff
aaaa bbbbb cccc ddddd eeeee fff
aaaaa bbbbb cccc ddddd eeeee ff
aaaaaa bbbbb cccc ddddd eeeee f
aaaaaaa bbbbb cccc ddddd eeeee

---enemy general difficulty order---
rat
crab
hound
zombie
kobold
themed (basic)

giant rat
wild buffalo
harpy
fairy
themed (mid)
brown recluse

fairy
Adventurer
Troll
Elemental
themed (high)

bosses

final bosses

*/