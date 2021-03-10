inherit "/std/monster";
#include <std.h>
#include <daemons.h>
#include "../lizard.h"

int FLAG;

void create() {
	object obj; 
  ::create();
  	set_name("war leader");
  	set_id(({"war leader","warleader","lizard","lizardman"}));
  	set("race","lizardman");
  	set_gender("male");
  	set("short","%^BOLD%^%^GREEN%^Lizardman War Leader%^RESET%^");
  	set("long","Standing over 6' tall this lizardman looks to be more lethal "+
  		"than the others.");
  	set_property("water breather",1);
    	set_speed(15);
  	set_overall_ac(2);
  	set_body_type("human");
    	set_class("fighter");
    	set_mlevel("fighter", 22);
    	set_property("full attacks",1);
  	set("aggressive",18);
  	set_alignment(9);
  	set_size(2);
  	set_hd(22,1);
  	set_stats("strength",random(3)+17);
  	set_stats("charisma", 6);
  	set_stats("dexterity",random(3)+16);
  	set_stats("constitution",14);
  	set_stats("wisdom",9);
  	set_stats("intelligence",9);
  	set_hp(150);
  	set_exp(3000);
  	set_wielding_limbs(({"right hand","left hand"}));
  	new(SHWEAP+"trident")->move(this_object());
  		command("wield trident");
  	new(LOBJ+"bone_ring")->move(this_object());
   		command("wear ring");
        if(!random(5))
           new(LOBJ+"green_key")->move(TO);
	obj=new("/d/common/obj/rand/r_helm.c");
		if(random(5)){
	obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/common/obj/rand/rand_chain.c");
	obj->set_property("enchantment",1);
		if(random(4)){
	obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wearall");
  	add_money("silver",random(500));
  	add_money("gold",random(1000));
        add_search_path("/cmds/fighter");
    	FLAG = 0;
    	set_emotes(1,({
		"The lizardman claws at your face.",
		"The warleader licks the blood from his trident!",
		"The warleader hisses loudly for reinforcements.",
		"%^BOLD%^%^GREEN%^Warleader hisses: %^RESET%^Yousss willsss feedsss "+
			"my warriorssss.",
		"%^BOLD%^%^GREEN%^Warleader hisses: %^RESET%^Yousss willsss neversss "+
			"leavesss alivessss!",
 		"The warleader whips his tail at you.",
		"The warleader hisses.",
		"%^BOLD%^%^GREEN%^Warleader hisses: %^RESET%^Yousss don't belongsss heresss!",
		"The warleader tests the air with his forked tongue.",
		"The warleader twitches his tail angrily.",
		"%^BOLD%^%^GREEN%^Warleader hisses: %^RESET%^Sssssoon....ssssoon.",
		"%^BOLD%^%^GREEN%^Warleader hisses: %^RESET%^Youssss kindssss not "+
			"welcomessss heresss.",
		"The warleader flickers his forked tongue in and out.",
		"The warleader narrows his reptilian eyes at you.",
    	}),0);
    	set_funcs(({"flag_set"}));
    	set_func_chance(25);
}
void init(){
	string mrace=TP->query_race();
    	::init();
    	if(avatarp(TP) || TP->query_invis() || mrace == "lizardman") return;
    	call_out("coverass", 2, TP);
}
void coverass(object targ){
      if(!objectp(targ)) return;  //added by Circe 12/5/03
	force_me("kill "+targ->query_name()+"");
	if(!random(25)) force_me("rush "+targ->query_name()+"");
	if (FLAG == 1) return;
	force_me("parry");
	FLAG = 1;
}
void flag_set(){
   	if (FLAG == 0)return;
   	if(query_attackers() != ({})){
		FLAG = 0;
		return;
	}
}
