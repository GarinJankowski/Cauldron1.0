#include "pch.h"
#include "Gear.h"

/*Types:
	Hands (attacks):
		No Weapon: 2 smacks
	Body (defends):
		No Armor: 2 endures
		Mage Armor:
	Head (spells):
		No Headgear: nothing
*/
WINDOW *makeWindow(int height, int width, int starty, int startx);
void mvprintInSize(int starty, int startx, int maxx, const char* toBePrinted);
//manually draw boxes
void manualBox(string typebox, int colorpair);

//printing Succumb trait
bool Succumb = FALSE;

Gear::Gear() {
	GearName = "";
}
Gear::Gear(const char *name):GearName(name)
{
	GearName = name;
	//Hands
	if (GearName == "No Weapon") {
		Type = "Hands";
		Description = "Bare hands are better than no hands.";
	}
	else if (GearName == "Crystal Ball") {
		Type = "Hands";
		Description = "A glass ball on a stand, supposedly used for scrying. Not a very good weapon, though.";
	}
	else if (GearName == "Shield") {
		Type = "Hands";
		Description = "Although it doesn't look like much of a weapon, it can pack quite an offensive punch.";
	}
	else if (GearName == "Long Sword") {
		Type = "Hands";
		Description = "A sturdy weapon with a double sided blade.";
	}
	else if (GearName == "Falchion") {
		Type = "Hands";
		Description = "A one-handed sword with a heavy blade, great for hacking throuhg armor.";
	}
	else if (GearName == "Metal Staff") {
		Type = "Hands";
		Description = "A long metal stick, a much more lethal weapon than its wooden counterparts.";
	}
	else if (GearName == "Steel Spear") {
		Type = "Hands";
		Description = "The pointed blade proves useful at piercing tough armor.";
	}
	else if (GearName == "Javelin") {
		Type = "Hands";
		Description = "A spear not just used for long ranged stabbing, but a useful projectile, as well.";
	}
	else if (GearName == "Obsidian Spear") {
		Type = "Hands";
		Description = "This spear has been sharpened so much that it will slide right through the victim.";
	}
	else if (GearName == "Halberd") {
		Type = "Hands";
		Description = "An axe head on a spear, a multipurpose tool.";
	}
	else if (GearName == "Lance") {
		Type = "Hands";
		Description = "A heavy charging spear made for cavalry, but will do just fine without a mount.";
	}
	else if (GearName == "Rapier") {
		Type = "Hands";
		Description = "A thin sword, capable of swift movements and deadly thrusts.";
	}
	else if (GearName == "War Hammer") {
		Type = "Hands";
		Description = "Extremely heavy, capable of dealing devastating blows.";
	}
	else if (GearName == "Morning Star") {
		Type = "Hands";
		Description = "A spiked mace, both used for blunt force and piercing strikes.";
	}
	else if (GearName == "Battle Axe") {
		Type = "Hands";
		Description = "An axe not for chopping trees but for chopping enemies.";
	}
	else if (GearName == "Double Axe") {
		Type = "Hands";
		Description = "A heavy war axe that can deal most powerful cleaving blows.";
	}
	else if (GearName == "Shiv") {
		Type = "Hands";
		Description = "A small blade, even compared to a dagger, used for a quick stab or two.";
	}
	else if (GearName == "Serrated Dagger") {
		Type = "Hands";
		Description = "A short blade with a jagged edge, wonderful for punturing its victims.";
	}
	else if (GearName == "Simple Bow") {
		Type = "Hands";
		Description = "A long ranged weapon so that enemies may be dealt with from afar.";
	}
	else if (GearName == "Recurve Bow") {
		Type = "Hands";
		Description = "A bow with its ends curved outwards, capable of firing more quick and powerful shots.";
	}
	else if (GearName == "Throwing Stars") {
		Type = "Hands";
		Description = "An ancient assassin's tool for quick and accurate strikes from range. ";
	}
	else if (GearName == "Wand") {
		Type = "Hands";
		Description = "A short, carved stick that has been enchanted to channel an amount of the user's arcane energy outwards to inflict harm.";
	}
	else if (GearName == "Sickle") {
		Type = "Hands";
		Description = "A very strange and surprisingly versatile tool, modified to be used as a weapon rather than a farming apparatus.";
	}
	else if (GearName == "Hand Cannon") {
		Type = "Hands";
		Description = "A terrible piece of technology, capable of firing immensely destructive shots without even the use of magic.";
	}
	else if (GearName == "Conductive Gloves") {
		Type = "Hands";
		Description = "These weapons allow you to direct magic into your fists for mighty blows.";
	}
	else if (GearName == "Sabre") {
		Type = "Hands";
		Description = "A single-edged blade for consistent slashing.";
	}
	else if (GearName == "Whip") {
		Type = "Hands";
		Description = "A simple cord on a handle, difficult to control at first, but powerful when used correctly.";
	}
	else if (GearName == "Twin Flail") {
		Type = "Hands";
		Description = "Two chains with spiked balls at the end. Dangerous.";
	}
	else if (GearName == "Leather Gauntlets") {
		Type = "Hands";
		Description = "The fists are mighty weapons, but flesh is soft and requires protection.";
	}
	else if (GearName == "Steel Gauntlets") {
		Type = "Hands";
		Description = "Converts your knuckes into hard and powerful steel.";
	}
	else if (GearName == "Spiked Gauntlets") {
		Type = "Hands";
		Description = "Steel gloves with spikes at the knuckles, allowing for puncturing blows.";
	}
	else if (GearName == "Arbalest") {
		Type = "Hands";
		Description = "A large crossbow with a mechanism to draw back bolts automatically, providing more power and speed.";
	}
	else if (GearName == "Dirk") {
		Type = "Hands";
		Description = "A long combat dagger.";
	}
	else if (GearName == "Cutlass") {
		Type = "Hands";
		Description = "A common weapon of sailors and pirates, useful for close quarters combat.";
	}
	//Body
	else if (GearName == "No Armor") {
		Type = "Body";
		Description = "Your tough form can take a hit or two.";
	}
	else if (GearName == "Mage Armor") {
		Type = "Body";
		Description = "This full body armor was specifically built for arcane soldiers, channeling the user's power in order to harden the material.";
	}
	else if (GearName == "Glitter Robes") {
		Type = "Body";
		Description = "These blindingly shiny robes provide almost no protection, but do provide a modest boost to the wearer's arcane energy.";
	}
	else if (GearName == "Riveted Chainmail") {
		Type = "Body";
		Description = "The strongest and lightest mail. Having taken so long to make, only the greatest of champions were given these.";
	}
	else if (GearName == "Reinforced Mail") {
		Type = "Body";
		Description = "A mix of mail and plates, this armor is reliable and fairly easy to move in.";
	}
	else if (GearName == "Full Plate Armor") {
		Type = "Body";
		Description = "The heaviest armor you can find, it is restricting but extremely sturdy.";
	}
	else if (GearName == "Cape") {
		Type = "Body";
		Description = "This is not only an accessory, but provides great dexterity in combat.";
	}
	else if (GearName == "Feathered Cloak") {
		Type = "Body";
		Description = "This cloak is composed of feathers, specifically made to increase your swiftness as you run.";
	}
	else if (GearName == "Leather Hauberk") {
		Type = "Body";
		Description = "Although leather may not be as strong as steel, this tunic provides great versatility in combat.";
	}
	else if (GearName == "Twilight Robes") {
		Type = "Body";
		Description = "Dash through the darkness, concealing your exact position even in combat.";
	}
	else if (GearName == "Dragon Scales") {
		Type = "Body";
		Description = "As tough as plate armor and as sharp as daggers, dragon scales also provide slight psychic enhancement.";
	}
	else if (GearName == "Spiked Mail") {
		Type = "Body";
		Description = "Sturdy mail interwoven with long spikes, this piece of equipment will deal great harm to any attacker.";
	}
	else if (GearName == "Buffalo Hide") {
		Type = "Body";
		Description = "The primary choice of battle-wear for the Berserkers, this clothing displays full commitment to unequivocal offensive rage.";
	}
	else if (GearName == "Steel Breastplate") {
		Type = "Body";
		Description = "A sturdy plate made with a the strongest alloy those alchemists could muster.";
	}
	else if (GearName == "Amulet of Aura") {
		Type = "Body";
		Description = "This jewelled necklace shines brightly when worn, emanating some kind of force that the user is given control over.";
	}
	else if (GearName == "Turtle Shell") {
		Type = "Body";
		Description = "A thick shell from an extraordinarily large turtle, one wearing this would probably not feel a thing from oncoming attackers.";
	}
	else if (GearName == "Crystal Breastplate") {
		Type = "Body";
		Description = "Made from the hardest materials one can manage to find, this mesmerizingly iridescent plate also connects with the wearer's mind.";
	}
	//Head
	else if (GearName == "No Headgear") {
		Type = "Head";
		Description = "Focus the mind, channel your inner power.";
	}
	else if (GearName == "Brown Hat") {
		Type = "Head";
		Description = "Who needs spells?";
	}
	else if (GearName == "Vampire Fangs") {
		Type = "Head";
		Description = "These loose canines will attach to yours like a magnet. It siphons the life of the wearer, but provides returns through its victims.";
	}
	else if (GearName == "Warp Goggles") {
		Type = "Head";
		Description = "These telescopic goggles allow you too manipulate and modify space as you see fit.";
	}
	else if (GearName == "Tundra Cap") {
		Type = "Head";
		Description = "This winter hat has been enchanted to steal and release heat at a focused area. This makes it very warm when being used.";
	}
	else if (GearName == "Plague Mask") {
		Type = "Head";
		Description = "Resembling the head of a bird, the beak of this mask contains many herbs and spices meant to shield the wearer from miasma.";
	}
	else if (GearName == "Dragonskin Hood") {
		Type = "Head";
		Description = "Skinned from an actual dragon, this hood radiates heat. It infuses the user with some abilities of a fire breather.";
	}
	else if (GearName == "Shifting Veil") {
		Type = "Head";
		Description = "The mind of whoever looks at this veil is bound to the whims of the wearer on the other side.";
	}
	else if (GearName == "Copper Cage") {
		Type = "Head";
		Description = "An odd piece of headgear, whoever created this cage probably wished to channel the power of electricity, and likely died trying.";
	}
	else if (GearName == "Bedstone Helmet") {
		Type = "Head";
		Description = "An extremely large and heavy and piece of equipment. This helmet allows the user to destroy and reform it to create unbreakable walls and bludgeons.";
	}
	//Trait Sacrifice
	else if (GearName == "Anemia") {
		Type = "Trait Sacrifice";
		Description = "Every turn, 25% chance to lose 5 health.";
	}
	else if (GearName == "Dumb") {
		Type = "Trait Sacrifice";
		Description = "-4 Int, +1 Def.";
	}
	else if (GearName == "Mind Flooded") {
		Type = "Trait Sacrifice";
		Description = "Add one Ponder (+2 mana) card to your deck.";
	}
	else if (GearName == "Tunnel Vision") {
		Type = "Trait Sacrifice";
		Description = "-2 Str, -2 Def, +1 Skl.";
	}
	else if (GearName == "Teleportitis") {
		Type = "Trait Sacrifice";
		Description = "Chance to move 1-2 rooms in any direction.";
	}
	else if (GearName == "Growing Pains") {
		Type = "Trait Sacrifice";
		Description = "Start each battle with 10 health lost.";
	}
	else if (GearName == "Conversion") {
		Type = "Trait Sacrifice";
		Description = "Each turn lose 2 mana and heal 1 health.";
	}
	else if (GearName == "Inversion") {
		Type = "Trait Sacrifice";
		Description = "Each turn take 3 damage and gain 1 mana.";
	}
	else if (GearName == "Jittery") {
		Type = "Trait Sacrifice";
		Description = "Lose block if kept for 4 turns.";
	}
	else if (GearName == "Tumors") {
		Type = "Trait Sacrifice";
		Description = "Lose 1 max health in battle every time you heal.";
	}
	else if (GearName == "Devolve") {
		Type = "Trait Sacrifice";
		Description = "Remove 1 positive trait. +1 Skl.";
	}
	else if (GearName == "Volatile") {
		Type = "Trait Sacrifice";
		Description = "Every 4 turns, everybody takes 15 damage.";
	}
	else if (GearName == "Melting") {
		Type = "Trait Sacrifice";
		Description = "Lose 2 block and take 1 damage every turn.";
	}
	else if (GearName == "The Box") {
		Type = "Trait Sacrifice";
		Description = "Reroll all stats.";
	}
	else if (GearName == "Amnesia") {
		Type = "Trait Sacrifice";
		Description = "Remove half of the map icons.";
	}
	else if (GearName == "Long Legs") {
		Type = "Trait Sacrifice";
		Description = "Skip a space for the next 3 steps.";
	}
	else if (GearName == "Oblivious") {
		Type = "Trait Sacrifice";
		Description = "You no longer see the text log.";
	}
	else if (GearName == "Blind") {
		Type = "Trait Sacrifice";
		Description = "You no longer see the enemy's stats.";
	}
	else if (GearName == "Numb") {
		Type = "Trait Sacrifice";
		Description = "You no longer see your stats.";
	}
	else if (GearName == "Sensitive") {
		Type = "Trait Sacrifice";
		Description = "All of your over-time effects occur twice every turn.";
	}
	else if (GearName == "Frenzy") {
		Type = "Trait Sacrifice";
		Description = "Take and deal double damage.";
	}
	else if (GearName == "Corpse") {
		Type = "Trait Sacrifice";
		Description = "You can no longer heal. +5 max hp.";
	}
	else if (GearName == "Radioactive") {
		Type = "Trait Sacrifice";
		Description = "Everybody takes (Skl/2) damage every turn.";
	}
	else if (GearName == "Forgetful") {
		Type = "Trait Sacrifice";
		Description = "You start combat with zero mana. +2 max mana.";
	}
	else if (GearName == "Tiny") {
		Type = "Trait Sacrifice";
		Description = "Reduce max hp by 39. +10 defense.";
	}
	else if (GearName == "Succumb") {
		Type = "Trait Sacrifice";
		Description = "Your traits are now randomly chosen. +2 Skill.";
	}
	
	//Trait Reward
	else if (GearName == "Mending Flesh") {
		Type = "Trait Reward";
		Description = "Heal 1d(Skl) health each turn.";
	}
	else if (GearName == "Gymnast") {
		Type = "Trait Reward";
		Description = "4x(Skl)% chance to get an extra turn in battle.";
	}
	else if (GearName == "Third Eye") {
		Type = "Trait Reward";
		Description = "See the next 2 cards to be drawn.";
	}
	else if (GearName == "Warper") {
		Type = "Trait Reward";
		Description = "You can travel downwards up to 5 times.";
	}
	else if (GearName == "Growth Spurt") {
		Type = "Trait Reward";
		Description = "Chance to gain +1 in a random stat after battle.";
	}
	else if (GearName == "Mind") {
		Type = "Trait Reward";
		Description = "+(Skl) max mana.";
	}
	else if (GearName == "Matter") {
		Type = "Trait Reward";
		Description = "+2x(Skl) max hp.";
	}
	else if (GearName == "Sharp Claws") {
		Type = "Trait Reward";
		Description = "Deal 1d(Skl) extra damage every attack.";
	}
	else if (GearName == "Gift") {
		Type = "Trait Reward";
		Description = "Choose a spell to add to your deck.";
	}
	else if (GearName == "Unseen") {
		Type = "Trait Reward";
		Description = "Extra turn at the start of battle.";
	}
	else if (GearName == "Spiny Skin") {
		Type = "Trait Reward";
		Description = "Deal (Skl)+3 damage when attacked.";
	}
	else if (GearName == "Adapt") {
		Type = "Trait Reward";
		Description = "Remove 1 negative trait. +1 Skl.";
	}
	else if (GearName == "Wings") {
		Type = "Trait Reward";
		Description = "Leave non-Final Boss combat at any time.";
	}
	else if (GearName == "Exoskeleton") {
		Type = "Trait Reward";
		Description = "Gain 1d(Skl-1) block every turn.";
	}
	else if (GearName == "Unpredictable") {
		Type = "Trait Reward";
		Description = "Shuffle your hand every turn.";
	}
	else if (GearName == "Ego") {
		Type = "Trait Reward";
		Description = "Choose a boss card.";
	}
	else if (GearName == "The Juice") {
		Type = "Trait Reward";
		Description = "Get +6 and -5 to random stats every turn.";
	}
	else if (GearName == "Quick Thinker") {
		Type = "Trait Reward";
		Description = "10x(Skl)% chance to gain 10 mana each turn.";
	}
	else if (GearName == "Foresight") {
		Type = "Trait Reward";
		Description = "Start your hand with spells.";
	}
	else if (GearName == "Photosynthesis") {
		Type = "Trait Reward";
		Description = "Heal for (Skl) hp when you use a spell.";
	}
	else if (GearName == "Dexterous") {
		Type = "Trait Reward";
		Description = "Deal (Skl) damage when you use a defend.";
	}
	else if (GearName == "Reconstruction") {
		Type = "Trait Reward";
		Description = "If you die, spend 2 Skill to come back to life.";
	}
	else if (GearName == "Laser Vision") {
		Type = "Trait Reward";
		Description = "Add a Laser card to your deck.";
	}
	else if (GearName == "Carnivore") {
		Type = "Trait Reward";
		Description = "Gain 1 max health after every battle.";
	}
	else if (GearName == "Hemoglobin") {
		Type = "Trait Reward";
		Description = "Your heals are increased by 50%.";
	}
	else if (GearName == "Destiny") {
		Type = "Trait Reward";
		Description = "Get 3 Cauldrons. You cannot recieve any more.";
	}
	
	else {
		Type = "";
		Description = "";
	}
}


