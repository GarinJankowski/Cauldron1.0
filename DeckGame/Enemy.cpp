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

	}
	else if (Name == "Molten Jelly") {

	}
	else if (Name == "Knight") {

	}
	else if (Name == "Drake") {

	}
	//------King:
	else if (Name == "Slave") {

	}
	else if (Name == "Soldier") {

	}
	else if (Name == "Guard") {

	}
	else if (Name == "Jester") {

	}
	//------Witch:
	else if (Name == "Eyeball") {

	}
	else if (Name == "Apprentice") {

	}
	else if (Name == "Monster") {

	}
	else if (Name == "Brain") {

	}
	//------Demon:
	else if (Name == "Cultist") {
		MaxHealth = 30;
	}
	else if (Name == "Imp") {

	}
	else if (Name == "Weeping Soul") {

	}
	else if (Name == "Hellhound") {

	}
	//------Machine:
	else if (Name == "Robot") {

	}
	else if (Name == "Golem") {

	}
	else if (Name == "Merchant") {

	}
	else if (Name == "Turret") {

	}
//----------------Boss-----------------
	else if (Name == "Paladin") {
		MaxHealth = 100;
	}
	else if (Name == "Hunter") {
		MaxHealth = 100;
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

	}
	else if (Name == "Exorcist") {
		MaxHealth = 120;
		type = rand() % 3;
	}
	else if (Name == "Demigod") {
		MaxHealth = 150;
		type = 1;
	}
