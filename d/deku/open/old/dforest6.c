#include <std.h>
inherit "/d/deku/open/dforest2i";

void create() {
    ::create();
    set_exits(([
       "west" : "/d/deku/open/dforest5",
       "east" : "/d/deku/open/dforest7"
    ] ));
}
