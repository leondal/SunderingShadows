#include <std.h>
#include "../juran.h"
inherit ROOM;

void create(){
	::create();
	set_property("indoors",1);
	set_short("Juran General Store");
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_long(
   		"This small, disorganized general store is set up with general "+
   		"supplies that commoners need, not that the commoners of this area "+
   		"are able to afford them here, and the items most adventurers need "+
   		"to continue to succeed in their adventures."
    	);
	set_property("light",-2);
    	set_smell("default", "The smell of old leather and burlap fills the air.");
    	set_listen("default", "The quietness of the place is only broken by the "+
    		"shuffling of the storekeeper.");
	set_items(([
		({"walls","shelves","equipment","goods"}) : "The various items that the "+
			"store sells are hung on the walls and stocked on the shelves "+
			"about the store. If you're wanting to look at something, the "+
			"shop keeper will be more than happy to show it to you.",
	]));
	set_exits(([
		"northwest" : JROOMS+"r29"
	]));
}

void reset() {
   	::reset();
   	if(!present("gratus")) {
      	new(JMONS+"gratus")->move(TO);
   	}
}
