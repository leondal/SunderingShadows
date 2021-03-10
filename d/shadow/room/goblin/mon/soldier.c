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
    set_id(({ "goblin", "soldier", "goblin soldier" }));
    set_short("Goblin soldier");
    set("aggressive", 12);
//      set_wimpy(10);
//Stopping them from running as this makes it more difficult and
//less rewarding than it should be in a lowbie area. ~Circe~ 11/1/07
    set_long("This foul and ugly little creature is one of the soldiers " +
             "of the Goblin army. Generally they are left either to guard the " +
             "home stronghold or to die on the battlefield. Needless to say, " +
             "they have a short lifespan and make great fodder in large numbers.");
    dlevel = random(2) + 4;
    set_hd(dlevel, 3);
    set_class("fighter");
    set_mlevel("fighter", dlevel);
    set_wielding_limbs(({ "right hand", "left hand" }));
    set_body_type("humanoid");
    set_alignment(9);
    set_stats("intelligence", 8);
    set_stats("wisdom", 8);
    set_stats("strength", 14);
    set_stats("charisma", 3);
    set_stats("dexterity", 14);
    set_stats("constitution", 13);
    set_race("goblin");
    set_gender("male");
    set_overall_ac(6);
    //set_exp(dlevel*35);
//        set_exp(500);
    set_new_exp(8, "very high");
    set_max_hp((random(20) + 10 + (dlevel * 6)));
    set_hp(query_max_hp());
    set_achats(3, ({
        "Goblin soldier swings wildly as his helm falls down over his eyes.",
        "Goblin soldier tries to bite you.",
        "%^CYAN%^Goblin yells: %^BOLD%^%^RED%^LEAVE ME BE!  I tell Goblyn get you!",
        "%^CYAN%^Goblin whines: %^BOLD%^%^RED%^I hope goblyn rogue not get all you "
        "shinies yet!!  I need sum too.",
        "Goblin Soldier spits at your face.",
        "%^CYAN%^Goblin whines: %^BOLD%^%^RED%^WHY BODDER POOR ME?!  Pick on goblyn!",
        "%^CYAN%^Goblin growls: It be hard get you blood off me stuff!!\n" +
        "Goblin soldier smiles wickedly showing many many teeth.",
    }));
    set_emotes(3, ({
        "Goblin soldier scratches his pimply chin.",
        "Goblin soldier's belly rumbles.",
        "Goblin soldier growls.",
        "%^CYAN%^Goblin growls: %^RESET%^What you doin' here?!?  Goblyn get your "
        "shinies?",
        "Goblin soldier looks you over.",
        "Goblin soldier looks worried and checks his pockets.",
    }), 0);
    add_money("gold", random(30) + 25);
    add_money("silver", random(80) + 15);
    add_money("copper", random(800) + 50);
    new(OPATH "whip.c")->move(TO);
    command("wield whip");
    if (!random(5)) {
        new(OPATH "helm")->move(TO);
        command("wear helm");
    }
    if (!random(10)) {
        new(OPATH "chain")->move(TO);
        command("wear chain");
    }
    set_property("full attacks", 1);
    add_search_path("/cmds/fighter");
    set_funcs(({ "flag_set" }));
    set_func_chance(25);
    FLAG = 0;
    set_monster_feats(({
        "parry"
    }));
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
    if (FLAG == 1) {
        return;
    }
    force_me("block north");
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