Gear::~Gear()
{
}

void Gear::GearOnOrOff(bool On, Character &guy, Deck &deck) {
	//Hands
	if (GearName == "No Weapon") {
		Card smack("Smack");
		if (On) {
			deck.addCard(smack);
			deck.addCard(smack);
		}
		else {
			deck.removeCard(smack);
			deck.removeCard(smack);
		}
	}
	else if (GearName == "Crystal Ball") {
		if (On) {
			//nothing
		}
		else {
			//nothing
		}
	}
	else if (GearName == "Shield") {
		Card ram("Ram");
		Card block("Block");
		if (On) {
			deck.addCard(ram);
			deck.addCard(ram);
			deck.addCard(ram);
			deck.addCard(block);
		}
		else {
			deck.removeCard(ram);
			deck.removeCard(ram);
			deck.removeCard(ram);
			deck.removeCard(block);
		}
	}
	else if (GearName == "Long Sword") {
		Card slice("Slice");
		Card crush("Crush");
		if (On) {
			deck.addCard(slice);
			deck.addCard(slice);
			deck.addCard(slice);
			deck.addCard(crush);
		}
		else {
			deck.removeCard(slice);
			deck.removeCard(slice);
			deck.removeCard(slice);
			deck.removeCard(crush);
		}
	}
	else if (GearName == "Falchion") {
		Card slice("Slice");
		Card hack("Hack");
		if (On) {
			deck.addCard(slice);
			deck.addCard(slice);
			deck.addCard(hack);
		}
		else {
			deck.removeCard(slice);
			deck.removeCard(slice);
			deck.removeCard(hack);
		}
	}
	else if (GearName == "Metal Staff") {
		Card parry("Parry");
		if (On) {
			deck.addCard(parry);
		}
		else {
			deck.removeCard(parry);
		}
	}
	else if (GearName == "Steel Spear") {
		Card pierce("Pierce");
		if (On) {
			deck.addCard(pierce);
			deck.addCard(pierce);
			deck.addCard(pierce);
		}
		else {
			deck.removeCard(pierce);
			deck.removeCard(pierce);
			deck.removeCard(pierce);
		}
	}
	else if (GearName == "Javelin") {
		Card pierce("Pierce");
		Card slice("Slice");
		Card throww("Throw");
		if (On) {
			deck.addCard(pierce);
			deck.addCard(pierce);
			deck.addCard(slice);
			deck.addCard(slice);
			deck.addCard(throww);
			deck.addCard(throww);
		}
		else {
			deck.removeCard(pierce);
			deck.removeCard(pierce);
			deck.removeCard(slice);
			deck.removeCard(slice);
			deck.removeCard(throww);
			deck.removeCard(throww);
		}
	}
	else if (GearName == "Obsidian Spear") {
		Card pierce("Pierce");
		Card impale("Impale");
		if (On) {
			deck.addCard(pierce);
			deck.addCard(pierce);
			deck.addCard(impale);
		}
		else {
			deck.removeCard(pierce);
			deck.removeCard(pierce);
			deck.removeCard(impale);
		}
	}
	else if (GearName == "Halberd") {
		Card charge("Charge");
		Card hack("Hack");
		Card pierce("Pierce");
		Card slice("Slice");
		Card parry("Parry");
		if (On) {
			deck.addCard(charge);
			deck.addCard(hack);
			deck.addCard(pierce);
			deck.addCard(slice);
			deck.addCard(slice);
			deck.addCard(parry);
		}
		else {
			deck.removeCard(charge);
			deck.removeCard(hack);
			deck.removeCard(pierce);
			deck.removeCard(slice);
			deck.removeCard(slice);
			deck.removeCard(parry);
		}
	}
	else if (GearName == "Lance") {
		Card charge("Charge");
		Card impale("Impale");
		if (On) {
			deck.addCard(charge);
			deck.addCard(charge);
			deck.addCard(impale);
		}
		else {
			deck.removeCard(charge);
			deck.removeCard(charge);
			deck.removeCard(impale);
		}
	}
	else if (GearName == "Rapier") {
		Card feint("Feint");
		Card parry("Parry");
		Card slice("Slice");
		Card pierce("Pierce");
		if (On) {
			deck.addCard(slice);
			deck.addCard(slice);
			deck.addCard(pierce);
			deck.addCard(parry);
			deck.addCard(feint);
		}
		else {
			deck.removeCard(slice);
			deck.removeCard(slice);
			deck.removeCard(pierce);
			deck.removeCard(parry);
			deck.removeCard(feint);
		}
	}
	else if (GearName == "War Hammer") {
		Card crush("Crush");
		Card demolish("Demolish");
		if (On) {
			deck.addCard(crush);
			deck.addCard(crush);
			deck.addCard(demolish);
		}
		else {
			deck.removeCard(crush);
			deck.removeCard(crush);
			deck.removeCard(demolish);
		}
	}
	else if (GearName == "Morning Star") {
		Card crush("Crush");
		Card pierce("Pierce");
		Card demolish("Demolish");
		if (On) {
			deck.addCard(crush);
			deck.addCard(crush);
			deck.addCard(pierce);
			deck.addCard(pierce);
			deck.addCard(demolish);
		}
		else {
			deck.removeCard(crush);
			deck.removeCard(crush);
			deck.removeCard(pierce);
			deck.removeCard(pierce);
			deck.removeCard(demolish);
		}
	}
	else if (GearName == "Battle Axe") {
		Card hack("Hack");
		Card crush("Crush");
		Card bleed("Bleed");
		if (On) {
			deck.addCard(hack);
			deck.addCard(hack);
			deck.addCard(hack);
			deck.addCard(crush);
			deck.addCard(bleed);
		}
		else {
			deck.removeCard(hack);
			deck.removeCard(hack);
			deck.removeCard(hack);
			deck.removeCard(crush);
			deck.removeCard(bleed);
		}
	}
	else if (GearName == "Double Axe") {
		Card charge("Charge");
		Card hack("Hack");
		Card demolish("Demolish");
		if (On) {
			deck.addCard(charge);
			deck.addCard(hack);
			deck.addCard(hack);
			deck.addCard(demolish);
		}
		else {
			deck.removeCard(charge);
			deck.removeCard(hack);
			deck.removeCard(hack);
			deck.removeCard(demolish);
		}
	}
	else if (GearName == "Shiv") {
		Card stab("Stab");
		Card pierce("Pierce");
		if (On) {
			deck.addCard(stab);
			deck.addCard(pierce);
		}
		else {
			deck.removeCard(stab);
			deck.removeCard(pierce);
		}
	}
	else if (GearName == "Serrated Dagger") {
		Card bleed("Bleed");
		Card slice("Slice");
		Card stab("Stab");
		if (On) {
			deck.addCard(bleed);
			deck.addCard(bleed);
			deck.addCard(slice);
			deck.addCard(stab);
		}
		else {
			deck.removeCard(bleed);
			deck.removeCard(bleed);
			deck.removeCard(slice);
			deck.removeCard(stab);
		}
	}
	else if (GearName == "Simple Bow") {
		Card shoot("Shoot");
		Card slice("Slice");
		Card pierce("Pierce");
		if (On) {
			deck.addCard(shoot);
			deck.addCard(shoot);
			deck.addCard(slice);
			deck.addCard(slice);
			deck.addCard(pierce);
		}
		else {
			deck.removeCard(shoot);
			deck.removeCard(shoot);
			deck.removeCard(slice);
			deck.removeCard(slice);
			deck.removeCard(pierce);
		}
	}
	else if (GearName == "Recurve Bow") {
		Card shoot("Shoot");
		if (On) {
			deck.addCard(shoot);
			deck.addCard(shoot);
			deck.addCard(shoot);
		}
		else {
			deck.removeCard(shoot);
			deck.removeCard(shoot);
			deck.removeCard(shoot);
		}
	}
	else if (GearName == "Throwing Stars") {
		Card throww("Throw");
		Card bleed("Bleed");
		if (On) {
			deck.addCard(throww);
			deck.addCard(throww);
			deck.addCard(bleed);
		}
		else {
			deck.removeCard(throww);
			deck.removeCard(throww);
			deck.removeCard(bleed);
		}
	}
	else if (GearName == "Wand") {
		Card zap("Zap");
		Card stab("Stab");
		if (On) {
			deck.addCard(zap);
			deck.addCard(zap);
			deck.addCard(stab);
		}
		else {
			deck.removeCard(zap);
			deck.removeCard(zap);
			deck.removeCard(stab);
		}
	}
	else if (GearName == "Sickle") {
		Card bleed("Bleed");
		Card hack("Hack");
		Card parry("Parry");
		Card pierce("Pierce");
		Card impale("Impale");
		if (On) {
			deck.addCard(bleed);
			deck.addCard(hack);
			deck.addCard(parry);
			deck.addCard(pierce);
			deck.addCard(impale);
		}
		else {
			deck.removeCard(bleed);
			deck.removeCard(hack);
			deck.removeCard(parry);
			deck.removeCard(pierce);
			deck.removeCard(impale);
		}
	}
	else if (GearName == "Hand Cannon") {
		Card shoot("Shoot");
		Card demolish("Demolish");
		if (On) {
			deck.addCard(shoot);
			deck.addCard(shoot);
			deck.addCard(demolish);
		}
		else {
			deck.removeCard(shoot);
			deck.removeCard(shoot);
			deck.removeCard(demolish);
		}
	}
	else if (GearName == "Conductive Gloves") {
		Card msmack("Magic Smack");
		if (On) {
			deck.addCard(msmack);
			deck.addCard(msmack);
		}
		else {
			deck.removeCard(msmack);
			deck.removeCard(msmack);
		}
	}
	else if (GearName == "Sabre") {
		Card slash("Slash");
		if (On) {
			deck.addCard(slash);
		}
		else {
			deck.removeCard(slash);
		}
	}
	else if (GearName == "Whip") {
		Card flay("Flay");
		Card slice("Slice");
		Card lash("Lash");
		if (On) {
			deck.addCard(slice);
			deck.addCard(flay);
			deck.addCard(lash);
		}
		else {
			deck.removeCard(slice);
			deck.removeCard(flay);
			deck.removeCard(lash);
		}
	}
	else if (GearName == "Twin Flail") {
		Card flay("Flay");
		Card demolish("Demolish");
		Card lash("Lash");
		if (On) {
			deck.addCard(flay);
			deck.addCard(lash);
			deck.addCard(lash);
			deck.addCard(demolish);
		}
		else {
			deck.removeCard(flay);
			deck.removeCard(lash);
			deck.removeCard(lash);
			deck.removeCard(demolish);
		}
	}
	else if (GearName == "Leather Gauntlets") {
		Card pummel("Pummel");
		//Card smack("Smack");
		if (On) {
			deck.addCard(pummel);
		}
		else {
			deck.removeCard(pummel);
		}
	}
	else if (GearName == "Steel Gauntlets") {
		Card pummel("Pummel");
		Card crush("Crush");
		if (On) {
			deck.addCard(pummel);
			deck.addCard(crush);
		}
		else {
			deck.removeCard(pummel);
			deck.removeCard(crush);
		}
	}
	else if (GearName == "Spiked Gauntlets") {
		Card pummel("Pummel");
		Card bleed("Bleed");
		if (On) {
			deck.addCard(pummel);
			deck.addCard(bleed);
		}
		else {
			deck.removeCard(pummel);
			deck.removeCard(bleed);
		}
	}
	else if (GearName == "Arbalest") {
		Card shoot("Shoot");
		Card impale("Impale");
		if (On) {
			deck.addCard(shoot);
			deck.addCard(shoot);
			deck.addCard(impale);
		}
		else {
			deck.removeCard(shoot);
			deck.removeCard(shoot);
			deck.removeCard(impale);
		}
	}
	else if (GearName == "Dirk") {
		Card stab("Stab");
		Card slice("Slice");
		Card feint("Feint");
		if (On) {
			deck.addCard(stab);
			deck.addCard(slice);
			deck.addCard(feint);
		}
		else {
			deck.removeCard(stab);
			deck.removeCard(slice);
			deck.removeCard(feint);
		}
	}
	else if (GearName == "Cutlass") {
		Card slash("Slash");
		Card feint("Feint");
		if (On) {
			deck.addCard(slash);
			deck.addCard(feint);
		}
		else {
			deck.removeCard(slash);
			deck.removeCard(feint);
		}
	}

	//Body
	else if (GearName == "No Armor") {
		Card endure("Endure");
		if (On) {
			deck.addCard(endure);
			deck.addCard(endure);
		}
		else {
			deck.removeCard(endure);
			deck.removeCard(endure);
		}
	}
	else if (GearName == "Mage Armor") {
		Card forcefield("Force Field");
		if (On) {
			deck.addCard(forcefield);
			deck.addCard(forcefield);
			deck.addCard(forcefield);
		}
		else {
			deck.removeCard(forcefield);
			deck.removeCard(forcefield);
			deck.removeCard(forcefield);
		}
	}
	else if (GearName == "Glitter Robes") {
		Card absorb("Absorb");
		Card predict("Predict");
		if (On) {
			deck.addCard(predict);
			deck.addCard(predict);
			deck.addCard(absorb);
		}
		else {
			deck.removeCard(predict);
			deck.removeCard(predict);
			deck.removeCard(absorb);
		}
	}
	else if (GearName == "Riveted Chainmail") {
		Card counter("Counter");
		Card dash("Dash");
		Card reinforce("Reinforce");
		if (On) {
			deck.addCard(counter);
			deck.addCard(dash);
			deck.addCard(reinforce);
		}
		else {
			deck.removeCard(counter);
			deck.removeCard(dash);
			deck.removeCard(reinforce);
		}
	}
	else if (GearName == "Reinforced Mail") {
		Card brace("Brace");
		Card obstruct("Obstruct");
		if (On) {
			deck.addCard(brace);
			deck.addCard(obstruct);
		}
		else {
			deck.removeCard(brace);
			deck.removeCard(obstruct);
		}
	}
	else if (GearName == "Full Plate Armor") {
		Card reinforce("Reinforce");
		Card obstruct("Obstruct");
		Card endure("Endure");
		if (On) {
			deck.addCard(reinforce);
			deck.addCard(obstruct);
			deck.addCard(endure);
			deck.addCard(endure);
		}
		else {
			deck.removeCard(reinforce);
			deck.removeCard(obstruct);
			deck.removeCard(endure);
			deck.removeCard(endure);
		}
	}
	else if (GearName == "Cape") {
		Card dodge("Dodge");
		if (On) {
			deck.addCard(dodge);
		}
		else {
			deck.removeCard(dodge);
		}
	}
	else if (GearName == "Feathered Cloak") {
		Card dash("Dash");
		Card flee("Flee");
		Card disrupt("Disrupt");
		if (On) {
			deck.addCard(dash);
			deck.addCard(flee);
			deck.addCard(disrupt);
		}
		else {
			deck.removeCard(dash);
			deck.removeCard(flee);
			deck.removeCard(disrupt);
		}
	}
	else if (GearName == "Leather Hauberk") {
		Card counter("Counter");
		Card brace("Brace");
		Card predict("Predict");
		if (On) {
			deck.addCard(counter);
			deck.addCard(brace);
			deck.addCard(predict);
		}
		else {
			deck.removeCard(counter);
			deck.removeCard(brace);
			deck.removeCard(predict);
		}
	}
	else if (GearName == "Twilight Robes") {
		Card dash("Dash");
		Card dodge("Dodge");
		Card flee("Flee");
		if (On) {
			deck.addCard(dash);
			deck.addCard(dodge);
			deck.addCard(dodge);
			deck.addCard(flee);
		}
		else {
			deck.removeCard(dash);
			deck.removeCard(dodge);
			deck.removeCard(dodge);
			deck.removeCard(flee);
		}
	}
	else if (GearName == "Dragon Scales") {
		Card spikes("Spikes");
		Card counter("Counter");
		Card predict("Predict");
		if (On) {
			deck.addCard(spikes);
			deck.addCard(spikes);
			deck.addCard(counter);
			deck.addCard(predict);
		}
		else {
			deck.removeCard(spikes);
			deck.removeCard(spikes);
			deck.removeCard(counter);
			deck.removeCard(predict);
		}
	}
	else if (GearName == "Spiked Mail") {
		Card spikes("Spikes");
		Card counter("Counter");
		if (On) {
			deck.addCard(spikes);
			deck.addCard(spikes);
			deck.addCard(spikes);
			deck.addCard(counter);
		}
		else {
			deck.removeCard(spikes);
			deck.removeCard(spikes);
			deck.removeCard(spikes);
			deck.removeCard(counter);
		}
	}
	else if (GearName == "Buffalo Hide") {
		Card counter("Counter");
		if (On) {
			deck.addCard(counter);
			deck.addCard(counter);
		}
		else {
			deck.removeCard(counter);
			deck.removeCard(counter);
		}
	}
	else if (GearName == "Steel Breastplate") {
		Card endure("Endure");
		Card obstruct("Obstruct");
		if (On) {
			deck.addCard(endure);
			deck.addCard(endure);
			deck.addCard(obstruct);
		}
		else {
			deck.removeCard(endure);
			deck.removeCard(endure);
			deck.removeCard(obstruct);
		}
	}
	else if (GearName == "Amulet of Aura") {
		Card forcefield("Force Field");
		Card absorb("Absorb");
		Card predict("Predict");
		Card repulse("Repulse");
		if (On) {
			deck.addCard(forcefield);
			deck.addCard(absorb);
			deck.addCard(predict);
			deck.addCard(repulse);
		}
		else {
			deck.removeCard(forcefield);
			deck.removeCard(absorb);
			deck.removeCard(predict);
			deck.removeCard(repulse);
		}
	}
	else if (GearName == "Turtle Shell") {
		Card block("Block");
		Card brace("Brace");
		if (On) {
			deck.addCard(block);
			deck.addCard(brace);
		}
		else {
			deck.removeCard(block);
			deck.removeCard(block);
			deck.removeCard(brace);
		}
	}
	else if (GearName == "Crystal Breastplate") {
		Card absorb("Absorb");
		Card obstruct("Obstruct");
		Card repulse("Repulse");
		if (On) {
			deck.addCard(absorb);
			deck.addCard(absorb);
			deck.addCard(obstruct);
			deck.addCard(obstruct);
			deck.addCard(repulse);
		}
		else {
			deck.removeCard(absorb);
			deck.removeCard(absorb);
			deck.removeCard(obstruct);
			deck.removeCard(obstruct);
			deck.removeCard(repulse);
		}
	}

	//Head
	else if (GearName == "No Headgear") {
		Card channel("Channel");
		Card meditate("Meditate");
		Card blast("Blast");
		if (On) {
			deck.addCard(channel);
			deck.addCard(blast);
		}
		else {
			deck.removeCard(channel);
			deck.removeCard(blast);
		}
	}
	else if (GearName == "Brown Hat") {
		if (On) {
			//nothing
		}
		else {
			//nothing
		}
	}
	else if (GearName == "Vampire Fangs") {
		Card leech("Leech");
		Card regen("Regenerate");
		Card transmute("Transmute");
		if (On) {
			deck.addCard(leech);
			deck.addCard(regen);
			deck.addCard(transmute);
		}
		else {
			deck.removeCard(leech);
			deck.removeCard(regen);
			deck.removeCard(transmute);
		}
	}
	else if (GearName == "Warp Goggles") {
		Card blink("Blink");
		Card push("Push");
		Card hole("Singularity");
		if (On) {
			deck.addCard(blink);
			deck.addCard(push);
			deck.addCard(hole);
		}
		else {

			deck.removeCard(blink);
			deck.removeCard(push);
			deck.removeCard(hole);
		}
	}
	else if (GearName == "Tundra Cap") {
		Card freeze("Freeze");
		Card shatter("Shatter");
		Card melt("Melt");
		if (On) {
			deck.addCard(freeze);
			deck.addCard(freeze);
			deck.addCard(freeze);
			deck.addCard(shatter);
			deck.addCard(melt);
		}
		else {
			deck.removeCard(freeze);
			deck.removeCard(freeze);
			deck.removeCard(freeze);
			deck.removeCard(shatter);
			deck.removeCard(melt);
		}
	}
	else if (GearName == "Plague Mask") {
		Card fumes("Fumes");
		Card incense("Incense");
		Card smoke("Smoke");
		if (On) {
			deck.addCard(fumes);
			deck.addCard(incense);
			deck.addCard(smoke);
		}
		else {
			deck.removeCard(fumes);
			deck.removeCard(incense);
			deck.removeCard(smoke);
		}
	}
	else if (GearName == "Dragonskin Hood") {
		Card fireball("Fireball");
		//Card conflagrate("Conflagrate");
		Card fuel("Fuel");
		if (On) {
			deck.addCard(fireball);
			deck.addCard(fireball);
			deck.addCard(fuel);
		}
		else {
			deck.removeCard(fireball);
			deck.removeCard(fireball);
			deck.removeCard(fuel);
		}
	}
	else if (GearName == "Shifting Veil") {
		Card mirror("Mirror");
		Card copy("Copy");
		Card confuse("Confuse");
		if (On) {
			deck.addCard(mirror);
			deck.addCard(copy);
			deck.addCard(confuse);
		}
		else {
			deck.removeCard(mirror);
			deck.removeCard(copy);
			deck.removeCard(confuse);
		}
	}
	else if (GearName == "Copper Cage") {
		Card lightning("Lightning");
		Card thunder("Thunder");
		Card charge("Overcharge");
		if (On) {
			deck.addCard(lightning);
			deck.addCard(thunder);
			deck.addCard(charge);
			deck.addCard(charge);
		}
		else {
			deck.removeCard(lightning);
			deck.removeCard(thunder);
			deck.removeCard(charge);
			deck.removeCard(charge);
		}
	}
	else if (GearName == "Bedstone Helmet") {
		Card destroy("Destroy");
		Card construct("Construct");
		Card deconstruct("Deconstruct");
		if (On) {
			deck.addCard(destroy);
			deck.addCard(construct);
			deck.addCard(deconstruct);
		}
		else {
			deck.removeCard(destroy);
			deck.removeCard(construct);
			deck.removeCard(deconstruct);
		}
	}
	
	guy.printStats();
}

