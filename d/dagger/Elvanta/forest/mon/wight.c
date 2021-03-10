//Coded by the one and only master of monsters...BANE//
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create()
{
    ::create();
    set_id(({ "wight" }));
    set_name("Wight");
    set_short("A nightmarish Wight");
    set_long(
        "This horrid undead creature is a ghastly reflection of its " +
        "former human self, with cruel, burning eyes set in mummified " +
        "flesh over a twisted skeleton with hands that end in sharp " +
        "claws. Long, sickly hair runs from its disfigured head. Its " +
        "teeth are bared, ready to feast on your flesh after it rends " +
        "you limb from limb..."
        );
    set_body_type("undead");
    set_race("wight");
    set_gender("male");
    set_size(2);
    set_hd(20, 25);
    set_hp(65);
    set_exp(1500);
    set_overall_ac(4);
    set("aggressive", 19);
    set_attack_limbs(({ "right hand" }));
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_damage(1, 4);
    set_hit_funcs((["right hand" : (: TO, "drain" :)]));
}

void drain(object target)
{
    int round_duration = roll_dice(query_level(), 20);
    int power = roll_dice(1, 4);
    tell_object(target, "%^BOLD%^BLUE%^You feel your life force drain away!");
    tell_room(ETO, "%^BOLD%^BLUE%^" + target->query_cap_name() + "'s stumbles back weakly from the touch of the " + TO->query_name() + "!", target);
    "/std/effect/status/negative_level"->apply_effect(target, round_duration, power);
}
