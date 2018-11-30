#include "pch.h"
#include "InputBoard.h"

void mvprintInSize(int starty, int startx, int x, const char* toBePrinted, bool Fuzzy);
WINDOW *makeWindow(int height, int width, int starty, int startx);
void rePrint(Character guy, Enemy enemy);
void escapeLoop(int getch);
int rtd(int multiplier, int power);
//manually draw boxes
void manualBox(string typebox, int colorpair);

InputBoard::InputBoard(Deck &deck, Character &guy)
{
	//no negative cards added yet
	negative = "";
	//put on the starting gear
	hands = Gear("No Weapon");
	hands.GearOnOrOff(TRUE, guy, deck);
	body = Gear("No Armor");
	body.GearOnOrOff(TRUE, guy, deck);
	head = Gear("No Headgear");
	head.GearOnOrOff(TRUE, guy, deck);

	//set decision board to first room
	RoomType = "First";

	//pushes all the cards in the deck to the discard pile
	if (deck.size() > 0) {
		for (int i = 0; i < deck.size(); i++) {
			if(!deck.at(i).Void)
				Discard.push_back(deck.at(i));
		}
	}
	//create vector for every equipment type for each piece of equipment
	//hands
	handsNorm.push_back(Gear("Long Sword"));
	handsNorm.push_back(Gear("Falchion"));
	handsNorm.push_back(Gear("Steel Spear"));
	handsNorm.push_back(Gear("Javelin"));
	handsNorm.push_back(Gear("Halberd"));
	handsNorm.push_back(Gear("Battle Axe"));
	handsNorm.push_back(Gear("Shiv"));
	handsNorm.push_back(Gear("Serrated Dagger"));
	handsNorm.push_back(Gear("Simple Bow"));
	handsNorm.push_back(Gear("Sabre"));
	handsNorm.push_back(Gear("Whip"));
	handsNorm.push_back(Gear("Leather Gauntlets"));
	handsNorm.push_back(Gear("Conductive Gloves"));
	handsNorm.push_back(Gear("Lance"));
	handsNorm.push_back(Gear("Dirk"));
	handsNorm.push_back(Gear("Cutlass"));

	handsLate.push_back(Gear("Metal Staff"));
	handsLate.push_back(Gear("Rapier"));
	handsLate.push_back(Gear("Sickle"));
	handsLate.push_back(Gear("Obsidian Spear"));
	handsLate.push_back(Gear("War Hammer"));
	handsLate.push_back(Gear("Morning Star"));
	handsLate.push_back(Gear("Double Axe"));
	handsLate.push_back(Gear("Recurve Bow"));
	handsLate.push_back(Gear("Twin Flail"));
	handsLate.push_back(Gear("Throwing Stars"));
	handsLate.push_back(Gear("Steel Gauntlets"));
	handsLate.push_back(Gear("Spiked Gauntlets"));
	handsLate.push_back(Gear("Crystal Ball"));
	handsLate.push_back(Gear("Arbalest"));

	handsRare.push_back(Gear("Shield"));
	handsRare.push_back(Gear("Wand"));
	handsRare.push_back(Gear("Hand Cannon"));

	//body
	bodyNorm.push_back(Gear("Leather Hauberk"));
	bodyNorm.push_back(Gear("Reinforced Mail"));
	bodyNorm.push_back(Gear("Full Plate Armor"));
	bodyNorm.push_back(Gear("Cape"));
	bodyNorm.push_back(Gear("Steel Breastplate"));
	bodyNorm.push_back(Gear("Feathered Cloak"));
	bodyNorm.push_back(Gear("Buffalo Hide"));

	bodyLate.push_back(Gear("Riveted Chainmail"));
	bodyLate.push_back(Gear("Glitter Robes"));
	bodyLate.push_back(Gear("Spiked Mail"));
	bodyLate.push_back(Gear("Dragon Scales"));
	bodyLate.push_back(Gear("Twilight Robes"));
	bodyLate.push_back(Gear("Crystal Breastplate"));
	bodyLate.push_back(Gear("Amulet of Aura"));

	bodyRare.push_back(Gear("Turtle Shell"));
	bodyRare.push_back(Gear("Mage Armor"));

	//head
	headNorm.push_back(Gear("Vampire Fangs"));
	headNorm.push_back(Gear("Warp Goggles"));
	headNorm.push_back(Gear("Tundra Cap"));
	headNorm.push_back(Gear("Plague Mask"));
	headNorm.push_back(Gear("Dragonskin Hood"));
	headNorm.push_back(Gear("Shifting Veil"));
	headNorm.push_back(Gear("Copper Cage"));
	headNorm.push_back(Gear("Bedstone Helmet"));
	headNorm.push_back(Gear("Glass Eye"));
	headNorm.push_back(Gear("Laurel Wreath"));
	headNorm.push_back(Gear("Diving Gear"));
	headNorm.push_back(Gear("Makeup Set"));
	headNorm.push_back(Gear("Safety Glasses"));

	headRare.push_back(Gear("Brown Hat"));

	//special cards
	specialNorm.push_back(Card("Revivify"));
	specialNorm.push_back(Card("Change Mind"));
	specialNorm.push_back(Card("Intimidate"));
	specialNorm.push_back(Card("Cripple"));
	specialNorm.push_back(Card("Merge"));
	specialNorm.push_back(Card("Entomb"));
	specialNorm.push_back(Card("Grow"));
	specialNorm.push_back(Card("Solidify"));
	specialNorm.push_back(Card("Learn"));
	specialNorm.push_back(Card("Boost"));
	specialNorm.push_back(Card("Vitalise"));
	specialNorm.push_back(Card("Combo"));
	specialNorm.push_back(Card("Slam"));
	specialNorm.push_back(Card("Stall"));
	specialNorm.push_back(Card("Strike"));
	specialNorm.push_back(Card("Defend"));

	specialRare.push_back(Card("Steroids"));
	specialRare.push_back(Card("Distract"));
	specialRare.push_back(Card("Prepare"));
	specialRare.push_back(Card("Train"));
	specialRare.push_back(Card("Jump"));

	//spells
	AvailableSpells.push_back(Card("Channel"));
	AvailableSpells.push_back(Card("Blast"));
	AvailableSpells.push_back(Card("Leech"));
	AvailableSpells.push_back(Card("Transmute"));
	AvailableSpells.push_back(Card("Blink"));
	AvailableSpells.push_back(Card("Singularity"));
	AvailableSpells.push_back(Card("Freeze"));
	AvailableSpells.push_back(Card("Shard"));
	AvailableSpells.push_back(Card("Fumes"));
	AvailableSpells.push_back(Card("Incense"));
	AvailableSpells.push_back(Card("Fireball"));
	AvailableSpells.push_back(Card("Fuel"));
	AvailableSpells.push_back(Card("Charm"));
	AvailableSpells.push_back(Card("Attract"));
	AvailableSpells.push_back(Card("Copy"));
	AvailableSpells.push_back(Card("Confuse"));
	AvailableSpells.push_back(Card("Lightning"));
	AvailableSpells.push_back(Card("Shock"));
	AvailableSpells.push_back(Card("Destroy"));
	AvailableSpells.push_back(Card("Construct"));
	AvailableSpells.push_back(Card("Beam"));
	AvailableSpells.push_back(Card("Diffract"));
	AvailableSpells.push_back(Card("Sap"));
	AvailableSpells.push_back(Card("Synthesize"));
	AvailableSpells.push_back(Card("Drown"));
	AvailableSpells.push_back(Card("Refresh"));
	AvailableSpells.push_back(Card("Reagent"));
	AvailableSpells.push_back(Card("Reactant"));

	//traits
	AvailableTraitsSacrifice.push_back(Gear("Anemia"));
	AvailableTraitsSacrifice.push_back(Gear("Dumb"));
	AvailableTraitsSacrifice.push_back(Gear("Mind Flooded"));
	AvailableTraitsSacrifice.push_back(Gear("Tunnel Vision"));
	AvailableTraitsSacrifice.push_back(Gear("Teleportitis"));
	AvailableTraitsSacrifice.push_back(Gear("Growing Pains"));
	AvailableTraitsSacrifice.push_back(Gear("Conversion"));
	AvailableTraitsSacrifice.push_back(Gear("Inversion"));
	AvailableTraitsSacrifice.push_back(Gear("Jittery"));
	AvailableTraitsSacrifice.push_back(Gear("Tumors"));
	AvailableTraitsSacrifice.push_back(Gear("Volatile"));
	AvailableTraitsSacrifice.push_back(Gear("Melting"));
	AvailableTraitsSacrifice.push_back(Gear("Amnesia"));
	AvailableTraitsSacrifice.push_back(Gear("Long Legs"));
	AvailableTraitsSacrifice.push_back(Gear("Oblivious"));
	AvailableTraitsSacrifice.push_back(Gear("Blind"));
	AvailableTraitsSacrifice.push_back(Gear("Numb"));
	AvailableTraitsSacrifice.push_back(Gear("Sensitive"));
	AvailableTraitsSacrifice.push_back(Gear("Frenzy"));
	AvailableTraitsSacrifice.push_back(Gear("Corpse"));
	AvailableTraitsSacrifice.push_back(Gear("Radioactive"));
	AvailableTraitsSacrifice.push_back(Gear("Forgetful"));
	AvailableTraitsSacrifice.push_back(Gear("Tiny"));
	AvailableTraitsSacrifice.push_back(Gear("Succumb"));
	AvailableTraitsSacrifice.push_back(Gear("Slow"));
	AvailableTraitsSacrifice.push_back(Gear("Sticky Feet"));
	AvailableTraitsSacrifice.push_back(Gear("Overconfidence"));
	AvailableTraitsSacrifice.push_back(Gear("Hallucinations"));
	AvailableTraitsSacrifice.push_back(Gear("Tail"));
	AvailableTraitsSacrifice.push_back(Gear("Weak Back"));
	AvailableTraitsSacrifice.push_back(Gear("Charred Skin"));
	AvailableTraitsSacrifice.push_back(Gear("Purple"));
	AvailableTraitsSacrifice.push_back(Gear("Madness"));
	AvailableTraitsSacrifice.push_back(Gear("Inefficient"));

	AvailableTraitsReward.push_back(Gear("Mending Flesh"));
	AvailableTraitsReward.push_back(Gear("Gymnast"));
	AvailableTraitsReward.push_back(Gear("Third Eye"));
	AvailableTraitsReward.push_back(Gear("Warper"));
	AvailableTraitsReward.push_back(Gear("Growth Spurt"));
	AvailableTraitsReward.push_back(Gear("Mind"));
	AvailableTraitsReward.push_back(Gear("Matter"));
	AvailableTraitsReward.push_back(Gear("Sharp Claws"));
	AvailableTraitsReward.push_back(Gear("Unseen"));
	AvailableTraitsReward.push_back(Gear("Spiny Skin"));
	AvailableTraitsReward.push_back(Gear("Wings"));
	AvailableTraitsReward.push_back(Gear("Exoskeleton"));
	AvailableTraitsReward.push_back(Gear("Unpredictable"));
	AvailableTraitsReward.push_back(Gear("Ego"));
	AvailableTraitsReward.push_back(Gear("Quick Thinker"));
	AvailableTraitsReward.push_back(Gear("Foresight"));
	AvailableTraitsReward.push_back(Gear("Photosynthesis"));
	AvailableTraitsReward.push_back(Gear("Dexterous"));
	AvailableTraitsReward.push_back(Gear("Reconstruction"));
	AvailableTraitsReward.push_back(Gear("Laser Vision"));
	AvailableTraitsReward.push_back(Gear("Carnivore"));
	AvailableTraitsReward.push_back(Gear("Hemoglobin"));
	AvailableTraitsReward.push_back(Gear("Destiny"));
	AvailableTraitsReward.push_back(Gear("Scavenger"));
	AvailableTraitsReward.push_back(Gear("Horns"));
	AvailableTraitsReward.push_back(Gear("Genius"));
	AvailableTraitsReward.push_back(Gear("Green Blood"));
	AvailableTraitsReward.push_back(Gear("Multi-Tongued"));
	AvailableTraitsReward.push_back(Gear("Triple-Jointed"));

	//vector of bosses
	bosses.push_back(Enemy("Paladin"));
	bosses.push_back(Enemy("Hunter"));
	bosses.push_back(Enemy("Juggernaut"));
	bosses.push_back(Enemy("Vampire"));
	bosses.push_back(Enemy("Hydra"));
	bosses.push_back(Enemy("Exorcist"));
	bosses.push_back(Enemy("Demigod"));
	bosses.push_back(Enemy("Wolf"));

	//decide final boss and themed enemies
	int rngboss = rand() % 5;
	if (rngboss == 0) {
		FinalBoss = Enemy("Dragon");

		tierone = Enemy("Hatchling");
		tiertwo = Enemy("Molten Jelly");
		tierthree1 = Enemy("Knight");
		tierthree2 = Enemy("Drake");
	}
	else if (rngboss == 1) {
		FinalBoss = Enemy("King");

		tierone = Enemy("Slave");
		tiertwo = Enemy("Soldier");
		tierthree1 = Enemy("Guard");
		tierthree2 = Enemy("Jester");
	}
	else if (rngboss == 2) {
		FinalBoss = Enemy("Machine");

		tierone = Enemy("Robot");
		tiertwo = Enemy("Golem");
		tierthree1 = Enemy("Merchant");
		tierthree2 = Enemy("Turret");
	}
	else if (rngboss == 3) {
		FinalBoss = Enemy("Witch");

		tierone = Enemy("Eyeball");
		tiertwo = Enemy("Apprentice");
		tierthree1 = Enemy("Monster");
		tierthree2 = Enemy("Brain");
	}
	else if (rngboss == 4) {
		FinalBoss = Enemy("Demon");

		tierone = Enemy("Cultist");
		tiertwo = Enemy("Imp");
		tierthree1 = Enemy("Weeping Soul");
		tierthree2 = Enemy("Hellhound");
	}

	//Multi-Tongued trait
	negotiateStep = 0;
}


InputBoard::~InputBoard()
{
}

void InputBoard::setRoom(const char *type) {
	//First, Combat, Boss, Final Boss, Stat, Addition, Cauldron, Empty
	RoomType = type;
}

//clears the decision board (the three card screen)
void InputBoard::clearBoard() {
	for (int y = 17; y < 23; y++) {
		mvprintw(y, 2, "                  ");
	}
	for (int y = 17; y < 23; y++) {
		mvprintw(y, 22, "                  ");
	}
	for (int y = 17; y < 23; y++) {
		mvprintw(y, 42, "                  ");
	}
}
void InputBoard::clearBoardWhole() {
	for (int y = 16; y < 24; y++) {
		mvprintw(y, 2, "                                                                           ");
	}
}

//shows your deck in place of the text log, allows you too see cards and choose modifiers
void InputBoard::showDeck(Character &guy, Deck &cardDeck) {
	standend();
	for (int y = 0; y < 15; y++) {
		mvprintw(y, 44, "                                  ");
	}

	vector<Card> tempdeck = cardDeck.cardDeck;
	vector<Card> tempscreendeck;
	vector<int> tempscreendeckcounter;

	//updates the screendeck and screendeck counter vectors
		//screendeck holds each card in the deck, but doesn't add duplicates as individual cards
		//screendeckcounter holds the amount of duplicates for each relative index of screendeck
	while (tempdeck.size() > 0) {
		Card cardnow = tempdeck.at(0);
		int counter = 0;
		for (int i = 0; i < tempdeck.size(); i++) {
			if (tempdeck.at(i).CardName == cardnow.CardName && tempdeck.at(i).checkSameMods(cardnow)) {
				tempdeck.erase(tempdeck.begin() + i);
				i--;
				counter++;
			}
		}
		tempscreendeck.push_back(cardnow);
		tempscreendeckcounter.push_back(counter);
	}

	screendeck = tempscreendeck;
	screendeckCounter = tempscreendeckcounter;

	mvprintw(0, 50, "Deck (ESC to exit deck)");
	mvprintInSize(14, 59, 0, "                  ", FALSE);

	int x = 45;
	int y = 2;
	for (int i = 0; i < screendeck.size(); i++) {
		Card cardnow = screendeck.at(i);
		int counternow = screendeckCounter.at(i);

		char ccc;
		switch (i) {
		case 0:
			ccc = 'a';
			break;
		case 1:
			ccc = 'b';
			break;
		case 2:
			ccc = 'c';
			break;
		case 3:
			ccc = 'd';
			break;
		case 4:
			ccc = 'e';
			break;
		case 5:
			ccc = 'f';
			break;
		case 6:
			ccc = 'g';
			break;
		case 7:
			ccc = 'h';
			break;
		case 8:
			ccc = 'i';
			break;
		case 9:
			ccc = 'j';
			break;
		case 10:
			ccc = 'k';
			break;
		case 11:
			ccc = 'l';
			break;
		case 12:
			ccc = 'm';
			break;
		case 13:
			ccc = 'n';
			break;
		case 14:
			ccc = 'o';
			break;
		case 15:
			ccc = 'p';
			break;
		case 16:
			ccc = 'q';
			break;
		case 17:
			ccc = 'r';
			break;
		case 18:
			ccc = 's';
			break;
		case 19:
			ccc = 't';
			break;
		case 20:
			ccc = 'u';
			break;
		case 21:
			ccc = 'v';
			break;
		}

		string option(1, ccc);
		option += ") ";
		mvprintInSize(y, x, 0, option.c_str(), FALSE);

		if (cardnow.CardType == "Attack") {
			attron(COLOR_PAIR(1));
		}
		else if (cardnow.CardType == "Defend") {
			attron(COLOR_PAIR(2));
		}
		else if (cardnow.CardType == "Spell") {
			attron(COLOR_PAIR(3));
		}
		else if (cardnow.CardType == "Special") {
			standend();
		}
		else if (cardnow.CardType == "Negative") {
			attron(COLOR_PAIR(5));
		}

		//creates a string of the duplicate count (if any), the card name, and the modifiers (if any) and prints it
		string whole = "";
		

		if (counternow == 1) {
			whole = string(cardnow.CardName);
		}
		else {
			whole = to_string(counternow) + "x ";
			whole += string(cardnow.CardName);
		}
		whole += " " + cardnow.modchars();
		mvprintInSize(y, x+3, 0, whole.c_str(), FALSE);

		standend();

		y++;
		if (y > 13) {
			if (x == 61)
				return;
			else {
				x += 16;
				y = 2;
			}
		}
	}
	standend();
	deckLoopWhole(guy, cardDeck);
}

