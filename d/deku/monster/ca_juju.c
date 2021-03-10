#include <std.h>
inherit "/d/deku/monster/juju.c";

void create() 
{
	::create();
	set_guild_level("fighter", 30);
	set_mlevel("fighter", 30);
	set_hp(320 + random(20));
	set_exp(5400);
	set_property("weapon resistance", 2);
	set_mob_magic_resistance("average");
	add_money("gold", random(1000));
	if(!random(5))
	{
		if(present("sword", TO)) 
		{
			present("sword", TO)->set_property("enchantment", 3);
		}
	}
	if(!random(5))
	{
		if(present("sword 2", TO))
		{
			present("sword 2", TO)->set_property("enchantment", 3);
		}
	}
	set_overall_ac(-10);
	set_max_level(40);
}

