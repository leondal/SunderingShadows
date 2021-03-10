#include <std.h>

inherit ROOM;

void create() {
    set_property("light", 3);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "East Boc La Road");
    set("long",
      "Just east of here is where Boc La Road intersects East Road "
      "marking the eastern edge of the adventuring town Praxis.  The "
      "gathering place of local adventurers is south of here, with Horace's "
      "Supply Store north of here.");
    set_exits( 
	      (["north" : "/d/standard/supply",
		"south" : "/d/standard/adv_main",
		"east" : "/d/standard/e_boc_la3",
		"west" : "/d/standard/e_boc_la1"]) );
    set_items(
        (["shop" : "A small place where items can be bought and sold.",
        "road" : "A dirt path leading east and west through Praxis.",
        "area" : "Adventurers gather there to form parties and "
	  "discuss their adventures.",
        "square" : "You cannot see it very well from here."]) );
}

