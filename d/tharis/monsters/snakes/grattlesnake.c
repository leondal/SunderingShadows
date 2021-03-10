//grattlesnake.c

#include <std.h>

inherit WEAPONLESS;

void create(){
	::create();
	set_name("giant rattle snake");
	set_id(({"rattler","rattle snake","Rattler","snake","giant"}));
   set_short("A giant rattle snake");
	set_long(
@OLI
   This snake has a rattler at the end of its tail. It has long
fangs protruding from its mouth. The size of the snke intimidates you.
OLI
	);
	set_hd(6,1);
	set_hp(40);
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
	set_overall_ac(6);
}

int poison(object targ){
	tell_object(targ,"%^BOLD%^%^RED%^The bite of this snake sends fear through you body!\n");
	if("daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death",2))
		return 0;
	
	tell_player(targ,"%^BOLD%^%^RED%^You feel the horrid poison filter into your blood. Death is at hand!");
	targ->add_poisoning(8);
	return 14;
}
