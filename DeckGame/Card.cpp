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
void mvprintInSize(int starty, int startx, int maxx, const char* toBePrinted, bool Fuzzy);
WINDOW *makeWindow(int height, int width, int starty, int startx);
WINDOW *cardWindow;
//manually draw boxes
void manualBox(string typebox, int colorpair);

Card::Card() {
	CardName = "";
}

Card::Card(const char *name):CardName(name)
{
	CardName = name;
	ManaCost = 0;

//setting the card type and description
//the '$ ' are added to the description to manually create a new line if the mvprintInSize function doesn't do it
 //Attacks
	if (CardName == "Smack" ||
		CardName == "Magic Smack" ||
		CardName == "Charge" ||
		CardName == "Pierce" ||
		CardName == "Throw" ||
		CardName == "Impale" ||
		CardName == "Parry" ||
		CardName == "Feint" ||
		CardName == "Slice" ||
		CardName == "Crush" ||
		CardName == "Demolish" ||
		CardName == "Bleed" ||
		CardName == "Hack" ||
		CardName == "Stab" ||
		CardName == "Zap" ||
		CardName == "Ram" ||
		CardName == "Flay" ||
		CardName == "Slash" ||
		CardName == "Lash" ||
		CardName == "Pummel" ||
		CardName == "Shoot") {
		CardType = "Attack";
		setAttack();
	}
//Defends
	else if (CardName == "Endure" ||
		CardName == "Force Field" ||
		CardName == "Block" ||
		CardName == "Obstruct" ||
		CardName == "Disrupt" ||
		CardName == "Dodge" ||
		CardName == "Dash" ||
		CardName == "Brace" ||
		CardName == "Counter" ||
		CardName == "Predict" ||
		CardName == "Absorb" ||
		CardName == "Reinforce" ||
		CardName == "Flee" ||
		CardName == "Spikes" ||
		CardName == "Repulse" ||
		CardName == "Wall" ||
		CardName == "Toughen") {
		CardType = "Defend";
		setDefend();
	}
//Spells
	else if (CardName == "Ponder" ||
		CardName == "Channel" ||
		CardName == "Medidate" ||
		CardName == "Blast" ||
		CardName == "Leech" ||
		CardName == "Regenerate" ||
		CardName == "Transmute" ||
		CardName == "Blink" ||
		CardName == "Singularity" ||
		CardName == "Freeze" ||
		CardName == "Shard" ||
		CardName == "Fumes" ||
		CardName == "Smoke" ||
		CardName == "Incense" ||
		CardName == "Fireball" ||
		CardName == "Fuel" ||
		CardName == "Charm" ||
		CardName == "Attract" ||
		CardName == "Copy" ||
		CardName == "Confuse" ||
		CardName == "Lightning" ||
		CardName == "Shock" ||
		CardName == "Destroy" ||
		CardName == "Construct" ||
		CardName == "Beam" ||
		CardName == "Diffract" ||
		CardName == "Sap" ||
		CardName == "Synthesize" ||
		CardName == "Drown" ||
		CardName == "Refresh" ||
		CardName == "Reagent" ||
		CardName == "Reactant" ||
		CardName == "Transmogrify" ||
		CardName == "Liquidate" ||
		CardName == "Sandstorm" ||
		CardName == "Screen" ||
		CardName == "Laser") {
		CardType = "Spell";
		setSpell();
	}
//Specials
	else if (CardName == "Haste" ||
		CardName == "Transfusion" ||
		CardName == "Revivify" ||
		CardName == "Steroids" ||
		CardName == "Change Mind" ||
		CardName == "Intimidate" ||
		CardName == "Cripple" ||
		CardName == "Merge" ||
		CardName == "Entomb" ||
		CardName == "Distract" ||
		CardName == "Prepare" ||
		CardName == "Grow" ||
		CardName == "Solidify" ||
		CardName == "Learn" ||
		CardName == "Train" ||
		CardName == "Boost" ||
		CardName == "Vitalise" ||
		CardName == "Jump" ||
		CardName == "Combo" ||
		CardName == "Slam" ||
		CardName == "Stall" ||
		CardName == "Strike" ||
		CardName == "Defend" ||
		CardName == "Shimmer") {
		CardType = "Special";
		setSpecial();
	}
//Negatives
	else if (CardName == "Steam" ||
	CardName == "Scalding Steam" ||
	CardName == "Webbed" ||
	CardName == "Tired" ||
	CardName == "Drain Str" ||
	CardName == "Drain Def" ||
	CardName == "Drain Int" ||
	CardName == "Patch" ||
	CardName == "Mad") {
	CardType = "Negative";
	setNegative();
 }
}


Card::~Card()
{
}

