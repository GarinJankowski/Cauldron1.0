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

	void HandsDescription();
	void BodyDescription();
	void HeadDescription();
	void ModDescription();
	void TraitSDescription();
	void TraitRDescription();

	void GearOnOrOff(bool On, Character &guy, Deck &deck);
	void HandsOnOrOff(bool On, Character &guy, Deck &deck);
	void BodyOnOrOff(bool On, Character &guy, Deck &deck);
	void HeadOnOrOff(bool On, Character &guy, Deck &deck);

	void TraitOnOrOff(bool On, Character &guy, Deck &deck);
	void SacrificeOnOrOff(bool On, Character &guy, Deck &deck);
	void RewardOnOrOff(bool On, Character &guy, Deck &deck);

	void CardOnOrOff(bool On, Character &guy, Deck &deck);
	void printGear(int position, Character &guy);
};

#endif //GEAR_H
