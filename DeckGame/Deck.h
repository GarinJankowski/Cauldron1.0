#pragma once
#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <string>
#include <vector>

#include "Card.h"


using namespace std;

class Deck
{
public:
	Deck();
	~Deck();

	vector<Card> cardDeck;
	int size();

	Card addCard(Card cardToBeAdded);
	Card removeCard(Card cardToBeRemoved, Character &guy);
	Card at(int i);
	void deckScreen();

	//trait specific functions
	void setBlackout();
};

#endif // DECK_H