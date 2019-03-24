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
void mvprintInSize(int starty, int startx, int maxx, const char* toBePrinted, bool Fuzzy);
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
	if (GearName == "No Weapon" ||
		GearName == "Crystal Ball" ||
		GearName == "Buckler" ||
		GearName == "Shield" ||
		GearName == "Long Sword" ||
		GearName == "Falchion" ||
		GearName == "Metal Staff" ||
		GearName == "Steel Spear" ||
		GearName == "Javelin" ||
		GearName == "Obsidian Spear" ||
		GearName == "Halberd" ||
		GearName == "Lance" ||
		GearName == "Rapier" ||
		GearName == "War Hammer" ||
		GearName == "Morning Star" ||
		GearName == "Battle Axe" ||
		GearName == "Double Axe" ||
		GearName == "Shiv" ||
		GearName == "Serrated Dagger" ||
		GearName == "Simple Bow" ||
		GearName == "Recurve Bow" ||
		GearName == "Throwing Stars" ||
		GearName == "Wand" ||
		GearName == "Sickle" ||
		GearName == "Hand Cannon" ||
		GearName == "Conductive Gloves" ||
		GearName == "Sabre" ||
		GearName == "Whip" ||
		GearName == "Twin Flail" ||
		GearName == "Leather Gauntlets" ||
		GearName == "Steel Gauntlets" ||
		GearName == "Spiked Gauntlets" ||
		GearName == "Arbalest" ||
		GearName == "Dirk" ||
		GearName == "Cutlass" ||
		GearName == "Greatsword" ||
		GearName == "Athame") {
		Type = "Hands";
		HandsDescription();
	}
	//Body
	else if (GearName == "No Armor" ||
		GearName == "Mage Armor" ||
		GearName == "Glitter Robes" ||
		GearName == "Riveted Chainmail" ||
		GearName == "Reinforced Mail" ||
		GearName == "Full Plate Armor" ||
		GearName == "Cape" ||
		GearName == "Feathered Cloak" ||
		GearName == "Leather Hauberk" ||
		GearName == "Twilight Robes" ||
		GearName == "Dragon Scales" ||
		GearName == "Spiked Mail" ||
		GearName == "Buffalo Hide" ||
		GearName == "Steel Breastplate" ||
		GearName == "Amulet of Aura" ||
		GearName == "Turtle Shell" ||
		GearName == "Crystal Breastplate" ||
		GearName == "Padded Tunic" ||
		GearName == "Chain Mail" ||
		GearName == "Gilded Robes" ||
		GearName == "Wizard Garb" ||
		GearName == "Cloth Shirt" ||
		GearName == "Grass Armor" ||
		GearName == "Flesh Suit" ||
		GearName == "Grey Robes") {
		Type = "Body";
		BodyDescription();
	}
	//Head
	else if (GearName == "No Headgear" ||
		GearName == "Brown Hat" ||
		GearName == "Vampire Fangs" ||
		GearName == "Warp Goggles" ||
		GearName == "Tundra Cap" ||
		GearName == "Plague Mask" ||
		GearName == "Dragonskin Hood" ||
		GearName == "Shifting Veil" ||
		GearName == "Copper Cage" ||
		GearName == "Bedstone Helmet" ||
		GearName == "Glass Eye" ||
		GearName == "Laurel Wreath" ||
		GearName == "Diving Gear" ||
		GearName == "Makeup Set" ||
		GearName == "Safety Glasses" ||
		GearName == "Golden Monocle" ||
		GearName == "Desert Wrappings" ||
		GearName == "Viking Helm" ||
		GearName == "Unholy Cowl" ||
		GearName == "Jewelled Crown" ||
		GearName == "Human Skull" ||
		GearName == "Crystal Earrings" ||
		GearName == "Scary Face" ||
		GearName == "Ear Plugs" ||
		GearName == "White Halo" ||
		GearName == "Bronze Head") {
		Type = "Head";
		HeadDescription();

	}

	//Modifications
	else if (GearName == "Burn" ||
		GearName == "Stay" ||
		GearName == "Flow" ||
		GearName == "Copy" ||
		GearName == "Push" ||
		GearName == "Void" ||
		GearName == "Link") {
		Type = "Mod";
	}
	
	//Trait Sacrifice
	else if (GearName == "Anemia" ||
		GearName == "Dumb" ||
		GearName == "Mind Flooded" ||
		GearName == "Tunnel Vision" ||
		GearName == "Teleportitis" ||
		GearName == "Growing Pains" ||
		GearName == "Conversion" ||
		GearName == "Inversion" ||
		GearName == "Jittery" ||
		GearName == "Tumors" ||
		GearName == "Volatile" ||
		GearName == "Melting" ||
		GearName == "The Box" ||
		GearName == "Amnesia" ||
		GearName == "Long Legs" ||
		GearName == "Oblivious" ||
		GearName == "Blind" ||
		GearName == "Numb" ||
		GearName == "Sensitive" ||
		GearName == "Frenzy" ||
		GearName == "Corpse" ||
		GearName == "Radioactive" ||
		GearName == "Forgetful" ||
		GearName == "Tiny" ||
		GearName == "Succumb" ||
		GearName == "Slow" ||
		GearName == "Sticky Feet" ||
		GearName == "Hallucinations" ||
		GearName == "Tail" ||
		GearName == "Weak Back" ||
		GearName == "Charred Skin" ||
		GearName == "Purple" ||
		GearName == "Madness" ||
		GearName == "Inefficient" ||
		GearName == "Brain Worm" ||
		GearName == "Gold Flesh" ||
		GearName == "Terraform" ||
		GearName == "Psychosis" ||
		GearName == "Dazed" ||
		GearName == "Strategy" ||
		GearName == "Doomed" ||
		GearName == "Eruption" ||
		GearName == "Flash Freeze" ||
		GearName == "Scented" ||
		GearName == "Colossus" ||
		GearName == "Timer" ||
		GearName == "Sacrificial" ||
		GearName == "Membrane" ||
		GearName == "Addiction" ||
		GearName == "Paranoia" ||
		GearName == "Sticky Skin" ||
		GearName == "Asthma" ||
		GearName == "Flat Feet" ||
		GearName == "Muscle Mass" ||
		GearName == "Chaos#" ||
		GearName == "Panic Attack" ||
		GearName == "Cursed" ||
		GearName == "Joint Pain" ||
		GearName == "Daredevil" ||
		GearName == "Careless" ||
		GearName == "Hoarder" ||
		GearName == "Atrophy" ||
		GearName == "Burnout" ||
		GearName == "Blackout" ||
		GearName == "Combo Breaker" ||
		GearName == "Memory Lapse" ||
		GearName == "Stiff" ||
		GearName == "Ethereal" ||
		GearName == "Overconfidence" ||
		GearName == "Falter" ||
		GearName == "Exposed" ||
		GearName == "Circus" ||
		GearName == "Spiritual" ||
		GearName == "Stuck" ||
		GearName == "Inert" ||
		GearName == "Lightweight" ||
		GearName == "Headache" ||
		GearName == "Reckless" ||
		GearName == "Wasteful" ||
		GearName == "Strain" ||
		GearName == "Materialist" ||
		GearName == "Run" ||
		GearName == "Heavy" ||
		GearName == "Commitment" ||
		GearName == "Wind Down" ||
		GearName == "Short Circuit" ||
		GearName == "Empty" ||
		GearName == "Unsteady" ||
		GearName == "Sore" ||
		GearName == "Earthquake") {
		Type = "Trait Sacrifice";
		TraitSDescription();
	}
	
	
	//Trait Reward
	else if (GearName == "Mending Flesh" ||
	GearName == "Gymnast" ||
	GearName == "Third Eye" || //not in pool
	GearName == "Warper" ||
	GearName == "Growth Spurt" ||
	GearName == "Mind" ||
	GearName == "Matter" ||
	GearName == "Sharp Claws" ||
	GearName == "Unseen" ||
	GearName == "Spiny Skin" ||
	GearName == "Wings" ||
	GearName == "Exoskeleton" ||
	GearName == "Unpredictable" ||
	GearName == "Ego" ||
	GearName == "The Box#" ||
	GearName == "Quick Thinker" ||
	GearName == "Foresight" ||
	GearName == "Photosynthesis" ||
	GearName == "Dexterous" ||
	GearName == "Reconstruction" ||
	GearName == "Laser Vision" ||
	GearName == "Carnivore" ||
	GearName == "Hemoglobin" ||
	GearName == "Destiny" ||
	GearName == "Scavenger" ||
	GearName == "Horns" ||
	GearName == "Genius" ||
	GearName == "Green Scales" ||
	GearName == "Multi-Tongued" ||
	GearName == "Triple-Jointed" ||
	GearName == "Blacksmith" ||
	GearName == "Iron Scabs" ||
	GearName == "Gelatinous" ||
	GearName == "Evolve" ||
	GearName == "Eight Legs" ||
	GearName == "Refine" ||
	GearName == "Relentless" ||
	GearName == "Heat Walker" ||
	GearName == "Metamorphosis" ||
	GearName == "Thick Hide" ||
	GearName == "Gold Bones" ||
	GearName == "Absorption" ||
	GearName == "Adrenaline" ||
	GearName == "Reaper" ||
	GearName == "Toxic Release" ||
	GearName == "Recycling" ||
	GearName == "Blue Scales" ||
	GearName == "Red Scales" ||
	GearName == "Curved Tusks" ||
	GearName == "Early Riser" ||
	GearName == "Outer Shell" ||
	GearName == "Resourceful" ||
	GearName == "Naturalist" ||
	GearName == "Bounty Hunter" ||
	GearName == "Scraps" ||
	GearName == "Tinkerer" ||
	GearName == "Magnetic" ||
	GearName == "Merchant" ||
	GearName == "Conservation" ||
	GearName == "Vendor" ||
	GearName == "Shock Absorber" ||
	GearName == "Stamina" ||
	GearName == "Rested" ||
	GearName == "Midas Touch" ||
	GearName == "Exhaust Vent" ||
	GearName == "Fervor" ||
	GearName == "Enlightened" ||
	GearName == "Engorged" ||
	GearName == "Archmage" ||
	GearName == "Rebirth" ||
	GearName == "Heavyweight" ||
	GearName == "Deja Vu" ||
	GearName == "Concentration" ||
	GearName == "Reversal" ||
	GearName == "Amass" ||
	GearName == "Technician" ||
	GearName == "Optimist" ||
	GearName == "Stockpile" ||
	GearName == "Draining Touch" ||
	GearName == "Fleet of Foot" ||
	GearName == "Gold Claws" ||
	GearName == "Gold Scales" ||
	GearName == "Gold Brain" ||
	GearName == "Phlogiston" ||
	GearName == "Momentum" ||
	GearName == "Dynamic") {
		Type = "Trait Reward";
		TraitRDescription();
	}

	else {
		Type = "";
		Description = "";
	}
}


Gear::~Gear()
{
}

