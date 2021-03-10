#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"21-11",
       "south" : F_ROOMS"22-10",
       "southeast" : F_ROOMS"21-10",
       "west" : F_ROOMS"23-11",
       "southwest" : F_ROOMS"23-10",
    ] ));
}
