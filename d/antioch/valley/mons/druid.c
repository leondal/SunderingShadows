//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit NPC;

string current, LONG, SHORT, NAME;

int x, i;
int BEAR = 0;
int DRAKE = 0;
int WOLF = 0;
int DRUID = 0;

void druid_form();
void drake_form();
void bear_form();
void wolf_form();

void create()
{
    ::create();
    i = 0;
    set_id(({ "druid", "dragon", "bear", "wolf", "drake", "wolverine", "great bear", "grizzly bear" }));
    set_gender("female");
    set_alignment(5);
    set_mob_magic_resistance("high");
    set_hd(20, 6);
    set_max_level(25);
    set_level(25);
    set_class("cleric");
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_mlevel("cleric", 20);
    set_guild_level("cleric", 20);
//   set_exp(5000+i);
    set_new_exp(20, "high");
    set_property("no hold", 1);
    set_property("no dominate", 1);
    set_property("no bows", 1);
    set_property("magic", 1);
}

void druid_form()
{
    set_name(NAME);
    set_short(SHORT);
    set_long(LONG);
    set_speed(20);
    set_race("half-elf");
    set_body_type("humanoid");
    set_max_hp(random(100) + 150);
    set_hp(query_max_hp());
    set_size(2);
    set_overall_ac(-3);
    set_attack_limbs(({ "left hand", "right hand" }));
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(1, 6);
    set_spells(({
        "call lightning",
        "hold person",
        "cause blindness",
        "limb attack",
        "cause serious wounds",
    }));
    set_spell_chance(80);
    if (!present("pouch")) {
        new(OBJ + "belt_pouch")->move(TO);
    }
    if (!present("belt")) {
        new(OBJ + "rope_belt")->move(TO);
        command("wear belt");
    }
    switch (random(2)) {
    case 0:
        new(OBJ + "herb")->move(TO);
        break;

    case 1:
        new(OBJ + "herb2")->move(TO);
        break;
    }
}

void heart_beat()
{
    int CHP, i, j;
    object* inven;

    CHP = random(40);

    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if (query_race() == "half-elf" && query_hp() < 50) {
        if (DRAKE == 0) {
            drake_form();
            tell_room(ETO, "%^BOLD%^%^BLUE%^The druid changes" +
                      " her form to that of a drake!");
            DRAKE = 1;
            i = 9000;
            return 1;
        }
        if (BEAR == 0) {
            bear_form();
            tell_room(ETO, "%^BOLD%^%^GREEN%^The druid" +
                      " transforms herself into the shape of a huge bear!");
            BEAR = 1;
            i = 12000;
            return 1;
        }
        if (WOLF == 0) {
            wolf_form();
            tell_room(ETO, "%^BOLD%^The druid changes her shape" +
                      " for the last time.");
            WOLF = 1;
            i = 15000;
            return 1;
        }
    }
    if (query_race() == "drake" && query_hp() < 100) {
        druid_form();
        tell_room(ETO, "%^GREEN%^The druid reverts back to her" +
                  " original form.");
        set_hp(230 - CHP);
        return 1;
    }
    if (query_race() == "bear" && query_hp() < 50) {
        druid_form();
        tell_room(ETO, "%^GREEN%^The druid reverts back to her" +
                  " original form.");
        set_hp(230 - CHP);
        return 1;
    }
    if (query_race() == "wolverine" && query_hp() < 30) {
        druid_form();
        tell_room(ETO, "%^GREEN%^The druid reverts back to her" +
                  " original form.");
        set_hp(230 - CHP);
        return 1;
    }
}

void drake_form()
{
    set_name("drake");
    set_race("drake");
    set_body_type("dragon");
    set_size(3);
    set_attack_limbs(({ "right foreclaw", "left foreclaw" }));
    set_attacks_num(4);
    set_base_damage_type("slashing");
    set_damage(1, 10);
    set_overall_ac(-6);
    set_short("A young drake");
    set_long(
        "This is a very young drake. Her scales are a light amethyst color but her" +
        " eyes remain the dark green of the druid's. Her tail is thrashing" +
        " restlessly and her teeth are bared. Though young, her claws are long" +
        " and very sharp. This drake could be the death of you, depending on how" +
        " familiar the druid is with the form. Then again, you still might not" +
        " stand a chance."
        );
    set_max_hp(random(100) + 300);
    set_hp(query_max_hp());
    set_spell_chance(0);
}

