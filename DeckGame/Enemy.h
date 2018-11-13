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

	int bleeding;
	int fumes;

	//enemy moves
	void Turn(Character &guy, TextLog &log);
	void ActivateDOT(Character &guy, TextLog &log);
	int takeDamage(int damage, Character &guy, TextLog &log);
	//print monster info
	void updateEnemy(Character &guy) {
		for (int i = 6; i < 10; i++) {
			mvprintw(i, 29, "             ");
		}

		if (CurrentHealth <= 0) {
			Alive = FALSE;
			guy.extraTurns = 0;
		}
		int n = (strlen(Name))/2;
		
		if (invisible)
			attron(COLOR_PAIR(2));
		else
			standend();

		//Blind trait
		if (!guy.Blind) {
			mvprintw(6, 35 - n, "%s", Name);

			mvprintw(7, 35, "/");

			mvprintw(7, 36, "%d)  ", MaxHealth);

			if (CurrentHealth >= 100)
				mvprintw(7, 29, "  (%d", CurrentHealth);
			else if (CurrentHealth >= 10)
				mvprintw(7, 30, "  (%d", CurrentHealth);
			else if (CurrentHealth >= 0)
				mvprintw(7, 31, "  (%d", CurrentHealth);

			if (enemyNegate > 0) {
				mvprintw(8, 29, "Block: %d    ", CurrentBlock);
				mvprintw(8, 39, "(%d)", enemyNegate);
			}
			else {
				mvprintw(8, 29, "  Block: %d  ", CurrentBlock);
				mvprintw(8, 41, " ");
			}
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