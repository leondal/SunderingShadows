#include <std.h>

inherit WEAPONLESS;

void create(){
    ::create();
    set_name("Cloaker");
    set_short("Cloaker");
    set_id( ({"cloak", "cloaker", "thing", "black cloak"}) );
    set_long(
      "This somewhat large floating monster is pure black on one side, but on the other side it is white, with a large mouth, large dark red eyes, and claws on the tips of its wings are ready to shred you to bits."
    );
    set_hd(31, 6);
    set_hp(200+random(150));
    set_race("cloaker");
    set_alignment(8);
    set_gender("male");
    set_body_type("humanoid");
    set_attack_num(2);
    set_damage(2,6);
    set_overall_ac(-2);
    set_base_damage_type("slashing");
    add_limb("tail", "torso", 0, 0, 0);
    add_limb("mouth", "torso", 0, 0, 0);
    add_limb("right claw", "torso", 0, 0, 0);
    add_limb("left claw", "torso", 0, 0, 0);
    set_attack_limbs( ({"right claw", "left claw", "mouth", "tail"}) );
    set_funcs( ({"chomp"}) );
    set_func_chance(75);
}

