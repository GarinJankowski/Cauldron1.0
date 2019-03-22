#include "pch.h"
#include "Character.h"

int rtd(int multiplier, int power);
void mvprintInSize(int starty, int startx, int maxx, const char* toBePrinted, bool Fuzzy);
void manualBox(string typebox, int colorpair);

Character::Character()
{
	//default stats
	Alive = TRUE;
	Win = FALSE;
	winBattle = FALSE;
	tier = 'A';
	MaxHealth = MaxHealthBase;
	CurrentHealth = MaxHealth;
	MaxMana = 10;
	CurrentMana = MaxMana;
	Strength = 5;
	Defense = 3;
	Intelligence = 4;
	Skill = 0;
	CurrentBlock = 0;
	Negate = 0;
	Gold = 0;
	Energy = 0;
	MaxEnergy = 10;

	extraTurns = 0;
	pierce = FALSE;
	shuffle = FALSE;
	fillType = " ";
	cannotUse = FALSE;
	
	strMod = 0;
	defMod = 0;
	intMod = 0;
	hpMod = 0;
	mpMod = 0;
	sklMod = 0;

	Burn = 0;
	Stay = 0;
	Flow = 0;
	Copy = 0;
	Push = 0;
	Void = 0;
	Link = 0;

	posx = 0;
	posy = 0;
	posxBefore = 0;
	posyBefore = 0;

	negative = "";

	//doesn't matter anymore
	RoomUp = FALSE;
	RoomRight = FALSE;
}

Character::~Character()
{
}

//print stuff for screen
//print directory
void Character::printDirectory() {
	mvprintw(1, 1, "(d)eck");
	mvprintw(2, 1, "(g)ear");
	mvprintw(3, 1, "(t)raits");
	mvprintw(1, 9, "(m)ods");
	mvprintw(2, 9, "(l)and");
}
//print stats
void Character::printStats() {
	bool fuzzy = FALSE;
	if (Numb)
		fuzzy = TRUE;

	string statline = "HP: " + to_string(CurrentHealth) + "/" + to_string(MaxHealth) + "  ";
	mvprintInSize(1, 18, 0, statline.c_str(), fuzzy);

	statline = "MP: " + to_string(CurrentMana) + "/" + to_string(MaxMana) + "  ";
	mvprintInSize(1, 31, 0, statline.c_str(), fuzzy);

	statline = "Str: " + to_string(Strength) + "  ";
	mvprintInSize(2, 18, 0, statline.c_str(), fuzzy);

	statline = "Def: " + to_string(Defense) + "  ";
	mvprintInSize(3, 18, 0, statline.c_str(), fuzzy);

	statline = "Int: " + to_string(Intelligence) + "  ";
	//mvprintInSize(2, 31, 0, statline.c_str(), fuzzy);
	mvprintInSize(2, 27, 0, statline.c_str(), fuzzy);

	statline = "Skl: " + to_string(Skill) + "  ";
	//mvprintInSize(3, 31, 0, statline.c_str(), fuzzy);
	mvprintInSize(3, 27, 0, statline.c_str(), fuzzy);

	/*statline = "Energy: #g" + to_string(Energy) + "/10#o";
	mvprintInSize(4, 18, 0, statline.c_str(), fuzzy);*/

	statline = "#$" + to_string(Gold) + "g  #o";
	mvprintInSize(3, 36, 0, statline.c_str(), fuzzy);

	manualBox("Stats", 0);
}

