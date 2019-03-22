#include "pch.h"
#include "Enemy.h"

void manualBox(string typebox, int colorpair);
int rtd(int multiplier, int power);

Enemy::Enemy() {
	Name = "";
}
Enemy::Enemy(const char *name):Name(name)
{
	Name = name;
	MaxHealth = 0;
	CurrentBlock = 0;
	TurnCount = 0;
	dot = 0;
	charge = FALSE;
	extraTurns = 0;
	cardAdded = FALSE;
	invisible = 0;
	type = 0;
	enemyNegate = 0;

	numA = 0;
	numB = 0;
	numC = 0;
	numD = 0;
	numE = 0;
	numF = 0;
	numG = 0;

	stepOne = FALSE;
	stepTwo = FALSE;

	sandstorm = 0;
	bleeding = 0;
	fumes = 0;
	flay = 0;

	//teirs are used for scaling bosses based on map placement
	tier = 1;

//----------------Basic----------------
	//Rat (does damage)
	if (Name == "Rat") {
		MaxHealth = 20;
		goldreward = 2;
	}
	else if (Name == "Crab") {
		MaxHealth = 11;
		goldreward = 3;
	}
	else if (Name == "Kobold") {
		MaxHealth = 25;
		goldreward = 3;
	}
	else if (Name == "Zombie") {
		MaxHealth = 30;
		goldreward = 3;
	}
	else if (Name == "Hound") {
		MaxHealth = 35;
		goldreward = 3;
	}
//-----------------Mid-----------------
	else if (Name == "Giant Rat") {
		MaxHealth = 50;
		goldreward = 5;
	}
	else if (Name == "Wild Buffalo") {
		MaxHealth = 50;
		goldreward = 5;
	}
	else if (Name == "Harpy") {
		MaxHealth = 45;
		goldreward = 5;
	}
	else if (Name == "Brown Recluse") {
		MaxHealth = 65;
		goldreward = 5;
	}
	else if (Name == "Fairy") {
		MaxHealth = 1;
		goldreward = 5;
	}
//----------------High-----------------
	else if (Name == "Elemental") {
		MaxHealth = 100;
		goldreward = 8;
	}
	else if (Name == "Adventurer") {
		MaxHealth = 80;
		goldreward = 7;
		type = rand() % 4;
	}
	else if (Name == "Troll") {
		MaxHealth = 140;
		goldreward = 7;
	}
//---------------Themed----------------
	//------Dragon:
	else if (Name == "Hatchling") {
		MaxHealth = 30;
		goldreward = 3;
	}
	else if (Name == "Molten Jelly") {
		MaxHealth = 55;
		goldreward = 5;
	}
	else if (Name == "Knight") {
		MaxHealth = 60;
		goldreward = 8;
	}
	else if (Name == "Drake") {
		MaxHealth = 75;
		goldreward = 8;
	}
	//------King:
	else if (Name == "Slave") {
		MaxHealth = 30;
		goldreward = 3;
	}
	else if (Name == "Soldier") {
		MaxHealth = 40;
		goldreward = 5;
	}
	else if (Name == "Guard") {
		MaxHealth = 60;
		goldreward = 8;
	}
	else if (Name == "Jester") {
		MaxHealth = 60;
		goldreward = 8;
	}
	//------Witch:
	else if (Name == "Eyeball") {
		MaxHealth = 25;
		goldreward = 3;
	}
	else if (Name == "Apprentice") {
		MaxHealth = 45;
		goldreward = 5;
	}
	else if (Name == "Monster") {
		MaxHealth = 60;
		goldreward = 8;
	}
	else if (Name == "Brain") {
		MaxHealth = 120;
		goldreward = 8;
	}
	//------Demon:
	else if (Name == "Cultist") {
		MaxHealth = 30;
		goldreward = 3;
	}
	else if (Name == "Imp") {
		MaxHealth = 25;
		goldreward = 5;
		charge = TRUE;
	}
	else if (Name == "Weeping Soul") {
		MaxHealth = 60;
		goldreward = 8;
	}
	else if (Name == "Hellhound") {
		MaxHealth = 70;
		goldreward = 8;
	}
	//------Machine:
	else if (Name == "Robot") {
		MaxHealth = 25;
		goldreward = 3;
	}
	else if (Name == "Golem") {
		MaxHealth = 60;
		goldreward = 5;
	}
	else if (Name == "Merchant") {
		MaxHealth = 70;
		goldreward = 15;
		type = rtd(1, 3);
	}
	else if (Name == "Turret") {
		MaxHealth = 80;
		goldreward = 8;
	}
//----------------Boss-----------------
	else if (Name == "Paladin") {
		goldreward = 20;
	}
	else if (Name == "Hunter") {
		goldreward = 20;
	}
	else if (Name == "Juggernaut") {
		goldreward = 20;
	}
	else if (Name == "Vampire") {
		goldreward = 20;
	}
	else if (Name == "Druid") {
		goldreward = 20;
	}
	else if (Name == "Thief") {
		goldreward = 20;
	}
	else if (Name == "Hydra") {
		goldreward = 20;
	}
	else if (Name == "Wolf") {
		goldreward = 20;
	}
	else if (Name == "Exorcist") {
		goldreward = 20;
		type = rand() % 3;
	}
	else if (Name == "Demigod") {
		goldreward = 20;
		type = 1;
	}
	else if (Name == "Serpent") {
		goldreward = 20;
	}
	else if (Name == "Spirit") {
		goldreward = 20;
	}
	else if (Name == "Artificer") {
		goldreward = 20;
	}
//-------------Final Boss--------------
	else if (Name == "Dragon") {
		MaxHealth = 275;
		goldreward = 50;
	}
	else if (Name == "King") {
		MaxHealth = 150;
		goldreward = 50;
	}
	else if (Name == "Witch") {
		MaxHealth = 150;
		goldreward = 50;
	}
	else if (Name == "Demon") {
		MaxHealth = 200;
		goldreward = 50;
	}
	else if (Name == "Machine") {
		MaxHealth = 300;
		goldreward = 50;
		numA = MaxHealth / 3;
		dot = numA * 2;
	}
	initNegotiateLines();

	CurrentHealth = MaxHealth;
}
Enemy::~Enemy()
{
}

//used for scaling bosses
void Enemy::setStats(Character &guy) {
	if (Name == "Paladin") {
		MaxHealth = 60 + (10*tier);
	}
	else if (Name == "Hunter") {
		MaxHealth = 50 + (15*tier);
	}
	else if (Name == "Juggernaut") {
		MaxHealth = 120 + (20 * tier);
	}
	else if (Name == "Vampire") {
		MaxHealth = 35 + (10 * tier);
	}
	else if (Name == "Druid") {
		MaxHealth = 95 + (5 * tier);
	}
	else if (Name == "Thief") {
	}
	else if (Name == "Hydra") {
		MaxHealth = 55 + (11 * tier);
	}
	else if (Name == "Wolf") {
		MaxHealth = 70 + (10 * tier);
	}
	else if (Name == "Exorcist") {
		MaxHealth = 90 + (15 * tier);
	}
	else if (Name == "Demigod") {
		MaxHealth = 90 + (15 * tier);
	}
	else if (Name == "Serpent") {
		MaxHealth = 70 + (10 * tier);
	}
	else if (Name == "Spirit") {
		MaxHealth = 70 + (7 * tier);
	}
	else if (Name == "Artificer") {
		MaxHealth = 55 + (15 * tier);
	}

	CurrentHealth = MaxHealth;
}

/*Enemies
Themed:
	Dragon:
		1 Hatchling
		2 Molten Jelly
		3 Knight
		3 Drake
	King:
		1 Slave
		2 Soldier
		3 Guard
		3 Jester
	Witch:
		1 Eyeball
		2 Apprentice
		3 Monster
		3 Brain
	Demon:
		1 Cultist
		2 Imp
		3 Weeping Soul
		3 Hellhound
	Machine:
		1 Robot
		2 Golem
		3 Merchant
		3 Turrent
Basic:
	Rat
	Crab
	Kobold
	Zombie
	Hound
Mid:
	Giant Rat
	Wild Buffalo
	Harpy
	Brown Recluse
	Fairy (also in high)
High:
	Elemntal
	Adventurer
	Troll
Boss:
	Paladin
	Hunter
	Juggernaut
	Vampire
	Druid
	Thief
	Hydra
	Wolf
	Exorcist
	Demigod
Final Boss:
	Dragon
	King
	Witch
	Demon
	Machine
*/

//not using this template anymore
/*          TEMPLATE
------------------------------------
Kobold::Kobold() {
	Name = "Kobold";
	MaxHealth = 20;
	CurrentHealth = MaxHealth;
}
void Kobold::Turn(Character &guy, TextLog &log) {
	if (CurrentHealth > 0) {
		string line;

		log.PushPop(line);
		updateEnemy(guy);
	}
	if (guy.CurrentHealth <= 0) {
		guy.Alive = FALSE;
	}
}
------------------------------------
*/


