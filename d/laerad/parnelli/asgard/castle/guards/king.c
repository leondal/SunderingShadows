//Coded by Bane//
#include <std.h>
#include <daemons.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit MONSTER;
object *attackers;
object ob;
void create(){
    ::create();
    set_id(({"king","asgard king","king of asgard","flagg"}));
    set_name("flagg");
    set_short("The King of Asgard");
    set_long(
	"Before you stands the greatest man in Asgardian history.  "+
	"He is the most noblest, yet most fearsome man you have ever "+
	"seen in your life.  He stands almost 7 feet tall and "+
	"about 5 feet wide.  A long white beard sticks out from "+
	"a grand helmet that covers his majesties head.  A suit "+
	"of the finest full plate armor covers his huge body and "+
	"an ancient trident rests at his side."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(40,10);
    set_hp(410);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_property("no animate",1);
    set_property("no death",1);
    set_overall_ac(0);
    set_exp(22000);
    set_stats("strength",19);
    set_stats("constitution",18);
    set_stats("dexterity",17);
    set_stats("charisma",17);
    set_class("fighter");
    set_guild_level("fighter",query_hd());
    add_search_path("/cmds/fighter");
    set_alignment(1);
    add_money("gold",random(500)+150);
    add_money("platinum",random(10)+5);
    set_wielding_limbs(({"right hand","left hand"}));
    ob = new("/d/shadow/obj/armor/fullplate");
    ob->move(TO);
    ob->set_property("enchantment",3);
    if(random(10)) ob->set_property("monsterweapon",1);
    command("wear armor");
    ob = new("/d/shadow/obj/armor/helm");
    ob->move(TO);
    ob->set_property("enchantment",2);
    if(random(10)) ob->set_property("monsterweapon",1);
    command("wear helm");
    ob = new("/d/laerad/obj/trident");
    ob->move(TO);
    if(random(10)) ob->set_property("monsterweapon",1);
    command("wield trident in right hand and left hand");
}
void init(){
    ::init();
    if(wizardp(TP)) return 1;
        if((string)TP->query_race() == "human" || (string)TP->query_race() == "elf"
|| (string)TP->query_race() == "half-elf" || (string)TP->query_race() ==
"dwarf" || (string)TP->query_race() == "gnome" || (string)TP->query_race() ==
"halfling" || (string)TP->query_race() == "horse"){
	    return 1;
	}
   force_me("kill "+TPQN);
	return 1;
}
void heart_beat(){
        int i, j;
        object *att;
        ::heart_beat();
        if((att = (object *)TO->query_attackers()) != ({})){
                j = sizeof(att);
                for(i = 0;i <j;i++){
                        call_out("force_me",2,"rush "+att[i]->query_name());

                }
	if(OVER->query_alarm() == 0) OVER->sound_alarm(ETO);
    }
}
void die(object ob){
    OVER->king_died(1);
    ob = new("/d/laerad/parnelli/asgard/castle/guards/crown");
    ob->move(TO);
    ::die(ob);
}