void bear_form()
{
    set_name("bear");
    set_race("bear");
    set_body_type("quadruped");
    set_short("A grizzly bear");
    set_size(3);
    set_attack_limbs(({ "right forepaw", "left forepaw" }));
    set_base_damage_type("slashing");
    set_attacks_num(2);
    set_damage(1, 8);
    set_hit_funcs((["left forepaw" : (: TO, "bear_hug" :)]));
    set_overall_ac(-2);
    set_max_hp(random(30) + 170);
    set_hp(query_max_hp());
    set_long(
        "This giant grizzly bear looks very angry. Her fur is brown and shaggy" +
        " and you can see a couple scars running along her back. She's obviously" +
        " survived many fights in this form and is quite proud of it. Her paws" +
        " are very large, they look like they might be able to swipe someone's head" +
        " off with pure strength. Even worse, they are adorned with large, sharp" +
        " looking claws. You definitely don't want to get a closer look at them!" +
        " Her green eyes glare at you and she roars."
        );
    set_spell_chance(0);
}

void wolf_form()
{
    set_name("wolverine");
    set_race("wolverine");
    set_body_type("quadruped");
    set_size(2);
    set_short("A vicious wolverine");
    add_limb("mouth", "torso", 0, 0, 0);
    set_attack_limbs(({ "right forepaw", "left forepaw", "mouth" }));
    set_base_damage_type("slashing");
    set_attacks_num(3);
    set_damage(1, 6);
    set_hit_funcs((["mouth" : (: TO, "wolf_bite" :)]));
    set_overall_ac(0);
    set_max_hp(random(50) + 120);
    set_hp(query_max_hp());
    set_long(
        "The wolverine is one of the most dangerous animals in the wilderness." +
        " This particular one is even more deadly, since the cold intelligence of" +
        " a person stares at you coldly with the druid's green eyes. Her teeth are" +
        " ivory white and you can tell she hungers to sink them into your flesh." +
        " She is crouched down in a defensive pose, ready to attack. You notice the" +
        " razor-sharp claws on her paws and realized that you had better be careful."
        );
    set_spell_chance(0);
}

void init()
{
    object ob;

    ::init();
    if (!x) {
        LONG = TO->query_long();
        NAME = TO->query_name();
        SHORT = TO->query_short();
        x = 1;
    }
    if (ALIGN->is_evil(TP) && !TP->query_invis()) {
        force_me("say Get out of my valley, evil scum! You are upsetting the Balance and for that you shall die!");
        kill_ob(TP, 1);
        return 1;
    }
}

int bear_hug(object targ)
{
    tell_object(targ, "%^YELLOW%^The bear swipes at you with her" +
                " paw and pulls you in for a tight hug!");
    tell_room(ETO, "%^YELLOW%^The bear swipes at " + targ->query_cap_name() + "" +
              " with her paw and pulls " + targ->query_objective() + " in for" +
              " a tight hug.", targ);
    targ->do_damage("torso", random(5) + 5);
    return 1;
}

int wolf_bite(object targ)
{
    tell_object(targ, "%^BOLD%^%^RED%^The wolverine locks her" +
                " jaws onto you and takes a vicious bite!");
    tell_room(ETO, "%^BOLD%^%^RED%^The wolverine locks her jaws" +
              " onto " + targ->query_cap_name() + " and takes a vicious bite" +
              " out of " + targ->objective() + ".", targ);
    targ->do_damage("torso", random(8) + 3);
    return 1;
}

void die(object ob)
{
    if (query_race() != "half-elf") {
        druid_form();
        tell_room(ETO, "%^GREEN%^The druid reverts back to her" +
                  " true form as she dies.");
    }
    ::die(ob);
}

void move_around()
{
    string* exits;
    string exit;

    if (!this_object()) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    ETO->setupExits();
    if (query_current_attacker()) {
        return;
    }
    if (environment(this_object())) {
        exits = (string*)environment(this_object())->query_obvious_exits();
    }else {
        exits = 0;
    }
    if (sizeof(exits)) {
        exit = exits[random(sizeof(exits))];
        (environment(this_object())->query_exit(exit))->init();
        if (exit != "temple") {
            command(exit);
        }
    }
    moving = 0;
}
