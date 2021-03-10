
#include <std.h>
inherit WEAPONLESS;

create (){
    ::create ();
    set_name("force field");
    set_id( ({"force field", "field"}) );
    set_short("force field");
    set_long(
      "%^BOLD%^%^BLUE%^A powerful energy barrier.%^RESET%^"
    );
    set("race", "magical shield");
    set_hd(26,0);
    set_overall_ac(-12);
    set_body_type("fowl");
    set_size(4);
    set_wielding_limbs(({"energy barrier"}));
    set_attacks_num(0);
    add_limb("energy barrier","energy barrier",96,1,4);
    remove_limb("left wing");
    remove_limb("right wing");
    remove_limb("beak");
    remove_limb("right leg");
    remove_limb("left leg");
    remove_limb("right claw");
    remove_limb("left claw");
    remove_limb("tail");
    remove_limb("head");
    remove_limb("left wing");
    remove_limb("torso");
    remove_limb("left wing");
    set_base_damage_type("blunt");
    set_damage(1,8);
    set_stats("strength", 19);
    set_stats("intelligence", 6);
    set_stats("dexterity", 19);
    set_stats("charisma", 6);
    set_stats("wisdom", 5);
    set_class("fighter");
    set("aggressive", 26);
    set_alignment(4);
    set_hp(2000);
    set_exp(8500);
    set_funcs( ({"fire"}) );
    set_func_chance(50);
}
void die(object ob) 
{
    if(objectp(TO) && objectp(ETO)) { tell_room(ETO, "%^BOLD%^%^BLUE%^The force field buckles and collapses.\n"); }
    TO->remove();
    return;
}

void fire(object targ)
{
    if(!targ) return 0;
    if(random(40) > targ->query_stats("wisdom")){
	tell_room(environment(targ), "%^BOLD%^%^BLUE%^A bolt of electricity collects on the force field and strikes "+targ->query_cap_name()+"!",targ);
	tell_object(targ, "%^BOLD%^%^BLUE%^A bolt of electricity collects on the force field and strikes you!");
	targ->do_damage("torso", random(2)+15);
	targ->set_paralyzed(random(5)+30,
	  "%^BOLD%^Electricity coarses through you!"
	);
	return 1;

    } else {

	tell_object(targ, "%^BOLD%^%^BLUE%^Energy ribbons from the force field strike the walls around you!");

    }
}
