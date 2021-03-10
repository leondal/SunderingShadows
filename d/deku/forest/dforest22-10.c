#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NTFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"21-10",
       "north" : F_ROOMS"22-11",
       "southwest" : F_ROOMS"23-9",
       "northeast" : F_ROOMS"21-11",
       "west" : F_ROOMS"23-10",
       "northwest" : F_ROOMS"23-11",
    ] ));
}
