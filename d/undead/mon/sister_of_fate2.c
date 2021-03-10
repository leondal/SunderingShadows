#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create()
{
	object ob;
	::create();
    set_name("Mina");
    set_id(({"mina","sister","fate","sister of fate"}));
    set_short("%^BOLD%^%^BLUE%^Mina, a sister of fate%^RESET%^");
	set_long("Mina is tall and lanky, almost all bones and no muscle. She has a "
        "long prodruding nose that threatens to reach out and poke you. She, "
        "like her sisters is hideously ugly, but like most things in these "
        "realms, she is not one to be underestimated.");
    set_hd(25,1);
    set_hp(400);
    set_exp(40000);
    set_new_exp(25,"boss");
	set_body_type("human");
	set_class("mage");
    set_guild_level("mage",25);
    set_property("swarm",1);
    set_spells(({"lower resistance","scorcher","fireball","wall of fire",}));
    set_spell_chance(100);
    set_race("human");
    set_gender("female");
	set_overall_ac(0);
	ob = new("/d/magic/scroll");
    ob->set_spell(5);
	ob->move(TO);
    new(OBJS"eyeball.c")->move(TO);
    command("wear eye");
	set_alignment(9);
	set_mob_magic_resistance("average");
	
}



