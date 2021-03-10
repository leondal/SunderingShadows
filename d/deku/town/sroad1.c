#include <std.h>
inherit "/d/deku/inherits/sroadi";

void create() {
    ::create();
    set_long(TO->query_long()+" %^GREEN%^The road meets the west gates just north of here or turns southeast and meets the south gates.");
    set_exits(([
       "north" : "/d/deku/town/road3",
       "southeast" : "/d/deku/town/sroad2",
       "east" : "/d/deku/town/portal",
    ] ));
}
