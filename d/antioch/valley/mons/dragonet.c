//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit V_WANDER;

string color, gender, tint, possessive, subjective, cposs, subj, objective;

void add_stuff();

void create()
{
    ::create();
    set_name("dragonet");
    set_id(({ "dragonet", "faerie dragon", "dragon", "fairy dragon" }));
    set_short("An innocent faerie dragon");
    switch (random(831)) {
    case 0..100:
        color = "red";
//			set_exp(1000);
        set_new_exp(5, "normal");
        set_mob_magic_resistance("extremely low");
        set_max_hp(random(50) + 50);
        set_class("mage");
        set_mlevel("mage", 5);
        set_class("cleric");
        set_mlevel("cleric", 5);
        set_spells(({
            "magic missile",
        }));
        set_spell_chance(20);
        break;

    case 101..200:
        color = "red-orange";
//			set_exp(1500);
        set_new_exp(6, "normal");
        set_mob_magic_resistance("very low");
        set_max_hp(random(100) + 50);
        set_class("mage");
        set_mlevel("mage", 5);
        set_class("cleric");
        set_mlevel("cleric", 5);
        set_spells(({
            "magic missile",
            "limb attack",
            "hold person",
        }));
        break;

    case 201..300:
        color = "orange";
//			set_exp(2000);
        set_new_exp(10, "normal");
        set_mob_magic_resistance("low");
        set_max_hp(random(50) + 100);
        set_class("mage");
        set_mlevel("mage", 10);
        set_class("cleric");
        set_mlevel("cleric", 10);
        set_spells(({
            "magic missile",
            "hold person",
            "limb attack",
            "call lightning",
        }));
        break;

    case 301..400:
        color = "orange-yellow";
//			set_exp(2500);
        set_new_exp(11, "normal");
        set_mob_magic_resistance("average");
        set_max_hp(random(100) + 100);
        set_class("mage");
        set_mlevel("mage", 10);
        set_class("cleric");
        set_mlevel("cleric", 10);
        set_spells(({
            "magic missile",
            "hold person",
            "limb attack",
            "call lightning",
            "web",
        }));
        break;

    case 401..500:
        color = "yellow";
//			set_exp(3000);
        set_new_exp(12, "normal");
        set_mob_magic_resistance("high");
        set_max_hp(random(150) + 100);
        set_class("mage");
        set_mlevel("mage", 10);
        set_class("cleric");
        set_mlevel("cleric", 10);
        set_spells(({
            "magic missile",
            "hold person",
            "limb attack",
            "call lightning",
            "web",
            "sticks into snakes",
            "flame strike",
        }));
        break;

    case 501..575:
        color = "yellow-green";
//			set_exp(3500);
        set_new_exp(15, "normal");
        set_mob_magic_resistance("very high");
        set_max_hp(random(150) + 150);
        set_class("mage");
        set_mlevel("mage", 15);
        set_class("cleric");
        set_mlevel("cleric", 13);
        set_spells(({
            "magic missile",
            "hold person",
            "call lightning",
            "web",
            "chill touch",
            "flame strike",
            "burning hands",
        }));
        break;

    case 576..625:
        color = "green";
//			set_exp(4000);
        set_new_exp(15, "normal");
        set_mob_magic_resistance("extremely high");
        set_max_hp(random(200) + 175);
        set_class("mage");
        set_mlevel("mage", 15);
        set_class("cleric");
        set_mlevel("cleric", 10);
        set_spells(({
            "magic missile",
            "sleep",
            "call lightning",
            "web",
            "chill touch",
            "flame strike",
            "scorcher",
        }));
        break;

    case 626..700:
        color = "blue-green";
//			set_exp(4500);
        set_new_exp(20, "normal");
        set_mob_magic_resistance("insanely high");
        set_max_hp(random(150) + 200);
        set_class("mage");
        set_mlevel("mage", 20);
        set_class("cleric");
        set_mlevel("cleric", 15);
        set_spells(({
            "magic missile",
            "prismatic spray",
            "ice storm",
            "finger of death",
            "chill touch",
            "fireball",
            "hideous laughter",
        }));
        break;

    case 701..750:
        color = "blue";
//			set_exp(5000);
        set_new_exp(20, "normal");
        set_mob_magic_resistance("insanely high");
        set_max_hp(random(175) + 225);
        set_class("mage");
        set_mlevel("mage", 20);
        set_class("cleric");
        set_mlevel("cleric", 15);
        set_spells(({
            "magic missile",
            "hold person",
            "ice storm",
            "finger of death",
            "ray of enfeeblement",
            "fireball",
            "hideous laughter",
        }));
        break;

    case 751..800:
        color = "blue-violet";
//			set_exp(5500);
        set_new_exp(20, "normal");
        set_mob_magic_resistance("insanely high");
        set_max_hp(random(250) + 200);
        set_class("mage");
        set_mlevel("mage", 20);
        set_class("cleric");
        set_mlevel("cleric", 15);
        set_spells(({
            "magic missile",
            "hideous laughter",
            "ice storm",
            "finger of death",
            "ray of enfeeblement",
            "fireball",
            "chain lightning",
        }));
        break;

    case 801..825:
        color = "violet";
//			set_exp(6000);
        set_new_exp(21, "normal");
        set_mob_magic_resistance("insanely high");
        set_max_hp(random(300) + 250);
        set_class("mage");
        set_mlevel("mage", 20);
        set_class("cleric");
        set_mlevel("cleric", 20);
        set_spells(({
            "magic missile",
            "prismatic spray",
            "ice storm",
            "finger of death",
            "ray of enfeeblement",
            "fireball",
            "chain lightning",
            "fire storm",
            "animate object",
            "powerword kill",
        }));
        break;

    case 826..830:
        color = "black";
//			set_exp(6500);
        set_new_exp(21, "normal");
        set_mob_magic_resistance("insanely high");
        set_max_hp(random(300) + 300);
        set_class("mage");
        set_mlevel("mage", 20);
        set_class("cleric");
        set_mlevel("cleric", 20);
        set_spells(({
            "acid arrow",
            "prismatic spray",
            "ice storm",
            "finger of death",
            "ray of enfeeblement",
            "fireball",
            "chain lightning",
            "fire storm",
            "animate object",
            "powerword kill",
            "lightning bolt",
            "incendiary cloud",
            "phantom guardians",
        }));
        break;
    }
    switch (random(2)) {
    case 0:
        gender = "male";
        tint = "silver";
        possessive = "his";
        cposs = "His";
        subjective = "He";
        subj = "he";
        objective = "him";
        break;

    case 1:
        gender = "female";
        tint = "gold";
        possessive = "her";
        subjective = "She";
        subj = "she";
        cposs = "Her";
        objective = "her";
        break;
    }
    set_long(
        "The faerie dragon is adorable! " + subjective + " is very tiny with a long tail" +
        " and wings like a butterfly's. There is a huge smile on" +
        " " + possessive + " face that makes you want to grin back. " + cposs + " coloring is" +
        " " + color + " and " + subj + " has a slight " + tint + " tinge to " + possessive + " hide which" +
        " denotes " + objective + " as " + gender + "."
        );
    set_hp(query_max_hp());
    set_size(1);
    set_body_type("dragon");
    set_race("dragonet");
    set_gender(gender);
    set_overall_ac(1);
    set_attack_limbs(({ "mouth", "right claw", "left claw" }));
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_damage(1, 3);
    set_alignment(7);
    add_money("gold", random(1000) + 50);
    set_spell_chance(95);
    set_level(20);
    set_stats("intelligence", 20);
    set_stats("wisdom", 18);
    set_emotes(7, ({
        "Someone giggles and it sounds like the tinkling of tiny silver bells.",
        "The wind seems to ruffle your hair.",
        "You feel a hot breath on your neck for a moment.",
        "Something brushes against your leg.",
        "You feel a light touch against your arm.",
        "%^BLUE%^%^BOLD%^You hear the rumble of hooves barreling in your direction.",
        "%^BOLD%^%^WHITE%^Someone rides with tremendous force into you, his weapon doing great damage!",
    }), 0);
    set_funcs(({ "breathweapon" }));
    set_func_chance(10);
    set_property("swarm", 1);
    TO->set_invis();
    add_stuff();
}

