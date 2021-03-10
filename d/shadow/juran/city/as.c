#include <std.h>
#include "../juran.h"
inherit ROOM;

void create(){
	::create();
	set_property("indoors",1);
	set_short("Juran Armory");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    	set_long(
   "Armor of many types and sizes are stacked about the room on "+
   		"display.  There is no organization you can discern as "+
   		"leather is placed with bronze and helms mixed with shields, "+
   		"but the armor does appear to be well cared for and in ready "+
   		"working order.  A large diverse party could be equipped from "+
   		"this store easily."
    	);
	set_property("light",-2);
    	set_smell("default", "The smell of oils, metal, and leather fill the air.");
    	set_listen("default", "The shop is relatively quiet.");
	set_items(([
		({"walls","shelves","equipment","weapons"}) : "The various items that the "+
			"store sells are hung on the walls and stocked on the shelves "+
			"about the store. If you're wanting to look at something, the "+
			"shop keeper will be more than happy to show it to you.",
	]));
	set_exits(([
		"south" : JROOMS+"r36"
	]));
}

void reset() {
   	::reset();
   	if(!present("plumbum")) {
      	new(JMONS+"plumbum")->move(TO);
   	}
}
