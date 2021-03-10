//Coded by Lujke, with code plundered from Cythera and Bane
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit WEAPONLESS;

object dragee;
nosave int BEAT, heartcount;

void create()
{
    string gender_poss, gender_Subj, gender_subj, gender_obj;
    object guider;
    ::create();
    set_name("Mummy");
    set_id(({ "mummy", "tecqumin mummy", "undead" }));
    set_short("%^RESET%^%^ORANGE%^Tecqumin %^BOLD%^%^WHITE%^Mummy"
              + "%^RESET%^");
    set_race("undead");
    set_body_type("humanoid");
    if (random(2)) {
        set_gender("male");
        gender_poss = "his";
        gender_Subj = "He";
        gender_subj = "he";
        gender_obj = "him";
    } else {
        set_gender("female");
        gender_poss = "her";
        gender_Subj = "She";
        gender_subj = "she";
        gender_obj = "her";
    }
    set_long("%^RESET%^The corpse of a %^CYAN%^Tecqumin %^RESET%^noble, wrapped"
             + " in %^BOLD%^%^WHITE%^cloth%^RESET%^, preserved with %^BLUE%^embalming"
             + " %^RESET%^fluids and animated with %^BLUE%^secret %^BOLD%^m%^RESET%^"
             + "%^MAGENTA%^a%^BOLD%^%^BLUE%^g%^RESET%^%^BLUE%^i%^BOLD%^cs%^RESET%^. "
             + gender_Subj + " moves with a deceptive, lurching speed, and "
             + gender_subj + " long dead limbs possess a horrible strength. The entire"
             + " body is swathed in %^BOLD%^%^WHITE%^wrappings%^RESET%^, with a%^BOLD%^"
             + " %^CYAN%^mask%^RESET%^ over the face, presumably representing how "
             + gender_subj + " looked in life.");
    set_size(2);
    set("aggressive", 25);
    set_class("fighter");
    set_mlevel("fighter", 50);
    level = 50;
    set_guild_level("fighter", 50);
    set_hp(random(1500) + 1000 + random(400));
    set_max_level(50);
    set_property("swarm", 1);
    set_alignment(7);
    set_overall_ac(-70);
    set_size(2);
    add_attack_bonus(70);
    set_property("magic", 1);
    set_monster_feats(({
        "power attack",
        "rush",
        "damage resistance",
        "shatter",
        "sunder",
        "daze",
        "unarmed fighting"
    }));
    set_stats("strength", 26);
    set_stats("intelligence", 10);
    set_stats("dexterity", 16);
    set_stats("charisma", 6);
    set_stats("wisdom", 20);
    set_alignment(4);
    set_new_exp(50, "normal");
    set_funcs(({ "shatter", "sunder", "rush", "summon_help", "kill_fodder" }));
    set_func_chance(60);
    set_mob_magic_resistance("average");
    set_property("bludgeoning resistance", 30);
    set_property("slashing resistance", 20);
    set_property("piercing resistance", 10);
    set_attacks_num(8);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({ "left arm", "right arm" }));
    set_damage(7, 6);
    set_property("full attacks", 1);
    set_property("swarm", 1);
    set_property("shapeshifted", 1);   //So that it can rush without a weapon
    will_open_doors(1);
    set_property("no random treasure", 1);
    BEAT = 0;
    heartcount = 0;
    check_my_heart();
}

void init()
{
    ::init();
}

void heart_beat()
{
    ::heart_beat();
}

void check_my_heart()
{
    if (heartcount > 300) {
        return;
    }
    if (BEAT > 7) {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart", 1);
        return;
    }
    BEAT++;
    call_out("check_my_heart", 1);
    return;
}

string get_id(object ob)
{
    return ob->query_name();
}

void kill_fodder()
{
    int i, count;
    object* critters;
    critters = query_attackers();
    count = sizeof(critters);
    if (count < 1) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    tell_room(ETO, "%^BLUE%^A cloud of %^BOLD%^%^BLACK%^dark energy"
              + "%^RESET%^%^BLUE%^ bursts from the %^ORANGE%^Mummy");
    for (i = 0; i < count; i++) {
        if (interactive(critters[i]) || critters[i] == TO || critters[i]->is_merc()) {
            continue;
        }
        if (critters[i]->fort_save(17)) {
            tell_room(ETO, "%^BOLD%^%^BLACK%^" + critters[i]->QCN + "%^BOLD%^%^BLACK%^"
                      + " gasps as its energy is drained by the dark cloud");
            critters[i]->cause_typed_damage(TO, "torso", 100 + random(800), "negative energy");
        } else {
            tell_room(ETO, critters[i]->QCN + " %^RESET%^%^BLUE%^shrugs off the worst"
                      + " of the cloud's effects");
            critters[i]->cause_typed_damage(TO, "torso", 100 + random(200), "negative energy");
        }
    }
}

void sunder()
{
    object* critters;
    string who;
    critters = query_attackers();
    if (sizeof(critters) < 1) {
        return;
    }
    who = critters[random(sizeof(critters))]->query_name();
    force_me("sunder " + who);
}

void shatter()
{
    object* critters;
    string who;
    critters = query_attackers();
    if (sizeof(critters) < 1) {
        return;
    }
    who = critters[random(sizeof(critters))]->query_name();
    force_me("shatter " + who);
}

void rush()
{
    object* critters;
    string who;
    critters = query_attackers();
    if (sizeof(critters) < 1) {
        return;
    }
    who = critters[random(sizeof(critters))]->query_name();
    force_me("rush " + who);
}

void summon_help()
{
    int i, num, target;
    object room, ob;
    target = 1 + random(2);
    num = 0;
    if (!objectp(ETO)) {
        return;
    }
    if (!interact("corridor", base_name(ETO))) {
        return;
    }
    tell_room(ETO, "The %^ORANGE%^mummy %^RESET%^tilts its head back and lets"
              + " out an unsettling, moaning cry");
    for (i = 1; i < 8; i++) {
        if (!file_exists(ROOMS + "corridor" + i + ".c")) {
            continue;
        }
        room = find_object_or_load(ROOMS + "corridor" + i);
        if (objectp(room)) {
            if (room->query_mummy() < 1) {
                continue;
            }
            room->set_mummy(0);
            ob = new(MOB + "mummy");
            ob->move(room);
            DESTINATIONS_D->generate_waystations(base_name(ETO), 2, 2);
            ob->start_walking(base_name(ETO));
            num++;
            if (num >= target) {
                break;
            }
        }
    }
}
