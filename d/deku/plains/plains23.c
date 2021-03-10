#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_exits(([
       "north" : "/d/deku/plains/plains24",
       "west" : "/d/deku/plains/plains27",
       "south" : "/d/deku/plains/plains22"
    ] ));
}
