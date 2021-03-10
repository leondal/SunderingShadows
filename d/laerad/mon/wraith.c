//Coded by the one and only master of monsters...BANE//
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create()
{
    ::create();
    set_id(({ "wraith", "Wraith" }));
    set_name("Wraith");
    set_short("A horrible Wraith");
    set_long(
        "This creature of the undead is pure evil...seeking only to " +
        "absorb human life energy. The monster appears as a black, " +
        "vaguely man-shaped cloud. It eyes glow a deadly red showing " +
        "its shear hatred of all that is living..."
        );
    set_body_type("undead");
    set_race("wraith");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_property("alignment adjustment", 4);
    set_property("swarm", 1);
    set_hd(10, 20);
    set_hp(100);
    set_exp(4500);
    set_overall_ac(3);
    set("aggressive", 19);
    set_attack_limbs(({ "right hand" }));
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_damage(1, 6);
    set_attack_bonus(1);
    set_hit_funcs((["right hand" : (: TO, "drain" :)]));
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case
}

void drain(object target)
{
    int round_duration = roll_dice(query_level(), 20);
    int power = roll_dice(1, 4);
    tell_object(target, "%^BOLD%^BLUE%^You feel your life force drain away!");
    tell_room(ETO, "%^BOLD%^BLUE%^" + target->query_cap_name() + "'s stumbles back weakly from the touch of the " + TO->query_name() + "!", target);
    "/std/effect/status/negative_level"->apply_effect(target, round_duration, power);
}
