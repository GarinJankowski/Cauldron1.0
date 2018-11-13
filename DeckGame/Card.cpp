#include "pch.h"
#include "Card.h"

//List of Cards
//Attacks:
//	Smack, Charge, Pierce, Shoot
//Defends:
// Endure, Forcefield, Block
//Spells:
// Fireball, Channel, Meditate, Leech
//Specials:
// Transfusion, Haste
//Negatives:
//

int rtd(int multiplier, int power);
void mvprintInSize(int starty, int startx, int maxx, const char* toBePrinted);
WINDOW *makeWindow(int height, int width, int starty, int startx);
WINDOW *cardWindow;
//manually draw boxes
void manualBox(string typebox, int colorpair);

Card::Card(const char *name):CardName(name)
{
	CardName = name;
	ManaCost = 0;

//setting the card type and description
//the '$ ' are added to the description to manually create a new line if the mvprintInSize function doesn't do it
 //Attacks
	if (CardName == "Smack") {
		//2d(Str)
		CardType = "Attack";
		Description = "Deal 2d(Str) damage.";
	}
	else if (CardName == "Magic Smack") {
		//2d(Int)
		CardType = "Attack";
		Description = "Deal 2d(Int) damage.";
	}
	else if (CardName == "Charge") {
		//7d(Str-5) damage, remove your block
		CardType = "Attack";
		Description = "Deal 6d(Str-5) damage. Remove all your block.";
	}
	else if (CardName == "Pierce") {
		//
		CardType = "Attack";
		Description = "Deal 2d(Str) damage. Ignores block.";
	}
	else if (CardName == "Shoot") {
		CardType = "Attack";
		Description = "Deal 2d(Str) damage. Take 7 damage. Gain 1 turn.";
	}
	else if (CardName == "Throw") {
		CardType = "Attack";
		Description = "Deal 1d(Str-2) damage. Gain 1 turn.";
	}
	else if (CardName == "Charge") {
		CardType = "Attack";
		Description = "Deal 7d(Str-5) damage, remove all your block.";
	}
	else if (CardName == "Impale") {
		CardType = "Attack";
		Description = "Only usable for a killing blow. Deal 3x(Str) damage.";
	}
	else if (CardName == "Parry") {
		CardType = "Attack";
		Description = "Negate the next hit taken. Deal (Str)$ damage.";
	}
	else if (CardName == "Slice") {
		CardType = "Attack";
		Description = "Deal (Str)d2 damage.";
	}
	else if (CardName == "Crush") {
		CardType = "Attack";
		Description = "Deal 3d(Str) damage.";
	}
	else if (CardName == "Demolish") {
		CardType = "Attack";
		Description = "Deal 3x(Str) damage. Add a Tired card to$ your deck.";
	}
	else if (CardName == "Bleed") {
		CardType = "Attack";
		Description = "Deal 2d(Str/2) damage for 4 rounds.";
	}
	else if (CardName == "Hack") {
		CardType = "Attack";
		Description = "Deal 2d(Str) damage. Deals double to block.";
	}
	else if (CardName == "Stab") {
		CardType = "Attack";
		Description = "Chance to deal either 1 or 12 damage. Gain an extra turn.";
	}
	else if (CardName == "Zap") {
		CardType = "Attack";
		Description = "Deal 1d(Int/2), gain an extra turn.";
	}
	else if (CardName == "Ram") {
		CardType = "Attack";
		Description = "Deal (Def)d2 damage.";
	}
//Defends
	else if (CardName == "Endure") {
		//(Def)+2
		CardType = "Defend";
		Description = "Block for (Def)+2.";
	}
	else if (CardName == "Force Field") {
		//(Int)d2 block
		CardType = "Defend";
		Description = "Block for (Int)d2.";
	}
	else if (CardName == "Block") {
		CardType = "Defend";
		Description = "Gain (Def)/2 block. Negate the next hit taken.";
	}
	else if (CardName == "Obstruct") {
		CardType = "Defend";
		Description = "Gain 2x(Def) block.";
	}
	else if (CardName == "Disrupt") {
		CardType = "Defend";
		Description = "Gain (Def)+2 block. Remove enemy block.";
	}
	else if (CardName == "Dodge") {
		CardType = "Defend";
		Description = "Lose all block. Negate next hit taken, shuffle deck.";
	}
	else if (CardName == "Dash") {
		CardType = "Defend";
		Description = "Gain 1d(Def) block. Gain an extra turn.";
	}
	else if (CardName == "Brace") {
		CardType = "Defend";
		Description = "Gain (Def) block. Fill your hand with$ defends.";
	}
	else if (CardName == "Counter") {
		CardType = "Defend";
		Description = "Gain (Def) block. Fill your hand with$ attacks.";
	}
	else if (CardName == "Predict") {
		CardType = "Defend";
		Description = "Gain (Def) block. Fill your hand with$ spells.";
	}
	else if (CardName == "Absorb") {
		CardType = "Defend";
		Description = "Gain (Def)+2 block. Gain 5 mana.";
	}
	else if (CardName == "Reinforce") {
		CardType = "Defend";
		Description = "Gain 50% of your block.";
	}
	else if (CardName == "Flee") {
		CardType = "Defend";
		Description = "Costs all of your block. Gain 2 extra turns.";
	}
	else if (CardName == "Spikes") {
		CardType = "Defend";
		Description = "Gain (Def) damage. Deal 7 damage.";
	}
	else if (CardName == "Repulse") {
		CardType = "Defend";
		Description = "Take 7 damage, negate the next hit. Gain an extra turn.";
	}
//Spells
	else if (CardName == "Ponder") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Gain 2 mana.";
	}
	
	else if (CardName == "Channel") {
		//0 Mana
		//gain 3d(Int) mana
		ManaCost = 0;
		CardType = "Spell";
		Description = "Recover 1d(Int) mana.";
	}
	else if (CardName == "Meditate") {
		//4 Mana
		//recover (Int)d3 current hp
		ManaCost = 4;
		CardType = "Spell";
		Description = "Costs 4 mana. Recover (Int)d3 health.";
	}
	else if (CardName == "Blast") {
		ManaCost = 8;
		CardType = "Spell";
		Description = "Cost 8 mana. Deal (Int)d2 damage. Extra$ turn.";
	}

	else if (CardName == "Leech") {
		ManaCost = 5;
		CardType = "Spell";
		Description = "Costs 5 mana. Deal (Int)d2 damage and heal for that amount.";
	}
	else if (CardName == "Regenerate") {
		ManaCost = 5;
		CardType = "Spell";
		Description = "Cost 5 mana. Heal 2+1d(Int) health for 5 turns.";
	}
	else if (CardName == "Transmute") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Take 3d4 damage. Gain (Int) mana. Extra turn.";
	}

	else if (CardName == "Blink") {
		ManaCost = 9;
		CardType = "Spell";
		Description = "Cost 9 mana. Gain 2 extra turns.";
	}
	else if (CardName == "Push") {
		ManaCost = 4;
		CardType = "Spell";
		Description = "Cost 4 mana. Deal 2d(Int) damage. Gain an extra turn.";
	}
	else if (CardName == "Singularity") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Gain (Int)+7 block and (Int) mana. Lose a$ turn.";
	}

	else if (CardName == "Freeze") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Enemy gains (Int)d2 block. Extra turn.";
	}
	else if (CardName == "Shatter") {
		ManaCost = 10;
		CardType = "Spell";
		Description = "Cost 10 mana. Remove enemy block, deal that much damage.";
	}
	else if (CardName == "Melt") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Enemy loses (Int) block. Gain that as mana.";
	}

	else if (CardName == "Fumes") {
		ManaCost = 8;
		CardType = "Spell";
		Description = "Cost 8 mana. Deal 1d(Int) damage for (Int) turns.";
	}
	else if (CardName == "Smoke") {
		ManaCost = 5;
		CardType = "Spell";
		Description = "Cost 5 mana. Get (Int)/2$ block for 5$ turns.";
	}
	else if (CardName == "Incense") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Gain 3 mana for (Int)-1 turns. Extra turn.";
	}
	
	else if (CardName == "Fireball") {
		//5 mana
		//(Int)d5
		ManaCost = 5;
		CardType = "Spell";
		Description = "Cost 5 mana. Deal (Int)d5 damage.";
	}
	else if (CardName == "Conflagrate") {
		ManaCost = 6;
		CardType = "Spell";
		Description = "Cost 6 mana. Remove enemy block. Extra turn.";
	}
	else if (CardName == "Fuel") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Gain mana for next unblocked damage dealt. Extra turn.";
	}

	else if (CardName == "Mirror") {
		ManaCost = 4;
		CardType = "Spell";
		Description = "Cost 4 mana. The next damage taken is dealt to the enemy.";
	}
	else if (CardName == "Copy") {
		ManaCost = 6;
		CardType = "Spell";
		Description = "Cost 6 mana. Use the next$ card twice.$ Extra turn.";
	}
	else if (CardName == "Confuse") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Gain (Int)/2 mana. Extra turn.";
	}

	else if (CardName == "Lightning") {
		ManaCost = 20;
		CardType = "Spell";
		Description = "Cost 20 mana. Deal 8d(Int) damage.";
	}
	else if (CardName == "Thunder") {
		ManaCost = 5;
		CardType = "Spell";
		Description = "Cost 5 mana. Remove all block on the field.";
	}
	else if (CardName == "Overcharge") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Overcharge mana based on next damage taken. Extra turn.";
	}

	else if (CardName == "Destroy") {
		ManaCost = 6;
		CardType = "Spell";
		Description = "Cost 6 mana. Deal your block as damage, lose your block.";
	}
	else if (CardName == "Construct") {
		ManaCost = 5;
		CardType = "Spell";
		Description = "Cost 5 mana. Gain (Int)d4 block.";
	}
	else if (CardName == "Deconstruct") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Use your block to refill your mana. Extra turn.";
	}

	else if (CardName == "Laser") {
		ManaCost = 0;
		CardType = "Spell";
		Description = "Deal 2d(Skl) damage to health and block. Extra turn.";
	}
