#include <std.h>

inherit "/d/deku/open/dforest2i";

void create() {
    ::create();
    set_short("Road to Verbobone");
    set_long( TO->query_long()+"  To the west, the forest seems to break "
      "into a large clearing." );
    set_smell("default","You smell the faint smell of wood burning towards the west.");
    set_exits(([
       "west" : "/d/deku/town/road14",
       "east" : "/d/deku/open/dforest2i"
    ] ));
}

