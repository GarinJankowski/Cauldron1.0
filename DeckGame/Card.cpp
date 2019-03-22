#include "pch.h"
#include "Card.h"

//List of Cards
//Attacks:
//	Smack, Charge, Pierce, Shoot
//Defends:
// Endure, Forcefield, Block
//Spells:
// Fireball, Channel, Meditate, Leech
//bosss:
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
		CardName == "Shoot" ||
		CardName == "Rend" ||
		CardName == "Ritual" ||
		CardName == "Prick" ||
		CardName == "Laser") {
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
		CardName == "Toughen" ||
		CardName == "Gamble" ||
		CardName == "Inspire" ||
		CardName == "Bide" ||
		CardName == "Restore" ||
		CardName == "Form" ||
		CardName == "Tear" ||
		CardName == "Barrier" ||
		CardName == "Defend") {
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
		CardName == "Empower" ||
		CardName == "Shed" ||
		CardName == "Extract" ||
		CardName == "Drain" ||
		CardName == "Soldier" ||
		CardName == "Attack" ||
		CardName == "Arise" ||
		CardName == "The Flesh" ||
		CardName == "Rainbow" ||
		CardName == "Focus" ||
		CardName == "Horrify" ||
		CardName == "Lurk" ||
		CardName == "Screech" ||
		CardName == "Echo" ||
		CardName == "Judge" ||
		CardName == "Bless" ||
		CardName == "Aegis" ||
		CardName == "Steadfast") {
		CardType = "Spell";
		setSpell();
	}
//bosss
	else if (CardName == "Haste" ||
		CardName == "Revivify" ||
		CardName == "Steroids" ||
		CardName == "Change Mind" ||
		CardName == "Intimidate" ||
		CardName == "Distract" ||
		CardName == "Prepare" ||
		CardName == "Boost" ||
		CardName == "Vitalise" ||
		CardName == "Jump" ||
		CardName == "Slam" ||
		CardName == "Stall" ||
		CardName == "Repel" ||
		CardName == "Ghost" ||
		CardName == "Catalyze" ||
		CardName == "Detonate" ||
		CardName == "Polymorph" ||
		CardName == "Cleanse" ||
		CardName == "Teleport" ||
		CardName == "Inject" ||
		CardName == "Flurry" ||
		CardName == "Materialize" ||
		CardName == "Overdrive" ||
		CardName == "Enrich" ||
		CardName == "Shimmer" ||
		CardName == "Relax" ||
		CardName == "Sharpen" ||
		CardName == "Amplify" ||
		CardName == "Cell" ||
		CardName == "Deflect" ||
		CardName == "Save" ||
		CardName == "Stop" ||
		CardName == "Chaos") {
		CardType = "BossCard";
		setboss();
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
	CardName == "Mad" ||
	CardName == "Burn") {
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
		Description = "Deal 6d(Str-5) damage. Remove all your block. -2 Energy.";
	}
	else if (CardName == "Pierce") {
		Description = "Deal 2d(Str) damage. Ignores block.";
	}
	else if (CardName == "Shoot") {
		Description = "Deal 2d(Str) damage. Take 7 damage. +12 Energy.";
	}
	else if (CardName == "Throw") {
		Description = "Deal 2d(Str/2) damage. +8 Energy.";
	}
	else if (CardName == "Impale") {
		Description = "Only usable for a killing blow. Deal 3x(Str) damage.";
	}
	else if (CardName == "Parry") {
		Description = "Deal (Str) damage. Negate the next attack.";
	}
	else if (CardName == "Feint") {
		Description = "Deal 2d(Str). Fill hand with Defends. +3 Energy.";
	}
	else if (CardName == "Slice") {
		Description = "Deal (Str)d2 damage.";
	}
	else if (CardName == "Crush") {
		Description = "Deal 3d(Str) damage. -2 Energy.";
	}
	else if (CardName == "Demolish") {
		Description = "Deal 3x(Str) damage. -12 Energy.";
	}
	else if (CardName == "Bleed") {
		Description = "Deal 2d(Str/2) damage for 4 rounds.";
	}
	else if (CardName == "Hack") {
		Description = "Deal 2d(Str) damage. Deals double to block.";
	}
	else if (CardName == "Stab") {
		Description = "Chance to deal either 1 or 12 damage. +10 Energy.";
	}
	else if (CardName == "Zap") {
		Description = "Deal 1d(Int/2) damage. +9 Energy.";
	}
	else if (CardName == "Ram") {
		Description = "Deal (Def)d2 damage. -5 Energy.";
	}
	else if (CardName == "Flay") {
		Description = "Deal 2d(Str) damage. Deal (Str/2) damage for 3 turns.";
	}
	else if (CardName == "Slash") {
		Description = "Deal (Str)d2 damage. Fill hand with Attacks. -2 Energy.";
	}
	else if (CardName == "Lash") {
		Description = "Deal (Str)d3 damage. Take 6d2 damage.";
	}
	else if (CardName == "Pummel") {
		Description = "Deal 2 damage. Increase this by 2d(Str/2). +2 Energy.";
	}
	else if (CardName == "Rend") {
		Description = "Halve the enemy's hp. -5 Energy.";
	}
	else if (CardName == "Ritual") {
		Description = "Deal 5 damage. If it kills, +1 max hp and max mana.";
	}
	else if (CardName == "Prick") {
		Description = "Deal 2 damage. +5 Energy.";
	}
	else if (CardName == "Laser") {
		Description = "Deal (Skl)d3 damage to health and block. +13 Energy.";
	}
}
void Card::setDefend() {
	if (CardName == "Endure") {
		//(Def)+2
		Description = "Gain (Def)+2 block. +3 Energy.";
	}
	else if (CardName == "Force Field") {
		//(Int)d2 block
		Description = "Gain (Int)d2 block. -4 Energy.";
	}
	else if (CardName == "Block") {
		Description = "Negate the next 2 hits taken.";
	}
	else if (CardName == "Obstruct") {
		Description = "Gain (Def)d2 block. +4 Energy.";
	}
	else if (CardName == "Disrupt") {
		Description = "Gain (Def)+2 block. Remove enemy block.";
	}
	else if (CardName == "Dodge") {
		Description = "Lose all block. Negate next hit taken, shuffle deck.";
	}
	else if (CardName == "Dash") {
		Description = "Gain 2d(Def/2) block. +5 Energy.";
	}
	else if (CardName == "Brace") {
		Description = "+(Def) block. Fill hand with Defends.";
	}
	else if (CardName == "Counter") {
		Description = "+(Def) block. Fill hand with Attacks. +3 Energy.";
	}
	else if (CardName == "Predict") {
		Description = "+(Def) block. Fill hand with Spells. +3 Energy.";
	}
	else if (CardName == "Absorb") {
		Description = "Gain (Def)x3 block. -12 Energy.";
	}
	else if (CardName == "Reinforce") {
		Description = "Gain 50% of your block.";
	}
	else if (CardName == "Flee") {
		Description = "Costs all of your block. +10d3 Energy.";
	}
	else if (CardName == "Spikes") {
		Description = "Gain (Def) damage. Deal 7 damage. +2 Energy.";
	}
	else if (CardName == "Repulse") {
		Description = "Take 7 damage, negate the next hit. +11 Energy.";
	}
	else if (CardName == "Wall") {
		Description = "Gain (Def)x3 block. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Toughen") {
		Description = "Gain 22 block. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Defend") {
		Description = "Gain (Def)+6 block. -3 Energy.";
	}
	else if (CardName == "Gamble") {
		Description = "You and enemy gain (Def)+3 block. +5g after combat. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Inspire") {
		Description = "Gain (Def)+4 block. Gain 3 mana.";
	}
	else if (CardName == "Bide") {
		Description = "Gain (Def)+3 block. Shuffle your deck.";
	}
	else if (CardName == "Restore") {
		Description = "Heal for (Def)x2.";
	}
	else if (CardName == "Form") {
		Description = "Gain (Def)+5 max hp and health for the combat.";
	}
	else if (CardName == "Tear") {
		Description = "Take (Def)x5 damage. Heal 3d2 for (Def)x2 turns. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Barrier") {
		Description = "Lose all of your mana. Gain 4 block for each.";
	}
}
void Card::setSpell() {
	if (CardName == "Ponder") {
		ManaCost = 0;
		Description = "Gain 2 mana.";
	}

	else if (CardName == "Channel") {
		ManaCost = 0;
		Description = "Recover (Int) mana.";
	}
	else if (CardName == "Meditate") {
		//4 Mana
		//recover (Int)d3 current hp
		ManaCost = 4;
		Description = "Recover (Int)d3 health.";
	}
	else if (CardName == "Blast") {
		ManaCost = 8;
		Description = "Deal (Int)d2 damage. +11 Energy.";
	}

	else if (CardName == "Leech") {
		ManaCost = 5;
		Description = "Deal and heal (Int)d2 damage. +2 Energy";
	}
	else if (CardName == "Regenerate") {
		ManaCost = 5;
		Description = "Heal 2+1d(Int) health for 5 turns.";
	}
	else if (CardName == "Transmute") {
		ManaCost = 0;
		Description = "Take 3d4 damage. Gain (Int) mana. +8 Energy.";
	}

	else if (CardName == "Blink") {
		ManaCost = 3;
		Description = "Deal 2d(Int) damage. +10 Energy.";
	}
	else if (CardName == "Singularity") {
		ManaCost = 0;
		Description = "Gain (Int)+7 block and (Int) mana. -15 Energy.";
	}

	else if (CardName == "Freeze") {
		ManaCost = 10;
		Description = "Gain 6+ 2d(Int) block. -5 Energy.";
	}
	else if (CardName == "Shard") {
		ManaCost = 0;
		Description = "Take 6 damage. +3 mana. Deal (Int/2)d2 damage. +11 Energy.";
	}

	else if (CardName == "Fumes") {
		ManaCost = 8;
		Description = "Deal (Int/2)d2 damage for (Int) turns.";
	}
	else if (CardName == "Incense") {
		ManaCost = 0;
		Description = "Gain 3 mana, 5 block, and 1 Energy for (Int/2) turns.";
	}

	else if (CardName == "Fireball") {
		ManaCost = 5;
		Description = "Deal (Int)d4 damage. -5 Energy.";
	}
	else if (CardName == "Fuel") {
		ManaCost = 0;
		Description = "Gain mana for next unblocked damage dealt. +12 Energy.";
	}

	else if (CardName == "Charm") {
		ManaCost = 4;
		Description = "The next damage taken is dealt to the enemy.";
	}
	else if (CardName == "Attract") {
		ManaCost = 0;
		Description = "The next damage taken is gained as mana. Gain (Int)+3 block.";
	}

	else if (CardName == "Copy") {
		ManaCost = 6;
		Description = "Use the next card twice. +5 Energy.";
	}
	else if (CardName == "Confuse") {
		ManaCost = 0;
		Description = "Gain (Int)/2 mana. +10 Energy.";
	}

	else if (CardName == "Lightning") {
		ManaCost = 0;
		Description = "Lose all mana and Energy. Deal 1d(Int/3) for each point lost.";
	}
	else if (CardName == "Shock") {
		ManaCost = 0;
		Description = "Gain 2 mana. Take 4 damage. +12 Energy.";
	}

	else if (CardName == "Destroy") {
		ManaCost = 10;
		Description = "Deal your block as damage, lose your block. +10 Energy.";
	}
	else if (CardName == "Construct") {
		ManaCost = 0;
		Description = "Gain (Int/2) mana. Gain (Int)d2 block. -2 Energy.";
	}

	else if (CardName == "Beam") {
		ManaCost = 3;
		Description = "Deal (Int)d2 damage. Fill hand with Spells.";
	}
	else if (CardName == "Diffract") {
		ManaCost = 0;
		Description = "Gain 5 mana. Shuffle your hand. +5 Energy.";
	}

	else if (CardName == "Sap") {
		ManaCost = 0;
		Description = "Deal 4d(Int/4) damage. Gain that much mana. +6 Energy";
	}
	else if (CardName == "Synthesize") {
		ManaCost = 10;
		Description = "Heal for 8d(Int).";
	}

	else if (CardName == "Drown") {
		ManaCost = 0;
		Description = "Stop Refresh. Lose 1 mana and deal (Int)/2 damage every turn.";
	}
	else if (CardName == "Refresh") {
		ManaCost = 0;
		Description = "Stop Drown. Gain 1 mana every turn. +10 Energy.";
	}

	else if (CardName == "Reagent") {
		ManaCost = 5;
		Description = "Deal 1d4 damage for (Int) more turns.";
	}
	else if (CardName == "Reactant") {
		ManaCost = 0;
		Description = "Deal all Reagent damage at once. Gain (Int) mana.";
	}

	else if (CardName == "Transmogrify") {
		ManaCost = 5;
		Description = "Gain (Int)d2 gold.";
	}
	else if (CardName == "Liquidate") {
		ManaCost = 0;
		Description = "Deal 3d(Int) damage. +12 Energy.";
	}

	else if (CardName == "Sandstorm") {
		ManaCost = 10;
		Description = "Everybody takes 3d(Int) damage for 3 turns.";
	}
	else if (CardName == "Screen") {
		ManaCost = 0;
		Description = "Gain 5 mana. Negate the next 2 attacks. -2 Energy.";
	}
	else if (CardName == "Empower") {
		ManaCost = 3;
		Description = "Your next Attack gains (Int/2)d3 damage. +10 Energy.";
	}
	else if (CardName == "Shed") {
		ManaCost = 0;
		Description = "Lose all block and Negates. Gain 9 mana.";
	}
	else if (CardName == "Extract") {
		ManaCost = 0;
		Description = "+8 mana. Deal 10 damage. -5 Energy. +1 Int on kill.";
	}
	else if (CardName == "Drain") {
		ManaCost = 2;
		Description = "The Enemy loses (Int/2) max hp. +8 Energy.";
	}
	else if (CardName == "Soldier") {
		ManaCost = 3;
		Description = "Gain 2d2 block every turn.";
	}
	else if (CardName == "Attack") {
		ManaCost = 0;
		Description = "Lose all Soldiers. +3 mana and deal (Int) damage for each.";
	}
	else if (CardName == "Arise") {
		ManaCost = 0;
		Description = "-8 max hp for the combat. Deal 2 dmg per turn. +10 Energy.";
	}
	else if (CardName == "The Flesh") {
		ManaCost = 0;
		Description = "Gain (Int) max hp for the combat.";
	}
	else if (CardName == "Rainbow") {
		ManaCost = 5;
		Description = "Deal 2d(Int) dmg, +(Def)+2 block and (Int)/2 Energy.";
	}
	else if (CardName == "Focus") {
		ManaCost = 0;
		Description = "Gain 1+ (Int)/2 mana. Fill hand with Spells.";
	}
	else if (CardName == "Horrify") {
		ManaCost = 7;
		Description = "The enemy can't gain block or hp for (Int/2) turns.";
	}
	else if (CardName == "Lurk") {
		ManaCost = 0;
		Description = "Gain 4 mana. +1d2 Int for the combat. +6 Energy.";
	}
	else if (CardName == "Screech") {
		ManaCost = 10;
		Description = "Pierce for (Int) damage 2d2 times.";
	}
	else if (CardName == "Echo") {
		ManaCost = 0;
		Description = "Gain 1d(Int) mana. +5 Energy.";
	}
	else if (CardName == "Judge") {
		ManaCost = 6;
		Description = "Halve the enemy's hp. +5 Energy.";
	}
	else if (CardName == "Bless") {
		ManaCost = 0;
		Description = "Gain (Int/2)d2 mana and health.";
	}
	else if (CardName == "Aegis") {
		ManaCost = 10;
		Description = "Gain 2+(Int/9) Negates.";
	}
	else if (CardName == "Steadfast") {
		ManaCost = 0;
		Description = "Lose 1 hp 2d2 times. Gain (Int/3) mana per hit.";
	}
}
void Card::setboss() {
	if (CardName == "Haste") {
		//2 extra turns
		Description = "Gain 11 +3d3 Energy. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Revivify") {
		Description = "Heal 6 health and 3 mana for 6 turns. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Steroids") {
		Description = "Your next attack deals double damage.";
	}
	else if (CardName == "Change Mind") {
		Description = "Shuffle your deck. +10 Energy.";
	}
	else if (CardName == "Intimidate") {
		Description = "Gain (Str)d3 block. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Distract") {
		Description = "Remove enemy block. +15 Energy. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Prepare") {
		Description = "Fill hand with spells. Full mana. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Boost") {
		Description = "Gain 5 mana. +10 Energy.";
	}
	else if (CardName == "Vitalise") {
		Description = "Full health. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Jump") {
		Description = "Fill hand with attacks. Negate 1 attack. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Slam") {
		Description = "Deal your block as damage.";
	}
	else if (CardName == "Stall") {
		Description = "+12 Energy.";
	}
	else if (CardName == "Repel") {
		Description = "Negate the next 2 attacks taken. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Ghost") {
		Description = "The next card you play will not burn.";
	}
	else if (CardName == "Catalyze") {
		Description = "Activate your over time effects thrice.";
	}
	else if (CardName == "Detonate") {
		Description = "Damage over time on the enemy is dealt at once.";
	}
	else if (CardName == "Polymorph") {
		Description = "Transform the enemy. +10 Energy. Burn this card.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Cleanse") {
		Description = "Burn your entire hand. +10 Energy.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Teleport") {
		Description = "End combat. Go to a random nearby tile.";
	}
	else if (CardName == "Inject") {
		Description = "Next damage dealt heals you for the same. +10 Energy. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Flurry") {
		Description = "Cards also Attack for 3 damage. +10 Energy. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Materialize") {
		Description = "Your next heal also gives the same block. +10 Energy. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Overdrive") {
		Description = "All stats +8 for 3 turns, then stats -10. +10 Energy. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Enrich") {
		Description = "Gain 1 mana per turn. +10 Energy. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Shimmer") {
		Description = "Deal (Gold) damage, lose your gold. +10 Energy. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Relax") {
		Description = "Stop your turn effects for 5 turns. +10 Energy. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Sharpen") {
		Description = "Next damage dealt pierces. +10 Energy. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Amplify") {
		Description = "Next Spell is used twice. +10 Energy. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Cell") {
		Description = "Next Spell that has cost is free. +10 Energy. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Deflect") {
		Description = "Next damage taken is dealt to enemy instead. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Save") {
		Description = "Dying next turn brings you back to life. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Stop") {
		Description = "You will not take damage next turn. Burn.";
		naturalBurn = TRUE;
	}
	else if (CardName == "Chaos") {
		Description = "Play a random card.";
	}
}
void Card::setNegative() {
	if (CardName == "Steam") {
		Description = "Take 7 damage. +10 Energy.";
	}
	else if (CardName == "Scalding Steam") {
		Description = "Take 12 damage. +10 Energy.";
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
		Description = "+2 and -2 to random stats for the battle. +10 Energy.";
	}
	else if (CardName == "Burn") {
		Description = "Burn your next card. +10 Energy.";
	}
}

