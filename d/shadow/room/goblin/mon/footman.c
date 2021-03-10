//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include <daemons.h>
#include "/d/shadow/room/goblin/short.h"
inherit MONSTER;

int FLAG, dlevel;

void create()
{
    ::create();
    set_name("goblin");
    set_id(({ "goblin", "footman", "goblin footman", "stronghold goblin" }));
    set_short("Goblin footman");
    set("aggressive", 10);
    set_wimpy(5);
    set_long("This foul and ugly little runt of a creature is one of the " +
             "underlings of the Goblin army. Generally they are left to guard " +
             "the home stronghold as they are too stupid to find a battlefield.  " +
             "Needless to say, they have a short lifespan and make good fodder.");
    dlevel = random(2) + 3;
    set_hd(dlevel, 1);
    set_class("fighter");
    set_mlevel("fighter", dlevel);
    set_body_type("human");
    set_stats("intelligence", 8);
    set_stats("wisdom", 5);
    set_stats("strength", 14);
    set_stats("charisma", 3);
    set_stats("dexterity", 12);
    set_stats("constitution", 10);
    set_alignment(9);
    set_race("goblin");
    set_gender("male");
    set_overall_ac(7);
    //set_exp(dlevel*30);
//        set_exp(500);
    set_new_exp(dlevel, "very high");
    set_max_hp((random(20) + 20 + (dlevel * 7)));
    set_hp(query_max_hp());
    set_achats(3, ({
        "%^CYAN%^Goblin squeaks: %^RESET%^Why bodder me?",
        "%^CYAN%^Goblin squeaks: %^RESET%^Leave, me look da udder way.",
        "Goblin whines.",
        "Goblin looks ready to flee",
        "The goblin looks around for reinforcements.",
        "%^CYAN%^Goblin squeaks: %^BOLD%^%^RED%^GET OUT!!  I sic hidey goblyn on you!",
        "%^CYAN%^Goblin whines: %^RESET%^ACK! WHY YOU STILL HERE?!?!",
        "The goblin looks scared.",
    }));
    set_emotes(3, ({
        "The goblin grunts.",
        "Goblin picks at his ear.",
        "Goblin grumbles to himself.",
        "%^CYAN%^Goblin whines: %^RESET%^Bash, bash, bash...all me do is bash!",
        "The Goblin trips over his feet.",
        "The goblin yawns and scratches himself.",
        "The goblin spys a bug and stomps it into %^BOLD%^%^GREEN%^goo%^RESET%^!",
        "The goblin catches a fat juicy fly and eats it greedily.",
    }), 0);
    add_money("gold", random(20) + 5);
    add_money("silver", random(50) + 15);
    add_money("copper", random(500) + 50);
    new(OPATH "club.c")->move(TO);
    command("wield club");
    new(OPATH "chain.c")->move(TO);
    command("wear chainmail");
    set_property("full attacks", 1);
    add_search_path("/cmds/fighter");
    set_monster_feats(({
        "parry"
    }));
    set_max_level(7);
    set_funcs(({ "flag_set" }));
    set_func_chance(25);
    FLAG = 0;
}

void init()
{
    string mrace = TP->query_race(), mname = TP->query_name();
    ::init();
    if (!objectp(TP)) {
        return;
    }
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
    if (FLAG == 1) {
        return;
    }
    force_me("parry");
    FLAG = 1;
}

void flag_set()
{
    if (FLAG == 0) {
        return;
    }
    if (query_attackers() != ({})) {
        FLAG = 0;
        return;
    }
}
