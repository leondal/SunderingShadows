#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "East Road at Sun Alley");
    set("long",
	"Sun Alley shoots off west here from East Road.  "
	"Heading north and south along the eastern border of town, "
	"East Road passes by the quiet Praxis Cemetary. ");
    set_items(
	(["alley" : "A bright and cheery alley which marks the northern "
 	    "boarder of Praxis.",
	  "road" : "East Road is a curvy road running north and south "
	    "on the east side of Praxis.",
	  "cemetary" : "The residents of Praxis get buried there. It "
	    "looks spooky.",
	  "forest" : "A great forest the marks the northern end of Praxis."])
    );
    set_exits( 
	      (["north" : "/d/standard/east_road3",
		"south" : "/d/standard/east_road1",
		"east" : "/d/standard/cemetary/grave_yard",
		"west"	 : "/d/standard/sun2"]) );
}

