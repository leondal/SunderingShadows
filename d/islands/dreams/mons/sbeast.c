#include <std.h>
#include "../defs.h"
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("shadow beast");
    set_id(({ "beast", "shadow beast", "shadow" }));
    set_short("A shadow beast");
    set_long("%^BOLD%^%^BLACK%^Towering above you is a huge creature that seems " +
             "to just blend into the darkness.  The details are " +
             "hard to make out, but it seems to have a large pair " +
             "of wings sprouting from its back.  A pair of %^GREEN%^" +
             "green eyes glow%^BLACK%^ hanging nearly 15 feet " +
             "above the floor.  A deep rumble emanates from somewhere " +
             "within the beast, and you a notice a large, spiked tail " +
             "as it swishes above your head.");
    set_race("shadow");
    set_body_type("human");
    set_gender("male");
    set_size(3);
    set_hd(30, 2);
    set("aggressive", 25);
    set_class("fighter");
    set_max_level(37);
    set_mlevel("fighter", 30);
    add_limb("mouth", "head", 0, 0, 0);
    add_limb("left wing", "torso", 0, 0, 0);
    add_limb("right wing", "torso", 0, 0, 0);
    add_limb("tail", "torso", 0, 0, 0);
    set_attack_limbs(({ "mouth", "tail", "left hand", "right hand" }));
    set_attacks_num(4);
    set_base_damage_type("piercing");
    set_damage(3, 4);
    set_max_hp(random(200) + 900);
    set_hp(query_max_hp());
    set_exp(9000);
    set_overall_ac(-12);
    set_funcs(({ "spells" }));
    set_func_chance(70);
    set_mob_magic_resistance("average");
    set_property("no paralyze", 1);
    set_property("no dominate", 1);
    set_property("no death", 1);
    set_property("no rush", 1);
    set_alignment(9);
    set_emotes(10, ({
        "%^BOLD%^%^BLACK%^The shadow beast flaps its large, leathery wings.",
        "%^BOLD%^%^GREEN%^You duck as the beast's tail swishes above your head."
    }), 1);
    if (!random(15)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("dream fragment");
        ob->move(TO);
    }
}

void spells(object targ)
{
    switch (random(100)) {
    case 0..10:
        new("/cmds/spells/b/_blink")->use_spell(TO, TO, 20, 100, "mage");
        break;

    case 11..15:
        new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO, 20, 100, "mage");
        break;

    case 16..20:
        new("/cmds/spells/d/_darkbolt")->use_spell(TO, targ, 20, 100, "cleric");
        break;

    case 21..50:
        new("/cmds/spells/s/_scorcher")->use_spell(TO, targ, 20, 100, "mage");
        break;

    case 51..60:
        new("/cmds/spells/i/_ice_storm")->use_spell(TO, targ, 20, 100, "mage");
        break;

    case 61..70:
        new("/cmds/spells/f/_fire_storm")->use_spell(TO, targ, 20, 100, "cleric");
        break;

    case 71..90:
        new("/cmds/spells/a/_acid_orb")->use_spell(TO, targ, 20, 100, "mage");
        break;

    case 91..99:
        new("/cmds/spells/g/_greater_shout")->use_spell(TO, targ, 20, 100, "mage");
        break;
    }
}

void die(object ob)
{
    object ob1;
    object ob2;
    if (!random(2)) { //was if(!random(3)) changed by ~Circe~ 5/11/11
        switch (random(3)) {
        case 0: new(OBJ "dhelm")->move(TO);
            break;

        case 1: new("/d/laerad/obj/bhelm.c")->move(TO);
            break;

        case 2: ob1 = new(OBJ "lyrecase");
            ob1->move(TO);
            ob2 = new(OBJ "crystallyre");
            ob2->move(ob1);
            break;

        default: break;
        }
    }
    new(OBJ "ycryst")->move(TO);
    tell_room(ETO, "From out of the shadows, a %^YELLOW%^" +
              "yellow crystal %^RESET%^appears.");
    ::die(ob);
}
