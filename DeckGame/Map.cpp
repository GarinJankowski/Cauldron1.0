#include "pch.h"
#include "Map.h"


Map::Map(bool inf, int itier, int ifloor) :infinite(inf), infiniteTier(itier), infiniteFloor(ifloor)
{
	if (infinite) {
		generateTerrain();
		if (infiniteFloor == 1) {
			for (int x = 0; x < 13; x++) {
				for (int y = 0; y < 4; y++) {
					if (x == 0 && y == 0) {
						if (infiniteTier == 1) {
							Room start("First", 0, 0, TRUE);
							start.Terrain = "";
							roomList.push_back(start);
						}
						else {
							Room start("Empty", 0, 0, TRUE);
							start.Terrain = "";
							roomList.push_back(start);
						}
					}
					else if (x == 12 && y == 3) {
						Room boss("Boss", 12, 3, TRUE);
						boss.Terrain = "";
						roomList.push_back(boss);
					}
					else {
						Room r;
						int rng = rand() % 13;
						if (rng == 0) {
							r = Room("Mod", x, y, TRUE);
						}
						else if (rng == 1) {
							r = Room("Gear Head", x, y, TRUE);
						}
						else if (rng >= 2 && rng < 4) {
							r = Room("Gear Body", x, y, TRUE);
						}
						else if (rng >= 4 && rng < 6) {
							r = Room("Gear Hands", x, y, TRUE);
						}
						else {
							r = Room("Combat", x, y, TRUE);
						}
						r.Terrain = terrainGridInfinite[x][y];
						roomList.push_back(r);
					}
				}
			}
		}
		else if (infiniteFloor == 2) {
			for (int x = 0; x < 13; x++) {
				for (int y = 0; y < 4; y++) {
					if (x == 0 && y == 0) {
						Room start("Empty", 0, 0, TRUE);
						start.Terrain = "";
						roomList.push_back(start);
					}
					else if (x == 12 && y == 3) {
						Room boss("Boss", 12, 3, TRUE);
						boss.Terrain = "";
						roomList.push_back(boss);
					}
					else if ((x == 11 && y == 3) || (x == 12 && y == 2)) {
						Room shop("Shop", x, y, TRUE);
						shop.Terrain = terrainGridInfinite[x][y];
						roomList.push_back(shop);
					}
					else {
						Room r;
						int rng = rand() % 13;
						if (rng == 0) {
							r = Room("Mod", x, y, TRUE);
						}
						else if (rng == 1) {
							r = Room("Gear Head", x, y, TRUE);
						}
						else if (rng >= 2 && rng < 4) {
							r = Room("Gear Body", x, y, TRUE);
						}
						else if (rng >= 4 && rng < 6) {
							r = Room("Gear Hands", x, y, TRUE);
						}
						else {
							r = Room("Combat", x, y, TRUE);
						}
						r.Terrain = terrainGridInfinite[x][y];
						roomList.push_back(r);
					}
				}
			}

		}
		else {
			for (int x = 0; x < 13; x++) {
				for (int y = 0; y < 4; y++) {
					if (x == 0 && y == 0) {
						Room start("Empty", 0, 0, TRUE);
						start.Terrain = "";
						roomList.push_back(start);
					}
					else if (x == 12 && y == 3) {
						Room boss("Final Boss", 12, 3, TRUE);
						boss.Terrain = "";
						roomList.push_back(boss);
					}
					else if ((x == 11 && y == 3) || (x == 12 && y == 2)) {
						Room boss("Boss", x, y, TRUE);
						boss.Terrain = terrainGridInfinite[x][y];
						roomList.push_back(boss);
					}
					else {
						Room r;
						int rng = rand() % 13;
						if (rng == 0 || rng == 1) {
							r = Room("Mod", x, y, TRUE);
						}
						else if (rng >= 2 && rng < 4) {
							r = Room("Gear Body", x, y, TRUE);
						}
						else if (rng >= 4 && rng < 6) {
							r = Room("Gear Hands", x, y, TRUE);
						}
						else {
							r = Room("Combat", x, y, TRUE);
						}
						r.Terrain = terrainGridInfinite[x][y];
						roomList.push_back(r);
					}
				}
			}
		}
	}
	else {
		int cauldron = 12;
		int gearbody = 30;
		int gearhands = 30;
		int gearhead = 15;
		int boss = 10;

		int cauldronCounter = 0;
		int cauldronx = 0;
		int cauldrony = 2;
		int shopCounter = 0;

		generateTerrain();

		for (int x = 0; x < 26; x++) {
			for (int y = 0; y < 8; y++) {
				if (x == 0 && y == 0) {
					//Room start("First", 0, 0);
					Room start("First", 0, 0, FALSE);
					start.Terrain = "";
					roomList.push_back(start);
				}
				else if (x == 25 && y == 7) {
					Room fboss("Final Boss", 25, 7, FALSE);
					fboss.Terrain = "";
					roomList.push_back(fboss);
				}
				else {
					int rng;
					if (getTier(x, y) == 'A') {
						//combat, hands, body
						rng = rand() % 14;
						Room a;
						if (rng == 0 || rng == 1) {
							a = Room("Gear Hands", x, y, FALSE);
						}
						else if (rng == 2 || rng == 3) {
							a = Room("Gear Body", x, y, FALSE);
						}
						else if (rng == 4 || rng == 5) {
							a = Room("Gear Head", x, y, FALSE);
						}
						else if (rng == 6) {
							a = Room("Cauldron", x, y, FALSE);
							cauldronCounter++;
						}
						else if (rng > 7 && rng <= 8) {
							a = Room("Mod", x, y, FALSE);
						}
						else {
							a = Room("Combat", x, y, FALSE);
						}
						a.Terrain = terrainGrid[x][y];
						roomList.push_back(a);
					}
					else if (getTier(x, y) == 'B' || getTier(x, y) == 'C' || getTier(x, y) == 'D') {
						//combat, hands, body, head, cauldron, boss(very small chance)
						rng = rand() % 22;
						Room bcd;
						if (rng == 0) {
							bcd = Room("Gear Head", x, y, FALSE);
						}
						else if (cauldronCounter < 12 && rng > 1 && rng <= 3) {
							bcd = Room("Cauldron", x, y, FALSE);
							cauldronCounter++;
						}
						else if (rng > 4 && rng <= 7) {
							bcd = Room("Gear Body", x, y, FALSE);
						}
						else if (rng > 9 && rng <= 12) {
							bcd = Room("Gear Hands", x, y, FALSE);
						}
						else if (rng > 14 && rng <= 15) {
							bcd = Room("Mod", x, y, FALSE);
						}
						else if (rng == 20 && getTier(x, y) != 'B' && rand() % 8 < 6) {
							bcd = Room("Shop", x, y, FALSE);
						}
						else if (rng == 21) {
							bcd = Room("Boss", x, y, FALSE);
						}
						else {
							bcd = Room("Combat", x, y, FALSE);
						}
						bcd.Terrain = terrainGrid[x][y];
						roomList.push_back(bcd);
					}
					else if (getTier(x, y) == 'E') {
						//combat, hands, body, head, cauldron, boss
						rng = rand() % 22;
						Room e;
						if (cauldronCounter < 18 && (rng == 0 || rng == 21)) {
							e = Room("Cauldron", x, y, FALSE);
							cauldronCounter++;
						}
						else if (rng > 0 && rng <= 3) {
							e = Room("Gear Hands", x, y, FALSE);
						}
						else if (rng > 3 && rng <= 6) {
							e = Room("Gear Body", x, y, FALSE);
						}
						else if (rng > 6 && rng <= 7) {
							e = Room("Mod", x, y, FALSE);
						}
						else if (rng > 16 && rng <= 18) {
							e = Room("Boss", x, y, FALSE);
						}
						else if (rng == 19 && rand() % 5 < 3) {
							e = Room("Shop", x, y, FALSE);
						}
						else {
							e = Room("Combat", x, y, FALSE);
						}
						e.Terrain = terrainGrid[x][y];
						roomList.push_back(e);
					}
					else if (getTier(x, y) == 'F') {
						//combat, boss
						rng = rand() % 21;
						Room f;
						if (rng == 0 && cauldronCounter < 22) {
							f = Room("Cauldron", x, y, FALSE);
							cauldronCounter++;
						}
						else if (rng > 0 && rng <= 4) {
							f = Room("Boss", x, y, FALSE);
						}
						else if (rng == 5 && rand() % 2 == 0) {
							f = Room("Shop", x, y, FALSE);
							shopCounter++;
						}
						else {
							f = Room("Combat", x, y, FALSE);
						}

						if (x > 21 && y > 4 && shopCounter < 2 && !(x == 22 && y == 5) && rand() % 3 == 0) {
							f = Room("Shop", x, y, FALSE);
							shopCounter++;
						}
						if (x > 21 && y > 4 && !(x == 22 && y == 5)) {
							if (rand() % 7 > 3 && f.RoomType != "Shop") {
								f = Room("Boss", x, y, FALSE);
							}
						}

						f.Terrain = terrainGrid[x][y];
						roomList.push_back(f);
					}
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

			if (roomList.at(i).clear)
				board.RoomType = "Empty";

			guy.RoomType = board.RoomType;
			guy.Terrain = board.Terrain;

			if(roomList.at(i).RoomType != "Final Boss")
				roomList.at(i).clear = TRUE;
		}
	}
}

void Map::PrintMapNoUpdate(Character &guy) {
	int maxx = 26;
	int maxy = 8;
	if (infinite) {
		maxx = 13;
		maxy = 4;
	}

	for (int x = 0; x < maxx; x++) {
		for (int y = 0; y < maxy; y++) {
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
			}
		}
	}
}

void Map::PrintWholeMap(Character &guy) {
	init_pair(9, COLOR_BLACK, COLOR_WHITE);
	guy.RoomUp = FALSE;
	guy.RoomRight = FALSE;

	int maxx = 26;
	int maxy = 8;
	if (infinite) {
		maxx = 13;
		maxy = 4;
	}

	for (int x = 0; x < maxx; x++) {
		for (int y = 0; y < maxy; y++) {
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
				if (roomList.at(i).posx == guy.posx && roomList.at(i).posy == guy.posy && roomList.at(i).RoomType != "Final Boss")
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

	//checkPosition(guy, board);

	int inf = 0;
	int inf2 = 0;
	if (infinite) {
		inf = 2;
		inf2 = 7;
	}

	attron(COLOR_PAIR(9));
	mvprintw(13 - guy.posy - inf, 1 + guy.posx + inf2, "@");
	attroff(COLOR_PAIR(9));

	if (infinite) {
		string floor = "Floor: " + to_string(infiniteFloor+((infiniteTier-1)*3));
		string difficulty = "Difficulty: " + to_string(infiniteTier);

		int px = 10;
		if (infiniteFloor+((infiniteTier-1)*3) > 99)
			px++;
		if (infiniteFloor+((infiniteTier-1)*3) > 9999)
			px++;
		mvprintInSize(7, px, 0, floor.c_str(), FALSE);

		px = 8;
		if (infiniteFloor+((infiniteTier-1)*3) > 99)
			px++;
		if (infiniteFloor+((infiniteTier-1)*3) > 9999)
			px++;
		mvprintInSize(12, px, 0, difficulty.c_str(), FALSE);
	}

	standend();
}

void Map::generateTerrain() {
	if (infinite) {
		for (int x = 0; x < 13; x++) {
			for (int y = 0; y < 4; y++) {
				terrainGridInfinite[x][y] = "Fog";
			}
		}

		for (int i = 0; i < 2; i++) {
			if (rand() % 2 == 0) {
				generateCity();
			}
		}

		for (int i = 0; i < 7; i++) {
			if (rand() % 3 > 1) {
				generateSingleTerrain("Ice");
			}
			if (rand() % 3 > 1) {
				generateSingleTerrain("Forest");
			}
			if (rand() % 8 > 1) {
				generateSingleTerrain("Lava");
			}
			if (rand() % 7 > 4) {
				generateSingleTerrain("Wasteland");
			}
		}

		generateSingleTerrain("Ice");
		generateSingleTerrain("Forest");
		generateSingleTerrain("Lava");
		generateSingleTerrain("Wasteland");

		int iter = 6;
		if (rand() % 4 == 0) {
			if (rand() % 2 == 0) {
				iter++;
			}
			else {
				iter--;
			}
		}
		for (int i = 0; i < iter; i++) {
			for (int x = 0; x < 13; x++) {
				for (int y = 0; y < 4; y++) {
					generateSurroundingTerrain(x, y);
				}
			}
		}

		int citycount = 0;
		if (rand() % 5 == 0)
			citycount--;

		for (int i = 0; i < 5; i++) {
			if (rand() % 3 == 0 && citycount < 3) {
				generateCity();
				citycount++;
			}
		}

		for (int x = 0; x < 13; x++) {
			for (int y = 0; y < 4; y++) {
				if (rand() % 10 == 0 && !(x == 0 && y == 0) && !(x == 12 && y == 3)) {
					terrainGrid[x][y] = "Fog";
				}
			}
		}

		int treasurecount = rand() % 3 - 1;
		while (treasurecount < 2) {
			for (int x = 0; x < 13; x++) {
				for (int y = 0; y < 4; y++) {
					if (rand() % 80 == 0 && !(x == 0 && y == 0) && !(x == 12 && y == 3)) {
						terrainGridInfinite[x][y] = "Treasure";
						treasurecount++;
						if (treasurecount > 1)
							break;
					}
					if (treasurecount > 1)
						break;
				}
				if (treasurecount > 1)
					break;
			}
		}

		terrainGridInfinite[0][0] = " ";
		terrainGridInfinite[12][3] = " ";
	}
	else {
		for (int x = 0; x < 26; x++) {
			for (int y = 0; y < 8; y++) {
				terrainGrid[x][y] = "Fog";
			}
		}

		for (int i = 0; i < 3; i++) {
			if (rand() % 2 == 0) {
				generateCity();
			}
		}

		for (int i = 0; i < 8; i++) {
			if (rand() % 3 > 1) {
				generateSingleTerrain("Ice");
			}
			if (rand() % 3 > 1) {
				generateSingleTerrain("Forest");
			}
			if (rand() % 8 > 1) {
				generateSingleTerrain("Lava");
			}
			if (rand() % 7 > 4) {
				generateSingleTerrain("Wasteland");
			}
		}

		generateSingleTerrain("Ice");
		generateSingleTerrain("Forest");
		generateSingleTerrain("Lava");
		generateSingleTerrain("Wasteland");
		generateSingleTerrain("Ice");
		generateSingleTerrain("Forest");
		generateSingleTerrain("Lava");
		generateSingleTerrain("Wasteland");

		int iter = 4;
		if (rand() % 4 == 0) {
			if (rand() % 2 == 0) {
				iter++;
				if (rand() % 15 == 0) {
					iter++;
				}
			}
			else {
				iter--;
				if (rand() % 15 == 0) {
					iter--;
				}
			}
		}
		for (int i = 0; i < iter; i++) {
			for (int x = 0; x < 26; x++) {
				for (int y = 0; y < 8; y++) {
					generateSurroundingTerrain(x, y);
				}
			}
		}

		for (int i = 0; i < 6; i++) {
			if (rand() % 2 > 0) {
				generateCity();
			}
		}

		for (int x = 0; x < 26; x++) {
			for (int y = 0; y < 8; y++) {
				if (rand() % 10 == 0 && !(x == 0 && y == 0) && !(x == 25 && y == 7)) {
					terrainGrid[x][y] = "Fog";
				}
			}
		}

		int treasurecount = 0;
		while (treasurecount < 5) {
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
}

void Map::generateSingleTerrain(const char* terrain) {
	int maxx = 26;
	int maxy = 8;
	if (infinite) {
		maxx = 13;
		maxy = 4;
	}

	int randx = rand() % maxx;
	int randy = rand() % maxy;
	
	const char* terr = terrainGrid[randx][randy];
	if (infinite)
		terr = terrainGridInfinite[randx][randy];

	if (terr != "Fog" ||
		(randx == 0 && randy == 0) ||
		(randx == maxx-1 && randy == maxy-1) ||
		(terrain == "Forest" && randx < 12 && randy < 4 && !infinite)){
		return;
		generateSingleTerrain(terrain);
	}
	else {
		if (infinite)
			terrainGridInfinite[randx][randy] = terrain;
		else
			terrainGrid[randx][randy] = terrain;
	}
}

int Map::generateSurroundingTerrain(int x, int y) {
	int num = 0;
	const char* terr = " ";

	const char* ter1 = terrainGrid[x][y];
	if (infinite)
		ter1 = terrainGridInfinite[x][y];

	if (ter1 != "Fog" && ter1 != "City") {
		terr = ter1;
	}
	if (ter1 == terr && terr != " ") {
		int chance = 17;
		if (terr == "Lava")
			chance += 3;
		if (terr == "Wasteland")
			chance += 3;

		if (infinite) {
			chance += 3;
			if (terr == "Forest")
				chance+=3;
			if (terr == "Ice")
				chance++;
		}

		if (y > 0 && rand() % 25 > chance) {
			terrainGrid[x][y - 1] = terr;
			terrainGridInfinite[x][y - 1] = terr;
			num++;
		}
		if (x > 0 && rand() % 25 > chance) {
			terrainGrid[x - 1][y] = terr;
			terrainGridInfinite[x - 1][y] = terr;
			num++;
		}
		if (y < 7 && rand() % 25 > chance) {
			terrainGrid[x][y + 1] = terr;
			terrainGridInfinite[x][y + 1] = terr;
			num++;
		}
		if (x < 25 && rand() % 25 > chance) {
			terrainGrid[x + 1][y] = terr;
			terrainGridInfinite[x + 1][y] = terr;
			num++;
		}
		//numIce += num;
	}
	return num;
}

void Map::generateCity() {
	int maxx = 26;
	int maxy = 8;
	if (infinite) {
		maxx = 13;
		maxy = 4;
	}

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

	if (infinite) {
		sizex /= 2;
		sizex++;
		sizey /= 2;
		sizey++;
	}

	int posx = rand() % maxx;
	int posy = rand() % maxy;

	if (posx + sizex > maxx-1) {
		posx = maxx-1 - sizex;
	}
	if (posy + sizey > maxy-1) {
		posy = maxy-1 - sizey;
	}

	for (int x = posx; x < sizex+posx; x++) {
		for (int y = posy; y < sizey+posy; y++) {
			if (!(x == 0 && (y == 0 || y == 1)) && !(x == 1 && y == 0)) {
				terrainGrid[x][y] = "City";
				terrainGridInfinite[x][y] = "City";
			}
		}
	}

	if (rand() % 2 == 0 && !infinite) {
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
			if (!(x == 0 && (y == 0 || y == 1)) && !(x == 1 && y == 0))
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

void Map::UpdateMap(Character &guy) {
	//checkPosition(guy, board);

	for (int i = 0; i < roomList.size(); i++) {
		if (roomList.at(i).checkXY(guy.posxBefore, guy.posyBefore)) {
			if(roomList.at(i).RoomType != "Final Boss")
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

	int inf = 0;
	int inf2 = 0;
	if (infinite) {
		inf = 2;
		inf2 = 7;
	}

	attron(COLOR_PAIR(9));
	mvprintw(13 - guy.posy - inf, 1 + guy.posx + inf2, "@");
	attroff(COLOR_PAIR(9));

	if (infinite) {
		string floor = "Floor: " + to_string(infiniteFloor+((infiniteTier-1)*3));
		string difficulty = "Difficulty: " + to_string(infiniteTier);

		int px = 10;
		if (infiniteFloor+((infiniteTier-1)*3) > 99)
			px++;
		if (infiniteFloor+((infiniteTier-1)*3) > 9999)
			px++;
		mvprintInSize(7, px, 0, floor.c_str(), FALSE);

		px = 8;
		if (infiniteFloor+((infiniteTier-1)*3) > 99)
			px++;
		if (infiniteFloor+((infiniteTier-1)*3) > 9999)
			px++;
		mvprintInSize(12, px, 0, difficulty.c_str(), FALSE);
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
 bbbbb cccc ddddd eeeee ffffff&
a bbbbb cccc ddddd eeeee ffffff
aa bbbbb cccc ddddd eeeee fffff
aaa bbbbb cccc ddddd eeeee ffff
aaaa bbbbb cccc ddddd eeeee fff
aaaaa bbbbb cccc ddddd eeeee ff
aaaaaa bbbbb cccc ddddd eeeee f
@aaaaaa bbbbb cccc ddddd eeeee

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


---Terrain---

lightblue- Ice: when you enter ice you have to keep going in a straight line
yellow- Treasure: gain 25 gold here
green- Forest: you cant go the same direction you went before
orange- Lava: get two combat for each tile, cauldrons are empty
purple- Wasteland: get double cauldrons for each tile, everything else is empty
gray- Fog: cant see these tiles, if inside fog you see a 1 radius circle around you
dark gray- City: only themed enemies. double forges

*/