#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_exits(([
       "east" : "/d/deku/open/forest53",
       "west" : "/d/deku/open/cave_ent2"
    ] ));
    set_items(([
    ] ));
}
