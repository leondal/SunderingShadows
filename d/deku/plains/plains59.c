#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(TO->query_long()+"You are along the edge of a forest.  Toward the "
       "northwest there is an opening leading into the forest.");
    set_listen("default","It's fairly quiet along the edge of the forest.");
    set_exits(([
       "east" : "/d/deku/plains/plains58",
       "north" : "/d/deku/plains/plains60"
    ] ));
}
