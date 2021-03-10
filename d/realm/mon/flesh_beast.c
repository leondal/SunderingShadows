#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;
int flag;

void create()
{
    ::create();
    set_name("monstrous glob of flesh");
    set_id(({ "glob", "flesh glob", "glob of flesh" }));
    set_gender("neuter");
    set_race("magical experiment");
    set_short("%^BOLD%^%^RED%^A monstrous glob of flesh%^RESET%^");

    set_long("%^BOLD%^%^RED%^This thing is almost beyond words.  " +
             "What you suppose is its torso is composed of some type of " +
             "red leathery mass of flesh and seems to heave heavily " +
             "with every intake of breath from its numerous mouths.  " +
             "Jutting outward, at very strange angles, from its torso " +
             "are the heads and arms of a minotaur, an ogre, an orc, " +
             "a gnoll, a troll, and a hobgoblin, each head is adorned " +
             "with a pair of %^BOLD%^%^WHITE%^twisted demonic horns" +
             "%^BOLD%^%^RED%^.  Each head is grotesquely bloated and " +
             "the flesh is mostly eat away with what looks like " +
             "acid.  The look on each face is one of unfathomable " +
             "horror.  This thing radiates a very powerful aura of " +
             "magic, as if it is the result of a potent experiment " +
             "gone awry.%^RESET%^");

    set_body_type("flesh glob");
    set_alignment(9);
    set_size(4);
    set_hd(50, 2);
    set_stats("strength", 18);
    set_stats("constitution", 12);
    set_stats("wisdom", 14);
    set_stats("intelligence", 14);
    set_stats("dexterity", 21);
    set_stats("charisma", 4);
    add_limb("torso", 0, 0, 0, 0);

    add_limb("troll head", "torso", 0, 0, 0);
    add_limb("gnoll head", "torso", 0, 0, 0);
    add_limb("hogboglin head", "torso", 0, 0, 0);
    add_limb("ogre head", "torso", 0, 0, 0);
    add_limb("minotaur head", "torso", 0, 0, 0);
    add_limb("orc head", "torso", 0, 0, 0);

    add_limb("minotaur arm", "torso", 0, 0, 0);
    add_limb("orc arm", "torso", 0, 0, 0);
    add_limb("ogre arm", "torso", 0, 0, 0);
    add_limb("hobgoblin arm", "torso", 0, 0, 0);
    add_limb("gnoll arm", "torso", 0, 0, 0);
    add_limb("troll arm", "torso", 0, 0, 0);

    add_limb("minotaur hand", "minotaur arm", 0, 0, 0);
    add_limb("orc hand", "orc arm", 0, 0, 0);
    add_limb("ogre hand", "ogre arm", 0, 0, 0);
    add_limb("hobgoblin hand", "hobgoblin arm", 0, 0, 0);
    add_limb("gnoll hand", "gnoll arm", 0, 0, 0);
    add_limb("troll hand", "troll arm", 0, 0, 0);

    set_attack_limbs(({
        "minotaur hand",
        "orc hand",
        "ogre hand",
        "hobgoblin hand",
        "gnoll hand",
        "troll hand",
    }));
    set_property("magic", 1);
    set("aggressive", "agg_func");
    set_overall_ac(-25);
    set_property("weapon resistance", 4);
    set_mob_magic_resistance("average");
    set_hp(1100 + random(200));
    //set_exp(45000);
    set_new_exp(35, "high");
    //intentionally has this much gold
    //hopefully it only rarely exists - if ever
    //and it eats other mobs - gains health from
    //them - should be dangerous :P - Saide
    set_money("gold", 35000);
    set_damage(4, 8);
    set_attacks_num(6);
    set_base_damage_type("bludgeoning");
    set_funcs(({ "acid" }));
    set_func_chance(50);
    set_moving(1);
    set_speed(30);
    set_property("death effects", "any");
}

