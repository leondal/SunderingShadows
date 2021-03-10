#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(TO->query_long()+"There is a break in the grass to the east here "
       "and to the north it appears to split again.");
    set_exits(([
       "north" : "/d/deku/plains/plains23",
       "east" : "/d/deku/plains/plains51",
       "south" : "/d/deku/plains/plains21"
    ] ));
}
