//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//boots random now by Styx 7/14/01

#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/std/monster";

void create()
{
    ::create();
    set_name("goblin");
    set_id(({ "goblin", "raider", "goblin raider" }));
    set_short("Goblin raider");
    set("aggressive", 17);
    set_hd(5, 3);
    set_level(5);
    set_long("This foul and ugly little creature is "
             "one of the raiders sent from the Goblin stronghold. They are "
             "Goblins of reknown ability to stay awake for lengthy "
             "amounts of time and to travel swiftly without tire.");
    set_class("fighter");
    set_body_type("human");
    set_alignment(9);
    set_race("goblin");
    set_gender("male");
    set_ac(6);
    set_max_hp(random(10) + 55);
    //set_exp(200);
//    set_exp(500);
    set_new_exp(5, "very high");
    set_max_level(7);
    set_hp(50);
    set_emotes(3, ({
        "Goblin screams: Die scum!",
        "%^CYAN%^Goblin says: %^RESET%^You be pathetic!",
        "Goblin soldier lashes wildly at you!",
    }), 1);
    TO->add_money("gold", random(50) + 5);
    TO->add_money("silver", random(100) + 15);
    TO->add_money("copper", random(1000) + 50);
    new(OPATH "lsword.c")->move(TO);
    command("wield longsword in right hand and left hand");
    if (!random(5)) {
        new(OPATH "lboot.c")->move(TO);
        command("wear boot");
        new(OPATH "rboot.c")->move(TO);
        command("wear boot");
    }
    set_moving(1);
    set_speed(40);
    set_monster_feats(({
        "blade block",
        "sweepingblow",
        "impale",
        "light weapon",
        "strength of arm"
    }));
    set_funcs(({
        "sweepit",
        "impaleit"
    }));
    set_func_chance(30);
}

void impaleit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("impale " + targ->query_name());
}

void sweepit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("sweepingblow " + targ->query_name());
}
