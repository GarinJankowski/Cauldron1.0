#pragma once
#ifndef INPUTBOARD_H
#define INPUTBOARD_H
#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <string>
#include <vector>

#include "Character.h"
#include "TextLog.h"
#include "Enemy.h"
#include "Card.h"
#include "Deck.h"
#include "Gear.h"

using namespace std;

class InputBoard
{
public:
	InputBoard(Deck &deck, Character &guy);
	~InputBoard();

	vector<Card> Draw;
	vector<Card> Discard;
	vector<Card> DecisionCards;

	vector<Gear> inventory;
	Gear hands;
	Gear body;
	Gear head;

	Gear pickup;

	vector<Gear> handsNorm;
	vector<Gear> handsLate;
	vector<Gear> handsRare;

	vector<Gear> bodyNorm;
	vector<Gear> bodyLate;
	vector<Gear> bodyRare;

	vector<Gear> headNorm;
	vector<Gear> headRare;

	vector<Card> specialNorm;
	vector<Card> specialRare;
	vector<Card> specialDecision;

	vector<Gear> AvailableTraitsSacrifice;
	vector<Gear> AvailableTraitsReward;
	vector<Gear> Traits;
	vector<Gear> TraitsDecision;

	vector<Enemy> bosses;

	Enemy FinalBoss;

	const char* negative;

	const char *RoomType;

	void setRoom(const char *type);
	void ShuffleAddPrint();
	Card removeCard();
	void getchCard(Character &guy, Enemy &enemy, Deck &deck, TextLog &log);
	void getchDecision(Character &guy, Deck &deck, TextLog &log);
	void printDecision(Character &guy, TextLog &log);
	bool checkUsable(Character &guy, Enemy &enemy);
	bool checkUsable(int i, Character &guy, Enemy &enemy);

	Enemy generateEnemy(Character &guy);
	void startBattle(Character &guy, Deck &deck, TextLog &log);
	void effectsBeforeTurns(Character &guy, Enemy &enemy, Deck &deck, TextLog &log);
	void restoreAfterBattle(Character &guy, Enemy &enemy, Deck &deck, TextLog &log);

	void showInventory(Character &guy, Deck &deck);
	void inventoryLoopWhole(Character &guy, Deck &deck);
	void inventoryLoopItem(Gear &item, Character &guy, Deck &deck);
	void removeGear(Gear &item);
	void generateGear(Character &guy);
	void generateSpecial();

	void showTraits();
	void traitsLoopWhole();
	void generateTraits();

	void addNegative(Character &guy, Deck &deck);
	bool removeNegatives(Deck &deck);
	void restoreStats(Character &guy);
	void AddRemoveTrait(int pm, const char *Name);
	void fillHand(Character &guy);
	void shuffleHand();

	void updateDeck(Deck &deck);
	void clearBoard();

	//special other stuff
	bool Third_Eye = FALSE;
};

#endif //INPUTBOARD_H