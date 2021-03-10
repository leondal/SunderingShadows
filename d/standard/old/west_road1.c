#include <std.h>

inherit ROOM;

void create() {
    set_property("light", 2);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "The southern end of West Road");
    set("long", 
      "The residential road through rural Praxis, West Road, comes to "
      "a dead end south of here at Boc La Road.  Huts line the road on "
      "all sides.");
    set_items(
	(["road" : "West Road, which marks the westernmost end of Praxis.",
	  "huts" : "They are small peasant huts.",
	  "hut" : "It has a thatch roofing, and is not really extravagant."
	  ]) );
    set_exits( 
	      (["north" : "/d/standard/west_road2",
		"south" : "/d/standard/w_boc_la3"]) );
}

