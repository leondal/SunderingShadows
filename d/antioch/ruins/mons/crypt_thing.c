#include <std.h>
#include "../ruins.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("crypt thing");
    set_short("A robed figure");
    set_id(({ "crypt thing", "thing", "figure", "robed figure", "monster" }));
    set_long(
        "Standing before you is a skeleton covered in dark robes. Its head is free" +
        " and you can see %^RED%^red%^CYAN%^ pin points of light boring into you" +
        " from its eye sockets. The creature appears to be angry about something."
        );
    set_property("undead", 1);
    set_gender("neuter");
    set_race("skeleton");
    set_body_type("humanoid");
    set_hd(20, 5);
    set_max_hp(370 + random(25));
    set_hp(query_max_hp());
    set_alignment(6);
    set_overall_ac(-10);
    set_mob_magic_resistance("high");
    set_property("weapon resistance", 1);
    set_max_level(25);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_level(20);
    set_stats("strength", 20);
    set_exp(2000);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(2);
    set_damage(2, 5);
    set_property("swarm", 1);
    set("aggressive", 25);
    set_resistance("negative energy", 10);
    set_resistance("positive energy", -10);
}
