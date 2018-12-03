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

	int handSize = 3;
	vector<Card> Draw;
	vector<Card> Discard;
	vector<Card> DecisionCards;

	int cardThere = 3;

	vector<Card> screendeck;
	vector<int> screendeckCounter;

	vector<Gear> inventory;
	Gear hands;
	Gear body;
	Gear head;

	Gear pickup;

	string pickup1;
	string pickup2;

	string modpickup1;
	string modpickup2;

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

	vector<Card> AvailableSpells;
	vector<Card> spellDecision;

	vector<Gear> AvailableTraitsSacrifice;
	vector<Gear> AvailableTraitsReward;
	vector<Gear> Traits;
	vector<Gear> TraitsDecision;

	vector<Enemy> bosses;

	Enemy tierone;
	Enemy tiertwo;
	Enemy tierthree1;
	Enemy tierthree2;

	Enemy FinalBoss;

	bool pushthisturn = FALSE;
	int linkdraw = 0;
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
	bool checkEnemyLife(Character &guy, Enemy &enemy, Deck &deck, TextLog &log);

	void showDeck(Character &guy, Deck &cardDeck, bool notbattle);
	void deckLoopWhole(Character &guy, Deck &cardDeck);
	void deckLoopCard(Character &guy, Deck &cardDeck, int modindex);
	void deckLoopMod(Character &guy, Deck &cardDeck, int modindex);
	void generateMods();

	void showMods(Character &guy, Deck &deck, bool notbattle);
	void modLoopWhole(Character &guy, Deck &deck, bool notbattle);
	void modLoopSecond(Character &guy, Deck &deck, bool notbattle);

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

	int gainBlock(int block, Character &guy);
	void updateDeck(Deck &deck);
	void clearBoard();
	void clearBoardWhole();

	//special other stuff
	int negotiateStep;
	bool Negotiate(Character &guy, Enemy &enemy, Deck &deck, TextLog &log);
	bool NegotiateGive(Character &guy, Enemy &enemy, Deck &deck, TextLog &log);
	bool Third_Eye = FALSE;
	bool Tail;
};

#endif //INPUTBOARD_H