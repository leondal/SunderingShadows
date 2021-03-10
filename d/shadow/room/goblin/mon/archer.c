/*Circe - 12/8/03 - removed kits to lower toughness of the area and thieves cycling for them.  Kits have been added to searches in the tower, but this should put the difficulty of the goblin fortress more in line with what we want here.
 */
//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include <daemons.h>
#include "/d/shadow/room/goblin/short.h"
inherit MONSTER;

int FLAG, dlevel;
object ob;

void create()
{
    ::create();
    set_name("goblin");
    set_id(({ "goblin", "archer", "goblin archer", "stronghold goblin" }));
    set_short("Goblin archer");
    set("aggressive", 15);
    set_max_level(7);
//      set_wimpy(10);
//Stopping them from running as this makes it more difficult and
//less rewarding than it should be in a lowbie area. ~Circe~ 11/1/07
    set_long("This foul and ugly little creature is one of the archers " +
             "of the Goblin stronghold. They are Goblins of reknown ability " +
             "to fire arrows at invaders of their keep. They especially like " +
             "taking pot-shots at elves and squirrels and other furry animals.");
    dlevel = random(3) + 3;
    set_hd(dlevel, 1);
    set_class("fighter");
    set_mlevel("fighter", dlevel);
    set_body_type("human");
    set_stats("intelligence", 8);
    set_stats("wisdom", 5);
    set_stats("strength", 14);
    set_stats("charisma", 3);
    set_stats("dexterity", 15);
    set_stats("constitution", 10);
    set_alignment(9);
    set_race("goblin");
    set_gender("male");
    //set_exp(dlevel*50);
//        set_exp(500);
    set_new_exp(dlevel, "very high");
    set_overall_ac(7);
    set_max_hp((random(30) + 20 + (dlevel * 6)));
    set_hp(query_max_hp());
    set_achats(3, ({
        "Goblin archer looks for places to hide.",
        "%^CYAN%^Goblin speaks: %^RESET%^Me gets reward fo' you me tinkin'.",
        "Goblin archer waves his bow at you like a club.",
        "%^CYAN%^Goblin squeaks: %^RESET%^Stop moving, let me hit you sum.",
        "%^CYAN%^Goblin screams: %^RED%^YOU PAY FER DAT YOU BASTITCH!%^RESET%^",
        "%^CYAN%^Goblin squeaks: %^RESET%^OK, you ask fo dis!",
    }));
    set_emotes(3, ({
        "Goblin archer giggles stupidly.",
        "Goblin archer checks his bow.",
        "Goblin archer picks his nose and admires what he finds.",
        "Goblin archer spits out the window at someone on the ground and giggles.",
        "%^CYAN%^Goblin squeaks: %^RESET%^Look there squirrel! 10 shinies sez "
        "me can pokie left eye out!",
        "Goblin archer waves his bow at you like a club.",
        "Goblin archer looks for places to hide.",
        "Goblin archer rolls his eyes wearily.",
    }), 0);
    add_money("gold", random(50) + 5);
    add_money("silver", random(100) + 15);
    add_money("copper", random(1000) + 50);
    new(OPATH "bow")->move(TO);
    command("wield bow");
    if (!random(8)) {
        new(OPATH "lglove")->move(TO);
        command("wear glove");
        new(OPATH "rglove")->move(TO);
        command("wear glove");
    }
    if (!random(3)) {
        new("/d/shadow/obj/armor/leather")->move(TO);
        command("wear leather");
    }
/*
    if(!random(3)) {
      ob = new("/d/common/obj/potion/healing");
            ob->move(TO);
            ob->set_uses(random(3)+3);
   }
   kits removed by Circe 12/8/03
 */
    set_property("full attacks", 1);
    add_search_path("/cmds/fighter");
    FLAG = 0;
    set_monster_feats(({ "parry" }));
}

void init()
{
    string mrace = TP->query_race(), mname = TP->query_name();
    ::init();
    if (avatarp(TP) || TP->query_invis() || mrace == "goblin" || mname == "dryzil") {
        return;
    }
    call_out("coverass", 2, TP);
}

void coverass(object targ)
{
    if (!objectp(targ) || !objectp(TO)) {
        return;
    }
    force_me("kill " + targ->query_name());
    force_me("block down");
    if (FLAG == 1) {
        return;
    }
    force_me("parry");
    FLAG = 1;
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
/* Circe removed this 12/8/03
    if(present("kit",TO) && query_hp() < query_max_hp()/2){
        command("open kit");
        command("quaff kit");
        command("offer bottle");
    }
        if(present("bottle",TO)) command("offer bottle");
 */
    if (FLAG == 0) {
        return;
    }
    if (query_attackers() != ({})) {
        FLAG = 0;
    }
    return;
}
