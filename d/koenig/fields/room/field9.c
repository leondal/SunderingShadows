#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/koenig/fields/room/field10",
       "north" : "/d/koenig/fields/room/field8",
       "east" : "/d/koenig/fields/room/field14",
       "west" : "/d/koenig/fields/room/field4"
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}