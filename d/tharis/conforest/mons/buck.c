#include <std.h>
#include "../defs.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("buck");
    set_id(({ "buck", "deer", "stag", "monster" }));
    set_short("A large buck");
    set_long("A large buck searches the ground for something to eat " +
             "in this thick forest.  The deer has a perfect rack of antlers, " +
             "spreading out into eight sharp points.  He moves gracefully " +
             "through the forest, protecting his territory and looking for " +
             "a doe.");
    set_race("deer");
    set_body_type("quadruped");
    set_gender("male");
    set_hd(6, 2);
    set_size(2);
    set("aggressive", 25);
    set_class("fighter");
    set_mlevel("fighter", 6);
    add_limb("antlers", "head", 0, 0, 0);
    set_attack_limbs(({ "right forepaw", "left forepaw", "antlers" }));
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(1, 8);
    set_hp(random(25) + 50);
    set_exp(500);
    set_overall_ac(5);
    set_alignment(5);
    set_funcs(({ "charge" }));
    set_func_chance(20);
    set_emotes(10, ({
        "The deer lowers his head, threatening you with 8 sharp " +
        "antler points.",
        "The buck lets out a loud huff while clawing at the ground " +
        "with his forepaw."
    }), 1);
    set_emotes(5, ({
        "The buck rubs his antlers up againt a nearby tree.",
        "The buck's head suddenly darts up, sniffing the air with " +
        "loud snorts, sensing something nearby."
    }), 0);
}

void charge(object targ)
{
    switch (random(20)) {
    case 0..4:
        tell_object(targ, "%^CYAN%^The buck lowers his head and lunges " +
                    "at you with his antlers, just missing to your side.%^RESET%^");
        tell_room(ETO, "%^CYAN%^The buck lowers his head and lunges at " +
                  "" + TQCN + ", but " + targ->query_subjective() + " manages to dodge " +
                  "out of the reach of the antlers.%^RESET%^", targ);
        break;

    case 5..15:
        tell_object(targ, "%^CYAN%^The deer suddenly rears up and lashes " +
                    "out with his forelegs, landing a hoof squarely on your chest." +
                    "%^RESET%^");
        tell_room(ETO, "%^CYAN%^The buck rises up and kicks " + TQCN + " " +
                  "squarely in the chest.%^RESET%^", targ);
        targ->do_damage("torso", roll_dice(2, 3));
        break;

    case 16..19:
        tell_object(targ, "%^CYAN%^The buck charges at you with his " +
                    "head lowered.  An antler pierces into your shoulder and the " +
                    "deer lifts you up off of your feet and slings you aside.%^RESET%^");
        tell_room(ETO, "%^CYAN%^The deer charges " + TQCN + " and pierces " +
                  "" + targ->query_possessive() + " shoulder with an antler.\n"
                  "The buck shakes his head and tosses " + TQCN + " to the ground." +
                  "%^RESET%^", targ);
        targ->do_damage("torso", roll_dice(3, 3));
        break;
    }
}
