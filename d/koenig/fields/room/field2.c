#include <std.h>

inherit "/d/koenig/fields/fields_inherit.c";

void create() {
    ::create();
    set_long( ::query_long()+"To the south you can see the entrance to "
    "the field where it meets the dusty road.");
    set_exits(([
       "south" : "/d/koenig/fields/room/field3",
       "north" : "/d/koenig/fields/room/field1",
       "east" : "/d/koenig/fields/room/field7"
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}