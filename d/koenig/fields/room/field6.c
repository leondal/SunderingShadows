#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/koenig/fields/room/field7",
       "east" : "/d/koenig/fields/room/field11",
       "west" : "/d/koenig/fields/room/field1"
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}