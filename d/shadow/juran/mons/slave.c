#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,timer;

create() {
    	::create();
    	set_name("slave");
    	set_id(({"monster","slave"}));
    	set_short("slave");
    	set_long("This wretched creature was once free, but now is "+
    		"a slave to the gnoll slavemaster.  Wearing only rags, this "+
    		"slave is covered in filth and looks to be severely underfed. ");
    	set_body_type("humanoid");
     	set_gender(random(2)?"male":"female");
   	dlevel = random(3) + 1;
    	set_hd(dlevel,4);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
  	set_size(2);
    	add_search_path("/cmds/fighter");
      set_wielding_limbs(({"right hand","left hand"}));
    	set_stats("intelligence",10);
    	set_stats("wisdom",10);
    	set_stats("strength",8);
    	set_stats("charisma",6);
    	set_stats("dexterity",10);
    	set_stats("constitution",4);
    	set_alignment(5);
    	set_race(random(2)?"elf":"half-elf");
    	set_overall_ac(9);
    	set_exp(dlevel*5);
    	set_max_hp((random(10)+(dlevel*6)));
    	set_hp(query_max_hp());
    	set_achats(0,({
		"%^CYAN%^Slave cries: %^RESET%^Please not again.",
		"Slave covers its head to avoid the blows.",
		"Slave dodges and ducks.",
		"%^CYAN%^Slave: %^RESET%^I'm sorry, please stop!",
		"%^CYAN%^Slave: %^RESET%^I'll behave, just stop hurting me please!",
		"%^CYAN%^Slave screams: %^BOLD%^%^RED%^You're going to kill me!!%^RESET%^",
    	}),0);
    	set_emotes(0,({
		"Slave keeps his eyes to the ground.",
        	"Slave drags his feet.",
		"Slave breathes with great effort.",
		"Slave adjusts his chaffing chain collar.",
    	}),0);
    	set_max_level(5);
    	command("speak common");
    	command("speech whimper");
    	FLAG = 0;
}
void init(){
    	::init();
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(base_name(ETO) == "/d/shadowgate/void")  return;
    	if(!present("gnoll")){
    		tell_room(ETO,"The slave flees from the room.");
			TO->move("/d/shadowgate/void");
			TO->remove();
         return;
	}
    	if(avatarp(TP) || TP->query_invis() || !interactive(TP)) return;
	if(is_beastrace(TP)){
		call_out("fearem",0,TP);
		return;
	}
	if(is_surfacerace(TP)){
		call_out("pleadem",0,TP);
		return;
	}
	call_out("fearem",0,TP);
	return;
}
void pleadem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if(!random(3))force_me("emote pleads with you with its eyes.");
	if (FLAG == 1) return;
	if(!random(3))force_me("emote looks at you sadly.");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if(!random(3))force_me("quiver");
	if (FLAG == 1) return;
	if(!random(3))force_me("emote trembles with fear.");
	FLAG = 1;
}
void heart_beat() {
    	::heart_beat();
  	if(!objectp(TO)) return;
  	if (!objectp(ETO)) return;

   	if (FLAG == 0)return;
    	timer++;
    	if(timer > 100){
      	timer = 0;
		if(query_attackers() != ({}))FLAG = 0;
    		return;
    	}
}
