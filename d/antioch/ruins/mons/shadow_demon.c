#include <std.h>
#include "../ruins.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("shadow demon");
	set_short("A horrible shadow demon");
	set_id(({"demon","shadow demon","shadow_demon","horrible shadow demon"}));
	set_long(
	"The shadow demon is a terrifying beast indeed! It is made of a semi-solid"+
	" smoke like substance, and is blacker than ebony. It is about six feet"+
	" tall and has glowing red eyes and large claws in place of hands. It has"+
	" a vaguely humanoid figure, but could never pass as human."
	);
	set_race("demon");
	set_gender("male");
	set_body_type("humanoid");
	set_hd(20,20);
	set_alignment(9);
	set_overall_ac(-15);
	set_max_hp(200+random(50));
	set_hp(query_max_hp());
	set_class("fighter");
	set_mlevel("fighter",20);
	set_level(20);
	set_stats("strength",25);
	remove_limb("right hand");
	remove_limb("left hand");
	add_limb("right claw","right arm",0,0,0);
	add_limb("left claw","left arm",0,0,0);
	set_attack_limbs(({"right claw","left claw"}));
	set_base_damage_type("slashing");
	set_attacks_num(2);
	set_damage(1,10);
	set_exp(6000);
	set_property("swarm",1);
	set_property("magic",1);
    set_resistance("electricity",10);
}