void Card::setAttack() {
	if (CardName == "Smack") {
		//2d(Str)
		Description = "Deal 2d(Str) damage.";
	}
	else if (CardName == "Magic Smack") {
		//2d(Int)
		Description = "Deal 2d(Int) damage.";
	}
	else if (CardName == "Charge") {
		//7d(Str-5) damage, remove your block
		Description = "Deal 6d(Str-5) damage. Remove all your block.";
	}
	else if (CardName == "Pierce") {
		Description = "Deal 2d(Str) damage. Ignores block.";
	}
	else if (CardName == "Shoot") {
		Description = "Deal 2d(Str) damage. Take 7 damage. Extra turn.";
	}
	else if (CardName == "Throw") {
		Description = "Deal 1d(Str-2) damage. Extra turn.";
	}
	else if (CardName == "Impale") {
		Description = "Only usable for a killing blow. Deal 3x(Str) damage.";
	}
	else if (CardName == "Parry") {
		Description = "Deal (Str) damage. Negate the next attack.";
	}
	else if (CardName == "Feint") {
		Description = "Deal 2d(Str) damage. Fill your hand with Defends.";
	}
	else if (CardName == "Slice") {
		Description = "Deal (Str)d2 damage.";
	}
	else if (CardName == "Crush") {
		Description = "Deal 3d(Str) damage.";
	}
	else if (CardName == "Demolish") {
		Description = "Deal 3x(Str) damage. Lose 5 Str for the battle.";
	}
	else if (CardName == "Bleed") {
		Description = "Deal 2d(Str/2) damage for 4 rounds.";
	}
	else if (CardName == "Hack") {
		Description = "Deal 2d(Str) damage. Deals double to block.";
	}
	else if (CardName == "Stab") {
		Description = "Chance to deal either 1 or 12 damage. Extra turn.";
	}
	else if (CardName == "Zap") {
		Description = "Deal 1d(Int/2), gain an extra turn.";
	}
	else if (CardName == "Ram") {
		Description = "Deal (Def/2)d2 damage.";
	}
	else if (CardName == "Flay") {
		Description = "Deal 2d(Str) damage. Deal (Str/2) damage for 3 turns.";
	}
	else if (CardName == "Slash") {
		Description = "Deal (Str)d2 damage. Fill your hand with attacks.";
	}
	else if (CardName == "Lash") {
		Description = "Deal (Str)d3 damage. Take 6d2 damage.";
	}
	else if (CardName == "Pummel") {
		Description = "Deal 2 damage. Increase this damage by 2d(Str/2).";
	}
}
void Card::setDefend() {
	if (CardName == "Endure") {
		//(Def)+2
		Description = "Block for (Def)+2.";
	}
	else if (CardName == "Force Field") {
		//(Int)d2 block
		Description = "Block for (Int)d2.";
	}
	else if (CardName == "Block") {
		Description = "Negate the next 2 hits taken.";
	}
	else if (CardName == "Obstruct") {
		Description = "Gain (Def)d2 block.";
	}
	else if (CardName == "Disrupt") {
		Description = "Gain (Def)+2 block. Remove enemy block.";
	}
	else if (CardName == "Dodge") {
		Description = "Lose all block. Negate next hit taken, shuffle deck.";
	}
	else if (CardName == "Dash") {
		Description = "Gain 1d(Def) block. Extra turn.";
	}
	else if (CardName == "Brace") {
		Description = "Gain (Def) block. Fill your hand with Defends.";
	}
	else if (CardName == "Counter") {
		Description = "Gain (Def) block. Fill your hand with Attacks.";
	}
	else if (CardName == "Predict") {
		Description = "Gain (Def) block. Fill your hand with Spells.";
	}
	else if (CardName == "Absorb") {
		Description = "Gain (Def)x3 block. Lose a turn.";
	}
	else if (CardName == "Reinforce") {
		Description = "Gain 50% of your block.";
	}
	else if (CardName == "Flee") {
		Description = "Costs all of your block. Gain 2 extra turns.";
	}
	else if (CardName == "Spikes") {
		Description = "Gain (Def) damage. Deal 7 damage.";
	}
	else if (CardName == "Repulse") {
		Description = "Take 7 damage, negate the next hit. Extra turn.";
	}
	else if (CardName == "Wall") {
		Description = "Gain (Def)x3 block. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Toughen") {
		Description = "Gain 22 block. Burn this card.";
		naturalBurn = TRUE;
	}
}
void Card::setSpell() {
	if (CardName == "Ponder") {
		ManaCost = 0;
		Description = "Gain 2 mana.";
	}

	else if (CardName == "Channel") {
		//0 Mana
		//gain 3d(Int) mana
		ManaCost = 0;
		Description = "Recover 1d(Int) mana.";
	}
	else if (CardName == "Meditate") {
		//4 Mana
		//recover (Int)d3 current hp
		ManaCost = 4;
		Description = "Costs 4 mana. Recover (Int)d3 health.";
	}
	else if (CardName == "Blast") {
		ManaCost = 8;
		Description = "Costs 8 mana. Deal (Int)d2 damage. Extra turn.";
	}

	else if (CardName == "Leech") {
		ManaCost = 5;
		Description = "Costs 5 mana. Deal (Int)d2 damage and heal for that amount.";
	}
	else if (CardName == "Regenerate") {
		ManaCost = 5;
		Description = "Costs 5 mana. Heal 2+1d(Int) health for 5 turns.";
	}
	else if (CardName == "Transmute") {
		ManaCost = 0;
		Description = "Take 3d4 damage. Gain (Int) mana. Extra turn.";
	}

	else if (CardName == "Blink") {
		ManaCost = 3;
		Description = "Costs 3 mana. Deal 2d(Int) damage. Extra turn.";
	}
	else if (CardName == "Singularity") {
		ManaCost = 0;
		Description = "Gain (Int)+7 block and (Int) mana. Lose a turn.";
	}

	else if (CardName == "Freeze") {
		ManaCost = 10;
		Description = "Costs 10 mana. Gain 6+ 2d(Int) block.";
	}
	else if (CardName == "Shard") {
		ManaCost = 0;
		Description = "Take 6 damage. +3 mana. Deal (Int/2)d2 damage. Extra turn.";
	}

	else if (CardName == "Fumes") {
		ManaCost = 8;
		Description = "Costs 8 mana. Deal (Int/2)d2 damage for (Int) turns.";
	}
	else if (CardName == "Incense") {
		ManaCost = 0;
		Description = "Gain 3 mana and 5 block for (Int/2) turns.";
	}

	else if (CardName == "Fireball") {
		//5 mana
		//(Int)d5
		ManaCost = 5;
		Description = "Cost 5 mana. Deal (Int)d4 damage.";
	}
	else if (CardName == "Fuel") {
		ManaCost = 0;
		Description = "Gain mana for next unblocked damage dealt. Extra turn.";
	}

	else if (CardName == "Charm") {
		ManaCost = 4;
		Description = "Cost 4 mana. The next damage taken is dealt to the enemy.";
	}
	else if (CardName == "Attract") {
		ManaCost = 0;
		Description = "The next damage taken is gained as mana. Gain (Int)+3 block.";
	}

	else if (CardName == "Copy") {
		ManaCost = 6;
		Description = "Cost 6 mana. Use the next card twice. Extra turn.";
	}
	else if (CardName == "Confuse") {
		ManaCost = 0;
		Description = "Gain (Int)/2 mana. Extra turn.";
	}

	else if (CardName == "Lightning") {
		ManaCost = 1;
		Description = "Lose all your mana. Deal 1d(Int/2) damage (Mana) times.";
	}
	else if (CardName == "Shock") {
		ManaCost = 0;
		Description = "Gain 2 mana. Take 4 damage. Extra turn.";
	}

	else if (CardName == "Destroy") {
		ManaCost = 10;
		Description = "Costs 10 mana. Deal your block as damage, lose your block.";
	}
	else if (CardName == "Construct") {
		ManaCost = 0;
		Description = "Gain (Int/2) mana. Gain (Int)d2 block.";
	}

	else if (CardName == "Beam") {
		ManaCost = 3;
		Description = "Costs 3 mana. Deal (Int)d2 damage. Fill hand with Spells.";
	}
	else if (CardName == "Diffract") {
		ManaCost = 0;
		Description = "Gain 5 mana. Shuffle your hand.";
	}

	else if (CardName == "Sap") {
		ManaCost = 0;
		Description = "Deal 1d(Int) damage. Gain that much mana.";
	}
	else if (CardName == "Synthesize") {
		ManaCost = 10;
		Description = "Costs 10 mana. Heal for 8d(Int).";
	}

	else if (CardName == "Drown") {
		ManaCost = 0;
		Description = "Stop Refresh. Lose 1 mana and deal (Int)/2 damage every turn.";
	}
	else if (CardName == "Refresh") {
		ManaCost = 0;
		Description = "Stop Drown. Gain 1 mana every turn. Extra turn.";
	}

	else if (CardName == "Reagent") {
		ManaCost = 5;
		Description = "Cost 5 mana. Deal 1d4 damage for (Int) more turns.";
	}
	else if (CardName == "Reactant") {
		ManaCost = 0;
		Description = "Deal all Reagent damage at once. Gain (Int) mana.";
	}

	else if (CardName == "Transmogrify") {
		ManaCost = 5;
		Description = "Cost 5 mana. Gain (Int)d2 gold.";
	}
	else if (CardName == "Liquidate") {
		ManaCost = 0;
		Description = "Cost 10 gold. Deal 3d(Int) damage. Extra turn.";
	}

	else if (CardName == "Sandstorm") {
		ManaCost = 10;
		Description = "Cost 10 mana. Everybody takes 3d(Int) damage for 3 turns.";
	}
	else if (CardName == "Screen") {
		ManaCost = 0;
		Description = "Gain 4 mana. Negate the next 2 attacks.";
	}

	else if (CardName == "Laser") {
		ManaCost = 0;
		Description = "Deal (Skl)d2 damage to health and block. Extra turn.";
	}
}
void Card::setSpecial() {
	if (CardName == "Haste") {
		//2 extra turns
		Description = "2 extra turns. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Transfusion") {
		//switch current hp with enemy
		Description = "Switch current hp with enemy.";
	}

	else if (CardName == "Revivify") {
		Description = "Heal 6 health and 3 mana for 6 turns. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Steroids") {
		Description = "Your next attack deals double damage.";
	}
	else if (CardName == "Change Mind") {
		Description = "Shuffle your hand. Gain 5 block.";
	}
	else if (CardName == "Intimidate") {
		Description = "Take half damage for 3 turns. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Cripple") {
		Description = "Deal 40% of the enemy's health as damage. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Merge") {
		Description = "Deal 5x(Skl) damage. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Entomb") {
		Description = "Enemy can't take/deal damage for 4 turns. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Distract") {
		Description = "Remove enemy block. Extra turn.";
	}
	else if (CardName == "Prepare") {
		Description = "Fill hand with spells. Full mana. Extra turn. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Grow") {
		Description = "Gain 4 Str for the battle. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Solidify") {
		Description = "Gain 4 Def for the battle. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Learn") {
		Description = "Gain 4 Int for the battle. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Train") {
		Description = "Gain 2 Skl for the battle. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Boost") {
		Description = "Gain 5 mana. Extra turn.";
	}
	else if (CardName == "Vitalise") {
		Description = "Full health. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Jump") {
		Description = "Fill hand with attacks. Negate 1 attack. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Combo") {
		Description = "Fill your hand with Special cards. Extra turn. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Slam") {
		Description = "Deal your block as damage.";
	}
	else if (CardName == "Stall") {
		Description = "Extra turn.";
	}
	else if (CardName == "Strike") {
		Description = "Deal 3d(Str) damage.";
	}
	else if (CardName == "Defend") {
		Description = "Gain (Def)d3 block.";
	}
	else if (CardName == "Shimmer") {
		Description = "Deal damage equal to your gold.";
	}
}
void Card::setNegative() {
	if (CardName == "Steam") {
		Description = "Take 5 damage. Extra turn.";
	}
	else if (CardName == "Scalding Steam") {
		Description = "Take 12 damage. Extra turn.";
	}
	else if (CardName == "Webbed") {
		Description = "Lose 2 block.";
	}
	else if (CardName == "Tired") {
		Description = "Lose 2 block and 1 mana.";
	}
	else if (CardName == "Drain Str") {
		Description = "Lose 1 Strength.";
	}
	else if (CardName == "Drain Def") {
		Description = "Lose 1 Defense.";
	}
	else if (CardName == "Drain Int") {
		Description = "Lose 1 Intelligence.";
	}
	else if (CardName == "Patch") {
		Description = "Reduce bleeding by 7.";
	}
	else if (CardName == "Mad") {
		Description = "+2 and -2 to random stats for the battle. Extra turn.";
	}
}

