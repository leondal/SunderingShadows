#include <std.h>

inherit MONSTER;

void create() {
	::create();
	set_name("orc guard");
	set_id(({"guard","orc"}));
	set_short("Orc guard");
	set_long("
This is an orc guard.
	");
	set_level(10);
	set_race("orc");
	set_gender("male");
	set_property("swarm",1);
	set_overall_ac(6);
	add_money("silver",random(5));
	set_body_type("human");
	set_class("fighter");
	set_stats("strength",10);
	set_stats("dexterity",10);
	set("aggressive","aggfunc");
	set_wielding_limbs( ({"right arm","left arm"}) );
	set_max_hp(650);
	set_hp(650);
	set_skill("melee",50);
	set_exp(15000);
	set_exp(500);
	set_alignment(9);
}
