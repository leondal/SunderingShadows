//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void set_rope(int rope);

int rope_present;

void create(){
    	::create();
   	set_short("Entrance");
    	set_long(
    		"%^RESET%^%^ORANGE%^"+
    		"You have found your way into a very small, dry cave.  The floor in the "+
    		"southern portion of this cave seems to have shadows that are darker "+
    		"than other parts of the cave.\n"+
    		"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The cave smells dry and musty.");
    	set_listen("default","You hear occasional animal noises from outside the cave.");
	set_items(([
      	({"molds","fungi","mold","fungus"}) : "Various colors of molds and fungi "+
      		"cling to the walls, floor and ceiling.\n",
		({"wall","walls"}) : "The rock walls look very solid with an occasional "+
			"dotting of a mold or a fungus to break its monotony.\n",
		"floor" : "Remarkably clear of debris the floor looks like the area may "+
			"have been cleared and cleaned.\n",
		"ceiling" : "The ceiling is high above and lost in the shadows.\n"
      ]));
     	set_exits(([
   		"northeast" : "/d/islands/tonerra/path/clear2"
 	]));

	set_search("shadows","You find that the darker shadows in the "+
		"southern part of the cave hides a tunnel leading downward.  Maybe you "+
		"can climb down if you are properly equipped or trained.\n");

     	set_climb_exits((["descend":({MROOMS+"moscom",20,6,100})]));
     	set_fall_desc("%^BOLD%^%^RED%^You fall a long way tumbling into the "+
		"darkness bouncing off the sides of the tunnel until you come to a sudden "+
		"and painful stop at the bottom!%^RESET%^\n");

	set_trap_functions(({"descend"}),({"alarm_me"}),({"descend"}));
}
int alarm_me(string str){
	tell_object(TP,"%^BOLD%^%^RED%^As you move to descend into the tunnel you "+
		"feel a rock press inward under your weight and then you hear a "+
		"barely audible click.%^RESET%^\n");
	TP->force_me("emote looks concerned suddenly.");
	TP->force_me("emote gulps.");
	tell_room((MROOMS+"mosscry"),"%^BOLD%^%^BLUE%^A bell rings one time.",TP);
	tell_room((MROOMS+"moslab"),"%^BOLD%^%^BLUE%^A bell rings one time.",TP);
	tell_room((MROOMS+"moslib"),"%^BOLD%^%^BLUE%^A bell rings one time.",TP);
	tell_room((MROOMS+"moslib1"),"%^BOLD%^%^BLUE%^A bell rings one time.",TP);
	tell_room((MROOMS+"moslib2"),"%^BOLD%^%^BLUE%^A bell rings one time.",TP);
	tell_room((MROOMS+"moslib3"),"%^BOLD%^%^BLUE%^A bell rings one time.",TP);
	tell_room((MROOMS+"moslib4"),"%^BOLD%^%^BLUE%^A bell rings one time.",TP);
	tell_room((MROOMS+"mossmok"),"%^BOLD%^%^BLUE%^A bell rings one time.",TP);
      toggle_trap("descend","alarm_me","descend"); //added by Circe to allow traps to be disabled
	return 0;
}