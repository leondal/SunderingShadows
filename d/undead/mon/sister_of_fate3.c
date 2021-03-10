#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create()
{
	object ob;
	::create();
    set_name("Percy");
    set_id(({"percy","sister","sister of fate","fate"}));
    set_short("%^MAGENTA%^Percy, a sister of fate%^RESET%^");
	set_long("Percy is about average hight, with sharp, almost elfish features.  "
        "She has small shifty eyes and a wicked kind of smirk that sends a "
        "chill running up your back. She is obviously the eldest sister and "
        "the one in charge here. Not that that is good news for you.");
	set_hd(25,1);
    set_hp(400);
    set_exp(40000);
    set_new_exp(25,"boss");
	set_body_type("human");
	set_class("mage");
    set_guild_level("mage",25);
    set_property("swarm",1);
    set_spells(({ "hold person","magic missile","hideous laughter","lightning bolt","ray of enfeeblement"}));
    set_spell_chance(100);
    set_race("human");
    set_gender("female");
	set_overall_ac(0);
	ob = new("/d/magic/scroll");
    ob->set_spell(5);
	ob->move(TO);
	set_alignment(9);
	set_mob_magic_resistance("average");
}
