//bbear.c

#include <std.h>

inherit WEAPONLESS;

void create(){
	::create();
	set_name("black bear");
	set_id(({"bear","black bear","bbear"}));
	set_short("A black bear");
	set_long(
@OLI
	This is a large black bear. You can see the light glisten off 
its sleek black coat. You can see the muscles ripple through its
back as it moves. A powerfull creature, capable of shreading small 
trees, you realize that it is truly gentle at heart.
OLI
	);
	set_attacks_num(3);
	set_damage(1,5);
	set_base_damage_type("slashing");
	set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
	set_hd(10,8);
	set_hp(50);
	set_exp(950);
add_money("silver", 500);
	set_body_type("quadruped");
	set_race("bear");
	set_gender("female");
	set_funcs(({"hug"}));
	set_func_chance(102);
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
