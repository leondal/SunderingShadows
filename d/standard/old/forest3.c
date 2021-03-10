#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "Deep in the North Forest");
    set("long",
	"You are at the end of a tiny path through the North Forest.  "
        "At the end of the tiny path is a small, dark cavern leading down.  "
	"A smaller dirt path heads northwest into the deep forest.");
    set_exits( 
	      (["south" : "d/standard/forest2",
		"northwest" : "/d/north_forest/path1",
		"down"	 : "/d/standard/kataan_join"]) );
    set_items(
        (["path" : "A small path throught the huge North Forest.",
	  "forest" : "The North Forest.  It is not a very well-"
	  "traveled place.",
	  "cavern" : "Its mysterious maw beckons you to enter."]) );
}
