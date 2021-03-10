#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "Southern Praxis");
    set("day long", "Southern Praxis is the business district of this "
      "small adventuring community.  Through it runs Centre Path, "
      "bringing people from the centre of town through here and southwest "
      "towards the town port.  As the day hits its peak, the area really "
      "begins to rumble with horse and foot traffic.");
    set("night long",
      "The business district of Praxis nearly slumbers save a few nocturnal "
      "races of adventurer.  Centre path winds down from the north out to "
      "the Port of Praxis southwest.  An unnamed road heads east.");
    set_exits( 
	      (["north" : "/d/standard/s_centre2",
		"southwest" : "/d/standard/s_centre4",
		"east" : "/d/standard/unnamed1"]) );
    set_items( 
	([({"path", "centre path"}) : "The main road leading north and "
	    "south through Praxis.",
	  ({"port", "port of praxis"}) : "You cannot see that from here.", 
	  ({"road", "unnamed road"}) : "It leads out of town."]) );
    set_listen_string("road", "An eerie silence fills the air that way.");
}

