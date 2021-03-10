//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit MONSTER;

int wander;
void create()
{
    ::create();
    set_name("goblyn");
    set_id(({ "goblyn", "goblyn rogue", "rogue", "thief", "goblin" }));
    set_short("Goblyn rogue");
    set("aggressive", 3);
    set_hd(7, 4);
    set_level(7);
    set_long("This stout and ugly little creature is "
             "one of the Goblin rogues who make their fortune from others "
             "misfortune. They are "
             "Goblins of reknown ability to steal the pants off a Goblinette "
             "street walker. Furthermore, they can pack a punch when needed. "
             "The King lets them operate in Shadow because they are more "
             "than happy to pay a *small* tribute of their thievery to his "
             "secret treasure hoard."
             );
    add_search_path("/cmds/thief");
    set_thief_skill("pick pockets", 45);
    set_class("thief");
    set_mlevel("thief", 6);
    set_body_type("humanoid");
    set_alignment(9);
    set_race("goblin");
    set_overall_ac(5);
    set_max_level(9);
    set_stats("strength", 16);
    set_stats("dexterity", 18);
    set_max_hp(80);
    set_hp(80);
//    set_exp(1200);
    set_new_exp(7, "very high");
    set_max_level(12);
    set_hidden(1);
    set_scrambling(1);
    set_monster_feats(({
        "dodge",
        "evasion",
        "mobility",
        "scramble",
        "spring attack",
        "combat reflexes"
    }));
    TO->add_money("gold", random(100) + 5);
    TO->add_money("silver", random(300) + 15);
    TO->add_money("copper", random(2500) + 50);
    switch (random(2)) {
    case 0:  new(OPATH "gknife")->move(TO);
        command("wield knife");
        break;

    case 1:  new(OPATH "gdagger")->move(TO);
        command("wield dagger");
        break;
    }
    "/d/common/daemon/randgear_d"->arm_me(TO, "edgeds", 60, 1);
    remove_property("swarm");
    toggle_steal();
}

void heart_beat()
{
    object ob, here, sucker, * players;
    int x, num_p, gold, silver, electrum, platinum, copper, i, j;
    string* exits;
    string exitn;
    ::heart_beat();
    if (random(100) < 50) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    here = ETO;
/***********************************
   removed & have them using thief steal code

    players=all_inventory(here);
    num_p=sizeof(players);
    for(x=0;x<num_p;x++)
    {
    sucker=players[x];
    if(userp(sucker) && !avatarp(sucker)) {
        if(random(15) < 2) {
        if((string)sucker->query_race() == "goblin") {
            message("goblin","Someone cackles in an evil manner.",sucker);
        } else {
            message("sucker","You catch someone with his hand in your pocket."
              ,sucker);
            message("env","You see "+sucker->query_cap_name()+" catch "
              "someone trying to steal something.",ETO,sucker);
        }
        if((string)sucker->query_race() != "goblin") {
            platinum = (int)sucker->query_money("platinum");
            gold = (int)sucker->query_money("gold");
            electrum = (int)sucker->query_money("electrum");
            silver = (int)sucker->query_money("silver");
            copper = (int)sucker->query_money("copper");
            platinum = (95*(platinum/8))/100;
            gold = (95*(gold/8))/100;
            electrum = (95*(electrum/8))/100;
            silver = (95*(silver/8))/100;
            copper = (95*(copper/8))/100;
            sucker->add_money("platinum", -platinum);
            sucker->add_money("gold", -gold);
            sucker->add_money("electrum", -electrum);
            sucker->add_money("silver", -silver);
            sucker->add_money("copper", -copper);
            TO->add_money("platinum", platinum);
            TO->add_money("gold", gold);
            TO->add_money("electrum", electrum);
            TO->add_money("silver", silver);
            TO->add_money("copper", copper);
        }
        }
    }
    }
 **********************************************/
    if (wander > 50) {
        exits = ETO->query_exits();
        i = sizeof(exits);
        j = random(i);
        exitn = (string)ETO->query_exit(exits[j]);
        if (exitn != "/d/shadow/room/forest/road3") {
            TO->force_me(exits[j]);
            wander = 0;
            if (!random(3)) {
                set_hidden(0);
            }
            return;
        } else {
            return;
        }
    } else {
        if (random(5)) {
            set_hidden(1);
        }
        wander = wander + 1;
        return;
    }

    return;
}
