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
You are moving through the core of the underdark. Upon entering this room,
your torch flickers as you examine the many passages which lead
deeper into the darkness.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/dark/hall1",
       "east" : "/d/deku/dark/hall3",
       "north" : "/d/deku/dark/room1",
       "south" : "/d/deku/dark/room6"
    ] ));
    set_items(([
    ] ));
}
