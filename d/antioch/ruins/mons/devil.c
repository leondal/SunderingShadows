#include <std.h>
#include "../ruins.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("barbed devil");
    set_short("An ugly devil covered in barbs");
    set_id(({ "devil", "ugly devil", "barbed devil", "monster" }));
    set_long("The horrendous creature before you is covered in barbs!" +
             " It is quite an ugly sight and stands just over seven feet tall." +
             " It has a reddish-brown scaly hide that has sharp barbs down" +
             " its back and at its joints. Two yellow horns protrude from the" +
             " top of its head, and green eyes stare at you balefully. It has" +
             " a pair of enormous ears and can probably hear almost any sound" +
             " in its vicinity. It also has a long tail that is covered in" +
             " barbs that it could use in a fight. Overall, his skin seems to" +
             " provide him with excellent protection, it looks thick and tough.");
    set_gender("male");
    set_race("devil");
    set_body_type("humanoid");
    add_limb("tail", "torso", 0, 0, 0);
    set_alignment(3);
    set("aggressive", 25);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_hd(20, 10);
    set_max_hp(190 + random(25));
    set_hp(query_max_hp());
    set_level(25);
    set_property("no bows", 1);
    set_property("full attacks", 1);
    set_property("swarm", 1);
    set_exp(8000);
    set_max_level(30);
    set_overall_ac(-17);
    add_limb("right claw", "right hand", 0, 0, 0);
    add_limb("left claw", "left hand", 0, 0, 0);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "right claw", "left claw", "tail" }));
    set_damage(4, 8);
    add_money("gold", random(750) + 250);
    set_funcs(({ "tackle" }));
    set_func_chance(5);
    set_resistance("electricity", 10);
}

void init()
{
    ::init();
    if (TP->query_invis() && !avatarp(TP)) {
        tell_object(TP, "The devil seems to sense your whereabouts and attacks!");
        force_me("kill " + TP->query_name() + "");
    }
}

void tackle(object targ)
{
    tell_object(targ, "The barbed demon lunges at you, butting you" +
                " with his head and knocking you to the ground!");
    tell_room(ETO, "The barbed demon lunges at " + targ->query_cap_name() + "," +
              " butting " + targ->query_objective() + " with his head and knocking" +
              " " + targ->query_objective() + " to the ground!", targ);
    targ->do_damage("torso", random(15) + 6);
    targ->set_tripped(3, "You're still a bit numb from that head-butt!");
    return 1;
}