void Enemy::Turn(Character &guy, TextLog &log) {
	//non final boss enemy's basic attacks deal more damage as the fight goes on
	int td = int(TurnCount / 25);

	//check if the enemy is DOT
	if (guy.Toxic_Release) {
		int damage = 1 + rtd(1, guy.Skill / 2);
		takeDamage(damage, guy, log);
	}
	if (bleeding > 0 || flay > 0) {
		int damage = 0;
		if (bleeding > 0) {
			damage += rtd(2, int(guy.Strength / 2));
			bleeding--;
		}
		if (flay > 0) {
			damage += int(guy.Strength / 2);
			flay--;
		}
		damage = takeDamage(damage, guy, log);

		string bleedline = "-The " + string(Name) + " bleeds for #y" + to_string(damage) + "#o damage.";
		log.PushPop(bleedline);

		
	}
	if (fumes > 0) {
		int damage = rtd(int(guy.Intelligence/2), 2);
		damage = takeDamage(damage, guy, log);

		string fumesline = "-The " + string(Name) + " takes #y" + to_string(damage) + "#o poison damage.";
		log.PushPop(fumesline);
		fumes--;
	}
	if (guy.reagent > 0) {
		int damage = rtd(1, 4);
		damage = takeDamage(damage, guy, log);

		string gasline = "-The " + string(Name) + " takes #y" + to_string(damage) + "#o damage from the gas.";
		log.PushPop(gasline);
		guy.reagent--;
	}
	if (guy.drown > 0 && guy.CurrentMana > 0) {
		int mana = guy.drown;
		int damage = int(guy.Intelligence / 2);
		damage = takeDamage(damage*guy.drown, guy, log);
		if (guy.Sacrificial)
			guy.TakeDamage(mana);
		else
			guy.DrainMana(mana);

		string drown = "-You drown the " + string(Name) + " for #y"
					+ to_string(damage) + "#o damage.";
		log.PushPop(drown);
	}
	if (sandstorm > 0) {
		int damage = rtd(3, guy.Intelligence);
		int damage2 = guy.TakeDamage(damage);
		damage = takeDamage(damage, guy, log);
		sandstorm--;

		string storm1 = " #mThe storm rages.#o It hits the " + string(Name) + " for #y" + to_string(damage) + "#o damage.";
		string storm2 = "-The storm hits you for #r" + to_string(damage2) + "#o damage.";
		log.PushPop(storm1);
		log.PushPop(storm2);
	}
	if (guy.Exhaust_Vent > 0) {
		int damage = rtd(guy.Skill, 2);
		damage = takeDamage(damage, guy, log);

		string ventline = "-The " + string(Name) + " takes #y" + to_string(damage) + "#o steam damage.";
		log.PushPop(ventline);
		guy.Exhaust_Vent--;
	}

	if (CurrentHealth <= 0) {
		//for the Druid coming back to life
		if (Name == "Druid" && charge) {
			charge = FALSE;
			MaxHealth = 95 + (5 * tier);
			CurrentHealth = MaxHealth/3;
			string rev = "#r-The Druid restores its life!#o";
			log.PushPop(rev);
		}
		else {
			Alive = FALSE;
			return;
		}
	}
	else if (CurrentHealth > 0) {
//----------------Basic----------------
	//Rat: just some damage
		if (Name == "Rat") {
				int damage = rtd(3+td, 4);

				damage = guy.TakeDamage(damage);
				string line = string("-The Rat bites you for #r") + to_string(damage)
					+ string("#o damage.");
				log.PushPop(line);
		}
	//Crab: lots of block first turn
		else if (Name == "Crab") {
				string line;
				if (TurnCount == 0) {
					int block = gainBlock(20, guy, log);
					line = "-The Crab hides in its shell and gains #b" + to_string(block) + "#o block.";
				}
				else {
					int rng = rand() % 4;
					if (rng == 0) {
						int block = gainBlock(rtd(3, 3), guy, log);
						line = "-The Crab gains #b" + to_string(block) + "#o block.";
					}
					else {
						int damage = rtd(2, 5+td);
						damage = guy.TakeDamage(damage);
						line = "-The Crab pinches you for #r" + to_string(damage) + "#o damage.";
					}
				}
				log.PushPop(line);
				updateEnemy(guy);
				//TurnCount++;
		}
	//Kobold: pierces block sometimes	
		else if (Name == "Kobold") {
				string line;
				int rng = rand() % 5;
				if (rng == 0) {
					int block = gainBlock(rtd(4, 2), guy, log);
					line = "-The Kobold gains #b" + to_string(block) + "#o block.";
				}
				else if (rng == 1 && guy.CurrentHealth > 1) {
					guy.pierce = TRUE;
					int damage = rtd(6, 2);
					if (guy.CurrentHealth < 12)
						damage = guy.CurrentHealth - 1;
					damage = guy.TakeDamage(damage);
					line = "-The Kobold #rpierces your armor#o and stabs you for #r" + to_string(damage) + "#o damage.";
				}
				else {
					int damage = rtd(3 + td, 4);
					damage = guy.TakeDamage(damage);
					line = "-The Kobold slices you for #r" + to_string(damage) + "#o damage.";
				}
				log.PushPop(line);
				updateEnemy(guy);
		}
	//Zombie: can leech for unblocked damage	
		else if (Name == "Zombie") {
				string line;

				int damage = rtd(3 + td, 2);
				int health = damage;
				if (health < guy.CurrentBlock || guy.Negate > 0)
					health = 0;
				else {
					health -= guy.CurrentBlock;
				}
				damage = guy.TakeDamage(damage);
				heal(health, guy, log);
				line = "-The Zombie bites you for #r" + to_string(damage) + "#o damage and steals #b" + to_string(health) + "#o health.";

				log.PushPop(line);
				updateEnemy(guy);
		}
	//Hound: can deal damage over time	
		else if (Name == "Hound") {
				string line;

				if (guy.dotDamage == 0) {
					guy.dotDamage += 2;
					line = "#r-The Hound tears your flesh, causing you to bleed out.#o";
				}
				else {
					int rng = rand() % 4;
					if (rng == 0) {
						guy.dotDamage += 2;
						line = "#r-The Hound tears your flesh, causing you to bleed out.#o";
					}
					else {
						int damage = rtd(3 + td, 3);
						damage = guy.TakeDamage(damage);
						line = "-The Hound bites you for #r" + to_string(damage) + "#o damage.";
					}
				}

				log.PushPop(line);
				updateEnemy(guy);
		}
//-----------------Mid-----------------
	//Giant Rat: does a lot of damage
		else if (Name == "Giant Rat") {
			string line;

			int damage = rtd(3 + td, 4)+2;
			damage = guy.TakeDamage(damage);

			line = string("-The Giant Rat bites you for #r") + to_string(damage)
				+ string("#o damage.");

			log.PushPop(line);
			updateEnemy(guy);
		}
	//Wild Buffalo: charges up and either removes your block or does a lot of damage	
		else if (Name == "Wild Buffalo") {
			string line;

			int rng = rand() % 4;
			if (charge || rng == 0) {
				if (!charge) {
					line = "#r-The Wild Buffalo paws the ground, preparing to charge.#o";
					charge = TRUE;
				}
				else if (charge) {
					if (guy.CurrentBlock != 0) {
						guy.CurrentBlock = 0;
						line = "#r-The Wild Buffalo charges at you and removes your block.#o";
					}
					else {
						int damage = rtd(9, 4);
						damage = guy.TakeDamage(damage);
						line = "-The Wild Buffalo charges at you and does #r" + to_string(damage) + "#o damage.";
					}
					charge = FALSE;
				}

			}
			else {
				int damage = rtd(3 + td, 5);
				damage = guy.TakeDamage(damage);
				line = "-The Wild Buffalo slams you for #r" + to_string(damage) + "#o damage.";
			}

			log.PushPop(line);
			updateEnemy(guy);
		}
	//Harpy: chance for an extra turn
		else if (Name == "Harpy") {
			string line;

			int rng = rand() % 3;
			if (rng == 0) {
				int block = gainBlock(rtd(1, 7), guy, log);
				line = "-The Harpy gains #b" + to_string(block) + "#o block.";
			}
			else {
				int damage = rtd(1 + td, 11);
				damage = guy.TakeDamage(damage);
				line = "-The Harpy scratches you for #r" + to_string(damage) + "#o damage.";
			}

			if (extraTurns > 0) {
				extraTurns--;
				TurnCount--;
				if (extraTurns == 0) {
					charge = TRUE;
				}
				Turn(guy, log);
				charge = FALSE;
			}
			else if(!charge){
				int turns = rand() % 3;
				extraTurns += turns;
			}

			log.PushPop(line);
			updateEnemy(guy);
		}
	//Brown Recluse: can web you and apply venom	
		else if (Name == "Brown Recluse") {
			string line;

			if (TurnCount == 0) {
				guy.ADDWebbed++;
				line = "#r-The Brown Recluse spews a web at you.#o";
				//TurnCount++;
			}
			else {
				int rng = rand() % 4;
				if (rng == 0 && guy.dotDamage < 4) {
					guy.dotDamage += 2;
					line = "#r-The Brown Recluse injects you with venom.#o";
				}
				else {
					int damage = rtd(6 + td, 2);
					damage = guy.TakeDamage(damage);
					line = "-The Brown Recluse bites you for #r" + to_string(damage) + "#o damage.";
				}
			}
			log.PushPop(line);
			updateEnemy(guy);
		}
	//Fairy: drops a spell when killed
		else if (Name == "Fairy") {

		}
//----------------High-----------------
	//Elemental: dot, stat drain, leech, can pierce, heal, adds cards that damage and give extra turn
		else if (Name == "Elemental") {
			string line;
			int rng = rand() % 14;
			if (rng == 0 && !cardAdded) {
				//add card
				guy.ADDScalding_Steam++;
				line = "#r-The Elemental sprays you with steam.#o";
				cardAdded = TRUE;
			}
			else if (rng > 0 && rng <= 2) {
				//dot
				guy.dotDamage += 2;
				line = "#r-The Elemental releases toxic fumes.#o";
			}
			else if (rng > 2 && rng <= 4) {
				//leech
				int damage = rtd(3, 2);
				damage = guy.TakeDamage(damage);
				heal(damage, guy, log);
				line = "-The Elemental #rsteals " + to_string(damage) + " health#o from you.";
			}
			else if (rng > 4 && rng <= 6) {
				//heal
				int health = rtd(6, 2);
				heal(health, guy, log);
				line = "-The Elemental gains #b" + to_string(health) + "#o health.";
			}
			else if (rng > 6 && rng <= 7) {
				//stat drain
				int rng2 = rand() % 8;
				if (rng2 >= 0 && rng2 < 2 && guy.Strength > 1) {
					//str
					guy.ModStat(-1, "Strength", TRUE);
					line = "-The Elemental drains #r1 strength#o from you.";
				}
				else if (rng2 >= 2 && rng2 < 4 && guy.Defense > 1) {
					//def
					guy.ModStat(-1, "Defense", TRUE);
					line = "-The Elemental drains #r1 defense#o from you.";
				}
				else if (rng2 >= 4 && rng2 < 6 && guy.Intelligence > 1) {
					//int
					guy.ModStat(-1, "Intelligence", TRUE);
					line = "-The Elemental drains #r1 intelligence#o from you.";
				}
				else if (rng2 >= 6 && rng2 < 7 && guy.MaxHealth > 10) {
					//hp
					guy.ModStat(-1, "MaxHealth", TRUE);
					if (guy.CurrentHealth > guy.MaxHealth)
						guy.MaxHealth--;
					line = "-The Elemental drains #r1 max health#o from you.";
				}
				else if (rng2 == 7 && guy.MaxMana > 3) {
					//mp
					guy.ModStat(-1, "MaxMana", TRUE);
					if (guy.CurrentMana > guy.MaxMana)
						guy.CurrentMana--;
					line = "-The Elemental drains #r1 max mana#o from you.";
				}
				else {
					//small attack
					int damage = 1;
					damage = guy.TakeDamage(damage);
					line = "-The Elemental hits you for #r1#o damage.";
				}
			}
			else {
				//damage
				int rng2 = rand() % 4;
				int damage = rtd(10, 2);
				if (rng2 == 0 && guy.CurrentHealth > 16) {
					guy.pierce = TRUE;
					int damage = rtd(8, 2);
					damage = guy.TakeDamage(damage);
					line = "-The Elemental #rpierces your armor#o and hits you for #r" + to_string(damage) + "#o damage.";
				}
				else {
					int damage = rtd(3 + td, 12);
					damage = guy.TakeDamage(damage);
					line = "-The Elemental hits you for #r" + to_string(damage) + "#o damage.";
				}
			}

			log.PushPop(line);
			updateEnemy(guy);
		}
	//Adventurer: damage, blocks, spells	
		else if (Name == "Adventurer") {
			string line;
			//type 1: lots of attacks, piercing attacks, removes block
			//type 2: lots of block, free damage sometimes
			//type 3: charges up, lots of spell damage
			//type 4: lots of heals, passive heals
			int rng1 = rand() % 3;

			if (rng1 == 0) {
				if (type == 0) {
					int rng2 = rand() % 3;
					if (rng2 == 0 && guy.CurrentHealth > 12) {
						int damage = 12;
						guy.pierce = TRUE;
						damage = guy.TakeDamage(damage);
						line = "-The Adventurer pierces your armor and deals #r" + to_string(damage) + "#o damage.";
					}
					else {
						int damage = rtd(12 + td, 3);
						damage = guy.TakeDamage(damage);
						line = "-The Adventurer crushes you for #r" + to_string(damage) + "#o damage.";
					}
				}
				else if (type == 1) {
					int damage = rtd(5 + td, 3);
					damage = guy.TakeDamage(damage);
					line = "-The Adventurer slices you for #r" + to_string(damage) + "#o damage.";
					charge = FALSE;
				}
				else if (type == 2) {
					dot++;
					line = "#r-The Adventurer is charging up.#o";
				}
				else if (type == 3) {
					int damage = rtd(12 + td, 2);
					damage = guy.TakeDamage(damage);
					line = "-The Adventurer stabs you for #r" + to_string(damage) + "#o damage.";
					int hp = heal(2, guy, log);
					string line2 = "-The Adventurer regenerates #r" + to_string(hp) + "#o health.";
					log.PushPop(line2);
				}
			}
			else if (rng1 == 1) {
				if (type == 0) {
					int block = gainBlock(rtd(3, 6), guy, log);
					line = "-The Adventurer gains #b" + to_string(block) + "#o block.";
				}
				else if (type == 1) {
					int block = gainBlock(rtd(8, 3), guy, log);
					line = "-The Adventurer gains #b" + to_string(block) + "#o block.";
					charge = FALSE;
				}
				else if (type == 2) {
					int block = gainBlock(rtd(3, 6), guy, log);
					line = "-The Adventurer gains #b" + to_string(block) + "#o block.";
				}
				else if (type == 3) {
					int block = gainBlock(rtd(2, 5), guy, log);
					line = "-The Adventurer gains #b" + to_string(block) + "#o block.";
					int hp = heal(2, guy, log);
					string line2 = "-The Adventurer regenerates #r" + to_string(hp) + "#o health.";
					log.PushPop(line2);
				}
			}
			else if (rng1 == 2) {
				if (type == 0) {
					int rng2 = rand() % 2;
					if (rng2 == 0) {
						guy.CurrentBlock = 0;
						line = "#r-The Adventurer destroys all your block.#o";
					}
					else {
						int health = rtd(4, 3);
						heal(health, guy, log);
						line = "-The Adventurer heals for #r" + to_string(health) + "#o health.";
					}
				}
				else if (type == 1) {
					if (!charge) {
						int damage = rtd(4, 5);
						damage = guy.TakeDamage(damage);
						line = "-The Adventurer zaps you for #r" + to_string(damage) + "#o damage.";
						charge = TRUE;
						Turn(guy, log);
					}
					else {
						int damage = rtd(4, 5);
						damage = guy.TakeDamage(damage);
						line = "-The Adventurer zaps you for #r" + to_string(damage) + "#o damage.";
					}
				}
				else if (type == 2) {
					if (dot <= 0) {
						Turn(guy, log);
					}
					else {
						for (int i = 0; i < dot; i++) {
							int damage = guy.TakeDamage(rtd(10 + td, 3));
							string line2 = "-The Adventurer electrocutes you for #r" + to_string(damage) + "#o damage.";
							log.PushPop(line2);
						}
						dot = 0;
					}
				}
				else if (type == 3) {
					int health = rtd(5, 2);
					heal(health, guy, log);
					line = "-The Adventurer heals for #r" + to_string(health) + "#o health.";
					int hp = heal(2, guy, log);
					string line2 = "-The Adventurer regenerates #r" + to_string(hp) + "#o health.";
					log.PushPop(line2);
				}
			}
			if(type != 2 || rng1 != 2)
				log.PushPop(line);
			updateEnemy(guy);
		}
	//Troll: charges up for big damage
		else if (Name == "Troll") {
			string line;

			if (charge) {
				int damage = rtd(16 + td, 2);
				damage = guy.TakeDamage(damage);
				line = "-The Troll bludgeons you for #r" + to_string(damage) + "#o damage.";
				charge = FALSE;
			}
			else {
				int rng = rand() % 3;
				if (rng == 0) {
					charge = TRUE;
					line = "#r-The Troll readies its swing.#o";
				}
				else {
					int block = gainBlock(rtd(2, 6), guy, log);
					line = "-The Troll gains #b" + to_string(block) + "#o block.";
				}
			}

			log.PushPop(line);
		}
//---------------Themed----------------
	//------Dragon:
	//Hatchling: charges up for big damage
		else if (Name == "Hatchling") {
			string line;

			int rng = rand() % 3;
			if (dot == 3 || (dot > 0 && rng < 2)) {
				int damage = 0;
				damage -= rtd(dot, 2);
				for (int i = 0; i < dot; i++) {
					damage += rtd(1, 7) + 11 + td;
				}
				damage = guy.TakeDamage(damage);
				dot = 0;
				line = "-The Hatchling launches a fireball at you for #r" + to_string(damage) + "#o damage.";
			}
			else {
				dot++;
				line = "#r-The Hatchling inhales...#o";
			}

			log.PushPop(line);
		}
	//Molten Jelly: damage over time, removes your block
		else if (Name == "Molten Jelly") {
			string line;

			int rng = rand() % 3;
			if (guy.dotDamage == 0 || (rng < 2 && guy.dotDamage < 8+2*td)) {
				guy.dotDamage += 2;
				line = "#r-The Molten Jelly sprays you with embers.#o";
			}
			else {
				guy.CurrentBlock = 0;
				line = "#r-The Molten Jelly disintegrates all of your block.#o";
			}

			log.PushPop(line);
		}
	//Knight: passive block, hit hard
		else if (Name == "Knight") {
			string line;

			if (CurrentBlock < 40) {
				int pblock = gainBlock(rtd(3, 2), guy, log);
				string line2 = "-The Knight gains #b" + to_string(pblock) + "#o block.";
				log.PushPop(line2);
			}

			int damage = rtd(3 + td, 6);
			damage = guy.TakeDamage(damage);
			line = "-The Knight slices you for #r" + to_string(damage) + "#o damage.";

			log.PushPop(line);
		}
	//Drake: can get extra turns
		else if (Name == "Drake") {
			string line;

			int rng = rand() % 3;
			if (rng == 0) {
				int block = gainBlock(rtd(3, 4), guy, log);
				line = "-The Drake gains #b" + to_string(block) + "#o block.";
			}
			else {
				int damage = rtd(2 + td, 7);
				damage = guy.TakeDamage(damage);
				line = "-The Drake burns you for #r" + to_string(damage) + "#o damage.";
			}

			if (extraTurns > 0) {
				extraTurns--;
				Turn(guy, log);
			}
			else {
				for (int i = 0; i < 3; i++) {
					int turn = rand() % 4;
					if (turn == 0)
						extraTurns++;
				}
			}

			log.PushPop(line);
			updateEnemy(guy);
		}
	//------King:
	//Slave: can heal by consuming block
		else if (Name == "Slave") {
			string line;

			int rng = rand() % 5;

			if (CurrentBlock > 6 && CurrentHealth < 15) {
				int health = CurrentBlock;
				CurrentBlock = 0;
				heal(health, guy, log);

				line = "-The Slave consumes their block and heals for #b" + to_string(health) + "#o health.";
			}
			else if (rng < 2 && CurrentBlock < 10) {
				int block = rtd(1, 4) + 1 + ((MaxHealth - CurrentHealth)/5);
				block = gainBlock(block, guy, log);

				line = "-The Slave gains #b" + to_string(block) + "#o block.";
			}
			else{
				int damage = rtd(3+td, 4);
				damage = guy.TakeDamage(damage);

				line = "-The Slave hits you for #r" + to_string(damage) + "#o damage.";
			}

			log.PushPop(line);
		}
	//Soldier: passive block, hits hard
		else if (Name == "Soldier") {
			string line;

			int pblock = gainBlock(rtd(2, 2), guy, log);
			string line2 = "-The Soldier gains #b" + to_string(pblock) + "#o block.";
			log.PushPop(line2);

			int damage = rtd(2+td, 5) + 2;
			damage = guy.TakeDamage(damage);
			line = "-The Soldier slices you for #r" + to_string(damage) + "#o damage.";

			log.PushPop(line);
		}
	//Guard: can damage you by consuming block
		else if (Name == "Guard") {
			string line;

			int rng = rand() % 3;

			if (rng == 0) {
				int damage = (3+td, 3);
				damage = guy.TakeDamage(damage);
				line = "-The Guard hits you for #r" + to_string(damage) + "#o damage.";
			}
			else if (CurrentBlock > 15 && rng == 1) {
				int damage = guy.TakeDamage(CurrentBlock);
				CurrentBlock = 0;
				line = "-The Guard #buses their block#o to crush you for #r" + to_string(damage) + "#o damage.";
			}
			else {
				int block = gainBlock(rtd(6, 4), guy, log);
				line = "-The Guard gains #b" + to_string(block) + "#o block.";
			}

			log.PushPop(line);
		}
	//Jester: massive stat drain and stat raise
		else if (Name == "Jester") {
			string line;

			if (guy.CurrentBlock > 80) {
				CurrentBlock += guy.CurrentBlock;
				guy.CurrentBlock = 0;
				string line2 = "-The Jester decides to #rsteal your block#o.";
				log.PushPop(line2);
			}
			if (guy.Strength > 20) {
				guy.ModStat(-12, "Strength", TRUE);
				string line2 = "-#yYou #bfeel #gweak.";
				log.PushPop(line2);
			}
			if (guy.Intelligence > 20) {
				guy.ModStat(-12, "Intelligence", TRUE);
				string line2 = "-#cYou #yfeel #mdumb.";
				log.PushPop(line2);
			}
			if (guy.Skill > 20) {
				guy.ModStat(-15, "Skill", TRUE);
				string line2 = "-#mYou #rfeel #bslow.";
				log.PushPop(line2);
			}
			if (guy.Strength <= 0 && guy.Intelligence <= 0) {
				guy.ModStat(30, "Strength", TRUE);
				string line2 = "-#yYou #bfeel #gweak.";
				log.PushPop(line2);
			}
			int rng = rand() % 8;
			if (rng < 2) {
				int statchange = rtd(10, 2);
				int statrng = rand() % 6;
				switch (statrng) {
				case 0:
					guy.ModStat(statchange, "MaxHealth", TRUE);
					break;
				case 1:
					guy.ModStat(statchange, "MaxMana", TRUE);
					break;
				case 2:
					guy.ModStat(statchange, "Strength", TRUE);
					break;
				case 3:
					guy.ModStat(statchange, "Defense", TRUE);
					break;
				case 4:
					guy.ModStat(statchange, "Intelligence", TRUE);
					break;
				case 5:
					guy.ModStat(statchange, "Skill", TRUE);
					break;
				}

				statchange += rtd(1, 5) - 10;
				statchange *= -1;
				statrng = rand() % 6;
				switch (statrng) {
				case 0:
					guy.ModStat(statchange, "MaxHealth", TRUE);
					break;
				case 1:
					guy.ModStat(statchange, "MaxMana", TRUE);
					break;
				case 2:
					guy.ModStat(statchange, "Strength", TRUE);
					break;
				case 3:
					guy.ModStat(statchange, "Defense", TRUE);
					break;
				case 4:
					guy.ModStat(statchange, "Intelligence", TRUE);
					break;
				case 5:
					guy.ModStat(statchange, "Skill", TRUE);
					break;
				}
				line = "#r-The Jester #gmesses #cwith #yyour #mstats#r.#o";
			}
			else if (rng >= 2 && rng < 4) {
				int statrng = rand() % 4;
				int statchange = 0;
				if (!guy.Stiff) {
					switch (statrng) {
					case 0:
						statchange = guy.Skill * -2;
						guy.ModStat(statchange, "Skill", TRUE);
						break;
					case 1:
						statchange = guy.Intelligence * -2;
						guy.ModStat(statchange, "Intelligence", TRUE);
						break;
					case 2:
						statchange = guy.Strength * -2;
						guy.ModStat(statchange, "Strength", TRUE);
						break;
					case 3:
						statchange = guy.Defense * -2;
						guy.ModStat(statchange, "Defense", TRUE);
						break;
					}
				}
				

				line = "#r-The Jester #ymesses #mwith #cyour #gstats#r.#o";
			}
			else if (rng == 5 || rng == 6) {
				int block = gainBlock(rtd(10, 2), guy, log);
				line = "-The Jester gains #b" + to_string(block) + "#o block.";
			}
			else {
				int damage = rtd(7, 4);
				damage = guy.TakeDamage(damage);
				line = "-The Jester shanks you for #r" + to_string(damage) + "#o damage.";
			}

			log.PushPop(line);
		}
	//------Witch:
	//Eyeball: drains max hp and mana
		else if (Name == "Eyeball") {
			string line;

			int rng = rand() % 4;

			if (rng == 0 && guy.MaxMana > 1) {
				int mana = 2;
				guy.ModStat(-1 * mana, "MaxMana", TRUE);

				line = "-The Eyeball #mdrains #r" + to_string(mana) + "#m of your max mana#o.";
			}
			else if (guy.MaxHealth > 1) {
				int health;
				if (guy.MaxHealth <= 24) {
					health = guy.MaxHealth - 1;
				}
				else {
					health = rtd(12, 2);
				}
				guy.ModStat(-1 * health, "MaxHealth", TRUE);

				line = "-The Eyeball drains #r" + to_string(health) + "#o of your max health.";
			}
			else {
				int damage = rtd(3+td, 2);
				damage = guy.TakeDamage(damage);

				line = "-The Eyeball zaps you for #r" + to_string(damage) + "#o damage.";
			}

			log.PushPop(line);
		}
	//Apprentice: high constant damage for a few rounds, rest for a couple rounds
		else if (Name == "Apprentice") {
			string line;

			if (!charge) {
				int damage = rtd(6+td, 3);
				damage = guy.TakeDamage(damage);
				line = "-The Apprentice blasts you for #r" + to_string(damage) + "#o damage.";

				if (rand() % 7 < 3 || damage > 14) {
					charge = TRUE;
				}
			}
			else {
				int health = rtd(3, 2);
				heal(health, guy, log);
				line = "-The Apprentice regains #b" + to_string(health) + "#o health.";
			
				if (rand() % 7 < 4 || CurrentHealth == MaxHealth) {
					charge = FALSE;
				}
			}

			log.PushPop(line);
		}
	//Monster: passive block, hits hard
		else if (Name == "Monster") {
			string line;

			if (CurrentBlock < 40) {
				int pblock = gainBlock(rtd(3, 2), guy, log);
				string line2 = "-The Monster gains #b" + to_string(pblock) + "#o block.";
				log.PushPop(line2);
			}

			int damage = rtd(3 + td, 7);
			damage = guy.TakeDamage(damage);
			line = "-The Monster crushes you for #r" + to_string(damage) + "#o damage.";

			log.PushPop(line);
		}
	//Brain: damage over time, drain stats
		else if (Name == "Brain") {

			if (rand() % 3 == 0 && guy.dotDamage < 7+(td*2)) {
				guy.dotDamage += 2;
			}

			if (TurnCount < 2) {
				if (rand() % 3 == 0)
					guy.ADDDrain_Int++;
				else
					guy.ADDDrain_Str++;
			}
			else if (dot < 4) {
				int rng = rand() % 5;
				if (rng == 0)
					guy.ADDDrain_Int++;
				else if (rng == 1)
					guy.dotDamage++;
				else
					guy.ADDDrain_Str++;
				dot++;
			}
		}
	//------Demon:
	//Cultist: drains stats
		else if (Name == "Cultist") {
			string line;

			int rng = rand() % 5;
			if (rng == 0 && guy.Strength > 1) {
				guy.ModStat(-1, "Strength", TRUE);
				line = "-The Cultist drains #r1 strength#o from you.";
			}
			else if (rng == 1 && guy.Defense > 1) {
				guy.ModStat(-1, "Defense", TRUE);
				line = "-The Cultist drains #r1 defense#o from you.";
			}
			else if (rng == 2 && guy.Intelligence > 1) {
				guy.ModStat(-1, "Intelligence", TRUE);
				line = "-The Cultist drains #r1 intelligence#o from you.";
			}
			else {
				int damage = rtd(4+td, 3) + 1;
				damage = guy.TakeDamage(damage);
				line = "-The Cultist stabs you for #r" + to_string(damage) + "#o damage.";
			}

			log.PushPop(line);
			updateEnemy(guy);
		}
	//Imp: heals for damage over time, can pierce	
		else if (Name == "Imp") {
			string line;

			int rng = rand() % 3;
			if (guy.dotDamage < 6 && rng < 2) {
				guy.dotDamage ++;
				if (TurnCount == 0)
					line = "#r-You begin to waste away.#o";
				else
					line = "#r-You waste further.#o";
				string line2 = "#r-The Imp points at you.#o";
				log.PushPop(line2);
			}
			else if (rng == 2 && guy.CurrentHealth > 12) {
				int damage = rtd(6, 2);
				guy.pierce = TRUE;
				damage = guy.TakeDamage(damage);
				line = "-The Imp #rpierces your block#o and impales you for #r" + to_string(damage) + "#o damage.";
			}
			else {
				int damage = rtd(4+td, 2);
				damage = guy.TakeDamage(damage);
				line = "-The Imp stabs you for #r" + to_string(damage) + "#o damage.";
			}

			log.PushPop(line);
		}
	//Weeping Soul: can go invisible to not deal/take damage
		else if (Name == "Weeping Soul") {
			string line;

			if (TurnCount == 0) {
				invisible += (1, 5) + 29;
				line = "#b-The Weeping Soul turns invisible, becoming immune to direct damage.#o";
				log.PushPop(line);
			}
			else {
				if (invisible > 0) {
					int damage = rtd(6, 4);
					damage = guy.TakeDamage(damage);
					invisible -= damage;
					line = "-The Weeping Soul wails at you for #r" + to_string(damage) + "#o damage.";
					log.PushPop(line);
					if (invisible <= 0) {
						invisible = -2;
						string line2 = "#b-The Weeping Soul suddenly appears! #o";
						log.PushPop(line2);
					}
				}
				else {
					
					invisible++;
					if (invisible == 0) {
						invisible += (1, 10) + 22;
						line = "#b-The Weeping Soul turns invisible, becoming immune to direct damage.#o";
					}
					else
						line = "-The Weeping Soul sobs.";
					log.PushPop(line);
				}
			}

		}
	//Hellhound: removes your block, damage over time
		else if (Name == "Hellhound") {
			string line;

			int rng = rand() % 3;
			if (guy.dotDamage == 0 || (rng < 2 && guy.dotDamage < 8 + 2 * td)) {
				guy.dotDamage += 3;
				if (TurnCount == 0)
					line = "#r-You begin to waste away.";
				else
					line = "#r-You waste further.#o";
				string line2 = "#r-The Hellhound howls.#o";
				log.PushPop(line2);
			}
			else if (rng == 2) {
				int damage = rtd(3+td, 3);
				damage = guy.TakeDamage(damage);
				line = "-The Hellhound bites you for #r" + to_string(damage) + "#o damage.";
			}
			else {
				guy.CurrentBlock = 0;
				line = "#r-The Hellhound disintegrates all of your block.#o";
			}

			log.PushPop(line);
		}
	//------Machine:
	//Robot: can add card that does damage and gives an extra turn
		else if (Name == "Robot") {
			string line;

			int rng = rand() % 3;
			if (rng < 2 && dot < 5+td) {
				guy.ADDSteam++;
				dot++;
				line = "#r-The Robot expels some steam.#o";
			}
			else {
				int block = gainBlock(rtd(5-dot, 2), guy, log);

				line = "-The Robot gains #b" + to_string(block) + "#o block.";
			}

			log.PushPop(line);
		}
	//Golem: passive block, hits hard
		else if (Name == "Golem") {
			string line;

			if (CurrentHealth < MaxHealth) {
				int regen = rtd(1, 3);
				heal(regen, guy, log);
				string line2 = "-The Golem repairs itself for #b" + to_string(regen) + "#o health.";
				log.PushPop(line2);
			}

			int damage = rtd(2 + td, 6);
			damage = guy.TakeDamage(damage);
			line = "-The Golem slams you for #r" + to_string(damage) + "#o damage.";

			log.PushPop(line);
		}
	//Merchant: can add card that heals 1 hp and 1 mana, can heal
		else if (Name == "Merchant") {
			string line;

			if (TurnCount == 0) {
				if (type == 1) {
					string line2 = "#r-The Merchant prepares a #gbribe#r.#o";
					log.PushPop(line2);
				}
				else if (type == 2) {
					string line2 = "#r-The Merchant prepares a #gspell#r.#o";
					log.PushPop(line2);
				}
				else if (type == 3) {
					string line2 = "#r-The Merchant prepares some #gbait#r.#o";
					log.PushPop(line2);
				}
			}
			else if (CurrentHealth < 25) {
				//guard 60
				//drake 75
				//knight 60
				//soul 60
				//hellh 70
				//ele 100
				if (type == 1) {
					string line2 = "#r-The Merchant runs away with the bribe.#o";

					if (rand() % 2 == 0) {
						line = " A #rGuard#o takes their place!";

						Name = "Guard";
						MaxHealth = 60;
						CurrentHealth = MaxHealth;
					}
					else {
						line = " A #rKnight#o takes their place!";

						Name = "Guard";
						MaxHealth = 60;
						CurrentHealth = MaxHealth;
					}

					log.PushPop(line2);
				}
				else if (type == 2) {
					string line2 = "#r-The Merchant drops the spell and runs.#o";
					if (rand() % 2 == 0) {
						line = " A #rWeeping Soul#o takes its place!";

						Name = "Weeping Soul";
						MaxHealth = 60;
						CurrentHealth = MaxHealth;
					}
					else {
						line = " An #rElemental#o takes its place!";

						Name = "Elemental";
						MaxHealth = 100;
						CurrentHealth = MaxHealth;
					}

					log.PushPop(line2);
				}
				else if (type == 3) {
					string line2 = "#r-The Merchant drops the bait and runs.#o";
					if (rand() % 2 == 0) {
						line = " A #rDrake#o takes its place!";

						Name = "Drake";
						MaxHealth = 70;
						CurrentHealth = MaxHealth;
					}
					else {
						line = " A #rHellhound#o takes its place!";

						Name = "Hellhound";
						MaxHealth = 75;
						CurrentHealth = MaxHealth;
					}

					log.PushPop(line2);
				}
				manualBox("Display", 0);
				updateEnemy(guy);
			}
			else {
				int damage = rtd(2, 5);
				damage = guy.TakeDamage(damage);
				line = "-The Merchant stabs you for #r" + to_string(damage) + "#o damage.";
			}

			log.PushPop(line);
		}
	//Turret: high consant damage for a few rounds, rest for a couple
		else if (Name == "Turret") {
			string line;

			if (!charge) {
				int damage = rtd(13+td, 2);
				damage = guy.TakeDamage(damage);
				dot += rtd(1, 2);
				line = "-The Turret shoots you for #r" + to_string(damage) + "#o damage.";

				if (dot >= 3) {
					charge = TRUE;
				}
			}
			else {
				dot--;
				line = "#r-The Turret reloads.#o";
				if (dot == 0) {
					charge = FALSE;
				}
			}

			log.PushPop(line);
		}
//----------------Boss-----------------
	//Paladin: passive block, hits hard, heals
		else if (Name == "Paladin") {
			int block = gainBlock(tier*1.3, guy, log);
			string line2 = "-The Paladin gains #b" + to_string(block) + "#o block";
			log.PushPop(line2);

			string line;
			int rng = rand() % 3;
			if (rng == 0) {
				int roll = 1 + (tier / 2);
				int health = rtd(3, roll);
				heal(health, guy, log);
				line = "-The Paladin heals for #b" + to_string(health) + "#o health.";
			}
			else if (rng == 1) {
				int multi = tier * 1.25;
				int damage = rtd(3+multi, 2);
				damage = guy.TakeDamage(damage);
				int block = gainBlock(rtd(1+tier, 2), guy, log);
				line = "-The Paladin slices you for #r" + to_string(damage) + "#o damage and gains #b" + to_string(block) + "#o block.";
			}
			else {
				int multi = tier * 1.5;
				int damage = rtd(5+multi, 2);
				damage = guy.TakeDamage(damage);
				line = "-The Paladin bashes you for #r" + to_string(damage) + "#o damage.";
			}
			log.PushPop(line);
		}
	//Hunter: charges up with block to get multiple turns later
		else if (Name == "Hunter") {
			int rng = rand() % 10;
				if (extraTurns > 2 && (rng < 2 || CurrentHealth < MaxHealth/2)) {
					while (extraTurns > 0) {
						int damage = 9 + (1.5*tier);
						damage = guy.TakeDamage(damage);

						string line = "-The Hunter shoots you for #r" + to_string(damage) + "#o damage.";
						log.PushPop(line);
						extraTurns--;
					}
				}
				else if (rng >= 2 && rng < 5) {
					extraTurns++;
					string line = "#r-The Hunter loads an arrow.#o";
					log.PushPop(line);
				}
				else if (rng == 5 || rng == 6) {
					int block = gainBlock(rtd(2, tier), guy, log);
					extraTurns++;
					string line = "#r-The Hunter loads an arrow and gains #b" + to_string(block) + "#r block.#o";
					log.PushPop(line);
				}
				else {
					int block = gainBlock(rtd(2+tier, 2), guy, log);
					string line = "-The Hunter gains #b" + to_string(block) + "#o block.";
					log.PushPop(line);
				}
		}
	//Juggernaut: charges up with block for huge damage, turns leftover block into hp
		else if (Name == "Juggernaut") {
			string line;

			if (charge) {
				int multi = tier * 1.4;
				int damage = rtd(6+tier, 2);
				int damage2 = 0;
				damage2 += guy.TakeDamage(damage);
				damage2 += guy.TakeDamage(damage);
				line = "-The Juggernaut slams you #rtwice#o for a total of #r" + to_string(damage2) + "#o damage.";
				charge = FALSE;
			}
			else {
				int rng = rand() % 8;
				if (rng == 0 || rng == 1) {
					int block = gainBlock(5+tier, guy, log);
					charge = TRUE;
					line = "#r-The Juggernaut gains #b" + to_string(block) + "#r block and begins to wind up...#o";
				}
				else if (rng == 2 || rng == 3) {
					line = "-The Juggernaut rests for a turn.";
				}
				else {
					int block = gainBlock(rtd(2+tier, 2)-(tier*.5), guy, log);
					line = "-The Juggernaut gains #b" + to_string(block) + "#o block.";
				}
			}
			log.PushPop(line);

			if (CurrentHealth < MaxHealth && CurrentBlock > 0) {
				string line2;
				int healthNeeded = MaxHealth - CurrentHealth;
				if (CurrentBlock > healthNeeded) {
					CurrentBlock -= healthNeeded;
				}
				else {
					healthNeeded = CurrentBlock;
					CurrentBlock = 0;
				}
				heal(healthNeeded, guy, log);
				line2 = "#b The Juggernaut converts its block into " + to_string(healthNeeded) + " health.#o";
				log.PushPop(line2);
			}
		}
	//Vampire: can leech for unblocked damage, can go invisible to stop taking damage
		else if (Name == "Vampire") {
			string line;
			if (invisible > 0) {
				invisible--;
				if (invisible == 0) {
					if (CurrentHealth < MaxHealth/2 && CurrentBlock < 5+(4*tier)) {
						int multi = tier * 1.4;
						int damage = rtd(5+multi, 2);
						damage = guy.TakeDamage(damage);
						heal(damage, guy, log);
						line = "-The Vampire suddenly appears and #rsteals " + to_string(damage) + " health#o from you.";
					}
					else {
						int damage = rtd(2+tier, 2);
						damage = guy.TakeDamage(damage);
						line = "-The Vampire suddenly appears and bites you for #r" + to_string(damage) + "#o damage.";
					}
				}
				else {
					int rng = rand() % 4;
					if (rng == 0) {
						int block = gainBlock(rtd(tier, 2), guy, log);
						line = "-The Vampire gains #b" + to_string(block) + "#o block.";
					}
					else {
						int health = (tier*.6) + 4;
						heal(health, guy, log);
						line = "-The Vampire regenerates #b" + to_string(health) + "#o health.";
					}
				}
				
			}
			else{
				if (CurrentHealth < MaxHealth*.5) {
					int rng = rand() % CurrentHealth;
					if (rng < 6 && dot < 4) {
						invisible += rtd(1, 2);
						dot++;
						line = "#b-The Vampire turns invisible and becomes immune to direct damage.#o";
					}
					else {
						if (rand() % 2 == 0) {
							int damage = rtd(5, tier);
							damage = guy.TakeDamage(damage);
							line = "-The Vampire bites you for #r" + to_string(damage) + "#o damage.";
						}
						else {
							int damage = rtd(2+tier, 3);
							damage = guy.TakeDamage(damage);
							heal(damage, guy, log);
							line = "-The Vampire #rsteals " + to_string(damage) + " health#o from you.";
						}
					}
				}
				else {
					int rng = rand() % 4;
					if (rng == 0) {
						int damage = rtd(3+tier, 2);
						damage = guy.TakeDamage(damage);
						heal(damage, guy, log);
						line = "-The Vampire #rsteals " + to_string(damage) + " health#o from you.";
					}
					else if (rng == 1) {
						int block = gainBlock(rtd(tier*3, 2)+5, guy, log);
						line = "-The Vampire gains #b" + to_string(block) + "#o block.";
					}
					else {
						int damage = rtd(3+tier, 4);
						damage = guy.TakeDamage(damage);
						line = "-The Vampire bites you for #r" + to_string(damage) + "#o damage.";
					}
				}
			}
			log.PushPop(line);
		}
	//Druid: heals, short damage over time, rivial move
		else if (Name == "Druid") {
			int health = rtd(1, 2 + tier / 3) - 1;
			health = heal(health, guy, log);
			string regen = "-The Druid regenerates #b" + to_string(health) + "#o health.";
			if(health > 0)
				log.PushPop(regen);

			if (charge) {
				charge = FALSE;
				string rev = "#b-The revival failed.#o";
				log.PushPop(rev);
			}
			if (CurrentHealth < MaxHealth*.3 && TurnCount % 3 == 0) {
				string rev = "#r-The Druid prepares for revival.#o";
				log.PushPop(rev);
				charge = TRUE;
			}

			int rng = rand() % 4;
			if (rng == 0 && numA < 3) {
				string vines;
				if (numA == 0) {
					vines = "#r-The Druid summons roots from the ground.#o";
					numA += 2;
				}
				else {
					vines = "#r-The vines strangle you further.#o";
					numA += rtd(1, 2);
				}
				guy.dotDamage = 4 + (tier * 2);
				log.PushPop(vines);
			}
			else if (rng == 1) {
				int damage = guy.TakeDamage(rtd(2+(tier/5), 2+(tier/2)));
				heal(damage, guy, log);

				string line = "#b-The Druid saps #r" + to_string(damage) + "#b of your health.#o";
				log.PushPop(line);
			}
			else if (rng == 2) {
				int damage = guy.TakeDamage(rtd(1, 4) + tier);

				string line = "-The Druid zaps you for #r" + to_string(damage) + "#o damage.";
				log.PushPop(line);
			}
			else {
				int health = rtd(tier, 3);
				heal(health, guy, log);

				string line = "-The Druid heals for #b" + to_string(health) + "#o.";
				log.PushPop(line);
			}

			if (numA > 0) {
				numA--;
				if (numA == 0) {
					guy.dotDamage = 0;
					string vines = "#b-The roots release you.#o";
					log.PushPop(vines);
				}
			}
		}
	//Thief:
		else if (Name == "Thief") {

		}
	//Hydra: 1 turn at full hp, 2 turns at half, 3 turns at low
		else if (Name == "Hydra") {
			if (CurrentHealth > MaxHealth*2/3)
				extraTurns = 1;
			else if (CurrentHealth <= MaxHealth * 2 / 3 && CurrentHealth > MaxHealth / 3) {
				extraTurns = 2;
				if (!stepOne) {
					string line2 = "#r The Hydra's head falls off, growing 2 in its place.#o";
					log.PushPop(line2);
					stepOne = TRUE;
				}
			}
			else {
				extraTurns = 3;
				if (!stepTwo) {
					string line2 = "#r Another head falls off, growing 2 more.#o";
					log.PushPop(line2);
					stepTwo = TRUE;
				}
			}

			for (int i = 0; i < extraTurns; i++) {
				string line;
				int rng = rand() % 2;
				if (rng == 0) {
					int block = gainBlock(rtd(2, tier), guy, log);
					line = "-The Hydra gains #b" + to_string(block) + "#o block.";
				}
				else {
					int damage = rtd(3+tier, 2);
					damage = guy.TakeDamage(damage);
					line = "-The Hydra bites you for #r" + to_string(damage) +"#o damage.";
				}
				log.PushPop(line);
			}
		}
	//Wolf: causes damage over time, adds card to remove it
		else if (Name == "Wolf") {
			string line;

			if (TurnCount == 0) {
				guy.dotDamage += 1+tier;
				line = "#r-The Wolf tears your flesh, causing you to bleed out.#o";
			}
			else {
				int rng = rand() % 6;
				if (rng < 4 && guy.dotDamage >= 3+tier && !charge) {
					guy.ADDPatch++;
					charge = TRUE;
					line = "#b-The Wolf retreats for a turn.#o";
				}
				else if (rng < 3) {
					guy.dotDamage += rtd(1, tier);
					line = "#r-The Wolf tears your flesh, causing you to bleed out.#o";
				}
				else if (rng == 3 || rng == 4) {
					int block = gainBlock(rtd(1, 2+tier) + tier + 2, guy, log);
					line = "-The Wolf gains #b" + to_string(block) + "#o block.";
 				}
				else {
					int damage = rtd(1, 1+tier) + 2*tier;
					damage = guy.TakeDamage(damage);
					line = "-The Wolf bites you for #r" + to_string(damage) + "#o damage.";
				}
			}

			log.PushPop(line);
		}
	//Exorcist: adds cards that sap stats and deal damage over time
		else if (Name == "Exorcist") {
			string line;
			int rng = rand() % 6;
			//dot
			if (rng == 0) {
				line = "#r-The Exorcist puntures you, causing bleed.#o";
				if (type == 0) {
					guy.dotDamage += tier;
					if (tier == 1)
						guy.dotDamage++;
				}
				else {
					guy.dotDamage += 1;
				}
			}
			//card
			else if (rng > 0 && rng <= 2 && !charge) {
				line = "#r-The Exorcist begins to drain you.#o";
				if (type == 0) {
					guy.ADDDrain_Str++;
				}
				else if (type == 1) {
					guy.ADDDrain_Def++;
				}
				else if (type == 2){
					guy.ADDDrain_Int++;
				}
				charge = TRUE;
			}
			//block
			else if (rng > 2 && rng <= 4) {
				int block;
				if (type == 1) {
					block = rtd(4+tier, 2);
				}
				else {
					block = rtd(tier, 2) + 3;
				}
				block = gainBlock(block, guy, log);
				line = "-The Exorcist gains #b" + to_string(block) + "#o block.";
			}
			//attack
			else {
				int damage;
				if (type == 2) {
					damage = rtd(2+tier, 3) + 2;
				}
				else {
					damage = rtd(tier, 2) + 2;
				}
				damage = guy.TakeDamage(damage);
				line = "-The Exorcist stabs you for #r" + to_string(damage) + "#o damage.";
			}
			log.PushPop(line);
		}
	//Demigod: heals every turn, attack and block simultaneosly
		else if (Name == "Demigod") {
			string line;
			string line2;
			int rngpower = rand() % 9;
			if (rngpower < 2) {
				type += 1 + tier/3;
				line2 = "-The Demigod grows in power.";
			}
			else if (rngpower >= 2 && rngpower <= 5) {
				MaxHealth += type;
				line2 = "#b-The Demigod grows in power.#o";
			}
			else {
				dot += type;
				line2 = "#r-The Demigod grows in power.#o";
				if(type > 0)
					type--;
			}
			log.PushPop(line2);

			int rng = rand() % (4+type);

			if (rng == 0) {
				int multi = tier * 1.25;
				int health = rtd(type+multi, 2);
				heal(health, guy, log);
				line = "-The Demigod heals for #b" + to_string(health) + "#o health.";
			}
			else if (rng > 0 && rng < 3) {
				int block = gainBlock(rtd(6-type+tier, 2), guy, log);
				line = "-The Demigod gains #b" + to_string(block) + "#o block.";
			}
			else {
				int damage = dot;
				damage = guy.TakeDamage(damage);
				line = "-The Demigod slices you for #r" + to_string(damage) + "#o damage.";
			}
			log.PushPop(line);
		}
	//Serpent: attacks apply dot, constriction deals damage and reduces str and def temporarily
		else if (Name == "Serpent") {
			int rng = rand() % 11;

			if (numA > 0) {
				numA--;

				if (numA == 0) {
					guy.ModStat(numB, "Strength", TRUE);
					guy.ModStat(numB, "Defense", TRUE);
					numB = 0;

					string line = "#b-The Serpent relases you.#o";
					string line2 = "#b You regain your strength.#o";
					log.PushPop(line);
					log.PushPop(line2);
				}
				else {
					int damage = guy.TakeDamage(rtd(10, 1 + tier / 3));

					int mod = 2 + (tier * .4);
					guy.ModStat(-mod, "Strength", TRUE);
					guy.ModStat(-mod, "Defense", TRUE);
					numB += mod;

					string line = "-The Serpent constricts you, dealing #r" + to_string(damage) +
						"#o damage and removing #r" + to_string(mod) + " Strength#o and #r" + to_string(mod) + " Defense#o.";
					log.PushPop(line);
				}
			}
			else if (rng < 2 || TurnCount == 4 - (tier*.4)) {
				numA += 4;

				string line = "#r-The Serpent wraps itself around you.#o";
				log.PushPop(line);
			}
			else if (rng >= 2 && rng < 5) {
				int block = rtd(2, tier * 2) + 4;
				block = gainBlock(block, guy, log);

				string line = "-The Serpent gains #b" + to_string(block) + "#o block.";
				log.PushPop(line);
			}
			else {
				int damage = rtd(4, 1+tier) + 5;
				guy.dotDamage++;

				string line = "-The Serpent bites you for #r" + to_string(damage) + "#o and injects you with venom.";
				log.PushPop(line);
			}
		}
	//Spirit: attacks drain mana, negates, adds a Burn card which burns your next card
		else if (Name == "Spirit") {
			int rng = rand() % 7;
			if (rng == 0 || numA == 8) {
				numA = 0;
				guy.ADDBurn++;
				string line = "#r-The Spirit blazes.#o";
				log.PushPop(line);
			}
			else if (rng > 0 && rng <= 2 && enemyNegate == 0) {
				int neg = rtd(1, 2) + rtd(1, tier*.4);
				enemyNegate += neg;
				
				string line = "#b-The Spirit negates the next " + to_string(neg) + " hits.#o";
				log.PushPop(line);
			}
			else if (rng > 2 && rng <= 4) {
				int times = rtd(3, 1 + tier * .5);
				int times2 = times;
				int damage2 = 0;
				while (times2 > 0) {
					int damage = guy.TakeDamage(rtd(2, 2));
					damage2 += damage;
					guy.DrainMana(1);
					times2--;
				}
				string line = "-The Spirit burns you #r" + to_string(times) + " times#o, #mdraining " + to_string(times) + " mana#o and dealing a total of #r" + to_string(damage2) + "#o damage.";
				log.PushPop(line);
			}
			else {
				int damage = guy.TakeDamage((4, 3 + (tier*.5)));
				guy.DrainMana(1);

				string line = "-The Spirit burns you for #r" + to_string(damage) + "#o damage and #mdrains 1 of your mana#o.";
				log.PushPop(line);
			}
			numA++;
		}
	//Artificer: makes turrets which either deal damage or add steam
		else if (Name == "Artificer") {
			if (type == 0) {
				numA = rtd(1, 3);
				string line;
				if (numA == 1)
					line = "#b The Artificer places down a #rgun#b turret.#o";
				else if (numA == 2) {
					line = "#b The Artificer places down a #rsteam#b turret.#o";
					numF++;
				}
				else if (numA == 3) {
					line = "#b The Artificer places down a #rdefense#b turret.#o";
					numG++;
				}
				log.PushPop(line);
				type++;
			}
			else if (type == 1) {
				numB = rtd(1, 3);
				string line;
				if (numB == 1)
					line = "#b The Artificer places down a #rgun#b turret.#o";
				else if (numB == 2) {
					line = "#b The Artificer places down a #rsteam#b turret.#o";
					numF++;
				}
				else if (numB == 3) {
					line = "#b The Artificer places down a #rdefense#b turret.#o";
					numG++;
				}
				log.PushPop(line);
				type++;

			}
			else if (type == 2) {
				numC = rtd(1, 3);
				if (numG >= 2)
					numC = rtd(1, 2);

				string line;
				if (numC == 1)
					line = "#b The Artificer places down a #rgun#b turret.#o";
				else if (numC == 2) {
					line = "#b The Artificer places down a #rsteam#b turret.#o";
					numF++;
				}
				else if (numC == 3) {
					line = "#b The Artificer places down a #rdefense#b turret.#o";
					numG++;
				}
				log.PushPop(line);
				type++;
			}
			else if (type == 3) {
				numD = rtd(1, 3);
				if (numG >= 2)
					numD = rtd(1, 2);

				string line;
				if (numD == 1)
					line = "#b The Artificer places down a #rgun#b turret.#o";
				else if (numD == 2) {
					line = "#b The Artificer places down a #rsteam#b turret.#o";
					numF++;
				}
				else if (numD == 3) {
					line = "#b The Artificer places down a #rdefense#b turret.#o";
					numG++;
				}
				log.PushPop(line);
				type++;
			}
			else {
				int rng = rand() % 5;
				string line;
				if (rng < 2) {
					int hp = rtd(1, tier);
					hp = heal(hp, guy, log);
					line = "-The Artificer heals for #b" + to_string(hp) + "#o.";
				}
				else {
					int damage = guy.TakeDamage(rtd(2, tier)-1);
					line = "-The Artificer zaps you for #r" + to_string(damage) + "#o damage.";
				}
				log.PushPop(line);
			}

			if (numA == 1) {
				string line;
				if (rand() % 4 == 0) {
					line = " Turret A #breloads.#o";
				}
				else {
					int damage = guy.TakeDamage(rtd(3, 2 + tier/3));
					line = " Turret A shoots you for #r" + to_string(damage) + "#o damage.";
				}
				log.PushPop(line);
			}
			else if (numA == 2) {
				string line;
				int r = rand() % 5;
				if (r == 0 && tier > 2 && numE < numF*(1+(tier*.25))) {
					guy.ADDScalding_Steam++;
					line = " Turret A #rreleases some steam.#o";
					numE++;
				}
				else if (r > 0 && r <= 3 && dot < numF*(1 + tier)) {
					guy.ADDSteam++;
					line = " Turret A #rreleases some steam.#o";
					dot++;
				}
				else {
					int damage = guy.TakeDamage(rtd(1, tier));
					line = " Turret A deals #r" + to_string(damage) + "#o steam damage.";
				}
				log.PushPop(line);
			}
			else if (numA == 3) {
				string line;
				if (rand() % (20 - 2*tier) == 0) {
					enemyNegate++;
					line = " Turret A #bnegates the next hit.#o";
				}
				else {
					int block = gainBlock(rtd(2, 1 + (tier*.4)) + tier*.35, guy, log);
					line = " Turret A gains #b" + to_string(block) + "#o block.";
				}
				log.PushPop(line);
			}
		
			if (numB == 1) {
				string line;
				if (rand() % 4 == 0) {
					line = " Turret B #breloads.#o";
				}
				else {
					int damage = guy.TakeDamage(rtd(3, 2 + tier/3));
					line = " Turret B shoots you for #r" + to_string(damage) + "#o damage.";
				}
				log.PushPop(line);
			}
			else if (numB == 2) {
				string line;
				int r = rand() % 5;
				if (r == 0 && tier > 2 && numE < numF*(1 + (tier*.25))) {
					guy.ADDScalding_Steam++;
					line = " Turret B #rreleases some steam.#o";
					numE++;
				}
				else if (r > 0 && r <= 3 && dot < numF*(1 + tier)) {
					guy.ADDSteam++;
					line = " Turret B #rreleases some steam.#o";
					dot++;
				}
				else {
					int damage = guy.TakeDamage(rtd(1, tier));
					line = " Turret B deals #r" + to_string(damage) + "#o steam damage.";
				}
				log.PushPop(line);
			}
			else if (numB == 3) {
				string line;
				if (rand() % (20 - 2*tier) == 0) {
					enemyNegate++;
					line = " Turret B #bnegates the next hit.#o";
				}
				else {
					int block = gainBlock(rtd(2, 1 + (tier*.4)) + tier * .35, guy, log);
					line = " Turret B gains #b" + to_string(block) + "#o block.";
				}
				log.PushPop(line);
			}
		
			if (numC == 1) {
				string line;
				if (rand() % 4 == 0) {
					line = " Turret C #breloads.#o";
				}
				else {
					int damage = guy.TakeDamage(rtd(3, 2 + tier/3));
					line = " Turret C shoots you for #r" + to_string(damage) + "#o damage.";
				}
				log.PushPop(line);
			}
			else if (numC == 2) {
				string line;
				int r = rand() % 5;
				if (r == 0 && tier > 2 && numE < numF*(1 + (tier*.25))) {
					guy.ADDScalding_Steam++;
					line = " Turret C #rreleases some steam.#o";
					numE++;
				}
				else if (r > 0 && r <= 3 && dot < numF*(1 + tier)) {
					guy.ADDSteam++;
					line = " Turret C #rreleases some steam.#o";
					dot++;
				}
				else {
					int damage = guy.TakeDamage(rtd(1, tier));
					line = " Turret C deals #r" + to_string(damage) + "#o steam damage.";
				}
				log.PushPop(line);
			}
			else if (numC == 3) {
				string line;
				if (rand() % (20 - 2*tier) == 0) {
					enemyNegate++;
					line = " Turret C #bnegates the next hit.#o";
				}
				else {
					int block = gainBlock(rtd(2, 1 + (tier*.4)) + tier * .35, guy, log);
					line = " Turret C gains #b" + to_string(block) + "#o block.";
				}
				log.PushPop(line);
			}

			if (numD == 1) {
				string line;
				if (rand() % 4 == 0) {
					line = " Turret D #breloads.#o";
				}
				else {
					int damage = guy.TakeDamage(rtd(3, 2 + tier/3));
					line = " Turret D shoots you for #r" + to_string(damage) + "#o damage.";
				}
				log.PushPop(line);
			}
			else if (numD == 2) {
				string line;
				int r = rand() % 5;
				if (r == 0 && tier > 2 && numE < numF*(1 + (tier*.25))) {
					guy.ADDScalding_Steam++;
					line = " Turret D #rreleases some steam.#o";
					numE++;
				}
				else if (r > 0 && r <= 3 && dot < numF*(1 + tier)) {
					guy.ADDSteam++;
					line = " Turret D #rreleases some steam.#o";
					dot++;
				}
				else {
					int damage = guy.TakeDamage(rtd(1, tier));
					line = " Turret D deals #r" + to_string(damage) + "#o steam damage.";
				}
				log.PushPop(line);
			}
			else if (numD == 3) {
				string line;
				if (rand() % (20 - 2*tier) == 0) {
					enemyNegate++;
					line = " Turret D #bnegates the next hit.#o";
				}
				else {
					int block = gainBlock(rtd(2, 1 + (tier*.4)) + tier * .35, guy, log);
					line = " Turret D gains #b" + to_string(block) + "#o block.";
				}
				log.PushPop(line);
			}
		}
//-------------Final Boss--------------
	//Dragon: can charge up multiple turns up for big attacks, flaps wings to shuffle deck, damage over time
		else if (Name == "Dragon") {
			/*
			3 attack
			4 block
			1 dot
			1 charge
			1 shuffle
			1 all block removed
			*/
			string line;
			if (dot > 0) {
				int rng = rand() % 9;
				if (!charge) {
					if (rng < 5 && dot < 6) {
						dot++;
						line = "#r-The Dragon inhales...#o";
					}
					else {
						charge = TRUE;
						//type = rtd(17, 2);
					}
				}
				if (charge) {
					int damage = rtd(1, 11) + 24;
					damage = guy.TakeDamage(damage);
					line = "-The Dragon blasts flames at you for #r" + to_string(damage) + "#o damage.";
					dot--;
					if (dot == 0)
						charge = FALSE;
				}
			}
			else {
				int rng = rand() % 11;
				if (rng == 0) {
					guy.shuffle = TRUE;
					string line2 = "#b-The Dragon flaps its wings and causes a gust.#b";
					line = "#b Your hand has been shuffled.#o";
					log.PushPop(line2);
				}
				else if (rng == 1) {
					dot++;
					line = "#r-The Dragon inhales...#o";
				}
				else if (rng == 2 && guy.CurrentBlock > 0) {
					if (rand() % 2 == 0) {
						guy.CurrentBlock = 0;
						CurrentBlock = 0;
						line = "#b-The Dragon incinerates all the block on the field.#o";
					}
					else {
						dot++;
						line = "#r-The Dragon inhales...#o";
					}
				}
				else if (rng == 3 && guy.dotDamage < 6) {
					guy.dotDamage += 2;
					line = "#r-The Dragon scorches you, causing you to burn.#o";
				}
				else if (rng > 3 && rng <= 7) {
					int block = gainBlock(rtd(5, 6), guy, log);
					line = "-The Dragon gains #b" + to_string(block) + "#o block.";
				}
				else {
					int damage = rtd(7, 3);
					damage = guy.TakeDamage(damage);
					line = "-The Dragon claws you for #r" + to_string(damage) + "#o damage.";
				}
			}
			log.PushPop(line);
		}
	//King: tons of block, can lose all block to hit you with it, can lose all block to heal with it
		else if (Name == "King") {
			string line;
			int rng = rand() % 7;
			if (rng == 0) {
				int damage = rtd(3, 2);
				damage = guy.TakeDamage(damage);
				damage = guy.TakeDamage(damage);
				line = "-The King slashes you twice for #r" + to_string(damage) + "#o damage each.";
			}
			else if (rng == 1) {
				int block = gainBlock(rtd(25, 3), guy, log);
				line = "-The King gains #b" + to_string(block) + "#o block.";
			}
			else if (rng == 2) {
				if (CurrentHealth < rtd(30, 3) && CurrentBlock > 0) {
					int health = CurrentBlock;
					heal(health, guy, log);
					CurrentBlock = 0;
					line = "-The King uses his #bblock to heal#o for #b" + to_string(health) + "#o health.";
				}
				else {
					int block = gainBlock(rtd(5, 5), guy, log);
					line = "-The King gains #b" + to_string(block) + "#o block.";
				}
			}
			else if (rng == 3) {
				if (CurrentBlock > rtd(15, 2)) {
					int damage = CurrentBlock;
					damage = guy.TakeDamage(damage);
					CurrentBlock = 0;
					line = "-The King crushes you for #r" + to_string(damage) + "#o damage and #bloses all his block.#o";
				}
				else {
					int block = gainBlock(rtd(10, 3), guy, log);
					line = "-The King gains #b" + to_string(block) + "#o block.";
				}
			}
			else if (rng == 4) {
				enemyNegate++;
				line = "#b-The King negates the next hit taken.#o";
			}
			else {
				int block = gainBlock(rtd(3, 10), guy, log);
				line = "-The King gains #r" + to_string(block) + "#o block.";
			}
			log.PushPop(line);
		}
	//Witch: saps stats including max, adds cards to sap stats, can go invisible to not take damage
		else if (Name == "Witch") {
			string line;

			if (invisible > 0) {
				invisible--;
				int health = rtd(1, 7) + 9;
				heal(health, guy, log);
				line = "-The Witch regenerates #b" + to_string(health) + "#o health.";
			}
			else {
				int rng = rand() % 9;
				if (TurnCount < 3) {
					int block = gainBlock(rtd(12, 2), guy, log);

					if (guy.Strength > guy.Defense && guy.Strength > guy.Intelligence)
						dot = 1;
					else if (guy.Defense > guy.Strength && guy.Defense > guy.Intelligence)
						dot = 2;
					else if (guy.Intelligence > guy.Strength && guy.Intelligence > guy.Defense)
						dot = 3;
					else if (guy.Defense == guy.Strength && guy.Strength > guy.Intelligence)
						dot = 4;
					else if (guy.Intelligence == guy.Strength && guy.Intelligence > guy.Defense)
						dot = 5;
					else if (guy.Defense == guy.Intelligence && guy.Defense > guy.Strength)
						dot = 6;

					if (dot == 0) {
						if (TurnCount == 0) {
							guy.ADDDrain_Str++;
						}
						else if (TurnCount == 1) {
							guy.ADDDrain_Def++;
						}
						else if (TurnCount == 2) {
							guy.ADDDrain_Int++;
						}
					}
					else if (dot == 1 || dot == 4) {
						if (TurnCount == 0) {
							guy.ADDDrain_Str++;
						}
						else if (TurnCount == 1) {
							guy.ADDDrain_Def++;
						}
						else if (TurnCount == 2) {
							guy.ADDDrain_Str++;
						}
					}
					else if (dot == 2) {
						if (TurnCount == 0) {
							guy.ADDDrain_Def++;
						}
						else if (TurnCount == 1) {
							guy.ADDDrain_Str++;
						}
						else if (TurnCount == 2) {
							guy.ADDDrain_Def++;
						}
					}
					else if (dot == 3) {
						if (TurnCount == 0) {
							guy.ADDDrain_Int++;
						}
						else if (TurnCount == 1) {
							guy.ADDDrain_Def++;
						}
						else if (TurnCount == 2) {
							guy.ADDDrain_Int++;
						}
					}
					else if (dot == 5) {
						if (TurnCount == 0) {
							guy.ADDDrain_Str++;
						}
						else if (TurnCount == 1) {
							guy.ADDDrain_Int++;
						}
						else if (TurnCount == 2) {
							guy.ADDDrain_Str++;
						}
					}
					else if (dot == 6) {
						if (TurnCount == 0) {
							guy.ADDDrain_Def++;
						}
						else if (TurnCount == 1) {
							guy.ADDDrain_Int++;
						}
						else if (TurnCount == 2) {
							guy.ADDDrain_Def++;
						}
					}
					
					line = "-The Witch gains #b" + to_string(block) + "#o block.";
					string line2 = "#r-The Witch chants.#o";
					log.PushPop(line2);
				}
				else if (TurnCount == 3) {
					guy.fillType = "Negative";
					line = "#r-The Witch curses you.#o";
				}
				else if (TurnCount % 15 == 0) {
					guy.fillType = "Negative";
					line = "#r-The Witch curses you.#o";
				}
				else if (rng == 0 || (type < 3 && CurrentHealth < 50)) {
					invisible += rtd(1, 2);
					if (rand() % 5 == 0 && invisible == 2)
						invisible++;

					line = "#b-The Witch turns invisible and becomes immune to direct damage.#o";
					type++;
				}
				else if (rng == 1 && guy.MaxHealth > 15) {
					int drain = rtd(4, 2);
					guy.ModStat(-drain, "MaxHealth", TRUE);
					if (guy.CurrentHealth > guy.MaxHealth && !guy.Engorged) {
						guy.CurrentHealth = guy.MaxHealth;
					}
					line = "-The Witch #rdrains " + to_string(drain) + " of your max health.#o";
				}
				else if (rng == 2 && guy.MaxMana > 8) {
					guy.ModStat(-1, "MaxMana", TRUE);
					if (guy.CurrentMana > guy.MaxMana && !guy.Enlightened) {
						guy.CurrentMana = guy.MaxMana;
					}
					line = "-The Witch #rdrains 2 of your max mana.#o";
				}
				else if (rng == 3) {
					guy.fillType = "Negative";
					line = "#r-The Witch curses you.#o";
				}
				else if (rng == 4 && !stepOne) {
					switch (dot) {
					case 0:
						guy.ADDDrain_Def++;
						break;
					case 1:
						guy.ADDDrain_Int++;
						break;
					case 2:
						guy.ADDDrain_Int++;
						break;
					case 3:
						guy.ADDDrain_Str++;
						break;
					case 4:
						guy.ADDDrain_Int++;
						break;
					case 5:
						guy.ADDDrain_Def++;
						break;
					case 6:
						guy.ADDDrain_Str++;
						break;
					}
					stepOne = TRUE;
					line = "#r-The Witch chants under her breath.#o";
				}
				else if (rng >= 5 && rng < 8) {
				int block = gainBlock(rtd(4, 6), guy, log);
					line = "-The Witch gains #b" + to_string(block) + "#o block.";
				}
				else {
					int damage = rtd(8, 2);
					damage = guy.TakeDamage(damage);

					line = "-The Witch stabs you for #r" + to_string(damage) + "#o damage.";
				}
			}

			log.PushPop(line);
			if (TurnCount > 2 && rand() % 2 == 0) {
				int damage = rtd(5, 2);
				damage = guy.TakeDamage(damage);

				string line3 = "-The Witch zaps you for #r" + to_string(damage) + "#o damage.";
				log.PushPop(line3);
			}
			if (TurnCount > 2 && rand() % 3 == 0) {
				int damage = rtd(5, 2);
				damage = guy.TakeDamage(damage);

				string line3 = "-The Witch zaps you for #r" + to_string(damage) + "#o damage.";
				log.PushPop(line3);
			}
		}
	//Demon: can pierce block, damage over time, leech
		else if (Name == "Demon") {
			if (stepOne) {
				stepOne = FALSE;
				guy.ModStat(8, "Defense", TRUE);
				string line = "-You regain your composure.";
				log.PushPop(line);
			}

			if (charge) {
				if (type > 3 && rand() % 9 < 5) {
					//guy.dotDamage -= 6;
					guy.dotDamage /= 3;

					type = 0;
					charge = FALSE;

					string line = "#b-The Demon stops channeling.#o";
					log.PushPop(line);
				}
				else
					type++;
			}
			else {
				string line;
				int rng = rand() % 8;
				if ((CurrentHealth < 100 && rng < 3) || CurrentHealth < 30) {
					guy.dotDamage *= 3;
					//guy.dotDamage += 6;

					charge = TRUE;
					line = "#r-The Demon slams the ground and begins to channel.#o";
				}
				else if (guy.dotDamage == 0) {
					guy.dotDamage += 3;
					line = "#r-The Demon points at you. You begin to waste away.#o";
				}
				else if ((rng == 0 || rng == 1) && guy.dotDamage < 5+td) {
					guy.dotDamage+=2;
					line = "#r-The Demon points at you. You rot further.#o";
				}
				else if ((rng == 2 || rng == 3) && guy.CurrentHealth > 1) {
					int damage;
					if (guy.CurrentHealth <= 20)
						damage = rtd(1, guy.CurrentHealth - 1);
					else
						damage = rtd(10, 2);

					guy.pierce = TRUE;
					damage = guy.TakeDamage(damage);
					line = "-The Demon #rpierces#o your block for #r" + to_string(damage) + "#o damage.";
				}
				else if (rng == 4) {
					guy.ModStat(-8, "Defense", TRUE);
					guy.fillType = "Defend";
					string line2 = "#b The Demon stares into your eyes.#o";
					log.PushPop(line2);
					line = "#b-You panic, #rlosing 8 Defense#b and filling your hand with Defends.#o";
					if(!guy.Purple)
						stepOne = TRUE;
				}
				else if (rng == 5) {
					int block = gainBlock(rtd(15, 2), guy, log);
					line = "-The Demon gains #b" + to_string(block) + "#o block.";
				}
				else {
					int damage = rtd(5, 2) + 7;
					guy.TakeDamage(damage);
					line = "-The Demon spears you for #r" + to_string(damage) + "#o damage.";
				}

				log.PushPop(line);
			}
		}
	//Machine: regen, adds cards that damage and give extra turn, gets more powerful at lower health but loses its maxhealth sometimes
		else if (Name == "Machine") {
			if (CurrentHealth < MaxHealth) {
				int health = 5-type;
				heal(health, guy, log);
				string line2 = "-The Machine repairs itself for #b" + to_string(health) + "#o health.";
				log.PushPop(line2);
			}
			if (charge) {
				int damage = rtd(14, 2);
				damage = guy.TakeDamage(damage);
				string line2 = "-The turrets shoot you for #r" + to_string(damage) + "#o damage.";
				log.PushPop(line2);
				if (rand() % 8 == 0) {
					extraTurns /= 4;
				}
			}

			string line;
			if (extraTurns == 0) {
				guy.ADDScalding_Steam++;
				line = "#r-The Machine expels clouds of steam.#o";
				extraTurns+=5;
			}
			else {
				int rngsteam = rand() % extraTurns;
				if (CurrentHealth <= dot && !stepOne) {
					type += 2;
					MaxHealth = dot;
					line = "#b A chunk of the machine is no longer in operation.#o";
					extraTurns /= 2;
					stepOne = TRUE;
				}
				else if (CurrentHealth <= numA && !stepTwo) {
					type += 2;
					MaxHealth = numA;
					charge = TRUE;
					string line2 = "#b Another chunk of the machine is no longer in operation.#o";
					line = "#r Two emergency turrets extend from the Machine.#o";
					log.PushPop(line2);
					stepTwo = TRUE;
				}
				else if (rngsteam == 0 && extraTurns < 40) {
					guy.ADDScalding_Steam++;
					line = "#r-The Machine expels clouds of steam.#o";
					extraTurns *= 2;
				}
				else {
					int block = gainBlock(rtd(4, 2+type), guy, log);
					line = "-The Machine gains #b" + to_string(block) + "#o block.";
				}
			}
			log.PushPop(line);

		}

		//Horrify
		if (guy.horrify > 0) {
			guy.horrify--;
			if (guy.horrify == 0) {
				string line = "#m-The " + string(Name) + "'s fear wears off.#o";
				log.PushPop(line);
			}
		}
		//Spiny Skin trait
		if (guy.Spiny_Skin && guy.SpinyDamage > 0) {
			takeDamage(guy.SpinyDamage, guy, log);
			string spine = "-Your spines damage the " + string(Name) + " for #y" + to_string(guy.SpinyDamage) + "#o damage.";
			log.PushPop(spine);
			guy.SpinyDamage = 0;
		}
		//Charm
		if (guy.mirror > 0 && guy.mirrorDamage > 0) {
			guy.mirror--;
			int damage = guy.mirrorDamage;
			takeDamage(damage, guy, log);
			string line = "#m-You charm the " + string(Name) + " to take #y" + to_string(damage) + "#m damage.#o";
			log.PushPop(line);
			guy.mirrorDamage = 0;
		}
		//Attract
		if (guy.charge > 0 && guy.chargeMana > 0) {
			guy.charge--;
			int mana = guy.chargeMana;
			guy.DrainMana(-1 * mana);
			string line = "#m-You gain " + to_string(mana) + " mana.#o";
			log.PushPop(line);
			guy.chargeMana = 0;
		}
		//Entomb
		if (guy.entomb > 0) {
			guy.entomb--;
		}
		//Inefficient trait
		if (guy.Inefficient == 1) {
			guy.Inefficient = 0;
			TurnCount++;
			Turn(guy, log);
		}
		//Reaper trait
		if (guy.Reaper && CurrentHealth < 5 + (2 * guy.Skill)) {
			CurrentHealth = 0;
			string reap = "#r You kill the " + string(Name) + ".#o";
			//log.PushPop(reap);
		}
	}
	if (guy.CurrentHealth <= 0) {
		//Rebirth trait
		if (guy.Rebirth && guy.MaxHealth <= 0) {
			guy.MaxHealth = 40;
			guy.CurrentHealth = guy.MaxHealth;
			guy.hpMod = 0;
		}
		//Save card
		if (guy.save > 0 && guy.MaxHealth > 0) {
			guy.CurrentHealth = guy.MaxHealth;
			string sv = "#g-You come back to life!#o";
			log.PushPop(sv);
		}
		//Absorption Trait
		if (guy.Absorption == 1 && guy.CurrentHealth <= 0) {
			int damage = rtd(guy.Skill, 3);
			damage = takeDamage(damage, guy, log);
			string absorb1 = "-You deal #g" + to_string(damage) + "#o damage.";
			log.PushPop(absorb1);
			guy.Absorption = 0;
			if (CurrentHealth <= 0) {
				string absorb2 = "#g-You absorb the " + string(Name) + " and remain alive.#o";
				log.PushPop(absorb2);
				guy.CurrentHealth = 1;
				guy.Alive = TRUE;
				guy.Absorption = 1;
			}
			guy.printStats();
			updateEnemy(guy);
		}
		//Reconstruction Trait
		if (guy.Reconstruction && guy.Skill > 1 && guy.CurrentHealth <= 0) {
			guy.restoreStats();
			guy.CurrentHealth = guy.MaxHealth;
			guy.ModStat(-2, "Skill", FALSE);
			string recon = "#g You come back to life!#o";
			log.PushPop(recon);
			if (guy.Absorption == 0)
				guy.Absorption++;
		}
		if (guy.CurrentHealth <= 0)
			guy.Alive = FALSE;
	}

	TurnCount++;
}

