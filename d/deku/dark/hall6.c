#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_short("Gateway to the Abyss");
    set_long(
@KAYLA
You are moving through the core of darkness. This is a long hallway 
of natural caverns.  There are many passages going in many directions.
A vile smell of rotten flesh comes from the south.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/dark/room2",
       "east" : "/d/deku/dark/hall5",
       "north" : "/d/deku/dark/room3"
    ] ));
    set_items(([
    ] ));
}
