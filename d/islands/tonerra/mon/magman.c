//magman.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("magman");
    set_short("%^RESET%^%^RED%^Fla%^ORANGE%^m%^RED%^ing Ma%^ORANGE%^g%^RED%^man%^RESET%^");
    set_id(({ "magman", "Magman", "Flaming Magman", "flaming", "magmen" }));
    set_long("%^RED%^This small creature looks as if it is solid rock but it is on fire The pointy webbed ears end in flames. Thick solid little legs end with a butt ended 4 toed stump. Long arms end in 5 fingered talons that drag along the ground. A mischievous grin crosses the creature's face. He is the original pyromaniac.");
    //turnign these up to lvl 32-35 - Saide
    //set_hd(14+random(12),10);
    set_hd(38 + random(4), 10);
    //upped from *13 - Saide
    set_hp(query_hd() * 15);
    //set_exp(400*query_hd());
    set_new_exp(35, "very high");
    set_max_level(36);
    set_race("magman");
    set_gender("genderless");
    set_body_type("human");
    set_attack_limbs(({ "right claw", "left claw" }));
    set_base_damage_type("slashing");
    //upped from 2 to 4 - Saide
    set_attacks_num(4);
    set_damage(3, 8);
    set_property("magic", 1);
    set_property("fire resistant", 1);
    set_mob_magic_resistance("average");
    set_hit_funcs((["right claw" : (: TO, "burnem" :), "left claw" : (: TO, "burnem" :) ]));
    set_overall_ac(-6 - random(13));
    set_stats("strength", 20);
    set("aggressive", 25);
    if (!random(2)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("tendril of flame");
        ob->move(TO);
    }
    set_resistance("cold", -15);
    set_resistance_percent("fire", 100);
}

void set_paralyzed(int time, string message)
{
    return 1;
}

void init()
{
    ::init();
    if (!objectp(TP)) {
        return;
    }
    if (wizardp(TP) || TP->query_invis() || !(TP->is_player())) {
        return;
    }
    if ("/daemon/saving_throw_d.c"->reflex_save(TP, -30)) {
        write("%^RED%^%^BOLD%^Magman tries to trip you but you avoid it");
        return;
    }
    TP->set_paralyzed(2, "You got tripped");
    write("%^RED%^%^BOLD%^The magman trips you with a laugh as you enter.");
    say("%^RED%^%^BOLD%^The magman trips " + TPQCN + " as " + TP->QS + " enters and laughs.");
    call_out("setafire", 2, TP);
}

void setafire(object ob)
{
    if (!objectp(ob)) {
        return;
    }

    if (!present("fireflame", TP)) {
        if (TO->Thaco(0, ob, 0) < random(10)) { //turning down the frequency. Was < random(20) ~C~
            tell_object(ob, "%^ORANGE%^With a laugh of glee, " +
                        "the magman reaches out and %^RED%^ignites%^ORANGE%^ " +
                        "you with a magical %^RED%^fire.");
            tell_room(environment(ob), "%^ORANGE%^With a laugh of glee, " +
                      "the magman reaches out and %^RED%^ignites%^ORANGE%^ "
                      + ob->QCN + " with a %^RED%^magical fire.", ob);
            force_me("giggle with glee");
            new(OBJ + "fireflame")->move(ob);
        }
        call_out("moveit", 1);
    }
}

void moveit()
{
    run_away();
}

int burnem(object targ)
{
    if (!objectp(targ)) {
        return 1;
    }

    if (random(20)) {
        return 1;
    }
    tell_room(ETO, "%^RED%^The touch of the magman burns"
              + targ->query_cap_name() + "severely.", targ);
    tell_object(targ, "%^RED%^You are burned severely by the magman's touch.\n");
    targ->do_damage(("torso"), random(50) + 25);
}
