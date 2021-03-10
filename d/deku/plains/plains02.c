#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_exits(([
       "east" : "/d/deku/plains/plains01",
       "west" : "/d/deku/plains/plains03i"
    ] ));
}
