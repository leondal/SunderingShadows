#include <std.h>
#include "../meadow.h"
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("spotted lion");
    set_short("A sleek spotted lion");
    set_id(({ "spotted lion", "lion", "sleek lion", "sleek spotted lion", "monster" }));
    set_long(
        "The spotted lion has a sleek coat and moves with easy grace. His coat" +
        " is glossy and every inch of him is pure muscle. His %^YELLOW%^golden%^RESET%^%^CYAN%^" +
        " eyes stare at you, watching you closely. The lion has spots all over" +
        " his hide, thus earning him his name. You notice sharp %^WHITE%^%^BOLD%^teeth%^RESET%^%^CYAN%^" +
        " protruding from his large mouth. He looks fierce."
        );
    set_hd(12, 5);
    set_race("cat");
    set_gender("male");
    set_body_type("quadruped");
    set("aggressive", 15);
    set_property("swarm", 1);
    //set_level(14);
    //set_class("fighter");
    //set_mlevel("fighter",14);
    set_hp(random(25) + 90);
    set_new_exp(6, "normal");
    set_stats("strength", 16);
    set_damage(1, 6);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    add_limb("left paw", "left hand", 0, 0, 0);
    add_limb("right paw", "right hand", 0, 0, 0);
    add_limb("mouth", "head", 0, 0, 0);
    set_attack_limbs(({ "left paw", "right paw", "mouth" }));
    set_hit_funcs((["mouth" : (: TO, "bite" :) ]));
    set_overall_ac(6);
    set_funcs(({ "pounce" }));
    set_func_chance(12);
    set_alignment(5);
    set_emotes(4, ({
        "The spotted lion snaps at you!",
        "The spotted lion twitches his tail in agitation.",
        "The spotted lion takes a swipe at your face!",
        "The spotted lion roars loudly!",
    }), 1);
    set_emotes(4, ({
        "The spotted lion flexes his claws.",
        "The spotted lion twitches his tail slowly.",
        "The spotted lion cleans his paws.",
        "The spotted lion watches you wearily.",
    }), 0);
    set_max_level(12);
    if (!random(15)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("fur");
        ob->move(TO);
    }
}

int bite(object targ)
{
    tell_object(targ, "The spotted lion bites you viciously!");
    tell_room(ETO, "The spotted lion bites " + targ->query_cap_name() + " viciously!", targ);
    targ->do_damage("torso", random(3) + 3);
    return 1;
}

void pounce(object targ)
{
    int dex, roll;
    dex = targ->query_stats("dexterity");
    roll = random(20);
    if (roll > dex) {
        tell_object(targ, "%^BOLD%^The spotted lion pounces on you, knocking you down!");
        tell_room(ETO, "%^BOLD%^The spotted lion pounces on " + targ->query_cap_name() + "" +
                  " knocking " + targ->query_objective() + " down!", targ);
        targ->set_tripped(1, "You're still a bit dazed from being knocked down.");
        targ->do_damage("torso", random(3) + 4);
        return 1;
    }
    tell_object(targ, "The spotted lion tries to pounce on you, but you manage" +
                " to evade him.");
    tell_room(ETO, "The spotted lion tries to pounce on " + targ->query_cap_name() + "," +
              " but " + targ->query_subjective() + " manages to evade the lion.", targ);
    return 1;
}

void die(object obj)
{
    if (!random(2)) {
        new(OBJ + "spelt")->move(TO);
    }
    ::die(obj);
}
