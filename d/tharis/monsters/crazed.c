//berserked.c
//put his armor in the description and adj. AC accordingly to save memory and
//made the sword randomly a monsterweapon, also made the gold random *Styx* 5/02

#include <std.h>

inherit "/d/tharis/monsters/fwander";

void create(){
        object ob;
	::create();
	
	set_name("crazed battle veteran");
	set_id(({"crazed","man","veteran","crazed battle veteran"}));
	set_short("Crazed battle veteran");
	set_long(
@OLI
This creature was once man but the ongoing battling of good and evil has finally cracked his mind.  Whether he fought for good or evil once he now fights because it is all his mind knows.  Wearing plate mail and a helm, he is clearly dressed for battle rather than hunting animals in these woods for food or sport.  These poor victims of the war have little chance of long survival, but will certainly do damage in the trip to death that they walk.
OLI
	);
	set_hd(18,8);
	set_hp(130);
	set_exp(7000);
        set_max_level(25);
	set_race("human");
	set_gender("male");
	set_alignment(8);
	set_attack_bonus(5);
	set_damage_bonus(5);
	set_body_type("human");
	set_property("no bow",1);
	set_wielding_limbs(({"right hand","left hand"}));
	set_class("fighter");
	set_overall_ac(-3);
	ob = new("/d/common/obj/weapon/two_hand_sword");
	  if(!random(3))   ob->set_property("monsterweapon", 1);
	  ob->move(TO);
	//command("wield sword in right hand and left hand");
    command("wield sword");
	add_search_path("/cmds/fighter");
        if(!random(2)) {
	   add_money("gold",random(300)+100);
	   add_money("platinum",random(100)+50);
	}
}

void init(){
	::init();
	
	if(!interactive(TP))
		if(random(3)) return;
	if(!TP->query_invis())
		kill_ob(TP,1);		
}

void heart_beat(){
	int i, j;
	object *att;
	::heart_beat();
	
   if(!objectp(TO)) return;
   if((att = (object *)(TO->query_attackers()))!= ({})){
		j = sizeof(att);
		for(i = 0;i <j;i++){
			call_out("force_me",2,"rush "+att[i]->query_name());
		}
	}
}