//gets decision to choose cards to look at individually
void InputBoard::deckLoopWhole(Character &guy, Deck &cardDeck) {
	char c = getch();
	//esc
	if (c == 27) {
		return;
	}
	int desc_x = 50;
	int desc_maxx = 20;
	int x = 59;

	bool chosen = FALSE;

	for (int i = 0; i < screendeck.size(); i++) {
		char ccc;
		//decides the char based off of the index
		switch (i) {
		case 0:
			ccc = 'a';
			break;
		case 1:
			ccc = 'b';
			break;
		case 2:
			ccc = 'c';
			break;
		case 3:
			ccc = 'd';
			break;
		case 4:
			ccc = 'e';
			break;
		case 5:
			ccc = 'f';
			break;
		case 6:
			ccc = 'g';
			break;
		case 7:
			ccc = 'h';
			break;
		case 8:
			ccc = 'i';
			break;
		case 9:
			ccc = 'j';
			break;
		case 10:
			ccc = 'k';
			break;
		case 11:
			ccc = 'l';
			break;
		case 12:
			ccc = 'm';
			break;
		case 13:
			ccc = 'n';
			break;
		case 14:
			ccc = 'o';
			break;
		case 15:
			ccc = 'p';
			break;
		case 16:
			ccc = 'q';
			break;
		case 17:
			ccc = 'r';
			break;
		case 18:
			ccc = 's';
			break;
		case 19:
			ccc = 't';
			break;
		case 20:
			ccc = 'u';
			break;
		case 21:
			ccc = 'v';
			break;
		}
		if (c == ccc) {
			chosen = TRUE;
			for (int y = 1; y < 15; y++) {
				mvprintw(y, 44, "                                  ");
			}
			/*if (kard.CardType == "Attack") {
				attron(COLOR_PAIR(1));
			}
			else if (kard.CardType == "Defend") {
				attron(COLOR_PAIR(2));
			}
			else if (kard.CardType == "Spell") {
				attron(COLOR_PAIR(3));
			}
			else if (kard.CardType == "Special") {
				standend();
			}
			else if (kard.CardType == "Negative") {
				attron(COLOR_PAIR(5));
			}
			int ax = int(strlen(kard.CardName) / 2);
			const char *desc = kard.Description;
			mvprintInSize(2, x - ax, 0, kard.CardName, FALSE);
			mvprintInSize(4, desc_x, desc_maxx, desc, FALSE);

			string mods = kard.modstrings();
			int modx = 59;
			modx -= (mods.size() / 4) - 1;
			mvprintInSize(3, modx, 0, mods.c_str(), FALSE);

			standend();
			mvprintInSize(14, 59, 0, "(M)odify this card", FALSE);*/

			for (int k = 0; k < cardDeck.size(); k++) {
				if (cardDeck.at(k).CardName == screendeck.at(i).CardName && cardDeck.at(k).checkSameMods(screendeck.at(i))) {
					deckLoopCard(guy, cardDeck, k);
					break;
				}
			}

			break;
		}
	}
	if (!chosen) {
		deckLoopWhole(guy, cardDeck);
	}
}
//checks if you want to apply modifiers
void InputBoard::deckLoopCard(Character &guy, Deck &cardDeck, int modindex) {
	for (int y = 1; y < 15; y++) {
		mvprintw(y, 44, "                                  ");
	}

	int desc_x = 50;
	int desc_maxx = 20;
	int x = 59;
	
	if (cardDeck.at(modindex).CardType == "Attack") {
		attron(COLOR_PAIR(1));
	}
	else if (cardDeck.at(modindex).CardType == "Defend") {
		attron(COLOR_PAIR(2));
	}
	else if (cardDeck.at(modindex).CardType == "Spell") {
		attron(COLOR_PAIR(3));
	}
	else if (cardDeck.at(modindex).CardType == "Special") {
		standend();
	}
	else if (cardDeck.at(modindex).CardType == "Negative") {
		attron(COLOR_PAIR(5));
	}
	int ax = int(strlen(cardDeck.at(modindex).CardName) / 2);
	const char *desc = cardDeck.at(modindex).Description;
	mvprintInSize(2, x - ax, 0, cardDeck.at(modindex).CardName, FALSE);
	mvprintInSize(4, desc_x, desc_maxx, desc, FALSE);

	string mods = cardDeck.at(modindex).modstrings();
	int modx = 59;
	modx -= (mods.size() / 4) - 1;
	mvprintInSize(3, modx, 0, mods.c_str(), FALSE);

	standend();
	mvprintInSize(13, 56, 0, "(M)odify this card", FALSE);
	mvprintInSize(14, 56, 0, "(R)emove all modifiers", FALSE);

	char m = getch();
	if (m == 27) {
		showDeck(guy, cardDeck);
	}
	else if (m == 'm') {
		deckLoopMod(guy, cardDeck, modindex);
	}
	else if (m == 'r') {
		cardDeck.cardDeck.at(modindex).removeMods(guy);
		showDeck(guy, cardDeck);
	}
	else {
		deckLoopCard(guy, cardDeck, modindex);
	}
}
//shows list of modifiers to apply it
void InputBoard::deckLoopMod(Character &guy, Deck &cardDeck, int modindex) {
	for (int y = 1; y < 15; y++) {
		mvprintw(y, 44, "                                  ");
	}

	/*bool burn = FALSE;
	bool stay = FALSE;
	bool flow = FALSE;
	bool copy = FALSE;
	bool push = FALSE;
	bool voidd = FALSE;
	bool link = FALSE;*/


	mvprintInSize(14, 59, 0, "                  ", FALSE);
	mvprintw(0, 49, "Modifiers (ESC to exit) ");
	int modcount = 0;
	/*if (Burn > 0) {
		modcount++;
		burn = TRUE;
	}
	if (Stay > 0) {
		modcount++;
		stay = TRUE;
	}
	if (Flow > 0) {
		modcount++;
		flow = TRUE;
	}
	if (Copy > 0) {
		modcount++;
		copy = TRUE;
	}
	if (Push > 0) {
		modcount++;
		push = TRUE;
	}
	if (Void > 0) {
		modcount++;
		voidd = TRUE;
	}
	if (Link > 0) {
		modcount++;
		link = TRUE;
	}*/

	int y = 2;
	for (int i = 0; i < 7; i++) {
		char ccc = ' ';
		string modtype = "";
		switch (i) {
		case 0:
			if (guy.Burn > 0) {
				ccc = 'a';
			}
			modtype = "#rBurn#o x" + to_string(guy.Burn);
			break;
		case 1:
			if (guy.Stay > 0) {
				ccc = 'b';
			}
			modtype = "#gStay#o x" + to_string(guy.Stay);
			break;
		case 2:
			if (guy.Flow > 0) {
				ccc = 'c';
			}
			modtype = "#cFlow#o x" + to_string(guy.Flow);
			break;
		case 3:
			if (guy.Copy > 0) {
				ccc = 'd';
			}
			modtype = "#mCopy#o x" + to_string(guy.Copy);
			break;
		case 4:
			if (guy.Push > 0) {
				ccc = 'e';
			}
			modtype = "#yPush#o x" + to_string(guy.Push);
			break;
		case 5:
			if (guy.Void > 0) {
				ccc = 'f';
			}

			modtype = "#oVoid#o x" + to_string(guy.Void);
			break;
		case 6:
			if (guy.Link > 0) {
				ccc = 'g';
			}
			modtype = "#bLink#o x" + to_string(guy.Link);
			break;
		
		}

		string c(1, ccc);
		if (ccc != ' ') {
			c += ") " + modtype;
		}
		else {
			c += "  " + modtype;
		}
		mvprintInSize(y, 45, 0, c.c_str(), FALSE);
		y++;
	}

	char mmm = getch();

	if (mmm == 27) {
		deckLoopCard(guy, cardDeck, modindex);
	}
	else {
	if (mmm == 'a' && guy.Burn > 0) {
	if (!cardDeck.cardDeck.at(modindex).Burn) {
		guy.Burn--;
	}
	cardDeck.cardDeck.at(modindex).setMod("Burn", true, guy);
	}
	else if (mmm == 'b' && guy.Stay > 0) {
	if (!cardDeck.cardDeck.at(modindex).Stay) {
		guy.Stay--;
	}
	cardDeck.cardDeck.at(modindex).setMod("Stay", true, guy);
	}
	else if (mmm == 'c' && guy.Flow > 0) {
	if (!cardDeck.cardDeck.at(modindex).Flow) {
		guy.Flow--;
	}
	cardDeck.cardDeck.at(modindex).setMod("Flow", true, guy);
	}
	else if (mmm == 'd' && guy.Copy > 0) {
	if (!cardDeck.cardDeck.at(modindex).Copy) {
		guy.Copy--;
	}
	cardDeck.cardDeck.at(modindex).setMod("Copy", true, guy);
	}
	else if (mmm == 'e' && guy.Push > 0) {
	if (!cardDeck.cardDeck.at(modindex).Push) {
		guy.Push--;
	}
	cardDeck.cardDeck.at(modindex).setMod("Push", true, guy);
	}
	else if (mmm == 'f' && guy.Void > 0) {
	if (!cardDeck.cardDeck.at(modindex).Void) {
		guy.Void--;
	}
	cardDeck.cardDeck.at(modindex).setMod("Void", true, guy);
	}
	else if (mmm == 'g' && guy.Link > 0) {
	if (cardDeck.cardDeck.at(modindex).Link == '0') {
		guy.Link--;
	}
	cardDeck.cardDeck.at(modindex).setMod("Link", true, guy);
	}
	else {
	deckLoopMod(guy, cardDeck, modindex);
	}
	showDeck(guy, cardDeck);
	}
}

void InputBoard::showInventory(Character &guy, Deck &deck) {
	//clears log from screen
	for (int y = 0; y < 15; y++) {
		mvprintw(y, 44, "                                  ");
	}

	//print the gear equipped
	mvprintw(2, 50, "Head:");
	mvprintw(3, 50, "Body:");
	mvprintw(4, 50, "Hands:");
	attron(COLOR_PAIR(10));
	mvprintw(2, 56, "%s", head.GearName);
	mvprintw(3, 56, "%s", body.GearName);
	mvprintw(4, 57, "%s", hands.GearName);
	standend();

	int x = 49;
	int y = 5;
	//print any non-equipped gear
	for (int i = 0; i < inventory.size(); i++) {
		//this switch sucks, it checks for letters a-r and prints if they exist
		switch (i) {
		case 0:
			mvprintw(y, x, "a) %s", inventory.at(i).GearName);
			break;
		case 1:
			mvprintw(y, x, "b) %s", inventory.at(i).GearName);
			break;
		case 2:
			mvprintw(y, x, "c) %s", inventory.at(i).GearName);
			break;
		case 3:
			mvprintw(y, x, "d) %s", inventory.at(i).GearName);
			break;
		case 4:
			mvprintw(y, x, "e) %s", inventory.at(i).GearName);
			break;
		case 5:
			mvprintw(y, x, "f) %s", inventory.at(i).GearName);
			break;
		case 6:
			mvprintw(y, x, "g) %s", inventory.at(i).GearName);
			break;
		case 7:
			mvprintw(y, x, "h) %s", inventory.at(i).GearName);
			break;
		case 8:
			mvprintw(y, x, "i) %s", inventory.at(i).GearName);
			break;
		}
		y++;
		if (y > 13) {
			y = 5;
			x += 16;
		}
	}
	mvprintw(0, 47, "Inventory (ESC to exit page)");
	int s = 9-inventory.size();
	mvprintw(14, 52, "%i spaces left", s);
	//calls getch loop for choosing gear
	inventoryLoopWhole(guy, deck);
}
//erases gear from inventory, used when equipping gear
void InputBoard::removeGear(Gear &item) {
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory.at(i).GearName == item.GearName) {
			inventory.erase(inventory.begin() + i);
			break;
		}
	}
}
//getch loop for choosing gear
void InputBoard::inventoryLoopWhole(Character &guy, Deck &deck) {
	
	char c = getch();
	//esc option
	if (c == 27) {
		return;
	}

	//this also sucks a lot, it getches for 18 separate letters
	int desc_x = 47;
	int desc_maxx = 25;
	int x = 59;

	//mvprintw(14, 52, "               ");
	if (inventory.size() >= 1 && c == 'a') {
		//clears log from screen
		mvprintw(14, 52, "               ");
		for (int y = 1; y < 14; y++) {
			mvprintw(y, 44, "                                 ");
		}
		//sets the gear you look at to the gear selected, print gear info
		Gear cgear = inventory.at(0);
		int ax = int(strlen(cgear.GearName) / 2);
		const char *desc = cgear.Description;
		mvprintw(2, x-ax, "%s", cgear.GearName);
		mvprintw(3, 56, "(%s)", cgear.Type);
		mvprintInSize(5, desc_x, desc_maxx, desc, FALSE);
		if (cgear.Type == "Hands")
			mvprintw(14, 58, "(W)ield this item");
		else
			mvprintw(14, 59, "(W)ear this item");

		//calls getch loop for looking at one piece of gear
		inventoryLoopItem(cgear, guy, deck);
		return;
	}
	//does ^this^ for 17 more letters (should update this at some point, Traits uses the better way)
	else if (inventory.size() >= 2 && c == 'b') {
		mvprintw(14, 52, "               ");
		for (int y = 1; y < 14; y++) {
			mvprintw(y, 44, "                                  ");
		}
		Gear cgear = inventory.at(1);
		const char *desc = cgear.Description;
		int ax = int(strlen(cgear.GearName) / 2);
		mvprintw(2, x-ax, "%s", cgear.GearName);
		mvprintw(3, 56, "(%s)", cgear.Type);
		mvprintInSize(5, desc_x, desc_maxx, desc, FALSE);
		if (cgear.Type == "Hands")
			mvprintw(14, 58, "(W)ield this item");
		else
			mvprintw(14, 59, "(W)ear this item");

		inventoryLoopItem(cgear, guy, deck);
		return;
	}
	else if (inventory.size() >= 3 && c == 'c') {
		mvprintw(14, 52, "               ");
		for (int y = 1; y < 14; y++) {
			mvprintw(y, 44, "                                  ");
		}
		Gear cgear = inventory.at(2);
		const char *desc = cgear.Description;
		int ax = int(strlen(cgear.GearName) / 2);
		mvprintw(2, x-ax, "%s", cgear.GearName);
		mvprintw(3, 56, "(%s)", cgear.Type);
		mvprintInSize(5, desc_x, desc_maxx, desc, FALSE);
		if (cgear.Type == "Hands")
			mvprintw(14, 58, "(W)ield this item");
		else
			mvprintw(14, 59, "(W)ear this item");

		inventoryLoopItem(cgear, guy, deck);
		return;
	}
	else if (inventory.size() >= 4 && c == 'd') {
		mvprintw(14, 52, "               ");
		for (int y = 1; y < 14; y++) {
			mvprintw(y, 44, "                                  ");
		}
		Gear cgear = inventory.at(3);
		const char *desc = cgear.Description;
		int ax = int(strlen(cgear.GearName) / 2);
		mvprintw(2, x-ax, "%s", cgear.GearName);
		mvprintw(3, 56, "(%s)", cgear.Type);
		mvprintInSize(5, desc_x, desc_maxx, desc, FALSE);
		if (cgear.Type == "Hands")
			mvprintw(14, 58, "(W)ield this item");
		else
			mvprintw(14, 59, "(W)ear this item");

		inventoryLoopItem(cgear, guy, deck);
		return;
	}
	else if (inventory.size() >= 5 && c == 'e') {
		mvprintw(14, 52, "               ");
		for (int y = 1; y < 14; y++) {
			mvprintw(y, 44, "                                  ");
		}
		Gear cgear = inventory.at(4);
		const char *desc = cgear.Description;
		int ax = int(strlen(cgear.GearName) / 2);
		mvprintw(2, x-ax, "%s", cgear.GearName);
		mvprintw(3, 56, "(%s)", cgear.Type);
		mvprintInSize(5, desc_x, desc_maxx, desc, FALSE);
		if (cgear.Type == "Hands")
			mvprintw(14, 58, "(W)ield this item");
		else
			mvprintw(14, 59, "(W)ear this item");

		inventoryLoopItem(cgear, guy, deck);
		return;
	}
	else if (inventory.size() >= 6 && c == 'f') {
		mvprintw(14, 52, "               ");
		for (int y = 1; y < 14; y++) {
			mvprintw(y, 44, "                                  ");
		}
		Gear cgear = inventory.at(5);
		const char *desc = cgear.Description;
		int ax = int(strlen(cgear.GearName) / 2);
		mvprintw(2, x-ax, "%s", cgear.GearName);
		mvprintw(3, 56, "(%s)", cgear.Type);
		mvprintInSize(5, desc_x, desc_maxx, desc, FALSE);
		if (cgear.Type == "Hands")
			mvprintw(14, 58, "(W)ield this item");
		else
			mvprintw(14, 59, "(W)ear this item");

		inventoryLoopItem(cgear, guy, deck);
		return;
	}
	else if (inventory.size() >= 7 && c == 'g') {
	mvprintw(14, 52, "               ");
	for (int y = 1; y < 14; y++) {
		mvprintw(y, 44, "                                  ");
	}
	Gear cgear = inventory.at(6);
	const char *desc = cgear.Description;
	int ax = int(strlen(cgear.GearName) / 2);
	mvprintw(2, x-ax, "%s", cgear.GearName);
	mvprintw(3, 56, "(%s)", cgear.Type);
	mvprintInSize(5, desc_x, desc_maxx, desc, FALSE);
	if (cgear.Type == "Hands")
		mvprintw(14, 58, "(W)ield this item");
	else
		mvprintw(14, 59, "(W)ear this item");

	inventoryLoopItem(cgear, guy, deck);
	return;
	}
	else if (inventory.size() >= 8 && c == 'h') {
	mvprintw(14, 52, "               ");
	for (int y = 1; y < 14; y++) {
		mvprintw(y, 44, "                                  ");
	}
	Gear cgear = inventory.at(7);
	const char *desc = cgear.Description;
	int ax = int(strlen(cgear.GearName) / 2);
	mvprintw(2, x-ax, "%s", cgear.GearName);
	mvprintw(3, 56, "(%s)", cgear.Type);
	mvprintInSize(5, desc_x, desc_maxx, desc, FALSE);
	if (cgear.Type == "Hands")
		mvprintw(14, 58, "(W)ield this item");
	else
		mvprintw(14, 59, "(W)ear this item");

	inventoryLoopItem(cgear, guy, deck);
	return;
	}
	else if (inventory.size() >= 9 && c == 'i') {
	mvprintw(14, 52, "               ");
	for (int y = 1; y < 14; y++) {
		mvprintw(y, 44, "                                  ");
	}
	Gear cgear = inventory.at(8);
	const char *desc = cgear.Description;
	int ax = int(strlen(cgear.GearName) / 2);
	mvprintw(2, x-ax, "%s", cgear.GearName);
	mvprintw(3, 56, "(%s)", cgear.Type);
	mvprintInSize(5, desc_x, desc_maxx, desc, FALSE);
	if (cgear.Type == "Hands")
		mvprintw(14, 58, "(W)ield this item");
	else
		mvprintw(14, 59, "(W)ear this item");

	inventoryLoopItem(cgear, guy, deck);
	return;
	}
	
	//if any other button is pressed, stay at this screen
	else {
		inventoryLoopWhole(guy, deck);
	}
}
//getch loop for looking at one piece of gear
void InputBoard::inventoryLoopItem(Gear &item, Character &guy, Deck &deck) {
	char w = getch();
	//esc option
	if (w == 27) {
		showInventory(guy, deck);
	}
	//wear gear, replaces equipped gear of the same slot (head, body, hands)
	else if (w == 'w') {
		if (item.Type == "Head") {
			Gear temp = head;
			temp.GearOnOrOff(FALSE, guy, deck);
			inventory.push_back(temp);
			removeGear(item);
			head = item;
			head.GearOnOrOff(TRUE, guy, deck);
			showInventory(guy, deck);
			return;
		}
		if (item.Type == "Body") {
			Gear temp = body;
			temp.GearOnOrOff(FALSE, guy, deck);
			inventory.push_back(temp);
			removeGear(item);
			body = item;
			body.GearOnOrOff(TRUE, guy, deck);
			showInventory(guy, deck);
			return;
		}
		if (item.Type == "Hands") {
			Gear temp = hands;
			temp.GearOnOrOff(FALSE, guy, deck);
			inventory.push_back(temp);
			removeGear(item);
			hands = item;
			hands.GearOnOrOff(TRUE, guy, deck);
			showInventory(guy, deck);
			return;
		}
	}
	//if any other button is pressed, stay at this screen
	else {
		inventoryLoopItem(item, guy, deck);
	}
}

