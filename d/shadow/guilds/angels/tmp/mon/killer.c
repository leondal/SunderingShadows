//Coded by Bane//
#include <std.h>
inherit MONSTER;
void create(){
    ::create();
    set_id(({"assassin","killer","angel","angels assassin","angels killer"}));
    set_name("Killer");
    set_short("An assassin");
    set_long("All you can see is a blur of movement.");
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(30,300);
    set_hp(540);
    set_overall_ac(-8);
    set_alignment(9);
    set_exp(10000);
    set_class("assassin");
    set_guild_level("assassin",30);
    add_search_path("/cmds/assassin");
    set_thief_skill("hide in shadows",95);
    set_thief_skill("move silently",95);
    set_mob_magic_resistance("average");
    set_stats("strength",17);
    set_stats("dexterity",25);
    set_stats("charisma",18);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/shadow/guilds/angels/tmp/mon/adagger")->move(this_object());
    command("wield dagger");
    new("/d/shadow/guilds/angels/tmp/mon/adagger")->move(this_object());
    command("wield dagger");      // was wield sword, fixed by Styx 8/2002
    set_invis();
}

void init(){
    ::init();
    if((string)TP->query_name() == "bane"){
	TP->cease_all_attacks();
	TO->cease_all_attacks();
	force_me("stab bane");
	return;
    }
}
/* was bugging and shouldn't be necessary
void heart_beat(){
    ::heart_beat();
    if(!present(TO->query_attackers())){
	TO->cease_all_attacks();
	return;
    }
}
*/