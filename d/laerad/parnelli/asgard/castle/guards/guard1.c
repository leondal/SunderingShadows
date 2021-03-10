//Coded by Bane//
#include <std.h>
#include <daemons.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit MONSTER;
object *attackers;
void create(){
    ::create();
    set_id(({"guard","city guard","City guard"}));
    set_name("City guard");
    set_short("A city guard");
    set_long(
	"A city guardsman, here to protect the peaceful citizens of the "+
	"city of Asgard.  They patrol the castle of Asgard keeping peace "+
	"and fighting crime.  These guards are said to be extremely "+
	"honorable and are supposed to keep the castle free of "+
	"anyone not of the royal guard."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(10+(random(8)),15);
    set_hp(query_hd()*10);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_overall_ac(2);
    set_exp(3500);
    set_stats("strength",18);
    set_stats("constitution",18);
    set_stats("dexterity",17);
    set_stats("charisma",17);
    set_damage_bonus(5);
    set_class("fighter");
    set_guild_level("fighter",query_hd());
    add_search_path("/cmds/fighter");
    set_alignment(1);
    add_money("gold",random(500)+150);
    add_money("platinum",random(10)+5);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/shadow/obj/armor/banded")->move(this_object());
    command("wear armor");
    new("/d/shadow/obj/armor/helm")->move(this_object());
    command("wear helm");
    new("/d/shadow/obj/weapon/two_hand_sword")->move(this_object());
    command("wield sword in right hand and left hand");
}
void init(){
    ::init();
    if(wizardp(TP)) return 1;
        if((string)TP->query_race() == "human" || (string)TP->query_race() == "elf"
|| (string)TP->query_race() == "half-elf" || (string)TP->query_race() ==
"dwarf" || (string)TP->query_race() == "gnome" || (string)TP->query_race() ==
"halfling" || (string)TP->query_race() == "horse"){
	    if((string)OVER->query_died() == 1){
             if(interactive(TP)) force_me("kill "+TPQN);
	    }
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
