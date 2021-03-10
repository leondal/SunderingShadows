//First level of the catacombs has basically 
//the same mobs (except for a few) as the graveyard.
//just a stronger version of said mobs - Saide

#include <std.h>
inherit "/d/deku/monster/babu.c";

void create() 
{
  	::create();
  	set_hp(query_hp() * 2);
	set_max_hp(query_hp());
	set_spell_chance(50);
	set_attacks_num(4);
	set_max_level(40);
	//set_exp(8000);
	set_mlevel("fighter", 30);
	set_guild_level("fighter", 30);
	set_mlevel("mage", 30);
	set_guild_level("mage", 30);
	set_money("gold", 300 + random(100));
	if(!random(5))
	{
		if(present("leather", TO))
		{
			present("leather", TO)->set_property("enchantment", 3);
		}
	}	
	set_overall_ac(-5);
	set_stats("strength", 18);
	set_stats("intelligence", 20);
}

