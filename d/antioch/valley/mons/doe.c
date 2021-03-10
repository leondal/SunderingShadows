//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit WEAPONLESS;

void create()
{
   ::create();
   set_name("doe");
   set_short("A gentle doe");
   set_id(({"monster","doe","gentle doe","animal"}));
   set_long("This is a very docile doe that is probably at least two"+
   " or three years old, although you don't see any young near her"+
   " at the moment. She has a spotted rump and a cute little white"+
   " tail. Her face is quite delicate and she also sports a set of"+
   " small antlers. Her hooves are black and hard, and she seems"+
   " ready to run away at the first sign of trouble.");
   set_race("deer");
   set_gender("female");
   set_body_type("equine");
	set_hd(10,8);
	set_max_level(20);
	add_limb("antlers","head",0,0,0);
	set_attack_limbs(({"antlers","right front hoof","left front hoof"}));
	set_attacks_num(3);
	set_base_damage_type("bludgeoning");
	set_damage(1,10);
	set_alignment(8);
	set_overall_ac(7);
	set_max_hp(random(30)+100);
	set_hp(query_max_hp());
	set_level(13);
	set_class("fighter");
	set_mlevel("fighter",10);
//	set_exp(1500);
	set_new_exp(10,"low");
	set_property("swarm",1);
}
