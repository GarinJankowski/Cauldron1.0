#include "pch.h"
#include "Enemy.h"

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

	stepOne = FALSE;
	stepTwo = FALSE;

	bleeding = 0;
	fumes = 0;
	flay = 0;

//----------------Basic----------------
	//Rat (does damage)
	if (Name == "Rat") {
		MaxHealth = 20;
	}
	else if (Name == "Crab") {
		MaxHealth = 11;
	}
	else if (Name == "Kobold") {
		MaxHealth = 25;
	}
	else if (Name == "Zombie") {
		MaxHealth = 30;
	}
	else if (Name == "Hound") {
		MaxHealth = 35;
	}
//-----------------Mid-----------------
	else if (Name == "Giant Rat") {
		MaxHealth = 50;
	}
	else if (Name == "Wild Buffalo") {
		MaxHealth = 50;
	}
	else if (Name == "Harpy") {
		MaxHealth = 45;
	}
	else if (Name == "Brown Recluse") {
		MaxHealth = 70;
	}
	else if (Name == "Fairy") {
		MaxHealth = 1;
	}
//----------------High-----------------
	else if (Name == "Elemental") {
		MaxHealth = 100;
	}
	else if (Name == "Adventurer") {
		MaxHealth = 80;
		type = rand() % 4;
	}
	else if (Name == "Troll") {
		MaxHealth = 140;
	}
//---------------Themed----------------
	//------Dragon:
	else if (Name == "Hatchling") {
		MaxHealth = 30;
	}
	else if (Name == "Molten Jelly") {
		MaxHealth = 55;
	}
	else if (Name == "Knight") {
		MaxHealth = 60;
	}
	else if (Name == "Drake") {
		MaxHealth = 75;
	}
	//------King:
	else if (Name == "Slave") {
		MaxHealth = 30;
	}
	else if (Name == "Soldier") {
		MaxHealth = 40;
	}
	else if (Name == "Guard") {
		MaxHealth = 60;
	}
	else if (Name == "Jester") {
		MaxHealth = 50;
	}
	//------Witch:
	else if (Name == "Eyeball") {
		MaxHealth = 30;
	}
	else if (Name == "Apprentice") {
		MaxHealth = 45;
	}
	else if (Name == "Monster") {
		MaxHealth = 60;
	}
	else if (Name == "Brain") {
		MaxHealth = 100;
	}
	//------Demon:
	else if (Name == "Cultist") {
		MaxHealth = 30;
	}
	else if (Name == "Imp") {
		MaxHealth = 30;
		charge = TRUE;
	}
	else if (Name == "Weeping Soul") {
		MaxHealth = 60;
	}
	else if (Name == "Hellhound") {
		MaxHealth = 70;
	}
	//------Machine:
	else if (Name == "Robot") {
		MaxHealth = 30;
	}
	else if (Name == "Golem") {
		MaxHealth = 60;
	}
	else if (Name == "Merchant") {
		MaxHealth = 70;
		type = rtd(1, 3);
	}
	else if (Name == "Turret") {
		MaxHealth = 80;
	}
//----------------Boss-----------------
	else if (Name == "Paladin") {
		MaxHealth = 100;
	}
	else if (Name == "Hunter") {
		MaxHealth = 110;
	}
	else if (Name == "Juggernaut") {
		MaxHealth = 200;
	}
	else if (Name == "Vampire") {
		MaxHealth = 75;
	}
	else if (Name == "Druid") {

	}
	else if (Name == "Thief") {

	}
	else if (Name == "Hydra") {
		MaxHealth = 99;
	}
	else if (Name == "Wolf") {
		MaxHealth = 120;
	}
	else if (Name == "Exorcist") {
		MaxHealth = 150;
		type = rand() % 3;
	}
	else if (Name == "Demigod") {
		MaxHealth = 150;
		type = 1;
	}
