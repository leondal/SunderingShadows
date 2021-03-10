#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Shadowlord Forest");
    set_terrain(HEAVY_FOREST);
    set_travel(DIRT_ROAD);
    set_long(
@KAYLA
You are standing on a path deep in the dark and lonely forest. 
The trees loom above, creating an eerie presence.  Far north
you can see a large keep taking form.  The drawbridge lies 
somewhat to the north.  The path continues north and south.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/keep/rooms/draw",
       "south" : "/d/deku/open/dforest8-5"
    ] ));
    set_items(([
    ] ));
}
