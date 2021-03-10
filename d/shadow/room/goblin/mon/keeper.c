//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
// changed aggro to 18 to auto everyone, increased level from 2 to 5
// hp from 32 to 55, added swarm & max_level, etc. Styx 7/11/01

#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/std/monster";

void create()
{
    ::create();
    set_name("goblin");
    set_id(({ "goblin", "gatekeeper", "goblin gatekeeper" }));
    set_short("Goblin gatekeeper");
    set("aggressive", 19);
    set_hd(5, 2);
    set_long("This foul and ugly little creature is "
             "one of the gatekeepers of the Goblin stronghold. They are "
             "Goblins of reknown ability to stay awake for lengthy "
             "amounts of time...or at least to appear too. Their one main "
             "flaw is they have no clue as to who they should keep out of "
             "the stronghold and who they can let in.");
    set_level(5);
    set_class("fighter");
    set_body_type("human");
    set_alignment(9);
    set_new_exp(8, "very high");
    set_max_level(7);
    set_race("goblin");
    set_gender("male");
    set_ac(5);
    set_max_hp(55);
    set_hp(55);
    set_property("swarm", 1);
    set_achats(3, ({
        "Goblin gatekeeper spits something green and nasty looking at you.",
        "%^CYAN%^Goblin says: %^RESET%^Umm...are you allowed in or not?  Sure, we take your life and gold!",
        "%^RED%^Goblin soldier cackles as he slices at your kneecap!",
        "Gatekeeper yells: %^RED%^EEIYYEEIIIEEE go 'way!%^RESET%^",
        "Gatekeeper yells: %^RED%^King assassin getcha if you go dere!%^RESET%^",
    }));
    this_object()->add_money("gold", random(50) + 5);
    this_object()->add_money("silver", random(100) + 15);
    this_object()->add_money("copper", random(1000) + 50);
    new(OPATH "lsword.c")->move(TO);
    command("wield longsword");
    if (!random(10)) {
        new(OPATH "lboot.c")->move(TO);
        command("wear boot");
        new(OPATH "rboot.c")->move(TO);
        command("wear boot");
    }
    set_monster_feats(({ "parry" }));
}

void init()
{
    string mrace = TP->query_race();
    ::init();
    if (TP->query_invis() || mrace == "goblin") {
        return;
    }
    command("block north");
}
