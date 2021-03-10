#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    ::create();
    set_long( ::query_long()+"To the north you can see the entrance to the "
    "field where it meets the dusty road.");
    set_exits(([
       "north" : "/d/koenig/fields/room/field3",
       "south" : "/d/koenig/fields/room/field5",
       "east" : "/d/koenig/fields/room/field9"
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}