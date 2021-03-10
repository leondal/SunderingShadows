#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "A narrow alley");
    set("long",
      "This narrow alley is cluttered with junk and is not nearly as "
      "beautiful as its extension across Centre Path.  The local Post "
      "Office is on the south side of the alley, and the bank is north.");
    set_exits( 
	      (["north" : "/d/standard/bank",
		"south" : "/d/standard/post",
		"east" : "/d/standard/s_centre2",
		"west" : "/d/standard/alley2"]) );
    set_items( 
	(["path" : "It intersects the alley to the east.",
	  "bank" : "The place where the local people keep their money safe.",
	  ({"office", "post", "post office"}) : "You can send and receive "
	  "mail to other people here or on other muds there.",
	  "alley" : "It looks much nicer across Centre Path east."]) );
}