//shows traits, allows you to select and look at them individually
void InputBoard::showTraits() {
	for (int y = 0; y < 15; y++) {
		mvprintw(y, 44, "                                  ");
	}

	int x = 44;
	int y = 3;
	//print any non-equipped gear
	for (int i = 0; i < Traits.size(); i++) {
		if (Traits.at(i).Type == "Trait Sacrifice")
			attron(COLOR_PAIR(5));
		else if (Traits.at(i).Type == "Trait Reward")
			attron(COLOR_PAIR(7));
		//checks for letters a-r and prints if they exist
		switch (i) {
		case 0:
			mvprintw(y, x, "a) %s", Traits.at(i).GearName);
			break;
		case 1:
			mvprintw(y, x, "b) %s", Traits.at(i).GearName);
			break;
		case 2:
			mvprintw(y, x, "c) %s", Traits.at(i).GearName);
			break;
		case 3:
			mvprintw(y, x, "d) %s", Traits.at(i).GearName);
			break;
		case 4:
			mvprintw(y, x, "e) %s", Traits.at(i).GearName);
			break;
		case 5:
			mvprintw(y, x, "f) %s", Traits.at(i).GearName);
			break;
		case 6:
			mvprintw(y, x, "g) %s", Traits.at(i).GearName);
			break;
		case 7:
			mvprintw(y, x, "h) %s", Traits.at(i).GearName);
			break;
		case 8:
			mvprintw(y, x, "i) %s", Traits.at(i).GearName);
			break;
		case 9:
			mvprintw(y, x, "j) %s", Traits.at(i).GearName);
			break;
		case 10:
			mvprintw(y, x, "k) %s", Traits.at(i).GearName);
			break;
		case 11:
			mvprintw(y, x, "l) %s", Traits.at(i).GearName);
			break;
		case 12:
			mvprintw(y, x, "m) %s", Traits.at(i).GearName);
			break;
		case 13:
			mvprintw(y, x, "n) %s", Traits.at(i).GearName);
			break;
		case 14:
			mvprintw(y, x, "o) %s", Traits.at(i).GearName);
			break;
		case 15:
			mvprintw(y, x, "p) %s", Traits.at(i).GearName);
			break;
		case 16:
			mvprintw(y, x, "q) %s", Traits.at(i).GearName);
			break;
		case 17:
			mvprintw(y, x, "r) %s", Traits.at(i).GearName);
			break;
		case 18:
			mvprintw(y, x, "s) %s", Traits.at(i).GearName);
			break;
		case 19:
			mvprintw(y, x, "t) %s", Traits.at(i).GearName);
			break;
		case 20:
			mvprintw(y, x, "u) %s", Traits.at(i).GearName);
			break;
		case 21:
			mvprintw(y, x, "v) %s", Traits.at(i).GearName);
			break;
		}
		y++;
		standend();
		if (y > 13) {
			y = 3;
			x += 16;
		}
	}
	mvprintw(0, 48, "Traits (ESC to exit page)");
	//calls method to see an individual trait
	traitsLoopWhole();
}
void InputBoard::traitsLoopWhole() {
	char c = getch();
	//esc option
	if (c == 27) {
		return;
	}
	//better version of getching for 18 separate letters
	int desc_x = 50;
	int desc_maxx = 18;
	int x = 59;

	for (int i = 0; i < Traits.size(); i++) {
		char ccc;
		switch (i) {
		case 0:
			ccc = 'a';
			break;
		case 1:
			ccc = 'b';
			break;
		case 2:
			ccc = 'c';
			break;
		case 3:
			ccc = 'd';
			break;
		case 4:
			ccc = 'e';
			break;
		case 5:
			ccc = 'f';
			break;
		case 6:
			ccc = 'g';
			break;
		case 7:
			ccc = 'h';
			break;
		case 8:
			ccc = 'i';
			break;
		case 9:
			ccc = 'j';
			break;
		case 10:
			ccc = 'k';
			break;
		case 11:
			ccc = 'l';
			break;
		case 12:
			ccc = 'm';
			break;
		case 13:
			ccc = 'n';
			break;
		case 14:
			ccc = 'o';
			break;
		case 15:
			ccc = 'p';
			break;
		case 16:
			ccc = 'q';
			break;
		case 17:
			ccc = 'r';
			break;
		case 18:
			ccc = 's';
			break;
		case 19:
			ccc = 't';
			break;
		case 20:
			ccc = 'u';
			break;
		case 21:
			ccc = 'v';
			break;
		}
		if (c == ccc) {
			for (int y = 1; y < 14; y++) {
				mvprintw(y, 44, "                                 ");
			}
			Gear ctrait = Traits.at(i);
			if (ctrait.Type == "Trait Sacrifice")
				attron(COLOR_PAIR(5));
			else if (ctrait.Type == "Trait Reward")
				attron(COLOR_PAIR(7));
			int ax = int(strlen(ctrait.GearName) / 2);
			const char *desc = ctrait.Description;
			mvprintw(2, x - ax, "%s", ctrait.GearName);
			mvprintInSize(4, desc_x, desc_maxx, desc, FALSE);
			standend();
			int c = 0;
			escapeLoop(c);
			break;
		}
	}
	showTraits();

	/*if (Traits.size() >= 1 && c == 'a') {
		//clears log from screen
		for (int y = 1; y < 14; y++) {
			mvprintw(y, 44, "                                 ");
		}
		//sets the gear you look at to the gear selected, print gear info
		Gear ctrait = Traits.at(0);
		if (ctrait.Type == "Trait Sacrifice")
			attron(COLOR_PAIR(5));
		else if (ctrait.Type == "Trait Reward")
			attron(COLOR_PAIR(7));
		int ax = int(strlen(ctrait.GearName) / 2);
		const char *desc = ctrait.Description;
		mvprintw(2, x - ax, "%s", ctrait.GearName);
		mvprintInSize(4, desc_x, desc_maxx, desc);
		standend();
		int c = 0;
		escapeLoop(c);
		showTraits();
		return;
	}
	else if (Traits.size() >= 2 && c == 'b') {
		//clears log from screen
		for (int y = 1; y < 14; y++) {
			mvprintw(y, 44, "                                 ");
		}
		//sets the gear you look at to the gear selected, print gear info
		Gear ctrait = Traits.at(1);
		if (ctrait.Type == "Trait Sacrifice")
			attron(COLOR_PAIR(5));
		else if (ctrait.Type == "Trait Reward")
			attron(COLOR_PAIR(7));
		int ax = int(strlen(ctrait.GearName) / 2);
		const char *desc = ctrait.Description;
		mvprintw(2, x - ax, "%s", ctrait.GearName);
		mvprintInSize(4, desc_x, desc_maxx, desc);
		standend();
		int c = 0;
		escapeLoop(c);
		showTraits();
		return;
	}*/
	
}

/*function for shuffling the deck in battle if the draw pile is empty,
  pushing forward cards from the draw pile into the cards that can be chosen,
  and printing the cards that can be chosen*/
void InputBoard::ShuffleAddPrint() {
	//mvprintw(17, 63, "Next: ");
	//push modifier
	if (pushthisturn) {
		int limit = 0;
		while (DecisionCards.size() > limit) {
			if (DecisionCards.at(limit).StayCard) {
				limit++;
				DecisionCards.at(limit).StayCard = FALSE;
			}
			else {
				Discard.push_back(DecisionCards.at(limit));
				DecisionCards.erase(DecisionCards.begin() + limit);
			}
		}
		pushthisturn = FALSE;
	}
	

	
	//shuffle
		//if there isn't enough cards in the draw pile, add cards from the discard pile into draw pile in a random order
		if (Draw.size() < handSize) {
			while (Discard.size() > 0) {
				Card tempCard = Discard.front();
				Discard.erase(Discard.begin());

				int rng = rand() % (Draw.size() + 1);
				Draw.insert(Draw.begin() + rng, tempCard);
			}
		}
		
	//add
		//link
		if (linkdraw != '-' && linkdraw != '0') {
			if (Draw.size() > 0) {
				for (int i = 0; i < Draw.size(); i++) {
					if (Draw.at(i).Link == linkdraw && DecisionCards.size() < handSize) {
						DecisionCards.push_back(Draw.at(i));
						Draw.erase(Draw.begin() + i);
					}
				}
			}
			if (Discard.size() > 0) {
				for (int i = 0; i < Discard.size(); i++) {
					if (Discard.at(i).Link == linkdraw && DecisionCards.size() < handSize) {
						DecisionCards.push_back(Discard.at(i));
						Discard.erase(Discard.begin() + i);
					}
				}
			}
			linkdraw = '-';
		}
		
		//draw for a deck with less than 3 cards (handSize = 3)
		if (Draw.size() < handSize && DecisionCards.size() < handSize-1) {
			cardThere = Draw.size();
		}

		if (Draw.size() < handSize && Discard.size() == 0) {
			while (Draw.size() > 0) {
				Card innout = Draw.back();
				Draw.pop_back();
				DecisionCards.push_back(innout);
			}
		}
		//if there aren't (handSize) cards to choose from, add cards from the draw pile to here until there are three
		else {
			while (DecisionCards.size() < handSize) {
				Card innout = Draw.back();
				Draw.pop_back();
				DecisionCards.push_back(innout);
			}
		}

	//print
		//prints the boxes
		//if (cardThere > 0)
		//manualBox("Card 1", 0);
		//if (cardThere > 1)
		//manualBox("Card 2", 0);
		//if (cardThere > 2)
		//manualBox("Card 3", 0);
		standend();
		//prints the cards to choose from
		/*if (DecisionCards.size() == 0) {
			clearBoard();
		}*/
		//else {
			for (int i = 0; i < handSize; i++) {
				if(DecisionCards.size() > i)
					DecisionCards.at(i).printCard(i + 1);
			}
		//}
		

		/*for (int i = 0; i < (int)Draw.size(); i++) {
			mvprintw(5 + i, 45, "%s   ", Draw.at(i).CardName);
		}*/
		//mvprintw(5, 70, "%s    ", Draw.back().CardName);
		
		
		//makeWindow(4, 15, 16, 61);


		//Third Eye trait
		if (Third_Eye) {
			int y = 16;
			if (handSize == 4)
				y += 2;
			for (int i = y; i < y + 3; i++) {
				mvprintw(y, 63, "               ");
			}
			mvprintw(y, 62, "Next: ");
			if (Draw.size() > 0) {
				Card nextCardName = Draw.back();
				if (nextCardName.CardType == "Attack")
					attron(COLOR_PAIR(1));
				else if (nextCardName.CardType == "Defend")
					attron(COLOR_PAIR(2));
				else if (nextCardName.CardType == "Spell")
					attron(COLOR_PAIR(3));
				else if (nextCardName.CardType == "Special")
					standend();
				else if (nextCardName.CardType == "Negative")
					attron(COLOR_PAIR(5));
				mvprintw(y+1, 63, "%s", nextCardName.CardName);
			}
			if (Draw.size() > 1) {
				Card next2 = Draw.at(Draw.size() - 2);
				if (next2.CardType == "Attack")
					attron(COLOR_PAIR(1));
				else if (next2.CardType == "Defend")
					attron(COLOR_PAIR(2));
				else if (next2.CardType == "Spell")
					attron(COLOR_PAIR(3));
				else if (next2.CardType == "Special")
					standend();
				else if (next2.CardType == "Negative")
					attron(COLOR_PAIR(5));
				mvprintw(y+2, 63, "%s", next2.CardName);
			}
			standend();
		}

		//redraws the decision box
		manualBox("Desicion", 0);
}

