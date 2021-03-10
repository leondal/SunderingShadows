#include <std.h>
inherit "/d/deku/fortress/monster/ghoul.c";

void create() 
{
	::create();
	set_moving(0);
	set_speed(0);
	set_guild_level("fighter", 30);
	set_mlevel("fighter", 30);
	set_hp(280 + random(40));
	//set_exp(8000);
	set_property("weapon resistance", 2);
	set_mob_magic_resistance("average");
	set_property("magic", 1);
	add_money("gold", random(500));
	set_damage(2,6);
	set_attacks_num(4);
	set_overall_ac(-10);
	set_max_level(40);
	set_stats("strength", 19);
}