void heart_beat()
{
    int x = 0, thp;
    object* vics, vic;
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    vics = filter_array(all_living(ETO), "is_non_immortal", FILTERS_D);
    vics -= ({ TO });
    if (!sizeof(vics)) {
        return;
    }
    while (x < 3) {
        if (!sizeof(vics)) {
            return;
        }
        vic = vics[random(sizeof(vics))];
        vics -= ({ vic });
        if (userp(vic)) {
            continue;
        }
        if (vic->id("retainer")) {
            continue;
        }
        if (vic->id("follower")) {
            continue;
        }
        tell_object(ETO, TOQCN + "%^BOLD%^%^RED%^ reaches out " +
                    "with its minotaur arm and grabs " + vic->QCN +
                    " tossing " + vic->QO + " into one of its " +
                    "mouths and swallowing " + vic->QO +
                    " whole!%^RESET%^");
        thp = vic->query_hp();
        if (TO->query_max_hp() < 2500) {
            TO->set_max_hp(TO->query_max_hp() + (thp / 10));
        }
        TO->add_hp(vic->query_hp());
        vic->move("/d/shadowgate/void");
        x++;
        continue;
    }
    return;
}

void continue_acid(object targ, string lim)
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (!objectp(targ)) {
        return;
    }
    if (!stringp(lim)) {
        return;
    }
    tell_object(targ, "%^BOLD%^%^GREEN%^The acidic " +
                "goo continues to burn into your " + lim + "!%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^GREEN%^The acidic " +
              "goo continues to burn into " + targ->QCN +
              "%^BOLD%^%^GREEN%^'s " + lim + "%^RESET%^", targ);
    targ->cause_typed_damage(targ, lim, roll_dice(8, 8), "acid");
    if (!random(3)) {
        call_out("continue_acid", 8, targ, lim);
    }else {
        tell_object(targ, "%^BOLD%^%^GREEN%^The green " +
                    "goos falls off of your " + lim + " and melts " +
                    "into the floor!%^RESET%^");
    }
    return;
}

void acid(object targ)
{
    string tlim;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (!objectp(targ)) {
        return;
    }
    tell_object(targ, "%^RESET%^%^GREEN%^The monstrous " +
                "glob of flesh spits an %^BOLD%^acidic green goo" +
                "%^RESET%^%^GREEN%^ at you!%^RESET%^");

    tell_room(ETO, "%^RESET%^%^GREEN%^The monstrous " +
              "glob of flesh spits an %^BOLD%^acidic green goo" +
              "%^RESET%^%^GREEN%^ at " + targ->QCN + "%^RESET%^" +
              "%^GREEN%^!%^RESET%^", targ);

    if ("/daemon/saving_throw_d.c"->reflex_save(targ, -30)) {
        tell_object(targ, "%^BOLD%^%^GREEN%^You quickly " +
                    "move out of the way of the acidic green goo!%^RESET%^");

        tell_room(ETO, targ->QCN + "%^BOLD%^%^GREEN%^ " +
                  "quickly moves out of the way of the acidic " +
                  "green goo!%^RESET%^", targ);
        return;
    }
    tlim = targ->return_target_limb();
    tell_object(targ, "%^BOLD%^%^GREEN%^The acidic green goo " +
                "sticks to your " + tlim + " and begins eating away at it!%^RESET%^");

    tell_room(ETO, "%^BOLD%^%^GREEN%^The acidic green goo " +
              "sticks to " + targ->QCN + "%^BOLD%^%^GREEN%^'s " + tlim +
              "and begins eating away at it!%^RESET%^", targ);
    targ->cause_typed_damage(targ, tlim, roll_dice(8, 8), "acid");
    if (!random(3)) {
        call_out("continue_acid", 8, targ, tlim);
    }else {
        tell_object(targ, "%^BOLD%^%^GREEN%^The green " +
                    "goos falls off of your " + tlim + " and melts " +
                    "into the floor!%^RESET%^");
    }
    return;
}

void agg_func()
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(TP)) {
        return;
    }
    if (TP->query_true_invis()) {
        return;
    }
    if (TP->query_invis()) {
        tell_object(TP, "%^BOLD%^%^BLACK%^You sense " +
                    "immediate danger as the monstrous glob of " +
                    "flesh has seen through your " +
                    "invisibility.%^RESET%^");
    }
    acid(TP);
    TO->force_me("kill " + TPQN);
}
