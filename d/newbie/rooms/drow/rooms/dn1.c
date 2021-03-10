#include <std.h>
#include "../drownew.h"

inherit VAULT;

// commenting out so don't use memory since not used (meant to be and unfinished?)
// void set_rope(int rope);
// int rope_present;
  int creating; // added by Lujke - to help with ensuring mobs load when room created

void create(){
::create();
	set_terrain(BUILT_CAVE);
	set_travel(RUBBLE);
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
		"the otherwise drab appearance of underground stone.  You see a tunnel "+
		"leading upward, but you will have to climb to use that exit.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",1);
	set_smell("default","You smell the musty smells of a dry cavern.");
	set_listen("default","You hear only the sounds you make echoed off the walls.");
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
		"northwest" : DNROOMS+"dn2"
    	]));

        set_climb_exits((["climb":({OUT,6,6,100})]));
    	set_fall_desc("%^BOLD%^%^RED%^You fall back into the tunnel, tumbling and "+
    		"bouncing off the walls, until you come to a sudden and painful stop "+
    		"at the bottom!%^RESET%^\n");
         creating = 1;
// moved to reset to help with longer reboot times
//      new(DNMONS+"ndrowf")->move(TO);
//        new(DNMONS+"ndrowf2")->move(TO);
}

void reset() {
    ::reset();

    if(!present("koboldf"))
    {
        new(DNMONS+"koboldf")->move(TO);
        new(DNMONS+"koboldf1")->move(TO);
        creating = 0;
    }
}
