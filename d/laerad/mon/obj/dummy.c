//Coded by Bane//
#include <std.h>
inherit MONSTER;
void create(){
    ::create();
    set_id(({"shadow","knight","shadow knight","dummy"}));
    set_name("Shadow Knight");
    set_short("Shadow Knight");
    set_long(
	"Before you stands one of the fabled Dark Knights of Shadow.  "+
	"Bred from birth by a secret clan, these beings are built "+
	"into the perfect killing machines.  It is dressed in a "+
	"black ninja outfit with a blue trim.  He wields a fearsome "+
	"dagger and stares at you with deadly intent.  Prepare yourself "+
	"for mortal combat."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(30,0);
    set_hp(1);
    set("aggressive",22);
    set_overall_ac(-11);
    set_exp(0);
    set_stats("strength",19);
    set_stats("dexterity",18);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_property("no bump",1);
    set_property("full attacks",1);
    set_class("ranger");
    set_guild_level("ranger",30);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/laerad/obj/ice_dagger2")->move(this_object());
    command("wield dagger in right hand");
    new("/d/laerad/mon/obj/sclaw")->move(this_object());
    command("wield claw in left hand");
}
/*
void init(){
    object master, targ;
    master = present("shadow", environment(TO));
    targ = master->query_attackers();
    TO->kill_ob(targ,0);
    return 1;
}
*/
void die(object ob){
    tell_room(ETO,"%^BOLD%^CYAN%^The Shadow Knight explodes into ice!");
    ob->set_paralyzed(20,"You are frozen solid from the ice blast!");
    ::die(TP);
}
void paralyzed(int time,string message){return 1;}