void Gear::HandsDescription() {
	if (GearName == "No Weapon") {
		Description = "Bare hands are better than no hands.";
	}
	else if (GearName == "Crystal Ball") {
		Description = "A glass ball on a stand, supposedly used for scrying. Not a very good weapon, though.";
	}
	else if (GearName == "Buckler") {
		Description = "A small shield, also capable of ramming the opponent.";
	}
	else if (GearName == "Shield") {
		Description = "Although it doesn't look like much of a weapon, it can pack quite an offensive punch.";
	}
	else if (GearName == "Long Sword") {
		Description = "A sturdy weapon with a double sided blade.";
	}
	else if (GearName == "Falchion") {
		Description = "A one-handed sword with a heavy blade, great for hacking through armor.";
	}
	else if (GearName == "Metal Staff") {
		Description = "A long metal stick, a much more lethal weapon than its wooden counterparts.";
	}
	else if (GearName == "Steel Spear") {
		Description = "The pointed blade proves useful at piercing tough armor.";
	}
	else if (GearName == "Javelin") {
		Description = "A spear not just used for long ranged stabbing, but a useful projectile, as well.";
	}
	else if (GearName == "Obsidian Spear") {
		Description = "This spear has been sharpened so much that it will slide right through the victim.";
	}
	else if (GearName == "Halberd") {
		Description = "An axe head on a spear, a multipurpose tool.";
	}
	else if (GearName == "Lance") {
		Description = "A heavy charging spear made for cavalry, but will do just fine without a mount.";
	}
	else if (GearName == "Rapier") {
		Description = "A thin sword, capable of swift movements and deadly thrusts.";
	}
	else if (GearName == "War Hammer") {
		Description = "Extremely heavy, capable of dealing devastating blows.";
	}
	else if (GearName == "Morning Star") {
		Description = "A spiked mace, both used for blunt force and piercing strikes.";
	}
	else if (GearName == "Battle Axe") {
		Description = "An axe not for chopping trees but for chopping enemies.";
	}
	else if (GearName == "Double Axe") {
		Description = "A heavy war axe that can deal most powerful cleaving blows.";
	}
	else if (GearName == "Shiv") {
		Description = "A small blade, even compared to a dagger, used for a quick stab or two.";
	}
	else if (GearName == "Serrated Dagger") {
		Description = "A short blade with a jagged edge, wonderful for punturing its victims.";
	}
	else if (GearName == "Simple Bow") {
		Description = "A long ranged weapon so that enemies may be dealt with from afar.";
	}
	else if (GearName == "Recurve Bow") {
		Description = "A bow with its ends curved outwards, capable of firing more quick and powerful shots.";
	}
	else if (GearName == "Throwing Stars") {
		Description = "An ancient assassin's tool for quick and accurate strikes from range. ";
	}
	else if (GearName == "Wand") {
		Description = "A short, carved stick that has been enchanted to channel an amount of the user's arcane energy outwards to inflict harm.";
	}
	else if (GearName == "Sickle") {
		Description = "A very strange and surprisingly versatile tool, modified to be used as a weapon rather than a farming apparatus.";
	}
	else if (GearName == "Hand Cannon") {
		Description = "A terrible piece of technology, capable of firing immensely destructive shots without even the use of magic.";
	}
	else if (GearName == "Conductive Gloves") {
		Description = "These weapons allow you to direct magic into your fists for mighty blows.";
	}
	else if (GearName == "Sabre") {
		Description = "A single-edged blade for consistent slashing.";
	}
	else if (GearName == "Whip") {
		Description = "A simple cord on a handle, difficult to control at first, but powerful when used correctly.";
	}
	else if (GearName == "Twin Flail") {
		Description = "Two chains with spiked balls at the end. Dangerous.";
	}
	else if (GearName == "Leather Gauntlets") {
		Description = "The fists are mighty weapons, but flesh is soft and requires protection.";
	}
	else if (GearName == "Steel Gauntlets") {
		Description = "Converts your knuckes into hard and powerful steel.";
	}
	else if (GearName == "Spiked Gauntlets") {
		Description = "Steel gloves with spikes at the knuckles, allowing for puncturing blows.";
	}
	else if (GearName == "Arbalest") {
		Description = "A large crossbow with a mechanism to draw back bolts automatically, providing more power and speed.";
	}
	else if (GearName == "Dirk") {
		Description = "A long combat dagger.";
	}
	else if (GearName == "Cutlass") {
		Description = "A common weapon of sailors and pirates, useful for close quarters combat.";
	}
	else if (GearName == "Greatsword") {
		Description = "A mighty and heavy two-handed sword, able to cut foes right in half.";
	}
	else if (GearName == "Athame") {
	Description = "Daggers used to perform sacrifices in hope that a god will respond in favor.";
	}
}
void Gear::BodyDescription() {
	if (GearName == "No Armor") {
		Description = "Your tough form can take a hit or two.";
	}
	else if (GearName == "Mage Armor") {
		Description = "This full body armor was specifically built for arcane soldiers, channeling the user's power in order to harden the material.";
	}
	else if (GearName == "Glitter Robes") {
		Description = "These blindingly shiny robes provide almost no protection, but do provide a modest boost to the wearer's arcane energy.";
	}
	else if (GearName == "Riveted Chainmail") {
		Description = "The strongest and lightest mail. Having taken so long to make, only the greatest of champions were given these.";
	}
	else if (GearName == "Reinforced Mail") {
		Description = "A mix of mail and plates, this armor is reliable and fairly easy to move in.";
	}
	else if (GearName == "Full Plate Armor") {
		Description = "The heaviest armor you can find, it is restricting but extremely sturdy.";
	}
	else if (GearName == "Cape") {
		Description = "This is not only an accessory, but provides great dexterity in combat.";
	}
	else if (GearName == "Feathered Cloak") {
		Description = "This cloak is composed of feathers, specifically made to increase your swiftness as you run.";
	}
	else if (GearName == "Leather Hauberk") {
		Description = "Although leather may not be as strong as steel, this armor provides great versatility in combat.";
	}
	else if (GearName == "Twilight Robes") {
		Description = "Dash through the darkness, concealing your exact position even in combat.";
	}
	else if (GearName == "Dragon Scales") {
		Description = "As tough as plate armor and as sharp as daggers, dragon scales also provide slight psychic enhancement.";
	}
	else if (GearName == "Spiked Mail") {
		Description = "Sturdy mail interwoven with long spikes, this piece of equipment will deal great harm to any attacker.";
	}
	else if (GearName == "Buffalo Hide") {
		Description = "The primary choice of battle-wear for the Berserkers, this clothing displays full commitment to unequivocal offensive rage.";
	}
	else if (GearName == "Steel Breastplate") {
		Description = "A sturdy plate made with a the strongest alloy those alchemists could muster.";
	}
	else if (GearName == "Amulet of Aura") {
		Description = "This jewelled necklace shines brightly when worn, emanating some kind of force that the user is given control over.";
	}
	else if (GearName == "Turtle Shell") {
		Description = "A thick shell from an extraordinarily large turtle, one wearing this would probably not feel a thing from oncoming attackers.";
	}
	else if (GearName == "Crystal Breastplate") {
		Description = "Made from the hardest materials one can manage to find, this mesmerizingly iridescent plate also connects with the wearer's mind.";
	}
	else if (GearName == "Padded Tunic") {
		Description = "An everyday garment with a bit of protection, but not enough to slow you down.";
	}
	else if (GearName == "Chain Mail") {
		Description = "A simple coat of metal rings linked together.";
	}
	else if (GearName == "Gilded Robes") {
		Description = "Clothing lined with gold, once belonging to a very wealthy individual.";
	}
	else if (GearName == "Wizard Garb") {
		Description = "The typical attire for an aspiring magician.";
	}
	else if (GearName == "Cloth Shirt") {
		Description = "A light and simple shirt.";
	}
	else if (GearName == "Grass Armor") {
		Description = "Light armor that mends itself.";
	}
	else if (GearName == "Flesh Suit") {
		Description = "A repulsive piece of equipment, made of ever morphing and moving tissue and bone.";
	}
	else if (GearName == "Grey Robes") {
		Description = "These robes give off a powerful feeling.";
	}
}
void Gear::HeadDescription() {
	if (GearName == "No Headgear") {
		Description = "Focus the mind, channel your inner power.";
	}
	else if (GearName == "Brown Hat") {
		Description = "Who needs spells?";
	}
	else if (GearName == "Vampire Fangs") {
		Description = "These loose canines will attach to yours like a magnet. It siphons the life of the wearer, but provides returns through its victims.";
	}
	else if (GearName == "Warp Goggles") {
		Description = "These telescopic goggles allow you too manipulate and modify space as you see fit.";
	}
	else if (GearName == "Tundra Cap") {
		Description = "This winter hat has been enchanted to steal and release heat at a focused area. This makes it very warm when being used.";
	}
	else if (GearName == "Plague Mask") {
		Description = "Resembling the head of a bird, the beak of this mask contains many herbs and spices meant to shield the wearer from miasma.";
	}
	else if (GearName == "Dragonskin Hood") {
		Description = "Skinned from an actual dragon, this hood radiates heat. It infuses the user with some abilities of a fire breather.";
	}
	else if (GearName == "Shifting Veil") {
		Description = "The mind of whoever looks at this veil is bound to the whims of the wearer on the other side.";
	}
	else if (GearName == "Copper Cage") {
		Description = "An odd piece of headgear, whoever created this cage probably wished to channel the power of electricity, and likely died trying.";
	}
	else if (GearName == "Bedstone Helmet") {
		Description = "An extremely large and heavy and piece of equipment. This helmet allows the user to destroy and reform it to create unbreakable walls and bludgeons.";
	}
	else if (GearName == "Glass Eye") {
		Description = "A glass sphere with a prism contained inside. It seems to stare back at you.";
	}
	else if (GearName == "Laurel Wreath") {
		Description = "A simple crown of leaves and branches. These ones seem to twist and write as if they were sentient.";
	}
	else if (GearName == "Diving Gear") {
		Description = "An ancient bronze helmet, meant to be airtight against a suit to protect from the ocean.";
	}
	else if (GearName == "Makeup Set") {
		Description = "These glimmering cosmetics could make even the most hideous beast attract another.";
	}
	else if (GearName == "Safety Glasses") {
		Description = "A good alchemist always wears protection from harmful ingredients.";
	}
	else if (GearName == "Golden Monocle") {
		Description = "An extravagant tool, more for show than anything else.";
	}
	else if (GearName == "Desert Wrappings") {
		Description = "Protect your self from the sand, it hits harder than you think.";
	}
	else if (GearName == "Viking Helm") {
		Description = "This ancient helmet holds the memories of many valiant warriors slain in battle.";
	}
	else if (GearName == "Unholy Cowl") {
		Description = "This hood is worn during rituals performed to drain the soul out of sacrifices.";
	}
	else if (GearName == "Jewelled Crown") {
		Description = "This priceless headpiece was one of a powerful king, able to summon loyal soldiers with only a word.";
	}
	else if (GearName == "Human Skull") {
		Description = "An object that once had life, able to channel the forbidden magic.";
	}
	else if (GearName == "Crystal Earrings") {
		Description = "The light glistens off these earrings quite beautifully.";
	}
	else if (GearName == "Scary Face") {
		Description = "Even a glance can scare an opponent into submission.";
	}
	else if (GearName == "Ear Plugs") {
		Description = "Be careful not to rupture your own eardrums.";
	}
	else if (GearName == "White Halo") {
		Description = "A symbol of the gods, capable of channeling divine power.";
	}
	else if (GearName == "Bronze Head") {
		Description = "An impenetrable helm of thick bronze.";
	}
}

void Gear::ModDescription() {
	if (GearName == "Burn") {
		Description = "Remove this card for the rest of combat.";
	}
	else if (GearName == "Stay") {
		Description = "Stays in hand after use, subtracting one Stay.";
	}
	else if (GearName == "Flow") {
		Description = "This card discards at the end of the turn.";
	}
	else if (GearName == "Copy") {
		Description = "Have one more of this card during combat.";
	}
	else if (GearName == "Push") {
		Description = "Discard entire hand after use.";
	}
	else if (GearName == "Void") {
		Description = "This card cannot be drawn.";
	}
	else if (GearName == "Link") {
		Description = "Draws the next card in the Link chain.";
	}
}