//get tier of room of character
char Character::getTier(int posx, int posy) {
	char tier = ' ';
	if (posy == 0) {
		if (posx > 0 && posx < 7)
			tier = 'A';
		else if (posx >= 7 && posx < 12)
			tier = 'B';
		else if (posx >= 12 && posx < 16)
			tier = 'C';
		else if (posx >= 16 && posx < 21)
			tier = 'D';
		else
			tier = 'E';
	}
	else if (posy == 1) {
		if (posx < 6)
			tier = 'A';
		else if (posx >= 6 && posx < 11)
			tier = 'B';
		else if (posx >= 11 && posx < 15)
			tier = 'C';
		else if (posx >= 15 && posx < 20)
			tier = 'D';
		else if (posx >= 20 && posx < 25)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 2) {
		if (posx < 5)
			tier = 'A';
		else if (posx >= 5 && posx < 10)
			tier = 'B';
		else if (posx >= 10 && posx < 14)
			tier = 'C';
		else if (posx >= 14 && posx < 19)
			tier = 'D';
		else if (posx >= 19 && posx < 24)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 3) {
		if (posx < 4)
			tier = 'A';
		else if (posx >= 4 && posx < 9)
			tier = 'B';
		else if (posx >= 9 && posx < 13)
			tier = 'C';
		else if (posx >= 13 && posx < 18)
			tier = 'D';
		else if (posx >= 18 && posx < 23)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 4) {
		if (posx < 3)
			tier = 'A';
		else if (posx >= 3 && posx < 8)
			tier = 'B';
		else if (posx >= 8 && posx < 12)
			tier = 'C';
		else if (posx >= 12 && posx < 17)
			tier = 'D';
		else if (posx >= 17 && posx < 22)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 5) {
		if (posx < 2)
			tier = 'A';
		else if (posx >= 2 && posx < 7)
			tier = 'B';
		else if (posx >= 7 && posx < 11)
			tier = 'C';
		else if (posx >= 11 && posx < 16)
			tier = 'D';
		else if (posx >= 16 && posx < 21)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 6) {
		if (posx < 1)
			tier = 'A';
		else if (posx >= 1 && posx < 6)
			tier = 'B';
		else if (posx >= 6 && posx < 10)
			tier = 'C';
		else if (posx >= 10 && posx < 15)
			tier = 'D';
		else if (posx >= 15 && posx < 20)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 7) {
		if (posx < 5)
			tier = 'B';
		else if (posx >= 5 && posx < 9)
			tier = 'C';
		else if (posx >= 9 && posx < 14)
			tier = 'D';
		else if (posx >= 14 && posx < 19)
			tier = 'E';
		else
			tier = 'F';
	}
	return tier;
}

char Character::getTier() {
	char tier = ' ';
	if (posy == 0) {
		if (posx > 0 && posx < 7)
			tier = 'A';
		else if (posx >= 7 && posx < 12)
			tier = 'B';
		else if (posx >= 12 && posx < 16)
			tier = 'C';
		else if (posx >= 16 && posx < 21)
			tier = 'D';
		else
			tier = 'E';
	}
	else if (posy == 1) {
		if (posx < 6)
			tier = 'A';
		else if (posx >= 6 && posx < 11)
			tier = 'B';
		else if (posx >= 11 && posx < 15)
			tier = 'C';
		else if (posx >= 15 && posx < 20)
			tier = 'D';
		else if (posx >= 20 && posx < 25)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 2) {
		if (posx < 5)
			tier = 'A';
		else if (posx >= 5 && posx < 10)
			tier = 'B';
		else if (posx >= 10 && posx < 14)
			tier = 'C';
		else if (posx >= 14 && posx < 19)
			tier = 'D';
		else if (posx >= 19 && posx < 24)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 3) {
		if (posx < 4)
			tier = 'A';
		else if (posx >= 4 && posx < 9)
			tier = 'B';
		else if (posx >= 9 && posx < 13)
			tier = 'C';
		else if (posx >= 13 && posx < 18)
			tier = 'D';
		else if (posx >= 18 && posx < 23)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 4) {
		if (posx < 3)
			tier = 'A';
		else if (posx >= 3 && posx < 8)
			tier = 'B';
		else if (posx >= 8 && posx < 12)
			tier = 'C';
		else if (posx >= 12 && posx < 17)
			tier = 'D';
		else if (posx >= 17 && posx < 22)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 5) {
		if (posx < 2)
			tier = 'A';
		else if (posx >= 2 && posx < 7)
			tier = 'B';
		else if (posx >= 7 && posx < 11)
			tier = 'C';
		else if (posx >= 11 && posx < 16)
			tier = 'D';
		else if (posx >= 16 && posx < 21)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 6) {
		if (posx < 1)
			tier = 'A';
		else if (posx >= 1 && posx < 6)
			tier = 'B';
		else if (posx >= 6 && posx < 10)
			tier = 'C';
		else if (posx >= 10 && posx < 15)
			tier = 'D';
		else if (posx >= 15 && posx < 20)
			tier = 'E';
		else
			tier = 'F';
	}
	else if (posy == 7) {
		if (posx < 5)
			tier = 'B';
		else if (posx >= 5 && posx < 9)
			tier = 'C';
		else if (posx >= 9 && posx < 14)
			tier = 'D';
		else if (posx >= 14 && posx < 19)
			tier = 'E';
		else
			tier = 'F';
	}
	return tier;
}

//show inventory
void Character::showInventoryScreen() {

}

