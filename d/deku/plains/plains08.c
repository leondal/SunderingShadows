#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_exits(([
       "east" : "/d/deku/plains/plains07",
       "west" : "/d/deku/plains/plains09"
    ] ));
}
