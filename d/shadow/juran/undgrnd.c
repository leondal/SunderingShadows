#include <std.h>
#include "juran.h"
inherit VAULT;

void create(){
::create();
    	set_name("cellar");
	set_short("cellar");
	set_long(
    		"%^RESET%^%^CYAN%^"+
		"The cellar still looks like a cellar oddly enough.  Time and the "+
		"ruination of the buildings upstairs has done little to change this "+
		"place.  Something has definitely been taking up residence in the "+
		"place, but what is anyone's guess.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",-3);
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
	set_smell("default","The smell of decay and rotted wood fills the air.");
	set_listen("default","Aside from the wind blowing through the room upstairs it is "+
		"as quiet as death here.");
	set_items(([
      	({"wall","walls"}) : "Some of the wall is made from stones and "+
      		"brick and other parts of the walls are made from compacted "+
      		"dirt.  Roots from the plants above have bored through the "+
      		"dirt sections.\n",
		({"stair","stairs"}) : "The stairs are made from stone and are "+
			"part of the wall.  They lead up to the ruined building above.\n"
        	]));
}