//giant_cockroach.c - Mob for low level cave area
//by Circe 3/11/05
#include <std.h>
#include "../ekibi.h"

inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("giant cockroach");
    set_short("%^RESET%^%^ORANGE%^A slimy giant cockroach%^BOLD%^%^RED%^");
    set_id(({ "cockroach", "roach", "giant roach", "giant cockroach", "slimy roach", "slimy giant cockroach", "slimy cockroach", "insect" }));
    set_long("%^RESET%^%^ORANGE%^This disgusting cockroach is over " +
             "six feet long and covered in slimy, stinking oils.  Its " +
             "carapace is a glossy brown tinged with black.  Six spindly, " +
             "jointed legs jut forth from its mid-section, while a pair " +
             "of slender antennae test the air around its head.  Covering " +
             "its back are two thick plates protecting a pair of fibrous " +
             "wings.%^RESET%^");
    set_gender(random(2) ? "male" : "female");
    set_race("cockroach");
    set_body_type("insectoid-winged");
    set_size(2);
    set_alignment(5);
    set_hd(5, 5);
    set("aggressive", 12);
    set_property("swarm", 1);
    set_class("fighter");
    set_mlevel("fighter", 5);
    set_hp(random(10) + 40);
    set_overall_ac(6);
    set_stats("strength", 12);
    set_damage(1, 4);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "right fore leg", "left fore leg" }));
    set_exp(150);
    set_emotes(2, ({
        "%^YELLOW%^The cockroach spreads its fibrous wings and takes flight.",
        "%^YELLOW%^The cockroach's insectoid eyes study its surroundings.",
        "%^YELLOW%^The cockroach's antennae test the air cautiously.",
        "%^YELLOW%^The cockroach scurries under a rock."
    }), 0);
    set_emotes(4, ({
        "%^YELLOW%^The cockroach hisses and rears on its hind legs!",
    }), 1);
    set_max_level(8);
    set_funcs(({ "stench" }));
    set_func_chance(5);
}

void die(object obj)
{
    if (!random(5)) {
        tell_room(ETO, "As the cockroach dies, a section of its " +
                  "exoskeleton falls off!");
        new(OBJ "carapace")->move(TO);
    }
    ::die(obj);
}

void stench(object targ)
{
    string name = targ->query_cap_name();
    tell_room(ETO, "%^ORANGE%^A horrible stench fills the air around " +
              "the cockroach!");
    if (!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death", 0)) {
        tell_object(targ, "%^GREEN%^You double over from the stench!");
        tell_room(ETO, "" + name + " doubles over!", targ);
        targ->set_paralyzed(2 + random(2), "You are gagging from the stench!");
        return;
    }
    tell_object(targ, "%^ORANGE%^You manage to fight the rising bile " +
                "in your throat!");
    return;
}
