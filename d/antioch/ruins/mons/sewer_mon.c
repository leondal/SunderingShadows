#include <std.h>
#include "../ruins.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("Svrrl");
    set_short("Svrrl, serpent of the deep");
    set_id(({ "svrrl", "Svrrl", "serpent", "deep serpent", "serpent of the deep" }));
    set_long(
        "This great serpent looms high into the air. Her body is slick with the" +
        " slime of the sewers, and her long tail twitches in agitation. Small" +
        " wings are on her back, but they probably would not even get this" +
        " monster off the ground. Dark blue scales cover her entire body, helping" +
        " to protect her from attacks. Her teeth are at least a foot long, and" +
        " they are quite sharp. She has fearsome claws that are ebony black and" +
        " razor sharp. Her appearance inspires fear deep in your heart."
        );
    set_gender("female");
    set_race("serpent");
    set_body_type("dragon");
    set_hd(40, 15);
    set_alignment(9);
    set_max_hp(900 + random(200));
    set_size(4);
    set_hp(query_max_hp());
    set_overall_ac(-20);
    set_max_level(30);
    set_exp(20000);
    set_class("fighter");
    set_mlevel("fighter", 40);
    set_class("mage");
    set_mlevel("mage", 40);
    set_level(40);
    set_attack_limbs(({ "right claw", "left claw", "mouth", "tail" }));
    set_attacks_num(4);
    set_damage(3, 5);
    set_base_damage_type("slashing");
    set_property("swarm", 1);
    set_mob_magic_resistance("average");
    set_property("no dominate", 1);
    set_property("no paralyze", 1);
    set_property("no hold", 1);
    set_property("magic", 1);
    set_property("no bows", 1);
    set("aggressive", 25);
    set_funcs(({ "breath", "sweep", "lunge" }));
    set_func_chance(60);
    set_spells(({
        "color spray",
        "fireball",
        "ice storm",
    }));
    set_spell_chance(50);
    set_resistance("acid", 15);
}

void init()
{
    ::init();
    command("block south");
    if (TP->query_invis() && !avatarp(TP)) {
        tell_object(TP, "The serpent stares right at you with her cold eyes" +
                    " and closes in for the kill!");
        TO->force_me("kill " + TP->query_cap_name() + "");
    }
    if (TP->id("snake")) {
        tell_room(ETO, "%^BLUE%^The serpent lashes her tail, destroying the snakes!");
        TP->die(TO);
        return;
    }
    if (TP->id("horse")) {
        tell_room(ETO, "%^BOLD%^%^RED%^The serpent guts the horse in one quick" +
                  " slice, and almost seems to smile at the poor animal's death screams.");
        TP->die(TO);
        return;
    }
    if (TP->id("summoned monster")) {
        tell_room(ETO, "%^YELLOW%^The serpent lets out a fearsome roar and all" +
                  " the summoned monsters fall to the ground, dead.");
        TP->die(TO);
        return;
    }
}

int query_watched()
{
    return 95;
}

void breath(object targ)
{
    int i, j;
    object* inven;
    inven = all_living(ETO);
    j = sizeof(inven);

    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i] == TO) {
            continue;
        }
        if (!"daemon/saving_d"->saving_throw(inven[i], "paralyzation_poison_death", -5)) {
            tell_object(inven[i], "%^GREEN%^The dragon breathes out a poisonous" +
                        " green vapor that chokes your lungs.");
            inven[i]->add_poisoning(90);
            inven[i]->set_paralyzed(8, "You're coughing too hard to do anything.");
            inven[i]->do_damage("torso", random(5) + 20);
        }else {
            tell_object(inven[i], "%^BOLD%^%^GREEN%^The dragon breathes out a" +
                        " poisonous vapor, you manage not to breath in too many of the fumes," +
                        " but it still burns your lungs.");
            inven[i]->do_damage("torso", random(5) + 20);
        }
    }
}

void sweep(object targ)
{
    int i, j, dex;
    object* inven;
    inven = all_living(ETO);
    j = sizeof(inven);

    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i] == TO) {
            continue;
        }
        dex = inven[i]->query_stats("dexterity");
        if (random(20) < random(dex)) {
            tell_object(inven[i], "%^CYAN%^The dragon sweeps her great tail" +
                        " across the room, knocking you to the floor!");
            inven[i]->do_damage("torso", random(15) + 20);
            inven[i]->set_tripped(1, "You are trying to get up!");
        }else {
            tell_object(inven[i], "%^BOLD%^You manage to jump out of the way as" +
                        " the dragon sweeps her tail across the room.");
        }
    }
}

void lunge(object targ)
{
    int dex, roll;
    dex = targ->query_stats("dexterity");
    roll = random(dex);

    if (random(20) < dex) {
        tell_object(targ, "%^BOLD%^%^BLUE%^The serpent lunges at you, tearing" +
                    " into you viciously with her teeth!");
        tell_room(ETO, "%^BOLD%^%^BLUE%^The serpent lunges at " + targ->query_cap_name() + "" +
                  " tearing into " + targ->query_objective() + " viciously with her teeth.", targ);
        targ->do_damage("torso", random(10) + 50);
    }else {
        tell_object(targ, "%^BOLD%^%^RED%^The serpent lunges at you, but you" +
                    " manage to dodge out of the way in the nick of time.");
        tell_room(ETO, "The serpent lunges at " + targ->query_cap_name() + ", but" +
                  " " + targ->query_subjective() + " manages to dodge out of the way.", targ);
    }
}

void die(object ob)
{
//    if(!random(2)) {
    switch (random(3)) {
    case 0:
        new(OBJ + "scales")->move(TO);
        break;

    case 1:
        new(OBJ + "tooth")->move(TO);
        break;

    case 2:
        TO->add_money("gold", random(1000) + 100);
        break;
    }
//   }
    ::die(ob);
}
