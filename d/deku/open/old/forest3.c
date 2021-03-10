#include <std.h>

inherit "/d/deku/open/forest2i";

void create() {
    ::create();
    set_exits(([
       "north" : "/d/deku/open/forest4",
       "south" : "/d/deku/open/forest2i"
    ] ));
    set_items(([
    ] ));
}