//check if stats are above their maximums
void Character::checkMax() {
	//Engorged trait
	if (CurrentHealth > MaxHealth && !Engorged)
		CurrentHealth = MaxHealth;
	//Enlightened trait
	if (CurrentMana > MaxMana && !Enlightened)
		CurrentMana = MaxMana;

	/*if (Strength < 0)
		Strength = 0;
	if (Defense < 0)
		Defense = 0;
	if (Intelligence < 0)
		Intelligence = 0;
	if (Skill < 0)
		Skill = 0;*/
	if (MaxHealth < 0)
		MaxHealth = 0;
	if (MaxMana < 0)
		MaxMana = 0;
}

//take/heal damage
int Character::TakeDamage(int damageTaken) {
	int healthBefore = CurrentHealth;
	//Stop card
	if (stop > 0 && damageTaken > 0) {
		damageTaken = 0;
	}
	//Hemoglobin trait
	if (Hemoglobin && damageTaken < 0) {
		damageTaken = int(damageTaken*1.5);
	}
	//Undead trait
	if (damageTaken < 0 && Undead) {
		damageTaken = 0;
	}
	//Frenzy trait
	if (damageTaken > 0 && Frenzy) {
		damageTaken *= 2;
	}
	//entomb
	if (entomb > 0 && damageTaken > 0) {
		damageTaken = 0;
	}
	//Tumors trait
	if (Tumors && damageTaken < 0) {
		ModStat(-1, "MaxHealth", TRUE);
		if (CurrentHealth > MaxHealth)
			CurrentHealth = MaxHealth;
		hpMod++;
	}
	//healing
	if (damageTaken < 0) {
		if (materialize > 0) {
			materialize--;
			materializeblock = -damageTaken;
			materializeTRUE = TRUE;
		}

		CurrentHealth -= damageTaken;
		checkMax();

		return damageTaken;
	}
	//intimidate
	if (damageTaken >= 0 && intimidate > 0) {
		damageTaken = int(damageTaken / 2);
	}
	//Green Scales trait
	if (Green_Scales && damageTaken > 0) {
		damageTaken -= int(Skill/2);
		if (damageTaken < 0)
			damageTaken = 0;
	}
	//Thick Hide trait
	if (Thick_Hide && CurrentBlock > 0) {
		damageTaken = int(damageTaken*.85);
	}
	//Blue Scales trait
	if (Blue_Scales && damageTaken <= 5) {
		damageTaken = 0;
	}
	//Red Scales trait
	if (Red_Scales && damageTaken >= 25) {
		damageTaken = 0;
	}
	if (Negate > 0 && damageTaken > 0) {
		//Deflect card
		if (deflect > 0) {
			deflectdamage = damageTaken;
			deflectTRUE = TRUE;
			deflect--;
		}
		else {
			damageTaken = 0;
		}
		//Horns trait
		if (Horns != -1) {
			Horns++;
		}
		Negate--;
	}

	//Gold Bones trait
	if (Gold_Bones && damageTaken > CurrentBlock && Negate == 0) {
		int goldblock = damageTaken - CurrentBlock;
		if (goldblock > Gold) {
			damageTaken -= Gold;
			Gold = 0;
		 }
		else {
			damageTaken -= goldblock;
			Gold -= goldblock;
		}
	}

	//Panic Attack trait
	if (Panic_Attack != -1 && damageTaken >= 20) {
		Panic_Attack = 1;
	}
	//Falter trait
	if (Falter != -1) {
		Falter += damageTaken;
	}
	//Exposed trait
	if (Exposed != -1) {
		int ex = damageTaken - CurrentBlock;
		if (ex < 0)
			ex = 0;
		Exposed += ex;
	}
	//Amass trait
	if (Amass != -1 && !pierce) {
		int am;
		if (damageTaken > CurrentBlock)
			am = CurrentBlock;
		else
			am = damageTaken;
		Amass += am;
	}

	//pierce
	if (pierce) {
		CurrentHealth -= damageTaken;
		pierce = FALSE;
	}
	else {
		if ((CurrentHealth - damageTaken) > MaxHealth)
			CurrentHealth = MaxHealth;
		else {
			if (damageTaken >= CurrentBlock) {
				int damage = damageTaken - CurrentBlock;
				CurrentHealth -= damage;
				CurrentBlock = 0;
			}
			else {
				CurrentBlock -= damageTaken;
			}
		}
	}
	if (mirror > 0 && damageTaken > 0) {
		mirrorDamage = damageTaken;
	}
	if (charge > 0 && damageTaken > 0) {
		chargeMana = damageTaken;
	}

	//Spiny Skin trait
	if (Spiny_Skin) {
		SpinyDamage = Skill + 3;
	}
	else {
		SpinyDamage = 0;
	}
	if (Iron_Scabs && CurrentHealth < healthBefore) {
		int block = int((healthBefore - CurrentHealth) / 2);
		block = gainBlock(block);
	}
	if (Gold_Flesh && CurrentHealth < healthBefore && Gold > 0) {
		Gold--;
	}

	//Shock Absorber trait
	if (Shock_Absorber != -1) {
		Shock_Absorber += damageTaken;
	}

	return damageTaken;
}

