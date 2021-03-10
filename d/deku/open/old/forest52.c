#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/deku/open/forest53",
       "east" : "/d/deku/open/forest51"
    ] ));
    set_items(([
    ] ));
}
