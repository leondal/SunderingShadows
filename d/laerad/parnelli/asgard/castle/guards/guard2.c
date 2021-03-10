//Coded by Bane//
#include <std.h>
#include <daemons.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit MONSTER;
object *attackers;
object ob;
void create(){
    ::create();
    set_id(({"guard","royal guard"}));
    set_name("royal guard");
    set_short("A royal guard");
    set_long(
	"One of Asgards elite guardsmen.  The best of Asgards soldiers are "+
	"chosen to be the personal royal guards of the king.  They patrol the "+
	"castle of Asgard and keep peace making sure that no one "+
	"not of the royal guard gets into the castle."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(16+(random(8)),5);
    set_hp(query_hd()*10);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_overall_ac(-2);
    set_exp(7000);
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
    ob=new("/d/shadow/obj/armor/banded");
    ob->move(TO);
    ob->set_property("enchantment",2);
    if(random(10)) ob->set_property("monsterweapon",1);
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
