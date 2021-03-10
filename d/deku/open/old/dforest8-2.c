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
You are standing on a path deep in the dark and lonely Shadowlord
Forest.  The trees loom above you.  The path continues north deeper
into the forest and toward the southwest.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/open/dforest8-3",
       "southwest" : "/d/deku/open/dforest7-1"
    ] ));
    set_listen("default","The usual sounds of life are strangely absent.");
    set_items(([
    ] ));
}
