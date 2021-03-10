//fixed a few bugs and updated some of the code ~Circe~ 9/27/05
//Coded by Bane//
#include <std.h>
#include <daemons.h>
// inherit "/d/laerad/mon/wander/illwander.c";
inherit WEAPONLESS;
int num, stoned, done, nocone;
string limb;
object ob;

void create()
{
    object ob;
    int num, droll;
    ::create();
    set_id(({ "illithid", "mind flayer", "flayer" }));
    set_name("illithid");
    set_short("A hideous Illithid");
    set_long(
        "This is a hideous Illithid, or more commonly known as Mind Flayer.  This " +
        "is perhaps one of the most feared creatures in all the realms.  This male stands " +
        "about 5 feet tall, his skin is a ghostly purple, and it is garbed in a flowing " +
        "green-black robe.  His head resembles a small octopus.  It has two " +
        "bug-eyes and four tentacles protruding from where his mouth should be.  " +
        "Although he looks fragile, beware his power."
        );
    set_property("wandermon", 1);
    set_race("illithid");
    set_body_type("human");
    set_gender("male");
    set_alignment(9);
    add_limb("tentacle1", "head", 0, 0, 0);
    add_limb("tentacle2", "head", 0, 0, 0);
    add_limb("tentacle3", "head", 0, 0, 0);
    add_limb("tentacle4", "head", 0, 0, 0);
    set_class("psion");
    droll = (21 + random(5));
    set_hd(droll, 12);
    set_guild_level("psion", droll);
    set_mlevel("psion", droll);
    set_attack_bonus(5);
    set_mob_magic_resistance("average");
    set_property("swarm", 1);
    set_property("magic", 1);
    set_stats("strength", 19);
    set_stats("dexterity", 18);
    set_exp(18000);
    set_overall_ac(-7);
    set("aggressive", 19);
    set_spells(({
        "mind thrust",
        "swarm of crystals",
        "energy cone",
        "energy bolt",
        "power leech",
        "ultrablast",
        "tornado blast",
        "hail of crystals"
    }));
    //ob = new("/d/common/obj/potion/healing");
    //ob->set_uses(50);
    //ob->move(TO);
    set_property("add kits", 20);
    if (random(2)) {
        if (TO->query_level() < 20) {
            num = random(6);
        } else {
            num = random(8);
        }
        if (num) {
            ob = new("/d/laerad/obj/bracers" + num)->move(TO);
            command("wear bracers");
        } else {
            ob = new("/d/laerad/obj/bracers")->move(TO);
            command("wear bracers");
        }
        command("wear bracers");
    }
    if (!random(100)) {
//removed the double ->move(TO) that was causing bugs.  Circe 11/22/03
        ob = new("/d/laerad/obj/ring_invis");
        ob->move(TO);
        //if(!random(50)) ob->set_property("monterweapon");
        command("wear ring");
        command("invisible");
    }
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
    set_spell_chance(30);
    stoned = 0;
    set_moving(1);
    set_speed(50);
    set_stabbed_func((: TO, "stabbed" :));
}

void stabbed()
{
    force_me("emote screams in pain.");
    if (TO->query_hp() < 0) {
        return;
    }
    execute_attack();
    return;
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
//was return 1; - that doesn't seem to work
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
    tell_object(targ, "%^BOLD%^BLUE%^The Illithid psionically assaults your brain!");
    tell_room(ETO, "%^BOLD%^BLUE%^The Illithid focuses a psionic assault on " + targ->query_cap_name() + ".", targ);
    if (!SAVING_D->will_save(targ, 20)) {
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
//adding checks for valid TO & targ/present to try to fix bugs *Styx*  5/12/02
    if (!objectp(TO) || !objectp(targ)) {
        return;
    }
    if (!present(targ, ETO)) {
        return;
    }
    if ((!userp(targ) && random(2)) || !SAVING_D->fort_save(targ, 20)) {
        tell_object(targ, "%^BOLD%^As the tentacle hits you it grabs hold of your head and starts to burrow towards your brain!");
        tell_room(ETO, "%^BOLD%^As the tentacle hits " + targ->query_cap_name() + " it grabs hold of " + targ->query_possessive() + " head and starts to burrow into it!", targ);
        set_attack_limbs((string*)TO->query_attack_limbs() - ({ limb }));
        num -= 1;
        if (num < 1) {
            num = 1;
        }
        set_attacks_num(num);
        call_out("burrow1", 5, targ);
        return 1;
    }
    tell_object(targ, "%^BOLD%^One of the illithid's tentacles slithers " +
                "along your head, but you manage to avoid its grasp!");
    return 1;
}

void burrow1(object targ)
{
//adding checks for valid TO & targ to try to fix bugs *Styx*  5/12/02
    if (!objectp(TO) || !objectp(targ)) {
        return;
    }
    if (!present(targ, ETO)) {
        return;
    }
    if ((!userp(targ) && !random(4)) && !SAVING_D->fort_save(targ, 20) && !targ->query_paralyzed()) {
        tell_object(targ, "%^BOLD%^You grab hold of the tentacle and tear it out of your head!");
        tell_room(ETO, "%^BOLD%^" + targ->query_cap_name() + " grabs hold of the tentacle and tears it out of " + targ->query_possessive() + " head!", targ);
        set_attack_limbs((string*)TO->query_attack_limbs() + ({ limb }));
        num += 1;
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
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (TO->query_paralyzed()) {
        return;
    }
    if (!query_stoneSkinned() && stoned < 5 && random(20) < 5) {
        if (done) {
            return 1;
        }
        new("/cmds/spells/i/_iron_body.c")->use_spell(TO, TO, 18, 100, "psion");
        done = 1;
        stoned += 1;
        call_out("check_me", 5, TP);
    }
    if (!query_property("amorpha") && !random(2)) {
        new("/cmds/spells/c/_concealing_amorpha.c")->use_spell(TO, TO, 18, 100, "psion");
    }
    //if(!present("scales",TO) && !random(3)) {
    //  new("/cmds/wizard/_dragon_scales")->use_spell(TO,TO,18);
    // return 1;
    //}
    //if(present("dragon scales")) {
    //   TO->force_me("wear dragon scales");
    //}
    if (!present(query_name() + " summoned", ETO) && random(20) < 5) {
        if (done) {
            return 1;
        }
        new("/cmds/spells/c/_call_crystals.c")->use_spell(TO, 0, query_level(), 100, "psion");
        done = 1;
        call_out("check_me", 5, TP);
    }
    /*if(TO->query_hp() < 75 && present("kit",TO)) {
        force_me("open kit");
        force_me("quaff kit");
        force_me("offer bottle");
        force_me("quaff kit");
        force_me("offer bottle");
        force_me("quaff kit");
        force_me("offer bottle");
       }*/
    if (TO->query_hp() < 20 && (string*)TO->query_attackers() != ({})) {
        TO->run_away();
    }
    if ((string*)TO->query_attackers() == ({})) {
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
    if (present("bottle")) {
        force_me("offer bottle");
    }
    return;
}

void check_me()
{
    done = 0;
    nocone = 0;
}

void reset()
{
    ::reset();
    stoned = 0;
    if (!present("scroll") && !random(3)) {
        ob = new("/d/magic/scroll");
        ob->set_spell(8);
        ob->move(TO);
    }
}

void set_paralyed(string message, int time)
{
    return 1;
}

void die(object ob)
{
    if (!random(2)) {
        force_me("offer kit");
    }
    ::die(ob);
}