void Enemy::ActivateDOT(Character &guy, TextLog &log) {
	if (guy.dotDamage > 0) {
		string line;
		int damage = guy.TakeDamage(guy.dotDamage);

		if (Name == "Hound" || Name == "Exorcist" || Name == "Wolf") {
			line = "-You bleed for #r" + to_string(damage) + "#o damage.";
		}
		else if (Name == "Brown Recluse" || Name == "Serpent") {
			line = "-You take #r" + to_string(damage) + "#o venom damage.";
		}
		else if (Name == "Elemental") {
			line = "-You take #r" + to_string(damage) + "#o poison damage.";
		}
		else if (Name == "Dragon" || Name == "Molten Jelly") {
			line = "-You burn for #r" + to_string(damage) + "#o damage.";
		}
		else if (Name == "Demon" || Name == "Imp" || Name == "Brain" || Name == "Hellhound") {
			if (charge) {
				heal(damage, guy, log);
				line = "-The " + string(Name) + " #rsteals " + to_string(damage) + " of your health#o. ";
			}
			else
				line = "-You waste for #r" + to_string(damage) + "#o damage.";
		}
		else if (Name == "Druid") {
			line = "-The roots strangle you for #r" + to_string(damage) + "#o damage.";
		}
		else {
			line = "-You take #r" + to_string(damage) + "#o damage.";
		}

		guy.SpinyDamage = 0;
		log.PushPop(line);

		if (guy.CurrentHealth <= 0) {
			//Rebirth trait
			if (guy.Rebirth && guy.MaxHealth <= 0) {
				guy.MaxHealth = 40;
				guy.CurrentHealth = guy.MaxHealth;
				guy.hpMod = 0;
			}
			//Save card
			if (guy.save > 0 && guy.MaxHealth > 0) {
				guy.CurrentHealth = guy.MaxHealth;
				string sv = "#g-You come back to life!#o";
				log.PushPop(sv);
			}
			//Absorption Trait
			if (guy.Absorption == 1 && guy.CurrentHealth <= 0) {
				int damage = rtd(guy.Skill, 3);
				damage = takeDamage(damage, guy, log);
				string absorb1 = "-You deal #g" + to_string(damage) + "#o damage.";
				log.PushPop(absorb1);
				guy.Absorption = 0;
				if (CurrentHealth <= 0) {
					string absorb2 = "#g-You absorb the " + string(Name) + " and remain alive.#o";
					log.PushPop(absorb2);
					guy.CurrentHealth = 1;
					guy.Alive = TRUE;
					guy.Absorption = 1;
				}
				guy.printStats();
				updateEnemy(guy);
			}
			//Reconstruction Trait
			if (guy.Reconstruction && guy.Skill > 1 && guy.CurrentHealth <= 0) {
				guy.CurrentHealth = guy.MaxHealth;
				guy.ModStat(-2, "Skill", FALSE);
				string recon = "#g You come back to life!#o";
				log.PushPop(recon);
				if (guy.Absorption == 0)
					guy.Absorption++;
			}
			if (guy.CurrentHealth <= 0)
				guy.Alive = FALSE;
		}
	}
}