//get choice of card in combat
void InputBoard::getchCard(Character &guy, Enemy &enemy, Deck &deck, TextLog &log) {
	//if your hand is filled with possibly unusable cards, you may reshuffle
	if (!checkUsable(guy, enemy)) {
		mvprintInSize(15, 18, 0, "#rTake a turn to #o(R)#reshuffle#o", FALSE);
	}
	else {
		manualBox("Decision", 0);
	}
	//Wings trait
	if (guy.Wings && RoomType != "Final Boss") {
		int y = 17;
		if (handSize == 4)
			y += 2;
		if (Third_Eye)
			y += 3;
		if (guy.Multi_Tongued)
			y++;
		mvprintInSize(y, 62, 11, "4) Leave", FALSE);
	}
	if (guy.Multi_Tongued) {
		int y = 17;
		if (handSize == 4)
			y += 2;
		if (Third_Eye)
			y += 3;
		mvprintInSize(y, 62, 11, "5) Negotiate", FALSE);
	}


	char choose = getch();
	//if you press 1-3, play the corresponding card
		//if you have the Triple-Jointed trait, you can play a fourth card
		//checks if you don't have enough mana for spells or enough block for Flee
	//press d to view your deck
	//the r is for reshuffling
	//else, keep this screen
	if (choose == '1' || choose == '2' || choose == '3' || (choose == '4' && handSize == 4)) {
		int in = choose - '0';
		in--;
		if (!checkUsable(in, guy, enemy)) {
			getchCard(guy, enemy, deck, log);
		}
		else {
			//Burn, Stay, Copy, Flow, and Link mods are taken care of here
			DecisionCards.at(in).cardFunction(guy, enemy, log);
			//check link
			if (DecisionCards.at(in).Link != '0') {
				int lint = DecisionCards.at(in).Link - '0';
				lint++;
				if (lint == 10) {
					linkdraw = '-';
				}
				else {
					linkdraw = char(lint);
				}
			}
			//check burn, stay
			if (DecisionCards.at(in).Stay)
				DecisionCards.at(in).StayCard = TRUE;
			if (DecisionCards.at(in).Push)
				pushthisturn = TRUE;
			if (!DecisionCards.at(in).Burn && !DecisionCards.at(in).naturalBurn && !DecisionCards.at(in).Stay)
				Discard.push_back(DecisionCards.at(in));
			//check copy
			if(DecisionCards.at(in).Copy && (Draw.size() + Discard.size()) < 75)
				Discard.push_back(DecisionCards.at(in));
			//check stay
			if (!DecisionCards.at(in).Stay || DecisionCards.at(in).Burn || DecisionCards.at(in).naturalBurn) {
				DecisionCards.erase(DecisionCards.begin() + in);
			}
			//check flow
			int limit2 = 0;
			while (DecisionCards.size() > limit2) {
				if (DecisionCards.at(limit2).Stay) {
					if (!DecisionCards.at(limit2).Push)
						DecisionCards.at(limit2).StayCard = FALSE;
					limit2++;
				}
				else if (DecisionCards.at(limit2).Flow) {
					Discard.push_back(DecisionCards.at(limit2));
					DecisionCards.erase(DecisionCards.begin() + limit2);
				}
				else {
					limit2++;
				}
			}
		}
	}
	else if (choose == 'r' && !checkUsable(guy, enemy)) {
		
		while (Draw.size() > 0) {
			Card tempCard = Draw.back();
			Draw.pop_back();

			int rng = rand() % (Discard.size() + 1);
			Discard.insert(Discard.begin() + rng, tempCard);
		}
		while (DecisionCards.size() > 0) {
			Card tempCard = DecisionCards.back();
			DecisionCards.pop_back();

			int rng = rand() % (Discard.size() + 1);
			Discard.insert(Discard.begin() + rng, tempCard);
		}
		ShuffleAddPrint();
	}
	else if (choose == 'd') {
		deck.deckScreen();

		int c = 0;
		escapeLoop(c);
		
		log.printLog();
		ShuffleAddPrint();
		getchCard(guy, enemy, deck, log);
	}
	else if (choose == 't') {
		showTraits();

		log.printLog();
		ShuffleAddPrint();
		getchCard(guy, enemy, deck, log);
	}
	//Wings trait
	else if (choose == '6' && guy.Wings && RoomType != "Final Boss") {
		guy.WingsUsed = TRUE;
	}
	else if (choose == '5' && guy.Multi_Tongued) {
		guy.negotiate = TRUE;
	}
	else {
		getchCard(guy, enemy, deck, log);
	}
}

//checks if you cant use any of the cards in your hand
bool InputBoard::checkUsable(Character &guy, Enemy &enemy) {
	int cardsUsable = handSize;
	bool usable = TRUE;
	if (DecisionCards.size() == 0)
		return FALSE;
	for (int i = 0; i < handSize; i++) {
		if (DecisionCards.size() <= i)
			cardsUsable--;
		else if ((DecisionCards.at(i).ManaCost > 0 && DecisionCards.at(i).ManaCost > guy.CurrentMana) ||
			(DecisionCards.at(i).CardName == "Flee" && guy.CurrentBlock <= 0) ||
			(DecisionCards.at(i).CardName == "Impale" && enemy.CurrentHealth + enemy.CurrentBlock > guy.Strength * 3) ||
			(DecisionCards.at(i).CardName == "Shoot" && guy.CurrentHealth + guy.CurrentBlock <= 7))
			cardsUsable--;
	}
	if (cardsUsable == 0)
		usable = FALSE;
	return usable;
}
//checks if you cant use a card in a specific place in your hand
bool InputBoard::checkUsable(int i, Character &guy, Enemy &enemy) {
	bool usable = TRUE;
	if (DecisionCards.size() <= i)
		return FALSE;
	else if ((DecisionCards.at(i).ManaCost > 0 && DecisionCards.at(i).ManaCost > guy.CurrentMana) ||
		(DecisionCards.at(i).CardName == "Flee" && guy.CurrentBlock <= 0) ||
		(DecisionCards.at(i).CardName == "Impale" && enemy.CurrentHealth + enemy.CurrentBlock > guy.Strength * 3))
		usable = FALSE;
	return usable;
}

//decide enemy based on room tier
Enemy InputBoard::generateEnemy(Character &guy) {
	Enemy enemy;
	if ((guy.posx == 1 && guy.posy == 0) || (guy.posx == 0 && guy.posy == 1))
		enemy = Enemy("Rat");
	else {
		if (guy.getTier() == 'A') {
			int rng = rand() % 5;
			if (rng == 0)
				enemy = Enemy("Kobold");
			else if (rng > 0 && rng <= 2) {
				enemy = Enemy("Crab");
			}
			else if (rng == 3) {
				enemy = tierone;
			}
			else {
				enemy = Enemy("Rat");
			}
		}
		else if (guy.getTier() == 'B') {
			int rng = rand() % 4;
			if (rng == 0)
				enemy = Enemy("Kobold");
			else if (rng == 1) {
				enemy = Enemy("Zombie");
			}
			else if (rng == 2) {
				enemy = tierone;
			}
			else {
				enemy = Enemy("Hound");
			}
		}
		else if (guy.getTier() == 'C' || guy.getTier() == 'D') {
			int rng = rand() % 5;
			if (rng == 0)
				enemy = Enemy("Giant Rat");
			else if (rng == 1)
				enemy = Enemy("Wild Buffalo");
			else if (rng == 2)
				enemy = Enemy("Harpy");
			else if (rng == 3) {
				enemy = tiertwo;
			}
			else
				enemy = Enemy("Brown Recluse");

		}
		else if (guy.getTier() == 'E') {
			int rng = rand() % 7;
			if (rng == 0)
				enemy = Enemy("Troll");
			else if (rng == 1) {
				enemy = Enemy("Elemental");
			}
			else if (rng == 2) {
				enemy = tierthree1;
			}
			else if (rng == 3) {
				enemy = tierthree2;
			}
			else {
				enemy = Enemy("Adventurer");
			}
		}
		else if (guy.getTier() == 'F') {
			int rng = rand() % 13;
			if (rng < 2)
				enemy = Enemy("Troll");
			else if (rng >= 2 && rng < 4) {
				enemy = Enemy("Elemental");
			}
			else if (rng >= 4 && rng < 7) {
				enemy = tierthree1;
			}
			else if (rng >= 7 && rng < 10) {
				enemy = tierthree2;
			}
			else {
				enemy = Enemy("Adventurer");
			}
		}
	}
	if(enemy.Name == "Adventurer")
		enemy.type = rand() % 4;
	return enemy;
}

//generates a battle based on what tile the character is on
void InputBoard::startBattle(Character &guy, Deck &deck, TextLog &log) {
	handSize = guy.handSize;
	Third_Eye = guy.Third_Eye;

	updateDeck(deck);
		Enemy enemy;
		manualBox("Display", 0);

		//gets the final boss
		if (RoomType == "Final Boss") {
			enemy = FinalBoss;
		}
		//chooses a boss
		else if (RoomType == "Boss") {
			//check if boss array is empty
			if (bosses.size() < 1) {
				bosses.push_back(Enemy("Paladin"));
				bosses.push_back(Enemy("Hunter"));
				bosses.push_back(Enemy("Juggernaut"));
				bosses.push_back(Enemy("Vampire"));
				bosses.push_back(Enemy("Hydra"));
				bosses.push_back(Enemy("Exorcist"));
				bosses.push_back(Enemy("Demigod"));
			}
			int rng = rand() % bosses.size();
			enemy = bosses.at(rng);
			bosses.erase(bosses.begin() + rng);
			
		}
		//chooses a regular enemy
		else if (RoomType == "Combat"){
			enemy = generateEnemy(guy);
		}

		//pushes line into log when encountering an enemy
		//checks for vowels and pushes "a" and "an" accordingly
		string encounter;
		if (enemy.Name[0] == 'A' || enemy.Name[0] == 'E' || enemy.Name[0] == 'I' || enemy.Name[0] == 'O' || enemy.Name[0] == 'U') {
			encounter = " You encounter an " + string(enemy.Name) + ".";
		}
		else
			encounter = " You encounter a " + string(enemy.Name) + ".";
		log.PushPop(encounter);

		//activate Tail trait
		if (guy.Tail) {
			Tail = TRUE;
		}
		//Slow trait
		if (guy.Slow) {
			enemy.enemyNegate++;
		}
		//Growing Pains trait
		if (guy.Growing_Pains) {
			int damage = 10;
			damage = guy.TakeDamage(damage);
			string pains = "-You take #r" + to_string(damage) + "#o damage.";
			log.PushPop(pains);
		}
		//Forgetful trait
		if (guy.Forgetful) {
			guy.CurrentMana = 0;
			string forget = "#f-You lose all of your mana.#o";
			log.PushPop(forget);
		}
		//Unseen trait
		if (guy.Unseen) {
			guy.extraTurns++;
			string un = "#g EXTRA TURN#o";
			log.PushPop(un);
		}

		log.printLog();

		//show the card options
		ShuffleAddPrint();

		//Foresight trait
		if (guy.Foresight == 1) {
			guy.fillType = "Spell";
			fillHand(guy);
			//guy.Foresight = 0;
		}  

		//battle loop
		while (enemy.Alive) {
			//check dead
			if (guy.CurrentHealth <= 0) {
				//Reconstruction Trait
				if (guy.Reconstruction && guy.Skill > 1) {
					guy.CurrentHealth = guy.MaxHealth;
					guy.ModStat(-2, "Skill");
					string recon = "#g You come back to life!#o";
					log.PushPop(recon);
				}
				guy.Alive = FALSE;
			}
			if (!guy.Alive) {
				break;
			}
			//show card options, update/print character stats, update/print enemy stats
			ShuffleAddPrint();
			guy.printStats();
			enemy.updateEnemy(guy);

			//Numb trait
			bool fuzzy = FALSE;
			if (guy.Numb)
				fuzzy = TRUE;

			mvprintInSize(10, 34, 0, "You", fuzzy);

			string stat = "HP: " + to_string(guy.CurrentHealth) + "/" + to_string(guy.MaxHealth) + "  ";
			mvprintInSize(11, 31, 0, stat.c_str(), fuzzy);
			stat = "MP: " + to_string(guy.CurrentMana) + "/" + to_string(guy.MaxMana) + "  ";
			mvprintInSize(12, 31, 0, stat.c_str(), fuzzy);

			//if you have any Negation, print the character block a bit more to the left to make room
			//print character block
			if (guy.Negate <= 0) {
				stat = "  Block: " + to_string(guy.CurrentBlock) + "  ";
				mvprintInSize(13, 29, 0, stat.c_str(), fuzzy);
				mvprintInSize(13, 41, 0, " ", fuzzy);
			}
			else {
				stat = "Block: " + to_string(guy.CurrentBlock) + "    ";
				mvprintInSize(13, 29, 0, stat.c_str(), fuzzy);
				stat = "(" + to_string(guy.Negate) + ")";
				mvprintInSize(13, 39, 0, stat.c_str(), fuzzy);
			}
			

			//check dead
			if (guy.CurrentHealth <= 0) {
				//Reconstruction Trait
				if (guy.Reconstruction && guy.Skill > 1) {
					guy.CurrentHealth = guy.MaxHealth;
					guy.ModStat(-2, "Skill");
					string recon = "#g You come back to life!#o";
					log.PushPop(recon);
				}
				else
					guy.Alive = FALSE;
			}
			if (!guy.Alive) {
				break;
			}
			//when the enemy dies, push the line about the enemy dying and restore your stats
			if (!checkEnemyLife(guy, enemy, deck, log))
				break;

			//Inefficient trait
			if (guy.Inefficient == 0) {
				guy.extraTurns++;
				guy.Inefficient = 1;
			}

			//checks for extra turns
			if (guy.extraTurns >= 0)
				getchCard(guy, enemy, deck, log);
			else if (guy.extraTurns < 0) {
				guy.extraTurns++;
				enemy.Turn(guy, log);
			}

			//Wings trait
			if (guy.Wings && guy.WingsUsed) {
				guy.WingsUsed = FALSE;

				string line = " You fly away.";
				log.PushPop(line);
				log.printLog();

				//revert in-battle effects
				restoreAfterBattle(guy, enemy, deck, log);

				for (int i = 0; i < 8; i++)
					mvprintw(6 + i, 29, "             ");
				clearBoard();

				RoomType = "Empty";

				//get decision for next choice
				printDecision(guy, log);
				getchDecision(guy, deck, log);
				break;
			}
			//Multi Tongued trait
			if (guy.Multi_Tongued && guy.negotiate) {
				guy.negotiate = FALSE;

				log.PushPop("");
				Negotiate(guy, enemy, deck, log);
				if (negotiateStep != -2) {
					negotiateStep = 0;

					string line = " You leave.";
					log.PushPop(line);
					log.printLog();

					for (int i = 0; i < 8; i++)
						mvprintw(6 + i, 29, "             ");
					clearBoard();

					//if its the final boss, set win varibale to TRUE. The win function will be played out in the main game loop
					if (RoomType == "Final Boss") {
						for (int i = 0; i < 8; i++)
							mvprintw(6 + i, 29, "             ");
						clearBoard();

						guy.Win = TRUE;
					}
					//if it is a boss or regular combat, push enemy death line, remove negative cards, restore stats
					else if (RoomType == "Boss" || RoomType == "Combat") {
						//revert in-battle effects
						restoreAfterBattle(guy, enemy, deck, log);

						for (int i = 0; i < 8; i++)
							mvprintw(6 + i, 29, "             ");
						clearBoard();

						//if its a boss, set the room to addition (not done yet)
						if (RoomType == "Boss") {
							//Overconfidence trait
							if (guy.Overconfidence)
								RoomType = "Stat";
							else
								RoomType = "Special";
							printDecision(guy, log);
							getchDecision(guy, deck, log);
						}
						//if its a regular enemy, set the room to stat
						else if (RoomType == "Combat") {
							//Overconfidence trait
							if (guy.Overconfidence)
								RoomType = "Special";
							else
								RoomType = "Stat";
							printDecision(guy, log);
							getchDecision(guy, deck, log);
						}

						//get decision for next choice
						printDecision(guy, log);
						getchDecision(guy, deck, log);
					}
					break;
				}
				else {
					negotiateStep = 0;
					ShuffleAddPrint();
				}
			}

			//checks for extra turns
			if (guy.extraTurns == 0)
				enemy.Turn(guy, log);
			else if(guy.extraTurns > 0)
				guy.extraTurns--;

			//apply any special mechanics
			effectsBeforeTurns(guy, enemy, deck, log);
			if(guy.Fast_Metabolism)
				effectsBeforeTurns(guy, enemy, deck, log);

			//Numb trait
			if (!guy.Numb) {
				mvprintw(10, 34, "You");
				mvprintw(11, 31, "HP: %d/%d  ", guy.CurrentHealth, guy.MaxHealth);
				mvprintw(12, 31, "MP: %d/%d  ", guy.CurrentMana, guy.MaxMana);

				//if you have any Negation, print the character block a bit more to the left to make room
				//print character block
				if (guy.Negate <= 0) {
					mvprintw(13, 29, "  Block: %d  ", guy.CurrentBlock);
					mvprintw(13, 41, " ");
				}
				else {
					mvprintw(13, 29, "Block: %d    ", guy.CurrentBlock);
					mvprintw(13, 39, "(%d)", guy.Negate);
				}
			}

			//check dead
			if (guy.CurrentHealth <= 0) {
				//Reconstruction Trait
				if (guy.Reconstruction && guy.Skill > 1) {
					guy.CurrentHealth = guy.MaxHealth;
					guy.ModStat(-2, "Skill");
					string recon = "#g You come back to life!#o";
					log.PushPop(recon);
				}
				else
					guy.Alive = FALSE;
			}
			if (!guy.Alive) {
				break;
			}
			//check again if enemy is dead
			if (!checkEnemyLife(guy, enemy, deck, log))
				break;

			//reprint log
			log.printLog();
		}
}

