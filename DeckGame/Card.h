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
	bool pierce = FALSE;
	bool copyUsed = FALSE;
	int pummel = 2;
	
	void printCard(int position);
	int dealDamage(int damage, Character &guy, Enemy &enemy, TextLog &log);
	int gainBlock(int block, Character &guy, Enemy &enemy);
	void cardFunction(Character &guy, Enemy &enemy, TextLog &log);
};

#endif //CARD_H