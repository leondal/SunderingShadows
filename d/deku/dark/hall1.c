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
There is a ray of light coming from the west.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/dark/stair1",
       "east" : "/d/deku/dark/hall2",
       "north" : "/d/deku/dark/elf1"
    ] ));
    set_items(([
    ] ));
}
