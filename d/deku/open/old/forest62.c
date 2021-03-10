#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_exits(([
       "west" : "/d/deku/open/forest63",
       "east" : "/d/deku/open/forest61"
    ] ));
    set_items(([
    ] ));
}
