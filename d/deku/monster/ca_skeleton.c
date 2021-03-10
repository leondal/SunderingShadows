#include <std.h>

inherit "/d/deku/monster/skeleton.c";

void create() 
{
  	::create();
  	set_hp(query_hp() * 2);
	set_guild_level("fighter", 30);
	set_mlevel("fighter", 30);
	set_exp(5000);
	set_hp(320 + random(100));
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
	set_overall_ac(-8);
	set_max_level(40);
}
