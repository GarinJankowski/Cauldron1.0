#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <string>

#include "Character.h"
#include "TextLog.h"

using namespace std;

void mvprintInSize(int starty, int startx, int maxx, const char* toBePrinted, bool Fuzzy);

//abstract enemy class
class Enemy
{
public:
	Enemy();
	Enemy(const char *name);
	~Enemy();

	//enemy stats
	const char *Name;
	int MaxHealth;
	int CurrentHealth;
	int CurrentBlock;
	bool Alive = TRUE;

	int TurnCount;
	int dot;
	bool charge;
	int extraTurns;
	bool cardAdded;
	int invisible;
	int type;
	int enemyNegate;
	bool stepOne;
	bool stepTwo;

	int numA;

	int sandstorm;
	int bleeding;
	int fumes;
	int flay;

	//enemy moves
	void Turn(Character &guy, TextLog &log);
	void ActivateDOT(Character &guy, TextLog &log);
	int takeDamage(int damage, Character &guy, TextLog &log);
	//print monster info
	void updateEnemy(Character &guy) {
		for (int i = 7; i < 9; i++) {
			mvprintw(i, 29, "             ");
		}

		if (CurrentHealth <= 0) {
			Alive = FALSE;
			guy.extraTurns = 0;
		}
		int n = (strlen(Name))/2;
		
		if (invisible > 0)
			attron(COLOR_PAIR(2));
		else
			standend();

		//Blind trait
		bool fuzzy = FALSE;
		if (guy.Blind)
			fuzzy = TRUE;

		string stat = string(Name);
		mvprintInSize(6, 35 - n, 0, stat.c_str(), fuzzy);

		mvprintInSize(7, 35, 0, "/", fuzzy);

		stat = to_string(MaxHealth) + ")  ";
		mvprintInSize(7, 36, 0, stat.c_str(), fuzzy);

		stat = "  (" + to_string(CurrentHealth);
		if (CurrentHealth >= 100)
			mvprintInSize(7, 29, 0, stat.c_str(), fuzzy);
		else if (CurrentHealth >= 10)
			mvprintInSize(7, 30, 0, stat.c_str(), fuzzy);
		else if (CurrentHealth >= 0)
			mvprintInSize(7, 31, 0, stat.c_str(), fuzzy);

		if (enemyNegate > 0) {
			stat = "Block: " + to_string(CurrentBlock) + "    ";
			mvprintInSize(8, 29, 0, stat.c_str(), fuzzy);
			stat = "(" + to_string(enemyNegate) + ")";
			mvprintInSize(8, 39, 0, stat.c_str(), fuzzy);
		}
		else {
			stat = "  Block: " + to_string(CurrentBlock) + "  ";
			mvprintInSize(8, 29, 0, stat.c_str(), fuzzy);
			mvprintInSize(8, 41, 0, " ", fuzzy);
		}
		
		standend();
	}
	//stat changes
	void heal(int health) {
		if ((MaxHealth - CurrentHealth) < health) {
			CurrentHealth = MaxHealth;
		}
		else {
			CurrentHealth += health;
		}
	}

	//other stuff
	string negotiate1;
	string negotiate2;
	string negotiate2b;
	string you1;
	string you2;
	string you2b;
	string you3;
	string price;
	void initNegotiateLines();
};
/*               TEMPLATE
------------------------------------------
class Kobold : public Enemy {
public:
	Kobold();
	void Turn(Character &guy, TextLog &log);
};
------------------------------------------
*/

#endif //ENEMY_H