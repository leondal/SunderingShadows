#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(TO->query_long()+"The grass begins to thin a little in this area.");
    set_exits(([
       "north" : "/d/deku/plains/plains54",
       "west" : "/d/deku/plains/plains56"
    ] ));
}
