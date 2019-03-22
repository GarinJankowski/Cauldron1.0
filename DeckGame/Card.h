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
	Card();
	Card(const char *name);
	~Card();

	const char *CardName;
	const char *CardType;
	const char *Description;
	int ManaCost;

	//variables for specific cards
	bool naturalBurn = FALSE;
	bool pierce = FALSE;
	bool copyUsed = FALSE;
	int pummel = 2;
	bool chaos = FALSE;

	//Modification variables
	bool Burn = FALSE;
	int Stay = 0;
	int tempStay = 0;
	bool StayCard = FALSE;
	bool Flow = FALSE;
	bool Copy = FALSE;
	bool Push = FALSE;
	bool Void = FALSE;
	int Link = 0;

	//variables for traits
	bool blackout = FALSE;
	int combobreaker = 0;
	int memorylapse = 0;
	void resetTraitValues();

	void setAttack();
	void setDefend();
	void setSpell();
	void setboss();
	void setNegative();
	
	void printCard(int position, Character &guy);
	int dealDamage(int damage, Character &guy, Enemy &enemy, TextLog &log);
	int dealDamageStrategy(int damage, Character &guy, Enemy &enemy);
	int gainBlock(int block, Character &guy, Enemy &enemy);
	int gainBlockStrategy(int block, Character &guy, Enemy &enemy);
	int gainEnergy(int energy, Character &guy, Enemy &enemy);
	void polymorph(Character &guy, Enemy &enemy);
	void setType();

	void setMod(string Mod, bool On, Character &guy);
	void setStay();
	string modchars();
	string modstrings();
	void removeMods(Character &guy);
	bool checkSameMods(Card kard);

	void cardFunction(Character &guy, Enemy &enemy, TextLog &log);
	void attackFunction(Character &guy, Enemy &enemy, TextLog &log);
	void defendFunction(Character &guy, Enemy &enemy, TextLog &log);
	void spellFunction(Character &guy, Enemy &enemy, TextLog &log);
	void bossFunction(Character &guy, Enemy &enemy, TextLog &log);
	void negativeFunction(Character &guy, Enemy &enemy, TextLog &log);
};

#endif //CARD_H