int InputBoard::gainBlock(int block, Character &guy) {
	if (block < 0)
		return 0;
	else {
		//Charred Skin trait
		if (guy.Charred_Skin)
			guy.TakeDamage(-1 * block);
		else
			guy.CurrentBlock += block;
	}
	return block;
}

//call special mechanics on characters if requested
void InputBoard::effectsBeforeTurns(Character &guy, Enemy &enemy, Deck &deck, TextLog &log) {
	if (enemy.CurrentHealth <= 0) {
		return;
	}
	if (guy.CurrentHealth <= 0) {
		//Reconstruction Trait
		if (guy.Reconstruction && guy.Skill > 1) {
			guy.CurrentHealth = guy.MaxHealth;
			guy.ModStat(-2, "Skill");
			string recon = "#g You come back to life!#o";
			log.PushPop(recon);
		}
		else
			return;
	}
	//for the specific spells
	//regenerate
	if (guy.regenerateTurns > 0) {
		int heal = 2 + rtd(1, guy.Intelligence);
		guy.TakeDamage(-1 * heal);
		string line = "-You gain #g" + to_string(heal) + "#o health.";
		log.PushPop(line);
		guy.regenerateTurns--;
	}
	//incense
	if (guy.incense > 0) {
		int mana = 3;
		guy.DrainMana(-1 * mana);

		int block = 5;
		block = gainBlock(block, guy);

		string line = "-You gain #m" + to_string(mana) + "#o mana and #c" + to_string(block) + "#o block.";
		log.PushPop(line);
		guy.incense--;
	}
	//refresh
	if (guy.refresh) {
		int mana = 1*guy.refresh;
		guy.DrainMana(-1*mana);

		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		log.PushPop(line);
	}
	//metabolise
	if (guy.metabolise > 0) {
		int mana = 2;
		int health = 4;
		guy.TakeDamage(-1 * health);
		guy.DrainMana(-1 * 2);

		string line = "-You gain #g" + to_string(health) + "#o health and #m" + to_string(mana) + "#o mana.";
		log.PushPop(line);
		guy.metabolise--;
	}
	//intimidate
	if (guy.intimidate > 0) {
		guy.intimidate--;
	}
	//Exoskeleton
	if (guy.Exoskeleton) {
		int block = rtd(1, guy.Skill-1);
		block = gainBlock(block, guy);
		string exo = "-You gain #c" + to_string(block) + "#o block.";
		//log.PushPop(exo);
	}
	//Mending Flesh trait
	if (guy.Mending_Flesh) {
		int hp = rtd(1, guy.Skill);
		guy.TakeDamage(-1 * hp);
		string mend = "-You regenerate #g" + to_string(hp) + "#o health.";
		//log.PushPop(mend);
	}
	//Quick Thinker trait
	if (guy.Quick_Thinker && guy.CurrentMana <= guy.MaxMana) {
		if (rand() % 100 < guy.Skill*8) {
			int mana = 5;
			guy.DrainMana(-1*mana);
			string think = "#m-You suddenly gain 5 mana.#o";
			log.PushPop(think);
		}
	}
	//Conversion trait
	if (guy.Conversion) {
		guy.DrainMana(2);
		guy.TakeDamage(-1);
		string conv = "-You #rlose 2 mana#o and gain #g1#o health.";
		//log.PushPop(conv);
	}
	//Anemia trait
	if (guy.Anemia && guy.CurrentHealth > 5) {
		if (rand() % 4 == 0) {
			guy.CurrentHealth -= 5;
			string line = "-You #rlose 5 health.#o";
			log.PushPop(line);
		}
	}
	//Inversion trait
	if (guy.Inversion) {
		guy.DrainMana(-1);
		guy.TakeDamage(3);
		string inv = "-You gain #m1#o mana and take #r3#o damage.";
		//log.PushPop(inv);
	}

	//Melting trait
	if (guy.Melting) {
		if (guy.CurrentBlock == 1)
			guy.CurrentBlock = 0;
		else if (guy.CurrentBlock > 1)
			guy.CurrentBlock -= 2;

		guy.TakeDamage(1);

		string melt = "-You #rlose 2 block#o and take #r1#o damage.";
		//log.PushPop(melt);
	}
	//Radioactive trait
	if (guy.Radioactive) {
		int damage = guy.Skill / 2;
		damage = guy.TakeDamage(damage);
		enemy.takeDamage(damage, guy, log);

		string radiate = "-You radiate #r" + to_string(damage) + "#o damage.";
		//log.PushPop(radiate);
	}
	//Jittery trait
	if (guy.Jittery != -1) {
		if (guy.CurrentBlock == 0 && guy.Negate == 0) {
			guy.Jittery = 0;
		}
		if (guy.Jittery == 4) {
			guy.CurrentBlock = 0;
			guy.Negate = 0;
			guy.Jittery = 0;

			string jitter = "#r-You lose all of your defenses.#o";
			log.PushPop(jitter);
		}
		else if (guy.CurrentBlock > 0 || guy.Negate > 0) {
			guy.Jittery++;
		}
	}
	//Volatile trait
	if (guy.Volatile != -1) {
		if (guy.Volatile == 3) {
			int damage = 15;
			damage = guy.TakeDamage(15);
			enemy.takeDamage(15, guy, log);
			guy.Volatile = 0;

			string erupt = "#r-You erupt, taking and dealing " + to_string(damage) + " damage.#o";
			log.PushPop(erupt);
		}
		else{
			guy.Volatile++;
		}
	}
	//The Juice
	if (guy.The_Juice) {
		vector<string> stats;
		stats.push_back("Max Health");
		stats.push_back("Max Mana");
		stats.push_back("Strength");
		stats.push_back("Defense");
		stats.push_back("Intelligence");
		stats.push_back("Skill");

		int rng = rand() % stats.size();
		guy.ModStat(6, stats.at(rng));
		stats.erase(stats.begin() + rng);

		int rng2 = rand() % stats.size();
		guy.ModStat(-5, stats.at(rng2));

		string drink;
		int rngline = rand() % 6;
		switch (rngline) {
		case 0:
			drink = "#g You change.#o";
			break;
		case 1:
			drink = "#g You morph.#o";
			break;
		case 2:
			drink = "#g You shift.#o";
			break;
		case 3:
			drink = "#g You mutate.#o";
			break;
		case 4:
			drink = "#g You deform.#o";
			break;
		case 5:
			drink = "#g You reshape.#o";
			break;
		}
		log.PushPop(drink);
		guy.printStats();
	}
	//Sticky Feet trait
	if (guy.Sticky_Feet != -1) {
		if (guy.Sticky_Feet == 10) {
			guy.Sticky_Feet = 0;
			guy.extraTurns--;
			string stick = "#r You lose a turn.#o";
			log.PushPop(stick);
		}
		else {
			guy.Sticky_Feet++;
		}
	}
	//Hallucinations trait
	if (guy.Hallucinations) {
		if (rand() % 7 == 0) {
			int enemyhp = enemy.CurrentHealth;
			int enemyblock = enemy.CurrentBlock;
			int enemyneg = enemy.enemyNegate;
			int enemytc = enemy.TurnCount;
			int enemydot = enemy.dot;

			vector<Enemy> enemylist;
			enemylist.push_back(Enemy("Rat"));
			enemylist.push_back(Enemy("Crab"));
			enemylist.push_back(Enemy("Hound"));
			enemylist.push_back(Enemy("Zombie"));
			enemylist.push_back(Enemy("Kobold"));
			enemylist.push_back(Enemy("Giant Rat"));
			enemylist.push_back(Enemy("Wild Buffalo"));
			enemylist.push_back(Enemy("Harpy"));
			enemylist.push_back(Enemy("Brown Recluse"));
			enemylist.push_back(Enemy("Adventurer"));
			enemylist.push_back(Enemy("Adventurer"));
			enemylist.push_back(Enemy("Troll"));
			enemylist.push_back(Enemy("Elemental"));

			enemylist.push_back(Enemy("Hatchling"));
			enemylist.push_back(Enemy("Molten Jelly"));
			enemylist.push_back(Enemy("Knight"));
			enemylist.push_back(Enemy("Drake"));
			enemylist.push_back(Enemy("Slave"));
			enemylist.push_back(Enemy("Soldier"));
			enemylist.push_back(Enemy("Guard"));
			enemylist.push_back(Enemy("Jester"));
			enemylist.push_back(Enemy("Eyeball"));
			enemylist.push_back(Enemy("Apprentice"));
			enemylist.push_back(Enemy("Monster"));
			enemylist.push_back(Enemy("Brain"));
			enemylist.push_back(Enemy("Cultist"));
			enemylist.push_back(Enemy("Imp"));
			enemylist.push_back(Enemy("Weeping Soul"));
			enemylist.push_back(Enemy("Hellhound"));
			enemylist.push_back(Enemy("Robot"));
			enemylist.push_back(Enemy("Golem"));
			enemylist.push_back(Enemy("Merchant"));
			enemylist.push_back(Enemy("Turret"));

			enemylist.push_back(Enemy("Paladin"));
			enemylist.push_back(Enemy("Juggernaut"));
			enemylist.push_back(Enemy("Vampire"));
			enemylist.push_back(Enemy("Hydra"));
			enemylist.push_back(Enemy("Demigod"));
			enemylist.push_back(Enemy("Hunter"));
			enemylist.push_back(Enemy("Exorcist"));
			enemylist.push_back(Enemy("Wolf"));

			enemylist.push_back(Enemy("King"));
			enemylist.push_back(Enemy("Demon"));
			enemylist.push_back(Enemy("Witch"));
			enemylist.push_back(Enemy("Dragon"));
			enemylist.push_back(Enemy("Machine"));

			int randenemy = rand() % enemylist.size();
			enemy = enemylist.at(randenemy);

			enemy.CurrentHealth = enemyhp;
			enemy.CurrentBlock = enemyblock;
			enemy.enemyNegate = enemyneg;
			enemy.TurnCount = enemytc;
			enemy.dot = enemydot;

			if (enemy.CurrentHealth > enemy.MaxHealth) {
				enemy.CurrentHealth = enemy.MaxHealth;
			}

			string line;
			int rngline = rand() % 3;
			if(rngline == 0)
				line = "#b The #renemy #gchanges!#o";
			else if (rngline == 1)
				line = "#r The #genemy #bchanges!#o";
			else if (rngline == 2)
				line = "#g The #benemy #rchanges!#o";
			log.PushPop(line);
		}
	}

	//apply any damage over time from enemies
	enemy.ActivateDOT(guy, log);

	//shuffles if shuffle is true
	if (guy.shuffle) {
		shuffleHand();
		guy.shuffle = FALSE;
	}

	//fills hand with certain cards if requested
	fillHand(guy);
	
	//add negative cards if any
	addNegative(guy, deck);

	//Gymnast trait
	if (guy.Gymnast) {
		/*
		1 = 4
		2 = 8
		3 = 12
		*/
		int exturn = rand() % 100;
		if (exturn < 4 * guy.Skill) {
			guy.extraTurns++;
			string ex = "#g EXTRA TURN#o";
			log.PushPop(ex);
		}
	}
}

//checks if the enemy is dead, ends the battle if so
bool InputBoard::checkEnemyLife(Character &guy, Enemy &enemy, Deck &deck, TextLog& log) {
	bool live = TRUE;
	if (!enemy.Alive) {
		live = FALSE;
		//if its the final boss, set win varibale to TRUE. The win function will be played out in the main game loop
		if (RoomType == "Final Boss") {
			string line = "-The " + string(enemy.Name)
				+ " dies. ";
			log.PushPop(line);
			log.printLog();

			for (int i = 0; i < 8; i++)
				mvprintw(6 + i, 29, "             ");
			clearBoard();

			guy.Win = TRUE;
		}
		//if it is a boss or regular combat, push enemy death line, remove negative cards, restore stats
		else if (RoomType == "Boss" || RoomType == "Combat") {
			string line = "-The " + string(enemy.Name)
				+ " dies. ";
			log.PushPop(line);
			log.printLog();

			//revert in-battle effects
			restoreAfterBattle(guy, enemy, deck, log);

			for (int i = 0; i < 8; i++)
				mvprintw(6 + i, 29, "             ");
			clearBoard();

			//if its a boss, set the room to addition (not done yet)
			if (RoomType == "Boss") {
				//Overconfidence trait
				if (guy.Overconfidence)
					RoomType = "Stat";
				else
					RoomType = "Special";
				printDecision(guy, log);
				getchDecision(guy, deck, log);
			}
			//if its a regular enemy, set the room to stat
			else if (RoomType == "Combat") {
				//Overconfidence trait
				if (guy.Overconfidence)
					RoomType = "Special";
				else
					RoomType = "Stat";
				printDecision(guy, log);
				getchDecision(guy, deck, log);
			}

			//get decision for next choice
			printDecision(guy, log);
			getchDecision(guy, deck, log);
		}
	}
	return live;
}

//restore any in-battle effects
void InputBoard::restoreAfterBattle(Character &guy, Enemy &enemy, Deck &deck, TextLog &log) {
	removeNegatives(deck);
	restoreStats(guy);
	guy.dotDamage = 0;
	enemy.bleeding = 0;
	enemy.fumes = 0;
	guy.Negate = 0;
	guy.regenerateTurns = 0;
	guy.smoke = 0;
	guy.incense = 0;
	guy.damageToMana = 0;
	guy.mirror = 0;
	guy.mirrorDamage = 0;
	guy.copy = 0;
	guy.charge = 0;
	guy.chargeMana = 0;
	guy.shuffle = FALSE;
	guy.fillType = " ";
	guy.drown = 0;
	guy.refresh = 0;
	if(guy.Volatile != -1)
		guy.Volatile = 0;
	if(guy.Jittery != -1)
		guy.Jittery = 0;
	guy.SpinyDamage = 0;
	if(guy.Sticky_Feet != -1)
		guy.Sticky_Feet = 0;
	if (guy.Inefficient != -1)
		guy.Inefficient = 0;

	guy.CurrentHealth = guy.MaxHealth;
	guy.CurrentMana = guy.MaxMana;
	guy.CurrentBlock = 0;
	guy.printStats();
}

