#include <std.h>
#include "../../fways.h"
inherit WEAPONLESS;

object focused_on;

void create()
{
    int lev;
    ::create();
    set_name("monstrous sludge beast");
    set_id(({ "beast", "sludge beast", "monstrous sludge beast", "dallyhallyevil" }));

    set_short("%^BOLD%^%^GREEN%^M%^RESET%^%^GREEN%^o%^BOLD%^nstr%^RESET%^%^GREEN%^ou" +
              "%^BOLD%^s Sl%^RESET%^%^GREEN%^u%^BOLD%^dg%^RESET%^%^GREEN%^e B%^RESET%^%^GREEN%^ea" +
              "%^BOLD%^st%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This strange creature towers nearly twenty feet tall. " +
             "It has multiple appendages which flap around it constantly in a chaotic display of " +
             "motion. The entire body of this thing is formed from a foul sludge which somehow manages " +
             "to retain shape. It emits an extremely foul and t%^RESET%^%^GREEN%^o%^BOLD%^xic " +
             "odor, making breathing a challenge in its presence. Pieces of it continually fall off " +
             "as it lunges back and forth. You recognize no face, head, nor eyes on this thing and " +
             "are not sure how it might see the world around it or how it might perceive anything, " +
             "if in fact it even does. Whatever is holding it together and providing life to it is " +
             "a complete mystery.%^RESET%^");

    set_race("sludge elemental");
    set_alignment(5);
    set_gender("neuter");
    set_body_type("human");
    set_class("fighter");
    lev = 42 + random(6);
    set_guild_level("fighter", lev);
    set_mlevel("fighter", lev);
    set_overall_ac(-20);
    set_size(4);

    set_property("damage resistance", 5);
    set_property("spell damage resistance", 55);
    set_resistance("bludgeoning resistance", 10);
    set_property("weapon resistance", 4);

    set_max_hp(1000 + random(1000));
    set_hp(query_max_hp());
    set("aggressive", 66);

    set_attacks_num(6);
    set_property("full attacks", 1);
    set_base_damage_type("bludgeoning");
    set_damage(4, 20);
    set_stats("strength", 30);
    set_stats("dexterity", 5);
    set_stats("constitution", 30);
    set_stats("intelligence", 5);
    set_stats("wisdom", 4);
    set_stats("charisma", 4);
    set_new_exp(lev, "very high");

    add_attack_bonus(15);
    set_func_chance(50);
    set_funcs(({ "slap", "slam", "slap", "slap", "slap", "slap", "slap" }));
}

void vape_me()
{
    string me;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    me = TO->query_short();
    tell_room(ETO, me + "%^BOLD%^%^GREEN%^ explodes in chunks " +
              "of G%^YELLOW%^OOEY%^GREEN%^ sludge!%^RESET%^");
    TO->move("/d/shadowgate/void");
    if (objectp(TO)) {
        TO->remove();
    }
    return;
}

int check_focus_target()
{
    if (!objectp(TO)) {
        return 0;
    }
    if (!objectp(ETO)) {
        return 0;
    }
    if (!objectp(focused_on) || environment(focused_on) != ETO) {
        vape_me();
        return 0;
    }
    TO->set_attackers(({ focused_on }));
    return 1;
}

void focus_on(object ob)
{
    string me;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (!objectp(ob)) {
        return;
    }
    me = TO->query_short();
    focused_on = ob;
    tell_room(ETO, me + "%^RESET%^%^RED%^ emits a dreadful roar " +
              "and seems to focus entirely on " + focused_on->QCN + "%^RESET%^" +
              "%^RED%^!%^RESET%^", focused_on);
    tell_object(focused_on, me + "%^RESET%^%^RED%^ emits a dreadful " +
                "roar and turns to focus entirely on you!%^RESET%^");
    return;
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    DYN_UP_D->dynamic_update(TO);
    if (!check_focus_target()) {
        return;
    }
}

void slam(object targ)
{
    string me;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (!check_focus_target()) {
        return;
    }
    me = TO->query_short();
    targ = focused_on;

    tell_object(targ, me + "%^BOLD%^%^RED%^ DIVES%^BOLD%^%^GREEN%^ with a reckless " +
                "abandon onto you, covering you with its entire %^BOLD%^%^YELLOW%^foul smelling " +
                "and gooey%^BOLD%^%^GREEN%^ body!%^RESET%^");

    targ->set_tripped(random(4)+1, "%^BOLD%^%^GREEN%^You are struggling to stand!%^RESET%^");

    tell_room(ETO, "%^BOLD%^%^RED%^You watch in HORROR as " + me + "%^BOLD%^%^BLACK%^ DIVES " +
              "%^BOLD%^%^RED%^ with a reckless abandon onto " + targ->QCN + "%^BOLD%^%^RED%^ covering " +
              targ->QO + " with the entirity of its %^BOLD%^%^YELLOW%^foul smelling " +
              "and gooey%^BOLD%^%^RED%^ body!%^RESET%^", targ);

    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(36, 12), "bludgeoning");
    return;
}

void slap(object targ)
{
    string me;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (!check_focus_target()) {
        return;
    }
    me = TO->query_short();
    targ = focused_on;

    tell_object(targ, me + "%^BOLD%^%^BLACK%^slaps your entire body with several of its " +
                "%^BOLD%^%^YELLOW%^gooey%^BOLD%^%^BLACK%^ and foul %^BOLD%^%^GREEN%^smelling " +
                "appendages!%^RESET%^");

    tell_room(ETO, me + "%^BOLD%^%^BLACK%^ slaps " + targ->QCN + "%^BOLD%^%^BLACK%^ with several of " +
              "its %^BOLD%^%^YELLOW%^gooey%^BOLD%^%^BLACK%^ and foul %^BOLD%^%^GREEN%^smelling " +
              "appendages!%^RESET%^", targ);

    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(24, 12), "bludgeoning");
    return;
}

void die(object ob)
{
    if (!objectp(TO)) {
        return ::die(ob);
    }
    if (!objectp(ETO)) {
        return ::die(ob);
    }
    return vape_me();
}
