#include <std.h>

inherit "/std/weaponless_monsters";

void create(){
  ::create();
  set_name("polar bear");
  set_id(({"bear","polar bear"}));
  set_short("Large polar bear");
  set_long("
This is a large polar bear.  You notice the muscles of this beast ripple
through its body as it moves.  This is a mysterious creature, who from
stories long told is very powerful.");
  set_attacks_num(3);
  set_damage(1,8);
  set_base_damage_type("slashing");
  set_hd(11,9);
  set_hp(105);
  set_exp(1350);
  set_body_type("quadruped");
  set_attack_limbs(({"right forpaw","left forepaw","mouth"}));
  set_stats("strength", 18);
  set_race("bear");
  set_gender("male");
  set_funcs(({"hug"}));
  set_func_chance(85);
}

void hug(object targ){
	set_func_chance(0);
	execute_attack();
	set_func_chance(102);
	if(roll_dice(1,20) > 17){
		tell_room(ETO,"%^BOLD%^The bear lands a paw so firmly that it lifts "+targ->query_cap_name()+" in a great hug!",targ);
		tell_object(targ,"%^BOLD%^The bear snags you with a great paw and lifts you in a great bear hug!\n");
		targ->do_damage(targ->return_target_limb(),roll_dice(2,8));
	}
}
