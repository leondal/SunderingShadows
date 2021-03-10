
//monsters by the House of Svaha

#include <std.h>

inherit MONSTER;

void create() {
	int resist;
::create();


set_name("lammasu");
set_id(({"lammasu"}));
set_short("%^ORANGE%^lammasu");
set_long(
@DESC
%^ORANGE%^This creature seems to be a combination of many things, a head
of a human, with a lions mane, legs and tail, and the wings of a great
eagle.  The colouring of the body is tawny, but the wings are bold greys,
pure whites and deepest blacks.  It is in the nature of these animals to 
aid and protect lawful good persons, and they are of generally kind and
friendly disposition to all good creatures.  However, the talons, and 
teeth make good fighting weapons, and the creature is magical as well.
DESC
);

set("race", "lammasu");
set_gender("male");
set_body_type("quadruped");
set_size(3);
set_level(20);
set_class("mage");
set_alignment(1);
set("aggressive",20);

set_stats("strength", 19);
set_stats("intelligence",25);
set_stats("wisdom",20);
set_stats("dexterity",20);
set_stats("constitution",18);
set_stats("charisma",18);

set_hd(21,21);
set_hp(300);

set_overall_ac(6);

resist = 30 + random(30) + random(30);
set_property("magical resistance", resist);
set_guild_level("mage", 10);
set_spell_chance(75);
set_spells(({"monster summoning vii", "dispel magic"}));

set_wielding_limbs( ({"right forepaw", "left forepaw", "head"}) );
new("/d/dagger/Elvanta/forest/items/wpns/claw")->move(this_object());
command("wield claw in right forepaw");
new("/d/dagger/Elvanta/forest/items/wpns/claw")->move(this_object());
command("wield claw in left forepaw");


add_money("gold", (1000));


}


