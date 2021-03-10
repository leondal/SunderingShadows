#include <std.h>
#include "juran.h"
inherit VAULT;

void create(){
::create();
    	set_name("ruined building");
	set_short("ruined building");
	set_long(
    		"%^RESET%^%^GREEN%^"+
		"This building lies in ruins.  Walls are partially collapsed "+
		"and next to no roof remains.  This place has been open to the "+
		"elements for a long time and vegetation and mold grows on what "+
		"is left of the rotted wood.  The area show signs of habitation, "+
		"but by what is anyone's guess.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",0);
	set_property("light",1);
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
	set_smell("default","The smell of decay and rotted wood fills the air.");
	set_listen("default","Aside from the wind blowing through the room it is "+
		"as quiet as death here.");
	set_items(([
      	({"wall","walls"}) : "More wall is in rubble at your feet than "+
      		"is still standing.\n",
		({"weed","weeds","mold"}) : "Weeds, mold, and other vegetation poke "+
			"up from the rotting wood and crumbling stone.\n",
		({"stones","stone","chunks","chunk"}) : "Much of the stone comes "+
			"from the collapsed walls and ceiling.\n",
		"roof" : "Very little of the roof remains above your head."
        	]));
}
