#include <std.h>

inherit ROOM;

void create() {
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "Monastary stairwell");
    set("long",
        "A spiraling flight of stairs leads up to the monastery "
        "attic and down to the cellar.  The prayer area is west.");
    set_exits( 
	      (["west" : "/d/standard/monastery",
		"up" : "/d/standard/monk_join",
		"down" : "/d/standard/immortal_hall"]) );
    set_items(
        (["stairs" : "They spiral up and down in this old monastery."]) );
    set_property("no castle", 1);
}


