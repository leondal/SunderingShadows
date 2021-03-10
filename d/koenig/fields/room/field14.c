#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/koenig/fields/room/field15",
       "north" : "/d/koenig/fields/room/field13",
       "east" : "/d/koenig/fields/room/field19",
       "west" : "/d/koenig/fields/room/field9"
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}