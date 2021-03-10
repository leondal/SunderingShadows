#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "A path in the North Forest");
    set("long",
      "A small path leads through the great North Forest into much denser "
      "and older tree cover north.  South, the forest starts to thin out.");
    set_exits( 
	      (["north" : "/d/standard/forest3",
		"south" : "/d/standard/forest1",
		"east"	 : "/d/18/forest"]) );
    set_items(
        (["path" : "A small path through the huge North Forest.",
	"forest" : "The North Forest.  It is not a very well-traveled "
	  "place."]) );
}

