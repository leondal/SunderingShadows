#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(TO->query_long()+"The path breaks off to the east and west here.");
    set_exits(([
       "south" : "/d/deku/plains/plains13",
       "east" : "/d/deku/plains/plains15",
       "west" : "/d/deku/plains/plains16"
    ] ));
}