void Card::printCard(int position) {
	/*init_pair(1, COLOR_YELLOW, COLOR_BLACK);

	init_pair(2, COLOR_CYAN, COLOR_BLACK);

	
	(COLOR_MAGENTA, 800, 0, 800);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);

	init_color(COLOR_BLACK, 700, 700, 700);
	init_pair(4, COLOR_BLACK, COLOR_BLACK);*/

	int mody = 18;
	int modx = 0;
	switch (position) {
	case 1:
		for (int i = 17; i < 23; i++) {
			mvprintw(i, 2, "                  ");
		}
		mvprintw(17, 2, "1)");
		modx = 9;
		break;
	case 2:
		for (int i = 17; i < 23; i++) {
			mvprintw(i, 22, "                  ");
		}
		mvprintw(17, 22, "2)");
		modx = 29;
		break;
	case 3:
		for (int i = 17; i < 23; i++) {
			mvprintw(i, 42, "                  ");
		}
		mvprintw(17, 42, "3)");
		modx = 49;
		break;
	case 4:
		for (int i = 17; i < 20; i++) {
			mvprintw(i, 61, "             ");
		}
		mvprintw(17, 62, "4)");
		modx = 63;
		break;
	}

	string mods = "";
	int modcounter = 0;
	if (Burn) {
		mods += "#rBurn#o";
		modcounter++;
	}
	if (Stay) {
		mods += "#gStay#o";
		modcounter++;
	}
	if (Flow) {
		mods += "#cFlow#o";
		modcounter++;
	}
	if (Copy) {
		mods += "#mCopy#o";
		modcounter++;
	}
	if (Push) {
		mods += "#yPush#o";
		modcounter++;
	}
	if (Void) {
		mods += "#oVoid#o";
		modcounter++;
	}
	if (Link != 0) {
		string s = to_string(Link);
		mods += "#bLink-" + s + "#o";
		modcounter++;
	}

	if (modcounter > 4 || position == 4) {
		mods = modchars();
		mvprintInSize(mody, modx+1, 0, mods.c_str(), FALSE);
	}
	else {
		modx -= int(mods.size() / 4) - 1;
		mvprintInSize(mody, modx, 0, mods.c_str(), FALSE);
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

	//const char* car;
	switch (position) {
	case 1:
		//car = CardName;
		mvprintInSize(17, 5, 15, CardName, FALSE);
		//car = Description;
		mvprintInSize(19, 4, 15, Description, FALSE);
		manualBox("Card 1", 0);
		break;
	case 2:
		//car = CardName;
		mvprintInSize(17, 25, 15, CardName, FALSE);
		//car = Description;
		mvprintInSize(19, 24, 15, Description, FALSE);
		manualBox("Card 2", 0);
		break;
	case 3:
		//car = CardName;
		mvprintInSize(17, 45, 15, CardName, FALSE);
		//car = Description;
		mvprintInSize(19, 44, 15, Description, FALSE);
		manualBox("Card 3", 0);
		break;
	case 4:
		mvprintw(17, 64, "            ");
		mvprintInSize(17, 64, 15, CardName, FALSE);
		manualBox("Card 4", 0);
		mods = modchars();
		mvprintInSize(mody, modx + 1, 0, mods.c_str(), FALSE);
		break;


	}
	standend();
	init_color(COLOR_BLACK, 0, 0, 0);
}

void Card::cardFunction(Character &guy, Enemy &enemy, TextLog &log) {
	//attacks
	if (CardType == "Attack") {
		attackFunction(guy, enemy, log);
	}
	//defends
	if (CardType == "Defend") {
		defendFunction(guy, enemy, log);
	}
	//spells (sorted by headgear)
	if (CardType == "Spell") {
		spellFunction(guy, enemy, log);
	}
	//specials
	if (CardType == "Special") {
		specialFunction(guy, enemy, log);
	}
	//negatives
	if (CardType == "Negative") {
		negativeFunction(guy, enemy, log);
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

void Card::attackFunction(Character &guy, Enemy &enemy, TextLog &log) {
	if (CardName == "Smack") {
		//do 2d(Str) dmg
		int damage = dealDamage(rtd(2, guy.Strength), guy, enemy, log);

		string line = "-You smack the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Magic Smack") {
		//do 2d(Int) dmg
		int damage = dealDamage(rtd(2, guy.Intelligence), guy, enemy, log);

		string line = "-You magically smack the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Charge") {
		//6d(Str-5) damage, remove your block
		int damage = dealDamage(rtd(6, guy.Strength - 5), guy, enemy, log);
		guy.CurrentBlock = 0;

		string line = "-You charge at the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage, #rlosing all your block.#o";
		log.PushPop(line);
	}
	else if (CardName == "Pierce") {
		//2d(Str) damage, ignoring block
		pierce = TRUE;
		int damage = dealDamage(rtd(2, guy.Strength), guy, enemy, log);

		string line = "-You #ypierce#o the " + string(enemy.Name)
			+ "'s block and deal #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Shoot") {
		//2d(Str) damage, take 7 damage, extra turn
		int damage = dealDamage(rtd(2, guy.Strength), guy, enemy, log);
		int selfdamage = guy.TakeDamage(7);
		guy.extraTurns += 1;

		string line = "-You shoot the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o and take #r" + to_string(selfdamage) + "#o.";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "Throw") {
		int damage = rtd(1, guy.Strength - 2);
		guy.extraTurns += 1;
		damage = dealDamage(damage, guy, enemy, log);

		string line = "-You hit the " + string(enemy.Name)
			+ " for #y" + to_string(damage) + "#o damage.";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "Impale") {
		//Can only be used to deal a killing blow. Deal 3x(Str) damage
		int damage = guy.Strength * 3;
		damage = dealDamage(damage, guy, enemy, log);

		string line = "-You impale the " + string(enemy.Name) + " for #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Parry") {
		int damage = guy.Strength;
		damage = dealDamage(damage, guy, enemy, log);
		guy.Negate++;

		string line = "-You #cnegate#o the next attack and parry for #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Feint") {
		int damage = rtd(2, guy.Strength);
		damage = dealDamage(damage, guy, enemy, log);
		guy.fillType = "Defend";
		//guy.extraTurns++;

		string line = "-You feint then deal #y" + to_string(damage) + "#o damage.";
		//string line2 = " EXTRA TURN";
		log.PushPop(line);
		//log.PushPop(line2);
	}
	else if (CardName == "Slice") {
		int damage = rtd(guy.Strength, 2);
		damage = dealDamage(damage, guy, enemy, log);

		string line = "-You slice the " + string(enemy.Name)
			+ " for #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Crush") {
		//do (Str)d3 dmg
		int damage = dealDamage(rtd(3, guy.Strength), guy, enemy, log);

		string line = "-You crush the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Demolish") {
		//do 3*(Str) dmg, lose 2 str
		int damage = dealDamage(3 * guy.Strength, guy, enemy, log);
		guy.ModStat(-5, "Strength");
		guy.strMod += 5;

		string line = "-You demolish the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Bleed") {
		//deal 2d(Str/2) damage for 4 rounds
		enemy.bleeding += 4;
		string line = "#y-You tear the " + string(enemy.Name)
			+ ", causing 4 extra rounds of bleed.#o";
		log.PushPop(line);
	}
	//hey dont screw this up with damage multipliers
	else if (CardName == "Hack") {
		//deal (Str)d2 damage, deals double to block
		int damageBlock;
		int damageHealth;
		string line;

		if (enemy.invisible > 0) {
			line = "-You hack the " + string(enemy.Name) + " for #y0#o damage.";
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
		line = "-You hack the " + string(enemy.Name) + " for #y" + to_string(damageBlock + damageHealth) + "#o damage.";
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
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "Zap") {
		//Deal 1d(Int/2), gain an extra turn
		int damage = rtd(1, int(guy.Intelligence / 2));
		damage = dealDamage(damage, guy, enemy, log);
		guy.extraTurns++;

		string line = "-You zap the " + string(enemy.Name) + " for #y" + to_string(damage) + "#o damage.";
		string line2 = " EXTRA TURN";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "Ram") {
		//Deal (Def/2)d2 damage
		int damage = rtd(int(guy.Defense/2), 2);
		damage = dealDamage(damage, guy, enemy, log);

		string line = "-You ram the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Flay") {
		//Deal 2d(Str) damage. Deal (Str/2) damage for 3 turns
		int damage = rtd(2, guy.Strength);
		damage = dealDamage(damage, guy, enemy, log);
		enemy.flay += 3;

		string line = "-You flay the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage and cause #y3 more rounds of bleed.#o";
		log.PushPop(line);
	}
	else if (CardName == "Slash") {
		//Deal (Str)d2 damage. Fill your hand with attacks
		int damage = rtd(guy.Strength, 2);
		damage = dealDamage(damage, guy, enemy, log);
		guy.fillType = "Attack";

		string line = "-You slash the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Lash") {
		//Deal (Str)d3 damage. Take 6d2 damage
		int damage = rtd(guy.Strength, 3);
		int sd = rtd(6, 2);

		damage = dealDamage(damage, guy, enemy, log);
		sd = guy.TakeDamage(sd);

		string line = "-You lash the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage and take #r" + to_string(sd)
			+ "#o.";
		log.PushPop(line);
	}
	else if (CardName == "Pummel") {
		//Deal (pummel) damage. Increase this damage by (Str/2)d2
		int damage = pummel;
		damage = dealDamage(damage, guy, enemy, log);
		pummel += rtd(2, int(guy.Strength / 2));

		string line = "-You pummel the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}

	//Horns trait
	if (CardType == "Attack" && guy.Horns) {
		if (rand() % 100 < guy.Skill + 7) {
			guy.Negate++;
			string horn = "#c-You negate the next attack.#o";
			log.PushPop(horn);
		}
	}
}
void Card::defendFunction(Character &guy, Enemy &enemy, TextLog &log) {
	if (CardName == "Endure") {
		//block for (Def)+2
		int block = gainBlock(guy.Defense + 2, guy, enemy);

		string line = "-You gain #c" + to_string(block)
			+ "#o block.";

		log.PushPop(line);
	}
	else if (CardName == "Force Field") {
		//block for (int)d2
		int block = gainBlock(rtd(guy.Intelligence, 2), guy, enemy);

		string line = "-You gain #c" + to_string(block)
			+ "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Block") {
		//negate 2 attacks
		guy.Negate+=2;

		string line = "-You #cnegate the next 2 attacks.#o";
		log.PushPop(line);
	}
	else if (CardName == "Obstruct") {
		//gain (Def)d2 block
		int block = rtd(guy.Defense, 2);
		gainBlock(block, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Disrupt") {
		//gain (Def)+2 block, remove enemy block
		int block = guy.Defense + 2;
		gainBlock(block, guy, enemy);
		enemy.CurrentBlock = 0;
		string line = "-You gain #c" + to_string(block)
			+ "#o block and #cremove the " + string(enemy.Name)
			+ "'s block.#o";
		log.PushPop(line);
	}
	else if (CardName == "Dodge") {
		//lose all block, negate next hit, shuffle deck
		guy.CurrentBlock = 0;
		guy.Negate++;
		guy.shuffle = TRUE;

		string line = "-You #rlose all your block#o and #cdodge the next hit.#o";
		log.PushPop(line);
	}
	else if (CardName == "Dash") {
		//gain 1d(Def) block, gain an extra turn
		int block = gainBlock(rtd(1, guy.Defense), guy, enemy);
		guy.extraTurns += 1;

		string line = "-You gain #c" + to_string(block) + "#o block.";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "Brace") {
		//gain (Def) block, fill your hand with blocks
		guy.fillType = "Defend";
		int block = gainBlock(guy.Defense, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Counter") {
		//gain (Def) block, fill your hand with attacks
		guy.fillType = "Attack";
		int block = gainBlock(guy.Defense, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Predict") {
		//gain (Def) block, fill your hand with spells
		guy.fillType = "Spell";
		int block = gainBlock(guy.Defense, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Absorb") {
		//Gain (Def)x3 block. Lose a turn.
		int block = gainBlock(guy.Defense*3, guy, enemy);
		guy.extraTurns--;

		string line = "-You gain #c" + to_string(block) + ".#o";
		log.PushPop(line);
	}
	else if (CardName == "Reinforce") {
		//gain 1.5x your block
		int block = int(guy.CurrentBlock / 2);
		gainBlock(block, guy, enemy);
		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Flee") {
		//only usable if you have block. lose all block, gain 2 extra turns
		guy.CurrentBlock = 0;
		guy.extraTurns += 2;

		string line = "#r-You lose all of your block.#o";
		string line2 = "#g 2 EXTRA TURNS#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "Spikes") {
		//gain (Def) block, deal 7 damage
		int block = gainBlock(guy.Defense, guy, enemy);
		int damage = dealDamage(7, guy, enemy, log);

		string line = "-You gain #c" + to_string(block) + "#o block and deal #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Repulse") {
		//Take 7 damage, negate the next hit. Gain an extra turn
		int damage = guy.TakeDamage(7);
		guy.Negate++;
		guy.extraTurns++;

		string line = "-You take #r" + to_string(damage) + "#o damage and #cnegate the next hit taken.#o";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "Wall") {
		//Gain (Def)x3 block. Burn this card
		int block = guy.Defense * 3;
		gainBlock(block, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Toughen") {
		//Gain 22 block. Burn this card
		int block = 22;
		block = gainBlock(block, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Mend") {
		//If you have block, increase it to (Def)x2
		int block = 0;
		if (guy.CurrentBlock > 0 && guy.CurrentBlock < guy.Defense * 2)
			guy.CurrentBlock = guy.Defense * 2;

		string line = "#c-Your armor mends itself.";
		log.PushPop(line);
	}

	//Dexterous trait
	if (guy.Dexterous && CardType == "Defend") {
		int ddamage = guy.Skill;
		dealDamage(ddamage, guy, enemy, log);
	}
}
void Card::spellFunction(Character &guy, Enemy &enemy, TextLog &log) {
	guy.CurrentMana -= ManaCost;
	//no headgear
	if (CardName == "Ponder") {
		int mana = 2;
		guy.DrainMana(-1 * mana);
		string line = "#m-You gain " + to_string(mana) + " mana.#o";
	}

	else if (CardName == "Channel") {
		//gain 1d(Int) mana
		ManaCost = (-1)*rtd(1, guy.Intelligence);
		int mana = ManaCost * -1;
		guy.DrainMana(ManaCost);

		string line = "#m-You regain " + to_string(mana)
			+ " mana.#o";
		log.PushPop(line);
	}
	else if (CardName == "Meditate") {
		//costs 4 mana. gain (int)d3 hp
		int heal = -1 * rtd(guy.Intelligence, 3);
		guy.TakeDamage(heal);

		heal *= -1;
		/*string line = "-You recover #y" + to_string(heal)
			+ "#o health.";*/
		string line = "-You recover #g" + to_string(heal)
			+ "#o health.";
		log.PushPop(line);
	}
	else if (CardName == "Blast") {
		//Cost 8 mana. Deal (Int)d2 damage. Extra turn.
		int damage = dealDamage(rtd(guy.Intelligence, 2), guy, enemy, log);
		guy.extraTurns++;

		string line = "-You blast the " + string(enemy.Name) + " for #y" + to_string(damage) + "#o damage.";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}

	else if (CardName == "Leech") {
		//cost 5 mana, deal (Int)d2 damage, gain that much hp
		int damage = dealDamage(rtd(guy.Intelligence, 2), guy, enemy, log);
		if (enemy.invisible <= 0)
			guy.TakeDamage(-1 * damage);

		string line = "#m-You steal #g" + to_string(damage)
			+ "#m health from the " + string(enemy.Name)
			+ ".#o";
		log.PushPop(line);
	}
	else if (CardName == "Regenerate") {
		//5 mana, heal 2+1d(int) for 5 turns
		guy.regenerateTurns += 5;
		string line = "#m-You regenerate for 5 more turns.#o";
		log.PushPop(line);
	}
	else if (CardName == "Transmute") {
		//take 3d4 damage, gain (Int) mana, extra turn
		int damage = rtd(3, 4);
		guy.TakeDamage(damage);
		int mana = -1 * guy.Intelligence;
		guy.DrainMana(mana);
		guy.extraTurns++;

		string line = "-You take #r" + to_string(damage)
			+ "#o damage and gain #m" + to_string(guy.Intelligence)
			+ " mana.#o";
		string line2 = "#g EXTR TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}

	else if (CardName == "Blink") {
		//cost 3 mana, deal 2d(Int) damage, gain an extra turn
		int damage = dealDamage(rtd(2, guy.Intelligence), guy, enemy, log);
		guy.extraTurns += 1;

		string line = "-You blink and deal #y" + to_string(damage)
			+ "#o damage to the " + string(enemy.Name) + ".";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "Singularity") {
		//gain (Int) block and (Int) mana, lose a extra turn
		int block = gainBlock(guy.Intelligence + 7, guy, enemy);
		int mana = guy.Intelligence;
		guy.DrainMana(-1 * mana);
		guy.extraTurns--;

		string line = "-You gain #c" + to_string(block)
			+ "#o block and #m" + to_string(mana)
			+ "#o mana.";
		log.PushPop(line);
	}

	else if (CardName == "Freeze") {
		//Costs 6 mana. Gain 6+(Int)d2 block
		int block = 6 + rtd(guy.Intelligence, 3);
		block = gainBlock(block, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Shard") {
		//Take 6 damage. +3 mana. Deal (Int/2)d2 damage. Extra turn."
		int selfdamage = guy.TakeDamage(6);
		int damage = rtd(int(guy.Intelligence / 2), 2);
		damage = dealDamage(damage, guy, enemy, log);
		guy.DrainMana(-3);
		guy.extraTurns++;

		string line = "-You deal #y" + to_string(damage)
			+ "#o damage, take #r" + to_string(selfdamage)
			+ "#o and #mgain 3 mana#o.";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}

	else if (CardName == "Fumes") {
		//Costs 8 mana. Deal (Int/2)d2 damage for (Int) turns
		int turns = guy.Intelligence;
		enemy.fumes += turns;
		string line = "#m-You release toxic fumes#o for " + to_string(turns) + " more turns.#o";
		log.PushPop(line);
	}
	else if (CardName == "Incense") {
		//Gain 3 mana and 5 block for (Int/2) turns
		int turns = (guy.Intelligence/2);
		guy.incense += turns;
		string line = "#m-You burn incense#o for #m" + to_string(turns) + " more turns.#o";
		log.PushPop(line);
	}

	else if (CardName == "Fireball") {
		//5 mana
		//do (Int)d4 dmg
		int damage = dealDamage(rtd((int)(guy.Intelligence), 4), guy, enemy, log);


		string line = "-You lob a fireball at the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Fuel") {
		//on the next turn, gain mana for unblocked damage dealt
		guy.damageToMana += 2;
		guy.extraTurns++;
		string line = "#m -You prepare to attack.#o";
		log.PushPop(line);
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line2);
	}

	else if (CardName == "Charm") {
		//Cost 4 mana, The next damage taken is dealt to the enemy
		guy.mirror++;
		string line = "#m-You prepare for the " + string(enemy.Name) + "'s next attack.#o";
		log.PushPop(line);
	}
	else if (CardName == "Attract") {
		//the next damage taken is gained as mana. Gain (Int)+3 block
		guy.charge++;
		int block = guy.Intelligence + 3;
		block = gainBlock(block, guy, enemy);
		string line = "#m-You attract the " + string(enemy.Name) + " and gain #c" + to_string(block) + "#m block.#o";
		log.PushPop(line);
	}
	else if (CardName == "Copy") {
		//Cost 6 mana. Use your next card twice
		guy.copy++;
		guy.extraTurns++;

		string line = "#m-You prepare a copy of your next card.#o";
		log.PushPop(line);
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line2);
		copyUsed = TRUE;
	}
	else if (CardName == "Confuse") {
		//Gain (Int)/2 mana, gain an extra turn
		int mana = int(guy.Intelligence / 2);
		guy.DrainMana(-1 * mana);
		guy.extraTurns++;
		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}

	else if (CardName == "Lightning") {
		//Lose all your mana. Deal 1d(Int/2) damage (Mana) times.
		int total = 0;
		for (int i = 0; i < guy.CurrentMana + 1; i++) {
			int damage = rtd(1, int(guy.Intelligence / 2));
			damage = dealDamage(damage, guy, enemy, log);
			total += damage;
		}
		string line;
		if (guy.CurrentMana == 0) {
			line = "-You electrocute the " + string(enemy.Name) + " #m"
				+ to_string(guy.CurrentMana + 1) + " time#o for a total of #y" + to_string(total)
				+ "#o damage.";
		}
		else {
			line = "-You electrocute the " + string(enemy.Name) + " #m"
				+ to_string(guy.CurrentMana + 1) + " times#o for a total of #y" + to_string(total)
				+ "#o damage.";
		}
		log.PushPop(line);

		guy.CurrentMana = 0;
	}
	else if (CardName == "Shock") {
		//Gain 2 mana. Take 4 damage. Extra turn
		guy.DrainMana(-2);
		guy.extraTurns++;
		int damage = guy.TakeDamage(4);

		string line = "-You #mgain 2 mana#o and take #r" + to_string(damage) + "#o damage.";
		log.PushPop(line);
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line2);
	}

	else if (CardName == "Destroy") {
		//Costs 10 mana. Deal your block as damage, lose your block
		int damage = guy.CurrentBlock;
		damage = dealDamage(damage, guy, enemy, log);
		guy.CurrentBlock = 0;

		string line = "-You destroy the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage and #rlose your block.#o";
		log.PushPop(line);
	}
	else if (CardName == "Construct") {
		//Gain (Int/2) mana. Gain (Int)d2 block
		int block = rtd(guy.Intelligence, 2);
		int mana = int(guy.Intelligence / 2);
		gainBlock(block, guy, enemy);
		guy.DrainMana(-1 * mana);

		string line = "-You #mgain " + to_string(guy.Intelligence)
			+ " mana#o and #c" + to_string(block)
			+ "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Beam") {
		//Costs 3 mana. Deal (Int)d2 damage. Fill your hand with Spells
		int damage = dealDamage(rtd(guy.Intelligence, 2), guy, enemy, log);
		guy.fillType = "Spell";

		string line = "-You sear the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Diffract") {
		//Gain 3 mana. Shuffle your hand. Extra turn
		int mana = 2;
		guy.DrainMana(-1 * mana);
		guy.shuffle = TRUE;
		//guy.extraTurns++;

		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		//log.PushPop(line2);
	}
	else if (CardName == "Sap") {
		//Deal 1d(Int) damage. Gain that much mana
		int damage = rtd(1, guy.Intelligence);
		int mana = damage;
		damage = dealDamage(damage, guy, enemy, log);
		guy.DrainMana(-1 * mana);

		string line = "-You deal #y" + to_string(damage)
			+ "#o damage and #mgain " + to_string(mana)
			+ " mana#o.";
		log.PushPop(line);
	}
	else if (CardName == "Synthesize") {
		//Costs 10 mana. Heal for 8d(Int)
		int health = rtd(8, guy.Intelligence);
		guy.TakeDamage(-1 * health);

		string line = "-You heal for #g" + to_string(health) + "#o.";
		log.PushPop(line);
	}
	else if (CardName == "Drown") {
		//Stop Refresh. Lose 1 mana and deal (Int)/2 damage every turn
		guy.refresh = 0;
		guy.drown++;

		string line = "#m-You begin to drown the " + string(enemy.Name) + ".#o";
		log.PushPop(line);
	}
	else if (CardName == "Refresh") {
		//Stop Drown. Gain 1 mana every turn. Extra turn
		guy.drown = 0;
		guy.refresh++;
		guy.extraTurns++;

		string line = "#m-You begin to refresh your mana.#o";
		string line2 = "#g EXTRA TURN";
		log.PushPop(line);
		log.PushPop(line2);
	}
	
	else if (CardName == "Reagent") {
		//Costs 5 mana. deal 1d4 damage for (Int) more turns
		int turns = guy.Intelligence;
		guy.reagent += turns;
		string line = "#m-You release some gas for " + to_string(turns) + " more turns.#o";
		log.PushPop(line);
	}
	else if (CardName == "Reactant") {
		//deal all reagent damage at once. gain (Int) mana
		int mana = guy.Intelligence;
		guy.DrainMana(-1 * mana);
		int damage = 0;
		for (guy.reagent; guy.reagent > 0; guy.reagent--) {
			damage += rtd(1, 4);
		}
		damage = dealDamage(damage, guy, enemy, log);
		string line = " #mYou strike a match.#o";
		string line2 = "#m-The gas reacts, dealing #y" + to_string(damage) + "#m damage to the " + string(enemy.Name) + ".#o";
		string line3 = "#m-You gain " + to_string(mana) + " mana.#o";
		log.PushPop(line);
		log.PushPop(line2);
		log.PushPop(line3);
	}
	else if (CardName == "Transmogrify") {
		//Cost 5 mana. gain (Int)d2 gold
		int gold = rtd(guy.Intelligence, 2);
		if (guy.Gold_Blood)
			gold *= 2;
		guy.Gold += gold;

		string line = "#y-You gain " + to_string(gold) + " gold.";
		log.PushPop(line);
	}
	else if (CardName == "Liquidate") {
		//Cost 10 gold. Deal 3d(Int) damage. Extra turn.
		if (guy.Gold >= 10)
			guy.Gold -= 10;
		else
			guy.Gold = 0;

		int damage = rtd(3, guy.Intelligence);
		damage = dealDamage(damage, guy, enemy, log);
		guy.extraTurns++;
		
		string line = "-You #rlose 10 gold#o to deal #y" + to_string(damage) + "#o damage.";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}

	else if (CardName == "Sandstorm") {
		//Cost 10 mana. Everybody takes 3d(Int) damage for 3 turns
		enemy.sandstorm += 3;

		string line = "#m-You stir up a sandstorm.#o";
		log.PushPop(line);
	}
	else if (CardName == "Screen") {
		//Gain 4 mana. Negate the next 2 attacks
		int mana = 4;
		guy.DrainMana(-1 * mana);
		guy.Negate+=2;

		string line = "-You #mgain " + to_string(mana) + " mana#o and #cnegate the next 2 hits taken#o.";
		log.PushPop(line);
	}

	else if (CardName == "Laser") {
		//Deal (Skl)d2 damage to health and block. Extra turn.
		int damageH = rtd(guy.Skill, 2);
		int damageB = rtd(guy.Skill, 2);
		if (damageB > enemy.CurrentBlock) {
			damageB = enemy.CurrentBlock;
			enemy.CurrentBlock = 0;
		}
		else
			enemy.CurrentBlock -= damageB;

		enemy.CurrentHealth -= damageH;
		guy.extraTurns++;

		string line = "-You incinerate the " + string(enemy.Name)
			+ " for #y" + to_string(damageB + damageH)
			+ "#o damage.";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}

	//Photosynthesis trait
	if (guy.Photosynthesis && CardType == "Spell") {
		int health = guy.Skill;
		guy.TakeDamage(-1 * health);
	}
}
void Card::specialFunction(Character &guy, Enemy &enemy, TextLog &log) {
	if (CardName == "Haste") {
		//2 extra turns
		guy.extraTurns += 2;

		string line = "#g 2 EXTRA TURNS#o";
		log.PushPop(line);
	}
	else if (CardName == "Transfusion") {
		//swap current hp with enemy current hp
		int tempHp = guy.CurrentHealth;
		guy.CurrentHealth = enemy.CurrentHealth;
		enemy.CurrentHealth = tempHp;
	}

	else if (CardName == "Revivify") {
		//Heal 6 health and 3 mana for 6 turns. Burn
		guy.metabolise += 6;
		string line = "#g-You heal for 6 turns.#o";
		log.PushPop(line);
	}
	else if (CardName == "Steroids") {
		//Your next attack deals double damage
		guy.steroids = TRUE;
		string line = "#y-You feel a boost in power.#o";
		log.PushPop(line);
	}
	else if (CardName == "Change Mind") {
		//Shuffle your hand. Gain 5 block
		guy.shuffle = TRUE;
		int block = gainBlock(5, guy, enemy);
		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Intimidate") {
		//Take half damage for 3 turns. Burn
		guy.intimidate += 3;
		string line = "#cYou intimidate the " + string(enemy.Name) + ".#o";
		log.PushPop(line);
	}
	else if (CardName == "Cripple") {
		//Deal 40% of the enemy's health as damage. Burn
		int damage = int(enemy.CurrentHealth*2/5);
		damage = dealDamage(damage, guy, enemy, log);
		string line = "-You cripple the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Merge") {
		//Deal 7x(Skl) damage. Burn
		int damage = guy.Skill * 5;
		damage = dealDamage(damage, guy, enemy, log);

		string line = "-You merge with the " + string(enemy.Name) + " for #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Entomb") {
		//Enemy cannot take or deal damage for 4 turns. Burn
		guy.entomb += 4;
		string line = "#c-You entomb the " + string(enemy.Name) + ".#m";
		log.PushPop(line);
	}
	else if (CardName == "Distract") {
		//Remove enemy block. Gain an extra turn
		enemy.CurrentBlock = 0;
		guy.extraTurns++;

		string line = "#c-You remove the " + string(enemy.Name) + "'s block.#o";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "Prepare") {
		//Fill hand with spells. Full mana. Extra turn. Burn this card
		guy.fillType = "Spell";
		guy.CurrentMana = guy.MaxMana;
		guy.extraTurns++;
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line2);
	}
	else if (CardName == "Grow") {
		//Gain 4 Str for the battle. Burn
		guy.ModStat(4, "Strength");
		guy.strMod-=4;

		string line = "#g-You gain 3 Strength.#o";
		log.PushPop(line);
	}
	else if (CardName == "Solidify") {
		//Gain 4 Def for the battle. Burn
		guy.ModStat(4, "Defense");
		guy.defMod-=4;

		string line = "#g-You gain 3 Defense.#o";
		log.PushPop(line);
	}
	else if (CardName == "Learn") {
		//Gain 4 Int for the battle. Burn
		guy.ModStat(4, "Intelligence");
		guy.intMod-=4;

		string line = "#g-You gain 3 Intelligence.#o";
		log.PushPop(line);
	}
	else if (CardName == "Train") {
		//Gain 2 Skl for the battle. Burn
		guy.ModStat(2, "Skill");
		guy.sklMod-=2;

		string line = "#g-You gain 2 Skill.#o";
		log.PushPop(line);
	}
	else if (CardName == "Boost") {
		//Gain 5 mana. extra turn
		guy.DrainMana(-5);
		guy.extraTurns++;

		string line = "#m-You gain 5 mana.#o";
		log.PushPop(line);
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line2);
	}
	else if (CardName == "Vitalise") {
		//Full health. Burn this card.
		guy.CurrentHealth = guy.MaxHealth;

		string line = "#gYou heal to full health.#o";
		log.PushPop(line);
	}
	else if (CardName == "Jump") {
		//Fill hand with attacks. Negate 1 attack. Burn this card.
		guy.fillType = "Attack";
		guy.Negate++;

		string line = "#c-You negate the next attack.#o";
		log.PushPop(line);
	}
	else if (CardName == "Combo") {
		//Fill your hand with boss cards. Extra turn. Burn this card.
		guy.fillType = "Special";
		guy.extraTurns++;
		string line = "#g EXTRA TURN#o";
		log.PushPop(line);
	}
	else if (CardName == "Slam") {
		//Deal your block as damage
		int damage = guy.CurrentBlock;
		damage = dealDamage(damage, guy, enemy, log);

		string line = "You slam the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Stall") {
		//extra turn
		guy.extraTurns++;
		string line = "#g EXTRA TURN#o";
		log.PushPop(line);
	}
	else if (CardName == "Strike") {
		//deal 3d(Str) damage
		int damage = dealDamage(rtd(3, guy.Strength), guy, enemy, log);

		string line = "You strike the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Defend") {
		//gain (Def)d3 block
		int block = gainBlock(rtd(guy.Defense, 3), guy, enemy);

		string line = "You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Shimmer") {
		//deal gold damage
		int damage = guy.Gold;
		damage = dealDamage(damage, guy, enemy, log);

		string line = "-You deal #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
}
void Card::negativeFunction(Character &guy, Enemy &enemy, TextLog &log) {
	if (CardName == "Steam") {
		//take 5 damage, get extra turn
		guy.TakeDamage(5);
		guy.extraTurns += 1;
		string line = "-You burn for #r5#o damage.";
		log.PushPop(line);
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line2);
	}
	else if (CardName == "Scalding Steam") {
		//take 5 damage, get extra turn
		guy.TakeDamage(12);
		guy.extraTurns += 1;
		string line = "-You burn for #r12#o damage.";
		log.PushPop(line);
		string line2 = "#g EXTRA TURN#o";
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

		string line = "-You #rlose 2 block.#o";
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

		string line = "-You lose #r2 block and 1 mana.#o";
		log.PushPop(line);
	}
	else if (CardName == "Drain Str") {
		guy.ModStat(-1, "Strength");
		guy.strMod++;
		string line = "-You #rlose 1 Strength.#o";
		log.PushPop(line);
	}
	else if (CardName == "Drain Def") {
		guy.ModStat(-1, "Defense");
		guy.defMod++;
		string line = "You #rlose 1 Defense.#o";
		log.PushPop(line);
	}
	else if (CardName == "Drain Int") {
		guy.ModStat(-1, "Intelligence");
		guy.intMod++;
		string line = "-You #rlose 1 Intelligence.#o";
		log.PushPop(line);
	}
	else if (CardName == "Patch") {
		guy.dotDamage -= 7;
		if (guy.dotDamage < 0)
			guy.dotDamage = 0;
		string line = "#g-You reduce your bleeding.#o";
		log.PushPop(line);
	}
	else if (CardName == "Mad") {
		int rng = rand() % 6;
		switch (rng) {
		case 0:
			guy.ModStat(2, "Strength");
			guy.strMod -= 2;
			break;
		case 1:
			guy.ModStat(2, "Defense");
			guy.defMod -= 2;
			break;
		case 2:
			guy.ModStat(2, "Intelligence");
			guy.intMod -= 2;
			break;
		case 3:
			guy.ModStat(2, "MaxHealth");
			guy.hpMod -= 2;
			break;
		case 4:
			guy.ModStat(2, "MaxMana");
			guy.mpMod -= 2;
			break;
		case 5:
			guy.ModStat(2, "Skill");
			guy.sklMod -= 2;
			break;
		}
		rng = rand() % 6;
		switch (rng) {
		case 0:
			guy.ModStat(-2, "Strength");
			guy.strMod += 2;
			break;
		case 1:
			guy.ModStat(-2, "Defense");
			guy.defMod += 2;
			break;
		case 2:
			guy.ModStat(-2, "Intelligence");
			guy.intMod += 2;
			break;
		case 3:
			guy.ModStat(-2, "MaxHealth");
			guy.hpMod += 2;
			break;
		case 4:
			guy.ModStat(-2, "MaxMana");
			guy.mpMod += 2;
			break;
		case 5:
			guy.ModStat(-2, "Skill");
			guy.sklMod += 2;
			break;
		}
		guy.extraTurns++;
		string line = "#r-You go a bit mad.#o";
		string line2 = "#g EXTRA TURN#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
}

int Card::dealDamage(int damage, Character &guy, Enemy &enemy, TextLog &log) {
	//Frenzy trait
	if (damage > 0 && guy.Frenzy) {
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
	//invisibility
	if (enemy.invisible > 0) {
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
		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		log.PushPop(line);
	}

	return damage;
	enemy.updateEnemy(guy);
}

int Card::gainBlock(int block, Character &guy, Enemy &enemy) {
	int b = block;
	if (b < 0)
		b = 0;
	else {
		//Charred Skin trait
		if (guy.Charred_Skin)
			guy.TakeDamage(-1 * b);
		else
			guy.CurrentBlock += b;
	}
	return b;
}

void Card::setMod(string Mod, bool On, Character &guy) {
	if (Mod == "Burn") {
		if (On) {
			Burn = TRUE;
		}
		else {
			Burn = FALSE;
		}
	}
	else if (Mod == "Stay") {
		if (On) {
			Stay = TRUE;
		}
		else {
			Stay = FALSE;
		}
	}
	else if (Mod == "Flow") {
		if (On) {
			Flow = TRUE;
		}
		else {
			Flow = FALSE;
		}
	}
	else if (Mod == "Copy") {
		if (On) {
			Copy = TRUE;
		}
		else {
			Copy = FALSE;
		}
	}
	else if (Mod == "Push") {
		if (On) {
			Push = TRUE;
		}
		else {
			Push = FALSE;
		}
	}
	else if (Mod == "Void") {
		if (On) {
			Void = TRUE;
		}
		else {
			Void = FALSE;
		}
	}
	else if (Mod == "Link") {
		if (On) {
			for (int y = 0; y < 15; y++) {
				mvprintw(y, 44, "                                  ");
			}
			string m = "Choose a position in the chain (1-9). 1 draws 2, 2 draws 3, and so on. The chain stops at the last number. 0 removes the Link from the card.";
			mvprintInSize(2, 47, 25, m.c_str(), FALSE);

			char chain = getch();
			if (chain == 27) {
				guy.Link++;
				return;
			}
			else if (chain == '0') {
				Link = 0;
				guy.Link++;
			}
			else if (chain == '1' ||
				chain == '2' ||
				chain == '3' ||
				chain == '4' ||
				chain == '5' ||
				chain == '6' ||
				chain == '7' ||
				chain == '8' ||
				chain == '9') {
				Link = chain - '0';
			}
			else {
				setMod(Mod, On, guy);
			}
		}
		else {
			Link = 0;
			guy.Link++;
		}
	}
}

string Card::modchars() {
	string charline = "";
	if (Burn) {
		charline += "#rB#o";
	}
	if (Stay) {
		charline += "#gS#o";
	}
	if (Flow) {
		charline += "#cF#o";
	}
	if (Copy) {
		charline += "#mC#o";
	}
	if (Push) {
		charline += "#yP#o";
	}
	if (Void) {
		charline += "#oV#o";
	}
	if (Link != 0) {
		string s = to_string(Link);
		charline += "#bL" + s + "#o";
	}
	return charline;
}

string Card::modstrings() {
	string mods = "";
	if (Burn) {
		mods += "#rBurn#o";
	}
	if (Stay) {
		mods += "#gStay#o";
	}
	if (Flow) {
		mods += "#cFlow#o";
	}
	if (Copy) {
		mods += "#mCopy#o";
	}
	if (Push) {
		mods += "#yPush#o";
	}
	if (Void) {
		mods += "#oVoid#o";
	}
	if (Link != 0) {
		string s = to_string(Link);
		mods += "#bLink-" + s + "#o";
	}
	return mods;
}

void Card::removeMods(Character &guy) {
	if (Burn)
		guy.Burn++;
	if (Stay)
		guy.Stay++;
	if (Flow)
		guy.Flow++;
	if (Copy)
		guy.Copy++;
	if (Push)
		guy.Push++;
	if (Void)
		guy.Void++;
	if (Link != 0)
		guy.Link++;

	Burn = FALSE;
	Stay = FALSE;
	Flow = FALSE;
	Copy = FALSE;
	Push = FALSE;
	Void = FALSE;
	Link = 0;
}

bool Card::checkSameMods(Card kard) {
	bool same = TRUE;
	if (Burn != kard.Burn)
		same = FALSE;
	if (Stay != kard.Stay)
		same = FALSE;
	if (Flow != kard.Flow)
		same = FALSE;
	if (Copy != kard.Copy)
		same = FALSE;
	if (Push != kard.Push)
		same = FALSE;
	if (Void != kard.Void)
		same = FALSE;
	if (Link != kard.Link)
		same = FALSE;
	return same;
}
