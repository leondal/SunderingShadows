#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    ::create();
    set_exits(([
       "north" : "/d/koenig/fields/room/field11",
       "east" : "/d/koenig/fields/room/field17",
       "south" : "/d/koenig/fields/room/field13",
       "west" : "/d/koenig/fields/room/field7",
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}