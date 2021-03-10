#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Gateway to the Abyss");
    set_long(
@KAYLA
The walls of this cavern are dotted with manacles and hanging
chains.  Most of them have almost rusted away.  A number of bones
are scattered on the ground.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/dark/lizard",
       "south" : "/d/deku/dark/hall2"
    ] ));
    set_items(([
       "bones" : "Scattered bones of many creatures lay about."
    ] ));
}
