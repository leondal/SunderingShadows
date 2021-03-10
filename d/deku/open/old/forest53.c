#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_exits(([
       "north" : "/d/deku/open/forest52",
       "west" : "/d/deku/open/forest54"
    ] ));
    set_items(([
    ] ));
}
