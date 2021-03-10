inherit "/std/monster";
#include <std.h>
// #include <daemons.h>  don't need this
#include "../lizard.h"

int FLAG;

void create() {
        object obj;
    ::create();
    	set_name("lizardman");
    	set_id(({"lizard","lizardman"}));
    	set_race("lizardman");
    	set_gender("male");
    	set_short("%^BOLD%^%^GREEN%^Lizardman%^RESET%^");
    	set_long("Standing over 6' tall this reptile walks on 2 legs like a man.  "+
      	"His hide is green with mottled brown markings.  He looks like he "+
      	"might be a tough customer in a fight.");
    	set_overall_ac(0);
    	set_body_type("human");
    	set_class("fighter");
    	set_mlevel("fighter", 18);
    	set_property("full attacks",1);
    	set("aggressive",18);
    	set_alignment(9);
    	set_size(2);
    	set_hd(18,1);
    	set_stats("strength",random(8)+11);
    	set_stats("charisma", 6);
    	set_stats("dexterity",random(8)+10);
    	set_stats("constitution",10);
    	set_stats("wisdom",9);
    	set_stats("intelligence",9);
    	set_hp(74);
    	set_emotes(1,({
		"The lizardman hisses.",
		"The lizardman hisses loudly for reinforcements.",
		"The lizardman licks the blood from his blade!",
		"The lizardman swing his tail around to hit you.",
		"The lizardman claws at your face.",
		"%^BOLD%^%^GREEN%^Lizardman hisses: %^RESET%^Leave usssss!",
		"The lizardman tests the air with his forked tongue.",
		"The lizardman twitches his tail angrily.",
		"%^BOLD%^%^GREEN%^Lizardman hisses: %^RESET%^Sssssoon....ssssoon.",
		"%^BOLD%^%^GREEN%^Lizardman hisses: %^RESET%^Sssssomeone is "+
			"close...i can tassste them.",
		"The lizardman flickers his forked tongue in and out.",
		"The lizardman narrows his reptilian eyes at you.",
    	}),0);
    	set_exp(1500);
    	set_wielding_limbs(({"right hand","left hand"}));
    	new(SHWEAP+"longsword")->move(this_object());
  		command("wield sword");
  	new(SHWEAP+"shortsword")->move(this_object());
  		command("wield sword");
    	add_money("silver",random(200));
    	add_money("gold",random(50));
      add_search_path("/cmds/fighter");
    	FLAG = 0;
    	set_funcs(({"flag_set"}));
    	set_func_chance(25);
    if(!random(20)) {
      obj = new("/d/common/obj/brewing/herb_special_inherit");
      obj->set_herb_name("reptile scales");
      obj->move(TO);
    }
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
	if(!random(25))force_me("rush "+targ->query_name()+"");
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