//Specials
	else if (CardName == "Haste") {
		//take (Skl)+1 extra turns
		CardType = "Special";
		Description = "Take (Skl)+1 extra turns.";
	}
	else if (CardName == "Transfusion") {
		//switch current hp with enemy
		CardType = "Special";
		Description = "Switch current hp with enemy.";
	}

	else if (CardName == "Revivify") {
		CardType = "Special";
		Description = "Heal 4 health and 2 mana for 5 turns.";
	}
	else if (CardName == "Steroids") {
		CardType = "Special";
		Description = "Your next attack deals$ double damage.";
	}
	else if (CardName == "Change Mind") {
		CardType = "Special";
		Description = "Shuffle your hand. Gain 5 block.";
	}
	else if (CardName == "Intimidate") {
		CardType = "Special";
		Description = "Take half damage for 2$ turns.";
	}
	else if (CardName == "Cripple") {
		CardType = "Special";
		Description = "Deal 25% of the enemy's health as damage.";
	}
	else if (CardName == "Merge") {
		CardType = "Special";
		Description = "Take 15 damage. Deal 6x(Skl) damage.";
	}
	else if (CardName == "Entomb") {
		CardType = "Special";
		Description = "Enemy cannot take or deal damage for 2$ turns.";
	}
	else if (CardName == "Distract") {
		CardType = "Special";
		Description = "Remove enemy block. Gain an extra turn.";
	}
	else if (CardName == "Prepare") {
		CardType = "Special";
		Description = "Fill your hand with spells. Gain 5 mana and 1 turn.";
	}
	else if (CardName == "Grow") {
		CardType = "Special";
		Description = "Gain 1 Str for the battle.";
	}
	else if (CardName == "Solidify") {
		CardType = "Special";
		Description = "Gain 1 Def for the battle.";
	}
	else if (CardName == "Learn") {
		CardType = "Special";
		Description = "Gain 1 Int for the battle.";
	}
	else if (CardName == "Train") {
		CardType = "Special";
		Description = "Gain 1 Skl for the battle.";
	}
	else if (CardName == "Boost") {
		CardType = "Special";
		Description = "Gain 5 mana. Can overcharge. Extra turn.";
	}
	else if (CardName == "Vitalise") {
		CardType = "Special";
		Description = "Gain 15 health.";
	}
	else if (CardName == "Jump") {
		CardType = "Special";
		Description = "Fill your hand with attacks. Negate 1 attack.";
	}
	else if (CardName == "Combo") {
		CardType = "Special";
		Description = "Fill your hand with specials.";
	}
	else if (CardName == "Slam") {
		CardType = "Special";
		Description = "Deal your block as damage.";
	}

