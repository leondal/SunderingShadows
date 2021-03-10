#include <std.h>
#include "../defs.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("bear");
    set_id(({ "bear", "grizzly bear", "monster" }));
    set_short("A grizzly bear");
    set_long("This large bear is an intimidating beast indeed.  The " +
             "grizzly stands well over nine feet tall, brandishing her " +
             "glistening teeth.  Huge paws end in three inch long razor " +
             "sharp claws.  She looks like she is searching for her " +
             "next meal, and you just may be it.");
    set_race("bear");
    set_body_type("quadruped");
    set_gender("female");
    set_hd(7, 2);
    set_size(3);
    set("aggressive", 25);
    set_class("fighter");
    set_mlevel("fighter", 7);
    add_limb("mouth", "head", 0, 0, 0);
    set_attack_limbs(({ "right forepaw", "left forepaw", "mouth" }));
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(1, 6);
    set_stats("strength", 16);
    set_hp(random(15) + 70);
    set_exp(700);
    set_overall_ac(5);
    set_alignment(5);
    set_funcs(({ "charge" }));
    set_func_chance(10);
    set_emotes(10, ({
        "The bear growls hungrily at you.",
        "The bear rises up onto her hind legs, standing as tall " +
        "as an ogre.",
        "The bear lets out a ferocious roar as she comes towards " +
        "you."
    }), 1);
    set_emotes(5, ({
        "The bear rakes huge paws across a nearby tree trunk, " +
        "leaving deep scratches in the bark.",
        "The bear stands on her hind legs next to a tree, rubbing " +
        "back and forth across the bark to scratch her back."
    }), 0);
}

void charge(object targ)
{
    switch (random(20)) {
    case 0..4:
        tell_object(targ, "%^CYAN%^The bear charges towards you, swinging " +
                    "a huge paw that slices through the air as you dodge aside.%^RESET%^");
        tell_room(ETO, "%^CYAN%^The bear takes a mighty swing at " + TQCN + " " +
                  "who just barely dodges out of the way.%^RESET%^", targ);
        break;

    case 5..15:
        tell_object(targ, "%^CYAN%^The bear charges towards you and lands a " +
                    "blow upon your shoulder with her huge paw, nearly knocking you off " +
                    "of your feet.%^RESET%^");
        tell_room(ETO, "%^CYAN%^The bear spins " + TQCN + " around with a swipe " +
                  "of her paw.%^RESET%^", targ);
        targ->do_damage("torso", random(5) + 3);
        break;

    case 16..19:
        tell_object(targ, "%^CYAN%^Lowering her head, the bear suddenly " +
                    "lunges towards you, barreling over you and knocking you onto your " +
                    "back. \nHer gaping maw closes down on your shoulder, and it feels " +
                    "as if she is going to rip you apart.  \nYou punch at her throat until " +
                    "she lets go and you manage to squirm away.%^RESET%^");
        tell_room(ETO, "%^CYAN%^The bear tackles " + TQCN + " to the ground, and " +
                  "rips into " + targ->query_possessive() + " shoulder.  \n" + TQCN + " flails " +
                  "up towards the bear before " + targ->query_possessive() + " finaly " +
                  "is able to get free of the bear.%^RESET%^", targ);
        targ->do_damage("torso", random(8) + 5);
        break;
    }
}
