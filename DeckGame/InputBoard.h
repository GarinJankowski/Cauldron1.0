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
	vector<Gear> handsNormREFILL;
	vector<Gear> handsLate;
	vector<Gear> handsLateREFILL;
	vector<Gear> handsRare;

	vector<Gear> bodyNorm;
	vector<Gear> bodyNormREFILL;
	vector<Gear> bodyLate;
	vector<Gear> bodyLateREFILL;
	vector<Gear> bodyRare;

	vector<Gear> headNorm;
	vector<Gear> headRare;

	vector<Card> bossNorm;
	vector<Card> bossNormREFILL;
	vector<Card> bossDecision;

	vector<Card> AvailableSpells;
	vector<Card> spellDecision;

	vector<Gear> AvailableTraitsSacrifice;
	vector<Gear> AvailableTraitsSacrificeREFILL;
	vector<Gear> AvailableTraitsReward;
	vector<Gear> AvailableTraitsRewardREFILL;
	vector<Gear> Traits;
	vector<Gear> TraitsDecision;

	vector<Enemy> bosses;
	vector<Enemy> bossesREFILL;

	Enemy tierone;
	Enemy tiertwo;
	Enemy tierthree1;
	Enemy tierthree2;

	Enemy FinalBoss;

	vector<Card> shopAttacks;
	vector<Card> shopAttacksREFILL;
	vector<Card> shopDefends;
	vector<Card> shopDefendsREFILL;
	//shop items
		//attacks $12
	Card shopA;
	Card shopB;
	Card shopC;
		//defends $12
	Card shopD;
	Card shopE;
	Card shopF;
		//spells $18
	Card shopG;
	Card shopH;
	Card shopI;
		//bosss $40
	Card shopJ;
	Card shopK;
	Card shopL;
		//gear $20
	Gear shopM;
	Gear shopN;
	Gear shopO;
		//mods $15
	string shopP;
	string shopQ;
	string shopR;

	bool up = TRUE;
	bool right = TRUE;
	bool down = FALSE;

	bool pushthisturn = FALSE;
	int linkdraw = 0;
	const char* negative;

	const char *RoomType;
	const char *Terrain;
	bool extraCombat = TRUE;
	bool extraCauldron = TRUE;
	bool extraForge = TRUE;

	void setRoom(const char *type, const char *terrain);
	void ShuffleAddPrint(Character &guy);
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
	bool checkDead(Character &guy, Enemy &enemy, TextLog &log);
	void printDisplayStats(Character &guy, Enemy &enemy, Deck &deck, TextLog &log);

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
	void generateboss();

	void showTraits();
	void traitsLoopWhole();
	void generateTraits();

	void showTerrain();
	void terrainLoopWhole();

	void addNegative(Character &guy, Deck &deck);
	bool removeNegatives(Deck &deck);
	void restoreStats(Character &guy);
	void AddRemoveTrait(int pm, const char *Name);
	void fillHand(Character &guy);
	void shuffleHand(Character &guy);

	int gainBlock(int block, Character &guy);
	int gainEnergy(int energy, Character &guy, Enemy &enemy, TextLog &log);
	void updateDeck(Deck &deck);
	void clearBoard();
	void clearBoardWhole();

	int shopnum = 0;
	int shopnum2 = 1;
	bool shopRoom = FALSE;
	int generateGold(Enemy &enemy);
	void generateShop();
	void printShop(Character &guy);
	void getchShop(Character &guy, Deck &deck, TextLog &log);

	bool restart = FALSE;
	bool quit = FALSE;
	string currentEnemyName;
	void win(Character &guy, Deck &deck, TextLog &log, bool gamewin);

	//other stuff
	int negotiateStep;
	bool Negotiate(Character &guy, Enemy &enemy, Deck &deck, TextLog &log);
	bool NegotiateGive(Character &guy, Enemy &enemy, Deck &deck, TextLog &log);
	void polymorph(Character &guy, Enemy &enemy);
	void teleport(Character &guy, Deck &deck, TextLog &log);
	bool Third_Eye = FALSE;
	bool Tail = FALSE;
	bool teleported = FALSE;
};

#endif //INPUTBOARD_H