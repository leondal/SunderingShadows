#include <std.h>

inherit VAULT;

void create(){
::create();
	set_name("lair");
	set_short("lair");
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
	set_long(
    		"%^GREEN%^"+
		"The tunnel ends in a large cul-de-sac.  The room is warm "+
		"and appears to have been recently used.  Large pieces of molted snake "+
		"skin litter the floor and judging by the pieces the snake must be "+
		"enormous.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",1);
	set_smell("default","The tunnel smells sickly sweet.");
	set_listen("default","You hear scratching and clicking sounds.");
	set_items(([
		({"wall","walls"}) : "The rock and dirt walls look very solid with an "+
			"occasional dotting of a mold or a fungus to break its monotony.\n",
		"floor" : "The dirt floor is marked with many unusual tracks.\n",
		({"tracks","track"}) : "The tracks are a diagonal grooves in the dirt "+
			"like a snake might make, but much too large for that to be true.\n",
		"ceiling" : "The ceiling is higher in the room, at least ten feet high and "+
			"made from dirt and rocks. It appears to be stable in this area.\n"
        	]));

    	set_exits(([
		"northeast" : "/d/deku/dark/tunnel3"
    	]));
}
void reset() {
  	::reset();
  	if(!present("naga") && !random(2)) {
  		new("/d/deku/monster/nagaf")->move(TO);
  	}
}