//Negatives
	else if (CardName == "Steam") {
		CardType = "Negative";
		Description = "Take 5 damage. Get an extra turn.";
	}
	else if (CardName == "Scalding Steam") {
		CardType = "Negative";
		Description = "Take 12 damage. Get an extra turn.";
	}
	else if (CardName == "Webbed") {
		CardType = "Negative";
		Description = "Lose 2 block.";
	}
	else if (CardName == "Tired") {
		CardType = "Negative";
		Description = "Lose 2 block and 1 mana.";
	}
	else if (CardName == "Drain Str") {
		CardType = "Negative";
		Description = "Lose 1 strength.";
	}
	else if (CardName == "Drain Def") {
		CardType = "Negative";
		Description = "Lose 1 defense.";
	}
	else if (CardName == "Drain Int") {
		CardType = "Negative";
		Description = "Lose 1 intelligence.";
	}
}


Card::~Card()
{
}

void Card::printCard(int position) {
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);

	init_pair(2, COLOR_CYAN, COLOR_BLACK);

	init_color(COLOR_MAGENTA, 800, 0, 800);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);

	init_color(COLOR_BLACK, 700, 700, 700);
	init_pair(4, COLOR_BLACK, COLOR_BLACK);

	switch (position) {
	case 1:
		for (int i = 17; i < 23; i++) {
			mvprintw(i, 2, "                  ");
		}
		mvprintw(17, 2, "1)");
		break;
	case 2:
		for (int i = 17; i < 23; i++) {
			mvprintw(i, 22, "                  ");
		}
		mvprintw(17, 22, "2)");
		break;
	case 3:
		for (int i = 17; i < 23; i++) {
			mvprintw(i, 42, "                  ");
		}
		mvprintw(17, 42, "3)");
		break;
	}

	if (CardType == "Attack")
		attron(COLOR_PAIR(1));
	else if (CardType == "Defend")
		attron(COLOR_PAIR(2));
	else if (CardType == "Spell")
		attron(COLOR_PAIR(3));
	else if (CardType == "Special")
		standend();
	else if (CardType == "Negative")
		attron(COLOR_PAIR(5));

	switch (position) {
	case 1:
		manualBox("Card 1", 0);
		mvprintInSize(17, 5, 15, CardName);
		mvprintInSize(19, 4, 15, Description);
		break;
	case 2:
		manualBox("Card 2", 0);
		//cardWindow = makeWindow(8, 20, 16, 21);
		mvprintInSize(17, 25, 15, CardName);
		mvprintInSize(19, 24, 15, Description);
		break;
	case 3:
		manualBox("Card 3", 0);
		//cardWindow = makeWindow(8, 20, 16, 41);
		mvprintInSize(17, 45, 15, CardName);
		mvprintInSize(19, 44, 15, Description);
		break;


	}
	standend();
	init_color(COLOR_BLACK, 0, 0, 0);
}

