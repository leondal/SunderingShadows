#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    ::create();
    set_travel(DIRT_ROAD);
    set_terrain(SCRUB_LANDS);
    set_short("Entrance to a vast corn field");
    set_long( ::query_long()+"You can see the dusty road back to the west.");
    set_exits(([
       "south" : "/d/koenig/fields/room/field4",
       "north" : "/d/koenig/fields/room/field2",
       "east" : "/d/koenig/fields/room/field8",
       "west" : "/d/koenig/village/dusty5"
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}
