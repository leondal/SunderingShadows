#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_exits(([
       "north" : "/d/deku/plains/plains53",
       "south" : "/d/deku/plains/plains55"
    ] ));
}
