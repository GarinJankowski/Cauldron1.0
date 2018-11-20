#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <string>



using namespace std;

class Character
{
public:
	Character();
	~Character();

	//character stats
	int MaxHealthBase = 40;
	int MaxHealth;
	int CurrentHealth;
	int MaxManaBase = 10;
	int MaxMana;
	int CurrentMana;
	int Strength;
	int Defense;
	int Intelligence;
	int Skill;
	int CurrentBlock;
	int Negate;

	int extraTurns;
	bool pierce;
	bool shuffle;
	const char* fillType = " ";
	bool cannotUse;

	//card specific mechanics
	int dotDamage = 0;
	int regenerateTurns = 0;
	int smoke = 0;
	int incense = 0;
	int damageToMana = 0;
	int mirror = 0;
	int mirrorDamage = 0;
	int copy = 0;
	int charge = 0;
	int chargeMana = 0;
	int metabolise = 0;
	bool steroids = FALSE;
	int intimidate = 0;
	int entomb = 0;
	int pummel = 2;

	int strMod;
	int defMod;
	int intMod;
	int hpMod;
	int mpMod;
	int sklMod;
	
	char tier;
	bool Alive;
	bool winBattle;
	bool Win;

	const char* negative;

	//for map stuff
	int posx;
	int posy;
	bool RoomUp;
	bool RoomRight;
	int posxBefore;
	int posyBefore;
	char getTier(int posx, int posy);
	char getTier();

	//Traits
	//sacrifice
		bool Anemia = FALSE;
		//Dumb bool isn't necessary
		//Mind Flooded bool isnt necessary
		//Tunnel Vision bool isnt necessary
		bool Teleportitis = FALSE;
		bool Growing_Pains = FALSE;
		bool Conversion = FALSE;
		bool Inversion = FALSE;
		int Jittery = -1;
		bool Tumors = FALSE;
		bool Devolve = FALSE;
		int Volatile = -1;
		bool Melting = FALSE;
		bool Dizzy = FALSE;
		int Long_Legs = 0;
		bool Oblivious = FALSE;
		bool Blind = FALSE;
		bool Numb = FALSE;
		bool Fast_Metabolism = FALSE;
		bool Deadly = FALSE;
		bool Undead = FALSE;
		bool The_Juice = FALSE;
		bool Radioactive = FALSE;
		bool Forgetful = FALSE;
		bool Succumb = FALSE;
	//Reward
		bool Mending_Flesh = FALSE;
		bool Gymnast = FALSE;
		bool Third_Eye = FALSE;
		int Warper = 0;
		bool Growth_Spurt = FALSE;
		bool Mind = FALSE;
		bool Matter = FALSE;
		bool Sharp_Claws = FALSE;
		bool Gift = FALSE;
		bool Unseen = FALSE;
		bool Spiny_Skin = FALSE;
		int SpinyDamage = 0;
		bool Adapt = FALSE;
		bool Wings = FALSE;
		bool WingsUsed = FALSE;
		bool Exoskeleton = FALSE;
		bool Crown = FALSE;
		bool Quick_Thinker = FALSE;
		int Foresight = -1;
		bool Photosynthesis = FALSE;
		bool Dexterous = FALSE;
		bool Reconstruction = FALSE;
		bool Carnivore = FALSE;
		bool Hemoglobin = FALSE;
		int Destiny = 0;

	//change stats
	int TakeDamage(int damageTaken);
	int DrainMana(int manaDrained);
	int ModStat(int bonus, string stat);

	//print character stuff
	void printDirectory();
	void printStats();
	void manaFlicker();
	void changePosBefore(char c, int i);

	//show inventory
	void showInventoryScreen();
};

#endif //CHARACTER_H