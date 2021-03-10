//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void set_rope(int rope);

int rope_present;

void create(){
	::create();
	set_name("cavern");
	set_short("Cavern");
	set_long(
    	"%^RESET%^%^ORANGE%^"+
    	"This part of the cave is large and airy.  You have entered into a large "+
    	"cavern.  The ceiling is so high that is cannot be seen with the feeble "+
    	"light sources that most surface dwellers must use to see in these caves.  "+
		"Stalagmites dot the floor area and provide many shadows even with the "+
		"best lighting.  The floor here is relatively free of debris as though "+
		"it has been cleared at some point in the recent past.  Guano deposits "+
		"splatter some of stalagmites attesting to the fact there is life in "+
		"the upper-reaches of the cavern.  Patches of mold and fungi add color to "+
		"the otherwise drab appearance of underground stone.  The shadows look a "+
		"little deeper to the east.\n"+
		"%^RESET%^"
    	);
  	set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
	set_property("indoors",1);
	set_property("light",-3);
	set_smell("default","You smell the musty smells of a dry cavern.");
	set_listen("default","Aside from your occasional noises you can hear the "+
		"chirps and squeaks of a colony of bats high above.");
	set_items(([
      ({"molds","fungi","mold","fungus"}) : "Various colors of molds and fungi "+
      	"cling to the walls, floor and ceiling.\n",
		({"stalagmite","stalagmites"}) : "Jutting from the floor these rock "+
			"formations look like old worn dull teeth pointing to the ceiling.\n",
		({"stalactite","stalactites"}) : "Hanging from the ceiling these rock "+
			"formations look like old worn dull teeth pointing towards the floor.\n",
		({"wall","walls"}) : "The rock walls look very solid with an occasional "+
			"dotting of a mold or a fungus to break its monotony.\n",
		"floor" : "Remarkably clear of debris the floor looks like the area may "+
			"have been cleared and cleaned.\n",
		"ceiling" : "The ceiling is high above and lost in the shadows, "+
			"stalactites hang above you threateningly.\n",
		"guano" : "The is bat poop.  Mostly this substance is dry and white, "+
			"but in some cases you find to your disgust it is still quite moist.\n"
   ]));
	set_exits(([
		"southwest" : DROOMS+"c14",
		"west" : DROOMS+"c13",
		"northwest" : DROOMS+"c12"
	]));

   set_climb_exits((["descend":({DROOMS+"cd0",20,6,100})]));
   set_fall_desc("%^BOLD%^%^RED%^You fall a long way tumbling into the "+
		"darkness bouncing off the sides of the tunnel until you come to a sudden "+
		"and painful stop at the bottom!%^RESET%^\n");

	set_search("shadows","You find a hole in the floor to the east.  Maybe if you "+
		"have the courage and the skills you can descend further into the "+
		"darkness.\n");

	set_trap_functions(({"descend"}),({"alarm_em"}),({"descend"}));
}

//not meant to hurt..meant to scare and alert occupant//

int alarm_em(string str){
	tell_object(TP,"%^BOLD%^%^RED%^As you move to descend you feel a tug and "+
		"hear a wire breaking.%^RESET%^\n");
	TP->force_me("emote looks concerned suddenly.");
	TP->force_me("emote gulps.");
	tell_room((DROOMS+"cbed3"),"%^BOLD%^%^RED%^A bell rings one time.",TP);
	tell_room((DROOMS+"cbed4"),"%^BOLD%^%^RED%^A bell rings one time.",TP);
	tell_room((DROOMS+"lab1"),"%^BOLD%^%^RED%^A bell rings one time.",TP);
	return 0;
}