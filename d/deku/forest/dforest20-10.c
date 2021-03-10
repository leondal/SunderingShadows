#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NTFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"19-10",
       "north" : F_ROOMS"20-11",
       "northeast" : F_ROOMS"19-11",
       "west" : F_ROOMS"21-10",
       "northwest" : F_ROOMS"21-11",
    ] ));
}