int Enemy::takeDamage(int damage, Character &guy, TextLog &log) {
	int damage2 = damage;
	if (damage > 0 && guy.Frenzy) {
		damage2 *= 2;
	}
	if (damage < 0) {
		damage2 = 0;
	}
	if (enemyNegate > 0) {
		damage2 = 0;
		enemyNegate--;
	}
	if (guy.pierce) {
		CurrentHealth -= damage2;
		guy.pierce = FALSE;
	}

	else {
		if (CurrentBlock > damage2)
			CurrentBlock -= damage2;
		else {
			damage2 -= CurrentBlock;
			CurrentHealth -= damage2;
			CurrentBlock = 0;
		}
	}
	/*if (guy.damageToMana > 0) {
		int mana = damage2 - CurrentBlock;
		if (mana < 0)
			mana = 0;
		guy.DrainMana(-1 * mana);
		guy.damageToMana = 0;
		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		log.PushPop(line);
	}*/

	//Reaper trait
	if (guy.Reaper && CurrentHealth < 5 + (2 * guy.Skill)) {
		CurrentHealth = 0;
		string reap = "#r You kill the " + string(Name) + ".#o";
		//log.PushPop(reap);
	}

	return damage2;
	updateEnemy(guy);
}

int Enemy::gainBlock(int block, Character &guy, TextLog &log) {
	if (guy.horrify > 0)
		block = 0;
	CurrentBlock += block;
	if (CurrentBlock > 999)
		CurrentBlock = 999;
	return block;
}


