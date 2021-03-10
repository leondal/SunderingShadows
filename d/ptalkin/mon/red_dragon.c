
//monsters by the house of Svaha
#include <std.h>

inherit MONSTER;
void init() {
	::init();
	add_action("get_func", "get");
}

void create() {
int resist;
	::create();

set_name("%^BOLD%^RED%^Bazzburr, the red dragon");
set_id(({"dragon", "red dragon", "Bazzburr", "bazzburr"}));
set_short("%^BOLD%^RED%^The Red Dragon, Bazzburr");
set_long("%^BOLD%^RED%^Bazzburr, one of the oldest, living, evil dragons
ever to roam this realm.  When he stands, he is close to forty feet
tall, with a wingspan of well over fifty feet.  Large, curved, jagged
teeth fill a maw with danger.  Scales of ruby red, cover a body one
hundred feet in length with an armour impossible to penetrate. Eyes
glowing black, gaze at you with deadly malice.  Razor sharp talons, 
three to a foot, glimmer with a silver undertone and a tail ends with
deadly sharp scales.");

set_race("dragon");
set_body_type("dragon");
set_gender("male");
set_size(3);
set_class("mage");
set("aggressive", 50);
set_alignment(9);
set_overall_ac(-5);

set_stats("intelligence", 25);
set_stats("wisdom", 25);
set_stats("strength", 25);
set_stats("charisma", 25);
set_stats("dexterity", 25);
set_stats("constitution", 25);

set_hd(20,6);
set_exp(25000);
set_hp(250);

set_wielding_limbs( ({"right foreclaw", "left foreclaw", "head"}) );
new("/realms/general/weapons/dragonclaw")->move(this_object());
new("realms/general/weapons/dragonclaw")->move(this_object());
new("/realms/general/weapons/dragonteeth")->move(this_object());
command("wield claw in right foreclaw");
command("wield claw 2 in left foreclaw");
command("wield teeth in head");

resist = 30 + random(30) + random(30);
set_property("magical resistance", resist);
set_guild_level("mage", 20);
set_spell_chance(70);
set_spells(({"chain lightning", "flaming sphere"}));

add_money("gold", (5000));
add_money("silver", (3500));
add_money("copper", (4000));

set_emotes(1, ({
"%^BOLD%^RED%^the dragon whispers : Who disturbeth my slumber?",
"%^BOLD%^RED%^the dragon croons : my treasure, my beautiful treasure"
}), 0);

set("aggressive", "attack_fun");
set_emotes(20, ({
"%^BOLD%^RED%^the dragon roars : YOU WANT MY GOLD!",
"%^BOLD%^RED%^the dragon snickers : Come and get it you fool!"
}), 1);

}

void reset() {
object ob;
::reset();
if(!present("scroll")){
ob = new("/d/magic/scroll");
ob->set_spell_name("finger of death");
ob->move(this_object());
}

}
int get_func(string str) {
	write("%^BOLD%^RED%^The dragon roars : You cannot have my treasure while I am alive");
	return 1;
}