//print function for non-combat decisions
//separated from getch because getch must always go after all of this printing, easier to maintain and add stuff this way
void InputBoard::printDecision(Character &guy, TextLog &log) {
	//clears the decision board, reprints windows
	clearBoardWhole();
	manualBox("Decision", 0);
	manualBox("Card 1", 0);
	manualBox("Card 2", 0);
	manualBox("Card 3", 0);

	//Destiny trait
	if (guy.Destiny == 1 && RoomType == "Cauldron") {
		RoomType = "Empty";
	}

	//Weak Back trait
	if (guy.Weak_Back && (RoomType == "Gear Hands" || RoomType == "Gear Body" || RoomType == "Gear Head"))
		RoomType = "Empty";

	//if it is the first room, print choice of movement
	if (RoomType == "First") {
		for (int y = 16; y < 24; y++) {
			mvprintw(y, 1, "                                                                      ");
		}
		manualBox("Card 2", 0);
		//print legend
		attron(COLOR_PAIR(5));
		mvprintw(16, 4, "!");
		attron(COLOR_PAIR(7));
		mvprintw(17, 4, "o");
		mvprintw(18, 4, "&");
		attron(COLOR_PAIR(2));
		mvprintw(19, 4, "^");
		mvprintw(20, 4, "#");
		mvprintw(21, 4, "/");
		attron(COLOR_PAIR(3));
		mvprintw(22, 4, "+");
		standend();

		mvprintw(16, 6, "= Combat");
		mvprintw(17, 6, "= Boss");
		mvprintw(18, 6, "= Final Boss");

		mvprintw(19, 6, "= Headgear");
		mvprintw(20, 6, "= Armor");
		mvprintw(21, 6, "= Weapon");
		mvprintw(22, 6, "= Cauldron");

		mvprintw(17, 26, "Which way?");
		if (guy.posx == 25) {
			mvprintw(19, 25, "1) Up");
			mvprintw(0, 25, "        ");
		}
		else if (guy.posy == 7) {
			mvprintw(19, 25, "1) Right");
			mvprintw(20, 25, "        ");
		}
		else {
			mvprintw(19, 25, "1) Up");
			mvprintw(20, 25, "2) Right");
		}
	}
	//if it is a stat room, print choice of stat upgrade
	else if (RoomType == "Stat") {
		for (int y = 16; y < 24; y++) {
			mvprintw(y, 1, "                                                                            ");
		}
		manualBox("Card 1", 0);
		manualBox("Card 2", 0);
		manualBox("Card 3", 0);

		mvprintw(17, 24, "Choose a stat.");
		mvprintw(19, 25, "1) +1 Str");
		mvprintw(20, 25, "2) +1 Def");
		mvprintw(21, 25, "3) +1 Int");

		if (guy.Carnivore) {
			guy.ModStat(1, "MaxHealth");
			guy.CurrentHealth = guy.MaxHealth;
			string car = "#g~You gain 1 Max Health.#o";
			log.PushPop(car);
		}
	}
	else if (RoomType == "Mod") {
		
	}
	//if the room is empty, get choice of movement
	else if (RoomType == "Empty") {
		for (int y = 16; y < 24; y++) {
			mvprintw(y, 1, "                                                                            ");
		}
		//Teleportitis trait
		if (guy.Teleportitis && rand() % 4 == 0) {
			int tiles = (rand() % 4)-2;
			if (tiles == 0)
				tiles += 2;

			int axis = rand() % 2;
			if (tiles > 0) {
				if (axis == 0 && guy.posx < 23)
					guy.posx += tiles;
				else if (axis == 1 && guy.posy < 5)
					guy.posy += tiles;
			}
			else if (tiles < 0) {
				if (axis == 0 && guy.posx > 2)
					guy.posx += tiles;
				else if (axis == 1 && guy.posy > 2)
					guy.posy += tiles;
			}

			string tele = "#r You teleport.#o";
			log.PushPop(tele);
			log.printLog();
			return;
		}
		manualBox("Card 2", 0);

		//print legend
		attron(COLOR_PAIR(5));
		mvprintw(16, 4, "!");
		attron(COLOR_PAIR(7));
		mvprintw(17, 4, "o");
		mvprintw(18, 4, "&");
		attron(COLOR_PAIR(2));
		mvprintw(19, 4, "^");
		mvprintw(20, 4, "#");
		mvprintw(21, 4, "/");
		attron(COLOR_PAIR(3));
		mvprintw(22, 4, "+");
		standend();

		mvprintw(16, 6, "= Combat");
		mvprintw(17, 6, "= Boss");
		mvprintw(18, 6, "= Final Boss");

		mvprintw(19, 6, "= Headgear");
		mvprintw(20, 6, "= Armor");
		mvprintw(21, 6, "= Weapon");
		mvprintw(22, 6, "= Cauldron");

		mvprintw(17, 26, "Which way?");
		//print available options
		//check for Warper trait
		if (guy.posx == 25) {
			mvprintw(19, 25, "1) Up");
			if (guy.Warper > 0 && guy.posy > 0 && guy.posyBefore != guy.posy - 1) {
				mvprintw(20, 25, "2) Down");
			}
		}
		else if (guy.posy == 7) {
			mvprintw(19, 25, "1) Right");
			if (guy.Warper > 0 && guy.posy > 0 && guy.posyBefore != guy.posy - 1) {
				mvprintw(20, 25, "2) Down");
			}
		}
		else {
			mvprintw(19, 25, "1) Up");
			mvprintw(20, 25, "2) Right");
			if (guy.Warper > 0&& guy.posy > 0 && guy.posyBefore != guy.posy - 1) {
				mvprintw(21, 25, "3) Down");
			}
		}
	}
	//if the room is any type of gear, print the gear there
	else if (RoomType == "Gear Hands" || RoomType == "Gear Body" || RoomType == "Gear Head") {
		//put procgen here
		for (int y = 16; y < 24; y++) {
			mvprintw(y, 1, "                                                                      ");
		}
		if (inventory.size() >= 9) {
			string line = "#r*Your inventory is full.#o";
			log.PushPop(line);
			log.printLog();
			RoomType = "Empty";
			printDecision(guy, log);
		}
		else {
			mvprintInSize(17, 4, 15, "You found some gear: ", FALSE);
			generateGear(guy);
			pickup.printGear(2, guy);
			/*else if (RoomType == "Gear Body") {
				//put procgen here
				mvprintInSize(19, 4, 15, "You found some gear: ");
				pickup = Gear("Mage Armor");
				pickup.printGear(2);
			}
			else if (RoomType == "Gear Hands") {
				//put procgen here
				mvprintInSize(19, 4, 15, "You found some gear: ");
				pickup = Gear("Crystal Ball");
				pickup.printGear(2);
			}*/
		}
	}
	else if (RoomType == "Special") {
		for (int i = 0; i < 8; i++)
			mvprintw(6 + i, 29, "             ");
		clearBoard();

		mvprintw(8, 32, "CHOOSE A");
		mvprintw(9, 32, "CARD TO");
		mvprintw(10, 32, "  ADD");
		mvprintw(17, 62, "4) Leave");

		generateSpecial();
		for (int i = 0; i < 3; i++) {
			specialDecision.at(i).printCard(i+1);
		}
	}
	else if (RoomType == "Spell") {
		for (int i = 0; i < 8; i++)
			mvprintw(6 + i, 29, "             ");
		clearBoard();

		attron(COLOR_PAIR(3));
		mvprintw(8, 32, "Choose a");
		mvprintw(9, 32, "spell to");
		mvprintw(10, 32, "  add");
		standend();
		mvprintw(17, 62, "4) Leave");

		while (spellDecision.size() < 3) {
			int randspell = rand() % AvailableSpells.size();
			spellDecision.push_back(AvailableSpells.at(randspell));
			AvailableSpells.erase(AvailableSpells.begin() + randspell);
		}

		for (int i = 0; i < 3; i++) {
			spellDecision.at(i).printCard(i + 1);
		}
	}
	else if (RoomType == "Cauldron") {
		for (int i = 0; i < 8; i++)
			mvprintw(6 + i, 29, "             ");
		clearBoard();

		guy.ModStat(1, "Skill");
		guy.printStats();
		mvprintw(6, 32, "+1 Skill");
		string skill1 = "#g~You gain 1 Skill.#o";
		log.PushPop(skill1);
		log.printLog();

		attron(COLOR_PAIR(5));
		//6
		manualBox("Display", 0);
		mvprintw(8, 33, "CHOOSE");
		mvprintw(10, 35, "A");
		mvprintw(12, 31, "SACRIFICE");
		//14
		standend();

		generateTraits();

		for (int i = 0; i < 3; i++) {
			TraitsDecision.at(i).printGear(i+1, guy);
		}
	}
	else if (RoomType == "Cauldron 2") {
		for (int i = 0; i < 8; i++)
			mvprintw(6 + i, 29, "             ");
		clearBoard();

		attron(COLOR_PAIR(7));
		//6
		manualBox("Display", 0);
		mvprintw(7, 33, "CHOOSE");
		mvprintw(9, 35, "A");
		mvprintw(11, 33, "REWARD");
		//14
		standend();

		generateTraits();

		for (int i = 0; i < 3; i++) {
			TraitsDecision.at(i).printGear(i + 1, guy);
		}
	}
}

void InputBoard::generateMods() {
	rand
}

void InputBoard::generateGear(Character &guy) {
	//refill any arrays if needed
	if (handsNorm.size() == 0) {
		handsNorm.push_back(Gear("Long Sword"));
		handsNorm.push_back(Gear("Falchion"));
		handsNorm.push_back(Gear("Staff"));
		handsNorm.push_back(Gear("Steel Spear"));
		handsNorm.push_back(Gear("Halberd"));
		handsNorm.push_back(Gear("Rapier"));
		handsNorm.push_back(Gear("Battle Axe"));
		handsNorm.push_back(Gear("Shiv"));
		handsNorm.push_back(Gear("Serrated Dagger"));
		handsNorm.push_back(Gear("Simple Bow"));
		handsNorm.push_back(Gear("Sickle"));
	}
	if (handsLate.size() == 0) {
		handsLate.push_back(Gear("Obsidian Spear"));
		handsLate.push_back(Gear("Lance"));
		handsLate.push_back(Gear("War Hammer"));
		handsLate.push_back(Gear("Morning Star"));
		handsLate.push_back(Gear("Double Axe"));
		handsLate.push_back(Gear("Throwing Stars"));
		handsLate.push_back(Gear("Recurve Bow"));
	}
	if (bodyNorm.size() == 0) {
		bodyNorm.push_back(Gear("Leather Hauberk"));
		bodyNorm.push_back(Gear("Reinforced Mail"));
		bodyNorm.push_back(Gear("Full Plate Armor"));
		bodyNorm.push_back(Gear("Cape"));
		bodyNorm.push_back(Gear("Steel Breastplate"));
		bodyNorm.push_back(Gear("Feathered Cloak"));
		bodyLate.push_back(Gear("Buffalo Hide"));
	}
	if (bodyLate.size() == 0) {
		bodyLate.push_back(Gear("Riveted Chainmail"));
		bodyLate.push_back(Gear("Glitter Robes"));
		bodyLate.push_back(Gear("Spiked Mail"));
		bodyLate.push_back(Gear("Dragon Scales"));
		bodyLate.push_back(Gear("Twilight Robes"));
		bodyLate.push_back(Gear("Crystal Breastplate"));
	}
	if (headNorm.size() == 0) {
		headNorm.push_back(Gear("Vampire Fangs"));
		headNorm.push_back(Gear("Warp Goggles"));
		headNorm.push_back(Gear("Tundra Cap"));
		headNorm.push_back(Gear("Plague Mask"));
		headNorm.push_back(Gear("Dragonskin Hood"));
		headNorm.push_back(Gear("Shifting Veil"));
		headNorm.push_back(Gear("Copper Cage"));
		headNorm.push_back(Gear("Bedstone Helmet"));
	}

	bool rare = FALSE;
	if (rand() % 50 == 0)
		rare = TRUE;
	if (RoomType == "Gear Hands") {
		if (rare && handsRare.size() > 0) {
			int rareng = rand() % handsRare.size();
			pickup = handsRare.at(rareng);
			handsRare.erase(handsRare.begin() + rareng);
		}
		else {
			if (guy.getTier(guy.posx, guy.posy) == 'A') {
				int rng = rand() % handsNorm.size();
				pickup = handsNorm.at(rng);
				handsNorm.erase(handsNorm.begin() + rng);
			}
			else if (guy.getTier(guy.posx, guy.posy) == 'B') {
				int normrare = rand() % 5;
				if (normrare == 0 || handsNorm.size() == 0) {
					int rng = rand() % handsLate.size();
					pickup = handsLate.at(rng);
					handsLate.erase(handsLate.begin() + rng);
				}
				else {
					int rng = rand() % handsNorm.size();
					pickup = handsNorm.at(rng);
					handsNorm.erase(handsNorm.begin() + rng);
				}
			}
			else if (guy.getTier(guy.posx, guy.posy) == 'C' || guy.getTier(guy.posx, guy.posy) == 'D') {
				int normrare = rand() % 5;
				if (normrare < 2 || handsNorm.size() == 0) {
					int rng = rand() % handsLate.size();
					pickup = handsLate.at(rng);
					handsLate.erase(handsLate.begin() + rng);
				}
				else {
					int rng = rand() % handsNorm.size();
					pickup = handsNorm.at(rng);
					handsNorm.erase(handsNorm.begin() + rng);
				}
			}
			else if (guy.getTier(guy.posx, guy.posy) == 'E') {
				int normrare = rand() % 4;
				if (normrare < 3 || handsNorm.size() == 0) {
					int rng = rand() % handsLate.size();
					pickup = handsLate.at(rng);
					handsLate.erase(handsLate.begin() + rng);
				}
				else {
					int rng = rand() % handsNorm.size();
					pickup = handsNorm.at(rng);
					handsNorm.erase(handsNorm.begin() + rng);
				}
			}
			else if (guy.getTier(guy.posx, guy.posy) == 'F') {
				int rng = rand() % handsLate.size();
				pickup = handsLate.at(rng);
				handsLate.erase(handsLate.begin() + rng);
			}
		}
	}
	else if (RoomType == "Gear Body") {
		if (rare && bodyRare.size() > 0) {
			int rareng = rand() % bodyRare.size();
			pickup = bodyRare.at(rareng);
			bodyRare.erase(bodyRare.begin() + rareng);
		}
		else {
			if (guy.getTier(guy.posx, guy.posy) == 'A') {
				int rng = rand() % bodyNorm.size();
				pickup = bodyNorm.at(rng);
				bodyNorm.erase(bodyNorm.begin() + rng);
			}
			else if (guy.getTier(guy.posx, guy.posy) == 'B') {
				int normrare = rand() % 5;
				if (normrare == 0 || bodyNorm.size() == 0) {
					int rng = rand() % bodyLate.size();
					pickup = bodyLate.at(rng);
					bodyLate.erase(bodyLate.begin() + rng);
				}
				else {
					int rng = rand() % bodyNorm.size();
					pickup = bodyNorm.at(rng);
					bodyNorm.erase(bodyNorm.begin() + rng);
				}
			}
			else if (guy.getTier(guy.posx, guy.posy) == 'C' || guy.getTier(guy.posx, guy.posy) == 'D') {
				int normrare = rand() % 5;
				if (normrare < 2 || bodyNorm.size() == 0) {
					int rng = rand() % bodyLate.size();
					pickup = bodyLate.at(rng);
					bodyLate.erase(bodyLate.begin() + rng);
				}
				else {
					int rng = rand() % bodyNorm.size();
					pickup = bodyNorm.at(rng);
					bodyNorm.erase(bodyNorm.begin() + rng);
				}
			}
			else if (guy.getTier(guy.posx, guy.posy) == 'E') {
				int normrare = rand() % 4;
				if (normrare < 3 || bodyNorm.size() == 0) {
					int rng = rand() % bodyLate.size();
					pickup = bodyLate.at(rng);
					bodyLate.erase(bodyLate.begin() + rng);
				}
				else {
					int rng = rand() % bodyNorm.size();
					pickup = bodyNorm.at(rng);
					bodyNorm.erase(bodyNorm.begin() + rng);
				}
			}
			else if (guy.getTier(guy.posx, guy.posy) == 'F') {
				int rng = rand() % bodyLate.size();
				pickup = bodyLate.at(rng);
				bodyLate.erase(bodyLate.begin() + rng);
			}
		}
	}
	else if (RoomType == "Gear Head") {
		if (rare && headRare.size() > 0) {
			int rareng = rand() % headRare.size();
			pickup = headRare.at(rareng);
			headRare.erase(headRare.begin() + rareng);
		}
		else {
			int rng = rand() % headNorm.size();
			pickup = headNorm.at(rng);
			headNorm.erase(headNorm.begin() + rng);
		}
	}
}

void InputBoard::generateSpecial() {
	if (specialNorm.size() < 3) {
		specialNorm.push_back(Card("Metabolise"));
		specialNorm.push_back(Card("Change Mind"));
		specialNorm.push_back(Card("Intimidate"));
		specialNorm.push_back(Card("Cripple"));
		specialNorm.push_back(Card("Merge"));
		specialNorm.push_back(Card("Entomb"));
		specialNorm.push_back(Card("Grow"));
		specialNorm.push_back(Card("Solidify"));
		specialNorm.push_back(Card("Learn"));
		specialNorm.push_back(Card("Boost"));
		specialNorm.push_back(Card("Vitalise"));
		specialNorm.push_back(Card("Combo"));
		specialNorm.push_back(Card("Slam"));
		
	}

	if (rand() % 12 == 0 && specialRare.size() > 0) {
		int rareng = rand() % specialRare.size();
		specialDecision.push_back(specialRare.at(rareng));
		specialRare.erase(specialRare.begin()+rareng);
	}
	while (specialDecision.size() < 3) {
		int rng = rand() % specialNorm.size();
		specialDecision.push_back(specialNorm.at(rng));
		specialNorm.erase(specialNorm.begin() + rng);
	}
}

void InputBoard::generateTraits() {
	if (AvailableTraitsSacrifice.size() < 3) {
		//traits
		AvailableTraitsSacrifice.push_back(Gear("Anemia"));
		AvailableTraitsSacrifice.push_back(Gear("Dumb"));
		AvailableTraitsSacrifice.push_back(Gear("Mind Flooded"));
		AvailableTraitsSacrifice.push_back(Gear("Tunnel Vision"));
		AvailableTraitsSacrifice.push_back(Gear("Teleportitis"));
		AvailableTraitsSacrifice.push_back(Gear("Growing Pains"));
		AvailableTraitsSacrifice.push_back(Gear("Conversion"));
		AvailableTraitsSacrifice.push_back(Gear("Inversion"));
		AvailableTraitsSacrifice.push_back(Gear("Jittery"));
		AvailableTraitsSacrifice.push_back(Gear("Tumors"));
		//AvailableTraitsSacrifice.push_back(Gear("Devolve")); not yet
		AvailableTraitsSacrifice.push_back(Gear("Volatile"));
		AvailableTraitsSacrifice.push_back(Gear("Melting"));
		AvailableTraitsSacrifice.push_back(Gear("Amnesia"));
		AvailableTraitsSacrifice.push_back(Gear("Oblivious"));
		AvailableTraitsSacrifice.push_back(Gear("Numb"));
		AvailableTraitsSacrifice.push_back(Gear("Blind"));
		AvailableTraitsSacrifice.push_back(Gear("Sensitive"));
		AvailableTraitsSacrifice.push_back(Gear("Frenzy"));
	}
	if (AvailableTraitsReward.size() < 3) {
		AvailableTraitsReward.push_back(Gear("Mending Flesh"));
		AvailableTraitsReward.push_back(Gear("Gymnast"));
		AvailableTraitsReward.push_back(Gear("Third Eye"));
		AvailableTraitsReward.push_back(Gear("Warper"));
		AvailableTraitsReward.push_back(Gear("Growth Spurt"));
		AvailableTraitsReward.push_back(Gear("Mind"));
		AvailableTraitsReward.push_back(Gear("Matter"));
		AvailableTraitsReward.push_back(Gear("Sharp Claws"));
		//AvailableTraitsReward.push_back(Gear("Gift")); not yet
		AvailableTraitsReward.push_back(Gear("Unseen"));
		AvailableTraitsReward.push_back(Gear("Spiny Skin"));
		//AvailableTraitsReward.push_back(Gear("Adapt")); not yet
		AvailableTraitsReward.push_back(Gear("Wings"));
		AvailableTraitsReward.push_back(Gear("Exoskeleton"));
		AvailableTraitsReward.push_back(Gear("Unpredictable"));
		AvailableTraitsReward.push_back(Gear("Ego"));
	}

	if (RoomType == "Cauldron") {
		if (rand() % 100 == 0) {
			TraitsDecision.push_back(Gear("The Box"));
		}
		while (TraitsDecision.size() < 3) {
			int rngt = rand() % AvailableTraitsSacrifice.size();
			TraitsDecision.push_back(AvailableTraitsSacrifice.at(rngt));
			AvailableTraitsSacrifice.erase(AvailableTraitsSacrifice.begin()+rngt);
		}
	}
	else if (RoomType == "Cauldron 2") {
		if (rand() % 100 == 0) {
			TraitsDecision.push_back(Gear("The Juice"));
		}
		while (TraitsDecision.size() < 3) {
			int rngt = rand() % AvailableTraitsReward.size();
			TraitsDecision.push_back(AvailableTraitsReward.at(rngt));
			AvailableTraitsReward.erase(AvailableTraitsReward.begin() + rngt);
		}
	}
}

