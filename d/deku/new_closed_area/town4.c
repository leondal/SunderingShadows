#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_property("light",1);
    set_property("indoors",0);
    set_short("Town of Solace");
    set_long(
@KAYLA
You seem to be leaving the small town of Solace.  Most of the buildings
along the main road are constructed of wood, with thatched roofs and
whitewashed or stuccoed walls.  The main road continues towards the
east through the center of the small town, and toward the west is
a rusty iron gate.
KAYLA
    );
    set_exits(([
          "west" : "/d/deku/open/castle/lane1",
       "east" : "/d/deku/new/town3"
    ] ));
    set_listen("default","You hear some birds from within the trees.");
    set_items(([
    ] ));
}

