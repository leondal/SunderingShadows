#include <std.h>
#include "../defs.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("wolf");
    set_id(({ "wolf", "dire wolf", "mnster" }));
    set_short("A dire wolf");
    set_long("The wolf before you is far larger than most.  Easily " +
             "twice the size of a large guard dog, he moves around on " +
             "strong, large paws.  His gold eyes flair, and he seems " +
             "more agressive than most wolves.  " +
             "A low, long growl escapes the wolf's mouth as he sniffs " +
             "something in the air.");
    set_race("canine");
    set_body_type("quadruped");
    set_gender("male");
    set_hd(5, 2);
    set_size(1);
    set("aggressive", 25);
    set_class("fighter");
    set_mlevel("fighter", 5);
    add_limb("mouth", "head", 0, 0, 0);
    add_limb("tail", "torso", 0, 0, 0);
    set_attack_limbs(({ "mouth" }));
    set_attacks_num(2);
    set_base_damage_type("piercing");
    set_damage(1, 8);
    set_stats("strength", 15);
    set_stats("dexterity", 15);
    set_exp(300);
    set_overall_ac(6);
    set_alignment(5);
    set_emotes(10, ({
        "The wolf growls hungrily at you.",
        "The wolf snarls at you, showing large teeth that glisten " +
        "with saliva."
    }), 1);
    set_emotes(5, ({
        "The wolf scratches at a flea on his shoulder, whining " +
        "softly.",
        "The wolf chases his tail, trying to get at a flea on his rump."
    }), 0);
}
