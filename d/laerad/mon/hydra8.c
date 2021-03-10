//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"hydra","Hydra"}));
    set_name("Hydra");
    set_short("An enormous Hydra");
    set_long(
	"This immense reptilian beast towers over you, its 8 heads "+
	"snaking back and forth. Its dark-brown body is enormous, thick "+
	"scales cover its hide offering excellent protection. Amber eyes "+
	"peer out from the many heads of the creature...searching for "+
	"prey to devour."
    );
    set_body_type("dragon");
    set_race("hydra");
    set_gender("male");
    remove_limb("left wing");
    set_alignment(9);
    remove_limb("right wing");
    remove_limb("head");
    add_limb("head1","FATAL", 0, 0, 0);
    add_limb("head2","FATAL", 0, 0, 0);
    add_limb("head3","FATAL", 0, 0, 0);
    add_limb("head4","FATAL", 0, 0, 0);
    add_limb("head5","FATAL", 0, 0, 0);
    add_limb("head6","FATAL", 0, 0, 0);
    add_limb("head7","FATAL", 0, 0, 0);
    add_limb("head8","FATAL", 0, 0, 0);
    set_size(3);
    set_hd(8,16);
    set_hp(80);
    set_exp(2500);
    set_property("swarm",1);
    set_overall_ac(4);
    set_stats("strength",13);
    set_stats("dexterity",13);
    set("aggressive",18);
    set_attack_limbs(({"head1","head2","head3","head4","head5","head6","head7","head8"}));
    set_attacks_num(4);
    set_base_damage_type("piercing");
    set_damage(1,8);
    set_attack_bonus(1);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
