#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(TO->query_long()+"Toward the west you can see a large forest.");
    set_exits(([
       "east" : "/d/deku/plains/plains57",
       "west" : "/d/deku/plains/plains59"
    ] ));
}
