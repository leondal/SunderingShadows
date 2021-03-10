//Coded by Bane//
//Use with extreme caution ;)//
#include <std.h>
#include <daemons.h>
// inherit "/d/laerad/mon/wander/illwander.c";
inherit WEAPONLESS;

void cone(object targ);

int num, nocone;
string limb;
void create()
{
    ::create();
    set_id(({ "illithid", "mind flayer", "flayer", "vampire", "vampire illithid" }));
    set_name("vampire illithid");
    set_short("A hideous Illithid");
    set_short("A Vampire Illithid");
    set_property("magic", 1);
    set_long(
        "Fear this abomination!  You have come face to face with one of the " +
        "deadliest creations ever!  An experiment by the Illithids gone horribly " +
        "horribly wrong, the Vampire Illithid is a completely insane " +
        "failed breed of super Illithids.  Unable to destroy these ghastly " +
        "creatures the Illithids ran them off into the world."
        );
    set_property("wandermon", 1);
    set_body_type("human");
    set_race("vampire illithid");
    set_gender("neuter");
    set_alignment(9);
    add_limb("tentacle1", "head", 0, 0, 0);
    add_limb("tentacle2", "head", 0, 0, 0);
    add_limb("tentacle3", "head", 0, 0, 0);
    add_limb("tentacle4", "head", 0, 0, 0);
    set_size(2);
    set_class("fighter");
    set_hd(15 + (random(10)), 8);
    set_mlevel("fighter", query_hd());
    set_hp(150 + (random(59)));
    set_guild_level("fighter", query_level());
    set_mob_magic_resistance("average");
    set_property("swarm", 1);
    set_property("magic", 1);
    set_property("no dominate", 1);
    set_property("no death", 1);
    set_property("no steal", 1);
    set_stats("strength", 19);
    set_stats("dexterity", 18);
    set_stats("intelligence", 1);
    set_stats("wisdom", 1);
    set_exp(32000);
    set_overall_ac(-6);
    set_attack_limbs(({ "tentacle1", "tentacle2", "tentacle3", "tentacle4" }));
    num = 4;
    set_attacks_num(num);
    set_base_damage_type("piercing");
    set_damage(1, 6);
    set_hit_funcs((["tentacle1" : (: TO, "brain_me1" :),
                    "tentacle2" : (: TO, "brain_me1" :),
                    "tentacle3" : (: TO, "brain_me1" :),
                    "tentacle4" : (: TO, "brain_me1" :)]));
    set_funcs(({ "cone" }));
    set_func_chance(30);
    if (!random(4)) {
        new("/d/laerad/obj/ring_stars")->move(this_object());
    }
    if (!random(3)) {
        new("/d/laerad/obj/soul_staff")->move(this_object());
    }
    set_moving(1);
    set_speed(15);
    set_stabbed_func((: TO, "stabbed" :));
}

void stabbed()
{
    force_me("emote jerks around flailing wildly");
    if (TO->query_hp() < 0) {
        return;
    }
    add_attack_bonus(5);
    set_func_chance(0);
    execute_attack();
    tell_room(ETO, "%^RED%^As the illithid feels the steel dig into him he lets loose a blast of defensive energy.");
    cone(TP);
    set_func_chance(30);
    add_attack_bonus(-5);
}

void init()
{
    ::init();
    if (wizardp(TP)) {
        return 1;
    }
    if ((string)TP->query_name() == "vampire illithid") {
        return 1;
    }
    TO->force_me("kill " + TPQN);
    TO->kill_ob(TP, 1);
}

int kill_ob(object victim, int which)
{
    int hold;
    hold = ::kill_ob(victim, which);
    if (hold) {
        if (nocone) {
            return hold;
        }
        call_out("cone", 0, victim);
        nocone = 1;
        call_out("check_me", 2, TO);
    }
    return hold;
}

void cone(object targ)
{
    if (!objectp(TO)) {
        return;
    }
    if (!present(targ->query_name(), ETO)) {
        return;                                 // changed to query targ name, as present requires a string for the first argument, not an object - Ares
    }
    if (targ->query_paralyzed()) {
        set_func_chance(0);
        execute_attack();
        set_func_chance(30);
        return 1;
    }
    tell_object(targ, "%^BOLD%^BLUE%^The Vampire Illithid psionically assaults your brain!");
    tell_room(ETO, "%^BOLD%^BLUE%^The Vampire Illithid focuses a psionic assault on " + targ->query_cap_name() + ".", targ);
    if (!SAVING_THROW_D->will_save(targ, 20)) {
        tell_object(targ, "Your body freezes up!");
        tell_room(ETO, targ->query_cap_name() + "'s body freezes up!", targ);
        targ->set_paralyzed(40 + (random(30)), "Your muscles won't budge.");
        return 1;
    }
    tell_object(targ, "You resist the attack!");
    tell_room(ETO, targ->query_cap_name() + " seems to shake off the attack!", targ);
    return 1;
}

void brain_me1(object targ)
{
    int i, hp_loss;
    string curclass, * classes;

    if (!SAVING_THROW_D->fort_save(targ, 20)) {
        tell_object(targ, "%^BOLD%^As the tentacle hits you it grabs ahold of your head and starts to burrow towards your brain!");
        tell_room(ETO, "%^BOLD%^As the tentacle hits " + targ->query_cap_name() + " it grabs ahold of " + targ->query_possessive() + " head and starts to burrow into it!", targ);
        set_attack_limbs((string*)TO->query_attack_limbs() - ({ limb }));
        num -= 1;
        if (num < 1) {
            num = 1;
        }
        if (num > 4) {
            num = 4;
        }
        set_attacks_num(num);
        call_out("burrow1", 5, targ);
        return 1;
    }
}

void burrow1(object targ)
{
    if (!present(targ, ETO)) {
        return 1;
    }
    if (!SAVING_THROW_D->fort_save(targ, 20) && !targ->query_paralyzed()) {
        tell_object(targ, "%^BOLD%^You grab ahold of the tentacle and tear it out of your head!");
        tell_room(ETO, "%^BOLD%^" + targ->query_cap_name() + " grabs ahold of the tentacle and tears it out of " + targ->query_possessive() + " head!", targ);
        set_attack_limbs((string*)TO->query_attack_limbs() + ({ limb }));
        num += 1;
        if (num < 1) {
            num = 1;
        }
        if (num > 4) {
            num = 4;
        }
        set_attacks_num(num);
        targ->do_damage(targ->return_target_limb(), roll_dice(1, 6));
        return 1;
    }
    tell_object(targ, "%^BOLD%^The tentacle burrows deeper into your head!");
    tell_room(ETO, "%^BOLD%^" + targ->query_cap_name() + " cries out in pain as the tentacle tears into " + targ->query_possessive() + " head!", targ);
    targ->do_damage(targ->return_target_limb(), roll_dice(1, 6));
    call_out("burrow1", 5, targ);
    return 1;
}

void heart_beat()
{
    ::heart_beat();
    if (query_hp() < query_max_hp()) {
        add_hp(3);
    }
    if (query_attackers() == ({})) {
        if (num < 4) {
            set_attacks_num(4);
        }
    }
    if (num < 0) {
        set_attacks_num(0);
    }
    if (num > 4) {
        set_attacks_num(4);
    }
}

void check_me()
{
    nocone = 0;
}

void set_paralyzed(string message, int time)
{
    return 1;
}
