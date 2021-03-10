//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit NPC;

string current, LONG, SHORT, NAME;

int x, i;
int BEAR = 0;
int DRAGON = 0;
int GRIFFON = 0;
int DRUID = 0;

void druid_form();
void dragon_form();
void bear_form();
void griffon_form();

void create()
{
    ::create();
    i = 0;
    set_property("unique", 1);
    set_id(({ "druid", "dragon", "owlbear", "griffon", "dragon", "galiedya", "galiedya silvertree", "arch druid" }));
    set_gender("female");
    set_name("Galiedya");
    set_short("Galiedya SilverTree, Arch Druid of Moonstone Vale");
    set_long("Galiedya SilverTree is the Arch Druid of Moonstone Vale." +
             " She is an older woman, probably in her forties, but still has an" +
             " aura of strength and power about her. Her hair is blonde but" +
             " brushed with silver strands. Her eyes are a pale blue that seem" +
             " to hold an eternity of knowledge within their depths. She is a" +
             " pretty woman, but mostly you can sense her strength and will." +
             " She wears the same green robes, belt pouch, and simple sandals" +
             " as the rest of her order, but there is obviously more than meets" +
             " the eye to this woman.");
    set_race("human");
    set_alignment(5);
    set_mob_magic_resistance("very high");
    set_property("magic", 1);
    set_hd(30, 15);
    set_max_level(25);
    set_level(30);
    set_class("cleric");
    set_class("fighter");
    set_mlevel("fighter", 30);
    set_mlevel("cleric", 30);
//   set_exp(10000+i);
    set_new_exp(30, "normal");
    set_max_hp(random(100) + 250);
    set_hp(query_max_hp());
    set_size(2);
    set_overall_ac(-6);
    set_property("no hold", 1);
    set_property("no dominate", 1);
    set_property("no bows", 1);
    set_property("magic", 1);
    set_property("no paralyze", 1);
    set_property("no death", 1);
    set_attack_limbs(({ "left hand", "right hand" }));
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(1, 10);
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

void druid_form()
{
    set_name("Galiedya");
    set_short("Galiedya SilverTree, Arch Druid of Moonstone Vale");
    set_long("Galiedya SilverTree is the Arch Druid of Moonstone Vale." +
             " She is an older woman, probably in her forties, but still has an" +
             " aura of strength and power about her. Her hair is blonde but" +
             " brushed with silver strands. Her eyes are a pale blue that seem" +
             " to hold an eternity of knowledge within their depths. She is a" +
             " pretty woman, but mostly you can sense her strength and will." +
             " She wears the same green robes, belt pouch, and simple sandals" +
             " as the rest of her order, but there is obviously more than meets" +
             " the eye to this woman.");
    set_race("human");
    set_body_type("humanoid");
    set_max_hp(random(100) + 250);
    set_hp(query_max_hp());
    set_size(2);
    set_overall_ac(-6);
    set_attack_limbs(({ "left hand", "right hand" }));
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(1, 10);
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
    if (query_race() == "human" && query_hp() < 90) {
        if (DRAGON == 0) {
            dragon_form();
            tell_room(ETO, "%^BOLD%^%^BLUE%^The arch druid changes" +
                      " her form to that of a dragon!");
            DRAGON = 1;
            i = 9000;
            return 1;
        }
        if (BEAR == 0) {
            bear_form();
            tell_room(ETO, "%^BOLD%^%^GREEN%^The arch druid" +
                      " transforms herself into the shape of a huge owlbear!");
            BEAR = 1;
            i = 12000;
            return 1;
        }
        if (GRIFFON == 0) {
            griffon_form();
            tell_room(ETO, "%^BOLD%^The arch druid changes her shape" +
                      " into that of a griffon.");
            GRIFFON = 1;
            i = 15000;
            return 1;
        }
    }
    if (query_race() == "dragon" && query_hp() < 100) {
        druid_form();
        tell_room(ETO, "%^GREEN%^The arch druid reverts back to her" +
                  " original form.");
        set_hp(330 - CHP);
        return 1;
    }
    if (query_race() == "owlbear" && query_hp() < 70) {
        druid_form();
        tell_room(ETO, "%^GREEN%^The arch druid reverts back to her" +
                  " original form.");
        set_hp(330 - CHP);
        return 1;
    }
    if (query_race() == "griffon" && query_hp() < 30) {
        druid_form();
        tell_room(ETO, "%^GREEN%^The arch druid reverts back to her" +
                  " original form.");
        set_hp(330 - CHP);
        return 1;
    }
}

void dragon_form()
{
    set_name("dragon");
    set_race("dragon");
    set_body_type("dragon");
    set_size(3);
    set_attack_limbs(({ "right foreclaw", "left foreclaw" }));
    set_attacks_num(4);
    set_base_damage_type("slashing");
    set_damage(1, 20);
    set_overall_ac(-16);
    set_short("A large amethyst dragon");
    set_long(
        "This is a very large dragon. Her scales are a dark purple color but her" +
        " eyes remain the pale blue of the arch druid's. Her tail is thrashing" +
        " restlessly and her teeth are bared. Though older, she is still" +
        " very fast and formidable with long, sharp claws and teeth." +
        " This dragon could very easily be the death of you, the arch druid" +
        " obviously knows this form well."
        );
    set_max_hp(random(100) + 800);
    set_hp(query_max_hp());
    set_spell_chance(0);
}

void bear_form()
{
    set_name("owlbear");
    set_race("owlbear");
    set_body_type("quadruped");
    set_short("An owlbear");
    set_size(3);
    add_limb("beak", "head", 0, 0, 0);
    set_attack_limbs(({ "right forepaw", "left forepaw", "beak" }));
    set_base_damage_type("slashing");
    set_attacks_num(2);
    set_damage(1, 12);
    set_hit_funcs((["left forepaw" : (: TO, "bear_hug" :)]));
    set_overall_ac(-6);
    set_max_hp(random(30) + 270);
    set_hp(query_max_hp());
    set_long(
        "The owlbear is large and ferocious looking. It is huge when it" +
        " stands on its hind legs, and you have a very good view of its" +
        " long, sharp, black claws. In addition to the claws, it has a" +
        " ferocious looking beak instead of a normal bear snout. One good" +
        " swipe and she could probably take your head off."
        );
    set_spell_chance(0);
}

void griffon_form()
{
    set_name("griffon");
    set_race("griffon");
    set_body_type("quadruped");
    add_limb("left wing", "torso", 0, 0, 0);
    add_limb("right wing", "torso", 0, 0, 0);
    add_limb("tail", "torso", 0, 0, 0);
    set_size(3);
    set_short("An agitated griffon");
    add_limb("mouth", "torso", 0, 0, 0);
    set_attack_limbs(({ "right forepaw", "left forepaw", "mouth" }));
    set_base_damage_type("slashing");
    set_attacks_num(3);
    set_damage(1, 8);
    set_overall_ac(-6);
    set_max_hp(random(50) + 320);
    set_hp(query_max_hp());
    set_long(
        "The griffon is beautiful in its golden glory, with outstretched" +
        " wings, a lion's body, and an eagle's head and claws. She seems" +
        " quite angry about something and lets out a screech every now" +
        " and then. It would certainly be foolish to mess with such an" +
        " awesome creature."
        );
    set_spell_chance(0);
}

void init()
{
    ::init();
    if ((mixed*)TO->query_attackers() != ({ })) {
        return;
    }
    if (ALIGN->is_evil(TP) && !wizardp(TP)) {
        tell_object(TP, "The Arch Druid turns and looks at you.");
        tell_room(ETP, "The Arch Druid turns and looks at " + TPQCN + ".", TP);
        force_me("say Since you have made it passed the wall you are" +
                 " allowed to stay here, under the condition that you do not cause" +
                 " any trouble.");
        force_me("say This is a sanctuary for all creatures.");
        return 1;
    }
}

int bear_hug(object targ)
{
    tell_object(targ, "%^ORANGE%^The owlbear swipes at you with her" +
                " paw and knocks you down!");
    tell_room(ETO, "%^ORANGE%^The owlbear swipes at " + targ->query_cap_name() + "" +
              " with her paw and knocks " + targ->query_objective() + " down.", targ);
    targ->do_damage("torso", random(5) + 15);
    targ->set_tripped(7, "You're still recovering from that last hit.");
    return 1;
}

void die(object ob)
{
    if (query_race() != "human") {
        druid_form();
        tell_room(ETO, "%^GREEN%^The arch druid reverts back to her" +
                  " true form as she dies.");
    }
    ::die(ob);
}
