#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_exits(([
       "north" : "/d/deku/open/forest9",
       "south" : "/d/deku/open/forest7"
    ] ));
    set_items(([
    ] ));
}
