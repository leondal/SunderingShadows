#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    ::create();
    set_exits(([
       "north" : "/d/koenig/fields/room/field9",
       "east" : "/d/koenig/fields/room/field15",
       "west" : "/d/koenig/fields/room/field5"
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}