void Gear::TraitOnOrOff(bool On, Character &guy, Deck &deck) {
	//Trait Sacrifice
	if (GearName == "Anemia") {
	if (On) {
		guy.Anemia = TRUE;
	}
	else {
		guy.Anemia = FALSE;
	}
	}
	else if (GearName == "Dumb") {
	if (On) {
		guy.ModStat(-4, "Intelligence");
		guy.ModStat(1, "Defense");
	}
	else {
		guy.ModStat(4, "Intelligence");
		guy.ModStat(-1, "Defense");
	}
	}
	else if (GearName == "Mind Flooded") {
	Card ponder("Ponder");
	if (On) {
		deck.addCard(ponder);
	}
	else {
		deck.removeCard(ponder);
	}
	}
	else if (GearName == "Tunnel Vision") {
	if (On) {
		guy.ModStat(-2, "Strength");
		guy.ModStat(-2, "Defense");
		guy.ModStat(1, "Skill");
	}
	else {
		guy.ModStat(2, "Strength");
		guy.ModStat(2, "Defense");
		guy.ModStat(-1, "Skill");
	}
	}
	else if (GearName == "Teleportitis") {
	if (On) {
		guy.Teleportitis = TRUE;
	}
	else {
		guy.Teleportitis = FALSE;
	}
	}
	else if (GearName == "Growing Pains") {
	if (On) {
		guy.Growing_Pains = TRUE;
	}
	else {
		guy.Growing_Pains = FALSE;
	}
	}
	else if (GearName == "Conversion") {
	if (On) {
		guy.Conversion = TRUE;
	}
	else {
		guy.Conversion = FALSE;
	}
		}
	else if (GearName == "Inversion") {
	if (On) {
		guy.Inversion = TRUE;
	}
	else {
		guy.Inversion = FALSE;
	}
	}
	else if (GearName == "Jittery") {
	if (On) {
		guy.Jittery = 0;
	}
	else {
		guy.Jittery = -1;
	}
	}
	else if (GearName == "Tumors") {
	if (On) {
		guy.Tumors = TRUE;
	}
	else {
		guy.Tumors = FALSE;
	}
	}
	else if (GearName == "Devolve") {
	if (On) {
		guy.Devolve = TRUE;
	}
	else {
		guy.Devolve = FALSE;
	}
	}
	else if (GearName == "Volatile") {
	if (On) {
		guy.Volatile = 0;
	}
	else {
		guy.Volatile = -1;
	}
	}
	else if (GearName == "Melting") {
	if (On) {
		guy.Melting = TRUE;
	}
	else {
		guy.Melting = FALSE;
	}
	}
	else if (GearName == "The Box") {
	if (On) {
		int statpool = 0;
		int tempstat = guy.MaxHealthBase;
		for (int i = 1; i < tempstat; i++) {
			guy.MaxHealthBase--;
			guy.MaxHealth--;
			statpool++;
		}
		tempstat = guy.MaxManaBase;
		for (int i = 0; i < tempstat; i++) {
			guy.MaxMana--;
			guy.MaxManaBase--;
			statpool++;
		}
		tempstat = guy.Strength;
		for (int i = 1; i < tempstat; i++) {
			guy.Strength--;
			statpool++;
		}
		tempstat = guy.Defense;
		for (int i = 0; i < tempstat; i++) {
			guy.Defense--;
			statpool++;
		}
		tempstat = guy.Intelligence;
		for (int i = 0; i < tempstat; i++) {
			guy.Intelligence--;
			statpool++;
		}
		tempstat = guy.Skill;
		for (int i = 0; i < tempstat; i++) {
			guy.Skill--;
			statpool++;
		}

		while (statpool > 0) {
			int amount = (rand() % statpool + 1) / 2;
			if (statpool == 1)
				amount = 1;
			statpool -= amount;
			int stat = rand() % 6;
			switch (stat) {
			case 0:
				guy.MaxHealthBase += amount;
				guy.MaxHealth += amount;
				break;
			case 1:
				guy.MaxManaBase += amount;
				guy.MaxMana += amount;
				break;
			case 5:
				guy.Strength += amount;
				break;
			case 2:
				guy.Defense += amount;
				break;
			case 3:
				guy.Intelligence += amount;
				break;
			case 4:
				guy.Skill += amount;
				break;
			}
			guy.CurrentHealth = guy.MaxHealth;
			guy.CurrentMana = guy.MaxMana;
			guy.printStats();
		}
	}
	else {
	}
	}
	else if (GearName == "Amnesia") {
	if (On) {
		for (int x = 1; x < 27; x++) {
			for (int y = 6; y < 14; y++) {
				if (rand() % 2 == 0)
					if (x != guy.posx && y != guy.posy)
						mvprintw(y, x, " ");
			}
		}
	}
	else {

	}
	}
	else if (GearName == "Long Legs") {
	if (On) {
		guy.Long_Legs += 3;
	}
	else {
		guy.Long_Legs = 0;
	}
	}
	else if (GearName == "Oblivious") {
	if (On) {
		for (int y = 0; y < 15; y++) {
			mvprintw(y, 44, "                                  ");
		}
		guy.Oblivious = TRUE;
	}
	else {
		guy.Oblivious = FALSE;
	}
	}
	else if (GearName == "Blind") {
	if (On) {
		guy.Blind = TRUE;
	}
	else {
		guy.Blind = FALSE;
	}
	}
	else if (GearName == "Numb") {
	if (On) {
		for (int y = 0; y < 5; y++) {
			mvprintw(y, 17, "                          ");
		}
		guy.Numb = TRUE;
	}
	else {
		guy.Numb = FALSE;
	}
	}
	else if (GearName == "Sensitive") {
	if (On) {
		guy.Fast_Metabolism = TRUE;
	}
	else {
		guy.Fast_Metabolism = FALSE;
	}
	}
	else if (GearName == "Frenzy") {
	if (On) {
		guy.Deadly = TRUE;
	}
	else {
		guy.Deadly = FALSE;
	}
	}
	else if (GearName == "Corpse") {
	if (On) {
		guy.ModStat(5, "MaxHealth");
		guy.CurrentHealth = guy.MaxHealth;
		guy.Undead = TRUE;
	}
	else {
		guy.ModStat(-5, "MaxHealth");
		guy.CurrentHealth = guy.MaxHealth;
		guy.Undead = FALSE;
	}
	}
	else if (GearName == "Radioactive") {
	if (On) {
		guy.Radioactive = TRUE;
	}
	else {
		guy.Radioactive = FALSE;
	}
	}
	else if (GearName == "Forgetful") {
	if (On) {
		guy.ModStat(2, "MaxMana");
		guy.Forgetful = TRUE;
	}
	else {
		guy.ModStat(-2, "MaxMana");
		guy.Forgetful = FALSE;
	}
	}

	else if (GearName == "Tiny") {
	if (On) {
		guy.ModStat(-39, "MaxHealth");
		guy.ModStat(10, "Defense");
		guy.CurrentHealth = guy.MaxHealth;
	}
	else {
		guy.ModStat(39, "MaxHealth");
		guy.ModStat(-8, "Defense");
		guy.CurrentHealth = guy.MaxHealth;
	}
	}
	else if (GearName == "Succumb") {
	if (On) {
		guy.ModStat(2, "Skill");
		guy.Succumb = TRUE;
		Succumb = TRUE;
	}
	else {
		guy.ModStat(-2, "Skill");
		guy.Succumb = FALSE;
		Succumb = FALSE;
	}
	}

	//Trait Reward
	else if (GearName == "Mending Flesh") {
	if (On) {
		guy.Mending_Flesh = TRUE;
	}
	else {
		guy.Mending_Flesh = FALSE;
	}
	}
	else if (GearName == "Gymnast") {
	if (On) {
		guy.Gymnast = TRUE;
	}
	else {
		guy.Gymnast = FALSE;
	}
	}
	else if (GearName == "Third Eye") {
	if (On) {
		guy.Third_Eye = TRUE;
	}
	else {
		guy.Third_Eye = FALSE;
	}
	}
	else if (GearName == "Warper") {
	if (On) {
		guy.Warper += 5;
	}
	else {
		guy.Warper = 0;
	}
	}
	else if (GearName == "Growth Spurt") {
	if (On) {
		guy.Growth_Spurt = TRUE;
	}
	else {
		guy.Growth_Spurt = FALSE;
	}
	}
	else if (GearName == "Mind") {
	if (On) {
		guy.Mind = TRUE;
	}
	else {
		guy.Mind = FALSE;
	}
	}
	else if (GearName == "Matter") {
	if (On) {
		guy.Matter = TRUE;
	}
	else {
		guy.Matter = FALSE;
	}
	}
	else if (GearName == "Sharp Claws") {
	if (On) {
		guy.Sharp_Claws = TRUE;
	}
	else {
		guy.Sharp_Claws = FALSE;
	}
	}
	else if (GearName == "Gift") {
	if (On) {
		guy.Gift = TRUE;
	}
	else {
		guy.Gift = FALSE;
	}
	}
	else if (GearName == "Unseen") {
	if (On) {
		guy.Unseen = TRUE;
	}
	else {
		guy.Unseen = FALSE;
	}
	}
	else if (GearName == "Spiny Skin") {
	if (On) {
		guy.Spiny_Skin = TRUE;
	}
	else {
		guy.Spiny_Skin = FALSE;
	}
	}
	else if (GearName == "Adapt") {
	if (On) {
		guy.Adapt = TRUE;
	}
	else {
		guy.Adapt = FALSE;
	}
	}
	else if (GearName == "Wings") {
	if (On) {
		guy.Wings = TRUE;
	}
	else {
		guy.Wings = FALSE;
	}
	}
	else if (GearName == "Exoskeleton") {
	if (On) {
		guy.Exoskeleton = TRUE;
	}
	else {
		guy.Exoskeleton = FALSE;
	}
	}
	else if (GearName == "Unpredictable") {
	if (On) {
		guy.Dizzy = TRUE;
	}
	else {
		guy.Dizzy = FALSE;
	}
	}
	else if (GearName == "Ego") {
	if (On) {
		guy.Crown = TRUE;
	}
	else {
		guy.Crown = FALSE;
	}
	}
	else if (GearName == "The Juice") {
	if (On) {
		guy.The_Juice = TRUE;
	}
	else {
		guy.The_Juice = FALSE;
	}
	}
	else if (GearName == "Quick Thinker") {
	if (On) {
		guy.Quick_Thinker = TRUE;
	}
	else {
		guy.Quick_Thinker = FALSE;
	}
	}
	else if (GearName == "Foresight") {
	if (On) {
		guy.Foresight = 1;
	}
	else {
		guy.Foresight = 1;
	}
	}
	else if (GearName == "Photosynthesis") {
	if (On) {
		guy.Photosynthesis = TRUE;
	}
	else {
		guy.Photosynthesis = FALSE;
	}
	}
	else if (GearName == "Dexterous") {
	if (On) {
		guy.Dexterous = TRUE;
	}
	else {
		guy.Dexterous = FALSE;
	}
	}
	else if (GearName == "Reconstruction") {
	if (On) {
		guy.Reconstruction = TRUE;
	}
	else {
		guy.Reconstruction = FALSE;
	}
	}
	else if (GearName == "Laser Vision") {
	Card laser("Laser");
	if (On) {
		deck.addCard(laser);
	}
	else {
		deck.removeCard(laser);
	}
	}
	else if (GearName == "Carnivore") {
	if (On) {
		guy.Carnivore = TRUE;
	}
	else {
		guy.Carnivore = FALSE;
	}
	}
	else if (GearName == "Hemoglobin") {
	if (On) {
		guy.Hemoglobin = TRUE;
	}
	else {
		guy.Hemoglobin = FALSE;
	}
	}
	else if (GearName == "Destiny") {
	if (On) {
		guy.Destiny = 5;
	}
	else {
		guy.Destiny = 0;
	}
	}

	guy.printStats();
}

