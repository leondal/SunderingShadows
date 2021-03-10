#include <std.h>
#include "../drownew.h"

inherit VAULT;

// commenting out so don't use memory since not used (meant to be and unfinished?)
// void set_rope(int rope);
// int rope_present;

void create(){
::create();
	set_terrain(BUILT_CAVE);
	set_travel(RUBBLE);
	set_name("dark pit");
	set_short("Dark pit");
	set_long(
    		"%^RESET%^%^RED%^"+
		"The pit is dark and the smell here is terrible.  The floor is "+
		"littered with debris and sharp stones.  Old bones from animals "+
		"that became trapped in this hole litter the floor.  With luck, tools, "+
		"and skill you should be able to climb out of here before you starve "+
		"to death.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",1);
   set_smell("default","This hole smells like something died and rotted here.");
	set_listen("default","You hear only the sounds you make echoed off the walls.");
	set_items(([
      	({"molds","fungi","mold","fungus"}) : "Various colors of molds and fungi "+
      		"cling to the walls, floor and ceiling.\n",
		({"wall","walls"}) : "The rock walls look very solid with an occasional "+
			"dotting of a mold or a fungus to break its monotony.\n",
		"floor" : "The floor is covered with debris and what appears to be bones.\n",
		({"stones","sharp stones"}) : "The stones on the floor, along with the "+
			"bones, make for a very uncomfortable surface to land on."
        	]));

        set_climb_exits((["climb":({DNROOMS+"dn28",6,6,100})]));
    	set_fall_desc("%^BOLD%^%^RED%^You fall back into the pit tumbling into the "+
		"darkness until you come to a sudden and painful stop at the "+
		"bottom!%^RESET%^\n");
}
