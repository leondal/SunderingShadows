#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(RUTTED_TRACK);
    set_long( ::query_long()+"The entrance and a dusty road lie to the west.");
    set_exits(([
       "south" : "/d/koenig/fields/room/field9",
       "north" : "/d/koenig/fields/room/field7",
       "east" : "/d/koenig/fields/room/field13",
       "west" : "/d/koenig/fields/room/field3"
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}
