//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create(){
      object ob;
	::create();
	set_name("gorilla bear");
	set_id(({"gorilla bear","bear","gorilla","monster","magical beast"}));
	set_short("An unpredictable gorilla bear");
	set_long(
	"This beast has the head, body, and legs of a gorilla mixed"+
	" with the sharp teeth and strong arms of a bear, making for"+
	" a deadly combination. The beast also has a volatile temper"+
	" and carnivorous tendencies. This is definitely a creature"+
	" to avoid messing with.");
	set_race("gorilla bear");
	set_gender("male");
	set_body_type("quadruped");
	set_hd(15,6);
	set_max_level(25);
	set_overall_ac(4);
	set_alignment(8);
	set_max_hp(random(40)+130);
	set_hp(query_max_hp());
	set_attack_limbs(({"right forepaw","left forepaw"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(1,8);
	set_hit_funcs((["right forepaw":(:TO,"hug":)]));
//	set_exp(13500);
	set_new_exp(15,"normal");
	set_level(20);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("strength",20);
	set_stats("intelligence",4);
	set_stats("dexterity",25);
	set("aggressive",20);
	set_property("swarm",1);
   set_property("no bows",1);
	set_emotes(5,({
	"The gorilla bear bellows loudly!",
	"The gorilla bear beats his fists against his chest.",
	"The gorilla bear glares at you.",
	}),1);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

int hug(object targ)
{
	int roll,ac;

	roll = random(20);
	ac = targ->query_ac();

	if(roll == 20) {
		tell_object(targ,"The gorilla bear grabs you and wraps"+
		" you in a crushing hug!");
		tell_room(ETO,"The gorilla bear grabs "+targ->query_cap_name()+""+
		" and wraps "+targ->query_objective()+" in a crushing hug!",targ);
		targ->do_damage(random(7)+6);
	}
	else if(roll > 10-ac) {
		tell_object(targ,"The gorilla bear grabs you and wraps"+
		" you in a crushing hug!");
		tell_room(ETO,"The gorilla bear grabs "+targ->query_cap_name()+""+
		" and wraps "+targ->query_objective()+" in a crushing hug!",targ);
		targ->do_damage(random(7)+6);
	}
	else {
		tell_object(targ,"The gorilla bear attempts to grab you"+
		" and you manage to dodge out of the way.");
		tell_room(ETO,"The gorilla bear makes a grab at "+targ->query_cap_name()+","+
		" but "+targ->query_subjective()+" dodges.",targ);
	}
}