//-------------Final Boss--------------
	else if (Name == "Dragon") {
		MaxHealth = 275;
	}
	else if (Name == "King") {
		MaxHealth = 150;
	}
	else if (Name == "Witch") {
		MaxHealth = 150;
	}
	else if (Name == "Demon") {
		MaxHealth = 200;
	}
	else if (Name == "Machine") {
		MaxHealth = 300;
	}
	initNegotiateLines();

	CurrentHealth = MaxHealth;
}
Enemy::~Enemy()
{
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

	//check if the enemy is bleeding
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
		int mana = 1*guy.drown;
		int damage = int(guy.Intelligence / 2);
		damage = takeDamage(damage*guy.drown, guy, log);
		guy.DrainMana(mana);

		string drown = "-You drown the " + string(Name) + " for #y"
					+ to_string(damage) + "#o damage.";
		log.PushPop(drown);
	}
	

	if (CurrentHealth <= 0) {
		Alive = FALSE;
		return;
	}
	else if (CurrentHealth > 0) {
//----------------Basic----------------
	//Rat: just some damage
		if (Name == "Rat") {
				int damage = rtd(3+td, 3);

				damage = guy.TakeDamage(damage);
				string line = string("-The Rat bites you for #r") + to_string(damage)
					+ string("#o damage.");
				log.PushPop(line);
		}
	//Crab: lots of block first turn
		else if (Name == "Crab") {
				string line;
				if (TurnCount == 0) {
					CurrentBlock += 20;
					line = "-The Crab hides in its shell and gains #b20#o block.";
				}
				else {
					int rng = rand() % 4;
					if (rng == 0) {
						int block = rtd(3 + td, 3);
						CurrentBlock += block;
						line = "-The Crab gains #b" + to_string(block) + "#o block.";
					}
					else {
						int damage = rtd(2, 5);
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
					int block = rtd(4, 2);
					CurrentBlock += block;
					line = "-The Kobold gains #b" + to_string(block) + "#o block.";
				}
				else if (rng == 1) {
					guy.pierce = TRUE;
					int damage = rtd(6, 2);
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
				heal(health);
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

			int damage = rtd(3 + td, 6);
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
				int block = rtd(1, 7);
				CurrentBlock += block;
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
				guy.negative = "Webbed";
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
				guy.negative = "Scalding Steam";
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
				heal(damage);
				line = "-The Elemental #rsteals " + to_string(damage) + " health#o from you.";
			}
			else if (rng > 4 && rng <= 6) {
				//heal
				int health = rtd(6, 2);
				heal(health);
				line = "-The Elemental gains #b" + to_string(health) + "#o health.";
			}
			else if (rng > 6 && rng <= 7) {
				//stat drain
				int rng2 = rand() % 8;
				if (rng2 >= 0 && rng2 < 2 && guy.Strength > 1) {
					//str
					guy.ModStat(-1, "Strength");
					guy.strMod++;
					line = "-The Elemental drains #r1 strength#o from you.";
				}
				else if (rng2 >= 2 && rng2 < 4 && guy.Defense > 1) {
					//def
					guy.ModStat(-1, "Defense");
					guy.defMod++;
					line = "-The Elemental drains #r1 defense#o from you.";
				}
				else if (rng2 >= 4 && rng2 < 6 && guy.Intelligence > 1) {
					//int
					guy.ModStat(-1, "Intelligence");
					guy.intMod++;
					line = "-The Elemental drains #r1 intelligence#o from you.";
				}
				else if (rng2 >= 6 && rng2 < 7 && guy.MaxHealth > 10) {
					//hp
					guy.ModStat(-1, "MaxHealth");
					guy.hpMod++;
					if (guy.CurrentHealth > guy.MaxHealth)
						guy.MaxHealth--;
					line = "-The Elemental drains #r1 max health#o from you.";
				}
				else if (rng2 == 7 && guy.MaxMana > 3) {
					//mp
					guy.ModStat(-1, "MaxMana");
					guy.mpMod++;
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
						guy.CurrentHealth -= 12;
						line = "-The Adventurer pierces your armor and deals #r12#o damage.";
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
					heal(2);
					string line2 = "-The Adventurer regenerates #r2#o health.";
					log.PushPop(line2);
				}
			}
			else if (rng1 == 1) {
				if (type == 0) {
					int block = rtd(3, 6);
					CurrentBlock += block;
					line = "-The Adventurer gains #b" + to_string(block) + "#o block.";
				}
				else if (type == 1) {
					int block = rtd(8, 3);
					CurrentBlock += block;
					line = "-The Adventurer gains #b" + to_string(block) + "#o block.";
					charge = FALSE;
				}
				else if (type == 2) {
					int block = rtd(3, 6);
					CurrentBlock += block;
					line = "-The Adventurer gains #b" + to_string(block) + "#o block.";
				}
				else if (type == 3) {
					int block = rtd(2, 5);
					CurrentBlock += block;
					line = "-The Adventurer gains #b" + to_string(block) + "#o block.";
					heal(2);
					string line2 = "-The Adventurer regenerates #r2#o health.";
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
						heal(health);
						line = "-The Adventurer heals for #r" + to_string(health) + "#o health.";
					}
				}
				else if (type == 1) {
					if (!charge) {
						int damage = rtd(4, 5);
						damage = guy.TakeDamage(damage);
						line = "The Adventurer zaps you for #r" + to_string(damage) + "#o damage.";
						charge = TRUE;
						Turn(guy, log);
					}
					else {
						int damage = rtd(4, 5);
						damage = guy.TakeDamage(damage);
						line = "The Adventurer zaps you for #r" + to_string(damage) + "#o damage.";
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
					heal(health);
					line = "-The Adventurer heals for #r" + to_string(health) + "#o health.";
					heal(2);
					string line2 = "-The Adventurer regenerates #r2#o health.";
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
					int block = rtd(2, 6);
					CurrentBlock += block;
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
				line = "#r-The Molten Jelly sprays you embers.#o";
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
				int pblock = rtd(3, 2);
				CurrentBlock += pblock;
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
				int block = rtd(3, 4);
				CurrentBlock += block;
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
				heal(health);

				line = "-The Slave consumes their block and heals for #b" + to_string(health) + "#o health.";
			}
			else if (rng < 2 && CurrentBlock < 10) {
				int block = rtd(1, 5) + 3 + ((MaxHealth - CurrentHealth)/4);
				CurrentBlock += block;

				line = "-The Slave gains #b" + to_string(block) + "#o block.";
			}
			else{
				int damage = rtd(3+td, 3);
				damage = guy.TakeDamage(damage);

				line = "-The Slave hits you for #r" + to_string(damage) + "#o damage.";
			}

			log.PushPop(line);
		}
	//Soldier: passive block, hits hard
		else if (Name == "Soldier") {
			string line;

			int pblock = rtd(2,2);
			CurrentBlock += pblock;
			string line2 = "-The Soldier gains #b" + to_string(pblock) + "#o block.";
			log.PushPop(line2);

			int damage = rtd(2+td, 6);
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
			else if (CurrentBlock > 20 && rng == 1) {
				int damage = guy.TakeDamage(CurrentBlock);
				CurrentBlock = 0;
				line = "-The Guard #buses their block#o to crush you for #r" + to_string(damage) + "#o damage.";
			}
			else {
				int block = rtd(5, 5);
				CurrentBlock += block;
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
				guy.ModStat(-12, "Strength");
				guy.strMod += 12;
				string line2 = "-#yYou #bfeel #gweak.";
				log.PushPop(line2);
			}
			if (guy.Intelligence > 20) {
				guy.ModStat(-12, "Intelligence");
				guy.intMod += 12;
				string line2 = "-#cYou #yfeel #mdumb.";
				log.PushPop(line2);
			}
			if (guy.Skill > 20) {
				guy.ModStat(-15, "Skill");
				guy.sklMod += 15;
				string line2 = "-#mYou #rfeel #bslow.";
				log.PushPop(line2);
			}
			int rng = rand() % 8;
			if (rng < 2) {
				int statchange = rtd(10, 2);
				int statrng = rand() % 6;
				switch (statrng) {
				case 0:
					guy.ModStat(statchange, "MaxHealth");
					guy.hpMod -= statchange;
					break;
				case 1:
					guy.ModStat(statchange, "MaxMana");
					guy.mpMod -= statchange;
					break;
				case 2:
					guy.ModStat(statchange, "Strength");
					guy.strMod -= statchange;
					break;
				case 3:
					guy.ModStat(statchange, "Defense");
					guy.defMod -= statchange;
					break;
				case 4:
					guy.ModStat(statchange, "Intelligence");
					guy.intMod -= statchange;
					break;
				case 5:
					guy.ModStat(statchange, "Skill");
					guy.sklMod -= statchange;
					break;
				}

				statchange += rtd(1, 5) - 10;
				statchange *= -1;
				statrng = rand() % 6;
				switch (statrng) {
				case 0:
					guy.ModStat(statchange, "MaxHealth");
					guy.hpMod -= statchange;
					break;
				case 1:
					guy.ModStat(statchange, "MaxMana");
					guy.mpMod -= statchange;
					break;
				case 2:
					guy.ModStat(statchange, "Strength");
					guy.strMod -= statchange;
					break;
				case 3:
					guy.ModStat(statchange, "Defense");
					guy.defMod -= statchange;
					break;
				case 4:
					guy.ModStat(statchange, "Intelligence");
					guy.intMod -= statchange;
					break;
				case 5:
					guy.ModStat(statchange, "Skill");
					guy.sklMod -= statchange;
					break;
				}
				line = "#r-The Jester #gmesses #cwith #yyour #mstats#r.#o";
			}
			else if (rng >= 2 && rng < 4) {
				int statrng = rand() % 4;
				int statchange = 0;
				switch (statrng) {
				case 0:
					statchange = guy.Skill * -2;
					guy.ModStat(statchange, "Skill");
					guy.sklMod -= statchange;
					break;
				case 1:
					statchange = guy.Intelligence * -2;
					guy.ModStat(statchange, "Intelligence");
					guy.intMod -= statchange;
					break;
				case 2:
					statchange = guy.Strength * -2;
					guy.ModStat(statchange, "Strength");
					guy.strMod -= statchange;
					break;
				case 3:
					statchange = guy.Defense * -2;
					guy.ModStat(statchange, "Defense");
					guy.defMod -= statchange;
					break;
				}
				

				line = "#r-The Jester #ymesses #mwith #cyour #gstats#r.#o";
			}
			else if (rng == 5 || rng == 6) {
				int block = rtd(12, 2);
				CurrentBlock += block;
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
				guy.ModStat(-1 * mana, "MaxMana");
				guy.mpMod += mana;

				line = "-The Eyeball #mdrains #r" + to_string(mana) + "#m of your max mana#o.";
			}
			else if (guy.MaxHealth > 1) {
				int health;
				if (guy.MaxHealth <= 20) {
					health = guy.MaxHealth - 1;
				}
				else {
					health = rtd(10, 2);
				}
				guy.ModStat(-1 * health, "MaxHealth");
				guy.hpMod += health;

				line = "-The Eyeball drains #r" + to_string(health) + "#o of your max health.";
			}
			else {
				int damage = rtd(3+td, 3);
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
				heal(health);
				line = "-The Apprentice is recharging and regains #b" + to_string(health) + "#o health.";
			
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
				int pblock = rtd(3, 2);
				CurrentBlock += pblock;
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
					guy.negative = "Drain Int";
				else
					guy.negative = "Drain Str";
			}
			else if (dot < 4) {
				int rng = rand() % 5;
				if (rng == 0)
					guy.negative = "Drain Int";
				else if (rng == 1)
					guy.dotDamage += 1;
				else
					guy.negative = "Drain Str";
				dot++;
			}
		}
	//------Demon:
	//Cultist: drains stats
		else if (Name == "Cultist") {
			string line;

			int rng = rand() % 5;
			if (rng == 0 && guy.Strength > 1) {
				guy.ModStat(-1, "Strength");
				guy.strMod++;
				line = "-The Cultist drains #r1 strength#o from you.";
			}
			else if (rng == 1 && guy.Defense > 1) {
				guy.ModStat(-1, "Defense");
				guy.defMod++;
				line = "-The Cultist drains #r1 defense#o from you.";
			}
			else if (rng == 2 && guy.Intelligence > 1) {
				guy.ModStat(-1, "Intelligence");
				guy.intMod++;
				line = "-The Cultist drains #r1 intelligence#o from you.";
			}
			else {
				int damage = rtd(3+td, 4);
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
				guy.dotDamage += 2;
				if (TurnCount == 0)
					line = "#r-You begin to waste away.";
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
					int damage = rtd(5, 4) - 1;
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
			if (rng < 2 && dot < 4+td) {
				guy.negative = "Steam";
				dot++;
				line = "#r-The Robot expels some steam.#o";
			}
			else {
				int block = rtd(6-dot, 2);
				CurrentBlock += block;

				line = "-The Robot gains #b" + to_string(block) + "#o block.";
			}

			log.PushPop(line);
		}
	//Golem: passive block, hits hard
		else if (Name == "Golem") {
			string line;

			if (CurrentHealth < MaxHealth) {
				int regen = rtd(1, 3);
				heal(regen);
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
				line = "#r-The Turret reloads.";
				if (dot == 0) {
					charge = FALSE;
				}
			}

			log.PushPop(line);
		}
//----------------Boss-----------------
	//Paladin: passive block, hits hard, heals
		else if (Name == "Paladin") {
			CurrentBlock += 5;
			string line2 = "-The Paladain gains #b5#o block";
			log.PushPop(line2);

			string line;
			int rng = rand() % 3;
			if (rng == 0) {
				int health = rtd(3, 3);
				heal(health);
				line = "-The Paladin heals for #b" + to_string(health) + "#o health.";
			}
			else if (rng == 1) {
				int damage = rtd(8, 2);
				int block = rtd(5, 2);
				damage = guy.TakeDamage(damage);
				CurrentBlock += block;
				line = "-The Paladin slices you for #r" + to_string(damage) + "#o damage and gains #b" + to_string(block) + "#o block.";
			}
			else {
				int damage = rtd(12, 2);
				damage = guy.TakeDamage(damage);
				line = "-The Paladin bashes you for #r" + to_string(damage) + "#o damage.";
			}
			log.PushPop(line);
		}
	//Hunter: charges up with block to get multiple turns later
		else if (Name == "Hunter") {
			int rng = rand() % 10;
				if (extraTurns > 0 && (rng < 2 || CurrentHealth < 30)) {
					while (extraTurns > 0) {
						int damage = 14 + (2*td);
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
				else if (rng == 5) {
					int block = rtd(2, 2);
					CurrentBlock += block;
					extraTurns++;
					string line = "#r-The Hunter loads an arrow and gains #b" + to_string(block) + "#r block.#o";
					log.PushPop(line);
				}
				else {
					int block = rtd(10, 2);
					CurrentBlock += block;
					string line = "-The Hunter gains #b" + to_string(block) + "#o block.";
					log.PushPop(line);
				}
		}
	//Juggernaut: charges up with block for huge damage, turns leftover block into hp
		else if (Name == "Juggernaut") {
			string line;

			if (charge) {
				int damage = rtd(11 + int(td/3), 2);
				damage = guy.TakeDamage(damage);
				damage = guy.TakeDamage(damage);
				line = "-The Juggernaut slams you #rtwice#o for #r" + to_string(damage) + "#o damage each.";
				charge = FALSE;
			}
			else {
				int rng = rand() % 5;
				if (rng == 0) {
					CurrentBlock += 10;
					charge = TRUE;
					line = "#r-The Juggernaut gains #b10#r block and begins to wind up...#o";
				}
				else if (rng == 1) {
					line = "-The Juggernaut rests for a turn.";
				}
				else {
					int block = rtd(8, 2);
					CurrentBlock += block;
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
				heal(healthNeeded);
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
					if (CurrentHealth < 35 && CurrentBlock < 25) {
						int damage = rtd(12, 2);
						damage = guy.TakeDamage(damage);
						heal(damage);
						line = "-The Vampire suddenly appears and #rsteals " + to_string(damage) + " health#o from you.";
					}
					else {
						int damage = rtd(7, 2);
						damage = guy.TakeDamage(damage);
						line = "-The Vampire suddenly appears and bites you for #r" + to_string(damage) + "#o damage.";
					}
				}
				else {
					int rng = rand() % 4;
					if (rng == 0) {
						int block = rtd(5, 2);
						CurrentBlock += block;
						line = "-The Vampire gains #b" + to_string(block) + "#o block.";
					}
					else {
						int health = 6;
						heal(health);
						line = "-The Vampire regenerates #b" + to_string(health) + "#o health.";
					}
				}
				
			}
			else{
				if (CurrentHealth < 50) {
					int rng = rand() % CurrentHealth;
					if (rng < 6 && dot < 3) {
						invisible += rtd(2, 2);
						dot++;
						line = "#b-The Vampire turns invisible and becomes immune to direct damage.#o";
					}
				}
				else {
					int rng = rand() % 4;
					if (rng == 0) {
						int damage = rtd(7, 2);
						damage = guy.TakeDamage(damage);
						heal(damage);
						line = "-The Vampire #rsteals " + to_string(damage) + " health#o from you.";
					}
					else if (rng == 1) {
						int block = rtd(15, 2);
						CurrentBlock += block;
						line = "-The Vampire gains #b" + to_string(block) + "#o block.";
					}
					else {
						int damage = rtd(7 + td, 4);
						damage = guy.TakeDamage(damage);
						line = "-The Vampire bites you for #r" + to_string(damage) + "#o damage.";
					}
				}
			}
			log.PushPop(line);
		}
	//Druid: heals and thorns
		else if (Name == "Druid") {
		
		}
	//Thief: can steal your spell and use them
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
					CurrentBlock += 6;
					line = "-The Hydra gains #b6#o block.";
				}
				else {
					int damage = rtd(6 + td, 2);
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
				guy.dotDamage += 6;
				line = "#r-The Wolf tears your flesh, causing you to bleed out.#o";
			}
			else {
				int rng = rand() % 6;
				if (rng < 4 && guy.dotDamage > 9 && !charge) {
					guy.negative = "Patch";
					charge = TRUE;
					line = "#b-The Wolf retreats for a turn.#o";
				}
				else if (rng < 3) {
					guy.dotDamage += 3;
					line = "#r-The Wolf tears your flesh, causing you to bleed out.#o";
				}
				else if (rng == 3 || rng == 4) {
					int block = rtd(1, 8) + 12;
					CurrentBlock += block;
					line = "-The Wolf gains #b" + to_string(block) + "#o block.";
 				}
				else {
					int damage = rtd(1, 7) + 11;
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
					guy.dotDamage += 3;
				}
				else {
					guy.dotDamage += 1;
				}
			}
			//card
			else if (rng > 0 && rng <= 2 && !charge) {
				line = "#r-The Exorcist begins to drain you.#o";
				if (type == 0) {
					guy.negative = "Drain Str";
				}
				else if (type == 1) {
					guy.negative = "Drain Def";
				}
				else if (type == 2){
					guy.negative = "Drain Int";
				}
				charge = TRUE;
			}
			//block
			else if (rng > 2 && rng <= 4) {
				int block;
				if (type == 1) {
					block = rtd(11, 2);
				}
				else {
					block = rtd(5, 2);
				}
				CurrentBlock += block;
				line = "-The Exorcist gains #b" + to_string(block) + "#o block.";
			}
			//attack
			else {
				int damage;
				if (type == 2) {
					damage = rtd(7 + td, 3);
				}
				else {
					damage = rtd(4 + td, 2);
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
			if (rngpower < 3) {
				type+=2;
				line2 = "-The Demigod grows in power.";
			}
			else if (rngpower >= 3 && rngpower <= 5) {
				MaxHealth += type;
				line2 = "#b-The Demigod grows in power.#o";
			}
			else {
				dot += type;
				line2 = "#r-The Demigod grows in power.#o";
			}
			log.PushPop(line2);

			int rng = rand() % (4+type);

			if (rng == 0) {
				int health = rtd(2+type, 2);
				heal(health);
				line = "-The Demigod heals for #b" + to_string(health) + "#o health.";
			}
			else if (rng > 0 && rng < 3) {
				int block = rtd(12-type, 2);
				CurrentBlock += block;
				line = "-The Demigod gains #b" + to_string(block) + "#o block.";
			}
			else {
				int damage = 3 + dot + td;
				damage = guy.TakeDamage(damage);
				line = "-The Demigod slices you for #r" + to_string(damage) + "#o damage.";
			}
			log.PushPop(line);
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
					if (rng < 5) {
						dot++;
						line = "#r-The Dragon inhales...#o";
					}
					else {
						charge = TRUE;
						type = rtd(17, 2);
					}
				}
				if (charge) {
					int damage = guy.TakeDamage(type);
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
					guy.CurrentBlock = 0;
					CurrentBlock = 0;
					line = "#b-The Dragon incinerates all the block on the field.#o";
				}
				else if (rng == 3 && guy.dotDamage < 6) {
					guy.dotDamage += 2;
					line = "#r-The Dragon scorches you, causing you to burn.#o";
				}
				else if (rng > 3 && rng <= 7) {
					int block = rtd(3, 10);
					CurrentBlock += block;
					line = "-The Dragon gains #b" + to_string(block) + "#o block.";
				}
				else {
					int damage = rtd(3, 9);
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
				int damage = rtd(4, 2);
				damage = guy.TakeDamage(damage);
				line = "-The King slashes you for #r" + to_string(damage) + "#o damage.";
			}
			else if (rng == 1) {
				int block = rtd(25, 3);
				CurrentBlock += block;
				line = "-The King gains #b" + to_string(block) + "#o block.";
			}
			else if (rng == 2) {
				if (CurrentHealth < rtd(30, 3) && CurrentBlock > 0) {
					int health = CurrentBlock;
					heal(health);
					CurrentBlock = 0;
					line = "-The King uses his #bblock to heal#o for #b" + to_string(health) + "#o health.";
				}
				else {
					int block = rtd(5, 5);
					CurrentBlock += block;
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
					int block = rtd(10, 3);
					CurrentBlock += block;
					line = "-The King gains #b" + to_string(block) + "#o block.";
				}
			}
			else if (rng == 4) {
				enemyNegate++;
				line = "#b-The King negates the next hit taken.#o";
			}
			else {
				int block = rtd(3, 10);
				CurrentBlock += block;
				line = "-The King gains #r" + to_string(block) + "#o block.";
			}
			log.PushPop(line);
		}
	//Witch: saps stats including max, adds cards to sap stats, can go invisible to not take damage
		else if (Name == "Witch") {
			string line;

			if (invisible > 0) {
				invisible--;
				int health = rtd(1, 6) + 9;
				line = "-The Witch regenerates #b" + to_string(health) + "#o health.";
			}
			else {
				int rng = rand() % 9;
				if (TurnCount < 3) {
					int block = (12, 2);
					CurrentBlock += block;

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
							guy.negative = "Drain Str";
						}
						else if (TurnCount == 1) {
							guy.negative = "Drain Def";
						}
						else if (TurnCount == 2) {
							guy.negative = "Drain Int";
						}
					}
					else if (dot == 1 || dot == 4) {
						if (TurnCount == 0) {
							guy.negative = "Drain Str";
						}
						else if (TurnCount == 1) {
							guy.negative = "Drain Def";
						}
						else if (TurnCount == 2) {
							guy.negative = "Drain Str";
						}
					}
					else if (dot == 2) {
						if (TurnCount == 0) {
							guy.negative = "Drain Def";
						}
						else if (TurnCount == 1) {
							guy.negative = "Drain Str";
						}
						else if (TurnCount == 2) {
							guy.negative = "Drain Def";
						}
					}
					else if (dot == 3) {
						if (TurnCount == 0) {
							guy.negative = "Drain Int";
						}
						else if (TurnCount == 1) {
							guy.negative = "Drain Def";
						}
						else if (TurnCount == 2) {
							guy.negative = "Drain Int";
						}
					}
					else if (dot == 5) {
						if (TurnCount == 0) {
							guy.negative = "Drain Str";
						}
						else if (TurnCount == 1) {
							guy.negative = "Drain Int";
						}
						else if (TurnCount == 2) {
							guy.negative = "Drain Str";
						}
					}
					else if (dot == 6) {
						if (TurnCount == 0) {
							guy.negative = "Drain Def";
						}
						else if (TurnCount == 1) {
							guy.negative = "Drain Int";
						}
						else if (TurnCount == 2) {
							guy.negative = "Drain Def";
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
				else if (rng == 0 || (type < 3 && CurrentHealth < 30)) {
					invisible += rtd(1, 3) + 2;
					line = "#b-The Witch turns invisible and becomes immune to direct damage.#o";
					type++;
				}
				else if (rng == 1 && guy.MaxHealth > 15) {
					int drain = rtd(4, 2);
					guy.MaxHealth-=drain;
					if (guy.CurrentHealth > guy.MaxHealth) {
						guy.CurrentHealth = guy.MaxHealth;
					}
					line = "-The Witch #rdrains " + to_string(drain) + " of your max health.#o";
				}
				else if (rng == 2 && guy.MaxMana > 8) {
					guy.MaxMana -= 2;
					if (guy.CurrentMana > guy.MaxMana) {
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
						guy.negative = "Drain Def";
						break;
					case 1:
						guy.negative = "Drain Int";
						break;
					case 2:
						guy.negative = "Drain Int";
						break;
					case 3:
						guy.negative = "Drain Str";
						break;
					case 4:
						guy.negative = "Drain Int";
						break;
					case 5:
						guy.negative = "Drain Def";
						break;
					case 6:
						guy.negative = "Drain Str";
						break;
					}
					stepOne = TRUE;
					line = "#r-The Witch chants under her breath.#o";
				}
				else if (rng >= 5 && rng < 8) {
					int block = rtd(4, 6);
					CurrentBlock += block;
					line = "-The Witch gains #b" + to_string(block) + "#o block.";
				}
				else {
					int damage = rtd(8, 2);
					damage = guy.TakeDamage(damage);

					line = "The Witch stabs you for #r" + to_string(damage) + "#o damage.";
				}
			}

			log.PushPop(line);
			if (TurnCount > 2 && rand() % 2 == 0) {
				int damage = rtd(4, 2);
				damage = guy.TakeDamage(damage);

				string line3 = "The Witch zaps you for #r" + to_string(damage) + "#o damage.";
				log.PushPop(line3);
			}
			if (TurnCount > 2 && rand() % 3 == 0) {
				int damage = rtd(4, 2);
				damage = guy.TakeDamage(damage);

				string line3 = "The Witch zaps you for #r" + to_string(damage) + "#o damage.";
				log.PushPop(line3);
			}
		}
	//Demon: can pierce block, damage over time, leech
		else if (Name == "Demon") {
			if (stepOne) {
				stepOne = FALSE;
				guy.Defense += 8;
				guy.defMod -= 8;
				string line = "-You regain your composure.";
				log.PushPop(line);
			}

			if (charge) {
				if (type > 4 && rand() % 8 < 3) {
					guy.dotDamage -= 6;
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
				if (CurrentHealth < 80 && rng < 3) {
					guy.dotDamage *= 3;
					guy.dotDamage += 6;

					charge = TRUE;
					line = "#r-The Demon slams the ground and begins to channel.#o";
				}
				else if ((rng == 0 || rng == 1) && guy.dotDamage < 3) {
					guy.dotDamage++;
					if (guy.dotDamage == 1)
						line = "#r-The Demon points at you. You begin to waste away.#o";
					else
						line = "#r-The Demon points at you. You rot further.#o";
				}
				else if ((rng == 2 || rng == 3) && guy.CurrentHealth > 1) {
					int damage;
					if (guy.CurrentHealth <= 20)
						damage = rtd(1, guy.CurrentHealth - 1);
					else
						damage = rtd(10, 2);

					guy.CurrentHealth -= damage;
					line = "-The Demon #rpierces#o your block for #r" + to_string(damage) + "#o damage.";
				}
				else if (rng == 4) {
					guy.Defense -= 8;
					guy.defMod += 8;
					guy.fillType = "Defend";
					string line2 = "#b The Demon stares into your eyes.#o";
					log.PushPop(line2);
					line = "#b-You panic, #rlosing 8 Defense#b and filling your hand with Defends.#o";
					stepOne = TRUE;
				}
				else if (rng == 5) {
					int block = rtd(12, 2);
					CurrentBlock += block;
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
				heal(health);
				string line2 = "-The Machine repairs itself for #b" + to_string(health) + "#o health.";
				log.PushPop(line2);
			}
			if (charge) {
				int damage = rtd(14, 2);
				damage = guy.TakeDamage(damage);
				string line2 = "-The turrets shoot you for #r" + to_string(damage) + "#o damage.";
				log.PushPop(line2);
			}

			string line;
			if (extraTurns == 0) {
				guy.negative = "Scalding Steam";
				line = "#r-The Machine expels clouds of steam.#o";
				extraTurns+=5;
			}
			else {
				int rngsteam = rand() % extraTurns;
				if (CurrentHealth <= 200 && !stepOne) {
					type += 2;
					MaxHealth = 200;
					line = "#b A chunk of the machine is no longer in operation.#o";
					extraTurns /= 2;
					stepOne = TRUE;
				}
				else if (CurrentHealth <= 100 && !stepTwo) {
					type += 2;
					MaxHealth = 100;
					charge = TRUE;
					string line2 = "#b Another chunk of the machine is no longer in operation.#o";
					line = "#r Two emergency turrets extend from the Machine.#o";
					log.PushPop(line2);
					stepTwo = TRUE;
				}
				else if (rngsteam == 0 && extraTurns < 40) {
					guy.negative = "Scalding Steam";
					line = "#r-The Machine expels clouds of steam.#o";
					extraTurns *= 2;
				}
				else {
					int block = rtd(4, 2+(type));
					CurrentBlock += block;
					line = "-The Machine gains #b" + to_string(block) + "#o block.";
				}
			}
			log.PushPop(line);

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
			guy.Alive = FALSE;
	}

	TurnCount++;
}

void Enemy::ActivateDOT(Character &guy, TextLog &log) {
	if (guy.dotDamage > 0) {
		string line;
		if (Name == "Hound" || Name == "Exorcist" || Name == "Wolf") {
			line = "-You bleed for #r" + to_string(guy.dotDamage) + "#o damage.";
		}
		else if (Name == "Brown Recluse") {
			line = "-You take #r" + to_string(guy.dotDamage) + "#o venom damage.";
		}
		else if (Name == "Elemental") {
			line = "-You take #r" + to_string(guy.dotDamage) + "#o poison damage.";
		}
		else if (Name == "Dragon" || Name == "Molten Jelly") {
			line = "-You burn for #r" + to_string(guy.dotDamage) + "#o damage.";
		}
		else if (Name == "Demon" || Name == "Imp" || Name == "Brain" || Name == "Hellhound") {
			if (charge) {
				heal(guy.dotDamage);
				line = "-The " + string(Name) + " #rsiphons your soul#o for #r" + to_string(guy.dotDamage) + "#o damage.";
			}
			else
				line = "-You waste for #r" + to_string(guy.dotDamage) + "#o damage.";
		}
		guy.TakeDamage(guy.dotDamage);
		log.PushPop(line);

		if (guy.CurrentHealth <= 0) {
			//Reconstruction Trait
			if (guy.Reconstruction && guy.Skill > 1) {
				guy.CurrentHealth = guy.MaxHealth;
				guy.ModStat(-2, "Skill");
				string recon = " You come back to life!";
				log.PushPop(recon);
			}
			else
				guy.Alive = FALSE;
		}
	}
}

int Enemy::takeDamage(int damage, Character &guy, TextLog &log) {
	int damage2 = damage;
	if (damage > 0 && guy.Frenzy) {
		damage *= 2;
	}
	if (damage < 0) {
		damage2 = 0;
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

	return damage2;
	updateEnemy(guy);
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

	1 Special
	5 Special

	Merchant (2 Gear, 1 Skill)
	Jester
	*/
	you1 = "Hey";
	you2b = "Screw you";
	if (Name == "Rat") {
		negotiate1 = "What";
		you2 = "I don't want to fight";
		negotiate2 = "Then give me #r2 of your Strength#o";
		you3 = "Ok sure";
		price = "2 Strength";
		negotiate2b = "Screw you too buddy";
	}
	else if (Name == "Crab") {
		negotiate1 = "Huh";
		you2 = "Stop pinching me";
		negotiate2 = "Then give me #b1 piece of Gear#o";
		you3 = "Ok sure";
		price = "1 Gear";
		negotiate2b = "Hey!";
	}
	else if (Name == "Kobold") {
		negotiate1 = "What";
		you2 = "I don't want to fight you";
		negotiate2 = "Then give me #b1 piece of Gear#o";
		you3 = "Ok sure";
		price = "1 Gear";
		negotiate2b = "Take this";
	}
	else if (Name == "Zombie") {
		negotiate1 = "...";
		you2 = "What do you want";
		negotiate2 = "...#rMax Health#o...#r3#o";
		you3 = "Here";
		price = "3 MaxHealth";
		negotiate2b = "...ughhhhhh...";
	}
	else if (Name == "Hound") {
		negotiate1 = "Woof";
		you2 = "I don't want to fight you";
		negotiate2 = "Give me #r3 Max Health#o please";
		you3 = "Here";
		price = "3 MaxHealth";
		negotiate2b = ":(";
	}
	//-----------------Mid-----------------
	else if (Name == "Giant Rat") {
		negotiate1 = "What";
		you2 = "I don't want to fight";
		negotiate2 = "Then give me #r8 of your Strength#o";
		you3 = "Ok sure";
		price = "8 Strength";
		negotiate2b = "Screw you too buddy";
	}
	else if (Name == "Wild Buffalo") {
		negotiate1 = "*grunts*";
		you2 = "Don't hurt me";
		negotiate2 = "Fine, then give me #b2 pieces of Gear#o";
		you3 = "Ok thanks";
		price = "2 Gear";
		negotiate2b = "*paws the ground*";
	}
	else if (Name == "Harpy") {
		negotiate1 = "What??";
		you2 = "I don't want to fight";
		negotiate2 = "Then give me #r1 of your Skill#o";
		you3 = "Ok";
		price = "1 Skill";
		negotiate2b = "SQUAWK";
	}
	else if (Name == "Brown Recluse") {
		negotiate1 = "Hsss";
		you2 = "I don't want to fight";
		negotiate2 = "Give me #b2 pieces of Gear#o and I won't kill you";
		you3 = "Ok sure";
		price = "2 Gear";
		negotiate2b = "I'll be sure to kill you slowly.";
	}
	else if (Name == "Fairy") {
		negotiate1 = "Yea?";
		you2 = "I don't want to fight";
		negotiate2 = "Then give me #r5 Max Mana#o.";
		you3 = "Ok";
		price = "5 MaxMana";
		negotiate2b = "Right back at ya";
	}
	//----------------High-----------------
	else if (Name == "Elemental") {
		negotiate1 = "What, mortal?";
		you2 = "I don't want to fight";
		negotiate2 = "Hmph, then give me #r2 of your Skill#o.";
		you3 = "Ok";
		price = "2 Skill";
		negotiate2b = "Face my wrath!";
	}
	else if (Name == "Adventurer") {
		negotiate1 = "Yea?";
		you2 = "I don't want to fight you";
		negotiate2 = "Can I have #b3 pieces of Gear#o then?";
		you3 = "Sure";
		price = "3 Gear";
		negotiate2b = "Screw you too!";
	}
	else if (Name == "Troll") {
		negotiate1 = "What, prey?";
		you2 = "I don't want to fight";
		negotiate2 = "I hunger. Give me #r8 of your Max Health#o";
		you3 = "Alright";
		price = "8 MaxHealth";
		negotiate2b = "";
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
		negotiate2 = "Hmm, then give me #r8 of your Strength#o.";
		you3 = "Ok";
		price = "8 Strength";
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
		negotiate2 = "Give me #r5 of your Defense#o, then.";
		you3 = "Ok";
		price = "5 Defense";
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
		negotiate2 = "Ha, then give me #r1 of your Skill#o!";
		you3 = "Sure";
		price = "1 Skill";
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
		negotiate2 = "Hm. #b2 pieces of Gear#o and #r1 Skill#o. Lowest offer.";
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
		negotiate2 = "My price is #g1 Special Card#o";
		you3 = "Ok";
		price = "1 Special";
	}
	else if (Name == "Juggernaut") {
		negotiate1 = "*grunts*";
		you2 = "Let's not fight";
		negotiate2 = "Not fight? Then give me #ga Special Card#o.";
		you3 = "Ok";
		price = "1 Special";
	}
	else if (Name == "Vampire") {
		negotiate1 = "Hmmm?";
		you2 = "I don't want to fight";
		negotiate2 = "Provide me #g1 Special Card#o and I will be merciful.";
		you3 = "Ok";
		price = "1 Special";
	}
	else if (Name == "Druid") {
	negotiate1 = "";
	you2 = "";
	negotiate2 = "";
	you3 = "";
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
		negotiate2 = "Then...give us...#ga Special Card#o.";
	}
	else if (stepOne) {
		negotiate1 = "What? What?";
		negotiate2 = "Then give us...#ga Special Card#o.";
	}
	else {
		negotiate1 = "What?";
		negotiate2 = "Then give me #ga Special Card#o.";
	}

	price = "1 Special";
	}
	else if (Name == "Wolf") {
		negotiate1 = "grrrrr";
		you2 = "I don't want to fight you";
		negotiate2 = "Then give me #r1 Special Card#o or I will eat you.";
		you3 = "Sure";
		price = "1 Special";
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
		negotiate2 = "Alright. Show me your worth with #ra Special Card#o.";
		you3 = "Ok";
		price = "1 Special";
	}
	//-------------Final Boss--------------
	else if (Name == "Dragon") {
		negotiate1 = "What is it, human?";
		you2 = "I wish to leave this place.";
		negotiate2 = "I will let you pass, if you provide me with #g5 Special Cards#o.";
		you3 = "Take them.";
		price = "5 Special";
	}
	else if (Name == "King") {
		negotiate1 = "What, peasant?";
		you2 = "Call off your soldiers please. I wish to leave.";
		negotiate2 = "Very well. The price is #g5 Special Cards#o.";
		you3 = "Here.";
		price = "5 Special";
	}
	else if (Name == "Witch") {
		negotiate1 = "What!? What isss it?";
		you2 = "Please. I wish to leave, not to fight.";
		negotiate2 = "Hmph. Throw over #g5 Special Cards#o.";
		you3 = "Alright. Here.";
		price = "5 Special";
	}
	else if (Name == "Demon") {
		negotiate1 = "So you wish to make a deal, mortal?";
		you2 = "I wish to leave this place.";
		negotiate2 = "If you give me #g5 Special Cards#o I will allow your passage through here.";
		you3 = "Take them.";
		price = "5 Special";
	}
	else if (Name == "Machine") {
		negotiate1 = "WHAT IS YOUR REQUEST.";
		you2 = "I wish to leave this place.";
		negotiate2 = "INSERT #g5 SPECIAL CARDS#o.";
		you3 = "Here.";
		price = "5 Special";
	}
}