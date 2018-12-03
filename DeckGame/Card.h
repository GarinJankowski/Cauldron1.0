#pragma once
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <string>
#include <vector>

#include "Character.h"
#include "TextLog.h"
#include "Enemy.h"

class Card
{
public:
	Card(const char *name);
	~Card();

	const char *CardName;
	const char *CardType;
	const char *Description;
	int ManaCost;

	//variables for special cards
	bool naturalBurn = FALSE;
	bool pierce = FALSE;
	bool copyUsed = FALSE;
	int pummel = 2;

	//Modification variables
	bool Burn = FALSE;
	bool Stay = FALSE;
	bool StayCard = FALSE;
	bool Flow = FALSE;
	bool Copy = FALSE;
	bool Push = FALSE;
	bool Void = FALSE;
	int Link = 0;

	void setAttack();
	void setDefend();
	void setSpell();
	void setSpecial();
	void setNegative();
	
	void printCard(int position);
	int dealDamage(int damage, Character &guy, Enemy &enemy, TextLog &log);
	int gainBlock(int block, Character &guy, Enemy &enemy);

	void setMod(string Mod, bool On, Character &guy);
	string modchars();
	string modstrings();
	void removeMods(Character &guy);
	bool checkSameMods(Card kard);

	void cardFunction(Character &guy, Enemy &enemy, TextLog &log);
	void attackFunction(Character &guy, Enemy &enemy, TextLog &log);
	void defendFunction(Character &guy, Enemy &enemy, TextLog &log);
	void spellFunction(Character &guy, Enemy &enemy, TextLog &log);
	void specialFunction(Character &guy, Enemy &enemy, TextLog &log);
	void negativeFunction(Character &guy, Enemy &enemy, TextLog &log);
};

#endif //CARD_H