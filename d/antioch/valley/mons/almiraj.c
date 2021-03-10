//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit V_WANDER;

void create(){
      object ob;
	::create();
	set_name("al-mi'raj");
	set_id(({"al-mi'raj","al-mi`raj","al mi raj","bunny","monster","rabbit","aberration","al mi`raj","al mi'raj","al-mi raj","hare","almiraj"}));
	set_short("A cute little al-mi'raj");
	set_long(
	"This odd looking creature looks like a strange cross between"+
	" a bunny rabbit and a unicorn. It has the body of a bunny right"+
	" down to the cute little white tail, but with a large black"+
	" spiral horn protruding from the center of its forehead."
	);
	set_gender("male");
	set_race("al-mi'raj");
	set_body_type("quadruped");
	add_limb("horn","head",0,0,0);
	set_hd(10,1);
	set_max_level(20);
	set_attack_limbs(({"horn"}));
	set_attacks_num(1);
	set_base_damage_type("piercing");
	set_damage(2,4);
	set_alignment(5);
	set_overall_ac(6);
//	set_exp(90);
      set_new_exp(10,"low");
	set_level(10);
	set_class("fighter");
	set_mlevel("fighter",10);
	set_max_hp(random(25)+50);
	set_hp(query_max_hp());
	set_property("swarm",1);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
