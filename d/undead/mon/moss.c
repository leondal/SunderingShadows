#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create()
{
    object ob;
    ::create();
    set_name("moss");
    set_id(({"moss"}));
    set_short("Moss");
    set_hd(30,1);
    set_hp(1000000);
    set_exp(10);
	set_body_type("human");
    set_class("cleric");
    set_guild_level("cleric",40);
	set_spell_chance(0);
    set_race("moss");
	set_gender("male");
	set_overall_ac(0);
	set_alignment(9);
    set_mob_magic_resistance("average");
    set_true_invis();	
}

void heart_beat()
{
	::heart_beat();
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
	
    if(present("corpse",ETO))
    {
		"cmds/spells/a/_animate_dead"->use_spell(TO,"corpse",30,100,"mage");
        return;
	}
}
