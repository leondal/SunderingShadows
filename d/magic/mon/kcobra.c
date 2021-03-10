//kcobra.c

#include "summoned_monster.h"

inherit WEAPONLESS;

void create(){
	::create();
	set_name("king cobra");
	set_id(({"cobra","Cobra","snake","king","king cobra"}));
	set_short("snake");
	set_long(
@OLI
	This snake is a long broadly hooded creature. It has long
fangs protruding from its mouth. Small in size you are sure it 
can still hurt you.
OLI
	);
	set_hd(5,1);
	set_hp(16);
	set_body_type("snake");
	set_damage(1,3);
	set_attacks_num(1);
	set_attack_limbs(({"fangs"}));
	set_hit_funcs((["fangs":(:TO,"poison":)]));
	set_base_damage_type("piercing");
	set_gender("male");
	set_race("snake");
	set_exp(800);
	set_alignment(5);
	set_overall_ac(4);
}

int poison(object targ){
	tell_object(targ,"%^BOLD%^%^RED%^The bite of this snake sends fear through you body!\n");
	if("daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death",2))
		return 0;
	
	tell_player(targ,"%^BOLD%^%^RED%^You feel the horrid poison filter into your blood. Death is at hand!");
	targ->add_poisoning(10);
	return 12;
}
