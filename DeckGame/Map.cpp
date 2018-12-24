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
	int shopCounter = 0;

	generateTerrain();

	for (int x = 0; x < 26; x++) {
		for (int y = 0; y < 8; y++) {
			if (x == 0 && y == 0) {
				//Room start("First", 0, 0);
				Room start("First", 0, 0);
				start.Terrain = "";
				roomList.push_back(start);
			}
			else if (x == 25 && y == 7) {
				Room fboss("Final Boss", 25, 7);
				fboss.Terrain = "";
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
					a.Terrain = terrainGrid[x][y];
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
					else if (rng == 24 && shopCounter < 1) {
						bcd = Room("Shop", x, y);
						shopCounter++;
					}
					else if (rng == 25) {
						bcd = Room("Boss", x, y);
					}
					else {
						bcd = Room("Combat", x, y);
					}
					bcd.Terrain = terrainGrid[x][y];
					roomList.push_back(bcd);
				}
				else if (getTier(x, y) == 'E') {
					//combat, hands, body, head, cauldron, boss
					rng = rand() % 22;
					Room e;
					if (cauldronCounter < 18 && (rng == 0 || rng == 21)) {
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
					else if (rng == 19 && shopCounter < 3) {
						e = Room("Shop", x, y);
						shopCounter++;
					}
					else {
						e = Room("Combat", x, y);
					}
					e.Terrain = terrainGrid[x][y];
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
					else if (rng == 5 && shopCounter < 4) {
						f = Room("Shop", x, y);
						shopCounter++;
					}
					else {
						f = Room("Combat", x, y);
					}
					f.Terrain = terrainGrid[x][y];
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
			board.Terrain = roomList.at(i).Terrain;
		}
	}
}

void Map::PrintWholeMap(Character &guy, InputBoard &board) {
	init_pair(9, COLOR_BLACK, COLOR_WHITE);
	guy.RoomUp = FALSE;
	guy.RoomRight = FALSE;

	for (int x = 0; x < 26; x++) {
		for (int y = 0; y < 8; y++) {
			for (int i = 0; i < roomList.size(); i++) {
				if (roomList.at(i).checkXY(x, y)) {
					//TERRAIN: Fog
					if (roomList.at(i).Terrain == "Fog") {
						if ((roomList.at(i).posx == guy.posx + 1 && roomList.at(i).posy == guy.posy + 1) ||
							(roomList.at(i).posx == guy.posx + 1 && roomList.at(i).posy == guy.posy - 1) || 
							(roomList.at(i).posx == guy.posx - 1 && roomList.at(i).posy == guy.posy - 1) || 
							(roomList.at(i).posx == guy.posx + 1 && roomList.at(i).posy == guy.posy + 1) || 
							(roomList.at(i).posx == guy.posx + 1 && roomList.at(i).posy == guy.posy) || 
							(roomList.at(i).posx == guy.posx && roomList.at(i).posy == guy.posy + 1) || 
							(roomList.at(i).posx == guy.posx - 1 && roomList.at(i).posy == guy.posy) || 
							(roomList.at(i).posx == guy.posx && roomList.at(i).posy == guy.posy - 1) ||
							(roomList.at(i).posx == guy.posx && roomList.at(i).posy == guy.posy)) {
							roomList.at(i).fogged = FALSE;
						}
						else {
							roomList.at(i).fogged = TRUE;
						}
					}
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

void Map::generateTerrain() {
	
	for (int x = 0; x < 26; x++) {
		for (int y = 0; y < 8; y++) {
			terrainGrid[x][y] = "Fog";
		}
	}

	for (int i = 0; i < 3; i++) {
		if (rand() % 2 == 0)
			generateCity();
	}

	for (int i = 0; i < 6; i++) {
		if (rand() % 3 > 1) {
			generateSingleTerrain("Ice");
		}
		if (rand() % 3 > 1) {
			generateSingleTerrain("Forest");
		}
		if (rand() % 7 > 3) {
			generateSingleTerrain("Magma");
		}
		if (rand() % 7 > 4) {
			generateSingleTerrain("Wasteland");
		}
	}

	generateSingleTerrain("Ice");
	generateSingleTerrain("Forest");
	generateSingleTerrain("Magma");
	generateSingleTerrain("Wasteland");

	for (int i = 0; i < 6; i++) {
		for (int x = 0; x < 26; x++) {
			for (int y = 0; y < 8; y++) {
				generateSurroundingTerrain(x, y);
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		if (rand() % 2 > 0)
			generateCity();
	}

	for (int x = 0; x < 26; x++) {
		for (int y = 0; y < 8; y++) {
			if (rand() % 10 == 0 && !(x == 0 && y == 0) && !(x == 25 && y == 7)) {
				terrainGrid[x][y] = "Fog";
			}
		}
	}

	int treasurecount = 0;
	while (treasurecount < 4) {
		for (int x = 0; x < 26; x++) {
			for (int y = 0; y < 8; y++) {
				if (rand() % 80 == 0 && !(x == 0 && y == 0) && !(x == 25 && y == 7)) {
					terrainGrid[x][y] = "Treasure";
					treasurecount++;
					if (treasurecount > 4)
						break;
				}
				if (treasurecount > 4)
					break;
			}
			if (treasurecount > 4)
				break;
		}
	}

	terrainGrid[0][0] = " ";
	terrainGrid[25][7] = " ";
}

void Map::generateSingleTerrain(const char* terrain) {
	int randx = rand() % 26;
	int randy = rand() % 8;

	if (terrainGrid[randx][randy] != "Fog" ||
		(randx == 0 && randy == 0) ||
		(randx == 25 && randy == 7) ||
		(terrain == "Forest" && randx < 12 && randy < 4)){
		return;
		generateSingleTerrain(terrain);
	}
	else {
		terrainGrid[randx][randy] = terrain;
	}
}

int Map::generateSurroundingTerrain(int x, int y) {
	int num = 0;
	const char* terr = " ";
	if(terrainGrid[x][y] != "Fog" && terrainGrid[x][y] != "City")
		 terr = terrainGrid[x][y];
	if (terrainGrid[x][y] == terr && terr != " ") {
		if (y > 0 && rand() % 25 > 17) {
			terrainGrid[x][y - 1] = terr;
			num++;
		}
		if (x > 0 && rand() % 25 > 17) {
			terrainGrid[x - 1][y] = terr;
			num++;
		}
		if (y < 7 && rand() % 25 > 17) {
			terrainGrid[x][y + 1] = terr;
			num++;
		}
		if (x < 25 && rand() % 25 > 17) {
			terrainGrid[x + 1][y] = terr;
			num++;
		}
		//numIce += num;
	}
	return num;
}

void Map::generateCity() {
	int sizex = rand() % 4 + 2;
	int sizey = rand() % 1 + 3;

	if (rand() % 40 == 0)
		sizex = 6;
	else if (rand() % 60 == 0)
		sizex = 7;

	if (rand() % 40 == 0)
		sizey = 5;
	else if (rand() % 60 == 0)
		sizey = 6;
	else if (rand() % 80 == 0)
		sizey = 7;

	int posx = rand() % 26;
	int posy = rand() % 8;

	if (posx + sizex > 25) {
		posx = 25 - sizex;
	}
	if (posy + sizey > 7) {
		posy = 7 - sizey;
	}

	for (int x = posx; x < sizex+posx; x++) {
		for (int y = posy; y < sizey+posy; y++) {
			terrainGrid[x][y] = "City";
		}
	}

	if (rand() % 2 == 0) {
		int px = rand() % sizex + posx + 1;
		int py = rand() % sizey + posy + 1;

		generateCity(px, py);
	}
}

void Map::generateCity(int px, int py) {
	int sizex = rand() % 4 + 2;
	int sizey = rand() % 1 + 3;

	if (rand() % 40 == 0)
		sizex = 6;
	else if (rand() % 60 == 0)
		sizex = 7;

	if (rand() % 40 == 0)
		sizey = 5;
	else if (rand() % 60 == 0)
		sizey = 6;
	else if (rand() % 80 == 0)
		sizey = 7;

	int posx = px;
	int posy = py;

	if (posx + sizex > 25) {
		posx = 25 - sizex;
	}
	if (posy + sizey > 7) {
		posy = 7 - sizey;
	}

	for (int x = posx; x < sizex + posx; x++) {
		for (int y = posy; y < sizey + posy; y++) {
			terrainGrid[x][y] = "City";
		}
	}
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
			roomList.at(i).clear = TRUE;
			roomList.at(i).PrintRoom(TRUE);
			//mvprintw(5, 60, "%i, %i", guy.posxBefore, guy.posyBefore);
			//mvprintw(6, 60, "%i, %i", guy.posx, guy.posy);
		}
		//TERRAIN: Fog
		else if (!roomList.at(i).clear && roomList.at(i).Terrain == "Fog" && (roomList.at(i).posx != guy.posx || roomList.at(i).posy != guy.posy)) {
			if ((roomList.at(i).posx == guy.posx + 1 && roomList.at(i).posy == guy.posy + 1) ||
				(roomList.at(i).posx == guy.posx + 1 && roomList.at(i).posy == guy.posy - 1) ||
				(roomList.at(i).posx == guy.posx - 1 && roomList.at(i).posy == guy.posy - 1) ||
				(roomList.at(i).posx == guy.posx - 1 && roomList.at(i).posy == guy.posy + 1) ||
				(roomList.at(i).posx == guy.posx + 1 && roomList.at(i).posy == guy.posy) ||
				(roomList.at(i).posx == guy.posx && roomList.at(i).posy == guy.posy + 1) ||
				(roomList.at(i).posx == guy.posx - 1 && roomList.at(i).posy == guy.posy) ||
				(roomList.at(i).posx == guy.posx && roomList.at(i).posy == guy.posy - 1)) {
				roomList.at(i).fogged = FALSE;
			}
			else {
				roomList.at(i).fogged = TRUE;
			}
			roomList.at(i).PrintRoom(FALSE);
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


Terrain:
lightblue- Ice: when you enter ice you have to keep going in a straight line
yellow- Treasure: gain 25 gold here
green- Forest: you cant go the same direction you went before
orange- Magma: get two combat for each tile, cauldrons are empty
purple- Wasteland: get double cauldrons for each tile, everything else is empty
gray- Fog: cant see these tiles, if inside fog you see a 1 radius circle around you
dark gray- City: ?

*/