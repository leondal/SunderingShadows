#include <std.h>
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("young carrion crawler");
    set_id(({ "crawler", "carrion crawler", "young carrion crawler", "young crawler" }));
    set_short("%^RESET%^%^GREEN%^a young carrion crawler%^RESET%^");
    set_long("%^RED%^This carrion crawler appears to be quite young, but is already several feet in length and "
             "has eight %^BLUE%^deadly %^RED%^tentacles that it uses to grab its prey. The centipede-like creature has "
             "sickly %^ORANGE%^yel%^GREEN%^l%^ORANGE%^ow-gr%^GREEN%^e%^ORANGE%^en %^RED%^skin, and reeks of "
             "%^BOLD%^%^BLACK%^decay%^RESET%^%^RED%^. Carrion crawlers are usually just scavengers, but this one appears "
             "to have been stuck here for a while and seems willing to try and eat just about anything.%^RESET%^");
    set_race("worm");
    set_body_type("snake");
    set_gender("neuter");
    set_size(2);
    set("aggressive", 25);
    set_property("swarm", 1);
    set_level(4);
    set_class("fighter");
    set_mlevel("fighter", 4);
    set_max_hp(55);
    set_hp(55);
    set_exp(700);
    set_damage(1, 2);
    set_attacks_num(2);
    add_limb("tentacles", "head", 0, 0, 0);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "tentacles" }));
    set_stats("strength", 16);
    set_stats("dexterity", 16);
    set_ac(8);
    set_alignment(5);
    set_funcs(({ "charge" }));
    set_func_chance(15);
    add_money("silver", random(1300) + 300);
    add_money("gold", random(50) + 40);
    set_new_exp(1, "very low");
}

void charge(object targ)
{
    if (!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death", 2)) {
        tell_object(targ, "%^ORANGE%^The young carrion crawler's tentacle lashes out and finds a section of bare "
                    "skin on you.  You feel your entire body go numb!%^RESET%^");
        tell_room(ETO, "%^ORANGE%^" + targ->QCN + " seems to slump over as a tentacle lashes across " + targ->QP + " bare "
                  "skin.%^RESET%^", targ);
        targ->set_paralyzed(random(5) + 3, "%^RED%^Your entire body feels numb!%^RESET%^");
        return 1;
    }else {
        tell_object(targ, "%^ORANGE%^The young carrion crawler lashes out with its tentacles, but bounces "
                    "harmlessly off of your clothing.%^RESET%^");
        return 1;
    }
}
