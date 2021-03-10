#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "West Boc La in Praxis");
    set("day long",
      "The local pub on the southwest corner of the square east of here "
      "gets little business at the height of the day.  As twilight falls "
      "into dusk, however, you will notice more people making their way "
      "into the pub to cap off a day of adventure.  The road you are "
      "on, West Boc La, leads into the western districts of Praxis "
      "and in the opposite direction Monument Square, the centre of town."
    );
    set("night long",
      "The street lamps provide you with barely enough light to see "
      "Krasna Square east and Lars' Pub south.  You can also make out "
      "the local church north, but you see no entrance.");
    set_listen_string("default", "Cheers of local adventurers "
		      "resonate from inside the pub.");
    set_exits( 
	      (["east" : "/d/standard/square",
		"west" : "/d/standard/w_boc_la2",
		"south" : "/d/standard/pub"]) );
    set_items( 
	(["church" : "It looks like the entrance might be on the "
	    "road leading north from Monument Square.",
	  ({"lamps", "lamp", "street lamp"}) : "All of the street "
	    "lamps along the road provide minimal light at night.",
	  ({"pub", "lars pub", "lars' pub"}) : "Local adventurers "
	    "wind down their day in Lars' Pub.",
	  ({"road", "west boc la", "boc la"}) : "It goes beyond the "
	    "western districts of Praxis into the mountains.",
	  "square" : "At the centre of Praxis, it is where "
	    "Boc La and Centre Path meet."]) );
}