//get decisions outside of combat
void InputBoard::getchDecision(Character &guy, Deck &deck, TextLog &log) {
	//clearBoard();
	if (guy.CurrentHealth <= 0) {
		//Reconstruction Trait
		if (guy.Reconstruction && guy.Skill > 1) {
			guy.CurrentHealth = guy.MaxHealth;
			guy.ModStat(-2, "Skill");
			string recon = "#g You come back to life!#o";
			log.PushPop(recon);
		}
		else
			guy.Alive = FALSE;
	}
	if (!guy.Alive) {
		return;
	}

	if (RoomType != "Combat" && RoomType != "Final Boss" && RoomType != "Boss") {
		char choose = getch();
		if (choose == 'd') {
			//deck.deckScreen();
			showDeck(guy, deck);
			log.printLog();
			//getchDecision(guy, deck, log);
		}
		else if (choose == 'g') {
			showInventory(guy, deck);
			log.printLog();
		}
		else if (choose == 't') {
			showTraits();
			log.printLog();
		}
		/*else if (choose == 'l') {
			clearBoard();
			log.printAllLog(0, 100);
		}*/
		if (RoomType == "First") {
			if (guy.posx == 25) {
				if (choose == '1') {
					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posy += 1;
				}
				else
					getchDecision(guy, deck, log);
			}
			else if (guy.posy == 7) {
				if (choose == '1') {
					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posx += 1;
				}
				else
					getchDecision(guy, deck, log);
			}
			else {
				if (choose == '1') {
					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posy += 1;
				}
				else if (choose == '2') {
					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posx += 1;
				}
				else
					getchDecision(guy, deck, log);
			}
		}
		else if (RoomType == "Stat") {
			//char choose = getch();
			if (choose == '1') {
				guy.ModStat(1, "Strength");
				string gain = "#g~You gain 1 Strength.#o";
				log.PushPop(gain);
				log.printLog();
				RoomType = "Empty";
			}
			else if (choose == '2') {
				guy.ModStat(1, "Defense");
				string gain = "#g~You gain 1 Defense.#o";
				log.PushPop(gain);
				log.printLog();
				RoomType = "Empty";
			}
			else if (choose == '3') {
				guy.ModStat(1, "Intelligence");
				string gain = "#g~You gain 1 Intelligence.#o";
				log.PushPop(gain);
				log.printLog();
				RoomType = "Empty";
			}
			else
				getchDecision(guy, deck, log);

			//Growth Spurt trait
			if (guy.Growth_Spurt) {
				/*
				20 str
				20 def
				20 int
				1 skl
				5 maxmana
				20 maxhp
				*/
				if (rand() % 8 < 3) {
					int grow = rand() % 86;
					string gain2;
					if (grow < 20) {
						guy.ModStat(1, "Strength");
						gain2 = "#g~You grow +1 Strength.#o";
					}
					else if (grow <= 20 && grow < 40) {
						guy.ModStat(1, "Defense");
						gain2 = "#g~You grow +1 Defense.#o";
					}
					else if (grow <= 40 && grow < 60) {
						guy.ModStat(1, "Intelligence");
						gain2 = "#g~You grow +1 Intelligence.#o";
					}
					else if (grow <= 60 && grow < 80) {
						guy.ModStat(1, "MaxHealth");
						gain2 = "#g~You grow +1 Maximum Health.#o";
						guy.CurrentHealth = guy.MaxHealth;
					}
					else if (grow >= 80 && grow < 85) {
						guy.ModStat(1, "MaxMana");
						gain2 = "#g~You grow +1 Maximum Mana.#o";
						guy.CurrentMana = guy.MaxMana;
					}
					else {
						guy.ModStat(1, "Skill");
						gain2 = "#g~You grow +1 Skill.#o";
					}
					log.PushPop(gain2);
					log.printLog();
				}
				
				//update mind and matter
				//Matter trait
				if (guy.Matter) {
					guy.MaxHealth = guy.MaxHealthBase + (2*guy.Skill);
					guy.CurrentHealth = guy.MaxHealth;
				}
				//Mind trait
				if (guy.Mind) {
					guy.MaxMana = guy.MaxManaBase + guy.Skill;
					guy.CurrentMana = guy.MaxMana;
				}
			}

			guy.printStats();
		}
		else if (RoomType == "Empty") {
			//char choose = getch();
			int space = 1;
			if (guy.posx == 25) {
				if (choose == '1') {
					//Long Legs trait
					if (guy.Long_Legs > 0 && guy.posy < 6) {
						space *= 2;
						guy.Long_Legs--;
					}

					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posy += space;
				}
				else if (guy.Warper > 0 && guy.posy > 0 && choose == '2' && guy.posyBefore != guy.posy-1) {
					//Long Legs trait
					if (guy.Long_Legs > 0 && guy.posy > 1) {
						space *= 2;
						guy.Long_Legs--;
					}

					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posy -= space;
					guy.Warper--;
				}
				else if (choose == '\033') {
					getch();
					switch (getch()) {
					case 'A':
						guy.changePosBefore('y', guy.posy);
						guy.changePosBefore('x', guy.posx);
						guy.posy += space;
						break;
					}
				}
				else
					getchDecision(guy, deck, log);
			}
			else if (guy.posy == 7) {
				if (choose == '1') {
					//Long Legs trait
					if (guy.Long_Legs > 0 && guy.posx < 24) {
						space *= 2;
						guy.Long_Legs--;
					}

					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posx += space;
				}
				else if (guy.Warper > 0 && guy.posy > 0 && choose == '2' && guy.posyBefore != guy.posy - 1) {
					//Long Legs trait
					if (guy.Long_Legs > 0) {
						space *= 2;
						guy.Long_Legs--;
					}

					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posy -= space;
					guy.Warper--;
				}
				else if (choose == '\033') {
					getch();
					switch (getch()) {
					case 'C':
						guy.changePosBefore('y', guy.posy);
						guy.changePosBefore('x', guy.posx);
						guy.posx += space;
						break;
					}
				}
				else
					getchDecision(guy, deck, log);
			}
			else {
				if (choose == '1') {
					//Long Legs trait
					if (guy.Long_Legs > 0 && guy.posy < 6) {
						space *= 2;
						guy.Long_Legs--;
					}

					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posy += space;
				}
				else if (choose == '2') {
					//Long Legs trait
					if (guy.Long_Legs > 0 && guy.posx < 24) {
						space *= 2;
						guy.Long_Legs--;
					}

					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posx += space;
				}
				else if (guy.Warper > 0 && guy.posy > 0 && choose == '3' && guy.posyBefore != guy.posy - 1) {
					//Long Legs trait
					if (guy.Long_Legs > 0 && guy.posy > 1) {
						space *= 2;
						guy.Long_Legs--;
					}

					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posy -= space;
					guy.Warper--;
				}
				else if (choose == '72') {
					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posy += space;
				}
				else if (choose == '77') {
					guy.changePosBefore('y', guy.posy);
					guy.changePosBefore('x', guy.posx);
					guy.posx += space;
				}
				else
					getchDecision(guy, deck, log);
			}
			
		}
		else if (RoomType == "Gear Head" || RoomType == "Gear Body" || RoomType == "Gear Hands") {
			if (inventory.size()<9 && choose == 'p') {
				inventory.push_back(pickup);
				string line = "#b-You pick up the " + string(pickup.GearName)
							+ ".#o";
				log.PushPop(line);
				log.printLog();

				//Scavenger trait
				if (guy.Scavenger != -1) {
					if (guy.Scavenger == 1) {
						if (RoomType == "Gear Head") {
							RoomType = "Gear Head";
						}
						else if (RoomType == "Gear Body") {
							RoomType = "Gear Body";
						}
						else if (RoomType == "Gear Hands") {
							RoomType = "Gear Hands";
						}
						guy.Scavenger = 0;
					}
					else {
						RoomType = "Empty";
						guy.Scavenger++;
					}
				}
				else
					RoomType = "Empty";
				printDecision(guy, log);
				getchDecision(guy, deck, log);
			}
			else if (inventory.size() >= 9 && choose == 'p') {
				string line = "#r*Your inventory is full.#o";
				log.PushPop(line);
				log.printLog();
				RoomType = "Empty";
				printDecision(guy, log);
				getchDecision(guy, deck, log);
			}
			else if (choose == 'i') {
				//Scavenger trait
				if (guy.Scavenger != -1) {
					if (guy.Scavenger == 1) {
						if (RoomType == "Gear Head") {
							RoomType = "Gear Head";
						}
						else if (RoomType == "Gear Body") {
							RoomType = "Gear Body";
						}
						else if (RoomType == "Gear Hands") {
							RoomType = "Gear Hands";
						}
						guy.Scavenger = 0;
					}
					else {
						RoomType = "Empty";
						guy.Scavenger++;
					}
				}
				else
					RoomType = "Empty";
				printDecision(guy, log);
				getchDecision(guy, deck, log);
			}
			else if (choose != 'p' && choose != 'i'){
				getchDecision(guy, deck, log);
			}
		}
		else if (RoomType == "Special") {
			if (choose == '1' || choose == '2' || choose == '3' || choose == '4') {
				string line;
				if (choose == '1') {
					Gear specialPickup(specialDecision.at(0).CardName);
					specialDecision.erase(specialDecision.begin());
					specialPickup.CardOnOrOff(TRUE, guy, deck);
					line = "#g~You add " + string(specialPickup.GearName) + " to your deck.#o";
					log.PushPop(line);
				}
				else if (choose == '2') {
					Gear specialPickup(specialDecision.at(1).CardName);
					specialDecision.erase(specialDecision.begin()+1);
					specialPickup.CardOnOrOff(TRUE, guy, deck);
					line = "#g~You add " + string(specialPickup.GearName) + " to your deck.#o";
					log.PushPop(line);
				}
				else if (choose == '3') {
					Gear specialPickup(specialDecision.at(2).CardName);
					specialDecision.erase(specialDecision.begin()+2);
					specialPickup.CardOnOrOff(TRUE, guy, deck);
					line = "#g~You add " + string(specialPickup.GearName) + " to your deck.#o";
					log.PushPop(line);
				}
				else if (choose == '4') {

				}
				while (specialDecision.size() > 0) {
					specialDecision.pop_back();
				}
				log.printLog();
				for (int i = 0; i < 8; i++)
					mvprintw(6 + i, 29, "             ");
				mvprintw(17, 62, "         ");
				guy.printStats();
				RoomType = "Empty";
				printDecision(guy, log);
				//getchDecision(guy, deck, log);
			}
			else {
				getchDecision(guy, deck, log);
			}
		}
		else if (RoomType == "Spell") {
			if (choose == '1' || choose == '2' || choose == '3' || choose == '4') {
				string line;
				if (choose == '1') {
					deck.addCard(spellDecision.at(0));
					line = "#m~You add " + string(spellDecision.at(0).CardName) + " to your deck.#o";
					log.PushPop(line);
				}
				else if (choose == '2') {
					deck.addCard(spellDecision.at(1));
					line = "#m~You add " + string(spellDecision.at(0).CardName) + " to your deck.#o";
					log.PushPop(line);
				}
				else if (choose == '3') {
					deck.addCard(spellDecision.at(2));
					line = "#m~You add " + string(spellDecision.at(0).CardName) + " to your deck.#o";
					log.PushPop(line);
				}
				else if (choose == '4') {

				}
				while (spellDecision.size() > 0) {
					AvailableSpells.push_back(spellDecision.back());
					spellDecision.pop_back();
				}
				log.printLog();
				for (int i = 0; i < 8; i++)
					mvprintw(6 + i, 29, "             ");
				mvprintw(17, 62, "         ");
				guy.printStats();
				RoomType = "Empty";
				printDecision(guy, log);
				//getchDecision(guy, deck, log);
			}
			else {
				getchDecision(guy, deck, log);
			}
		}
		else if (RoomType == "Cauldron" || RoomType == "Cauldron 2") {
			if (choose == '1' || choose == '2' || choose == '3') {
				//Succumb trait
				if (guy.Succumb) {
					int ch = (rand() % 3) + 1;
					switch (ch) {
					case 1:
						choose = '1';
						break;
					case 2:
						choose = '2';
						break;
					case 3:
						choose = '3';
						break;
					}
				}
				string line;
				if (choose == '1') {
					TraitsDecision.at(0).TraitOnOrOff(TRUE, guy, deck);
					if(TraitsDecision.at(0).Type == "Trait Sacrifice")
						line = "#r~You recieve " + string(TraitsDecision.at(0).GearName) + ".#o";
					else if (TraitsDecision.at(0).Type == "Trait Reward")
						line = "#g~You recieve " + string(TraitsDecision.at(0).GearName) + ".#o";
					AddRemoveTrait(1, TraitsDecision.at(0).GearName);
					TraitsDecision.erase(TraitsDecision.begin());
				}
				else if (choose == '2') {
					TraitsDecision.at(1).TraitOnOrOff(TRUE, guy, deck);
					if (TraitsDecision.at(1).Type == "Trait Sacrifice")
						line = "#r~You recieve " + string(TraitsDecision.at(1).GearName) + ".#o";
					else if (TraitsDecision.at(1).Type == "Trait Reward")
						line = "#g~You recieve " + string(TraitsDecision.at(1).GearName) + ".#o";
					AddRemoveTrait(1, TraitsDecision.at(1).GearName);
					TraitsDecision.erase(TraitsDecision.begin()+1);
				}
				else if (choose == '3') {
					TraitsDecision.at(2).TraitOnOrOff(TRUE, guy, deck);
					if (TraitsDecision.at(2).Type == "Trait Sacrifice")
						line = "#r~You recieve " + string(TraitsDecision.at(2).GearName) + ".#o";
					else if (TraitsDecision.at(2).Type == "Trait Reward")
						line = "#g~You recieve " + string(TraitsDecision.at(2).GearName) + ".#o";
					AddRemoveTrait(1, TraitsDecision.at(2).GearName);
					TraitsDecision.erase(TraitsDecision.begin() + 2);
				}
				log.PushPop(line);
				log.printLog();
				while (TraitsDecision.size() > 0) {
					if (RoomType == "Cauldron") {
						AvailableTraitsSacrifice.push_back(TraitsDecision.back());
						TraitsDecision.pop_back();
					}
					else if (RoomType == "Cauldron 2") {
						AvailableTraitsReward.push_back(TraitsDecision.back());
						TraitsDecision.pop_back();
					}
				}
				if (RoomType == "Cauldron") {
					if (guy.Oblivious)
						log.Oblivious = TRUE;
					log.printLog();
					RoomType = "Cauldron 2";
					printDecision(guy, log);
					getchDecision(guy, deck, log);
				}
				else if (RoomType == "Cauldron 2") {
					for (int i = 0; i < 8; i++)
						mvprintw(6 + i, 29, "             ");

					//update Mind and Matter
					//Matter trait
					if (guy.Matter) {
						guy.MaxHealth = guy.MaxHealthBase + (2*guy.Skill);
						guy.CurrentHealth = guy.MaxHealth;
					}
					//Mind trait
					if (guy.Mind) {
						guy.MaxMana = guy.MaxManaBase + guy.Skill;
						guy.CurrentMana = guy.MaxMana;
					}

					//Third Eye trait
					if (guy.Third_Eye)
						Third_Eye = TRUE;

					guy.printStats();
					manualBox("Display", 0);

					//Ego trait
					if (guy.Ego) {
						RoomType = "Special";
						guy.Ego = FALSE;
						printDecision(guy, log);
						getchDecision(guy, deck, log);
					}

					//Genius trait
					if (guy.Genius) {
						RoomType = "Spell";
						guy.Genius = FALSE;
						printDecision(guy, log);
						getchDecision(guy, deck, log);
					}

					//Destiny trait
					if (guy.Destiny > 1) {
						RoomType = "Cauldron";
						guy.Destiny--;
						//printDecision(guy, log);
						//getchDecision(guy, deck, log);
					}
					else
						RoomType = "Empty";
					printDecision(guy, log);
					getchDecision(guy, deck, log);
				}
			}
			else {
				getchDecision(guy, deck, log);
			}
		}
	}
	else if (RoomType == "Combat"){
		startBattle(guy, deck, log);
	}
	else if (RoomType == "Boss") {
		startBattle(guy, deck, log);
	}
	else if (RoomType == "Final Boss") {
		startBattle(guy, deck, log);
	}
	
}

