//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"rohch","Rohch","Dark Rohch"}));
    set_name("Dark Rohch");
    set_short("A dark Rohch");
    set_long(
	"This beast is the crossbreed of a wolf and a large beetle. "+
	"Its body is covered in a mix of tough carapace and tufts of "+
	"fur. Its head appears wolf-like, with beetle pincers "+
	"protruding from the lower jaw and a carapace covering "+
	"the top of its skull. Six jagged claws extend from this "+
	"horrid creatures back."
    );
    set_body_type("quadruped");
    set_race("rohch");
    set_gender("male");
    set_size(1);
    set_alignment(9);
    set_hd(8,11);
    set_hp(75);
    set_exp(2000);
    set_overall_ac(1);
    set_property("swarm",1);
    add_limb("claw1", "torso", 0, 0, 0);
    add_limb("claw2", "torso", 0, 0, 0);
    add_limb("claw3", "torso", 0, 0, 0);
    add_limb("claw4", "torso", 0, 0, 0);
    add_limb("claw5", "torso", 0, 0, 0);
    add_limb("claw6", "torso", 0, 0, 0);
    set("aggressive",18);
    set_attack_limbs(({"claw1","claw2","claw3","claw4","claw5","claw6"}));
    set_attacks_num(6);
    set_base_damage_type("slashing");
    set_damage(1,6);
    set_attack_bonus(1);
    set_funcs(({"bite"}));
    set_func_chance(20);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
void bite(object targ){
    int roll, ac;
    roll=random(20);
    ac=targ->query_ac();
    if(roll > 10-ac){
	tell_object(targ,"%^BOLD%^GREEN%^The Dark Rohch bites you hard, sinking its "+
	"teeth into you!");
	tell_room(ETO,"%^BOLD%^GREEN%^The Dark Rohch bites "+targ->query_cap_name()+" "+
	"hard, sinking its teeth into "+targ->query_objective()+"!",targ);
	targ->do_damage("torso",roll_dice(3,6));
	targ->add_poisoning(40);
	return 1;
    }
    tell_object(targ,"%^BOLD%^GREEN%^The Dark Rohch bites for you but misses!");
    tell_room(ETO,"%^BOLD%^GREEN%^The Dark Rohch bites for "+targ->query_cap_name()+" "+
    "but misses!",targ);
    return 1;
}