void Gear::CardOnOrOff(bool On, Character &guy, Deck &deck) {
	//Special
	if (GearName == "Revivify") {
	Card s("Revivify");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Steroids") {
	Card s("Steroids");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Change Mind") {
	Card s("Change Mind");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Intimidate") {
	Card s("Intimidate");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Cripple") {
	Card s("Cripple");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Merge") {
	Card s("Merge");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Entomb") {
	Card s("Entomb");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Distract") {
	Card s("Distract");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Prepare") {
	Card s("Prepare");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Grow") {
	Card s("Grow");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Solidify") {
	Card s("Solidify");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Learn") {
	Card s("Learn");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Train") {
	Card s("Train");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Boost") {
	Card s("Boost");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Vitalise") {
	Card s("Vitalise");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Jump") {
	Card s("Jump");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Combo") {
	Card s("Combo");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Slam") {
	Card s("Slam");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}
	else if (GearName == "Stall") {
	Card s("Stall");
	if (On) {
		deck.addCard(s);
	}
	else {
		deck.removeCard(s);
	}
	}

	guy.printStats();
}


void Gear::printGear(int position, Character &guy) {
	WINDOW *gearWindow;

	switch (position) {
	case 1:
		for (int i = 17; i <= 22; i++) {
			mvprintw(i, 2, "                  ");
		}
		if (Type == "Trait Sacrifice" || Type == "Trait Reward")
			mvprintw(17, 2, "1)");
		break;
	case 2:
		for (int i = 17; i <= 22; i++) {
			mvprintw(i, 22, "                  ");
		}
		if (Type == "Trait Sacrifice" || Type == "Trait Reward")
			mvprintw(17, 22, "2)");
		break;
	case 3:
		for (int i = 17; i <= 22; i++) {
			mvprintw(i, 42, "                  ");
		}
		if (Type == "Trait Sacrifice" || Type == "Trait Reward")
			mvprintw(17, 42, "3)");
		break;
	}
	init_pair(10, COLOR_BLUE, COLOR_BLACK);
	init_color(COLOR_BLUE, 200, 400, 1000);
	attron(COLOR_PAIR(10));
	if (Type == "Trait Sacrifice")
		attron(COLOR_PAIR(5));
	else if (Type == "Trait Reward")
		attron(COLOR_PAIR(7));
	int addx = int(strlen(GearName) / 2);
	int gy = 19;
	if (Type == "Trait Sacrifice" || Type == "Trait Reward")
		gy = 17;
	switch (position) {
	case 1:
		manualBox("Card 1", 0);
		mvprintInSize(gy, 12-addx, 15, GearName);
		if (Type == "Trait Sacrifice" || Type == "Trait Reward") {
			//Succumb trait
			if (guy.Succumb) {
				mvprintw(17, 6, "               ");
				for (int x = 6; x < 14; x++) {
					char a = rand() % 9000 + 50;
					if (rand() % 4 > 0)
						mvprintw(17, x, "%c", a);
				}
				for (int y = 19; y < 22; y++) {
					for (int x = 3; x < 18; x++) {
						char a = rand() % 9000 + 50;
						if (rand() % 5 > 0)
							mvprintw(y, x, "%c", a);
					}
				}
			}
			else
				mvprintInSize(19, 4, 15, Description);
		}
		break;
	case 2:
		manualBox("Card 2", 0);
		mvprintInSize(gy, 31-addx, 15, GearName);
		if (Type == "Trait Sacrifice" || Type == "Trait Reward") {
			//Succumb trait
			if (guy.Succumb) {
				mvprintw(17, 26, "               ");
				for (int x = 26; x < 34; x++) {
					char a = rand() % 9000 + 50;
					if (rand() % 4 > 0)
						mvprintw(17, x, "%c", a);
				}
				for (int y = 19; y < 22; y++) {
					for (int x = 24; x < 38; x++) {
						char a = rand() % 9000 + 50;
						if (rand() % 3 > 0)
							mvprintw(y, x, "%c", a);
					}
				}
			}
			else
				mvprintInSize(19, 24, 15, Description);
		}
		attroff(COLOR_PAIR(10));
		if (Type != "Trait Sacrifice" && Type != "Trait Reward")
			mvprintw(22, 22, "(P)ickup   (L)eave");
		break;
	case 3:
		manualBox("Card 3", 0);
		mvprintInSize(gy, 52-addx, 15, GearName);
		if (Type == "Trait Sacrifice" || Type == "Trait Reward") {
			//Succumb trait
			if (guy.Succumb) {
				mvprintw(17, 46, "               ");
				for (int x = 46; x < 54; x++) {
					char a = rand() % 9000 + 50;
					if (rand() % 4 > 0)
						mvprintw(17, x, "%c", a);
				}
				for (int y = 19; y < 22; y++) {
					for (int x = 44; x < 58; x++) {
						char a = rand() % 9000 + 50;
						if (rand() % 3 > 0)
							mvprintw(y, x, "%c", a);
					}
				}
			}
			else
				mvprintInSize(19, 44, 15, Description);
		}
		break;

	}
	standend();
}
