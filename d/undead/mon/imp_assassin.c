//Added feats - Octothorpe 6/22/10

#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
    ::create();
    set_name("imp");
    set_id(({"imp","assassin","imp assassin"}));
    set_short("%^BOLD%^%^BLACK%^Imp Assassin");
    set_long(
      "%^BOLD%^%^RED%^The assassin imp is a clever and evil creature "
      "that, like the common quasit or traditional imp, serves the "
      "causes of darkness.");
    set_race("imp");
    set_body_type("human");
    set_gender("male");
    set_hd(25,8);
    set_size(1);
    set_overall_ac(0);
    set_class("thief");
    set_mlevel("thief",25);
    set_class("assassin");
    set_mlevel("assassin",25);
    add_search_path("/cmds/thief");
    add_search_path("/cmds/assassin");
    set_hp(400);
    set_property("full attacks",1);
    set_property("swarm",1);
    set_stats("strength",18);
    set_stats("dexterity",20);
    set_thief_skill("move silently",95);
    set_thief_skill("hide in shadows",95);
    set("aggressive","aggfunc");
    set_speed(35);
    set_exp(25000);
    set_new_exp(25,"very high");
    set_speed(40);
    nogo("one");
    set_alignment(9);
    set_emotes(15, ({"%^BOLD%^%^RED%^The Imp assassin slits your throat!%^RESET%^",
	    "%^BOLD%^%^BLACK%^The imp assassin slips through your guard!%^RESET%^",
        "%^BOLD%^%^BLUE%^You stupid fool!  Did you really think you could win?
        %^RESET%^"}),1);
    new(OBJS"sickle_of_venom.c")->move(TO);
    new(OBJS"sickle_of_venom.c")->move(TO);
    command("wield sickle");
    command("wield sickle 2");
    add_money("gold",random(5000)+550);
    add_money("platinum",random(1000)+30);
    set_invis();
	set_monster_feats(({
       "ambidexterity",
	   "two weapon fighting",
	   "improved two weapon fighting",
	   "greater two weapon fighting",
	   "two weapon defense",
	   "dodge",
	   "evasion",
	   "mobility",
	   "scramble",
	   "spring attack"
    }));
}

void aggfunc() 
{
    if(TP->query_true_invis()) { return; }
    if ((string)TP->query_race() == "Imp" || TP->query_invis()) { command("giggle"); return; } 

    command("say Can't have you bothering the master.");
    command("stab "+TPQN+"");
    command("crit "+TPQN+"");
    set_scrambling(1);
    return;
}