//adds any negative cards based of the character's negative variable
void InputBoard::addNegative(Character &guy, Deck &deck) {
	if (guy.negative == "") {
		return;
	}
	else {
		Card steam("Steam");
		Card steam2("Scalding Steam");
		Card webbed("Webbed");
		Card tired("Tired");
		Card dstr("Drain Str");
		Card ddef("Drain Def");
		Card dint("Drain Int");
		Card patch("Patch");

		if (guy.negative == "Steam") {
			Draw.push_back(steam);
		}
		else if (guy.negative == "Scalding Steam") {
			Discard.push_back(steam2);
		}
		else if (guy.negative == "Webbed") {
			Draw.push_back(webbed);
		}
		else if (guy.negative == "Tired") {
			Draw.push_back(tired);
		}
		else if (guy.negative == "Drain Str") {
			Draw.push_back(dstr);
		}
		else if (guy.negative == "Drain Def") {
			Draw.push_back(ddef);
		}
		else if (guy.negative == "Drain Int") {
			Draw.push_back(dint);
		}
		else if (guy.negative == "Patch") {
			Draw.push_back(patch);
		}
	}
	guy.negative = "";
}

//removes any negative cards after battle
bool InputBoard::removeNegatives(Deck &deck) {
	bool removed = FALSE;
	for (int i = 0; i < deck.size(); i++) {
		if (deck.at(i).CardType == "Negative" && deck.at(i).CardName != "Mad") {
			deck.cardDeck.erase(deck.cardDeck.begin() + i);
			i--;
			removed = TRUE;
		}
		//also using this function to reset the Pummel card
		else if (deck.at(i).CardName == "Pummel") {
			deck.cardDeck.at(i).pummel = 2;
		}
	}
	return removed;
}

//any modifiers that were put on the character in battle are reverted
void InputBoard::restoreStats(Character &guy) {
	//Purple trait
	if (guy.Purple)
		return;

	guy.ModStat(guy.strMod, "Strength");
	guy.ModStat(guy.defMod, "Defense");
	guy.ModStat(guy.intMod, "Intelligence");
	guy.ModStat(guy.hpMod, "MaxHealth");
	guy.ModStat(guy.mpMod, "MaxMana");
	guy.ModStat(guy.sklMod, "Skill");

	guy.strMod = 0;
	guy.defMod = 0;
	guy.intMod = 0;
	guy.hpMod = 0;
	guy.mpMod = 0;
	guy.sklMod = 0;
}

//add or remove to the list of traits
void InputBoard::AddRemoveTrait(int pm, const char *Name){
	if (pm > 0) {
		Gear argear(Name);
		Traits.push_back(argear);
	}
	else if (pm < 0 && Traits.size() > 0) {
		for (int i = 0; i < Traits.size(); i++) {
			if (Traits.at(i).GearName == Name) {
				Traits.erase(Traits.begin() + i);
				break;
			}
		}
	}
}

//fills hand with a certain type of card based off the player's fillType variable
//idk how i want this to work yet
void InputBoard::fillHand(Character &guy) {
	if (!Tail) {
		if (guy.fillType != " ") {
			while (DecisionCards.size() > 0) {
				Discard.push_back(DecisionCards.back());
				DecisionCards.pop_back();
			}
			while (Draw.size() > 0) {
				Discard.push_back(Draw.back());
				Draw.pop_back();
			}
			int counter = 0;
			for (int i = 0; i < Discard.size(); i++) {
				if (counter < handSize && Discard.at(i).CardType == guy.fillType) {
					DecisionCards.push_back(Discard.at(i));
					Discard.erase(Discard.begin() + i);
					counter++;
					i--;
				}
			}
			ShuffleAddPrint();
			/*while (DecisionCards.size() < 3) {
				if (Discard.size() == 0)
					ShuffleAddPrint();
				else {
					DecisionCards.push_back(Discard.front());
					Discard.erase(Discard.begin());
				}
			}*/
		}
	}
	guy.fillType = " ";
}

//used for reshuffling the deck after every combat
void InputBoard::updateDeck(Deck &deck) {
	while (Draw.size() > 0)
		Draw.pop_back();
	while (Discard.size() > 0)
		Discard.pop_back();
	while (DecisionCards.size() > 0)
		DecisionCards.pop_back();

	for (int i = 0; i < deck.size(); i++) {
		if(!deck.at(i).Void)
			Discard.push_back(deck.at(i));
	}
}

//shuffles the player's hand
void InputBoard::shuffleHand() {
	//Tail trait
	if (!Tail) {
		//put everything in the discard pile
		while (DecisionCards.size() > 0) {
			Discard.push_back(DecisionCards.back());
			DecisionCards.pop_back();
		}
		while (Draw.size() > 0) {
			Discard.push_back(Draw.back());
			Draw.pop_back();
		}
		ShuffleAddPrint();
	}
}

bool InputBoard::Negotiate(Character &guy, Enemy &enemy, Deck &deck, TextLog &log) {
	if (negotiateStep < 0) {
		return FALSE;
	}

	clearBoardWhole();
	bool leave = TRUE;

	manualBox("Card 1", 0);
	manualBox("Card 2", 0);
	manualBox("Card 3", 0);

	if (negotiateStep == 0) {
		mvprintInSize(18, 25, 0, "1) \"Hey\"", FALSE);
		mvprintInSize(19, 25, 0, "2) Nevermind", FALSE);
	}
	else if (negotiateStep == 1) {
		mvprintInSize(18, 25, 10, "1) I don't want to fight", FALSE);
		mvprintInSize(20, 25, 0, "2) Nevermind", FALSE);
	}
	else if (negotiateStep == 2) {
		mvprintInSize(18, 25, 0, "1) Ok", FALSE);
		mvprintInSize(19, 25, 0, "2) Nevermind", FALSE);
	}
	log.printLog();

	char choose = getch();
	if (choose == 'd') {
		deck.deckScreen();

		int c = 0;
		escapeLoop(c);

		log.printLog();
	}
	else if (choose == 't') {
		showTraits();
		log.printLog();
	}
	else if (choose == '2') {
		string line = " You: Nevermind";
		negotiateStep = -2;
		guy.extraTurns++;
		log.PushPop(line);
		return FALSE;
	}
	else if (choose == '1') {
		string line;
		
		if (negotiateStep == 0) {
			line = " You: " + enemy.you1 + " ";
			log.PushPop(line);
			line = " " + string(enemy.Name) + ": " + enemy.negotiate1 + " ";
			log.PushPop(line);
			negotiateStep++;
		}
		else if (negotiateStep == 1) {
			line = " You: " + enemy.you2 + " ";
			log.PushPop(line);
			line = " " + string(enemy.Name) + ": " + enemy.negotiate2 + " ";
			log.PushPop(line);
			negotiateStep++;
		}
		else if (negotiateStep == 2) {
			if (!NegotiateGive(guy, enemy, deck, log)) {
				leave = FALSE;
				return false;
			}
			else
				return leave;
		}
		log.printLog();
	}
	else {
		
	}
	if(negotiateStep > -1 && negotiateStep < 3)
		Negotiate(guy, enemy, deck, log);

	return leave;
}

bool InputBoard::NegotiateGive(Character &guy, Enemy &enemy, Deck &deck, TextLog &log) {
	bool given = TRUE;
	/*
	1 Gear
	2 Gear
	3 Gear

	4 MaxHealth
	6 MaxHealth
	8 MaxHealth

	3 MaxMana
	5 MaxMana

	2 Strength
	8 Strength

	3 Defense
	5 Defense

	3 Intelligence
	7 Intelligence

	1 Skill
	2 Skill
	3 Skill

	1 Special
	5 Special

	Merchant (2 Gear, 1 Skill)
	Jester
	*/
	string price = enemy.price;
	string line;
	if (price == "1 Gear") {
		if (inventory.size() < 1) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int rngear = rand() % inventory.size();
			string g1 = inventory.at(rngear).GearName;
			if (g1 == "No Weapon" || g1 == "No Armor" || g1 == "No Headgear")
				g1 = g1 + " (sucker)";
			inventory.erase(inventory.begin() + rngear);

			line = "#g You give the " + string(enemy.Name) + " your #b" + string(g1) + "#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "2 Gear") {
		if (inventory.size() < 2) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int rngear = rand() % inventory.size();
			string g1 = inventory.at(rngear).GearName;
			if (g1 == "No Weapon" || g1 == "No Armor" || g1 == "No Headgear")
				g1 = g1 + " (sucker)";
			inventory.erase(inventory.begin() + rngear);

			rngear = rand() % inventory.size();
			string g2 = inventory.at(rngear).GearName;
			if (g2 == "No Weapon" || g2 == "No Armor" || g2 == "No Headgear")
				g2 = g2 + " (sucker)";
			inventory.erase(inventory.begin() + rngear);

			line = "#g You give the " + string(enemy.Name) + " your #b" + string(g1) + "#g and #b" + string(g2) + "#g. #o";
			log.PushPop(line);
		}
	}
	else if (price == "3 Gear") {
		if (inventory.size() < 3) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int rngear = rand() % inventory.size();
			string g1 = inventory.at(rngear).GearName;
			if (g1 == "No Weapon" || g1 == "No Armor" || g1 == "No Headgear")
				g1 = g1 + " (sucker)";
			inventory.erase(inventory.begin() + rngear);

			rngear = rand() % inventory.size();
			string g2 = inventory.at(rngear).GearName;
			if (g2 == "No Weapon" || g2 == "No Armor" || g2 == "No Headgear")
				g2 = g2 + " (sucker)";
			inventory.erase(inventory.begin() + rngear);

			rngear = rand() % inventory.size();
			string g3 = inventory.at(rngear).GearName;
			if (g3 == "No Weapon" || g3 == "No Armor" || g3 == "No Headgear")
				g3 = g3 + " (sucker)";
			inventory.erase(inventory.begin() + rngear);

			line = "#g You give the " + string(enemy.Name) + " your #b" + string(g1) + "#g, #b" + string(g2) + "#g, and #b" + string(g3) + "#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "3 MaxHealth") {
		line = " You: " + enemy.you3;
		log.PushPop(line);

		int maxhp = 3;
		guy.ModStat(-1*maxhp, "MaxHealth");

		line = "#g You give the " + string(enemy.Name) + " #r" + to_string(maxhp) + " of your Max Health#g.#o";
		log.PushPop(line);
	}
	else if (price == "6 MaxHealth") {
		line = " You: " + enemy.you3;
		log.PushPop(line);

		int maxhp = 6;
		guy.ModStat(-1 * maxhp, "MaxHealth");

		line = "#g You give the " + string(enemy.Name) + " #r" + to_string(maxhp) + " of your Max Health#g.#o";
		log.PushPop(line);
	}
	else if (price == "8 MaxHealth") {
		line = " You: " + enemy.you3;
		log.PushPop(line);

		int maxhp = 8;
		guy.ModStat(-1 * maxhp, "MaxHealth");

		line = "#g You give the " + string(enemy.Name) + " #r" + to_string(maxhp) + " of your Max Health#g.#o";
		log.PushPop(line);
	}
	else if (price == "3 MaxMana") {
		if (guy.MaxMana < 3) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int maxmana = 3;
			guy.ModStat(-1 * maxmana, "MaxMana");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(maxmana) + " of your Max Mana#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "5 MaxMana") {
		if (guy.MaxMana < 5) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int maxmana = 5;
			guy.ModStat(-1 * maxmana, "MaxMana");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(maxmana) + " of your Max Mana#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "2 Strength") {
		if (guy.Strength < 2) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int str = 2;
			guy.ModStat(-1 * str, "Strength");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(str) + " of your Strength#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "8 Strength") {
		if (guy.Strength < 8) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int str = 8;
			guy.ModStat(-1 * str, "Strength");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(str) + " of your Strength#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "3 Defense") {
		if (guy.Defense < 3) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int def = 3;
			guy.ModStat(-1 * def, "Defense");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(def) + " of your Defense#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "5 Defense") {
		if (guy.Defense < 5) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int def = 5;
			guy.ModStat(-1 * def, "Defense");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(def) + " of your Defense#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "3 Intelligence") {
		if (guy.Intelligence < 3) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int intt = 3;
			guy.ModStat(-1 * intt, "Intelligence");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(intt) + " of your Intelligence#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "7 Intelligence") {
		if (guy.Intelligence < 7) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int intt = 7;
			guy.ModStat(-1 * intt, "Intelligence");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(intt) + " of your Intelligence#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "1 Skill") {
		if (guy.Skill < 1) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int skl = 1;
			guy.ModStat(-1 * skl, "Skill");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(skl) + " of your Skill#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "2 Skill") {
		if (guy.Skill < 2) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int skl = 2;
			guy.ModStat(-1 * skl, "Skill");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(skl) + " of your Skill#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "3 Skill") {
		if (guy.Skill < 3) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int skl = 3;
			guy.ModStat(-1 * skl, "Skill");

			line = "#g You give the " + string(enemy.Name) + " #r" + to_string(skl) + " of your Skill#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "1 Special") {
		int sp = 0;
		for (int i = 0; i < deck.size(); i++) {
			if (deck.at(i).CardType == "Special")
				sp++;
		}
		if (sp < 1) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			line = " You: " + enemy.you3;
			log.PushPop(line);

			string sp1;
			for (int i = 0; i < deck.size(); i++) {
				if (deck.at(i).CardType == "Special") {
					sp1 = deck.at(i).CardName;
					deck.removeCard(deck.at(i), guy);
					break;
				}
			}
			line = "#g You give the " + string(enemy.Name) + " your #o" + string(sp1) + "#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "5 Special") {
		int sp = 0;
		for (int i = 0; i < deck.size(); i++) {
			if (deck.at(i).CardType == "Special")
				sp++;
		}
		if (sp < 5) {
			log.PushPop(" #rYou don't have enough.#o");

			string bossline;
			if (enemy.Name == "Dragon") {
				bossline = " Dragon: That is not enough.";
			}
			else if (enemy.Name == "King") {
				bossline = " King: *flicks wrist*";
			}
			else if (enemy.Name == "Witch") {
				bossline = " Witch: Oho, you think you can trick me?";
			}
			else if (enemy.Name == "Demon") {
				bossline = " Demon: Fool.";
			}
			else if (enemy.Name == "Machine") {
				bossline = " Machine: REQUEST DENIED.";
			}
			log.PushPop(bossline);

			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			string sp1;
			string sp2;
			string sp3;
			string sp4;
			string sp5;
			int sptaken = 5;
			for (int i = 0; i < deck.size(); i++) {
				if (deck.at(i).CardType == "Special") {
					switch (sptaken) {
					case 5:
						sp1 = deck.at(i).CardName;
						break;
					case 4:
						sp2 = deck.at(i).CardName;
						break;
					case 3:
						sp3 = deck.at(i).CardName;
						break;
					case 2:
						sp4 = deck.at(i).CardName;
						break;
					case 1:
						sp5 = deck.at(i).CardName;
						break;
					}
					deck.removeCard(deck.at(i), guy);
					sptaken--;
					i--;
					if(sptaken <= 0)
						break;
				}
			}
			line = "#g You give the " + string(enemy.Name) + " your #o"
				+ string(sp1) + "#g, #o"
				+ string(sp2) + "#g, #o"
				+ string(sp3) + "#g, #o"
				+ string(sp4) + "#g, and #o"
				+ string(sp5) + "#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "Merchant") {
		if (inventory.size() < 2 || guy.Skill < 1) {
			log.PushPop(" #rYou don't have enough.#o");
			negotiateStep = -2;
			given = FALSE;
			return false;
		}
		else {
			line = " You: " + enemy.you3;
			log.PushPop(line);

			int skl = 1;
			guy.ModStat(-1 * skl, "Skill");

			int rngear = rand() % inventory.size();
			string g1 = inventory.at(rngear).GearName;
			if (g1 == "No Weapon" || g1 == "No Armor" || g1 == "No Headgear")
				g1 = g1 + " (sucker)";
			inventory.erase(inventory.begin() + rngear);

			rngear = rand() % inventory.size();
			string g2 = inventory.at(rngear).GearName;
			if (g2 == "No Weapon" || g2 == "No Armor" || g2 == "No Headgear")
				g2 = g2 + " (sucker)";
			inventory.erase(inventory.begin() + rngear);

			line = "#g You give the " + string(enemy.Name) + " your #b" + string(g1) + " #g, #b" + string(g2) + "#g.#o";
			log.PushPop(line);
		}
	}
	else if (price == "Jester") {
		line = " You: " + enemy.you3;
		log.PushPop(line);

		Gear("The Box").SacrificeOnOrOff(TRUE, guy, deck);
		line = "#g-The Jester #cmesses #mwith #byour #rstats#g.#o";
		log.PushPop(line);
	}

	log.printLog();
	return given;
}