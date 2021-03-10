//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void create(){
    	::create();
   	set_short("%^BOLD%^%^YELLOW%^Ijan's Office%^RESET%^");
    	set_long(
    		"%^RESET%^%^CYAN%^"+
    		"This is a short alcove ending in a %^BOLD%^%^YELLOW%^yellow "+
    		"%^RESET%^%^CYAN%^door.\n"+
    		"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The smell of old, dry, crumbling parchment dominates "+
    		"this room and keeps you on the verge of a sneezing fit.");
    	set_listen("default","The room is very quiet.");
     	set_exits(([
   		"southeast" : MROOMS+"moslib",
   		"northwest" : MROOMS+"moslib4"
 	]));

    	set_door("yellow door",MROOMS+"moslib4","northwest","guild earring");
    	set_locked("yellow door",1,"lock");
     		(MROOMS+"moslib4")->set_locked("yellow door",1,"lock");
    	set_door_description("yellow door","The door is a "+
    		"normal looking door made from oak and painted %^BOLD%^%^YELLOW%^yellow "+
		"%^RESET%^with a simple lock.  The name %^BOLD%^%^BLACK%^Ijan %^RESET%^is "+
		"burned into the top of the door leaving continually smoking "+
		"%^BOLD%^%^BLACK%^black %^RESET%^letters.");
    	lock_difficulty("yellow door",10,"lock");
   	set_string("yellow door","open","You open the door noiselessly into a "+
   		"mage's office.\n");

	set_trap_functions(({"yellow door"}),({"stick_em"}),({"pick"}));
}
int stick_em(string str){
	int poison;
	if(str != "lock"){
		return 0;
	}
	tell_object(TP,"As you work on the lock with your tools you feel a sudden hitch "+
		"and then a louder click.");
	TP->force_me("emote gulps");
	tell_room(TO,"%^BOLD%^%^RED%^Four small holes appear on the wall to your right.");
	tell_room(TO,"%^BOLD%^%^RED%^Four arrows shoot out with great velocity!");
	tell_object(TP,"The arrows fly directly at you with deadly accuracy!");
	if((int)TP->query_stats("dexterity")>random(25)){
		tell_room(TO,"%^BOLD%^%^RED%^The arrows fly past you into the far wall "+
			"and shatter into splinters!");
            toggle_trap("yellow door","stick_em","lock"); //added by Circe to allow traps to be disabled
		return 0;
	}
	tell_room(TO,"%^BOLD%^%^RED%^The arrows fly into "+TPQCN+" and sink in with a "+
		"sickly thud!",TP);
	tell_object(TP,"%^BOLD%^%^RED%^The arrows fly into you and pierce your flesh deeply!");
	TP->do_damage("torso",(roll_dice(1,8)+3));
	TP->do_damage("torso",(roll_dice(1,8)+3));
	TP->do_damage("torso",(roll_dice(1,8)+3));
	TP->do_damage("torso",(roll_dice(1,8)+3));
	TP->add_attacker(TO);
	TP->continue_attack();
      if((int)TP->query_stats("constitution")>random(25)){
      	tell_object(TP,"You feel the arrows burn as they pierce your flesh.");
            toggle_trap("yellow door","stick_em","lock"); //added by Circe to allow traps to be disabled
      	return 0;
      }
      poison = roll_dice(40,10);
	TP->setPoisoner(TO);
      TP->force_me("emote %^BOLD%^%^GREEN%^coughs and chokes as the poison from the "+
      	"arrows works its way to the bloodstream.%^RESET%^\n");
	TP->add_poisoning(poison);
      toggle_trap("yellow door","stick_em","lock"); //added by Circe to allow traps to be disabled
	return 0;
}