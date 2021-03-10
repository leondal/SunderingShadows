//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void create(){
    	::create();
   	set_short("%^BOLD%^%^MAGENTA%^Daelmas' Office%^RESET%^");
    	set_long(
    		"%^RESET%^%^CYAN%^"+
    		"This is a short alcove ending in a %^BOLD%^%^MAGENTA%^purple "+
    		"%^RESET%^%^CYAN%^door.\n"+
    		"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The smell of old, dry, crumbling parchment dominates "+
    		"this room and keeps you on the verge of a sneezing fit.");
    	set_listen("default","The room is very quiet.");
     	set_exits(([
   		"northeast" : MROOMS+"moslib",
   		"southwest" : MROOMS+"moslib3"
 	]));

    	set_door("purple door",MROOMS+"moslib3","southwest","guild earring");
    	set_locked("purple door",1,"lock");
     		(MROOMS+"moslib3")->set_locked("purple door",1,"lock");
    	set_door_description("purple door","The door is a "+
    		"normal looking door made from oak and painted %^BOLD%^%^MAGENTA%^purple "+
		"%^RESET%^with a simple lock. The name %^BOLD%^%^MAGENTA%^Daelmas %^RESET%^"+
		"is carefully and artistically rendered in "+
		"%^BOLD%^%^WHITE%^mother of pearl %^RESET%^at the top of the door.");
    	lock_difficulty("purple door",10,"lock");
   	set_string("purple door","open","You open the "+
   		"door noiselessly into a mage's office.\n");

	set_trap_functions(({"purple door"}),({"drop_me"}),({"pick"}));
}
int drop_me(string str){
	tell_object(TP,"You feel your tools catch in the lock and then you feel the "+
		"floor give way beneath you.\n");
	TP->force_me("emote yelps!");
	tell_room(TO,""+TPQCN+" drops out of sight through a hole in the floor!\n",TP);
	TP->move(MROOMS+"mospit");
	tell_object(TP,"%^BOLD%^%^RED%^You tumble into a dark pit\n!");
	TP->do_damage("torso",roll_dice(30,10));
	tell_object(TP,"%^BOLD%^%^RED%^You come to a sudden painful stop at the "+
		"bottom of the pit!\n");
	tell_object((MROOMS+"mospit"),"%^BOLD%^%^MAGENTA%^"+TPQCN+" lands with a thud "+
		"right next to you!\n",TP);
      TP->force_me("emote %^BOLD%^%^MAGENTA%^groans");
      toggle_trap("purple door","drop_me","lock"); //added by Circe to allow traps to be disabled
	return 0;
}
