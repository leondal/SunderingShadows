#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(TO->query_long()+"There is a break to the south here and the path "
       "seems to widen a little there.");
    set_exits(([
       "east" : "/d/deku/plains/plains16",
       "south" : "/d/deku/plains/plains53",
       "west" : "/d/deku/plains/plains18"
    ] ));
}
