#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_exits(([
       "north" : "/d/deku/plains/plains22",
       "south" : "/d/deku/plains/plains18"
    ] ));
}