//steal\\

void breathweapon(object targ)
{
    tell_room(ETO, "%^BOLD%^%^MAGENTA%^The faerie dragon breathes out cloud of" +
              " pink gas on " + targ->query_cap_name() + ".", targ);
    tell_object(targ, "%^BOLD%^%^MAGENTA%^The faerie dragon breathes" +
                " a cloud of pink gas on you./n");
    if (!"daemon/saving_d"->saving_throw(targ, "breath")) {
        tell_object(targ, "%^BOLD%^%^MAGENTA%^You breathe" +
                    " the gas in and feel light headed.");
        new("/cmds/spells/h/_hideous_laughter.c")->use_spell(TO, targ->query_name(), 20, 100, "mage");
        return 1;
    }else {
        tell_object(targ, "%^MAGENTA%^You are able to barely" +
                    " cling to your senses.");
        return 1;
    }
}

void add_stuff()
{
    object ob;

    //::reset();
    if (!random(2)) {
        if (!present("scroll")) {
            ob = new("/d/magic/scroll");
            ob->set_spell(7);
            ob->move(this_object());
        }
    }
    if (random(9)) {
        if (!present("gem")) {
            switch (random(400)) {
            case 0..300:
                new(OBJ + "gem")->move(TO);
                break;

            case 301..350:
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                break;

            case 351..375:
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                break;

            case 376..400:
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                break;
            }
        }
    }
    if (!present("jewelry")) {
        if (!random(8)) {
            switch (random(200)) {
            case 0..100:
                new(OBJ + "jewelry")->move(TO);
                break;

            case 101..175:
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                break;

            case 176..200:
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                break;
            }
        }
    }
}
