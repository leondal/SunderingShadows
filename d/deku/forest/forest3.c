#include <std.h>

inherit "/d/deku/forest/forest2i";

void create() {
    ::create();
    set_exits(([
       "north" : "/d/deku/forest/dforest35-1",
       "south" : "/d/deku/forest/forest2i"
    ] ));
    set_items(([
    ] ));
}