//gain block
int Character::gainBlock(int block) {
	int b = block;
	if (b < 0)
		b = 0;
	else {
		//Charred Skin trait
		if (Charred_Skin)
			TakeDamage(-1 * b);
		else if (Overconfidence < 6)
			CurrentBlock += b;
	}
	if (CurrentBlock > 999) {
		CurrentBlock = 999;
	}

	return b;
}

//lose block
int Character::loseBlock(int block) {
	//Amass trait
	if (Amass != -1) {
		int am;
		if (block > CurrentBlock)
			am = CurrentBlock;
		else
			am = block;
		Amass += am;
	}
	if (block > CurrentBlock)
		CurrentBlock = 0;
	else
		CurrentBlock -= block;


	return block;
}

//drain/regain mana
int Character::DrainMana(int manaDrained) {
	int mananow = CurrentMana;
	if (CurrentMana - manaDrained < 0)
		CurrentMana = 0;
	else
		CurrentMana -= manaDrained;

	checkMax();

	return manaDrained;
}

//gain energy
int Character::gainEnergy(int energy) {
	int en = energy;
	//Stamina trait
	if (Stamina && Energy < 0)
		en *= 2;
	//Heavy trait
	if (Heavy)
		gainBlock(en);
	else {
		Energy += en;
	}

	//Flat Feet trait
	if (Flat_Feet && Energy <= -5) {
		Energy = -10;
	}

	return en;
}

//change stats permanently
int Character::ModStat(int bonus, string stat, bool battle) {
	//Stiff trait
	if (!Stiff) {
		//Reversal trait
		if (Reversal && bonus < 0) {
			bonus *= -1;
		}

		if (battle) {
			if (stat == "MaxHealth")
				hpMod -= bonus;
			else if (stat == "MaxMana")
				mpMod -= bonus;
			else if (stat == "Strength")
				strMod -= bonus;
			else if (stat == "Defense")
				defMod -= bonus;
			else if (stat == "Intelligence")
				intMod -= bonus;
			else if (stat == "Skill")
				sklMod -= bonus;
		}

		if (stat == "MaxHealth") {
			MaxHealthBase += bonus;
			MaxHealth += bonus;
		}
		else if (stat == "MaxMana") {
			MaxManaBase += bonus;
			MaxMana += bonus;
		}
		else if (stat == "Strength")
			Strength += bonus;
		else if (stat == "Defense")
			Defense += bonus;
		else if (stat == "Intelligence")
			Intelligence += bonus;
		else if (stat == "Skill")
			Skill += bonus;
	}
	checkMax();

	return bonus;
}

void Character::restoreStats() {
	//Purple trait
	if (Purple || Stiff)
		return;

	Strength += strMod;
	Defense += defMod;
	Intelligence += intMod;
	MaxHealth += hpMod;
	MaxMana += mpMod;
	Skill += sklMod;

	strMod = 0;
	defMod = 0;
	intMod = 0;
	hpMod = 0;
	mpMod = 0;
	sklMod = 0;
}

int Character::gainGold(int gold) {
	Gold += gold;
	if (Gold < 0)
		gold = 0;
	return gold;
}

//to be implemented (probably not)
void Character::manaFlicker() {
	/*init_pair(1, COLOR_WHITE, COLOR_MAGENTA);
	attron(COLOR_PAIR(1));
	mvprintw(1, 31, "MP: %d/%d  ", CurrentMana, MaxMana);
	attroff(COLOR_PAIR(1));
	mvprintw(1, 31, "MP: %d/%d  ", CurrentMana, MaxMana);*/
}

void Character::changePosBefore(char c, int i) {
	if (c == 'x')
		posxBefore = i;
	else if (c == 'y')
		posyBefore = i;
}