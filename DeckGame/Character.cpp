#include "pch.h"
#include "Character.h"

int rtd(int multiplier, int power);

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
	mvprintw(1, 1, "(D)eck");
	mvprintw(2, 1, "(G)ear");
	mvprintw(3, 1, "(T)raits");
}
//print stats
void Character::printStats() {
	if (!Numb) {
		mvprintw(1, 18, "HP: %d/%d  ", CurrentHealth, MaxHealth);
		mvprintw(1, 31, "MP: %d/%d  ", CurrentMana, MaxMana);

		mvprintw(2, 18, "Str: %d  ", Strength);
		mvprintw(3, 18, "Def: %d  ", Defense);
		mvprintw(2, 31, "Int: %d  ", Intelligence);

		mvprintw(3, 31, "Skl: %d  ", Skill);
	}
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

//take/heal damage
int Character::TakeDamage(int damageTaken) {
	int healthBefore = CurrentHealth;
	//Hemoglobin trait
	if (Hemoglobin && damageTaken < 0) {
		damageTaken = int(damageTaken*1.5);
	}
	//Undead trait
	if (damageTaken < 0 && Undead) {
		damageTaken = 0;
	}
	//Deadly trait
	if (damageTaken > 0 && Deadly) {
		damageTaken *= 2;
	}
	//entomb
	if (entomb > 0 && damageTaken > 0) {
		damageTaken = 0;
	}
	//Tumors trait
	if (Tumors && damageTaken < 0) {
		ModStat(-1, "MaxHealth");
		if (CurrentHealth > MaxHealth)
			CurrentHealth = MaxHealth;
		hpMod++;
	}
	//healing
	if (damageTaken < 0) {
		if (healthBefore - damageTaken > MaxHealth)
			CurrentHealth = MaxHealth;
		else
			CurrentHealth -= damageTaken;
		return healthBefore - CurrentHealth;
	}
	//intimidate
	if (damageTaken >= 0 && intimidate > 0) {
		damageTaken = int(damageTaken / 2);
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
			if (Negate > 0) {
				Negate--;
			}
			else if (damageTaken >= CurrentBlock) {
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
	if (Spiny_Skin && damageTaken > 0) {
		SpinyDamage = Skill + 3;
	}

	return damageTaken;
}

//drain/regain mana
int Character::DrainMana(int manaDrained) {
	int mananow = CurrentMana;
	if (CurrentMana - manaDrained < 0)
		CurrentMana = 0;
	else if (mananow - manaDrained > MaxMana) {
		CurrentMana = MaxMana;
	}
	else
		CurrentMana -= manaDrained;
	return manaDrained;
}

//change stats besides CurrentHealth
int Character::ModStat(int bonus, string stat) {
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
	return bonus;
}

//to be implemented
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