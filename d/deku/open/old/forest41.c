#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_listen("default","Sounds of rushing water seem to be coming from the east.");
    set_exits(([
       "west" : "/d/deku/open/forest4",
       "east" : "/d/deku/open/lake"
    ] ));
    set_items(([
    ] ));
}