//-------------Final Boss--------------
	else if (Name == "Dragon") {
		MaxHealth = 225;
	}
	else if (Name == "King") {
		MaxHealth = 150;
	}
	else if (Name == "Witch") {
		MaxHealth = 150;
	}
	else if (Name == "Demon") {
		MaxHealth = 175;
	}
	else if (Name == "Machine") {
		MaxHealth = 300;
	}

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
	//check if the enemy is bleeding
	if (bleeding > 0) {
		int damage = rtd(2, int(guy.Strength/2));
		if (CurrentBlock > damage)
			CurrentBlock -= damage;
		else {
			int damage2 = damage - CurrentBlock;
			CurrentHealth -= damage;
		}

		string bleedline = "-The " + string(Name) + " bleeds for " + to_string(damage) + " damage.";
		log.PushPop(bleedline);

		bleeding--;
	}
	if (fumes > 0) {
		int damage = rtd(1, guy.Intelligence);
		if (CurrentBlock > damage)
			CurrentBlock -= damage;
		else {
			int damage2 = damage - CurrentBlock;
			CurrentHealth -= damage;
		}

		string fumesline = "-The " + string(Name) + " takes " + to_string(damage) + " poison damage.";
		log.PushPop(fumesline);
		fumes--;
	}

	if (CurrentHealth <= 0) {
		Alive = FALSE;
		return;
	}
	else if (CurrentHealth > 0) {
//----------------Basic----------------
	//Rat: just some damage
		if (Name == "Rat") {
				int damage = rtd(3, 3);

				damage = guy.TakeDamage(damage);
				string line = string("-The Rat bites you for ") + to_string(damage)
					+ string(" damage.");
				log.PushPop(line);
		}
	//Crab: lots of block first turn
		else if (Name == "Crab") {
				string line;
				if (TurnCount == 0) {
					CurrentBlock += 20;
					line = "-The Crab hides in its shell and gains 20 block.";
				}
				else {
					int rng = rand() % 4;
					if (rng == 0) {
						int block = rtd(3, 3);
						CurrentBlock += block;
						line = "-The Crab gains " + to_string(block) + " block.";
					}
					else {
						int damage = rtd(2, 5);
						damage = guy.TakeDamage(damage);
						line = "-The Crab pinches you for " + to_string(damage) + " damage.";
					}
				}
				log.PushPop(line);
				updateEnemy(guy);
				TurnCount++;
		}
	//Kobold: pierces block sometimes	
		else if (Name == "Kobold") {
				string line;
				int rng = rand() % 5;
				if (rng == 0) {
					int block = rtd(4, 2);
					CurrentBlock += block;
					line = "-The Kobold gains " + to_string(block) + " block.";
				}
				else if (rng == 1) {
					guy.pierce = TRUE;
					int damage = rtd(6, 2);
					damage = guy.TakeDamage(damage);
					line = "-The Kobold pierces your block and stabs you for " + to_string(damage) + " damage.";
				}
				else {
					int damage = rtd(3, 4);
					damage = guy.TakeDamage(damage);
					line = "-The Kobold slices you for " + to_string(damage) + " damage.";
				}
				log.PushPop(line);
				updateEnemy(guy);
		}
	//Zombie: can leech for unblocked damage	
		else if (Name == "Zombie") {
				string line;

				int damage = rtd(2, 4);
				int health = damage;
				if (health < guy.CurrentBlock || guy.Negate > 0)
					health = 0;
				else {
					health -= guy.CurrentBlock;
				}
				damage = guy.TakeDamage(damage);
				heal(health);
				line = "-The Zombie bites you for " + to_string(damage) + " damage and steals " + to_string(health) + " health.";

				log.PushPop(line);
				updateEnemy(guy);
		}
	//Hound: can deal damage over time	
		else if (Name == "Hound") {
				string line;

				if (guy.dotDamage == 0) {
					guy.dotDamage += 2;
					line = "-The Hound tears your flesh, causing you to bleed out.";
				}
				else {
					int rng = rand() % 3;
					if (rng == 0) {
						guy.dotDamage += 2;
						line = "-The Hound tears your flesh, causing you to bleed out.";
					}
					else {
						int damage = rtd(3, 3);
						damage = guy.TakeDamage(damage);
						line = "-The Hound bites you for " + to_string(damage) + " damage.";
					}
				}

				log.PushPop(line);
				updateEnemy(guy);
		}
//-----------------Mid-----------------
	//Giant Rat: does a lot of damage
		else if (Name == "Giant Rat") {
			string line;

			int damage = rtd(3, 6);
			damage = guy.TakeDamage(damage);

			line = string("-The Giant Rat bites you for ") + to_string(damage)
				+ string(" damage.");

			log.PushPop(line);
			updateEnemy(guy);
		}
	//Wild Buffalo: charges up and either removes your block or does a lot of damage	
		else if (Name == "Wild Buffalo") {
			string line;

			int rng = rand() % 4;
			if (charge || rng == 0) {
				if (!charge) {
					line = "-The Wild Buffalo paws the ground, preparing to charge.";
					charge = TRUE;
				}
				else if (charge) {
					if (guy.CurrentBlock != 0) {
						guy.CurrentBlock = 0;
						line = "-The Wild Buffalo charges at you and removes your block.";
					}
					else {
						int damage = rtd(9, 4);
						damage = guy.TakeDamage(damage);
						line = "-The Wild Buffalo charges at you and does " + to_string(damage) + " damage.";
					}
					charge = FALSE;
				}

			}
			else {
				int damage = rtd(3, 5);
				damage = guy.TakeDamage(damage);
				line = "-The Wild Buffalo slams you for " + to_string(damage) + " damage.";
			}

			log.PushPop(line);
			updateEnemy(guy);
		}
	//Harpy: chance for an extra turn
		else if (Name == "Harpy") {
			string line;

			int rng = rand() % 4;
			if (rng == 0) {
				int block = rtd(1, 7);
				CurrentBlock += block;
				line = "-The Harpy gains " + to_string(block) + " block.";
			}
			else {
				int damage = rtd(1, 13);
				damage = guy.TakeDamage(damage);
				line = "-The Harpy scratches you for " + to_string(damage) + " damage.";
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
	//Brown Recluse: can web you and apply venom	
		else if (Name == "Brown Recluse") {
			string line;

			if (TurnCount == 0) {
				guy.negative = "Webbed";
				line = "-The Brown Recluse spews a web at you.";
				TurnCount++;
			}
			else {
				int rng = rand() % 4;
				if (rng == 0) {
					guy.dotDamage += 2;
					line = "-The Brown Recluse injects you with venom.";
				}
				else {
					int damage = rtd(6, 2);
					damage = guy.TakeDamage(damage);
					line = "-The Brown Recluse bites you for " + to_string(damage) + " damage.";
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
				line = "-The Elemental sprays you with steam.";
				cardAdded = TRUE;
			}
			else if (rng > 0 && rng <= 2) {
				//dot
				guy.dotDamage += 2;
				line = "-The Elemental releases toxic fumes.";
			}
			else if (rng > 2 && rng <= 4) {
				//leech
				int damage = rtd(3, 2);
				damage = guy.TakeDamage(damage);
				heal(damage);
				line = "-The Elemental steals " + to_string(damage) + " health from you.";
			}
			else if (rng > 4 && rng <= 6) {
				//heal
				int health = rtd(6, 2);
				heal(health);
				line = "-The Elemental gains " + to_string(health) + " health.";
			}
			else if (rng > 6 && rng <= 7) {
				//stat drain
				int rng2 = rand() % 8;
				if (rng2 >= 0 && rng2 < 2 && guy.Strength > 1) {
					//str
					guy.ModStat(-1, "Strength");
					guy.strMod++;
					line = "-The Elemental drains 1 strength from you.";
				}
				else if (rng2 >= 2 && rng2 < 4 && guy.Defense > 1) {
					//def
					guy.ModStat(-1, "Defense");
					guy.defMod++;
					line = "-The Elemental drains 1 defense from you.";
				}
				else if (rng2 >= 4 && rng2 < 6 && guy.Intelligence > 1) {
					//int
					guy.ModStat(-1, "Intelligence");
					guy.intMod++;
					line = "-The Elemental drains 1 intelligence from you.";
				}
				else if (rng2 >= 6 && rng2 < 7 && guy.MaxHealth > 10) {
					//hp
					guy.ModStat(-1, "MaxHealth");
					guy.hpMod++;
					if (guy.CurrentHealth > guy.MaxHealth)
						guy.MaxHealth--;
					line = "-The Elemental drains 1 max health from you.";
				}
				else if (rng2 == 7 && guy.MaxMana > 3) {
					//mp
					guy.ModStat(-1, "MaxMana");
					guy.mpMod++;
					if (guy.CurrentMana > guy.MaxMana)
						guy.CurrentMana--;
					line = "-The Elemental drains 1 max mana from you.";
				}
				else {
					//small attack
					int damage = 1;
					damage = guy.TakeDamage(damage);
					line = "-The Elemental hits you for 1 damage.";
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
					line = "-The Elemental pierces your armor and hits you for " + to_string(damage) + " damage.";
				}
				else {
					int damage = rtd(3, 12);
					damage = guy.TakeDamage(damage);
					line = "-The Elemental hits you for " + to_string(damage) + " damage.";
				}
			}

			log.PushPop(line);
			updateEnemy(guy);
		}
	//Adventurer: damage, blocks, spells	
		else if (Name == "Adventurer") {
			string line;
			//type 1: lots of attacks, piercing attacks, removes block
			//type 2: lots of block, small free damage sometimes
			//type 3: charges up, lots of spell damage
			//type 4: lots of heals, passive heals
			int rng1 = rand() % 3;

			if (rng1 == 0) {
				if (type == 0) {
					int rng2 = rand() % 3;
					if (rng2 == 0 && guy.CurrentHealth > 12) {
						guy.CurrentHealth -= 12;
						line = "-The Adventurer pierces your armor and deals 12 damage.";
					}
					else {
						int damage = rtd(12, 3);
						damage = guy.TakeDamage(damage);
						line = "-The Adventurer crushes you for " + to_string(damage) + " damage.";
					}
				}
				else if (type == 1) {
					int damage = rtd(5, 3);
					damage = guy.TakeDamage(damage);
					line = "-The Adventurer slices you for " + to_string(damage) + " damage.";
					charge = FALSE;
				}
				else if (type == 2) {
					dot++;
					line = "-The Adventurer is charging up.";
				}
				else if (type == 3) {
					int damage = rtd(12, 2);
					damage = guy.TakeDamage(damage);
					line = "-The Adventurer stabs you for " + to_string(damage) + " damage.";
					heal(2);
					string line2 = "-The Adventurer regenerates 2 health.";
					log.PushPop(line2);
				}
			}
			else if (rng1 == 1) {
				if (type == 0) {
					int block = rtd(3, 6);
					CurrentBlock += block;
					line = "-The Adventurer gains " + to_string(block) + " block.";
				}
				else if (type == 1) {
					int block = rtd(8, 3);
					CurrentBlock += block;
					line = "-The Adventurer gains " + to_string(block) + " block.";
					charge = FALSE;
				}
				else if (type == 2) {
					int block = rtd(3, 6);
					CurrentBlock += block;
					line = "-The Adventurer gains " + to_string(block) + " block.";
				}
				else if (type == 3) {
					int block = rtd(2, 5);
					CurrentBlock += block;
					line = "-The Adventurer gains " + to_string(block) + " block.";
					heal(2);
					string line2 = "-The Adventurer regenerates 2 health.";
					log.PushPop(line2);
				}
			}
			else if (rng1 == 2) {
				if (type == 0) {
					int rng2 = rand() % 2;
					if (rng2 == 0) {
						guy.CurrentBlock = 0;
						line = "-The Adventurer destroys all your block.";
					}
					else {
						int health = rtd(4, 3);
						heal(health);
						line = "-The Adventurer heals for " + to_string(health) + " health.";
					}
				}
				else if (type == 1) {
					if (!charge) {
						int damage = rtd(4, 5);
						damage = guy.TakeDamage(damage);
						line = "The Adventurer zaps you for " + to_string(damage) + " damage.";
						charge = TRUE;
						Turn(guy, log);
					}
					else {
						int damage = rtd(4, 5);
						damage = guy.TakeDamage(damage);
						line = "The Adventurer zaps you for " + to_string(damage) + " damage.";
					}
				}
				else if (type == 2) {
					if (dot <= 0) {
						Turn(guy, log);
					}
					else {
						for (int i = 0; i < dot; i++) {
							int damage = guy.TakeDamage(rtd(10, 3));
							string line2 = "-The Adventurer electrocutes you for " + to_string(damage) + " damage.";
							log.PushPop(line2);
						}
						dot = 0;
					}
				}
				else if (type == 3) {
					int health = rtd(5, 2);
					heal(health);
					line = "-The Adventurer heals for " + to_string(health) + " health.";
					heal(2);
					string line2 = "-The Adventurer regenerates 2 health.";
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
				int damage = rtd(16, 2);
				damage = guy.TakeDamage(damage);
				line = "-The Troll bludgeons you for " + to_string(damage) + " damage.";
				charge = FALSE;
			}
			else {
				int rng = rand() % 3;
				if (rng == 0) {
					charge = TRUE;
					line = "-The Troll readies its swing.";
				}
				else {
					int block = rtd(2, 6);
					CurrentBlock += block;
					line = "-The Troll gains " + to_string(block) + " block.";
				}
			}

			log.PushPop(line);
		}
//---------------Themed----------------
	//------Dragon:
	//Hatchling: charges up for big damage
		else if (Name == "Hatchling") {

		}
	//Molten Jelly: damage over time, removes your block
		else if (Name == "Molten Jelly") {

		}
	//Knight: passive block, hit hard
		else if (Name == "Knight") {

		}
	//Drake: gets extra turns, then rests
		else if (Name == "Drake") {

		}
	//------King:
	//Slave: can heal by consuming block
		else if (Name == "Slave") {

		}
	//Soldier: passive block, hits hard
		else if (Name == "Soldier") {

		}
	//Guard: can damage you by consuming block
		else if (Name == "Guard") {

		}
	//Jester: adds card to your hand with massive stat drain and stat raise
		else if (Name == "Jester") {

		}
	//------Witch:
	//Eyeball: drains max hp and mana
		else if (Name == "Eyeball") {

		}
	//Apprentice: high constant damage for a few rounds, rest for a couple rounds
		else if (Name == "Apprentice") {

		}
	//Monster: passive block, hits hard
		else if (Name == "Monster") {

		}
	//Brain: damage over time, drain stats
		else if (Name == "Brain") {

		}
	//------Demon:
	//Cultist: drains stats
		else if (Name == "Cultist") {
			string line;

			int rng = rand() % 5;
			if (rng == 0 && guy.Strength > 1) {
				guy.ModStat(-1, "Strength");
				guy.strMod++;
				line = "The Cultist drains 1 strength from you.";
			}
			else if (rng == 1 && guy.Defense > 1) {
				guy.ModStat(-1, "Defense");
				guy.defMod++;
				line = "The Cultist drains 1 defense from you.";
			}
			else if (rng == 2 && guy.Intelligence > 1) {
				guy.ModStat(-1, "Intelligence");
				guy.intMod++;
				line = "The Cultist drains 1 intelligence from you.";
			}
			else {
				int damage = rtd(3, 4);
				damage = guy.TakeDamage(damage);
				line = "The Cultist stabs you for " + to_string(damage) + " damage.";
			}

			log.PushPop(line);
			updateEnemy(guy);
		}
	//Imp: damage over time, can pierce	
		else if (Name == "Imp") {

		}
	//Weeping Soul: can go invisible to not deal/take damage
		else if (Name == "Weeping Soul") {

		}
	//Hellhound: removes your block, damage over time
		else if (Name == "Hellhound") {

		}
	//------Machine:
	//Robot: can add card that does damage and gives an extra turn
		else if (Name == "Robot") {

		}
	//Golem: passive block, hits hard
		else if (Name == "Golem") {

		}
	//Merchant: can add card that heals 1 hp and 1 mana, can heal
		else if (Name == "Merchant") {

		}
	//Turret: high consant damage for a few rounds, rest for a couple
		else if (Name == "Turret") {

		}
//----------------Boss-----------------
	//Paladin: passive block, hits hard, heals
		else if (Name == "Paladin") {
			CurrentBlock += 5;
			string line2 = "-The Paladain gains 5 block";
			log.PushPop(line2);

			string line;
			int rng = rand() % 3;
			if (rng == 0) {
				int health = rtd(3, 3);
				heal(health);
				line = "-The Paladin heals for " + to_string(health) + " health.";
			}
			else if (rng == 1) {
				int damage = rtd(8, 2);
				int block = rtd(5, 2);
				damage = guy.TakeDamage(damage);
				CurrentBlock += block;
				line = "-The Paladin slices you for " + to_string(damage) + " damage and gains " + to_string(block) + " block.";
			}
			else {
				int damage = rtd(12, 2);
				damage = guy.TakeDamage(damage);
				line = "-The Paladin bashes you for " + to_string(damage) + " damage.";
			}
			log.PushPop(line);
		}
	//Hunter: charges up with block to get multiple turns later
		else if (Name == "Hunter") {
			int rng = rand() % 10;
				if (extraTurns > 0 && (rng < 2 || CurrentHealth < 30)) {
					while (extraTurns > 0) {
						int damage = 14;
						damage = guy.TakeDamage(damage);

						string line = "-The Hunter shoots you for " + to_string(damage) + " damage.";
						log.PushPop(line);
						extraTurns--;
					}
				}
				else if (rng >= 2 && rng < 5) {
					extraTurns++;
					string line = "-The Hunter loads an arrow.";
					log.PushPop(line);
				}
				else if (rng == 5) {
					int block = rtd(2, 2);
					CurrentBlock += block;
					extraTurns++;
					string line = "-The Hunter loads an arrow and gains " + to_string(block) + " block.";
					log.PushPop(line);
				}
				else {
					int block = rtd(10, 2);
					CurrentBlock += block;
					string line = "-The Hunter gains " + to_string(block) + " block.";
					log.PushPop(line);
				}
		}
	//Juggernaut: charges up with block for huge damage, turns leftover block into hp
		else if (Name == "Juggernaut") {
			string line;

			if (charge) {
				int damage = rtd(11, 2);
				damage = guy.TakeDamage(damage);
				damage = guy.TakeDamage(damage);
				line = "-The Juggernaut slams you twice for " + to_string(damage) + " damage each.";
				charge = FALSE;
			}
			else {
				int rng = rand() % 5;
				if (rng == 0) {
					CurrentBlock += 10;
					charge = TRUE;
					line = "-The Juggernaut gains 10 block and begins to wind up...";
				}
				else if (rng == 1) {
					line = "-The Juggernaut rests for a turn.";
				}
				else {
					int block = rtd(8, 2);
					CurrentBlock += block;
					line = "-The Juggernaut gains " + to_string(block) + " block.";
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
				line2 = "The Juggernaut converts its block into " + to_string(healthNeeded) + " health.";
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
						line = "-The Vampire suddenly appears and steals " + to_string(damage) + " health from you.";
					}
					else {
						int damage = rtd(7, 2);
						damage = guy.TakeDamage(damage);
						line = "-The Vampire suddenly appears and bites you for " + to_string(damage) + " damage.";
					}
				}
				else {
					int rng = rand() % 4;
					if (rng == 0) {
						int block = rtd(5, 2);
						CurrentBlock += block;
						line = "-The Vampire gains " + to_string(block) + " block.";
					}
					else {
						int health = 6;
						heal(health);
						line = "-The Vampire regenerates " + to_string(health) + " health.";
					}
				}
				
			}
			else{
				if (CurrentHealth < 50) {
					int rng = rand() % CurrentHealth;
					if (rng < 6 && dot < 3) {
						invisible += rtd(2, 2);
						dot++;
						line = "-The Vampire turns invisible and becomes immune to attacks. ";
					}
				}
				else {
					int rng = rand() % 4;
					if (rng == 0) {
						int damage = rtd(7, 2);
						damage = guy.TakeDamage(damage);
						heal(damage);
						line = "-The Vampire steals " + to_string(damage) + " health from you.";
					}
					else if (rng == 1) {
						int block = rtd(15, 2);
						CurrentBlock += block;
						line = "-The Vampire gains " + to_string(block) + " block.";
					}
					else {
						int damage = rtd(7, 4);
						damage = guy.TakeDamage(damage);
						line = "-The Vampire bites you for " + to_string(damage) + " damage.";
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
					string line2 = " The Hydra's head falls off, growing 2 in its place.";
					log.PushPop(line2);
					stepOne = TRUE;
				}
			}
			else {
				extraTurns = 3;
				if (!stepTwo) {
					string line2 = " Another head falls off, growing 2 more.";
					log.PushPop(line2);
					stepTwo = TRUE;
				}
			}

			for (int i = 0; i < extraTurns; i++) {
				string line;
				int rng = rand() % 2;
				if (rng == 0) {
					CurrentBlock += 6;
					line = "-The Hydra gains 6 block.";
				}
				else {
					int damage = rtd(6, 2);
					damage = guy.TakeDamage(damage);
					line = "-The Hydra bites you for " + to_string(damage) +"  damage.";
				}
				log.PushPop(line);
			}
		}
	//Wolf: causes damage over time, adds card to remove it
		else if (Name == "Wolf") {

		}
	//Exorcist: adds cards that sap stats and deal damage over time
		else if (Name == "Exorcist") {
			string line;
			int rng = rand() % 6;
			//dot
			if (rng == 0) {
				line = "-The Exorcist puntures you, causing bleed.";
				if (type == 0) {
					guy.dotDamage += 3;
				}
				else {
					guy.dotDamage += 1;
				}
			}
			//card
			else if (rng > 0 && rng <= 2 && !charge) {
				line = "-The Exorcist begins to drain you.";
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
				line = "-The Exorcist gains " + to_string(block) + " block.";
			}
			//attack
			else {
				int damage;
				if (type == 2) {
					damage = rtd(7, 3);
				}
				else {
					damage = rtd(4, 2);
				}
				damage = guy.TakeDamage(damage);
				line = "-The Exorcist stabs you for " + to_string(damage) + " damage.";
			}
			log.PushPop(line);
		}
	//Demigod: heals every turn, attack and block simultaneosly
		else if (Name == "Demigod") {
			string line;
			string line2 = "-The Demigod grows in power.";
			int rngpower = rand() % 9;
			if (rngpower < 3) {
				type+=2;
			}
			else if (rngpower >= 3 && rngpower <= 5) {
				MaxHealth += type;
			}
			else {
				dot += type;
			}
			log.PushPop(line2);

			int rng = rand() % (4+type);

			if (rng == 0) {
				int health = rtd(2+type, 2);
				heal(health);
				line = "-The Demigod heals for " + to_string(health) + " health.";
			}
			else if (rng > 0 && rng < 3) {
				int block = rtd(12-type, 2);
				CurrentBlock += block;
				line = "-The Demigod gains " + to_string(block) + " block.";
			}
			else {
				int damage = 3 + dot;
				damage = guy.TakeDamage(damage);
				line = "-The Demigod slices you for " + to_string(damage) + " damage.";
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
						line = "-The Dragon inhales...";
					}
					else {
						charge = TRUE;
						type = rtd(17, 2);
					}
				}
				if (charge) {
					int damage = guy.TakeDamage(type);
					line = "-The Dragon breathes flames at you for " + to_string(damage) + " damage.";
					dot--;
					if (dot == 0)
						charge = FALSE;
				}
			}
			else {
				int rng = rand() % 11;
				if (rng == 0) {
					guy.shuffle = TRUE;
					string line2 = "-The Dragon flaps its wings and causes a gust.";
					line = " Your hand has been shuffled.";
					log.PushPop(line2);
				}
				else if (rng == 1) {
					dot++;
					line = "-The Dragon inhales...";
				}
				else if (rng == 2 && guy.CurrentBlock > 0) {
					guy.CurrentBlock = 0;
					CurrentBlock = 0;
					line = "-The Dragon incinerates all the block on the field.";
				}
				else if (rng == 3 && guy.dotDamage < 6) {
					guy.dotDamage += 2;
					line = "-The Dragon scorches you, causing you to burn.";
				}
				else if (rng > 3 && rng <= 7) {
					int block = rtd(3, 10);
					CurrentBlock += block;
					line = "-The Dragon gains " + to_string(block) + " block.";
				}
				else {
					int damage = rtd(3, 9);
					damage = guy.TakeDamage(damage);
					line = "-The Dragon claws you for " + to_string(damage) + " damage.";
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
				line = "-The King slashes you for " + to_string(damage) + " damage.";
			}
			else if (rng == 1) {
				int block = rtd(40, 2);
				CurrentBlock += block;
				line = "-The King gains " + to_string(block) + " block.";
			}
			else if (rng == 2) {
				if (CurrentHealth < rtd(30, 3) && CurrentBlock > 0) {
					int health = CurrentBlock;
					heal(health);
					CurrentBlock = 0;
					line = "-The King uses his block to heal for " + to_string(health) + " health.";
				}
				else {
					int block = rtd(5, 5);
					CurrentBlock += block;
					line = "-The King gains " + to_string(block) + " block.";
				}
			}
			else if (rng == 3) {
				if (CurrentBlock > rtd(15, 2)) {
					int damage = CurrentBlock;
					damage = guy.TakeDamage(damage);
					CurrentBlock = 0;
					line = "-The King crushes you for " + to_string(damage) + " damage and loses all his block.";
				}
				else {
					int block = rtd(10, 3);
					CurrentBlock += block;
					line = "-The King gains " + to_string(block) + " block.";
				}
			}
			else if (rng == 4) {
				enemyNegate++;
				line = "-The King negates the next hit taken.";
			}
			else {
				int block = rtd(3, 10);
				CurrentBlock += block;
				line = "-The King gains " + to_string(block) + " block.";
			}
			log.PushPop(line);
		}
	//Witch: saps stats including max, adds cards to sap stats, can go invisible to not deal/take damage
		else if (Name == "Witch") {

		}
	//Demon: can pierce block, damage over time, leech
		else if (Name == "Demon") {
			
		}
	//Machine: regen, adds cards that damage and give extra turn, gets more powerful at lower health but loses its maxhealth sometimes
		else if (Name == "Machine") {
			if (CurrentHealth < MaxHealth) {
				int health = 5-type;
				heal(health);
				string line2 = "-The Machine repairs itself for " + to_string(health) + " health.";
				log.PushPop(line2);
			}
			if (charge) {
				int damage = rtd(14, 2);
				damage = guy.TakeDamage(damage);
				string line2 = "-The turrets shoot you for " + to_string(damage) + " damage.";
				log.PushPop(line2);
			}

			string line;
			if (extraTurns == 0) {
				guy.negative = "Scalding Steam";
				line = "The Machine expels clouds of steam.";
				extraTurns+=5;
			}
			else {
				int rngsteam = rand() % extraTurns;
				if (CurrentHealth <= 200 && !stepOne) {
					type += 2;
					MaxHealth = 200;
					line = "A chunk of the machine is no longer in operation.";
					extraTurns /= 2;
					stepOne = TRUE;
				}
				else if (CurrentHealth <= 100 && !stepTwo) {
					type += 2;
					MaxHealth = 100;
					charge = TRUE;
					string line2 = "Another chunk of the machine is no longer in operation.";
					line = "Two emergency turrets extend from the Machine.";
					log.PushPop(line2);
					stepTwo = TRUE;
				}
				else if (rngsteam == 0 && extraTurns < 40) {
					guy.negative = "Scalding Steam";
					line = "The Machine expels clouds of steam.";
					extraTurns *= 2;
				}
				else {
					int block = rtd(4, 2+(type));
					CurrentBlock += block;
					line = "The Machine gains " + to_string(block) + " block.";
				}
			}
			log.PushPop(line);

		}

		if (guy.Spiny_Skin && guy.SpinyDamage > 0) {
			takeDamage(guy.SpinyDamage, guy, log);
			string spine = "-Your spines damage the " + string(Name) + " for " + to_string(guy.SpinyDamage) + " damage.";
			log.PushPop(spine);
			guy.SpinyDamage = 0;
		}
		if (guy.mirror > 0) {
			guy.mirror--;
			int damage = guy.mirrorDamage;
			takeDamage(damage, guy, log);
			string line = "-You mirror the " + string(Name) + " and deal " + to_string(damage) + " damage.";
			log.PushPop(line);
			guy.mirrorDamage = 0;
		}
		if (guy.charge > 0 && guy.chargeMana > 0) {
			guy.charge--;
			int mana = guy.chargeMana;
			guy.CurrentMana += mana;
			string line = "-You gain " + to_string(mana) + " mana.";
			log.PushPop(line);
			guy.chargeMana = 0;
		}
		if (guy.entomb > 0) {
			guy.entomb--;
		}
	}
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

void Enemy::ActivateDOT(Character &guy, TextLog &log) {
	if (guy.dotDamage > 0) {
		string line;
		if (Name == "Hound" || Name == "Exorcist") {
			line = "-You bleed for " + to_string(guy.dotDamage) + " damage.";
		}
		else if (Name == "Brown Recluse") {
			line = "-You take " + to_string(guy.dotDamage) + " venom damage.";
		}
		else if (Name == "Elemental") {
			line = "-You take " + to_string(guy.dotDamage) + " poison damage.";
		}
		else if (Name == "Dragon") {
			line = "-You burn for " + to_string(guy.dotDamage) + " damage.";
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
	if (guy.damageToMana > 0) {
		int mana = damage2 - CurrentBlock;
		if (mana < 0)
			mana = 0;
		guy.DrainMana(-1 * mana);
		guy.damageToMana = 0;
		string line = "-You gain " + to_string(mana) + " mana.";
		log.PushPop(line);
	}

	return damage2;
	updateEnemy(guy);
}