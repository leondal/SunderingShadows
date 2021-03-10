//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void create(){
    	::create();
   	set_short("%^BOLD%^%^RED%^Nightfall's Office%^RESET%^");
    	set_long(
    		"%^RESET%^%^CYAN%^"+
    		"This is a short alcove ending in a %^BOLD%^%^RED%^red "+
		"%^RESET%^%^CYAN%^door.\n"+
    		"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The smell of old, dry, crumbling parchment dominates "+
    		"this room and keeps you on the verge of a sneezing fit.");
    	set_listen("default","The room is very quiet.");
     	set_exits(([
   		"northwest" : MROOMS+"moslib",
   		"southeast" : MROOMS+"moslib2"
 	]));

    	set_door("red door",MROOMS+"moslib2","southeast","guild earring");
    	set_locked("red door",1,"lock");
     		(MROOMS+"moslib2")->set_locked("red door",1,"lock");
    	set_door_description("red door","The door is a normal "+
    		"looking door made from oak and painted %^BOLD%^%^RED%^red %^RESET%^with "+
    		"a simple lock.  The name %^BOLD%^%^RED%^Nightfall%^RESET%^ is "+
    		"emblazened with fire opals at the top of the door.");
    	lock_difficulty("red door",10,"lock");
   	set_string("red door","open","You open the door "+
   		"noiselessly into a mage's office.\n");

	set_trap_functions(({"red door"}),({"spear_me"}),({"pick"}));
}
int spear_me(string str){
	tell_object(TP,"As you work on the lock with your tools you feel a sudden hitch "+
		"and then a louder click.\n");
	TP->force_me("emote gulps");
	tell_room(TO,"%^BOLD%^%^RED%^A small hole appears in the ceiling.\n");
	tell_room(TO,"%^BOLD%^%^RED%^A spear shoots out with great velocity!\n");
	tell_object(TP,"The spear flies directly at you with deadly accuracy!\n");
	if((int)TP->query_stats("dexterity")>random(25)){
		tell_room(TO,"%^BOLD%^%^RED%^The spear flies into the the floor "+
			"and explodes violently in a loud "+
			"F%^YELLOW%^L%^RED%^A%^YELLOW%^S%^RED%^H%^YELLOW%^!\n");
		return 1; //changed to return 1 to allow them to be disabled Circe 10/28/03
	   }
	   tell_room(TO,"%^BOLD%^%^RED%^The spear flies into "+TPQCN+" and explodes in a loud "+
	         "F%^YELLOW%^L%^RED%^A%^YELLOW%^S%^RED%^H%^YELLOW%^!\n",TP);
	   tell_object(TP,"%^BOLD%^%^RED%^The spear flies into you and explodes in a loud "+
		   "F%^YELLOW%^L%^RED%^A%^YELLOW%^S%^RED%^H%^YELLOW%^!\n");
	   TP->do_damage("torso",roll_dice(30,10));
	   TP->add_attacker(TO);
	   TP->continue_attack();
         toggle_trap("red door","pick","lock");//added by Circe 12/14/03 to allow trap to be disarmed
	   return 0; 
}
//reset added to allow traps to reset
void reset(){
        ::reset();
        if(!trapped("red door"))
                toggle_trap("red door","pick","lock");
}