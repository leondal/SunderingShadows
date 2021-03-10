#include <std.h>
#include "../juran.h"
inherit ROOM;

void create(){
	::create();
	set_property("indoors",1);
	set_short("Juran Weapon's and Stuff");
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_long(
   "This shop looks small and cluttered, but on closer "+
   		"examination the weaponry seems to be well cared for "+
   		"and oiled.  The bugbear shopkeeper seems to make the "+
   		"shop look even littler as he moves about all hunched "+
   		"over to avoid smacking his head on the ceiling.  "+
   		"Everything you need to go out hunting seems to be here "+
   		"for the right price."
    	);
	set_property("light",-2);
    	set_smell("default", "The smell of honing oil, metal, and leather fill the air.");
    	set_listen("default", "The shop is relatively quiet.");
	set_items(([
		({"walls","shelves","equipment","weapons"}) : "The various items that the "+
			"store sells are hung on the walls and stocked on the shelves "+
			"about the store. If you're wanting to look at something, the "+
			"shop keeper will be more than happy to show it to you.",
	]));
	set_exits(([
		"southeast" : JROOMS+"r38"
	]));
}

void reset() {
   	::reset();
   	if(!present("gobsplat")) {
      	new(JMONS+"gobsplat")->move(TO);
   	}
}
