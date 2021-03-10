#include <std.h>
#include "../drownew.h"

inherit PASSAGE;

// commenting out so don't use memory since not used (meant to be and unfinished?)
// void set_rope(int rope);
// int rope_present;

void create(){
::create();
	set_name("cave passageway");
	set_short("Cave passageway");
	set_long(
    		"%^RESET%^%^ORANGE%^"+
		"The walls glisten with mineral deposits.  Stone surrounds you as you "+
		"make your way through this underground passage.  Stalactites hang from "+
		"the ceiling and stalagmites sprout from the floor like the teeth of a "+
		"hungry beast.  The passage is wide and the ceiling is high.  Molds "+
		"grow in patches on the walls and the floor.  White patches of guano "+
		"speckle the floor and walls.  There is a hole in the center of the "+
		"room that is hidden within the gloom of this passaway.\n"+
		"%^RESET%^"
    	);
//	set_property("indoors",1);  changed to inherit PASSAGE, don't need these
//	set_property("light",1);    changed to inherit PASSAGE, don't need these
	set_smell("default","You smell the musty smells of a dry cave.");
	set_listen("default","You hear only the noises you make echoed off the walls.");
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
			"but in some cases you find to your disgust it is still quite moist.\n",
		({"pit","dark pit","hole"}) : "A dark pit dominates the room with a "+
			"small walkway going around it.  Maybe you can climb down into the pit.\n"
        	]));
  	set_exits(([
		"northeast" : DNROOMS+"dn11",
		"southwest" : DNROOMS+"dn22"
    	]));

        set_climb_exits((["descend":({DNROOMS+"pit1",6,6,100})]));
    	set_fall_desc("%^BOLD%^%^RED%^You fall into the pit tumbling into the "+
		"darkness until you come to a sudden and painful stop at the "+
		"bottom!%^RESET%^\n");
}