void Card::cardFunction(Character &guy, Enemy &enemy, TextLog &log) {
	//attacks
	if (CardType == "Attack") {
		if (CardName == "Smack") {
			//do 2d(Str) dmg
			int damage = dealDamage(rtd(2, guy.Strength), guy, enemy, log);

			string line = "-You smack the " + string(enemy.Name)
				+ " for " + to_string(damage)
				+ " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Magic Smack") {
			//do 2d(Int) dmg
			int damage = dealDamage(rtd(2, guy.Intelligence), guy, enemy, log);

			string line = "-You magically smack the " + string(enemy.Name)
				+ " for " + to_string(damage)
				+ " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Charge") {
			//6d(Str-5) damage, remove your block
			int damage = dealDamage(rtd(6, guy.Strength - 5), guy, enemy, log);
			guy.CurrentBlock = 0;

			string line = "-You charge at the " + string(enemy.Name)
				+ " for " + to_string(damage)
				+ " damage, losing all your block.";
			log.PushPop(line);
		}
		else if (CardName == "Pierce") {
			//2d(Str) damage, ignoring block
			pierce = TRUE;
			int damage = dealDamage(rtd(2, guy.Strength), guy, enemy, log);

			string line = "-You pierce the " + string(enemy.Name)
				+ "'s block and deal " + to_string(damage)
				+ " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Shoot") {
			//2d(Str) damage, take 7 damage, extra turn
			int damage = dealDamage(rtd(2, guy.Strength), guy, enemy, log);
			int selfdamage = guy.TakeDamage(7);
			guy.extraTurns += 1;

			string line = "-You shoot the " + string(enemy.Name)
				+ " for " + to_string(damage)
				+ " and take " + to_string(selfdamage) + ".";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Throw") {
			int damage = rtd(1, guy.Strength - 2);
			guy.extraTurns += 1;
			damage = dealDamage(damage, guy, enemy, log);

			string line = "-You hit the " + string(enemy.Name)
						+" for " + to_string(damage) + " damage.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Impale") {
			//Can only be used to deal a killing blow. Deal 3x(Str) damage
			int damage = guy.Strength * 3;
			damage = dealDamage(damage, guy, enemy, log);

			string line = "-You impale the " + string(enemy.Name) + " for " + to_string(damage) + " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Parry") {
			guy.Negate++;

			int damage = rtd(guy.Strength, 1);
			
			damage = dealDamage(damage, guy, enemy, log);

			string line = "-You parry for " + to_string(damage) + " damage.";
			string line2 = "-You negate the next attack.";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Slice") {
			int damage = rtd(guy.Strength, 2);
			damage = dealDamage(damage, guy, enemy, log);

			string line = "-You slice the " + string(enemy.Name)
						+ " for " + to_string(damage) + " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Crush") {
			//do (Str)d3 dmg
			int damage = dealDamage(rtd(3, guy.Strength), guy, enemy, log);

			string line = "-You crush the " + string(enemy.Name)
				+ " for " + to_string(damage)
				+ " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Demolish") {
			//do 3*(Str) dmg, add 1 Tired to the deck
			int damage = dealDamage(3*guy.Strength, guy, enemy, log);
			guy.negative = "Tired";

			string line = "-You demolish the " + string(enemy.Name)
				+ " for " + to_string(damage)
				+ " damage.";
			string line2 = "-You feel a bit tired.";
			log.PushPop(line);
			if(enemy.CurrentHealth > 0)
				log.PushPop(line2);
		}
		else if (CardName == "Bleed") {
		//deal 2d(Str/2) damage for 4 rounds
			enemy.bleeding += 4;
			string line = "-You tear the " + string(enemy.Name)
						+ ", causing 4 extra rounds of bleed.";
			log.PushPop(line);
		}
		//hey dont screw this up with damage multipliers
		else if (CardName == "Hack") {
		//deal (Str)d2 damage, deals double to block
			int damageBlock;
			int damageHealth;
			string line;

			if (enemy.invisible > 0) {
				line = "-You hack the " + string(enemy.Name) + " for 0 damage.";
				log.PushPop(line);
				return;
			}

			int damageNormal = rtd(2, guy.Strength);
			int damageDouble = damageNormal * 2;
			if (enemy.CurrentBlock >= damageDouble) {
				enemy.CurrentBlock -= damageDouble;
				damageBlock = damageDouble;
				damageHealth = 0;
				
			}
			else if (enemy.CurrentBlock == 0) {
				enemy.CurrentHealth -= damageNormal;
				damageHealth = damageNormal;
				damageBlock = 0;
			}
			else {
				damageBlock = enemy.CurrentBlock;
				enemy.CurrentBlock = 0;
				int damageNew1 = damageDouble - enemy.CurrentBlock;
				int damageNew2 = (int)(damageNew1 / 2);
				damageHealth = damageNew2;
				enemy.CurrentHealth -= damageNew2;
			}
			line = "-You hack the " + string(enemy.Name) + " for " + to_string(damageBlock + damageHealth) + " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Stab") {
		//33% to deal 12 damage, 66% to 1, extra turn
			int rng = rand() % 3;
			int damage;
			if (rng == 0)
				damage = dealDamage(12, guy, enemy, log);
			else
				damage = dealDamage(1, guy, enemy, log);

			guy.extraTurns++;

			string line = "-You stab the " + string(enemy.Name)
						+ " for " + to_string(damage)
						+ " damage.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Zap") {
			//Deal 1d(Int/2), gain an extra turn
			int damage = rtd(1, int(guy.Intelligence / 2));
			damage = dealDamage(damage, guy, enemy, log);
			guy.extraTurns++;

			string line = "-You zap the " + string(enemy.Name) + " for " + to_string(damage) + " damage.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Ram") {
			//Deal(Def)d2 damage
			int damage = rtd(guy.Defense, 2);
			damage = dealDamage(damage, guy, enemy, log);

			string line = "You ram the " + string(enemy.Name)
						+ " for " + to_string(damage)
						+ " damage.";
			log.PushPop(line);
		}
	}
	//defends
	if (CardType == "Defend") {
		if (CardName == "Endure") {
			//block for (Def)+2
			int block = gainBlock(guy.Defense + 2, guy, enemy);

			string line = "-You gain " + to_string(block)
				+ " block.";
			
			log.PushPop(line);
		}
		else if (CardName == "Force Field") {
			//block for (int)d2
			int block = gainBlock(rtd(guy.Intelligence, 2), guy, enemy);

			string line = "-You gain " + to_string(block)
				+ " block.";
			log.PushPop(line);
		}
		else if (CardName == "Block") {
			//lose all block, negate one attack
			int block = gainBlock(int(guy.Defense / 2), guy, enemy);
			guy.Negate++;

			string line = "-You prepare to block an attack.";
			log.PushPop(line);
		}
		else if (CardName == "Obstruct") {
			//gain def*2 block
			int block = guy.Defense * 2;
			gainBlock(block, guy, enemy);

			string line = "-You gain " + to_string(block) + " block.";
			log.PushPop(line);
		}
		else if (CardName == "Disrupt") {
		//gain (Def)+2 block, remove enemy block
			int block = guy.Defense + 2;
			gainBlock(block, guy, enemy);
			enemy.CurrentBlock = 0;
			string line = "-You gain " + to_string(block)
						+ " block and remove the " + string(enemy.Name)
						+ "'s block.";
			log.PushPop(line);
		}
		else if (CardName == "Dodge") {
			//lose all block, negate next hit, shuffle deck
			guy.CurrentBlock = 0;
			guy.Negate++;
			guy.shuffle = TRUE;
			
			string line = "-You lose all your block and dodge the next hit.";
			log.PushPop(line);
		}
		else if (CardName == "Dash") {
			//gain 1d(Def) block, gain an extra turn
			int block = gainBlock(rtd(1, guy.Defense), guy, enemy);
			guy.extraTurns += 1;

			string line = "-You gain " + to_string(block) + " block.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Brace") {
			//gain (Def) block, fill your hand with blocks
			guy.fillType = "Defend";
			int block = gainBlock(guy.Defense, guy, enemy);

			string line = "-You gain " + to_string(block) + " block.";
			log.PushPop(line);
		}
		else if (CardName == "Counter") {
			//gain (Def) block, fill your hand with attacks
			guy.fillType = "Attack";
			int block = gainBlock(guy.Defense, guy, enemy);

			string line = "-You gain " + to_string(block) + " block.";
			log.PushPop(line);
		}
		else if (CardName == "Predict") {
			//gain (Def) block, fill your hand with spells
			guy.fillType = "Spell";
			int block = gainBlock(guy.Defense, guy, enemy);

			string line = "-You gain " + to_string(block) + " block.";
			log.PushPop(line);
		}
		else if (CardName == "Absorb") {
			//gain (Def)+2 block, gain 5 mana
			int block = gainBlock(guy.Defense+2, guy, enemy);
			guy.DrainMana(-5);

			string line = "-You gain " + to_string(block) + " block and 5 mana.";
			log.PushPop(line);
		}
		else if (CardName == "Reinforce") {
			//gain 1.5x your block
			int block = int(guy.CurrentBlock / 2);
			gainBlock(block, guy, enemy);
			string line = "-You gain " + to_string(block) + " block.";
			log.PushPop(line);
		}
		else if (CardName == "Flee") {
			//only usable if you have block. lose all block, gain 2 extra turns
				guy.CurrentBlock = 0;
				guy.extraTurns += 2;

				string line = "-You lose all of your block.";
				string line2 = " 2 EXTRA TURNS";
				log.PushPop(line);
				log.PushPop(line2);
		}
		else if (CardName == "Spikes") {
			//gain (Def) block, deal 7 damage
			int block = gainBlock(guy.Defense, guy, enemy);
			int damage = dealDamage(7, guy, enemy, log);

			string line = "-You gain " + to_string(block) + " block and deal " + to_string(damage) +" damage.";
			log.PushPop(line);
		}
		else if (CardName == "Repulse") {
			//Take 7 damage, negate the next hit. Gain an extra turn
			guy.TakeDamage(7);
			guy.Negate++;
			guy.extraTurns++;

			string line = "-You take 7 damage and ignore the next hit taken.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}

		if (guy.Dexterous && CardType == "Defend") {
			int ddamage = guy.Skill;
			dealDamage(ddamage, guy, enemy, log);
		}
	}
	//spells (sorted by headgear)
	if (CardType == "Spell") {
		guy.CurrentMana -= ManaCost;
		//no headgear
		if (CardName == "Ponder") {
			int mana = 2;
			guy.DrainMana(-1 * mana);
			string line = "-You gain " + to_string(mana) + " mana.";
		}
		
		else if (CardName == "Channel") {
			//gain 1d(Int) mana
			ManaCost = (-1)*rtd(1, guy.Intelligence);
			int mana = ManaCost * -1;
			guy.DrainMana(ManaCost);

			string line = "-You regain " + to_string(mana)
				+ " mana.";
			log.PushPop(line);
		}
		else if (CardName == "Meditate") {
			//costs 4 mana. gain (int)d3 hp
			int heal = -1 * rtd(guy.Intelligence, 3);
			guy.TakeDamage(heal);

			heal *= -1;
			/*string line = "-You recover #y" + to_string(heal)
				+ "#o health.";*/
			string line = "-You recover " + to_string(heal)
				+ " health.";
			log.PushPop(line);
		}
		else if (CardName == "Blast") {
			//Cost 8 mana. Deal (Int)d2 damage. Extra turn.
			int damage = dealDamage(rtd(guy.Intelligence, 2), guy, enemy, log);
			guy.extraTurns++;

			string line = "-You blast the " + string(enemy.Name) + " for " + to_string(damage) + " damage.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		
		else if (CardName == "Leech") {
			//cost 5 mana, deal (Int)d2 damage, gain that much hp
			int damage = dealDamage(rtd(guy.Intelligence, 2), guy, enemy, log);
			if(enemy.invisible <= 0)
				guy.TakeDamage(-1 * damage);

			string line = "-You steal " + to_string(damage)
				+ " health from the " + string(enemy.Name)
				+ ".";
			log.PushPop(line);
		}
		else if (CardName == "Regenerate") {
			//5 mana, heal 2+1d(int) for 5 turns
			guy.regenerateTurns += 5;
			string line = "-You regenerate for 5 more turns.";
			log.PushPop(line);
		}
		else if (CardName == "Transmute") {
			//take 3d4 damage, gain (Int) mana, extra turn
			int damage = rtd(3, 4);
			guy.TakeDamage(damage);
			int mana = -1 * guy.Intelligence;
			guy.DrainMana(mana);
			guy.extraTurns++;

			string line = "-You take " + to_string(damage)
						+ " damage and gain " + to_string(guy.Intelligence)
						+ " mana.";
			string line2 = " EXTR TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		
		else if (CardName == "Blink") {
			//cost 9 mana, gain 2 extra turns
			guy.extraTurns += 2;
			string line = " 2 EXTRA TURNS";
			log.PushPop(line);
		}
		else if (CardName == "Push") {
			//cost 3 mana, deal 1d(Int) damage, gain an extra turn
			int damage = dealDamage(rtd(2, guy.Intelligence), guy, enemy, log);
			guy.extraTurns += 1;

			string line = "-You force the "+ string(enemy.Name)
						+ " back for " + to_string(damage)
						+ " damage.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Singularity") {
			//gain (Int) block and (Int) mana, lose a extra turn
			int block = gainBlock(guy.Intelligence+7, guy, enemy);
			int mana = guy.Intelligence;
			guy.DrainMana(-1 * mana);
			guy.extraTurns--;

			string line = "-You gain " + to_string(block)
						+ " block and " + to_string(mana)
						+ " mana.";
			log.PushPop(line);
		}

		else if (CardName == "Freeze") {
			//enemy gains (int)d2 block, extra turn
			int block = rtd(guy.Intelligence, 2);
			enemy.CurrentBlock += block;
			guy.extraTurns++;

			string line = "-You freeze the " + string(enemy.Name)
						+ " for " + to_string(block) + " block.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Shatter") {
			//10 mana, remove enemy block, deal that much damage
			int damage = enemy.CurrentBlock;
			enemy.CurrentBlock = 0;
			damage = dealDamage(damage, guy, enemy, log);

			string line = "-You remove the " + string(enemy.Name)
						+ "'s block and deal " + to_string(damage)
						+ " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Melt") {
			//enemy loses (Int)block, gain that much mana
			int mana;
			if (enemy.CurrentBlock < guy.Intelligence) {
				mana = enemy.CurrentBlock;
				enemy.CurrentBlock = 0;
			}
			else {
				mana = guy.Intelligence;
				enemy.CurrentBlock -= guy.Intelligence;
			}
			guy.DrainMana(-1 * mana);

			string line = "-You remove " + to_string(mana)
				+ " block from the " + string(enemy.Name)
				+ " and gain " + to_string(mana) + " mana.";
			log.PushPop(line);
		}

		else if (CardName == "Fumes") {
			//8 mana, deal 1d(Int) damage for (Int) turns
			enemy.fumes += guy.Intelligence;
			string line = "-You release toxic fumes for " + to_string(guy.Intelligence) + " more turns.";
			log.PushPop(line);
		}
		else if (CardName == "Smoke") {
			//5 mana, gain (int)/2 block for 5 turns
			int turns = int(guy.Intelligence / 2);
			guy.smoke += turns;
			string line = "-You create smoke for " + to_string(turns) + " more turns.";
			log.PushPop(line);
		}
		else if (CardName == "Incense") {
			//Gain 3 mana for (Int)-1 turns
			int turns = guy.Intelligence - 1;
			guy.incense += turns;
			guy.extraTurns++;
			string line = "-You burn incense for " + to_string(turns) + " more turns.";
			log.PushPop(line);
			string line2 = " EXTRA TURN";
			log.PushPop(line2);
		}

		//fix this garbage spell set
		else if (CardName == "Fireball") {
			//5 mana
			//do (Int)d5 dmg
			int damage = dealDamage(rtd((int)(guy.Intelligence), 5), guy, enemy, log);


			string line = "-You lob a fireball at the " + string(enemy.Name)
				+ " for " + to_string(damage)
				+ " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Conflagrate") {
			//cost 6 mana, remove enemy block.
			enemy.CurrentBlock = 0;
			guy.extraTurns++;
			string line = "-You remove the " + string(enemy.Name) + "'s block.";
			log.PushPop(line);
			string line2 = " EXTRA TURN";
			log.PushPop(line2);
		}
		else if (CardName == "Fuel") {
			//on the next turn, gain mana for unblocked damage dealt
			guy.damageToMana +=2;
			guy.extraTurns++;
			string line = "-You prepare to attack.";
			log.PushPop(line);
			string line2 = " EXTRA TURN";
			log.PushPop(line2);
		}

		else if (CardName == "Mirror") {
			//Cost 4 mana, The next damage taken is dealt to the enemy
			guy.mirror++;
			string line = "-You prepare a reflection of the " + string(enemy.Name) + "'s next attack.";
			log.PushPop(line);
		}
		else if (CardName == "Copy") {
			//Cost 6 mana. Use your next card twice
			guy.copy++;
			guy.extraTurns++;

			string line = "-You prepare a copy of your next card.";
			log.PushPop(line);
			string line2 = " EXTRA TURN";
			log.PushPop(line2);
			copyUsed = TRUE;
		}
		else if (CardName == "Confuse") {
			//Gain (Int)/2 mana, gain an extra turn
			int mana = int(guy.Intelligence / 2);
			guy.DrainMana(-1 * mana);
			guy.extraTurns++;
			string line = "-You gain " + to_string(mana) + " mana.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
	
		else if (CardName == "Lightning") {
			//Cost 20 mana. Deal 8d(Int) damage
			int damage = rtd(8, guy.Intelligence);
			damage = dealDamage(damage, guy, enemy, log);

			string line = "-You electrocute the " + string(enemy.Name)
						+ " for " + to_string(damage)
						+ " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Thunder") {
			//Cost 5 mana. Remove all block on the field
			guy.CurrentBlock = 0;
			guy.Negate = 0;
			enemy.CurrentBlock = 0;
			string line = "The thunderclap obliterates all block.";
			log.PushPop(line);
		}
		else if (CardName == "Overcharge") {
			//Gain mana based on next unblocked damage taken. Can overcharge.
			guy.charge++;
			guy.extraTurns++;

			string line = "You brace yourself.";
			log.PushPop(line);
			string line2 = " EXTRA TURN";
			log.PushPop(line2);
		}
	
		else if (CardName == "Destroy") {
			//Cost 6 mana. Deal your block as damage, lose your block
			int damage = guy.CurrentBlock;
			damage = dealDamage(damage, guy, enemy, log);
			guy.CurrentBlock = 0;

			string line = "-You slam the " + string(enemy.Name)
						+ " for " + to_string(damage)
						+ " damage and lose your block.";
			log.PushPop(line);
		}
		else if (CardName == "Construct") {
			//Cost 5 mana. Gain (Int)d4 block
			int block = rtd(guy.Intelligence, 4);
			gainBlock(block, guy, enemy);

			string line = "-You gain " + to_string(block) + " block.";
			log.PushPop(line);
		}
		else if (CardName == "Deconstruct") {
			//use your block to refill your mana
			int missingMana = guy.MaxMana - guy.CurrentMana;
			int mana = 0;
			if (missingMana > guy.CurrentBlock) {
				mana = guy.CurrentBlock;
				guy.DrainMana(-1 * mana);
			}
			else {
				mana = missingMana;
				guy.CurrentBlock -= mana;
				guy.DrainMana(-1 * mana);
			}
			guy.Negate++;

			string line = "-You lose " + to_string(mana)
						+ " block and gain " + to_string(mana) + " mana.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Laser") {
			//Deal 2d(Skl) damage to health and block. Extra turn.
			int damageH = rtd(2, guy.Skill);
			int damageB = rtd(2, guy.Skill);
			if (damageB > enemy.CurrentBlock) {
				damageB = enemy.CurrentBlock;
				enemy.CurrentBlock = 0;
			}
			else
				enemy.CurrentBlock -= damageB;

			enemy.CurrentHealth -= damageH;
			guy.extraTurns++;

			string line = "-You incinerate the " + string(enemy.Name)
						+ " for " + to_string(damageB + damageH)
						+ " damage.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}

		//Power trait
		if (guy.Power && CardType == "Spell") {
			int health = guy.Skill;
			guy.TakeDamage(-1 * health);
		}
	}
	//specials
	if (CardType == "Special") {
		if (CardName == "Haste") {
			//take (Skl)+1 extra turns
			int turns = guy.Skill + 1;
			guy.extraTurns += turns;

			string line = " " + to_string(turns)
				+ " EXTRA TURN(S)";
			if (turns == 1) {
				string line = " " + to_string(turns)
					+ " EXTRA TURN";
			}
			log.PushPop(line);
		}
		else if (CardName == "Transfusion") {
			//swap current hp with enemy current hp
			int tempHp = guy.CurrentHealth;
			guy.CurrentHealth = enemy.CurrentHealth;
			enemy.CurrentHealth = tempHp;
		}

		else if (CardName == "Revivify") {
			//Heal 4 health and 2 mana for 5 turns
			guy.metabolise += 5;
			string line = "You heal for 5 more turns.";
			log.PushPop(line);
		}
		else if (CardName == "Steroids") {
			//Your next attack deals double damage
			guy.steroids = TRUE;
			string line = "You feel a boost in power.";
			log.PushPop(line);
		}
		else if (CardName == "Change Mind") {
			//Shuffle your hand. Gain 5 block
			guy.shuffle = TRUE;
			int block = gainBlock(5, guy, enemy);
			string line = "-You gain " + to_string(block) + " block.";
			log.PushPop(line);
		}
		else if (CardName == "Intimidate") {
			//Take half damage for 2 turns
			guy.intimidate += 2;
			string line = "You intimidate the " + string(enemy.Name) + ".";
			log.PushPop(line);
		}
		else if (CardName == "Cripple") {
			//Deal 25% of the enemy's health as damage
			int damage = int(enemy.CurrentHealth / 4);
			damage = dealDamage(damage, guy, enemy, log);
			string line = "-You cripple the " + string(enemy.Name)
						+ " for " + to_string(damage)
						+ " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Merge") {
			//Take 15 damage. Deal 6x(Skl) damage
			guy.TakeDamage(15);
			int damage = guy.Skill * 6;
			damage = dealDamage(damage, guy, enemy, log);

			string line = "-You take 15 damage and deal " + to_string(damage) + " damage.";
			log.PushPop(line);
		}
		else if (CardName == "Entomb") {
			//Enemy cannot take or deal damage for 2 turns
			guy.entomb += 2;
			string line = "-You entomb the " + string(enemy.Name) + ".";
			log.PushPop(line);
		}
		else if (CardName == "Distract") {
			//Remove enemy block. Gain an extra turn
			enemy.CurrentBlock = 0;
			guy.extraTurns++;

			string line = "-You remove the " + string(enemy.Name) + "'s block.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Prepare") {
			//Fill your hand with spells. Gain 5 mana and 1 turn
			guy.fillType = "Spell";
			guy.DrainMana(-5);
			guy.extraTurns++;
			string line = "-You gain 5 mana.";
			string line2 = " EXTRA TURN";
			log.PushPop(line);
			log.PushPop(line2);
		}
		else if (CardName == "Grow") {
			//Gain 1 Str for the battle
			guy.ModStat(1, "Strength");
			guy.strMod--;
			
			string line = "-You gain 1 Strength.";
			log.PushPop(line);
		}
		else if (CardName == "Solidify") {
			//Gain 1 Def for the battle
			guy.ModStat(1, "Defense");
			guy.defMod--;

			string line = "-You gain 1 Defense.";
			log.PushPop(line);
		}
		else if (CardName == "Learn") {
			//Gain 1 Int for the battle
			guy.ModStat(1, "Intelligence");
			guy.intMod--;

			string line = "-You gain 1 Intelligence.";
			log.PushPop(line);
		}
		else if (CardName == "Train") {
			//Gain 1 Skl for the battle
			guy.ModStat(1, "Skill");
			guy.sklMod--;

			string line = "-You gain 1 Skill.";
			log.PushPop(line);
		}
		else if (CardName == "Boost") {
			//Gain 6 mana. Can overcharge
			guy.CurrentMana += 5;
			guy.extraTurns++;

			string line = "-You gain 5 mana.";
			log.PushPop(line);
			string line2 = " EXTRA TURN";
			log.PushPop(line2);
		}
		else if (CardName == "Vitalise") {
			//Gain 15 health
			guy.TakeDamage(-15);

			string line = "You heal 15 health.";
			log.PushPop(line);
		}
		else if (CardName == "Jump") {
			//Fill your hand with attacks. Negate 1 attack
			guy.fillType = "Attack";
			guy.Negate++;

			string line = "-You negate the next attack.";
			log.PushPop(line);
		}
		else if (CardName == "Combo") {
			//Fill your hand with specials. Gain 1 turn
			guy.fillType = "Special";
		}
		else if (CardName == "Slam") {
			//Deal your block as damage
			int damage = guy.CurrentBlock;
			damage = dealDamage(damage, guy, enemy, log);

			string line = "You slam the " + string(enemy.Name)
						+ " for " + to_string(damage)
						+ " damage.";
			log.PushPop(line);
		}
	}
	//negatives
	if (CardType == "Negative") {
		if (CardName == "Steam") {
			//take 5 damage, get extra turn
			guy.TakeDamage(5);
			guy.extraTurns += 1;
			string line = "-You burn for 5 damage.";
			log.PushPop(line);
			string line2 = " EXTRA TURN";
			log.PushPop(line2);
		}
		else if (CardName == "Scalding Steam") {
			//take 5 damage, get extra turn
			guy.TakeDamage(12);
			guy.extraTurns += 1;
			string line = "-You burn for 12 damage.";
			log.PushPop(line);
			string line2 = " EXTRA TURN";
			log.PushPop(line2);
		}
		else if (CardName == "Webbed") {
			//-2 block
			if (guy.CurrentBlock < 0)
				guy.CurrentBlock++;
			else if (guy.CurrentBlock > 2)
				guy.CurrentBlock -= 2;
			else
				guy.CurrentBlock = 0;

			string line = "-You lose 2 block.";
			log.PushPop(line);
		}
		else if (CardName == "Tired") {
		//-2 block, -1 mana
			if (guy.CurrentBlock > 1)
				guy.CurrentBlock -= 2;
			else
				guy.CurrentBlock = 0;
			if (guy.CurrentMana > 0)
				guy.CurrentMana--;

			string line = "-You lose 2 block and 1 mana.";
			log.PushPop(line);
		}
		else if (CardName == "Drain Str") {
			guy.ModStat(-1, "Strength");
			guy.strMod++;
			string line = "You lose 1 strength.";
			log.PushPop(line);
		}
		else if (CardName == "Drain Def") {
			guy.ModStat(-1, "Defense");
			guy.defMod++;
			string line = "You lose 1 defense.";
			log.PushPop(line);
		}
		else if (CardName == "Drain Int") {
			guy.ModStat(-1, "Intelligence");
			guy.intMod++;
			string line = "You lose 1 intelligence.";
			log.PushPop(line);
		}
	}

	//check for Copy card
	while (!copyUsed && guy.copy > 0) {
		guy.copy--;
		guy.DrainMana(-1 * ManaCost);
		cardFunction(guy, enemy, log);
	}
	//Dizzy trait
	if (guy.Dizzy) {
		guy.shuffle = TRUE;
	}
}

int Card::dealDamage(int damage, Character &guy, Enemy &enemy, TextLog &log) {
	//Deadly trait
	if (damage > 0 && guy.Deadly) {
		damage *= 2;
	}
	//entomb
	if (guy.entomb > 0) {
		damage = 0;
	}
	//steroids
	if (guy.steroids) {
		damage *= 2;
		guy.steroids = FALSE;
	}
	//Sharp Claws trait
	if (guy.Sharp_Claws) {
		int claw = rtd(1, guy.Skill);
		damage += claw;
	}
	int damage2 = damage;
	if (enemy.invisible) {
		return 0;
	}
	if (enemy.enemyNegate > 0) {
		enemy.enemyNegate--;
		return 0;
	}
	if (damage < 0) {
		damage2 = 0;
	}
	if (pierce) {
		enemy.CurrentHealth -= damage2;
		pierce = FALSE;
	}
	else {
		if (enemy.CurrentBlock > damage2)
			enemy.CurrentBlock -= damage2;
		else {
			damage2 -= enemy.CurrentBlock;
			enemy.CurrentHealth -= damage2;
			enemy.CurrentBlock = 0;
		}
	}
	if (guy.damageToMana > 0) {
		int mana = damage2 - enemy.CurrentBlock;
		if (mana < 0)
			mana = 0;
		guy.DrainMana(-1 * mana);
		guy.damageToMana = 0;
		string line = "-You gain " + to_string(mana) + " mana.";
		log.PushPop(line);
	}

	return damage;
	enemy.updateEnemy(guy);
}

int Card::gainBlock(int block, Character &guy, Enemy &enemy) {
	int b = block;
	guy.CurrentBlock += b;
	return b;
}