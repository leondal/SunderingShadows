#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "Centre Path north of Krasna Square");
    set("long",
	"Centre Path is a highly-traveled dirt path that runs "
	"north and south through Praxis.  Just south of here, "
	"it intersects Boc La Road in Krasna Square.  A small "
	"church is off to the west.");
    set_exits( 
	      (["north" : "/d/standard/n_centre2",
		"south" : "/d/standard/square",
		"west" : "/d/standard/cleric_join"]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["path" : "Centre Path leads to Monument square south and out "
	    "of town north.",
	  "road" : "Boc La Road is the main east-west road.",
	  "church" : "It is a small church run by the local clerics.",
	  "square" : "The central square of Praxis."]) );
}