//stat changes
int Enemy::heal(int health, Character &guy, TextLog &log) {
	if (guy.horrify > 0)
		health = 0;
	if ((MaxHealth - CurrentHealth) < health) {
		CurrentHealth = MaxHealth;
	}
	else {
		CurrentHealth += health;
	}
	return health;
}

void Enemy::initNegotiateLines() {
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

	1 boss
	5 boss

	Merchant (2 Gear, 1 Skill)
	Jester
	*/
	you1 = "Hey";
	if (Name == "Rat") {
		negotiate1 = "What";
		you2 = "I don't want to fight";
		negotiate2 = "Then give me #r2 of your Strength#o";
		you3 = "Ok sure";
		price = "2 Strength";
	}
	else if (Name == "Crab") {
		negotiate1 = "Huh";
		you2 = "Stop pinching me";
		negotiate2 = "Then give me #b1 piece of Gear#o";
		you3 = "Ok sure";
		price = "1 Gear";
	}
	else if (Name == "Kobold") {
		negotiate1 = "What";
		you2 = "I don't want to fight you";
		negotiate2 = "Then give me #$5 gold#o";
		you3 = "Ok sure";
		price = "5 gold";
	}
	else if (Name == "Zombie") {
		negotiate1 = "...";
		you2 = "What do you want";
		negotiate2 = "...#rMax Health#o...#r3#o";
		you3 = "Here";
		price = "3 MaxHealth";
	}
	else if (Name == "Hound") {
		negotiate1 = "Woof";
		you2 = "I don't want to fight you";
		negotiate2 = "Give me #r3 Max Health#o please";
		you3 = "Here";
		price = "3 MaxHealth";
	}
	//-----------------Mid-----------------
	else if (Name == "Giant Rat") {
		negotiate1 = "What";
		you2 = "I don't want to fight";
		negotiate2 = "Then give me #r8 of your Strength#o";
		you3 = "Ok sure";
		price = "8 Strength";
	}
	else if (Name == "Wild Buffalo") {
		negotiate1 = "*grunts*";
		you2 = "Don't hurt me";
		negotiate2 = "Fine, then give me #b2 pieces of Gear#o";
		you3 = "Ok thanks";
		price = "2 Gear";
	}
	else if (Name == "Harpy") {
		negotiate1 = "What??";
		you2 = "I don't want to fight";
		negotiate2 = "Then give me #r1 of your Skill#o";
		you3 = "Ok";
		price = "1 Skill";
	}
	else if (Name == "Brown Recluse") {
		negotiate1 = "Hsss";
		you2 = "I don't want to fight";
		negotiate2 = "Give me #$10 gold#o and I won't kill you";
		you3 = "Ok sure";
		price = "10 gold";
	}
	else if (Name == "Fairy") {
		negotiate1 = "Yea?";
		you2 = "I don't want to fight";
		negotiate2 = "Then give me #r5 Max Mana#o.";
		you3 = "Ok";
		price = "5 MaxMana";
	}
	//----------------High-----------------
	else if (Name == "Elemental") {
		negotiate1 = "What, mortal?";
		you2 = "I don't want to fight";
		negotiate2 = "Hmph, then give me #r2 of your Skill#o.";
		you3 = "Ok";
		price = "2 Skill";
	}
	else if (Name == "Adventurer") {
		negotiate1 = "Yea?";
		you2 = "I don't want to fight you";
		negotiate2 = "Can I have #$15 gold#o then?";
		you3 = "Sure";
		price = "15 gold";
	}
	else if (Name == "Troll") {
		negotiate1 = "What, prey?";
		you2 = "I don't want to fight";
		negotiate2 = "I hunger. Give me #r8 of your Max Health#o";
		you3 = "Alright";
		price = "8 MaxHealth";
	}
	//---------------Themed----------------
		//------Dragon:
	else if (Name == "Hatchling") {
		negotiate1 = "What?";
		you2 = "I don't want to fight";
		negotiate2 = "I am vulnerable. Give me #r3 of your Defense#o";
		you3 = "Ok";
		price = "3 Defense";
	}
	else if (Name == "Molten Jelly") {
		negotiate1 = "...";
		you2 = "Let's not fight";
		negotiate2 = "Feed me #b2 pieces of Gear#o";
		you3 = "Sure";
		price = "2 Gear";
	}
	else if (Name == "Knight") {
		negotiate1 = "What";
		you2 = "I don't want to fight";
		negotiate2 = "Can I have #b3 pieces of Gear#o then?";
		you3 = "Sure";
		price = "2 Gear";
	}
	else if (Name == "Drake") {
		negotiate1 = "What is it?";
		you2 = "I don't want to fight";
		negotiate2 = "Hmm, then give me #$15 gold#o.";
		you3 = "Ok";
		price = "15 gold";
	}
	//------King:
	else if (Name == "Slave") {
		negotiate1 = "Yea";
		you2 = "I don't want to fight";
		negotiate2 = "I want #b1 piece of Gear#o";
		you3 = "Ok here";
		price = "1 Gear";
	}
	else if (Name == "Soldier") {
		negotiate1 = "What";
		you2 = "I don't want to fight";
		negotiate2 = "Give me #$10 gold#o, then.";
		you3 = "Ok";
		price = "10 gold";
	}
	else if (Name == "Guard") {
		negotiate1 = "What do you want?";
		you2 = "I wish to pass";
		negotiate2 = "The King demands #r2 of your Skill#o.";
		you3 = "Ok";
		price = "3 Gear";
	}
	else if (Name == "Jester") {
		negotiate1 = "Hmmm, what is it?";
		you2 = "I don't want to fight";
		negotiate2 = "Then let me #rmess with your stats#o a bit, eh?";
		you3 = "Alright";
		price = "Jester";
	}
	//------Witch:
	else if (Name == "Eyeball") {
		negotiate1 = "...";
		you2 = "I don't want to fight";
		negotiate2 = "#r(3 Max Health)#o";
		you3 = "Here";
		price = "3 MaxHealth";
	}
	else if (Name == "Apprentice") {
		negotiate1 = "What";
		you2 = "I don't want to fight";
		negotiate2 = "Then give me #r3 of your Intelligence#o to make me more powerful.";
		you3 = "Ok";
		price = "3 Intelligence";
	}
	else if (Name == "Monster") {
		negotiate1 = "*grunting and popping noises*";
		you2 = "Uhh...Can we stop fighting please?";
		negotiate2 = "Hungrrryy...#r8 of your Max Health#o";
		you3 = "Um sure";
		price = "8 MaxHealth";
	}
	else if (Name == "Brain") {
		negotiate1 = "(Hello.)";
		you2 = "I don't want to fight";
		negotiate2 = "(Then provide me with #r7 of your Intelligence#o please.)";
		you3 = "Ok";
		price = "7 Intelligence";
	}
	//------Demon:
	else if (Name == "Cultist") {
		negotiate1 = "What";
		you2 = "I don't want to fight";
		negotiate2 = "Then sacrifice to me #r3 of your Max Health#o";
		you3 = "Ok";
		price = "3 MaxHealth";
	}
	else if (Name == "Imp") {
		negotiate1 = "What? what?";
		you2 = "I don't want to fight";
		negotiate2 = "Ha, then give me #$10 gold#o!";
		you3 = "Sure";
		price = "10 gold";
	}
	else if (Name == "Weeping Soul") {
		negotiate1 = "*sobs*";
		you2 = "Do you wish to stop fighting?";
		negotiate2 = "I wish to be whole. Give me #r8 of your Max Health#o.";
		you3 = "Ok";
		price = "8 MaxHealth";
	}
	else if (Name == "Hellhound") {
		negotiate1 = "Grrrrr";
		you2 = "Let's not fight";
		negotiate2 = "How about you give me #b3 pieces of Gear#o, then?";
		you3 = "Ok";
		price = "3 Gear";
	}
	//------Machine:
	else if (Name == "Robot") {
		negotiate1 = "WHAT.";
		you2 = "I don't want to fight";
		negotiate2 = "INSERT #r1 GEAR#o.";
		you3 = "Ok";
		price = "1 Gear";
	}
	else if (Name == "Golem") {
		negotiate1 = "Hmph";
		you2 = "I don't want to fight";
		negotiate2 = "#r3 Max Mana#o.";
		you3 = "Sure";
		price = "3 MaxMana";
	}
	else if (Name == "Merchant") {
		negotiate1 = "What do you want?";
		you2 = "I don't want to fight";
		negotiate2 = "Hm. #b2 pieces of Gear#o and #$15 gold#o. Lowest offer.";
		you3 = "Fine";
		price = "Merchant";
	}
	else if (Name == "Turret") {
		negotiate1 = "WHAT.";
		you2 = "Don't shoot me please";
		negotiate2 = "INSERT #r2 SKILL#o.";
		you3 = "Alright";
		price = "2 Skill";
	}
	//----------------Boss-----------------
	else if (Name == "Paladin") {
		negotiate1 = "What?";
		you2 = "I don't want to fight";
		negotiate2 = "Then remove #r3 of your Skill#o, it is the Devil's power.";
		you3 = "Ok fine";
		price = "3 Skill";
	}
	else if (Name == "Hunter") {
		negotiate1 = "What?";
		you2 = "I don't want to fight";
		negotiate2 = "My price is #g1 boss Card#o";
		you3 = "Ok";
		price = "1 boss";
	}
	else if (Name == "Juggernaut") {
		negotiate1 = "*grunts*";
		you2 = "Let's not fight";
		negotiate2 = "Not fight? Then give me #ga boss Card#o.";
		you3 = "Ok";
		price = "1 boss";
	}
	else if (Name == "Vampire") {
		negotiate1 = "Hmmm?";
		you2 = "I don't want to fight";
		negotiate2 = "Provide me #g1 boss Card#o and I will be merciful.";
		you3 = "Ok";
		price = "1 boss";
	}
	else if (Name == "Druid") {
		negotiate1 = "Yes?";
		you2 = "I don't want to fight";
		negotiate2 = "Then give me #r3 of your Skill#o.";
		you3 = "Ok";
		price = "3 Skill";
	}
	else if (Name == "Thief") {
	negotiate1 = "";
	you2 = "";
	negotiate2 = "";
	you3 = "";
	}
	else if (Name == "Hydra") {
	you2 = "I don't want to fight";
	you3 = "Ok";

	if (stepTwo) {
		negotiate1 = "What? What? What?";
		negotiate2 = "Then...give us...#ga boss Card#o.";
	}
	else if (stepOne) {
		negotiate1 = "What? What?";
		negotiate2 = "Then give us...#ga boss Card#o.";
	}
	else {
		negotiate1 = "What?";
		negotiate2 = "Then give me #ga boss Card#o.";
	}

	price = "1 boss";
	}
	else if (Name == "Wolf") {
		negotiate1 = "grrrrr";
		you2 = "I don't want to fight you";
		negotiate2 = "Then give me #r1 boss Card#o.";
		you3 = "Sure";
		price = "1 boss";
	}
	else if (Name == "Exorcist") {
		negotiate1 = "What?";
		you2 = "Please leave me alone";
		negotiate2 = "Then cleanse yourself by giving up #r3 Skill#o.";
		you3 = "Fine";
		price = "3 Skill";
	}
	else if (Name == "Demigod") {
		negotiate1 = "What, mortal?";
		you2 = "I don't want to fight";
		negotiate2 = "Alright. Show me your worth with #ra boss Card#o.";
		you3 = "Ok";
		price = "1 boss";
	}
	else if (Name == "Serpent") {
		negotiate1 = "Hss";
		you2 = "I don't want to fight";
		negotiate2 = "Give me #r3 Skill#o.";
		you3 = "Ok";
		price = "3 Skill";
	}
	else if (Name == "Spirit") {
		negotiate1 = "Why do you disturb me?";
		you2 = "I don't want to fight you";
		negotiate2 = "Give me a #rBoss Card#o, then.";
		you3 = "Ok";
		price = "1 boss";
	}
	else if (Name == "Artificer") {
		negotiate1 = "Yes?";
		you2 = "I don't want to fight";
		negotiate2 = "I need you to get me a #rBoss Card#o.";
		you3 = "Sure";
		price = "1 boss";
	}
	//-------------Final Boss--------------
	else if (Name == "Dragon") {
		negotiate1 = "What is it, human?";
		you2 = "I wish to leave this place.";
		negotiate2 = "I will let you pass, if you provide me with #g5 boss Cards#o.";
		you3 = "Take them.";
		price = "5 boss";
	}
	else if (Name == "King") {
		negotiate1 = "What, peasant?";
		you2 = "Call off your soldiers please. I wish to leave.";
		negotiate2 = "Very well. The price is #g5 boss Cards#o.";
		you3 = "Here.";
		price = "5 boss";
	}
	else if (Name == "Witch") {
		negotiate1 = "What!? What isss it?";
		you2 = "Please. I wish to leave, not to fight.";
		negotiate2 = "Hmph. Throw over #g5 boss Cards#o.";
		you3 = "Alright. Here.";
		price = "5 boss";
	}
	else if (Name == "Demon") {
		negotiate1 = "So you wish to make a deal, mortal?";
		you2 = "I wish to leave this place.";
		negotiate2 = "If you give me #g5 boss Cards#o I will allow your passage through here.";
		you3 = "Take them.";
		price = "5 boss";
	}
	else if (Name == "Machine") {
		negotiate1 = "WHAT IS YOUR REQUEST.";
		you2 = "I wish to leave this place.";
		negotiate2 = "INSERT #g5 boss CARDS#o.";
		you3 = "Here.";
		price = "5 boss";
	}
}