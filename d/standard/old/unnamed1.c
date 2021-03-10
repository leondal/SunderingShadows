#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "Outside the financial district");
    set("long",
      "Leading out east into the rural lands outside of Praxis, this unnamed "
      "dirt road sits almost entirely untravelled.  The business district "
      "of Praxis is west.");
    set_exits( 
	      (["west" : "/d/standard/s_centre3"]) );
    set_items( 
	(["road" : "It is temporarily blocked going east."]) );
}

