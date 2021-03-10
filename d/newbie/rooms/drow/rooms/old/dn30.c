#include <std.h>
#include "../drownew.h"

inherit PASSAGE;

void create(){
::create();
  	set_exits(([
		"southwest" : DNROOMS+"dn29",
		"northeast" : DNROOMS+"dn2"
    	]));
    	set_door("door",DNROOMS+"dn29","southwest","iron key");
    	set_locked("door",1,"lock");
     		(DNROOMS+"dn29")->set_locked("door",1,"lock");
    	set_door_description("door","The door is heavily made and is "+
    		"reinforced with iron bands.");
    	set_string("door","open","You open the door into a dark room.\n");

	set_trap_functions(({"door"}),({"stick_em"}),({"pick"}));
}
int stick_em(string str){
	int poison;
	if(str != "lock"){
		return 0;
	}
	toggle_trap("door","pick","lock");
	tell_object(TP,"As you work on the lock with your tools you feel a sudden hitch "+
		"and then a louder click.");
	TP->force_me("emote gulps");
	tell_room(TO,"%^BOLD%^%^RED%^A small hole appears on the south wall.\n");
	tell_room(TO,"%^BOLD%^%^RED%^An arrow shoots out with great velocity!\n");
	tell_object(TP,"The arrow flies directly at you with deadly accuracy!");
	if((int)TP->query_stats("dexterity")>random(25)){
		tell_room(TO,"%^BOLD%^%^RED%^The arrow flies past you into the far wall "+
			"and shatters into splinters!");
		return 0;
	}
	tell_room(TO,"%^BOLD%^%^RED%^The arrow flies into "+TPQCN+" and sticks with a "+
		"sickly thud!",TP);
	tell_object(TP,"%^BOLD%^%^RED%^The arrow flies into you and pierces your "+
		"flesh deeply!");
	TP->do_damage("torso",roll_dice(8,2));
	TP->add_attacker(TO);
	TP->continue_attack();
// remove attacker was missing...
	TP->remove_attacker(TO);
      if((int)TP->query_stats("constitution")>random(25)){
      	tell_object(TP,"You feel the arrowhead burn as it pierces your flesh "+
      		"and then the burning quickly recedes.");
      	return 0;
      }
      poison = roll_dice(15,5);
	TP->setPoisoner(TO);
      TP->force_me("emote %^BOLD%^%^GREEN%^coughs and chokes as the poison from the "+
      	"arrowhead works its way to "+TP->query_possessive()+" system.%^RESET%^\n");
	TP->add_poisoning(poison);
	return 0;
}
