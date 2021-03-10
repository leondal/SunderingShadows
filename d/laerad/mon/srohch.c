//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"rohch","Rohch","Swamp Rohch"}));
    set_name("Swamp Rohch");
    set_short("A swamp Rohch");
    set_long(
	"This beast is the crossbreed of a wolf and a large beetle. "+
	"Its body is covered in a mix of tough carapace and tufts of "+
	"fur. Its head appears wolf-like, with beetle pincers "+
	"protruding from the lower jaw and a carapace covering "+
	"the top of its skull. The creature stands on six beetle legs "+
	"covered in dirty patches of fur."
    );
    set_body_type("quadruped");
    set_race("rohch");
    set_gender("male");
    set_size(1);
    set_alignment(9);
    set_hd(4,11);
    set_hp(44);
    set_exp(400);
    set_overall_ac(3);
    set_property("swarm",1);
    add_limb("right middle paw","torso", 0, 0, 0);
    add_limb("left middle paw","torso", 0, 0, 0);
    set("aggressive",14);
    set_attack_limbs(({"right forepaw","left forepaw","head"}));
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_damage(1,6);
    set_attack_bonus(6);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
