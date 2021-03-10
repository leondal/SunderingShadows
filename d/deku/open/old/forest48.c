#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/deku/open/forest47",
       "north" : "/d/deku/open/tower2"
    ] ));
    set_items(([
    ] ));
}
