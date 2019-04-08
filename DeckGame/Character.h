#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <string>

#include "TextLog.h"

using namespace std;

class Character
{
public:
	Character(bool inf, int itier, int iFloor);
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
	int Gold;
	int Energy;
	int MaxEnergy;

	int dotDamage = 0;

	int handSize = 3;

	int extraTurns;
	bool pierce;
	bool shuffle = FALSE;
	const char* fillType = " ";
	bool cannotUse;

	bool infinite;
	int infiniteTier;
	int infiniteFloor;

	//roomtype and terrain reference for functions that are not in the input board
	const char *RoomType;
	const char *Terrain;

	//card specific mechanics
	int ADDSteam = 0;
	int ADDScalding_Steam = 0;
	int ADDWebbed = 0;
	int ADDDrain_Str = 0;
	int ADDDrain_Def = 0;
	int ADDDrain_Int = 0;
	int ADDPatch = 0;
	int ADDBurn = 0;

	int regenerateTurns = 0;
	int smoke = 0;
	int incense = 0;
	int damageToMana = 0;
	int mirror = 0;
	int mirrorDamage = 0;
	int copy = 0;
	int charge = 0;
	int chargeMana = 0;
	int drown = 0;
	int refresh = 0;
	int reagent = 0;
	int empower = 0;
	int soldier = 0;
	int arise = 0;
	int horrify = 0;

	int metabolise = 0;
	bool steroids = FALSE;
	int intimidate = 0;
	int entomb = 0;
	int catalyze = 0;
	int ghost = 0;
	bool ghostPlayed = FALSE;
	int ghostinarow = 0;
	bool cleanse = FALSE;
	int tear = 0;
	bool teleport = FALSE;
	int inject = 0;
	int flurry = 0;
	int materialize = 0;
	int materializeTRUE = FALSE;
	int materializeblock = 0;
	int overdrive = 0;
	int overdrivestats = 0;
	int enrich = 0;
	int relax = 0;
	int sharpen = 0;
	int amplify = 0;
	bool amplifyTRUE = FALSE;
	int cell = 0;
	int deflect = 0;
	bool deflectTRUE = FALSE;
	int deflectdamage = 0;
	int save = 0;
	int stop = 0;
	int burncard = 0;
	bool burnPlayed = FALSE;
	int burninarow = 0;
	int stumble = 0;


	int strMod;
	int defMod;
	int intMod;
	int hpMod;
	int mpMod;
	int sklMod;
	int engMod;
	
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

	//modifiers
	int Burn;
	int Stay;
	int Flow;
	int Copy;
	int Push;
	int Void;
	int Link;

