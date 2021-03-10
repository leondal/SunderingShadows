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
    set_id(({ "goblin", "guard", "royal guard", "goblin royal guard" }));
    set_short("Goblin royal guard");
    set("aggressive", 25);
//      set_wimpy(20);
//Stopping them from running as this makes it more difficult and
//less rewarding than it should be in a lowbie area. ~Circe~ 11/1/07
    set_long("This stout and ugly little creature is one of the king's " +
             "personal royal guards. They are Goblins of reknown ability to " +
             "fight in defense of their King and take immense pleasure in " +
             "killing anything in their path.");
    dlevel = random(2) + 6;      // tuned down from random(6)+8 Circe 9/5/03
    set_hd(dlevel, 4);          // and again from random(3) + 6 Styx 3/20/05
    set_class("fighter");
    set_mlevel("fighter", dlevel);
    set_body_type("human");
    set_alignment(9);
    set_race("goblin");
    set_gender("male");
    set_overall_ac(6);      // was 2
    set_stats("strength", 16);     // was 17
    set_stats("dexterity", 14);    // was 17
    //set_exp(dlevel*70);
//        set_exp(650);
    set_new_exp(dlevel, "very high");
    set_max_hp((random(20) + 20 + (dlevel * 7)));
    set_hp(query_max_hp());
    set_monster_feats(({
        "parry"
    }));
    set_achats(2, ({
        "%^CYAN%^Goblin grunts: %^RESET%^Me thrash you silly scum.  Feed you "
        "to assassin and give goblyn you shinies!",
        "Goblin royal guard screams for reinforcements.",
        "Goblin royal soldier glances over his shoulder to the north and shudders.\n" +
        "%^CYAN%^Goblin grunts: %^RESET%^You die now fore king calls him, yup?",
        "%^CYAN%^Goblin grunts: %^RESET%^King sez you die!",
        "%^CYAN%^Goblin whispers: Give me shinies and go, mebbe me let " +
        "you live.%^RESET%^",
        "%^CYAN%^Goblin yells: %^BOLD%^%^RED%^LEAVE NOW!!  I sic goblyn on you!",
    }));
    set_emotes(2, ({
        "Goblin royal guard wipes his snotty nose on his hairy arm.",
        "Goblin royal guard coughs and spits as he glances north.",
        "Goblin royal guard examines you carefully.",
        "%^CYAN%^Goblin whispers: Give me shinies and go, mebbe me let " +
        "you live.%^RESET%^",
        "Goblin royal guard glances slyly at you.",
        "Goblin royal guard flexes his impressive, but diminutive muscles.",
        "Goblin royal guard nearly trips over his greatblade.",
    }), 0);
    add_money("gold", random(80) + 25);
    add_money("silver", random(200) + 15);
    add_money("copper", random(1000) + 50);
    new(OPATH "gsword.c")->move(TO);
    command("wield sword");
    new(OPATH "chain.c")->move(TO);
    command("wear chainmail");
/*
        ob = new("/d/common/obj/potion/healing");
            ob->move(TO);
            ob->set_uses(random(5)+5);
 *** they were a little too tough with them *Styx* */
//      set_property("full attacks",1);
    add_search_path("/cmds/fighter");
//      set_funcs(({"drink_kit","flag_set"}));
//      set_func_chance(50); //taken out to reduce cycling by thieves and bring the area in line difficulty wise
//Circe 12/8/03
    set_max_level(9);
    FLAG = 0;
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
    force_me("parry");
    FLAG = 1;
}

/*
   void drink_kit(){
    if(present("kit") && query_hp() < query_max_hp()/2){
        force_me("open kit");
        force_me("quaff kit");
        force_me("offer bottle");
    }
        if(present("bottle",TO)) force_me("offer bottle");
   }
 */
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
