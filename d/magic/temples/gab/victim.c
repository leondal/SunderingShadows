#include <std.h>
#include <daemons.h>
#include "../loviatar.h"
inherit MONSTER;

int FLAG,dlevel,timer;

create() {
    	::create();
    	set_name("victim");
    	set_id(({"monster","victim"}));
    	set_short("helpless victim chained to the wall");
    	set_long("This wretched creature is barely alive.  "+
    		"There is almost no area visible on it's body that "+
    		"has not been burnt, whipped, cut, or flayed.  The "+
    		"poor fool is naked and covered in grime and its own body wastes."
    	);
    	set_body_type("human");
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
    	set_race(random(2)?"elf":"human");
    	set_overall_ac(9);
    	set_exp(dlevel*5);
    	set_max_hp((random(10)+(dlevel*6)));
    	set_hp(query_max_hp());
    	set_emotes(1,({
			"%^CYAN%^The victim whimpers.",
        	"%^CYAN%^The victim wails.",
        	"%^CYAN%^The victim weeps.",
			"%^CYAN%^The victim tries to cower, but does not have the strength.",
			"%^CYAN%^The victim coughs up some %^BOLD%^%^RED%^blood%^RESET%^%^CYAN%^.",
			"%^CYAN%^The victim rattles his chains weakly.",
			"%^CYAN%^The victim whimpers hoarsely: %^RESET%^please let me go."
    	}),0);
    	set_max_level(5);
    	command("speak common");
    	command("speech whimper");
    	FLAG = 0;
}
void init(){
	::init();
 	add_action("free_em","free");
//  if(avatarp(TP) || TP->query_invis() || !interactive(TP)) return;
}
int free_em(string str) {
   if(present("urgoth"))return 1;
	if(!str) {
   	tell_object(TP,"%^BOLD%^%^CYAN%^Free who?");
      return 1;
   }
  	if(str == "victim"){
   	tell_object(TP,"%^BOLD%^You start to work at the chains "+
   		"restraining the victim and opens the manacles.\n%^RESET%^");
   	tell_room(ETP,"%^BOLD%^"+TPQCN+" starts working on the "+
   		"chains that are restraining the victim opens the "+
      	"manacles.\n%^RESET%^",TP);
   	tell_room(ETP,"The freed victim thanks you profusely and "+
   		"then slips from the room with strength you did not know he had.\n");
		TO->remove();
	}
	return 1;
}