void Card::printCard(int position, Character &guy) {
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
	if (Stay > 0) {
		mods += "#gStay" + to_string(tempStay) + "#o";
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
		mods += "#bLink" + s + "#o";
		modcounter++;
	}

	if (modcounter > 4 || position == 4) {
		mods = modchars();
		mvprintInSize(mody, modx-2, 0, mods.c_str(), FALSE);
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
	else if (CardType == "BossCard")
		standend();
	else if (CardType == "Negative")
		attron(COLOR_PAIR(5));

	//string for cost description at the bottom of the card
	int mcx = 0;
	int mcy = 23;
	string manacost = "";
	int mc = ManaCost;
	if (guy.Dazed && CardType == "Spell")
		mc++;
	if (guy.Psychosis != -1)
		mc *= 2;
	if (mc > 0 || CardName == "Lightning") {
		manacost = "(Costs " + to_string(mc) + " mana.)";
		if (CardName == "Lightning") {
			manacost = "(Lose all mana.)";
		}
		if (guy.Sacrificial) {
			manacost = "#r(Take " + to_string(mc) + " damage.)#m";
			if (CardName == "Lightning") {
				manacost = "(Lose all hp and block.)";
				mcx -= 2;
			}
		}
	}
	if (CardName == "Liquidate") {
		manacost = "#$(Costs 10 gold.)#m";
	}
	if (CardName == "Flee") {
		manacost = "(Costs all block.)";
		mcx--;
	}

	//const char* car;
	switch (position) {
	case 1:
		//car = CardName;
		mvprintInSize(17, 5, 15, CardName, FALSE);
		//car = Description;
		mvprintInSize(19, 4, 15, Description, FALSE);
		manualBox("Card 1", 0);

		mcx += 3;
		mvprintInSize(mcy, mcx, 0, manacost.c_str(), FALSE);

		break;
	case 2:
		//car = CardName;
		mvprintInSize(17, 25, 15, CardName, FALSE);
		//car = Description;
		mvprintInSize(19, 24, 15, Description, FALSE);
		manualBox("Card 2", 0);

		mcx += 23;
		mvprintInSize(mcy, mcx, 0, manacost.c_str(), FALSE);

		break;
	case 3:
		//car = CardName;
		mvprintInSize(17, 45, 15, CardName, FALSE);
		//car = Description;
		mvprintInSize(19, 44, 15, Description, FALSE);
		manualBox("Card 3", 0);

		mcx += 43;
		mvprintInSize(mcy, mcx, 0, manacost.c_str(), FALSE);

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
	//bosss
	if (CardType == "BossCard") {
		bossFunction(guy, enemy, log);
	}
	//negatives
	if (CardType == "Negative") {
		negativeFunction(guy, enemy, log);
	}

	//used for consecutive Burn uses
	if (CardName != "Burn")
		guy.burninarow = 0;
	//used for consecutive Ghost uses
	if (CardName != "Ghost")
		guy.ghostinarow = 0;

	//Memory Lapse trait
	if (guy.Memory_Lapse) {
		memorylapse += 2;
		if (memorylapse == 3) {
			int damage = guy.TakeDamage(guy.Skill);
			string lapse = "-You take #r" + to_string(damage) + "#o damage.";
			log.PushPop(lapse);
			memorylapse = 2;
		}
	}

	//Concentration trait
	if (guy.Concentration != -1) {
		guy.ConcentrationType = CardType;
		if (guy.ConcentrationType == CardType) {
			guy.Concentration++;
		}
		else {
			guy.Concentration = 0;
		}
		if (guy.Concentration == 3) {
			string line = "#g-You concentrate.#o";
			log.PushPop(line);
			gainEnergy(rtd(guy.Skill, 2), guy, enemy);
		}
	}
	//Combo Breaker trait
	if (guy.Combo_Breaker) {
		combobreaker++;
		if (combobreaker == 5) {
			naturalBurn = TRUE;
			string cb = "#r-Your";
			if (CardType == "Attack") {
				cb += " #y";
			}
			else if (CardType == "Defend") {
				cb += " #c";
			}
			else if (CardType == "Spell") {
				cb += " #m";
			}
			else if (CardType == "BossCard") {
				cb += " #o";
			}
			else if (CardType == "Negative") {
				cb += " #r";
			}
			cb += string(CardName) + modchars() + "#r burns.#o";
			log.PushPop(cb);
		}
	}
	//Flurry card
	if (guy.flurry > 0) {
		int totaldamage = 0;
		for (int i = 0; i < guy.flurry; i++) {
			int damage = dealDamage(3, guy, enemy, log);
			totaldamage += damage;
		}
		string line;
		if (guy.flurry == 1) {
			line = "-You attack for #y" + to_string(totaldamage) + "#o damage.";
		}
		else {
			line = "-You attack #y" + to_string(guy.flurry) + " times#o for #y" + to_string(totaldamage) + "#o damage total.";
		}
		log.PushPop(line);
	}
	//Addiction trait
	if (guy.Addiction && CardType != "Spell") {
		if (guy.Intelligence > 0) {
			guy.ModStat(-1, "Intelligence", TRUE);
		}
	}
	//Recycling trait
	if (guy.Recycling != -1) {
		if (CardType == "Spell") {
			guy.Recycling++;
		}
		else {
			guy.Recycling = 0;
		}

		if (guy.Recycling == 3) {
			guy.Recycling = 0;
			int mana = 4 + rtd(1, guy.Skill);
			guy.DrainMana(-mana);
			string recycle = "#m-You gain " + to_string(mana) + " mana.#o";
			log.PushPop(recycle);
		}
	}
	//Run trait
	if (guy.Run) {
		if (CardType == "Defend")
			gainEnergy(10, guy, enemy);
		else
			gainEnergy(-10, guy, enemy);
	}

	//check for Copy card
	while (!copyUsed && guy.copy > 0) {
		guy.copy--;
		guy.DrainMana(-1 * ManaCost);
		if (chaos) {
			CardName = "Chaos";
			CardType = "BossCard";
		}
		cardFunction(guy, enemy, log);
	}
	//Unpredictable trait
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
		//6d(Str-5) damage, remove your block. -2 Energy
		int damage = dealDamage(rtd(6, guy.Strength - 5), guy, enemy, log);
		guy.CurrentBlock = 0;
		gainEnergy(-2, guy, enemy);

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
		//2d(Str) damage, take 7 damage, +12 Energy
		int damage = dealDamage(rtd(2, guy.Strength), guy, enemy, log);
		int selfdamage = guy.TakeDamage(7);
		gainEnergy(12, guy, enemy);

		string line = "-You shoot the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o and take #r" + to_string(selfdamage) + "#o.";
		log.PushPop(line);
	}
	else if (CardName == "Throw") {
		int damage = rtd(2, guy.Strength/2);
		gainEnergy(8, guy, enemy);
		damage = dealDamage(damage, guy, enemy, log);

		string line = "-You hit the " + string(enemy.Name)
			+ " for #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
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
		gainEnergy(3, guy, enemy);

		string line = "-You feint then deal #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Slice") {
		int damage = rtd(guy.Strength, 2);
		damage = dealDamage(damage, guy, enemy, log);

		string line = "-You slice the " + string(enemy.Name)
			+ " for #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Crush") {
		//do 3d(Str) dmg
		int damage = dealDamage(rtd(3, guy.Strength), guy, enemy, log);
		gainEnergy(-2, guy, enemy);

		string line = "-You crush the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Demolish") {
		//do 3*(Str) dmg, lose 12 energy
		int damage = dealDamage(3 * guy.Strength, guy, enemy, log);
		gainEnergy(-12, guy, enemy);

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
		if (guy.Strategy) {
			int damage = rtd(guy.Strength, 2);
			damage = gainBlockStrategy(damage, guy, enemy);
			line = "-You hack the " + string(enemy.Name) + " for #y" + to_string(damage) + "#o damage.";
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
		//33% to deal 12 damage, 66% to 1. +10 energy
		int rng = rand() % 3;
		int damage;
		if (rng == 0)
			damage = dealDamage(12, guy, enemy, log);
		else
			damage = dealDamage(1, guy, enemy, log);
		gainEnergy(10, guy, enemy);

		string line = "-You stab the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Zap") {
		//Deal 1d(Int/2), +9 Energy
		int damage = rtd(1, int(guy.Intelligence / 2));
		damage = dealDamage(damage, guy, enemy, log);
		gainEnergy(9, guy, enemy);

		string line = "-You zap the " + string(enemy.Name) + " for #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Ram") {
		//Deal (Def)d2 damage. -5 Energy
		int damage = rtd(int(guy.Defense), 2);
		damage = dealDamage(damage, guy, enemy, log);
		gainEnergy(-5, guy, enemy);

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
		gainEnergy(-2, guy, enemy);

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
		gainEnergy(+2, guy, enemy);

		string line = "-You pummel the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Rend") {
		//Halve the enemy's hp. -5 Energy.
		if (enemy.CurrentHealth > 1)
			enemy.CurrentHealth /= 2;
		gainEnergy(-5, guy, enemy);

		string line = "#y-You rend the " + string(enemy.Name) + ".#o";
		log.PushPop(line);
	}
	else if (CardName == "Ritual") {
		//Deal 5 damage. If it kills, +1 max hp and max mana.
		int damage = dealDamage(5, guy, enemy, log);
		
		string line = "-You cut the " + string(enemy.Name) + " for #y" + to_string(damage) + "#o damage.";
		string line2 = "#r-You steal the " + string(enemy.Name) + "'s vitality.#o";

		log.PushPop(line);
		if (enemy.CurrentHealth <= 0) {
			guy.ModStat(1, "MaxHealth", FALSE);
			guy.ModStat(1, "MaxMana", FALSE);
			log.PushPop(line2);
		}
	}
	else if (CardName == "Prick") {
		//Deal 2 damage. +5 Energy.
		int damage = dealDamage(2, guy, enemy, log);
		gainEnergy(5, guy, enemy);

		string line = "-You prick the " + string(enemy.Name) + " for #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}

	else if (CardName == "Laser") {
		//Deal (Skl)d3 damage to health and block. +13 energy
		int damageH = rtd(guy.Skill, 3);
		int damageB = rtd(guy.Skill, 3);
		if (damageB > enemy.CurrentBlock) {
			damageB = enemy.CurrentBlock;
			enemy.CurrentBlock = 0;
		}
		else
			enemy.CurrentBlock -= damageB;

		enemy.CurrentHealth -= damageH;
		gainEnergy(13, guy, enemy);

		string line = "-You incinerate the " + string(enemy.Name)
			+ " for #y" + to_string(damageB + damageH)
			+ "#o damage.";
		log.PushPop(line);
	}

	//Fervor trait
	if (guy.Fervor != -1) {
		guy.Fervor += guy.Skill;
		guy.FervorDamage++;
	}
	//Draining Touch trait
	if (guy.Draining_Touch) {
		int mana = -guy.DrainMana(-(2 + guy.Skill));
		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		log.PushPop(line);
	}
}
void Card::defendFunction(Character &guy, Enemy &enemy, TextLog &log) {
	if (CardName == "Endure") {
		//block for (Def)+2. +3 energy
		int block = gainBlock(guy.Defense + 2, guy, enemy);
		gainEnergy(3, guy, enemy);

		string line = "-You gain #c" + to_string(block)
			+ "#o block.";

		log.PushPop(line);
	}
	else if (CardName == "Force Field") {
		//block for (int)d2. -4 Energy
		int block = gainBlock(rtd(guy.Intelligence, 2), guy, enemy);
		gainEnergy(-4, guy, enemy);

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
		//gain (Def)d2 block. +4 Energy
		int block = rtd(guy.Defense, 2);
		gainBlock(block, guy, enemy);
		gainEnergy(4, guy, enemy);

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
		//gain 2d(Def/2) block, +5 energy
		int block = gainBlock(rtd(2, guy.Defense/2), guy, enemy);
		gainEnergy(5, guy, enemy);;

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Brace") {
		//gain (Def) block, fill your hand with blocks
		guy.fillType = "Defend";
		int block = gainBlock(guy.Defense, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Counter") {
		//gain (Def) block, fill your hand with attacks. +3 Energy
		guy.fillType = "Attack";
		int block = gainBlock(guy.Defense, guy, enemy);
		gainEnergy(3, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Predict") {
		//gain (Def) block, fill your hand with spells. +3 Energy
		guy.fillType = "Spell";
		int block = gainBlock(guy.Defense, guy, enemy);
		gainEnergy(3, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Absorb") {
		//Gain (Def)x3 block. -12 Energy
		int block = gainBlock(guy.Defense*3, guy, enemy);
		gainEnergy(-12, guy, enemy);

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
		//only usable if you have block. lose all block, gain 10d3 Energy
		guy.CurrentBlock = 0;
		gainEnergy(rtd(10, 3), guy, enemy);

		string line = "#r-You lose all of your block.#o";
		log.PushPop(line);
	}
	else if (CardName == "Spikes") {
		//gain (Def) block, deal 7 damage. +2 Energy
		int block = gainBlock(guy.Defense, guy, enemy);
		int damage = dealDamage(7, guy, enemy, log);
		gainEnergy(2, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block and deal #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Repulse") {
		//Take 7 damage, negate the next hit. +11 ENergy
		int damage = guy.TakeDamage(7);
		guy.Negate++;
		gainEnergy(11, guy, enemy);

		string line = "-You take #r" + to_string(damage) + "#o damage and #cnegate the next hit taken.#o";
		log.PushPop(line);
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
	else if (CardName == "Defend") {
		//gain (Def)+6 block. -3 Energy
		int block = gainBlock(guy.Defense + 6, guy, enemy);
		gainEnergy(-3, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Gamble") {
		//You and enemy gain (Def)+3 block. +5g after combat. Burn
		int block1 = gainBlock(guy.Defense+3, guy, enemy);
		int block2 = enemy.gainBlock(guy.Defense+3, guy, log);
		enemy.goldreward += 5;

		string line1 = "-You gain #c" + to_string(block1) + "#o block.";
		string line2 = "-The " + string(enemy.Name) + " gains #b" + to_string(block1) + "#o block.";
		log.PushPop(line1);
		log.PushPop(line2);
	}
	else if (CardName == "Inspire") {
		//Gain (Def)+4 block. Gain 3 mana.
		int block = gainBlock(guy.Defense + 4, guy, enemy);
		int mana = guy.DrainMana(-3);

		string line = "-You gain #c" + to_string(block) + "#o block and #m" + to_string(mana) + "#o mana.";
		log.PushPop(line);
	}
	else if (CardName == "Bide") {
		//Gain (Def)+3 block. Shuffle your deck."
		int block = gainBlock(guy.Defense + 3, guy, enemy);
		guy.shuffle = TRUE;

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Restore") {
		//Heal for (Def)x2."
		int health = guy.TakeDamage(guy.Defense*-2);

		string line = "-You restore #g" + to_string(-health) + "#o health.";
		log.PushPop(line);
	}
	else if (CardName == "Form") {
		//Gain (Def)+5 max hp and health for the combat
		int hp = guy.Defense + 5;
		guy.ModStat(hp, "MaxHealth", TRUE);
		int hp2 = guy.TakeDamage(-hp);

		string line = "-You gain #g" + to_string(hp) + " max health#o for the combat and heal for #g" + to_string(-hp2) + "#o.";
		log.PushPop(line);
	}
	else if (CardName == "Tear") {
		//Take (Def)x5 damage. Heal 3d2 for (Def)x2 turns. Burn.
		int damage = guy.TakeDamage(guy.Defense * 5);
		int turns = guy.Defense * 2;
		guy.tear += turns;

		string line = "-You take #r" + to_string(damage) + "#o damage and #gheal for " + to_string(turns) + " turns#o.";
		log.PushPop(line);
	}
	else if (CardName == "Barrier") {
		//Lose all of your mana. Gain 4 block for each.
		int times = 0;
		int block = 0;
		for (guy.CurrentMana; guy.CurrentMana > 0; guy.DrainMana(1)) {
			times++;
			block += gainBlock(4, guy, enemy);
		}

		string line = "-You gain block #c" + to_string(times) + " times#o for a total of #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}

	//Dexterous trait
	if (guy.Dexterous && CardType == "Defend") {
		int ddamage = guy.Skill;
		dealDamage(ddamage, guy, enemy, log);
	}
	//Fleet of Foot trait
	if (guy.Fleet_of_Foot) {
		gainEnergy(3, guy, enemy);
	}
}
void Card::spellFunction(Character &guy, Enemy &enemy, TextLog &log) {
	//lose mana if the spell has a cost
	//Sacrificial trait
	//Dazed trait
	//makes sure you dont lose mana while using chaos
	if (!chaos && !guy.amplifyTRUE && guy.cell == 0 && !guy.Psychosis == 0) {
		int cost = ManaCost;
		if (guy.Dazed)
			cost++;
		if (guy.Psychosis != -1)
			cost *= 2;

		if (guy.Sacrificial) {
			guy.TakeDamage(cost);
		}
		else {
			guy.DrainMana(cost);
		}
	}
	if ((ManaCost > 0 || guy.Dazed) && guy.cell > 0) {
		guy.cell--;
	}
	if (guy.amplifyTRUE)
		guy.amplifyTRUE = FALSE;

	//no headgear
	if (CardName == "Ponder") {
		int mana = 2;
		guy.DrainMana(-1 * mana);
		string line = "#m-You gain " + to_string(mana) + " mana.#o";
	}

	else if (CardName == "Channel") {
		//gain (Int) mana
		int mana = -guy.DrainMana(-guy.Intelligence);

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
		//Cost 8 mana. Deal (Int)d2 damage. +11 Energy
		int damage = dealDamage(rtd(guy.Intelligence, 2), guy, enemy, log);
		guy.Energy += 11;

		string line = "-You blast the " + string(enemy.Name) + " for #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}

	else if (CardName == "Leech") {
		//cost 5 mana, deal (Int)d2 damage, gain that much hp. +2 energy
		int damage = dealDamage(rtd(guy.Intelligence, 2), guy, enemy, log);
		if (enemy.invisible <= 0)
			guy.TakeDamage(-1 * damage);
		gainEnergy(2, guy, enemy);

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
		//take 3d4 damage, gain (Int) mana, extra turn. +8 energy
		int damage = rtd(3, 4);
		guy.TakeDamage(damage);
		int mana = -1 * guy.Intelligence;
		guy.DrainMana(mana);
		gainEnergy(8, guy, enemy);

		string line = "-You take #r" + to_string(damage)
			+ "#o damage and gain #m" + to_string(guy.Intelligence)
			+ " mana.#o";
		log.PushPop(line);
	}

	else if (CardName == "Blink") {
		//cost 3 mana, deal 2d(Int) damage, gain an extra turn. +10 energy
		int damage = dealDamage(rtd(2, guy.Intelligence), guy, enemy, log);
		gainEnergy(10, guy, enemy);

		string line = "-You blink and deal #y" + to_string(damage)
			+ "#o damage to the " + string(enemy.Name) + ".";
		log.PushPop(line);
	}
	else if (CardName == "Singularity") {
		//gain (Int) block and (Int) mana. -15 energy
		int block = gainBlock(guy.Intelligence + 7, guy, enemy);
		int mana = guy.Intelligence;
		guy.DrainMana(-1 * mana);
		gainEnergy(-15, guy, enemy);

		string line = "-You gain #c" + to_string(block)
			+ "#o block and #m" + to_string(mana)
			+ "#o mana.";
		log.PushPop(line);
	}

	else if (CardName == "Freeze") {
		//Costs 6 mana. Gain 6+(Int)d2 block. -5 energy
		int block = 6 + rtd(guy.Intelligence, 3);
		block = gainBlock(block, guy, enemy);
		gainEnergy(-5, guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Shard") {
		//Take 6 damage. +3 mana. Deal (Int/2)d2 damage. +11 energy."
		int selfdamage = guy.TakeDamage(6);
		int damage = rtd(int(guy.Intelligence / 2), 2);
		damage = dealDamage(damage, guy, enemy, log);
		guy.DrainMana(-3);
		gainEnergy(11, guy, enemy);

		string line = "-You deal #y" + to_string(damage)
			+ "#o damage, take #r" + to_string(selfdamage)
			+ "#o and #mgain 3 mana#o.";
		log.PushPop(line);
	}

	else if (CardName == "Fumes") {
		//Costs 8 mana. Deal (Int/2)d2 damage for (Int) turns
		int turns = guy.Intelligence;
		enemy.fumes += turns;
		string line = "#m-You release toxic fumes#o for " + to_string(turns) + " more turns.#o";
		log.PushPop(line);
	}
	else if (CardName == "Incense") {
		//Gain 3 mana, 5 block, and 1 energy for (Int/2) turns
		int turns = (guy.Intelligence/2);
		guy.incense += turns;
		string line = "#m-You burn incense#o for #m" + to_string(turns) + " more turns.#o";
		log.PushPop(line);
	}

	else if (CardName == "Fireball") {
		//costs 5 mana, (Int)d4 dmg. -5 energy
		int damage = dealDamage(rtd((int)(guy.Intelligence), 4), guy, enemy, log);
		gainEnergy(-5, guy, enemy);

		string line = "-You lob a fireball at the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Fuel") {
		//next attack gain mana for unblocked damage dealt. +12 energy
		guy.damageToMana += 1;
		gainEnergy(12, guy, enemy);

		string line = "#m -You prepare to attack.#o";
		log.PushPop(line);
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
		//Cost 6 mana. Use your next card twice. +5 energy
		guy.copy++;
		gainEnergy(5, guy, enemy);

		string line = "#m-You prepare a copy of your next card.#o";
		log.PushPop(line);
		copyUsed = TRUE;
	}
	else if (CardName == "Confuse") {
		//Gain (Int)/2 mana, +10 energy
		int mana = int(guy.Intelligence / 2);
		guy.DrainMana(-1 * mana);
		gainEnergy(10, guy, enemy);

		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		log.PushPop(line);
	}

	else if (CardName == "Lightning") {
		//Lose all your mana and energy. Deal 1d(Int/3) damage for each point lost.
		int total = 0;
		int i = 0;
		//Sacrificial trait
		if (guy.Sacrificial) {
			for (i = 0; i < guy.CurrentHealth + guy.CurrentBlock + guy.Negate + guy.Energy; i++) {
				int damage = rtd(1, int(guy.Intelligence / 3));
				damage = dealDamage(damage, guy, enemy, log);
				total += damage;
			}
		}
		else {
			for (i = 0; i < guy.CurrentMana + guy.Energy; i++) {
				int damage = rtd(1, int(guy.Intelligence / 2));
				damage = dealDamage(damage, guy, enemy, log);
				total += damage;
			}
		}

		string line;
		if (i == 1) {
			line = "-You electrocute the " + string(enemy.Name) + " #m"
				+ to_string(i) + " time#o for a total of #y" + to_string(total)
				+ "#o damage.";
		}
		else {
			line = "-You electrocute the " + string(enemy.Name) + " #m"
				+ to_string(i) + " times#o for a total of #y" + to_string(total)
				+ "#o damage.";
		}
		log.PushPop(line);

		if (guy.Sacrificial) {
			if (enemy.CurrentHealth <= 0 || (guy.Reaper && enemy.CurrentHealth - (5 + (2 * guy.Skill)) <= 0))
				guy.CurrentHealth = 1;
			else
				guy.CurrentHealth = 0;
			guy.CurrentBlock = 0;
			guy.Energy = 0;
		}
		else
			guy.CurrentMana = 0;
		guy.Energy = 0;
	}
	else if (CardName == "Shock") {
		//Gain 2 mana. Take 4 damage. +12 energy
		guy.DrainMana(-2);
		int damage = guy.TakeDamage(4);
		gainEnergy(12, guy, enemy);

		string line = "-You #mgain 2 mana#o and take #r" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}

	else if (CardName == "Destroy") {
		//Costs 10 mana. Deal your block as damage, lose your block. +10 Energy
		int damage = guy.CurrentBlock;
		damage = dealDamage(damage, guy, enemy, log);
		guy.CurrentBlock = 0;
		gainEnergy(10, guy, enemy);

		string line = "-You destroy the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage and #rlose your block.#o";
		log.PushPop(line);
	}
	else if (CardName == "Construct") {
		//Gain (Int/2) mana. Gain (Int)d2 block. -2 Energy
		int block = rtd(guy.Intelligence, 2);
		int mana = int(guy.Intelligence / 2);
		gainBlock(block, guy, enemy);
		guy.DrainMana(-1 * mana);
		gainEnergy(-2, guy, enemy);

		string line = "-You #mgain " + to_string(mana)
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
		//Gain 5 mana. Shuffle your hand. +5 energy
		int mana = 5;
		guy.DrainMana(-1 * mana);
		guy.shuffle = TRUE;
		gainEnergy(5, guy, enemy);

		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		log.PushPop(line);
	}
	else if (CardName == "Sap") {
		//Deal 4d(Int/4) damage. Gain that much mana. +6 energy
		int damage = rtd(4, guy.Intelligence/4);
		int mana = damage;
		damage = dealDamage(damage, guy, enemy, log);
		guy.DrainMana(-1 * mana);
		gainEnergy(6, guy, enemy);

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
		//Stop Drown. Gain 1 mana every turn. +10 energy
		guy.drown = 0;
		guy.refresh++;
		gainEnergy(10, guy, enemy);

		string line = "#m-You begin to refresh your mana.#o";
		log.PushPop(line);
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
		gold = guy.gainGold(gold);

		string line = "#y-You gain " + to_string(gold) + " gold.#o";
		log.PushPop(line);
	}
	else if (CardName == "Liquidate") {
		//Cost 10 gold. Deal 3d(Int) damage. +12 energy
		if (guy.Gold >= 10)
			guy.Gold -= 10;
		else
			guy.Gold = 0;

		int damage = rtd(3, guy.Intelligence);
		damage = dealDamage(damage, guy, enemy, log);
		gainEnergy(12, guy, enemy);
		
		string line = "-You #rlose 10 gold#o to deal #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}

	else if (CardName == "Sandstorm") {
		//Cost 10 mana. Everybody takes 3d(Int) damage for 3 turns
		enemy.sandstorm += 3;

		string line = "#m-You stir up a sandstorm.#o";
		log.PushPop(line);
	}
	else if (CardName == "Screen") {
		//Gain 5 mana. Negate the next 2 attacks. -2 Energy
		int mana = 5;
		guy.DrainMana(-1 * mana);
		guy.Negate+=2;
		gainEnergy(-2, guy, enemy);

		string line = "-You #mgain " + to_string(mana) + " mana#o and #cnegate the next 2 hits taken#o.";
		log.PushPop(line);
	}
	else if (CardName == "Empower") {
		//Your next Attack gains (Int/2)d3 damage. +10 Energy.
		int dmg = rtd(guy.Intelligence / 2, 3);
		guy.empower += dmg;
		gainEnergy(10, guy, enemy);

		string line = "#m-You empower your next Attack.#o";
		log.PushPop(line);
	}
	else if (CardName == "Shed") {
		//Lose all block and Negates. Gain 9 mana.
		guy.loseBlock(guy.CurrentBlock);
		guy.Negate = 0;
		int mana = -guy.DrainMana(-9);

		string line = "-You #rlose all your defenses#o and gain #m" + to_string(mana) + "#o mana.";
		log.PushPop(line);
	}
	else if (CardName == "Extract") {
		//+8 mana. Deal 10 damage. -5 Energy. +1 Int on kill.
		int mana = guy.DrainMana(-8);
		int damage = dealDamage(10, guy, enemy, log);
		gainEnergy(-5, guy, enemy);

		string line = "-You deal #y" + to_string(damage) + "#o and gain #m" + to_string(mana) + "#o mana.";
		log.PushPop(line);

		string line2 = "#m-You extract the " + string(enemy.Name) + "'s Intelligence.#o";
		if (enemy.CurrentHealth <= 0) {
			guy.ModStat(1, "Intelligence", FALSE);
			log.PushPop(line2);
		}
	}
	else if (CardName == "Drain") {
		//The Enemy loses (Int/2) max hp. +8 Energy.
		int maxhp = guy.Intelligence / 2;
		enemy.MaxHealth -= maxhp;
		if (enemy.CurrentHealth > enemy.MaxHealth)
			enemy.CurrentHealth = enemy.MaxHealth;
		gainEnergy(8, guy, enemy);

		string line = "-The " + string(enemy.Name) + "#m loses #y" + to_string(maxhp) + "#m max health#o.";
		log.PushPop(line);
	}
	else if (CardName == "Soldier") {
		//Gain 2d2 block every turn.
		guy.soldier++;

		string line = "#m-You summon a solder.#o";
		log.PushPop(line);
	}
	else if (CardName == "Attack") {
		//Lose all Soldiers. +3 mana and deal (Int) damage for each.
		int times = 0;
		int damage = 0;
		int mana = 0;
		while (guy.soldier > 0) {
			damage += dealDamage(guy.Intelligence, guy, enemy, log);
			mana += -guy.DrainMana(-3);
			times++;
			guy.soldier--;
		}

		string line = "-You command #y" + to_string(times) + " soldiers#o to deal a total of #y" +
					to_string(damage) + "#o damage and #mgain " + to_string(mana) + " mana#o.";
		log.PushPop(line);
	}
	else if (CardName == "Arise") {
		//-8 max hp for the combat. Deal 2 dmg per turn. +10 Energy.
		int maxhp = 8;
		guy.ModStat(-maxhp, "MaxHealth", TRUE);
		guy.arise++;
		gainEnergy(10, guy, enemy);

		string line = "-You #rlose " +to_string(maxhp) + " max health#o.";
		string line2 = "#m-You raise a follower from the ground.#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "The Flesh") {
		//Gain (Int) max hp for the combat.
		int maxhp = guy.Intelligence;
		guy.ModStat(maxhp, "MaxHealth", TRUE);

		string line = "#m-You gain #g" + to_string(maxhp) + " max health#m for the combat.#o";
		log.PushPop(line);
	}
	else if (CardName == "Rainbow") {
		//Deal 2d(Str) damage, gain (Def)+2 block, and (Int) Energy.
		int damage = dealDamage(rtd(2, guy.Strength), guy, enemy, log);
		int block = gainBlock(guy.Defense + 2, guy, enemy);
		gainEnergy(guy.Intelligence/2, guy, enemy);

		string line = "-You deal #y" + to_string(damage) + "#o damage and gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Focus") {
		//Gain 1+ (Int)/2 mana. Fill hand with Spells.
		int mana = -guy.DrainMana(-(1 + guy.Intelligence/2));
		guy.fillType = "Spell";

		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		log.PushPop(line);
	}
	else if (CardName == "Horrify") {
		//The enemy can't gain block or hp for (Int/2) turns.
		int h = guy.Intelligence / 2;
		guy.horrify += h;

		string line = "#m-You horrify the " + string(enemy.Name) + " for " + to_string(h) + " more turns.#o";
		log.PushPop(line);
	}
	else if (CardName == "Lurk") {
		//Gain 4 mana. +1d2 Int for the combat. +6 Energy.
		int mana = -guy.DrainMana(-4);
		int in = rtd(1, 2);
		guy.ModStat(in, "Intelligence", TRUE);
		gainEnergy(6, guy, enemy);

		string line = "-You #mgain " + to_string(mana) + " mana#o and #m" + to_string(in) + " Intelligence#o for the combat.";
		log.PushPop(line);
	}
	else if (CardName == "Screech") {
		//Pierce for (Int) damage 2d2 times.
		int damage = 0;
		int times = rtd(2, 2);

		for (int i = 0; i < times; i++) {
			pierce = TRUE;
			damage += dealDamage(guy.Intelligence, guy, enemy, log);
		}

		string line = "-You #ypierce " + to_string(times) + " times#o for a total of #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Echo") {
		//Gain 1d(Int) mana. +5 Energy.
		int mana = -guy.DrainMana(-rtd(1, guy.Intelligence));
		gainEnergy(5, guy, enemy);

		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		log.PushPop(line);
	}
	else if (CardName == "Judge") {
		//Halve the enemy's hp. +5 Energy.
		if(enemy.CurrentHealth > 1)
			enemy.CurrentHealth /= 2;
		gainEnergy(5, guy, enemy);

		string line = "#m-You halve the " + string(enemy.Name) + "'s health.#o";
		log.PushPop(line);
	}
	else if (CardName == "Bless") {
		//Gain (Int/2)d2 mana and health.
		int mana = -guy.DrainMana(-rtd(guy.Intelligence/2, 2));
		int health = -guy.TakeDamage(-rtd(guy.Intelligence / 2, 2));

		string line = "-You #mgain " + to_string(mana) + " mana#o and heal for #g" + to_string(health) + "#o health.";
		log.PushPop(line);
	}
	else if (CardName == "Aegis") {
		//Gain 2+(Int/9) Negates.
		int neg = 2 + (guy.Intelligence / 9);
		guy.Negate += neg;

		string line = "#m-You gain #c" + to_string(neg) + " Negates#m.#o";
		log.PushPop(line);
	}
	else if (CardName == "Steadfast") {
		//Lose 1 hp 2d2 times. Gain (Int/3) mana per hit.
		int times = rtd(2, 2);
		int damage = 0;
		int mana = 0;
		for (int i = 0; i < times; i++) {
			guy.pierce = TRUE;
			damage += guy.TakeDamage(1);
			mana += -guy.DrainMana(-guy.Intelligence / 3);
		}

		string line = "-You lose health and gain mana #m" + to_string(times) + " times#o for a total of #r" +
						to_string(damage) + "#o damage and #m" + to_string(mana) + "#o mana. ";
		log.PushPop(line);
	}

	//Photosynthesis trait
	if (guy.Photosynthesis && CardType == "Spell") {
		int health = guy.Skill;
		guy.TakeDamage(-1 * health);
	}
	//Archmage trait
	if (guy.Archmage) {
		guy.ModStat(1, "Intelligence", TRUE);
	}
	//Amplify
	if (guy.amplify > 0) {
		guy.amplifyTRUE = TRUE;
		guy.amplify--;
		spellFunction(guy, enemy, log);
	}
	//Psychosis trait
	if (guy.Psychosis != -1) {
		if (guy.Psychosis == 1 && (ManaCost > 0 || guy.Dazed)) {
			guy.Psychosis = 0;
			spellFunction(guy, enemy, log);
		}
		else if (guy.Psychosis == 0) {
			guy.Psychosis = 1;
		}
	}
}
void Card::bossFunction(Character &guy, Enemy &enemy, TextLog &log) {
	if (CardName == "Haste") {
		//gain 11 +3d3 energy
		gainEnergy(11 + rtd(3, 3), guy, enemy);
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
		string line = "#y-Your next attack will deal double damage.#o";
		log.PushPop(line);
	}
	else if (CardName == "Change Mind") {
		//Shuffle your hand. +10 Energy
		guy.shuffle = TRUE;
		gainEnergy(10, guy, enemy);

		string line = "-You shuffle your deck";
		log.PushPop(line);
	}
	else if (CardName == "Intimidate") {
		//Gain (Str)d3 block. Burn
		int block = gainBlock(rtd(guy.Strength, 3), guy, enemy);

		string line = "-You gain #c" + to_string(block) + "#o block.";
		log.PushPop(line);
	}
	else if (CardName == "Distract") {
		//Remove enemy block. +15 energy. Burn
		enemy.CurrentBlock = 0;
		gainEnergy(15, guy, enemy);

		string line = "#c-You remove the " + string(enemy.Name) + "'s block.#o";
		log.PushPop(line);
	}
	else if (CardName == "Prepare") {
		//Fill hand with spells. Full mana. Burn this card
		guy.fillType = "Spell";
		if(guy.CurrentMana <= guy.MaxMana)
			guy.CurrentMana = guy.MaxMana;
		string line = "#m-You restore your mana.#o";
		log.PushPop(line);
	}
	else if (CardName == "Boost") {
		//Gain 5 mana. +10 energy
		guy.DrainMana(-5);
		gainEnergy(10, guy, enemy);

		string line = "#m-You gain 5 mana.#o";
		log.PushPop(line);
	}
	else if (CardName == "Vitalise") {
		//Full health. Burn this card.
		if(guy.CurrentHealth <= guy.MaxHealth)
			guy.CurrentHealth = guy.MaxHealth;

		string line = "#g-You heal to full health.#o";
		log.PushPop(line);
	}
	else if (CardName == "Jump") {
		//Fill hand with attacks. Negate 1 attack. Burn this card.
		guy.fillType = "Attack";
		guy.Negate++;

		string line = "#c-You negate the next attack.#o";
		log.PushPop(line);
	}
	else if (CardName == "Slam") {
		//Deal your block as damage
		int damage = guy.CurrentBlock;
		damage = dealDamage(damage, guy, enemy, log);

		string line = "-You slam the " + string(enemy.Name)
			+ " for #y" + to_string(damage)
			+ "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Stall") {
		//+12 energy
		gainEnergy(12, guy, enemy);
	}
	else if (CardName == "Repel") {
		//gain 2 negate. burn
		guy.Negate += 2;

		string line = "-You #cnegate the next 2 attacks#o.";
		log.PushPop(line);
	}
	else if (CardName == "Ghost") {
		//the next card you play will not burn
		guy.ghost++;
		guy.ghostPlayed = TRUE;
		guy.ghostinarow++;

		string line = "#g-You will save your next card.#o";
		log.PushPop(line);
	}
	else if (CardName == "Catalyze") {
		//activate your over time effects thrice
		guy.catalyze += 3;

		string line = "#c-You catalyze your body.#o";
		log.PushPop(line);
	}
	else if (CardName == "Detonate") {
		//damage over time on the enemy is dealt at once
		//bleed, flay, fumes, reagent, drown, (not sandstorm thought)
		int damage = 0;
		while (enemy.bleeding + enemy.flay + enemy.fumes + guy.reagent > 0) {
			if (enemy.bleeding > 0) {
				damage += rtd(2, int(guy.Strength / 2));
				enemy.bleeding--;
			}
			if (enemy.flay > 0) {
				damage += int(guy.Strength / 2);
				enemy.flay--;
			}
			if (enemy.fumes) {
				damage += rtd(int(guy.Intelligence / 2), 2);
				enemy.fumes--;
			}
			if (guy.reagent > 0) {
				damage += rtd(1, 4);
				guy.reagent--;
			}
		}
		while (guy.drown > 0) {
			if (guy.drown > 0) {
				int mana = guy.drown;
				damage += guy.drown*guy.Intelligence / 2;
				if (guy.Sacrificial) {
					guy.TakeDamage(mana);
					if (guy.CurrentHealth <= 0)
						break;
				}
				else {
					if (guy.CurrentMana < guy.drown)
						break;
					guy.DrainMana(mana);
				}
			}
		}

		damage = dealDamage(damage, guy, enemy, log);
		if (enemy.CurrentHealth <= 0)
			guy.CurrentHealth = 1+guy.drown;

		string line = "-You detonate the " + string(enemy.Name) + " for a total of #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Polymorph") {
		//transform the enemy +10 Energy. burn
		string name1 = enemy.Name;

		polymorph(guy, enemy);

		string name2 = "a #r" + string(enemy.Name);
		if (enemy.Name[0] == 'A' || enemy.Name[0] == 'E' || enemy.Name[0] == 'I' || enemy.Name[0] == 'O' || enemy.Name[0] == 'U') {
			name2 = "an #r" + string(enemy.Name);
		}

		string line = "#g-You polymorph the #r" + string(name1) + "#g into " + string(name2) + "#g!#o ";
		log.PushPop(line);

		gainEnergy(10, guy, enemy);
	}
	else if (CardName == "Cleanse") {
		//burn whole hand. +10 energy
		guy.cleanse = TRUE;
		gainEnergy(10, guy, enemy);

		string line = "#g-You cleanse your hand.#o";
		log.PushPop(line);
	}
	else if (CardName == "Teleport") {
		//End combat. Go to a random nearby tile.
		guy.teleport = TRUE;
	}
	else if (CardName == "Inject") {
		//Next damage dealt heals you for the same. +10 Energy. Burn.
		guy.inject++;
		gainEnergy(10, guy, enemy);

		string line = "#c-Your next damage dealt will heal you.#o";
		log.PushPop(line);
	}
	else if (CardName == "Flurry") {
		//Cards also Attack for 3 damage. +10 Energy. Burn.
		guy.flurry++;
		gainEnergy(10, guy, enemy);

		string line = "#y-You launch into a flurry of attacks.#o";
		log.PushPop(line);
	}
	else if (CardName == "Materialize") {
		//Your next heal also gives block. +10 Energy. Burn
		guy.materialize++;
		gainEnergy(10, guy, enemy);

		string line = "#c-Your next heal will also give block.#o";
		log.PushPop(line);
	}
	else if (CardName == "Overdrive") {
		//All stats +8 for 3 turns, then stats -10. +10 Energy. Burn.
		guy.ModStat(8, "Strength", TRUE);
		guy.ModStat(8, "Defense", TRUE);
		guy.ModStat(8, "Intelligence", TRUE);
		guy.ModStat(8, "Skill", TRUE);
		guy.ModStat(8, "MaxHealth", TRUE);
		guy.ModStat(8, "MaxMana", TRUE);

		guy.overdrive += 3;
		guy.overdrivestats += 10;
		gainEnergy(10, guy, enemy);

		string line = "#r-You overexert yourself.#o";
		log.PushPop(line);
	}
	else if (CardName == "Enrich") {
		//Gain 1 mana per turn. +10 Energy. Burn.
		guy.enrich++;
		gainEnergy(10, guy, enemy);

		string line = "#m-You increase your mana regeneration.#o";
		log.PushPop(line);
	}
	else if (CardName == "Shimmer") {
		//Deal (Gold) damage, lose your gold. +10 Energy. Burn.
		int damage = guy.Gold;
		guy.gainGold(-damage);
		damage = dealDamage(damage, guy, enemy, log);

		gainEnergy(10, guy, enemy);

		string line = "-You deal #$" + to_string(damage) + "#o damage.";
		string line2 = "#r-You lose all of your gold.#o";
		log.PushPop(line);
		log.PushPop(line2);
	}
	else if (CardName == "Relax") {
		//Stop your turn effects for 5 turns. +10 Energy. Burn.
		guy.relax += 5;
		gainEnergy(10, guy, enemy);

		string line = "#g-You relax your body.#o";
		log.PushPop(line);
	}
	else if (CardName == "Sharpen") {
		//Next damage dealt pierces. +10 Energy. Burn.
		guy.sharpen++;
		gainEnergy(10, guy, enemy);

		string line = "#y-Your next damage dealt will pierce.#o";
		log.PushPop(line);
	}
	else if (CardName == "Amplify") {
		//Next Spell is used twice. +10 Energy. Burn.
		guy.amplify++;
		gainEnergy(10, guy, enemy);

		string line = "#m-You will amplify your next spell.#o";
		log.PushPop(line);
	}
	else if (CardName == "Cell") {
		//Next Spell that has cost is free. +10 Energy. Burn.
		guy.cell++;
		gainEnergy(10, guy, enemy);

		string line = "#m-Your next Spell with cost will be free.#o";
		log.PushPop(line);
	}
	else if (CardName == "Deflect") {
		//Next damage taken is dealt to enemy instead. Burn.
		guy.deflect++;
		guy.Negate++;
		gainEnergy(10, guy, enemy);

		string line = "#c-You will deflect your next hit.#o";
		log.PushPop(line);
	}
	else if (CardName == "Save") {
		//Dying next turn brings you back to life. Burn
		guy.save++;

		string line = "#r-You feel immortal.#o";
		log.PushPop(line);
	}
	else if (CardName == "Stop") {
		//You will not take damage next turn. Burn
		guy.stop++;

		string line = "#r-You feel invincible.#o";
		log.PushPop(line);
	}
	else if (CardName == "Chaos") {
		//play a random card
		vector<const char*> cards;

		cards.push_back("Smack");
		cards.push_back("Magic Smack");
		cards.push_back("Charge");
		cards.push_back("Pierce");
		cards.push_back("Throw");
		cards.push_back("Impale");
		cards.push_back("Parry");
		cards.push_back("Feint");
		cards.push_back("Slice");
		cards.push_back("Crush");
		cards.push_back("Demolish");
		cards.push_back("Bleed");
		cards.push_back("Hack");
		cards.push_back("Stab");
		cards.push_back("Zap");
		cards.push_back("Ram");
		cards.push_back("Flay");
		cards.push_back("Slash");
		cards.push_back("Lash");
		cards.push_back("Pummel");
		cards.push_back("Shoot");
		cards.push_back("Rend");
		cards.push_back("Prick");
		cards.push_back("Ritual");
		cards.push_back("Laser");

		cards.push_back("Endure");
		cards.push_back("Force Field");
		cards.push_back("Block");
		cards.push_back("Obstruct");
		cards.push_back("Disrupt");
		cards.push_back("Dodge");
		cards.push_back("Dash");
		cards.push_back("Brace");
		cards.push_back("Counter");
		cards.push_back("Predict");
		cards.push_back("Absorb");
		cards.push_back("Reinforce");
		cards.push_back("Flee");
		cards.push_back("Spikes");
		cards.push_back("Repulse");
		cards.push_back("Toughen");
		cards.push_back("Defend");
		cards.push_back("Gamble");
		cards.push_back("Inspire");
		cards.push_back("Bide");
		cards.push_back("Restore");
		cards.push_back("Form");
		cards.push_back("Tear");
		cards.push_back("Barrier");

		cards.push_back("Ponder");
		cards.push_back("Channel");
		cards.push_back("Blast");
		cards.push_back("Leech");
		cards.push_back("Transmute");
		cards.push_back("Blink");
		cards.push_back("Singularity");
		cards.push_back("Freeze");
		cards.push_back("Shard");
		cards.push_back("Fumes");
		cards.push_back("Incense");
		cards.push_back("Fireball");
		cards.push_back("Fuel");
		cards.push_back("Charm");
		cards.push_back("Attract");
		cards.push_back("Copy");
		cards.push_back("Confuse");
		cards.push_back("Lightning");
		cards.push_back("Shock");
		cards.push_back("Destroy");
		cards.push_back("Construct");
		cards.push_back("Beam");
		cards.push_back("Diffract");
		cards.push_back("Sap");
		cards.push_back("Synthesize");
		cards.push_back("Drown");
		cards.push_back("Refresh");
		cards.push_back("Reagent");
		cards.push_back("Reactant");
		cards.push_back("Transmogrify");
		cards.push_back("Liquidate");
		cards.push_back("Sandstorm");
		cards.push_back("Screen");
		cards.push_back("Empower");
		cards.push_back("Shed");
		cards.push_back("Extract");
		cards.push_back("Drain");
		cards.push_back("Soldier");
		cards.push_back("Attack");
		cards.push_back("Arise");
		cards.push_back("The Flesh");
		cards.push_back("Rainbow");
		cards.push_back("Focus");
		cards.push_back("Horrify");
		cards.push_back("Lurk");
		cards.push_back("Screech");
		cards.push_back("Echo");
		cards.push_back("Judge");
		cards.push_back("Bless");
		cards.push_back("Aegis");
		cards.push_back("Steadfast");

		cards.push_back("Haste");
		cards.push_back("Revivify");
		cards.push_back("Steroids");
		cards.push_back("Change Mind");
		cards.push_back("Intimidate");
		cards.push_back("Distract");
		cards.push_back("Prepare");
		cards.push_back("Boost");
		cards.push_back("Vitalise");
		cards.push_back("Jump");
		cards.push_back("Slam");
		cards.push_back("Stall");
		cards.push_back("Repel");
		cards.push_back("Ghost");
		cards.push_back("Catalyze");
		cards.push_back("Detonate");
		cards.push_back("Polymorph");
		cards.push_back("Cleanse");
		cards.push_back("Teleport");
		cards.push_back("Inject");
		cards.push_back("Flurry");
		cards.push_back("Materialize");
		cards.push_back("Overdrive");
		cards.push_back("Enrich");
		cards.push_back("Shimmer");
		cards.push_back("Relax");
		cards.push_back("Sharpen");
		cards.push_back("Amplify");
		cards.push_back("Cell");
		cards.push_back("Deflect");
		cards.push_back("Save");
		cards.push_back("Stop");

		cards.push_back("Steam");
		cards.push_back("Scalding Steam");
		cards.push_back("Webbed");
		cards.push_back("Drain Str");
		cards.push_back("Drain Def");
		cards.push_back("Drain Int");
		cards.push_back("Patch");
		cards.push_back("Mad");
		cards.push_back("Burn");

		CardName = cards.at(rand() % cards.size());
		setType();
		ManaCost = 0;
		chaos = TRUE;
		cardFunction(guy, enemy, log);
		CardName = "Chaos";
		CardType = "BossCard";
		chaos = FALSE;
	}

	//Strain trait
	if (guy.Strain) {
		gainEnergy(-5, guy, enemy);
	}
}
void Card::negativeFunction(Character &guy, Enemy &enemy, TextLog &log) {
	if (CardName == "Steam") {
		//take 5 damage, +10 energy
		int damage = guy.TakeDamage(7);
		gainEnergy(10, guy, enemy);

		string line = "-You burn for #r" + to_string(damage) + "#o damage.";
		log.PushPop(line);
	}
	else if (CardName == "Scalding Steam") {
		//take 5 damage, +10 energy
		int damage = guy.TakeDamage(12);
		gainEnergy(10, guy, enemy);

		string line = "-You burn for #r" + to_string(damage) + "#o damage.";
		log.PushPop(line);
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
		guy.ModStat(-1, "Strength", TRUE);
		string line = "-You #rlose 1 Strength.#o";
		log.PushPop(line);
	}
	else if (CardName == "Drain Def") {
		guy.ModStat(-1, "Defense", TRUE);
		string line = "-You #rlose 1 Defense.#o";
		log.PushPop(line);
	}
	else if (CardName == "Drain Int") {
		guy.ModStat(-1, "Intelligence", TRUE);
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
			guy.ModStat(2, "Strength", TRUE);
			break;
		case 1:
			guy.ModStat(2, "Defense", TRUE);
			break;
		case 2:
			guy.ModStat(2, "Intelligence", TRUE);
			break;
		case 3:
			guy.ModStat(2, "MaxHealth", TRUE);
			break;
		case 4:
			guy.ModStat(2, "MaxMana", TRUE);
			break;
		case 5:
			guy.ModStat(2, "Skill", TRUE);
			break;
		}
		rng = rand() % 6;
		switch (rng) {
		case 0:
			guy.ModStat(-2, "Strength", TRUE);
			break;
		case 1:
			guy.ModStat(-2, "Defense", TRUE);
			break;
		case 2:
			guy.ModStat(-2, "Intelligence", TRUE);
			break;
		case 3:
			guy.ModStat(-2, "MaxHealth", TRUE);
			break;
		case 4:
			guy.ModStat(-2, "MaxMana", TRUE);
			break;
		case 5:
			guy.ModStat(-2, "Skill", TRUE);
			break;
		}
		gainEnergy(10, guy, enemy);
		string line = "#r-You go slightly insane.#o";
		log.PushPop(line);
	}
	else if (CardName == "Burn") {
		//Burn your next card. +10 Energy
		guy.burncard++;
		guy.burnPlayed = TRUE;
		guy.burninarow++;
		gainEnergy(10, guy, enemy);

		string line = "#r Your next card will burn.#o";
		log.PushPop(line);
	}

	//Optimist trait
	if (guy.Optimist) {
		int damage = dealDamage(guy.Skill * 3, guy, enemy, log);
		string line = "-You deal #y" + to_string(damage) + "#o damage.";
		log.PushPop(line);
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
	//Technician trait
	if (guy.Technician && damage < 10) {
		damage *= 2;
	}
	//Empower
	if (guy.empower > 0 && CardType == "Attack") {
		damage += guy.empower;
		guy.empower = 0;
	}
	//Sharp Claws trait
	if (guy.Sharp_Claws) {
		int claw = rtd(1, guy.Skill);
		damage += claw;
	}
	//Muscle Mass trait
	if (guy.Muscle_Mass != -1) {
		guy.Muscle_MassDamage += damage;
		damage = 0;
	}
	//Strategy trait
	if (guy.Strategy) {
		int block = gainBlockStrategy(damage, guy, enemy);
		return block;
	}

	int damage2 = damage;
	//invisibility
	if (enemy.invisible > 0) {
		damage2 = 0;
	}
	if (enemy.enemyNegate > 0) {
		enemy.enemyNegate--;
		damage2 = 0;
	}
	if (damage < 0) {
		damage2 = 0;
	}
	//Reckless trait
	if (guy.Reckless && damage2 > 0) {
		guy.TakeDamage(2);
	}
	//pierce
	if (pierce || guy.sharpen > 0) {
		enemy.CurrentHealth -= damage2;
		pierce = FALSE;
		if (guy.sharpen > 0)
			guy.sharpen--;
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
	//Inject card
	if (guy.inject > 0) {
		int health = guy.TakeDamage(-damage2);
		string line = "-You gain #g" + to_string(-health) + "#o health.";
		log.PushPop(line);
		guy.inject--;
	}
	//Fuel card
	if (guy.damageToMana > 0) {
		int mana = damage2 - enemy.CurrentBlock;
		if (mana < 0)
			mana = 0;
		guy.DrainMana(-1 * mana);
		guy.damageToMana--;
		string line = "#m-You gain " + to_string(mana) + " mana.#o";
		log.PushPop(line);
	}

	return damage;
	enemy.updateEnemy(guy);
}

//this is for the Strategy trait
int Card::dealDamageStrategy(int damage, Character &guy, Enemy &enemy) {
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
	}
	return damage2;
}

int Card::gainBlock(int block, Character &guy, Enemy &enemy) {
	if (guy.Strategy) {
		int dmg = dealDamageStrategy(block, guy, enemy);
		return dmg;
	}
	int b = block;
	if (b < 0)
		b = 0;
	else {
		//Charred Skin trait
		if (guy.Charred_Skin)
			guy.TakeDamage(-1 * b);
		else if(guy.Overconfidence < 6)
			guy.CurrentBlock += b;
	}
	if (guy.CurrentBlock > 999) {
		guy.CurrentBlock = 999;
	}

	return b;
}

//this is for the Strategy trait
int Card::gainBlockStrategy(int block, Character &guy, Enemy &enemy) {
	int b = block;
	if (b < 0)
		b = 0;
	else {
		//Charred Skin trait
		if (guy.Charred_Skin)
			guy.TakeDamage(-1 * b);
		else if (guy.Overconfidence < 6)
			guy.CurrentBlock += b;
	}
	if (guy.CurrentBlock > 999) {
		guy.CurrentBlock = 999;
	}

	return b;
}

int Card::gainEnergy(int energy, Character &guy, Enemy &enemy) {
	int en = energy;
	//Stamina trait
	if (guy.Stamina && guy.Energy < 0)
		en *= 2;
	//Heavy trait
	if (guy.Heavy)
		gainBlock(en, guy, enemy);
	else {
		guy.Energy += en;
	}

	//Flat Feet trait
	if (guy.Flat_Feet && guy.Energy <= -5) {
		guy.Energy = -10;
	}

	return en;
}

//transform the enemy to one of the same tier
void Card::polymorph(Character &guy, Enemy &enemy) {
	Enemy beforeenemy = enemy;

	int enemyhp = enemy.CurrentHealth;
	int enemyblock = enemy.CurrentBlock;
	int enemyneg = enemy.enemyNegate;
	int enemytc = enemy.TurnCount;
	int enemydot = enemy.dot;
	int enemyreward = enemy.goldreward;


	vector<Enemy> early;
	vector<Enemy> mid;
	vector<Enemy> late;
	vector<Enemy> boss;
	vector<Enemy> finalboss;

	early.push_back(Enemy("Rat"));
	early.push_back(Enemy("Crab"));
	early.push_back(Enemy("Hound"));
	early.push_back(Enemy("Zombie"));
	early.push_back(Enemy("Kobold"));
	mid.push_back(Enemy("Giant Rat"));
	mid.push_back(Enemy("Wild Buffalo"));
	mid.push_back(Enemy("Harpy"));
	mid.push_back(Enemy("Brown Recluse"));
	late.push_back(Enemy("Adventurer"));
	late.push_back(Enemy("Adventurer"));
	late.push_back(Enemy("Troll"));
	late.push_back(Enemy("Elemental"));

	early.push_back(Enemy("Hatchling"));
	mid.push_back(Enemy("Molten Jelly"));
	late.push_back(Enemy("Knight"));
	late.push_back(Enemy("Drake"));
	early.push_back(Enemy("Slave"));
	mid.push_back(Enemy("Soldier"));
	late.push_back(Enemy("Guard"));
	late.push_back(Enemy("Jester"));
	early.push_back(Enemy("Eyeball"));
	mid.push_back(Enemy("Apprentice"));
	late.push_back(Enemy("Monster"));
	late.push_back(Enemy("Brain"));
	early.push_back(Enemy("Cultist"));
	mid.push_back(Enemy("Imp"));
	late.push_back(Enemy("Weeping Soul"));
	late.push_back(Enemy("Hellhound"));
	early.push_back(Enemy("Robot"));
	mid.push_back(Enemy("Golem"));
	late.push_back(Enemy("Merchant"));
	late.push_back(Enemy("Turret"));

	boss.push_back(Enemy("Paladin"));
	boss.push_back(Enemy("Juggernaut"));
	boss.push_back(Enemy("Vampire"));
	boss.push_back(Enemy("Hydra"));
	boss.push_back(Enemy("Demigod"));
	boss.push_back(Enemy("Hunter"));
	boss.push_back(Enemy("Exorcist"));
	boss.push_back(Enemy("Wolf"));
	boss.push_back(Enemy("Druid"));
	boss.push_back(Enemy("Serpent"));
	boss.push_back(Enemy("Spirit"));
	boss.push_back(Enemy("Artificer"));

	finalboss.push_back(Enemy("King"));
	finalboss.push_back(Enemy("Demon"));
	finalboss.push_back(Enemy("Witch"));
	finalboss.push_back(Enemy("Dragon"));
	finalboss.push_back(Enemy("Machine"));

	char tier = guy.getTier();

	if (guy.RoomType == "Final Boss") {
		int rng = rand() % finalboss.size();
		enemy = finalboss.at(rng);

		//Doomed trait
		if (guy.Doomed)
			enemy.MaxHealth *= 1.5;
	}
	else if (guy.RoomType == "Boss") {
		int rng = rand() % boss.size();
		enemy = boss.at(rng);

		if (guy.getTier() == 'C')
			enemy.tier = 2;
		if (guy.getTier() == 'D')
			enemy.tier = 3;
		if (guy.getTier() == 'E')
			enemy.tier = 4;
		if (guy.getTier() == 'F')
			enemy.tier = 5;

		enemy.setStats(guy);
	}
	else if (tier == 'A' || tier == 'B') {
		int rng = rand() % early.size();
		enemy = early.at(rng);
	}
	else if (tier == 'C' || tier == 'D') {
		int rng = rand() % mid.size();
		enemy = mid.at(rng);
	}
	else if (tier == 'E' || tier == 'F') {
		int rng = rand() % late.size();
		enemy = late.at(rng);
	}

	if (enemy.Name == beforeenemy.Name) {
		polymorph(guy, enemy);
	}

	enemy.CurrentHealth = enemyhp;
	enemy.CurrentBlock = enemyblock;
	enemy.enemyNegate = enemyneg;
	enemy.TurnCount = enemytc;
	enemy.dot = enemydot;
	enemy.goldreward = enemyreward;

	if (enemy.CurrentHealth > enemy.MaxHealth) {
		enemy.CurrentHealth = enemy.MaxHealth;
	}

	manualBox("Display", 0);
	enemy.updateEnemy(guy);
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
			Stay++;
			tempStay = Stay;
		}
		else {
			Stay = 0;
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
			string m = "Choose a position in the chain (1-9). 1 draws 2, 2 draws 3, and so on. The chain stops at the last number. 0 removes the Link mod from the card.";
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
	if (Stay > 0) {
		charline += "#gS" + to_string(tempStay) + "#o";
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
	if (Stay > 0) {
		mods += "#gStay" + to_string(tempStay) + "#o";
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
	for (int i = 0; i < Stay; i++) {
		guy.Stay++;
	}
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
	Stay = 0;
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

void Card::setStay() {
	tempStay = Stay;
}

//functions for specific traits and cards
//resets card values
void Card::resetTraitValues() {
	blackout = FALSE;
	combobreaker = 0;
	memorylapse = FALSE;
}

//sets the type of the card based on the name, used for Chaos
void Card::setType() {
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
		CardName == "Shoot" ||
		CardName == "Rend" ||
		CardName == "Ritual" ||
		CardName == "Prick" ||
		CardName == "Laser") {
		CardType = "Attack";
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
		CardName == "Toughen" ||
		CardName == "Defend" ||
		CardName == "Gamble" ||
		CardName == "Inspire" ||
		CardName == "Bide" ||
		CardName == "Restore" ||
		CardName == "Form" ||
		CardName == "Tear" ||
		CardName == "Barrier") {
		CardType = "Defend";
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
		CardName == "Empower" ||
		CardName == "Shed" ||
		CardName == "Extract" ||
		CardName == "Drain" ||
		CardName == "Soldier" ||
		CardName == "Attack" ||
		CardName == "Arise" ||
		CardName == "The Flesh" ||
		CardName == "Rainbow" ||
		CardName == "Focus" ||
		CardName == "Horrify" ||
		CardName == "Lurk" ||
		CardName == "Screech" ||
		CardName == "Echo" ||
		CardName == "Judge" ||
		CardName == "Bless" ||
		CardName == "Aegis" ||
		CardName == "Steadfast") {
		CardType = "Spell";
	}
	//bosss
	else if (CardName == "Haste" ||
		CardName == "Revivify" ||
		CardName == "Steroids" ||
		CardName == "Change Mind" ||
		CardName == "Intimidate" ||
		CardName == "Distract" ||
		CardName == "Prepare" ||
		CardName == "Boost" ||
		CardName == "Vitalise" ||
		CardName == "Jump" ||
		CardName == "Slam" ||
		CardName == "Stall" ||
		CardName == "Repel" ||
		CardName == "Ghost" ||
		CardName == "Catalyze" ||
		CardName == "Detonate" ||
		CardName == "Polymorph" ||
		CardName == "Cleanse" ||
		CardName == "Teleport" ||
		CardName == "Inject" ||
		CardName == "Flurry" ||
		CardName == "Materialize" ||
		CardName == "Overdrive" ||
		CardName == "Enrich" ||
		CardName == "Shimmer" ||
		CardName == "Relax" ||
		CardName == "Sharpen" ||
		CardName == "Amplify" ||
		CardName == "Cell" ||
		CardName == "Deflect" ||
		CardName == "Save" ||
		CardName == "Stop" ||
		CardName == "Chaos") {
		CardType = "BossCard";
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
		CardName == "Mad" ||
		CardName == "Burn") {
		CardType = "Negative";
	}
}
