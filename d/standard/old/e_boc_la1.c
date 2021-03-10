#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "East Boc La south of the monastary");
    set("long",
      "Boc La Road on the east side of the town is a simple dirt road "
      "leading towards Krasna Square at the centre of Praxis west and out "
      "into the western outskirst west.  The village monastary is on "
      "the north side of the road.");
    set_exits( 
	      (["north" : "/d/standard/monastery",
		"east" : "/d/standard/e_boc_la2",
		"west" : "/d/standard/square"]) );
    set_items(
	      (["road" : "Boc La Road, the main east-west path "
		  "through Praxis.", 
		"monastery" : "The monks of Nightmare make their home there.", 
		"square" : "Krasna Square, the center point of "
		  "Praxian life."]) );
}

