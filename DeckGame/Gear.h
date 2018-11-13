#pragma once
#ifndef GEAR_H
#define GEAR_H

#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <string>
#include <vector>

#include "Character.h"
#include "Card.h"
#include "Deck.h"

class Gear
{
public:
	Gear();
	Gear(const char *name);
	~Gear();

	const char *GearName;
	const char *Description;
	const char *Type;

	void GearOnOrOff(bool On, Character &guy, Deck &deck);
	void printGear(int position);
};

#endif //GEAR_H
