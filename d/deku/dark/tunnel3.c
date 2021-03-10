#include <std.h>

inherit VAULT;

void create(){
::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
	set_name("tunnel");
	set_short("tunnel passage");
	set_long(
    		"%^RESET%^%^ORANGE%^"+
		"The tunnel is dry and dusty.  The walls are formed of rock and "+
		"dirt, but appear to be stable.  Strange tracks cover the floor, "+
		"they look familiar, but then again something is not quite right "+
		"about them.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",0);
	set_smell("default","The tunnel smells cloyingly sweet.");
	set_listen("default","You hear scratching and clicking sounds coming from "+
		"the room to the south.");
	set_items(([
		({"wall","walls"}) : "The rock and dirt walls look very solid with an "+
			"occasional dotting of a mold or a fungus to break its monotony.\n",
		"floor" : "The dirt floor is marked with unusual tracks.\n",
		({"tracks","track"}) : "The tracks are diagonal grooves in the dirt "+
			"like a snake might make, but much too large for that to be true.\n",
		"ceiling" : "The ceiling is made from dirt and rocks and appears to be "+
			"stable in this area.\n"
        	]));

    	set_exits(([
		"southwest" : "/d/deku/dark/lair",
		"northwest" : "/d/deku/dark/tunnel2"
    	]));
}
