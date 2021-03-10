#include <std.h>
#include "../ruins.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("shadow");
    set_short("A flickering shadow");
    set_id(({ "shadow", "flickering shadow", "monster" }));
    set_long(
        "%^BOLD%^%^BLACK%^This looks like the shadow of a rather large man. The" +
        " edges are blurry and indistinct, constantly moving so you can't quite" +
        " focus on it. It blends in well with its surroundings."
        );
    set_gender("neuter");
    set_race("shadow");
    set_body_type("humanoid");
    set_hd(20, 5);
    set_max_hp(250 + random(75));
    set_hp(query_max_hp());
    set_alignment(9);
    set_max_level(25);
    set_overall_ac(-17);
    set_property("undead", 1);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_level(20);
    set_exp(4000);
    set_stats("strength", 18);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(1, 8);
    set_property("swarm", 1);
    set("aggressive", 25);
    set_mob_magic_resistance("average");
    set_property("magic", 1);
    set_property("no bows", 1);
    set_resistance("negative energy", 10);
    set_resistance("positive energy", -10);
}

void reset()
{
    ::reset();
    if (!TO->query_invis()) {
        TO->set_invis();
    }
}

void init()
{
    ::init();
    if (avatarp(TP) && TP->query_invis()) {
        return;
    }
    if (!userp(TP)) {
        return;
    }else {
        force_me("kill " + TP->query_name() + "");
    }
}
