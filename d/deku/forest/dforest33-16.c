#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"32-16",
       "west" : F_ROOMS"34-16",
       "south" : F_ROOMS"33-15",
       "southwest" : F_ROOMS"34-15",
       "southeast" : F_ROOMS"32-15",       
    ] ));
}
