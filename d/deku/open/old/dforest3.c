#include <std.h>
inherit "/d/deku/open/dforest2i";

void create() {
    ::create();
    set_exits(([
       "west" : "/d/deku/open/dforest2i",
       "south":"/d/deku/open/dforest3-1",
       "east" : "/d/deku/open/dforest4"
    ] ));
}
