//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit V_WANDER;

void create(){
      object ob;
	::create();
	set_name("wild dog");
	set_id(({"wild dog","dog","monster","cunning dog"}));
	set_short("A cunning dog");
	set_long(
	"The dog looks almost like a wolf. His coat is a thick gray"+
	" with swirls of black. There are a couple scratches on his"+
	" hide, but he looks like he's well fed. His hackles are raised"+
	" and you can see vicious teeth beneath his lips as he stares"+
	" warily at you."
	);
	set_gender("male");
	set_race("dog");
	set_body_type("quadruped");
	set_hd(15,4);
	set_max_level(20);
	set_alignment(5);
	set_max_hp(random(75)+50);
	set_hp(query_max_hp());
	set_overall_ac(7);
	set_level(12);
	set_class("fighter");
	set_mlevel("fighter",15);
//	set_exp(330);
	set_new_exp(15,"normal");
	set_property("swarm",1);
	set_attack_limbs(({"right forepaw","left forepaw"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(1,4);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
