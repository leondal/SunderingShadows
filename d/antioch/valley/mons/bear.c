//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create(){
      object ob;
	::create();
	set_name("bear");
	set_id(({"bear","cave bear","monster","animal"}));
	set_short("Cave bear");
	set_long(
	"The cave bear is very large and looks strong. His fur is"+
	" a dark brown and is a bit dirty. Several straight scars"+
	" cutting through his fur are probably marks from other"+
	" adventurers unlucky enough to have stumbled upon this"+
	" rather angry animal. He growls and rears up to attack"+
	" you, showing his teeth and bellowing loudly. His claws"+
	" are sharp and a good swipe with one could probably take"+
	" anyone's head off."
	);
	set_race("bear");
	set_body_type("quadruped");
	set_hd(15,8);
	set_max_level(20);
	set_gender("male");
	set_alignment(5);
	set_overall_ac(6);
	set_size(3);
	set_max_hp(random(60)+200);
	set_hp(query_max_hp());
	set_level(15);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("strength",20);
	add_limb("mouth","head",0,0,0);
	set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
	set_attacks_num(3);
	set_base_damage_type("slashing");
	set_damage(1,8);
	set_hit_funcs(([
		"mouth":(:TO,"bite":),
		"left forepaw":(:TO,"hug":)
	]));
	set("aggressive",25);
	set_property("swarm",1);
//	set_exp(5400);
      set_new_exp(15,"normal");
	set_emotes(10,({
	"The cave bear growls at you.",
	"The cave bear roars ferociously.",
	"The cave bear swipes at you with his paw.",
	}),1);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

int bite(object targ)
{
	targ->do_damage("torso",random(4)+1);
	return 1;
}

int hug(object targ)
{
	int roll;

	roll = random(20);
	if(roll > 17) {
		tell_object(targ,"%^BOLD%^The cave bear pulls you in for"+
		" a bone-crushing hug!");
		tell_room(ETO,"The cave bear pulls "+targ->query_cap_name()+""+
		" in for a bone-crushing hug!");
		targ->do_damage("torso",random(16)+2);
		return 1;
	}
	else {
		return 1;
	}
}
