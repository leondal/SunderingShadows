#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create()
{
    object ob;
	::create();
    set_name("Gwendyln");
    set_id(({"gwendyln","sister","sister of fate","fate"}));
    set_short("%^RED%^Gwendyln, a sister of fate%^RESET%^");
	set_long("Gwendyln is short and fat, covered in warts, and missing most of her "
        "hair. She still has one good tooth which juts out against her best "
        "efforts to keep it hidden. Despite her hideousness it is obvious "
        "she wields a power of the oldest, blackest, order. She should not "
        "be taken lightly, for combined with her other two sisters she is "
        "truly a force to fear.");
    set_hd(25,1);
    set_hp(400);
    set_exp(40000);
    set_new_exp(25,"boss");
	set_body_type("human");
	set_class("mage");
    set_guild_level("mage",25);
    set_property("swarm",1);
	set_spells(({"magic missile","scorcher","hideous laughter","lightning bolt","fireball"}));
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