	//Traits
	//Sacrifice
		bool Anemia = FALSE;
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
		bool Frenzy = FALSE;
		bool Undead = FALSE;
		bool Radioactive = FALSE;
		bool Forgetful = FALSE;
		bool Succumb = FALSE;
		bool Slow = FALSE;
		int Sticky_Feet = -1;
		int Overconfidence = -1;
		bool Hallucinations = FALSE;
		bool Tail = FALSE;
		bool Weak_Back = FALSE;
		bool Charred_Skin = FALSE;
		bool Purple = FALSE;
		int Inefficient = -1;
		bool Gold_Flesh = FALSE;
		bool Terraform = FALSE;
		int Psychosis = -1;
		bool Dazed = FALSE;
		bool Strategy = FALSE;
		bool Doomed = FALSE;
		int Scented = -1;
		bool Timer = FALSE;
		bool Sacrificial = FALSE;
		bool Membrane = FALSE;
		bool Addiction = FALSE;
		bool Paranoia = FALSE;
		bool Sticky_Skin = FALSE;
		bool Flat_Feet = FALSE;
		int Muscle_Mass = -1;
		int Muscle_MassDamage = 0;
		int Panic_Attack = -1;
		bool Cursed = FALSE;
		bool Joint_Pain = FALSE;
		bool Daredevil = FALSE;
		bool Careless = FALSE;
		bool Hoarder = FALSE;
		int Atrophy = -1;
		int Burnout = -1;
		bool Blackout = FALSE;
		bool Combo_Breaker = FALSE;
		bool Memory_Lapse = FALSE;
		bool Stiff = FALSE;
		bool Ethereal = FALSE;
		int Falter = -1;
		int Exposed = -1;
		bool Circus = FALSE;
		bool Spiritual = FALSE;
		int Stuck = -1;
		bool Inert = FALSE;
		bool Lightweight = FALSE;
		bool Headache = FALSE;
		bool Reckless = FALSE;
		int Wasteful = -1;
		bool Strain = FALSE;
		bool Run = FALSE;
		bool Commitment = FALSE;
		bool Heavy = FALSE;
		bool Wind_Down = FALSE;
		bool Short_Circuit = FALSE;
		bool Empty = FALSE;
		bool Sore = FALSE;
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
		bool Ego = FALSE;
		bool Genius = FALSE;
		int Quick_Thinker = -1;
		int Foresight = -1;
		bool Photosynthesis = FALSE;
		bool Dexterous = FALSE;
		bool Reconstruction = FALSE;
		bool Carnivore = FALSE;
		bool Hemoglobin = FALSE;
		int Destiny = 0;
		int Scavenger = -1;
		int Horns = -1;
		bool Green_Scales = FALSE;
		bool Multi_Tongued = FALSE;
		bool negotiate = FALSE;
		bool Blacksmith = FALSE;
		bool Iron_Scabs = FALSE;
		bool Gelatinous = FALSE;
		bool Eight_Legs = FALSE;
		bool Heat_Walker = FALSE;
		int Metamorphosis = 0;
		bool Thick_Hide = FALSE;
		bool Gold_Bones = FALSE;
		int Absorption = -1;
		int Adrenaline = -1;
		bool Reaper = FALSE;
		bool Toxic_Release = FALSE;
		int Recycling = -1;
		bool Blue_Scales = FALSE;
		bool Red_Scales = FALSE;
		bool Curved_Tusks = FALSE;
		int Early_Riser = -1;
		bool Outer_Shell = FALSE;
		bool Resourceful = FALSE;
		bool Naturalist = FALSE;
		int Bounty_Hunter = -1;
		bool Scraps = FALSE;
		bool Tinkerer = FALSE;
		bool Magnetic = FALSE;
		bool Merchant = FALSE;
		int Conservation = -1;
		bool Vendor = FALSE;
		int Shock_Absorber = -1;
		bool Stamina = FALSE;
		bool Rested = FALSE;
		bool Midas_Touch = FALSE;
		int Exhaust_Vent = -1;
		int Fervor = -1;
		int FervorDamage = 0;
		bool Enlightened = FALSE;
		bool Engorged = FALSE;
		bool Archmage = FALSE;
		bool Rebirth = FALSE;
		bool Heavyweight = FALSE;
		int Deja_Vu = -1;
		int Concentration = -1;
		const char *ConcentrationType = "";
		bool Reversal = FALSE;
		int Amass = -1;
		bool Technician = FALSE;
		bool Optimist = FALSE;
		bool Stockpile = FALSE;
		bool Therapy = FALSE;
		bool Fleet_of_Foot = FALSE;
		bool Gold_Claws = FALSE;
		bool Gold_Scales = FALSE;
		bool Gold_Brain = FALSE;
		bool Phlogiston = FALSE;
		bool Momentum = FALSE;
		int Dynamic = -1;
		bool Resistant = FALSE;
		bool Carbon_Copy = FALSE;

	//change stats
	int TakeDamage(int damageTaken);
	int gainBlock(int block);
	int loseBlock(int block);
	int DrainMana(int manaDrained);
	int ModStat(int bonus, string stat, bool battle);
	int gainEnergy(int energy);
	void restoreStats();
	int gainGold(int gold);
	void checkMax();

	//print character stuff
	void printDirectory();
	void printStats();
	void manaFlicker();
	void changePosBefore(char c, int i);

	//show inventory
	void showInventoryScreen();
};

#endif //CHARACTER_H