void Gear::TraitSDescription() {
	//Trait Sacrifice
	if (GearName == "Anemia") {
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
	else if (GearName == "Volatile") {
		Type = "Trait Sacrifice";
		Description = "Every 4 turns, everybody takes 15 damage.";
	}
	else if (GearName == "Melting") {
		Type = "Trait Sacrifice";
		Description = "Gain 1 block and lose 1 health every turn.";
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
		Description = "You no longer see the text log. ";
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
		Description = "All of your over time effects occur twice every turn.";
	}
	else if (GearName == "Frenzy") {
		Type = "Trait Sacrifice";
		Description = "Take and deal double damage.";
	}
	else if (GearName == "Corpse") {
		Type = "Trait Sacrifice";
		Description = "You can no longer heal during combat. +5 max hp.";
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
		Description = "Reduce max hp by 35. +10 defense.";
	}
	else if (GearName == "Succumb") {
		Type = "Trait Sacrifice";
		Description = "Your traits are now randomly chosen. +2 Skill.";
	}
	else if (GearName == "Slow") {
		Type = "Trait Sacrifice";
		Description = "Every enemy starts battle with one negate.";
	}
	else if (GearName == "Sticky Feet") {
		Type = "Trait Sacrifice";
		Description = "Every turn, 20% chance to lose 4 Energy.";
	}
	else if (GearName == "Overconfidence") {
		Type = "Trait Sacrifice";
		Description = "You cannot gain block after turn 5. +3 Def.";
	}
	else if (GearName == "Hallucinations") {
		Type = "Trait Sacrifice";
		Description = "Enemies have a chance of changing form.";
	}
	else if (GearName == "Tail") {
		Type = "Trait Sacrifice";
		Description = "Your hand can neither be shuffled nor filled.";
	}
	else if (GearName == "Weak Back") {
		Type = "Trait Sacrifice";
		Description = "You can no longer pick up gear.";
	}
	else if (GearName == "Charred Skin") {
		Type = "Trait Sacrifice";
		Description = "You heal instead of gaining block.";
	}
	else if (GearName == "Purple") {
		Type = "Trait Sacrifice";
		Description = "All stat changes are now permanent.";
	}
	else if (GearName == "Madness") {
		Type = "Trait Sacrifice";
		Description = "Add a Mad card to your deck.";
	}
	else if (GearName == "Inefficient") {
		Type = "Trait Sacrifice";
		Description = "Everyone takes 2 turns instead of 1.";
	}
	else if (GearName == "Brain Worm") {
		Type = "Trait Sacrifice";
		Description = "Lose half your max hp. Double your current max mana.";
	}
	else if (GearName == "Gold Flesh") {
		Type = "Trait Sacrifice";
		Description = "Lose 1 gold every time you lose health.";
	}
	else if (GearName == "Terraform") {
		Type = "Trait Sacrifice";
		Description = "You sometimes transform the land around you.";
	}
	else if (GearName == "Psychosis") {
		Type = "Trait Sacrifice";
		Description = "Spells with cost are used twice and cost twice as much.";
	}
	else if (GearName == "Dazed") {
		Type = "Trait Sacrifice";
		Description = "Spells cost 1 more mana.";
	}
	else if (GearName == "Strategy") {
		Type = "Trait Sacrifice";
		Description = "Your damage and block are switched.";
	}
	else if (GearName == "Doomed") {
		Type = "Trait Sacrifice";
		Description = "The final boss will have 50% more hp.";
	}
	else if (GearName == "Eruption") {
		Type = "Trait Sacrifice";
		Description = "Many of the tiles around you become Lava.";
	}
	else if (GearName == "Flash Freeze") {
		Type = "Trait Sacrifice";
		Description = "10 tiles in each direction from you will become Ice.";
	}
	else if (GearName == "Scented") {
		Type = "Trait Sacrifice";
		Description = "Combat tiles have a chance for an extra fight.";
	}
	else if (GearName == "Colossus") {
		Type = "Trait Sacrifice";
		Description = "Convert all Str, Def, and Int into threefold max hp.";
	}
	else if (GearName == "Timer") {
		Type = "Trait Sacrifice";
		Description = "Start combat with 1 health and 5 Negates.";
	}
	else if (GearName == "Sacrificial") {
		Type = "Trait Sacrifice";
		Description = "You take damage instead of losing mana.";
	}
	else if (GearName == "Membrane") {
		Type = "Trait Sacrifice";
		Description = "Start combat with half hp, gain that much block.";
	}
	else if (GearName == "Addiction") {
		Type = "Trait Sacrifice";
		Description = "Every time you play a non-Spell, lose 1 Int. +3 Int.";
	}
	else if (GearName == "Paranoia") {
		Type = "Trait Sacrifice";
		Description = "Does nothing.";
	}
	else if (GearName == "Sticky Skin") {
		Type = "Trait Sacrifice";
		Description = "You can no longer take off gear.";
	}
	else if (GearName == "Asthma") {
		Type = "Trait Sacrifice";
		Description = "Increase your max Energy by 2.";
	}
	else if (GearName == "Flat Feet") {
		Type = "Trait Sacrifice";
		Description = "If you have -5 or less Energy, decrease it to -10.";
	}
	else if (GearName == "Muscle Mass") {
		Type = "Trait Sacrifice";
		Description = "Damage dealt is stored instead and dealt every 5 turns.";
	}
	else if (GearName == "Chaos#") {
		Type = "Trait Sacrifice";
		Description = "Add two Chaos cards to your deck.";
	}
	else if (GearName == "Panic Attack"){
		Type = "Trait Sacrifice";
		Description = "If you take 20 or more damage at once, -9 Energy.";
	}
	else if (GearName == "Cursed") {
	Type = "Trait Sacrifice";
	Description = "Negative cards are added to your deck twice.";
	}
	else if (GearName == "Joint Pain") {
	Type = "Trait Sacrifice";
	Description = "Every time you get an extra turn take 6 damage.";
	}
	else if (GearName == "Daredevil") {
	Type = "Trait Sacrifice";
	Description = "After combat take 2x(Skl) dmg and gain (Skl) gold.";
	}
	else if (GearName == "Careless") {
	Type = "Trait Sacrifice";
	Description = "Gear is destroyed when taken off.";
	}
	else if (GearName == "Hoarder") {
	Type = "Trait Sacrifice";
	Description = "Take damage every turn equal to your extra Gear.";
	}
	else if (GearName == "Atrophy") {
	Type = "Trait Sacrifice";
	Description = "On turn 4, add a Drain card to your hand.";
	}
	else if (GearName == "Burnout") {
	Type = "Trait Sacrifice";
	Description = "Burn the first (Skl) cards used in combat.";
	}
	else if (GearName == "Blackout") {
	Type = "Trait Sacrifice";
	Description = "Void a random card at the start of combat.";
	}
	else if (GearName == "Combo Breaker") {
	Type = "Trait Sacrifice";
	Description = "Playing a card 5 times Burns it.";
	}
	else if (GearName == "Memory Lapse") {
	Type = "Trait Sacrifice";
	Description = "Take (Skl) dmg if you use the same card twice in a row.";
	}
	else if (GearName == "Stiff") {
	Type = "Trait Sacrifice";
	Description = "Your stats can no longer change.";
	}
	else if (GearName == "Ethereal") {
	Type = "Trait Sacrifice";
	Description = "-3d2 block per turn. If you have 0 block, gain 2 mana.";
	}
	else if (GearName == "Falter") {
	Type = "Trait Sacrifice";
	Description = "Every 6 damage taken, lose 1 Max Health for the combat.";
	}
	else if (GearName == "Exposed") {
	Type = "Trait Sacrifice";
	Description = "Every 8 health lost, reduce a random stat by 1.";
	}
	else if (GearName == "Circus") {
	Type = "Trait Sacrifice";
	Description = "Jesters appear more often.";
	}
	else if (GearName == "Spiritual") {
	Type = "Trait Sacrifice";
	Description = "Lose 1 Max Hp and gain 1 Max Mana after every fight.";
	}
	else if (GearName == "Stuck") {
	Type = "Trait Sacrifice";
	Description = "Energy goes over max. Extra turns occur every 2 turns.";
	}
	else if (GearName == "Inert") {
	Type = "Trait Sacrifice";
	Description = "-3 Max Energy. Get Negates instead of extra turns.";
	}
	else if (GearName == "Lightweight") {
	Type = "Trait Sacrifice";
	Description = "Having 30 block converts it to a Negate.";
	}
	else if (GearName == "Headache") {
	Type = "Trait Sacrifice";
	Description = "Lose 2 Energy each turn you have full mana.";
	}
	else if (GearName == "Reckless") {
	Type = "Trait Sacrifice";
	Description = "Take 2 damage when you deal damage.";
	}
	else if (GearName == "Wasteful") {
	Type = "Trait Sacrifice";
	Description = "Every 10 turns, burn your hand.";
	}
	else if (GearName == "Strain") {
	Type = "Trait Sacrifice";
	Description = "Lose 5 Energy when you use a Boss Card.";
	}
	else if (GearName == "Materialist") {
	Type = "Trait Sacrifice";
	Description = "Lose 5 max mana. Gain 50 gold.";
	}
	else if (GearName == "Run") {
	Type = "Trait Sacrifice";
	Description = "Defends give 10 Energy, other cards lose 10.";
	}
	else if (GearName == "Commitment") {
	Type = "Trait Sacrifice";
	Description = "Choose a stat. You can only gain this from stat rewards.";
	}
	else if (GearName == "Heavy") {
	Type = "Trait Sacrifice";
	Description = "Gain/lose block instead of Energy.";
	}
	else if (GearName == "Wind Down") {
	Type = "Trait Sacrifice";
	Description = "-6 Max Energy. +1 for the combat every Extra Turn.";
	}
	else if (GearName == "Short Circuit") {
	Type = "Trait Sacrifice";
	Description = "Take 4 damage each time you lose mana.";
	}
	else if (GearName == "Empty") {
	Type = "Trait Sacrifice";
	Description = "During combat, +1 Max Energy for every Voided card.";
	}
	else if (GearName == "Unsteady") {
	Type = "Trait Sacrifice";
	Description = "Add a Stumble card to your deck.";
	}
	else if (GearName == "Sore") {
	Type = "Trait Sacrifice";
	Description = "Lose 6 health before healing.";
	}
	else if (GearName == "Earthquake") {
	Type = "Trait Sacrifice";
	Description = "All City becomes Wasteland.";
	}
	else if (GearName == "") {
	Type = "Trait Sacrifice";
	Description = "";
	}
	else {
		Type = "";
		Description = "";
	}
}
void Gear::TraitRDescription() {
	//Trait Reward
	if (GearName == "Mending Flesh") {
	Type = "Trait Reward";
	Description = "Heal 1d(Skl) health each turn.";
	}
	else if (GearName == "Gymnast") {
	Type = "Trait Reward";
	Description = "Gain 1d2 Energy every turn.";
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
	else if (GearName == "Unseen") {
	Type = "Trait Reward";
	Description = "Gain 9 +1d(Skl) Energy at the start of combat.";
	}
	else if (GearName == "Spiny Skin") {
	Type = "Trait Reward";
	Description = "Deal (Skl)+3 damage when attacked.";
	}
	else if (GearName == "Wings") {
	Type = "Trait Reward";
	Description = "Leave non-Final Boss combat at any time.";
	}
	else if (GearName == "Exoskeleton") {
	Type = "Trait Reward";
	Description = "Gain 1d(Skl) -1 block every turn.";
	}
	else if (GearName == "Unpredictable") {
	Type = "Trait Reward";
	Description = "Shuffle your hand every turn.";
	}
	else if (GearName == "Ego") {
	Type = "Trait Reward";
	Description = "Choose a Boss card to add to your deck.";
	}
	else if (GearName == "The Box#") {
	Type = "Trait Reward";
	Description = "Reroll all stats.";
	}
	else if (GearName == "Quick Thinker") {
	Type = "Trait Reward";
	Description = "Every 4 turns, gain (Skl)d2 mana.";
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
	Description = "Gain 1 max health after every fight.";
	}
	else if (GearName == "Hemoglobin") {
	Type = "Trait Reward";
	Description = "Your heals are increased by 50%.";
	}
	else if (GearName == "Destiny") {
	Type = "Trait Reward";
	Description = "Get 3 Cauldrons. You cannot recieve any more.";
	}
	else if (GearName == "Scavenger") {
	Type = "Trait Reward";
	Description = "You find twice as much gear.";
	}
	else if (GearName == "Horns") {
	Type = "Trait Reward";
	Description = "Losing a Negate deals 5 +(Skl/2)d2 damage.";
	}
	else if (GearName == "Genius") {
	Type = "Trait Reward";
	Description = "+2 Int. Choose a spell to add to your deck.";
	}
	else if (GearName == "Green Scales") {
	Type = "Trait Reward";
	Description = "All damage taken is reduced by (Skl/2).";
	}
	else if (GearName == "Multi-Tongued") {
	Type = "Trait Reward";
	Description = "You can now talk to your enemies.";
	}
	else if (GearName == "Triple-Jointed") {
	Type = "Trait Reward";
	Description = "Have one more card choice in combat.";
	}
	else if (GearName == "Blacksmith") {
	Type = "Trait Reward";
	Description = "Recieve 12 card modifiers.";
	}
	else if (GearName == "Iron Scabs") {
	Type = "Trait Reward";
	Description = "Whenever you lose health, gain half of that as block.";
	}
	else if (GearName == "Gelatinous") {
	Type = "Trait Reward";
	Description = "Gain (Skl)x2 block at the start of each combat.";
	}
	else if (GearName == "Evolve") {
	Type = "Trait Reward";
	Description = "All stats +1.";
	}
	else if (GearName == "Eight Legs") {
	Type = "Trait Reward";
	Description = "Ice and Forest no longer affects you negatively.";
	}
	else if (GearName == "Refine") {
		Type = "Trait Reward";
		Description = "Gain 2 Void modifiers.";
	}
	else if (GearName == "Relentless") {
	Type = "Trait Reward";
	Description = "Gain 4 Stay modifiers.";
	}
	else if (GearName == "Heat Walker") {
	Type = "Trait Reward";
	Description = "Lava no longer affects you negatively.";
	}
	else if (GearName == "Metamorphosis") {
	Type = "Trait Reward";
	Description = "Lose all Str, Def, and Int. Gain that many +2 stats.";
	}
	else if (GearName == "Thick Hide") {
	Type = "Trait Reward";
	Description = "Having any block reduces damage taken by 15%.";
	}
	else if (GearName == "Gold Bones") {
	Type = "Trait Reward";
	Description = "Losing health will remove gold first. +25 gold.";
	}
	else if (GearName == "Absorption") {
	Type = "Trait Reward";
	Description = "Deal (Skl)d3 damage on death. You live if the enemy dies.";
	}
	else if (GearName == "Adrenaline") {
	Type = "Trait Reward";
	Description = "+6 Str and +12 Def if below 15 block + hp.";
	}
	else if (GearName == "Reaper") {
	Type = "Trait Reward";
	Description = "Kill any enemy below 5+ 2x(Skl) health.";
	}
	else if (GearName == "Toxic Release") {
	Type = "Trait Reward";
	Description = "The enemy takes 1+ 1d(Skl/2) damage every turn.";
	}
	else if (GearName == "Recycling") {
	Type = "Trait Reward";
	Description = "Playing 3 Spells in a row gives 4 +1d(Skl) mana.";
	}
	else if (GearName == "Blue Scales") {
	Type = "Trait Reward";
	Description = "If you take 5 or less damage, reduce it to 0.";
	}
	else if (GearName == "Red Scales") {
	Type = "Trait Reward";
	Description = "If you take 25 or more damage, reduce it to 0.";
	}
	else if (GearName == "Curved Tusks") {
	Type = "Trait Reward";
	Description = "Deal 4+(Skl/2) damage every turn you have 0 block.";
	}
	else if (GearName == "Early Riser") {
	Type = "Trait Reward";
	Description = "Get +5 to Str, Def, and Int on the first turn of combat.";
	}
	else if (GearName == "Outer Shell") {
	Type = "Trait Reward";
	Description = "Block is retained after combat.";
	}
	else if (GearName == "Resourceful") {
	Type = "Trait Reward";
	Description = "If you are forced to Reshuffle, gain 40 block.";
	}
	else if (GearName == "Naturalist") {
	Type = "Trait Reward";
	Description = "Each turn you have 0 cards, deal 40 damage.";
	}
	else if (GearName == "Bounty Hunter") {
	Type = "Trait Reward";
	Description = "Winning Combat or Boss before turn 3 gives 5x gold reward.";
	}
	else if (GearName == "Scraps") {
	Type = "Trait Reward";
	Description = "After battle, turn your block into gold.";
	}
	else if (GearName == "Tinkerer") {
	Type = "Trait Reward";
	Description = "Gain 1 card modifier after Combat.";
	}
	else if (GearName == "Magnetic") {
	Type = "Trait Reward";
	Description = "Find 1 gear after Combat.";
	}
	else if (GearName == "Merchant") {
	Type = "Trait Reward";
	Description = "Entering shops sells your gear for 2x(Skl) gold each.";
	}
	else if (GearName == "Conservation") {
	Type = "Trait Reward";
	Description = "+1 Str, Def, and Int for each negative Energy.";
	}
	else if (GearName == "Vendor") {
	Type = "Trait Reward";
	Description = "Open a shop after Cauldrons and bosses.";
	}
	else if (GearName == "Shock Absorber") {
	Type = "Trait Reward";
	Description = "Taking a total of 50 damage gives 2 Negates.";
	}
	else if (GearName == "Stamina") {
	Type = "Trait Reward";
	Description = "Gain double Energy if below 0.";
	}
	else if (GearName == "Rested") {
	Type = "Trait Reward";
	Description = "Losing a turn gives (Skl)d3 hp and (Skl)d2 mana.";
	}
	else if (GearName == "Midas Touch") {
	Type = "Trait Reward";
	Description = "Gain gold equal to the enemy's negative hp.";
	}
	else if (GearName == "Exhaust Vent") {
	Type = "Trait Reward";
	Description = "Losing a turn deals (Skl)d2 damage for 3 turns.";
	}
	else if (GearName == "Fervor") {
	Type = "Trait Reward";
	Description = "Attacks also deal 1 dmg for (Skl) turns, stacking.";
	}
	else if (GearName == "Enlightened") {
	Type = "Trait Reward";
	Description = "Mana can exceed max. Lose 2 mana per turn over max.";
	}
	else if (GearName == "Engorged") {
	Type = "Trait Reward";
	Description = "Hp can exceed max. Lose 3 hp per turn over max.";
	}
	else if (GearName == "Archmage") {
	Type = "Trait Reward";
	Description = "Gain 1 Int every time you use a Spell.";
	}
	else if (GearName == "Rebirth") {
	Type = "Trait Reward";
	Description = "Having 0 max hp sets it to 40.";
	}
	else if (GearName == "Heavyweight") {
	Type = "Trait Reward";
	Description = "Having 50 block converts it to damage.";
	}
	else if (GearName == "Deja Vu") {
	Type = "Trait Reward";
	Description = "Seeing an enemy twice in a row deals 40 damage.";
	}
	else if (GearName == "Concentration") {
	Type = "Trait Reward";
	Description = "Using a card type thrice in a row gives (Skl)d2 Energy.";
	}
	else if (GearName == "Reversal") {
	Type = "Trait Reward";
	Description = "Losing a stat gains it instead.";
	}
	else if (GearName == "Amass") {
	Type = "Trait Reward";
	Description = "Every 4 block lost gain 1 Str for the combat.";
	}
	else if (GearName == "Technician") {
	Type = "Trait Reward";
	Description = "Damage you deal under 10 is doubled.";
	}
	else if (GearName == "Optimist") {
	Type = "Trait Reward";
	Description = "Negative cards deal (Skl)x3 damage.";
	}
	else if (GearName == "Stockpile") {
	Type = "Trait Reward";
	Description = "The Boss stat reward is doubled.";
	}
	else if (GearName == "Draining Touch") {
	Type = "Trait Reward";
	Description = "Attacks give 2+(Skl) mana.";
	}
	else if (GearName == "Fleet of Foot") {
	Type = "Trait Reward";
	Description = "Defends give 3 Energy.";
	}
	else if (GearName == "Gold Claws") {
	Type = "Trait Reward";
	Description = "Increase damage dealt by 1d(Gold/9).";
	}
	else if (GearName == "Gold Scales") {
	Type = "Trait Reward";
	Description = "Reduce damage taken by (Gold)/12.";
	}
	else if (GearName == "Gold Brain") {
	Type = "Trait Reward";
	Description = "+(Gold/15) Int during combat.";
	}
	else if (GearName == "Phlogiston") {
	Type = "Trait Reward";
	Description = "Burning a card deals (Skl)d2 damage.";
	}
	else if (GearName == "Momentum") {
	Type = "Trait Reward";
	Description = "Every Extra Turn, +1 random stat for the combat.";
	}
	else if (GearName == "Dynamic") {
	Type = "Trait Reward";
	Description = "+3d2 Energy when you shuffle or fill your hand.";
	}
	else if (GearName == "") {
	Type = "Trait Reward";
	Description = "";
	}
	else {
	Type = "";
	Description = "";
	}
}

void Gear::GearOnOrOff(bool On, Character &guy, Deck &deck) {
	//Hands
	if (Type == "Hands") {
		HandsOnOrOff(On, guy, deck);
	}

	//Body
	else if (Type == "Body") {
		BodyOnOrOff(On, guy, deck);
	}

	//Head
	else if (Type == "Head") {
		HeadOnOrOff(On, guy, deck);
	}
	
	guy.printStats();
}

void Gear::HandsOnOrOff(bool On, Character &guy, Deck &deck) {
	if (GearName == "No Weapon") {
		Card smack("Smack");
		if (On) {
			deck.addCard(smack);
			deck.addCard(smack);
		}
		else {
			deck.removeCard(smack, guy);
			deck.removeCard(smack, guy);
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
	else if (GearName == "Buckler") {
		Card ram("Ram");
		if (On) {
			deck.addCard(ram);
		}
		else {
			deck.removeCard(ram, guy);
		}
	}
	else if (GearName == "Shield") {
		Card ram("Ram");
		if (On) {
			deck.addCard(ram);
			deck.addCard(ram);
			deck.addCard(ram);
		}
		else {
			deck.removeCard(ram, guy);
			deck.removeCard(ram, guy);
			deck.removeCard(ram, guy);
		}
	}
	else if (GearName == "Long Sword") {
		Card slice("Slice");
		Card crush("Crush");
		if (On) {
			deck.addCard(slice);
			deck.addCard(slice);
			deck.addCard(crush);
		}
		else {
			deck.removeCard(slice, guy);
			deck.removeCard(slice, guy);
			deck.removeCard(crush, guy);
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
			deck.removeCard(slice, guy);
			deck.removeCard(slice, guy);
			deck.removeCard(hack, guy);
		}
	}
	else if (GearName == "Metal Staff") {
		Card parry("Parry");
		if (On) {
			deck.addCard(parry);
		}
		else {
			deck.removeCard(parry, guy);
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
			deck.removeCard(pierce, guy);
			deck.removeCard(pierce, guy);
			deck.removeCard(pierce, guy);
		}
	}
	else if (GearName == "Javelin") {
		Card pierce("Pierce");
		Card throww("Throw");
		if (On) {
			deck.addCard(pierce);
			deck.addCard(pierce);
			deck.addCard(throww);
			deck.addCard(throww);
		}
		else {
			deck.removeCard(pierce, guy);
			deck.removeCard(pierce, guy);
			deck.removeCard(throww, guy);
			deck.removeCard(throww, guy);
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
			deck.removeCard(pierce, guy);
			deck.removeCard(pierce, guy);
			deck.removeCard(impale, guy);
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
			deck.addCard(parry);
		}
		else {
			deck.removeCard(charge, guy);
			deck.removeCard(hack, guy);
			deck.removeCard(pierce, guy);
			deck.removeCard(slice, guy);
			deck.removeCard(parry, guy);
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
			deck.removeCard(charge, guy);
			deck.removeCard(charge, guy);
			deck.removeCard(impale, guy);
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
			deck.removeCard(slice, guy);
			deck.removeCard(slice, guy);
			deck.removeCard(pierce, guy);
			deck.removeCard(parry, guy);
			deck.removeCard(feint, guy);
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
			deck.removeCard(crush, guy);
			deck.removeCard(crush, guy);
			deck.removeCard(demolish, guy);
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
			deck.removeCard(crush, guy);
			deck.removeCard(crush, guy);
			deck.removeCard(pierce, guy);
			deck.removeCard(pierce, guy);
			deck.removeCard(demolish, guy);
		}
	}
	else if (GearName == "Battle Axe") {
		Card hack("Hack");
		Card crush("Crush");
		Card bleed("Bleed");
		if (On) {
			deck.addCard(hack);
			deck.addCard(hack);
			deck.addCard(crush);
			deck.addCard(bleed);
		}
		else {
			deck.removeCard(hack, guy);
			deck.removeCard(hack, guy);
			deck.removeCard(crush, guy);
			deck.removeCard(bleed, guy);
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
			deck.removeCard(charge, guy);
			deck.removeCard(hack, guy);
			deck.removeCard(hack, guy);
			deck.removeCard(demolish, guy);
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
			deck.removeCard(stab, guy);
			deck.removeCard(pierce, guy);
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
			deck.removeCard(bleed, guy);
			deck.removeCard(bleed, guy);
			deck.removeCard(slice, guy);
			deck.removeCard(stab, guy);
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
			deck.addCard(pierce);
		}
		else {
			deck.removeCard(shoot, guy);
			deck.removeCard(shoot, guy);
			deck.removeCard(slice, guy);
			deck.removeCard(pierce, guy);
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
			deck.removeCard(shoot, guy);
			deck.removeCard(shoot, guy);
			deck.removeCard(shoot, guy);
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
			deck.removeCard(throww, guy);
			deck.removeCard(throww, guy);
			deck.removeCard(bleed, guy);
		}
	}
	else if (GearName == "Wand") {
		Card zap("Zap");
		if (On) {
			deck.addCard(zap);
			deck.addCard(zap);
		}
		else {
			deck.removeCard(zap, guy);
			deck.removeCard(zap, guy);
		}
	}
	else if (GearName == "Sickle") {
		Card bleed("Bleed");
		Card hack("Hack");
		Card parry("Parry");
		Card impale("Impale");
		if (On) {
			deck.addCard(bleed);
			deck.addCard(hack);
			deck.addCard(parry);
			deck.addCard(impale);
		}
		else {
			deck.removeCard(bleed, guy);
			deck.removeCard(hack, guy);
			deck.removeCard(parry, guy);
			deck.removeCard(impale, guy);
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
			deck.removeCard(shoot, guy);
			deck.removeCard(shoot, guy);
			deck.removeCard(demolish, guy);
		}
	}
	else if (GearName == "Conductive Gloves") {
		Card msmack("Magic Smack");
		if (On) {
			deck.addCard(msmack);
			deck.addCard(msmack);
		}
		else {
			deck.removeCard(msmack, guy);
			deck.removeCard(msmack, guy);
		}
	}
	else if (GearName == "Sabre") {
		Card slash("Slash");
		if (On) {
			deck.addCard(slash);
		}
		else {
			deck.removeCard(slash, guy);
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
			deck.removeCard(slice, guy);
			deck.removeCard(flay, guy);
			deck.removeCard(lash, guy);
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
			deck.removeCard(flay, guy);
			deck.removeCard(lash, guy);
			deck.removeCard(lash, guy);
			deck.removeCard(demolish, guy);
		}
	}
	else if (GearName == "Leather Gauntlets") {
		Card pummel("Pummel");
		//Card smack("Smack");
		if (On) {
			deck.addCard(pummel);
		}
		else {
			deck.removeCard(pummel, guy);
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
			deck.removeCard(pummel, guy);
			deck.removeCard(crush, guy);
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
			deck.removeCard(pummel, guy);
			deck.removeCard(bleed, guy);
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
			deck.removeCard(shoot, guy);
			deck.removeCard(shoot, guy);
			deck.removeCard(impale, guy);
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
			deck.removeCard(stab, guy);
			deck.removeCard(slice, guy);
			deck.removeCard(feint, guy);
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
			deck.removeCard(slash, guy);
			deck.removeCard(feint, guy);
		}
	}

	else if (GearName == "Greatsword") {
		Card rend("Rend");
		Card slice("Slice");
		if (On) {
			deck.addCard(rend);
			deck.addCard(rend);
			deck.addCard(slice);
		}
		else {
			deck.removeCard(rend, guy);
			deck.removeCard(rend, guy);
			deck.removeCard(slice, guy);
		}
	}
	else if (GearName == "Athame") {
		Card prick("Prick");
		Card ritual("Ritual");
		if (On) {
			deck.addCard(prick);
			deck.addCard(ritual);
		}
		else {
			deck.removeCard(prick, guy);
			deck.removeCard(ritual, guy);
		}
	}
}

void Gear::BodyOnOrOff(bool On, Character &guy, Deck &deck) {
	if (GearName == "No Armor") {
		Card endure("Endure");
		if (On) {
			deck.addCard(endure);
			deck.addCard(endure);
		}
		else {
			deck.removeCard(endure, guy);
			deck.removeCard(endure, guy);
		}
	}
	else if (GearName == "Mage Armor") {
		Card forcefield("Force Field");
		if (On) {
			deck.addCard(forcefield);
		}
		else {
			deck.removeCard(forcefield, guy);
		}
	}
	else if (GearName == "Glitter Robes") {
		Card predict("Predict");
		if (On) {
			deck.addCard(predict);
			deck.addCard(predict);
		}
		else {
			deck.removeCard(predict, guy);
			deck.removeCard(predict, guy);
		}
	}
	else if (GearName == "Riveted Chainmail") {
		Card dash("Dash");
		Card obstruct("Obstruct");
		Card bide("Bide");
		if (On) {
			deck.addCard(dash);
			deck.addCard(bide);
			deck.addCard(obstruct);
		}
		else {
			deck.removeCard(dash, guy);
			deck.removeCard(bide, guy);
			deck.removeCard(obstruct, guy);
		}
	}
	else if (GearName == "Reinforced Mail") {
		Card toughen("Toughen");
		if (On) {
			deck.addCard(toughen);
		}
		else {
			deck.removeCard(toughen, guy);
		}
	}
	else if (GearName == "Full Plate Armor") {
		Card obstruct("Obstruct");
		Card absorb("Absorb");
		if (On) {
			deck.addCard(obstruct);
			deck.addCard(obstruct);
			deck.addCard(absorb);
		}
		else {
			deck.removeCard(obstruct, guy);
			deck.removeCard(obstruct, guy);
			deck.removeCard(absorb, guy);
		}
	}
	else if (GearName == "Cape") {
		Card dodge("Dodge");
		if (On) {
			deck.addCard(dodge);
		}
		else {
			deck.removeCard(dodge, guy);
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
			deck.removeCard(dash, guy);
			deck.removeCard(flee, guy);
			deck.removeCard(disrupt, guy);
		}
	}
	else if (GearName == "Leather Hauberk") {
		Card counter("Counter");
		Card predict("Predict");
		if (On) {
			deck.addCard(counter);
			deck.addCard(predict);
		}
		else {
			deck.removeCard(counter, guy);
			deck.removeCard(predict, guy);
		}
	}
	else if (GearName == "Twilight Robes") {
		Card dash("Dash");
		Card dodge("Dodge");
		Card flee("Flee");
		if (On) {
			deck.addCard(dash);
			deck.addCard(dodge);
			deck.addCard(flee);
		}
		else {
			deck.removeCard(dash, guy);
			deck.removeCard(dodge, guy);
			deck.removeCard(flee, guy);
		}
	}
	else if (GearName == "Dragon Scales") {
		Card spikes("Spikes");
		Card predict("Predict");
		if (On) {
			deck.addCard(spikes);
			deck.addCard(spikes);
			deck.addCard(predict);
		}
		else {
			deck.removeCard(spikes, guy);
			deck.removeCard(spikes, guy);
			deck.removeCard(predict, guy);
		}
	}
	else if (GearName == "Spiked Mail") {
		Card spikes("Spikes");
		if (On) {
			deck.addCard(spikes);
			deck.addCard(spikes);
			deck.addCard(spikes);
		}
		else {
			deck.removeCard(spikes, guy);
			deck.removeCard(spikes, guy);
			deck.removeCard(spikes, guy);
		}
	}
	else if (GearName == "Buffalo Hide") {
		Card counter("Counter");
		if (On) {
			deck.addCard(counter);
			deck.addCard(counter);
		}
		else {
			deck.removeCard(counter, guy);
			deck.removeCard(counter, guy);
		}
	}
	else if (GearName == "Steel Breastplate") {
		Card obstruct("Obstruct");
		if (On) {
			deck.addCard(obstruct);
			deck.addCard(obstruct);
		}
		else {
			deck.removeCard(obstruct, guy);
			deck.removeCard(obstruct, guy);
		}
	}
	else if (GearName == "Amulet of Aura") {
		Card forcefield("Force Field");
		Card predict("Predict");
		Card repulse("Repulse");
		if (On) {
			deck.addCard(forcefield);
			deck.addCard(predict);
			deck.addCard(repulse);
		}
		else {
			deck.removeCard(forcefield, guy);
			deck.removeCard(predict, guy);
			deck.removeCard(repulse, guy);
		}
	}
	else if (GearName == "Turtle Shell") {
		Card block("Block");
		if (On) {
			deck.addCard(block);
		}
		else {
			deck.removeCard(block, guy);
		}
	}
	else if (GearName == "Crystal Breastplate") {
		Card obstruct("Obstruct");
		Card repulse("Repulse");
		if (On) {
			deck.addCard(obstruct);
			deck.addCard(obstruct);
			deck.addCard(repulse);
		}
		else {
			deck.removeCard(obstruct, guy);
			deck.removeCard(obstruct, guy);
			deck.removeCard(repulse, guy);
		}
	}
	else if (GearName == "Padded Tunic") {
		Card dash("Dash");
		if (On) {
			deck.addCard(dash);
			deck.addCard(dash);
		}
		else {
			deck.removeCard(dash, guy);
			deck.removeCard(dash, guy);
		}
	}
	else if (GearName == "Chain Mail") {
		Card defend("Defend");
		if (On) {
			deck.addCard(defend);
			deck.addCard(defend);
		}
		else {
			deck.removeCard(defend, guy);
			deck.removeCard(defend, guy);
		}
	}
	else if (GearName == "Gilded Robes") {
		Card gamble("Gamble");
		if (On) {
			deck.addCard(gamble);
			deck.addCard(gamble);
			deck.addCard(gamble);
		}
		else {
			deck.removeCard(gamble, guy);
			deck.removeCard(gamble, guy);
			deck.removeCard(gamble, guy);
		}
	}
	else if (GearName == "Wizard Garb") {
		Card inspire("Inspire");
		if (On) {
			deck.addCard(inspire);
			deck.addCard(inspire);
		}
		else {
			deck.removeCard(inspire, guy);
			deck.removeCard(inspire, guy);
		}
	}
	else if (GearName == "Cloth Shirt") {
		Card bide("Bide");
		if (On) {
			deck.addCard(bide);
			deck.addCard(bide);
		}
		else {
			deck.removeCard(bide, guy);
			deck.removeCard(bide, guy);
		}
	}
	else if (GearName == "Grass Armor") {
		Card restore("Restore");
		if (On) {
			deck.addCard(restore);
			deck.addCard(restore);
		}
		else {
			deck.removeCard(restore, guy);
			deck.removeCard(restore, guy);
		}
	}
	else if (GearName == "Flesh Suit") {
		Card form("Form");
		Card tear("Tear");
		if (On) {
			deck.addCard(form);
			deck.addCard(form);
			deck.addCard(tear);
		}
		else {
			deck.removeCard(form, guy);
			deck.removeCard(form, guy);
			deck.removeCard(tear, guy);
		}
	}
	else if (GearName == "Grey Robes") {
		Card barrier("Barrier");
		if (On) {
			deck.addCard(barrier);
		}
		else {
			deck.removeCard(barrier, guy);
	}
	}
}

void Gear::HeadOnOrOff(bool On, Character &guy, Deck &deck) {
	if (GearName == "No Headgear") {
		Card channel("Channel");
		Card blast("Blast");
		if (On) {
			deck.addCard(channel);
			deck.addCard(blast);
		}
		else {
			deck.removeCard(channel, guy);
			deck.removeCard(blast, guy);
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
		Card transmute("Transmute");
		if (On) {
			deck.addCard(leech);
			deck.addCard(leech);
			deck.addCard(transmute);
		}
		else {
			deck.removeCard(leech, guy);
			deck.removeCard(leech, guy);
			deck.removeCard(transmute, guy);
		}
	}
	else if (GearName == "Warp Goggles") {
		Card blink("Blink");
		Card hole("Singularity");
		if (On) {
			deck.addCard(blink);
			deck.addCard(blink);
			deck.addCard(hole);
		}
		else {

			deck.removeCard(blink, guy);
			deck.removeCard(blink, guy);
			deck.removeCard(hole, guy);
		}
	}
	else if (GearName == "Tundra Cap") {
		Card freeze("Freeze");
		Card shard("Shard");
		if (On) {
			deck.addCard(freeze);
			deck.addCard(shard);
			deck.addCard(shard);
		}
		else {
			deck.removeCard(freeze, guy);
			deck.removeCard(shard, guy);
			deck.removeCard(shard, guy);
		}
	}
	else if (GearName == "Plague Mask") {
		Card fumes("Fumes");
		Card incense("Incense");
		if (On) {
			deck.addCard(fumes);
			deck.addCard(incense);
		}
		else {
			deck.removeCard(fumes, guy);
			deck.removeCard(incense, guy);
		}
	}
	else if (GearName == "Dragonskin Hood") {
		Card fireball("Fireball");
		Card fuel("Fuel");
		if (On) {
			deck.addCard(fireball);
			deck.addCard(fireball);
			deck.addCard(fuel);
		}
		else {
			deck.removeCard(fireball, guy);
			deck.removeCard(fireball, guy);
			deck.removeCard(fuel, guy);
		}
	}
	else if (GearName == "Shifting Veil") {
		Card mirror("Mirror");
		Card copy("Copy");
		Card confuse("Confuse");
		if (On) {
			deck.addCard(copy);
			deck.addCard(confuse);
			deck.addCard(confuse);
		}
		else {
			deck.removeCard(copy, guy);
			deck.removeCard(confuse, guy);
			deck.removeCard(confuse, guy);
		}
	}
	else if (GearName == "Copper Cage") {
		Card lightning("Lightning");
		Card shock("Shock");
		if (On) {
			deck.addCard(lightning);
			deck.addCard(shock);
			deck.addCard(shock);
			deck.addCard(shock);
		}
		else {
			deck.removeCard(lightning, guy);
			deck.removeCard(shock, guy);
			deck.removeCard(shock, guy);
			deck.removeCard(shock, guy);
		}
	}
	else if (GearName == "Bedstone Helmet") {
		Card destroy("Destroy");
		Card construct("Construct");
		if (On) {
			deck.addCard(destroy);
			deck.addCard(construct);
			deck.addCard(construct);
		}
		else {
			deck.removeCard(destroy, guy);
			deck.removeCard(construct, guy);
			deck.removeCard(construct, guy);
		}
	}
	else if (GearName == "Glass Eye") {
		Card beam("Beam");
		Card diffract("Diffract");
		if (On) {
			deck.addCard(beam);
			deck.addCard(diffract);
		}
		else {
			deck.removeCard(beam, guy);
			deck.removeCard(diffract, guy);
		}
	}
	else if (GearName == "Laurel Wreath") {
		Card sap("Sap");
		Card synth("Synthesize");
		if (On) {
			deck.addCard(sap);
			deck.addCard(sap);
			deck.addCard(synth);
		}
		else {
			deck.removeCard(sap, guy);
			deck.removeCard(sap, guy);
			deck.removeCard(synth, guy);
		}
	}
	else if (GearName == "Diving Gear") {
		Card drown("Drown");
		Card refresh("Refresh");
		if (On) {
			deck.addCard(drown);
			deck.addCard(refresh);
		}
		else {
			deck.removeCard(drown, guy);
			deck.removeCard(refresh, guy);
		}
	}
	else if (GearName == "Makeup Set") {
		Card charm("Charm");
		Card attract("Attract");
		if (On) {
			deck.addCard(charm);
			deck.addCard(charm);
			deck.addCard(attract);
		}
		else {
			deck.removeCard(charm, guy);
			deck.removeCard(charm, guy);
			deck.removeCard(attract, guy);
		}
	}
	else if (GearName == "Safety Glasses") {
		Card reag("Reagent");
		Card react("Reactant");
		if (On) {
			deck.addCard(reag);
			deck.addCard(react);
		}
		else {
			deck.removeCard(reag, guy);
			deck.removeCard(react, guy);
		}
	}
	else if (GearName == "Golden Monocle") {
		Card mog("Transmogrify");
		Card liquidate("Liquidate");
		if (On) {
			deck.addCard(mog);
			deck.addCard(liquidate);
			//deck.addCard(liquidate);
		}
		else {
			deck.removeCard(mog, guy);
			deck.removeCard(liquidate, guy);
			//deck.removeCard(liquidate, guy);
		}
	}
	else if (GearName == "Desert Wrappings") {
		Card storm("Sandstorm");
		Card screen("Screen");
		if (On) {
			deck.addCard(storm);
			deck.addCard(screen);
			deck.addCard(screen);
		}
		else {
			deck.removeCard(storm, guy);
			deck.removeCard(screen, guy);
			deck.removeCard(screen, guy);
		}
	}
	else if (GearName == "Viking Helm") {
		Card empower("Empower");
		Card shed("Shed");
		if (On) {
			deck.addCard(empower);
			deck.addCard(empower);
			deck.addCard(shed);
		}
		else {
			deck.removeCard(empower, guy);
			deck.removeCard(empower, guy);
			deck.removeCard(shed, guy);
		}
	}
	else if (GearName == "Unholy Cowl") {
		Card extract("Extract");
		Card drain("Drain");
		if (On) {
			deck.addCard(extract);
			deck.addCard(drain);
			deck.addCard(drain);
			deck.addCard(drain);
		}
		else {
			deck.removeCard(extract, guy);
			deck.removeCard(drain, guy);
			deck.removeCard(drain, guy);
			deck.removeCard(drain, guy);
		}
	}
	else if (GearName == "Jewelled Crown") {
		Card soldier("Soldier");
		Card attack("Attack");
		if (On) {
			deck.addCard(soldier);
			deck.addCard(soldier);
			deck.addCard(attack);
		}
		else {
			deck.removeCard(soldier, guy);
			deck.removeCard(soldier, guy);
			deck.removeCard(attack, guy);
		}
	}
	else if (GearName == "Human Skull") {
		Card arise("Arise");
		Card the_flesh("The Flesh");
		if (On) {
			deck.addCard(arise);
			deck.addCard(arise);
			deck.addCard(arise);
			deck.addCard(the_flesh);
		}
		else {
			deck.removeCard(arise, guy);
			deck.removeCard(arise, guy);
			deck.removeCard(arise, guy);
			deck.removeCard(the_flesh, guy);
		}
	}
	else if (GearName == "Crystal Earrings") {
		Card rainbow("Rainbow");
		Card focus("Focus");
		if (On) {
			deck.addCard(rainbow);
			deck.addCard(focus);
		}
		else {
			deck.removeCard(rainbow, guy);
			deck.removeCard(focus, guy);
		}
	}
	else if (GearName == "Scary Face") {
		Card horrify("Horrify");
		Card lurk("Lurk");
		if (On) {
			deck.addCard(horrify);
			deck.addCard(lurk);
			deck.addCard(lurk);
		}
		else {
			deck.removeCard(horrify, guy);
			deck.removeCard(lurk, guy);
			deck.removeCard(lurk, guy);
		}
	}
	else if (GearName == "Ear Plugs") {
		Card screech("Screech");
		Card echo("Echo");
		if (On) {
			deck.addCard(screech);
			deck.addCard(echo);
			deck.addCard(echo);
		}
		else {
			deck.removeCard(screech, guy);
			deck.removeCard(echo, guy);
			deck.removeCard(echo, guy);
		}
	}
	else if (GearName == "White Halo") {
		Card judge("Judge");
		Card bless("Bless");
		if (On) {
			deck.addCard(judge);
			deck.addCard(bless);
		}
		else {
			deck.removeCard(judge, guy);
			deck.removeCard(bless, guy);
		}
	}
	else if (GearName == "Bronze Head") {
		Card aegis("Aegis");
		Card steadfast("Steadfast");
		if (On) {
			deck.addCard(aegis);
			deck.addCard(steadfast);
		}
		else {
			deck.removeCard(aegis, guy);
			deck.removeCard(steadfast, guy);
		}
	}
}


void Gear::TraitOnOrOff(bool On, Character &guy, Deck &deck, Map &map) {
	//Trait Sacrifice
	if (Type == "Trait Sacrifice") {
		SacrificeOnOrOff(On, guy, deck, map);
	}

	//Trait Reward
	else if (Type == "Trait Reward") {
		RewardOnOrOff(On, guy, deck, map);
	}

	guy.printStats();
}

void Gear::SacrificeOnOrOff(bool On, Character &guy, Deck &deck, Map &map) {
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
			guy.ModStat(-4, "Intelligence", FALSE);
			guy.ModStat(1, "Defense", FALSE);
			if (guy.Intelligence < 0)
				guy.Intelligence = 0;
		}
		else {
			guy.ModStat(4, "Intelligence", FALSE);
			guy.ModStat(-1, "Defense", FALSE);
			if (guy.Defense < 0)
				guy.Defense = 0;
		}
	}
	else if (GearName == "Mind Flooded") {
		Card ponder("Ponder");
		if (On) {
			deck.addCard(ponder);
		}
		else {
			deck.removeCard(ponder, guy);
		}
	}
	else if (GearName == "Tunnel Vision") {
		if (On) {
			guy.ModStat(-2, "Strength", FALSE);
			guy.ModStat(-2, "Defense", FALSE);
			guy.ModStat(1, "Skill", FALSE);
			if (guy.Strength < 0)
				guy.Strength = 0;
			if (guy.Defense < 0)
				guy.Defense = 0;
		}
		else {
			guy.ModStat(2, "Strength", FALSE);
			guy.ModStat(2, "Defense", FALSE);
			guy.ModStat(-1, "Skill", FALSE);
			if (guy.Skill < 0)
				guy.Skill = 0;
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
						if (x-1 != guy.posx || y != guy.posy)
							mvprintw(y, x, "?");
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
			guy.Frenzy = TRUE;
		}
		else {
			guy.Frenzy = FALSE;
		}
	}
	else if (GearName == "Corpse") {
		if (On) {
			guy.ModStat(5, "MaxHealth", FALSE);
			guy.CurrentHealth = guy.MaxHealth;
			guy.Undead = TRUE;
		}
		else {
			guy.ModStat(-5, "MaxHealth", FALSE);
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
			guy.ModStat(2, "MaxMana", FALSE);
			guy.CurrentMana = guy.MaxMana;
			guy.Forgetful = TRUE;
		}
		else {
			guy.ModStat(-2, "MaxMana", FALSE);
			guy.Forgetful = FALSE;
		}
	}

	else if (GearName == "Tiny") {
		if (On) {
			guy.ModStat(-35, "MaxHealth", FALSE);
			guy.ModStat(10, "Defense", FALSE);
			guy.CurrentHealth = guy.MaxHealth;
		}
		else {
			guy.ModStat(35, "MaxHealth", FALSE);
			guy.ModStat(-10, "Defense", FALSE);
			guy.CurrentHealth = guy.MaxHealth;
		}
	}
	else if (GearName == "Succumb") {
		if (On) {
			guy.ModStat(2, "Skill", FALSE);
			guy.Succumb = TRUE;
			Succumb = TRUE;
		}
		else {
			guy.ModStat(-2, "Skill", FALSE);
			if (guy.Skill < 0)
				guy.Skill = 0;
			guy.Succumb = FALSE;
			Succumb = FALSE;
		}
	}
	else if (GearName == "Slow") {
		if (On) {
			guy.Slow = TRUE;
		}
		else {
			guy.Slow = FALSE;
		}
	}
	else if (GearName == "Sticky Feet") {
		if (On) {
			guy.Sticky_Feet = 0;
		}
		else {
			guy.Sticky_Feet = -1;
		}
	}
	else if (GearName == "Overconfidence") {
		if (On) {
			guy.Overconfidence = 0;
			guy.ModStat(3, "Defense", FALSE);
		}
		else {
			guy.Overconfidence = -1;
			guy.ModStat(-3, "Defense", FALSE);
		}
	}
	else if (GearName == "Hallucinations") {
		if (On) {
			guy.Hallucinations = TRUE;
		}
		else {
			guy.Hallucinations = FALSE;
		}
	}
	else if (GearName == "Tail") {
		if (On) {
			guy.Tail = TRUE;
		}
		else {
			guy.Tail = FALSE;
		}
	}
	else if (GearName == "Weak Back") {
		if (On) {
			guy.Weak_Back = TRUE;
		}
		else {
			guy.Weak_Back = FALSE;
		}
	}
	else if (GearName == "Charred Skin") {
		if (On) {
			guy.Charred_Skin = TRUE;
		}
		else {
			guy.Charred_Skin = FALSE;
		}
	}
	else if (GearName == "Purple") {
		if (On) {
			guy.Purple = TRUE;
		}
		else {
			guy.Purple = FALSE;
		}
	}
	else if (GearName == "Madness") {
		Card mad("Mad");
		if (On) {
			deck.addCard(mad);
			if(guy.Cursed)
				deck.addCard(mad);
		}
		else {
			deck.removeCard(mad, guy);
			if(guy.Cursed)
				deck.removeCard(mad, guy);
		}
	}
	else if (GearName == "Inefficient") {
		if (On) {
			guy.Inefficient = 0;
		}
		else {
			guy.Inefficient = -1;
		}
	}
	else if (GearName == "Brain Worm") {
		if (On) {
			int hp = int(guy.MaxHealthBase / 2);
			guy.ModStat(-1 * hp, "MaxHealth", FALSE);
			guy.ModStat(guy.MaxManaBase, "MaxMana", FALSE);
			guy.CurrentMana = guy.MaxMana;
		}
		else {
			int mana = int(guy.MaxManaBase / 2);
			guy.ModStat(-1 * mana, "MaxMana", FALSE);
			guy.ModStat(guy.MaxHealthBase, "MaxHealth", FALSE);
			guy.CurrentHealth = guy.MaxHealth;
		}
	}
	else if (GearName == "Gold Flesh") {
		if (On) {
			guy.Gold_Flesh = TRUE;
		}
		else {
			guy.Gold_Flesh = FALSE;
		}
	}
	else if (GearName == "Terraform") {
		if (On) {
			guy.Terraform = TRUE;
		}
		else {
			guy.Terraform = FALSE;
		}
	}
	else if (GearName == "Psychosis") {
		if (On) {
			guy.Psychosis = 1;
		}
		else {
			guy.Psychosis = -1;
		}
	}
	else if (GearName == "Dazed") {
		if (On) {
			guy.Dazed = TRUE;
		}
		else {
			guy.Dazed = FALSE;
		}
	}
	else if (GearName == "Strategy") {
		if (On) {
			guy.Strategy = TRUE;
		}
		else {
			guy.Strategy = FALSE;
		}
	}
	else if (GearName == "Doomed") {
		if (On) {
			guy.Doomed = TRUE;
		}
		else {
			guy.Doomed = FALSE;
		}
	}
	else if (GearName == "Eruption") {
		if (On) {
			/*
			   ooooo
			  ooooooo
			 ooooooooo
			 ooooooooo
			 oooo@oooo
			 ooooooooo
			 ooooooooo
			  ooooooo
			   ooooo
			*/
			for (int x = guy.posx-3; x <= guy.posx+3; x++) {
				for (int y = guy.posy-3; y <= guy.posy+3; y++) {
					if (x <= 25 && x >= 0 && y <= 7 && y >= 0 &&
						(x != 25 || y != 7) &&
						rand() % 3 != 0) {
						map.terrainGrid[x][y] = "Lava";
					}
				}
			}
			for (int x = guy.posx - 2; x <= guy.posx + 2; x++) {
				if (x <= 25 && x >= 0 && guy.posy-4 <= 7 && guy.posy-4 >= 0 && rand() % 3 != 0) {
					map.terrainGrid[x][guy.posy - 4] = "Lava";
				}
				if (x <= 25 && x >= 0 && guy.posy+4 <= 7 && guy.posy+4 >= 0 && rand() % 3 != 0) {
					map.terrainGrid[x][guy.posy + 4] = "Lava";
				}
			}
			for (int y = guy.posy - 2; y <= guy.posy + 2; y++) {
				if (guy.posx-4 <= 25 && guy.posx-4 >= 0 && y <= 7 && y >= 0 && rand() % 3 != 0) {
					map.terrainGrid[guy.posx - 4][y] = "Lava";
				}
				if (guy.posx+4 <= 25 && guy.posx+4 >= 0 && y <= 7 && y >= 0 && rand() % 3 != 0) {
					map.terrainGrid[guy.posx + 4][y] = "Lava";
				}
			}
			int i = 0;
			for (int x = 0; x < 26; x++) {
				for (int y = 0; y < 8; y++) {
					map.roomList.at(i).Terrain = map.terrainGrid[x][y];
					i++;
				}
			}
			map.PrintWholeMap(guy);
		}
		else {
		}
	}
	else if (GearName == "Flash Freeze") {
		if (On) {
				for (int x = guy.posx-10; x <= guy.posx+10; x++) {
					if (x <= 25 && x >= 0 && (x != 25 || guy.posy != 7))
						map.terrainGrid[x][guy.posy] = "Ice";
				}
				for (int y = guy.posy-10; y <= guy.posy+10; y++) {
					if (y <= 7 && y >= 0 && (guy.posx != 25 || y != 7))
						map.terrainGrid[guy.posx][y] = "Ice";
				}
				int i = 0;
				for (int x = 0; x < 26; x++) {
					for (int y = 0; y < 8; y++) {
						map.roomList.at(i).Terrain = map.terrainGrid[x][y];
						i++;
					}
				}
				map.PrintWholeMap(guy);
		}
		else {
		}
	}
	else if (GearName == "Scented") {
		if (On) {
			guy.Scented = 1;
		}
		else {
			guy.Scented = -1;
		}
	}
	else if (GearName == "Colossus") {
		if (On) {
			int maxhp = guy.Strength + guy.Defense + guy.Intelligence;
			guy.ModStat(3*maxhp, "MaxHealth", FALSE);
			guy.CurrentHealth = guy.MaxHealth;
			guy.Strength = 0;
			guy.Defense = 0;
			guy.Intelligence = 0;
		}
		else {
		}
	}
	else if (GearName == "Timer") {
		if (On) {
			guy.Timer = TRUE;
		}
		else {
			guy.Timer = FALSE;
		}
	}
	else if (GearName == "Sacrificial") {
		if (On) {
			guy.Sacrificial = TRUE;
		}
		else {
			guy.Sacrificial = FALSE;
		}
	}
	else if (GearName == "Membrane") {
		if (On) {
			guy.Membrane = TRUE;
		}
		else {
			guy.Membrane = FALSE;
		}
	}
	else if (GearName == "Addiction") {
		if (On) {
			guy.ModStat(3, "Intelligence", FALSE);
			guy.Addiction = TRUE;
		}
		else {
			guy.ModStat(-3, "Intelligence", FALSE);
			guy.Addiction = FALSE;
		}
	}
	else if (GearName == "Paranoia") {
		if (On) {
			guy.Paranoia = TRUE;
		}
		else {
			guy.Paranoia = FALSE;
		}
	}
	else if (GearName == "Sticky Skin") {
		if (On) {
			guy.Sticky_Skin = TRUE;
		}
		else {
			guy.Sticky_Skin = FALSE;
		}
	}
	else if (GearName == "Asthma") {
		if (On) {
			guy.MaxEnergy += 2;
		}
		else {
			guy.MaxEnergy -= 2;
		}
	}
	else if (GearName == "Flat Feet") {
		if (On) {
			guy.Flat_Feet = TRUE;
		}
		else {
			guy.Flat_Feet = FALSE;
		}
	}
	else if (GearName == "Muscle Mass") {
		if (On) {
			guy.Muscle_Mass = 0;
		}
		else {
			guy.Muscle_Mass = -1;
		}
	}
	else if (GearName == "Chaos#") {
		Card chaos("Chaos");
		if (On) {
			deck.addCard(chaos);
			deck.addCard(chaos);
		}
		else {
			deck.removeCard(chaos, guy);
			deck.removeCard(chaos, guy);
		}
	}
	else if (GearName == "Panic Attack") {
	if (On) {
		guy.Panic_Attack = 0;
	}
	else {
		guy.Panic_Attack = -1;
	}
	}
	else if (GearName == "Cursed") {
	if (On) {
		guy.Cursed = TRUE;
	}
	else {
		guy.Cursed = FALSE;
	}
	}
	else if (GearName == "Joint Pain") {
	if (On) {
		guy.Joint_Pain = TRUE;
	}
	else {
		guy.Joint_Pain = FALSE;
	}
	}
	else if (GearName == "Daredevil") {
	if (On) {
		guy.Daredevil = TRUE;
	}
	else {
		guy.Daredevil = FALSE;
	}
	}
	else if (GearName == "Careless") {
	if (On) {
		guy.Careless = TRUE;
	}
	else {
		guy.Careless = FALSE;
	}
	}
	else if (GearName == "Hoarder") {
	if (On) {
		guy.Hoarder = TRUE;
	}
	else {
		guy.Hoarder = FALSE;
	}
	}
	else if (GearName == "Atrophy") {
	if (On) {
		guy.Atrophy = 0;
	}
	else {
		guy.Atrophy = -1;
	}
	}
	else if (GearName == "Burnout") {
	if (On) {
		guy.Burnout = guy.Skill;
	}
	else {
		guy.Burnout = -1;
	}
	}
	else if (GearName == "Blackout") {
	if (On) {
		guy.Blackout = TRUE;
	}
	else {
		guy.Blackout = FALSE;
	}
	}
	else if (GearName == "Combo Breaker") {
	if (On) {
		guy.Combo_Breaker = TRUE;
	}
	else {
		guy.Combo_Breaker = FALSE;
	}
	}
	else if (GearName == "Memory Lapse") {
	if (On) {
		guy.Memory_Lapse = TRUE;
	}
	else {
		guy.Memory_Lapse = FALSE;
	}
	}
	else if (GearName == "Stiff") {
	if (On) {
		guy.Stiff = TRUE;
	}
	else {
		guy.Stiff = FALSE;
	}
	}
	else if (GearName == "Ethereal") {
	if (On) {
		guy.Ethereal = TRUE;
	}
	else {
		guy.Ethereal = FALSE;
	}
	}
	else if (GearName == "Falter") {
	if (On) {
		guy.Falter = 0;
	}
	else {
		guy.Falter = -1;
	}
	}
	else if (GearName == "Exposed") {
	if (On) {
		guy.Exposed = 0;
	}
	else {
		guy.Exposed = -1;
	}
	}
	else if (GearName == "Circus") {
	if (On) {
		guy.Circus = TRUE;
	}
	else {
		guy.Circus = FALSE;
	}
	}
	else if (GearName == "Spiritual") {
	if (On) {
		guy.Spiritual = TRUE;
	}
	else {
		guy.Spiritual = FALSE;
	}
	}
	else if (GearName == "Stuck") {
	if (On) {
		guy.Stuck = 0;
	}
	else {
		guy.Stuck = -1;
	}
	}
	else if (GearName == "Inert") {
	if (On) {
		guy.Inert = TRUE;
	}
	else {
		guy.Inert = FALSE;
	}
	}
	else if (GearName == "Lightweight") {
	if (On) {
		guy.Lightweight = TRUE;
	}
	else {
		guy.Lightweight = FALSE;
	}
	}
	else if (GearName == "Headache") {
	if (On) {
		guy.Headache = TRUE;
	}
	else {
		guy.Headache = FALSE;
	}
	}
	else if (GearName == "Reckless") {
	if (On) {
		guy.Reckless = TRUE;
	}
	else {
		guy.Reckless = FALSE;
	}
	}
	else if (GearName == "Wasteful") {
	if (On) {
		guy.Wasteful = 1;
	}
	else {
		guy.Wasteful = -1;
	}
	}
	else if (GearName == "Strain") {
	if (On) {
		guy.Strain = TRUE;
	}
	else {
		guy.Strain = FALSE;
	}
	}
	else if (GearName == "Materialist") {
	if (On) {
		guy.ModStat(-5, "MaxMana", FALSE);
		guy.checkMax();
		guy.gainGold(50);
	}
	else {

		guy.ModStat(5, "MaxMana", FALSE);
		guy.checkMax();
		guy.gainGold(-50);
	}
	}
	else if (GearName == "Run") {
	if (On) {
		guy.Run = TRUE;
	}
	else {
		guy.Run = FALSE;
	}
	}
	else if (GearName == "Heavy") {
	if (On) {
		guy.Heavy = TRUE;
	}
	else {
		guy.Heavy = FALSE;
	}
	}
	else if (GearName == "Commitment") {
	if (On) {
		guy.Commitment = TRUE;
	}
	else {
		guy.Commitment = FALSE;
	}
	}
	else if (GearName == "Wind Down") {
	if (On) {
		guy.ModStat(-6, "MaxEnergy", FALSE);
		guy.Wind_Down = TRUE;
	}
	else {
		guy.ModStat(6, "MaxEnergy", FALSE);
		guy.Wind_Down = FALSE;
	}
	}
	else if (GearName == "Short Circuit") {
	if (On) {
		guy.Short_Circuit = TRUE;
	}
	else {
		guy.Short_Circuit = FALSE;
	}
	}
	else if (GearName == "Empty") {
	if (On) {
		guy.Empty = TRUE;
	}
	else {
		guy.Empty = FALSE;
	}
	}
	else if (GearName == "Unsteady") {
	Card stumble("Stumble");
	if (On) {
		deck.addCard(stumble);
	}
	else {
		deck.removeCard(stumble, guy);
	}
	}
	else if (GearName == "Sore") {
	if (On) {
		guy.Sore = TRUE;
	}
	else {
		guy.Sore = TRUE;
	}
	}
	else if (GearName == "Earthquake") {
	if (On) {
		for (int x = 0; x < 26; x++) {
			for (int y = 0; y < 8; y++) {
				if (map.terrainGrid[x][y] == "City")
					map.terrainGrid[x][y] = "Wasteland";
			}
		}

		int i = 0;
		for (int x = 0; x < 26; x++) {
			for (int y = 0; y < 8; y++) {
				map.roomList.at(i).Terrain = map.terrainGrid[x][y];
				i++;
			}
		}
		map.PrintWholeMap(guy);
	}
	else {
	}
	}
	else if (GearName == "") {
	if (On) {

	}
	else {

	}
	}

}

void Gear::RewardOnOrOff(bool On, Character &guy, Deck &deck, Map &map) {
	if (GearName == "Mending Flesh") {
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
			guy.ModStat(guy.Skill, "MaxMana", FALSE);
		}
		else {
			guy.Mind = FALSE;
			guy.ModStat(-guy.Skill, "MaxMana", FALSE);
		}
	}
	else if (GearName == "Matter") {
		if (On) {
			guy.Matter = TRUE;
			guy.ModStat(guy.Skill * 2, "MaxHealth", FALSE);
		}
		else {
			guy.Matter = FALSE;
			guy.ModStat(-guy.Skill * 2, "MaxHealth", FALSE);
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
			guy.Ego = TRUE;
		}
		else {
			guy.Ego = FALSE;
		}
	}
	else if (GearName == "Genius") {
		if (On) {
			guy.ModStat(2, "Intelligence", FALSE);
			guy.Genius = TRUE;
		}
		else {
			guy.ModStat(-2, "Intelligence", FALSE);
			guy.Genius = FALSE;
		}
	}
	else if (GearName == "The Box#") {
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
	else if (GearName == "Quick Thinker") {
		if (On) {
			guy.Quick_Thinker = 0;
		}
		else {
			guy.Quick_Thinker = -1;
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
			deck.removeCard(laser, guy);
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
	else if (GearName == "Scavenger") {
		if (On) {
			guy.Scavenger = 1;
		}
		else {
			guy.Scavenger = -1;
		}
	}
	else if (GearName == "Horns") {
		if (On) {
			guy.Horns = 0;
		}
		else {
			guy.Horns = -1;
		}
	}
	else if (GearName == "Green Scales") {
		if (On) {
			guy.Green_Scales = TRUE;
		}
		else {
			guy.Green_Scales = FALSE;
		}
	}
	else if (GearName == "Multi-Tongued") {
		if (On) {
			guy.Multi_Tongued = TRUE;
		}
		else {
			guy.Multi_Tongued = FALSE;
		}
	}
	else if (GearName == "Triple-Jointed") {
		if (On) {
			guy.handSize++;
		}
		else {
			guy.handSize--;
		}
	}
	else if (GearName == "Blacksmith") {
		if (On) {
			guy.Blacksmith = TRUE;
		}
		else {
		}
	}
	else if (GearName == "Iron Scabs") {
		if (On) {
			guy.Iron_Scabs = TRUE;
		}
		else {
			guy.Iron_Scabs = FALSE;
		}
	}
	else if (GearName == "Gelatinous") {
		if (On) {
			guy.Gelatinous = TRUE;
		}
		else {
			guy.Gelatinous = FALSE;
		}
	}
	else if (GearName == "Evolve") {
		if (On) {
			guy.ModStat(1, "Strength", FALSE);
			guy.ModStat(1, "Defense", FALSE);
			guy.ModStat(1, "Intelligence", FALSE);
			guy.ModStat(1, "Skill", FALSE);
			guy.ModStat(1, "MaxHealth", FALSE);
			guy.CurrentHealth = guy.MaxHealth;
			guy.ModStat(1, "MaxMana", FALSE);
			guy.CurrentMana = guy.MaxMana;
		}
		else {
			guy.ModStat(-1, "Strength", FALSE);
			guy.ModStat(-1, "Defense", FALSE);
			guy.ModStat(-1, "Intelligence", FALSE);
			guy.ModStat(-1, "Skill", FALSE);
			guy.ModStat(-1, "MaxHealth", FALSE);
			guy.ModStat(-1, "MaxMana", FALSE);
		}
	}
	else if (GearName == "Eight Legs") {
		if (On) {
			guy.Eight_Legs = TRUE;
		}
		else {
			guy.Eight_Legs = FALSE;
		}
	}
	else if (GearName == "Refine") {
		if (On) {
			guy.Void += 2;
		}
		else {
		}
	}
	else if (GearName == "Relentless") {
		if (On) {
			guy.Stay += 4;
		}
		else {
		}
	}
	else if (GearName == "Heat Walker") {
		if (On) {
			guy.Heat_Walker = TRUE;
		}
		else {
			guy.Heat_Walker = FALSE;
		}
	}
	else if (GearName == "Metamorphosis") {
		if (On) {
			int meta = guy.Strength + guy.Defense + guy.Intelligence + 2 + 1;
			guy.Metamorphosis = meta;
			guy.Strength = 0;
			guy.Defense = 0;
			guy.Intelligence = 0;
		}
		else {
			guy.Metamorphosis = 0;
		}
	}
	else if (GearName == "Thick Hide") {
		if (On) {
			guy.Thick_Hide = TRUE;
		}
		else {
			guy.Thick_Hide = FALSE;
		}
	}
	else if (GearName == "Gold Bones") {
		if (On) {
			guy.Gold_Bones = TRUE;
			guy.gainGold(25);
		}
		else {
			guy.Gold_Bones = FALSE;
		}
	}
	else if (GearName == "Absorption") {
		if (On) {
			guy.Absorption = 1;
		}
		else {
			guy.Absorption = -1;
		}
	}
	else if (GearName == "Adrenaline") {
		if (On) {
			guy.Adrenaline = 0;
		}
		else {
			guy.Adrenaline = -1;
		}
	}
	else if (GearName == "Reaper") {
		if (On) {
			guy.Reaper = TRUE;
		}
		else {
			guy.Reaper = FALSE;
		}
	}
	else if (GearName == "Toxic Release") {
		if (On) {
			guy.Toxic_Release = TRUE;
		}
		else {
			guy.Toxic_Release = FALSE;
		}
	}
	else if (GearName == "Recycling") {
		if (On) {
			guy.Recycling = 0;
		}
		else {
			guy.Recycling = -1;
		}
	}
	else if (GearName == "Blue Scales") {
		if (On) {
			guy.Blue_Scales = TRUE;
		}
		else {
			guy.Blue_Scales = FALSE;
		}
	}
	else if (GearName == "Red Scales") {
		if (On) {
			guy.Red_Scales = TRUE;
		}
		else {
			guy.Red_Scales = FALSE;
		}
	}
	else if (GearName == "Curved Tusks") {
		if (On) {
			guy.Curved_Tusks = TRUE;
		}
		else {
			guy.Curved_Tusks = FALSE;
		}
	}
	else if (GearName == "Early Riser") {
		if (On) {
			guy.Early_Riser = 0;
		}
		else {
			guy.Early_Riser = -1;
		}
	}
	else if (GearName == "Outer Shell") {
		if (On) {
			guy.Outer_Shell = TRUE;
		}
		else {
			guy.Outer_Shell = FALSE;
		}
	}
	else if (GearName == "Resourceful") {
	if (On) {
		guy.Resourceful = TRUE;
	}
	else {
		guy.Resourceful = FALSE;
	}
	}
	else if (GearName == "Naturalist") {
	if (On) {
		guy.Naturalist = TRUE;
	}
	else {
		guy.Naturalist = FALSE;
	}
	}
	else if (GearName == "Bounty Hunter") {
	if (On) {
		guy.Bounty_Hunter = 0;
	}
	else {
		guy.Bounty_Hunter = -1;
	}
	}
	else if (GearName == "Scraps") {
	if (On) {
		guy.Scraps = TRUE;
	}
	else {
		guy.Scraps = FALSE;
	}
	}
	else if (GearName == "Tinkerer") {
	if (On) {
		guy.Tinkerer = TRUE;
	}
	else {
		guy.Tinkerer = FALSE;
	}
	}
	else if (GearName == "Magnetic") {
	if (On) {
		guy.Magnetic = TRUE;
	}
	else {
		guy.Magnetic = FALSE;
	}
	}
	else if (GearName == "Merchant") {
	if (On) {
		guy.Merchant = TRUE;
	}
	else {
		guy.Merchant = FALSE;
	}
	}
	else if (GearName == "Conservation") {
	if (On) {
		guy.Conservation = 0;
	}
	else {
		guy.Conservation = -1;
	}
	}
	else if (GearName == "Vendor") {
	if (On) {
		guy.Vendor = TRUE;
	}
	else {
		guy.Vendor = FALSE;
	}
	}
	else if (GearName == "Shock Absorber") {
	if (On) {
		guy.Shock_Absorber = 0;
	}
	else {
		guy.Shock_Absorber = -1;
	}
	}
	else if (GearName == "Stamina") {
	if (On) {
		guy.Stamina = TRUE;
	}
	else {
		guy.Stamina = FALSE;
	}
	}
	else if (GearName == "Rested") {
	if (On) {
		guy.Rested = TRUE;
	}
	else {
		guy.Rested = FALSE;
	}
	}
	else if (GearName == "Midas Touch") {
	if (On) {
		guy.Midas_Touch = TRUE;
	}
	else {
		guy.Midas_Touch = FALSE;
	}
	}
	else if (GearName == "Exhaust Vent") {
	if (On) {
		guy.Exhaust_Vent = 0;
	}
	else {
		guy.Exhaust_Vent = -1;
	}
	}
	else if (GearName == "Fervor") {
	if (On) {
		guy.Fervor = 0;
	}
	else {
		guy.Fervor = -1;
	}
	}
	else if (GearName == "Enlightened") {
	if (On) {
		guy.Enlightened = TRUE;
	}
	else {
		guy.Enlightened = FALSE;
	}
	}
	else if (GearName == "Engorged") {
	if (On) {
		guy.Engorged = TRUE;
	}
	else {
		guy.Engorged = FALSE;
	}
	}
	else if (GearName == "Archmage") {
	if (On) {
		guy.Archmage = TRUE;
	}
	else {
		guy.Archmage = FALSE;
	}
	}
	else if (GearName == "Rebirth") {
	if (On) {
		guy.Rebirth = TRUE;
	}
	else {
		guy.Rebirth = FALSE;
	}
	}
	else if (GearName == "Heavyweight") {
	if (On) {
		guy.Heavyweight = TRUE;
	}
	else {
		guy.Heavyweight = FALSE;
	}
	}
	else if (GearName == "Deja Vu") {
	if (On) {
		guy.Deja_Vu = TRUE;
	}
	else {
		guy.Deja_Vu = FALSE;
	}
	}
	else if (GearName == "Concentration") {
	if (On) {
		guy.Concentration = 0;
	}
	else {
		guy.Concentration = -1;
	}
	}
	else if (GearName == "Reversal") {
	if (On) {
		guy.Reversal = TRUE;
	}
	else {
		guy.Reversal = FALSE;
	}
	}
	else if (GearName == "Amass") {
	if (On) {
		guy.Amass = 0;
	}
	else {
		guy.Amass = -1;
	}
	}
	else if (GearName == "Technician") {
	if (On) {
		guy.Technician = TRUE;
	}
	else {
		guy.Technician = FALSE;
	}
	}
	else if (GearName == "Optimist") {
	if (On) {
		guy.Optimist = TRUE;
	}
	else {
		guy.Optimist = FALSE;
	}
	}
	else if (GearName == "Stockpile") {
	if (On) {
		guy.Stockpile = TRUE;
	}
	else {
		guy.Stockpile = FALSE;
	}
	}
	else if (GearName == "Draining Touch") {
	if (On) {
		guy.Draining_Touch = TRUE;
	}
	else {
		guy.Draining_Touch = FALSE;
	}
	}
	else if (GearName == "Fleet of Foot") {
	if (On) {
		guy.Fleet_of_Foot = TRUE;
	}
	else {
		guy.Fleet_of_Foot = FALSE;
	}
	}
	else if (GearName == "Gold Claws") {
	if (On) {
		guy.Gold_Claws = TRUE;
	}
	else {
		guy.Gold_Claws = FALSE;
	}
	}
	else if (GearName == "Gold Scales") {
	if (On) {
		guy.Gold_Scales = TRUE;
	}
	else {
		guy.Gold_Scales = FALSE;
	}
	}
	else if (GearName == "Gold Brain") {
	if (On) {
		guy.Gold_Brain = TRUE;
	}
	else {
		guy.Gold_Brain = FALSE;
	}
	}
	else if (GearName == "Phlogiston") {
	if (On) {
		guy.Phlogiston = TRUE;
	}
	else {
		guy.Phlogiston = FALSE;
	}
	}
	else if (GearName == "Momentum") {
	if (On) {
		guy.Momentum = TRUE;
	}
	else {
		guy.Momentum = FALSE;
	}
	}
	else if (GearName == "Dynamic") {
	if (On) {
		guy.Dynamic = 0;
	}
	else {
		guy.Dynamic = -1;
	}
	}
	else if (GearName == "") {
	if (On) {

	}
	else {

	}
	}
}

void Gear::CardOnOrOff(bool On, Character &guy, Deck &deck) {
	vector<Card> bosss;
	bosss.push_back(Card("Haste"));
	bosss.push_back(Card("Revivify"));
	bosss.push_back(Card("Change Mind"));
	bosss.push_back(Card("Intimidate"));
	bosss.push_back(Card("Boost"));
	bosss.push_back(Card("Vitalise"));
	bosss.push_back(Card("Slam"));
	bosss.push_back(Card("Stall"));
	bosss.push_back(Card("Steroids"));
	bosss.push_back(Card("Distract"));
	bosss.push_back(Card("Prepare"));
	bosss.push_back(Card("Jump"));
	bosss.push_back(Card("Repel"));
	bosss.push_back(Card("Ghost"));
	bosss.push_back(Card("Catalyze"));
	bosss.push_back(Card("Detonate"));
	bosss.push_back(Card("Polymorph"));
	bosss.push_back(Card("Cleanse"));
	bosss.push_back(Card("Teleport"));
	bosss.push_back(Card("Inject"));
	bosss.push_back(Card("Flurry"));
	bosss.push_back(Card("Materialize"));
	bosss.push_back(Card("Overdrive"));
	bosss.push_back(Card("Enrich"));
	bosss.push_back(Card("Shimmer"));
	bosss.push_back(Card("Relax"));
	bosss.push_back(Card("Sharpen"));
	bosss.push_back(Card("Amplify"));
	bosss.push_back(Card("Cell"));
	bosss.push_back(Card("Deflect"));
	bosss.push_back(Card("Save"));
	bosss.push_back(Card("Stop"));
	bosss.push_back(Card("Mend"));
	bosss.push_back(Card("Chaos"));

	int index = 0;
	for (int i = 0; i < bosss.size(); i++) {
		if (bosss.at(i).CardName == GearName) {
			if (On) {
				deck.addCard(bosss.at(i));
			}
			else {
				deck.removeCard(bosss.at(i), guy);
			}
			break;
		}
	}
	
	/*if (GearName == "Revivify") {
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
	}*/

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
	//init_pair(10, COLOR_BLUE, COLOR_BLACK);
	init_color(COLOR_BLUE, 200, 400, 1000);
	attron(COLOR_PAIR(6));
	if (Type == "Trait Sacrifice")
		attron(COLOR_PAIR(5));
	else if (Type == "Trait Reward")
		attron(COLOR_PAIR(7));
	int addx = int(strlen(GearName) / 2);
	int gy = 19;
	if (Type == "Trait Sacrifice" || Type == "Trait Reward")
		gy = 17;
	const char* car;
	switch (position) {
	case 1:
		manualBox("Card 1", 0);
		car = GearName;
		mvprintInSize(gy, 12-addx, 15, car, FALSE);
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
			else {
				car = Description;
				mvprintInSize(19, 4, 15, car, FALSE);
			}
		}
		break;
	case 2:
		manualBox("Card 2", 0);
		car = GearName;
		mvprintInSize(gy, 31-addx, 15, car, FALSE);
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
			else {
				car = Description;
				mvprintInSize(19, 24, 15, car, FALSE);
			}
		}
		attroff(COLOR_PAIR(10));
		if (Type != "Trait Sacrifice" && Type != "Trait Reward")
			mvprintw(22, 22, "(P)ickup  (I)gnore");
		break;
	case 3:
		manualBox("Card 3", 0);
		car = GearName;
		mvprintInSize(gy, 52-addx, 15, car, FALSE);
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
			else {
				car = Description;
				mvprintInSize(19, 44, 15, car, FALSE);
			}
		}
		break;

	}
	standend();
}
