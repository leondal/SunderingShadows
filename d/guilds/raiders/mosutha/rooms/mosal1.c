//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void create(){
    	::create();
   	set_short("%^BOLD%^%^BLUE%^Alcove%^RESET%^");
    	set_long(
    		"%^RESET%^%^CYAN%^"+
    		"This is a short alcove ending in a %^BOLD%^%^BLUE%^blue%^RESET%^ "+
    		"%^CYAN%^door.\n"+
    		"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The smell of old, dry, crumbling parchment dominates "+
    		"this room and keeps you on the verge of a sneezing fit.");
    	set_listen("default","The alcove is very quiet.");
     	set_exits(([
   		"southwest" : MROOMS+"moslib",
   		"northeast" : MROOMS+"moslib1"
 	]));

    	set_door("blue door",MROOMS+"moslib1","northeast","guild earring");
    	set_locked("blue door",1,"lock");
     		(MROOMS+"moslib1")->set_locked("blue door",1,"lock");
    	set_door_description("blue door","The door is a "+
    		"normal looking door made from oak and painted %^BOLD%^%^BLUE%^green "+
		"%^RESET%^with a simple lock.  The name %^BOLD%^%^BLUE%^Mosutha %^RESET%^"+
		"is displayed in %^BOLD%^%^YELLOW%^gold%^RESET%^ lettering at the "+
		"top of the door.");
    	lock_difficulty("blue door",10,"lock");
   	set_string("blue door","open","You open the door "+
   		"noiselessly into a mage's office.\n");

	set_trap_functions(({"blue door"}),({"blow_me"}),({"pick"}));
}
int blow_me(string str){
	tell_object(TP,"As you work on the lock with your tools you feel a sudden hitch "+
		"and then a louder click.\n");
	TP->force_me("emote gulps");
	tell_room(TO,"%^BOLD%^%^YELLOW%^You hear a crackling sound that builds to a "+
		"very loud crescendo.\n");
	tell_room(TO,"%^BOLD%^%^YELLOW%^A bolt of lightning blasts out of the "+
		"door into "+TPQCN+"!%^RESET%^\n");
	tell_object(TP,"%^BOLD%^%^RED%^Your hair stands on end as a bolt of "+
		"lightning blasts you in the chest!%^RESET%^\n");
	tell_room(TO,"%^BOLD%^%^YELLOW%^The bolt flies into "+TPQCN+" and explodes in a loud "+
		"%^BOLD%^%^RED%^F%^BLUE%^L%^RED%^A%^BLUE%^S%^RED%^H%^YELLOW%^!\n",TP);
	tell_object(TP,"%^BOLD%^%^YELLOW%^The bolt explodes into your great pain and a loud "+
		"%^BOLD%^%^RED%^F%^BLUE%^L%^RED%^A%^BLUE%^S%^RED%^H%^YELLOW%^!\n");
	TP->do_damage("torso",roll_dice(30,10));
	TP->add_attacker(TO);
	TP->continue_attack();
      toggle_trap("blue door","blow_me","lock"); //added by Circe to allow traps to be disabled
	return 0;
}
