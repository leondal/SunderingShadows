#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"34-13",
       "east" : F_ROOMS"32-13",
       "south" : F_ROOMS"33-12",
       "north" : F_ROOMS"33-14",
       "northwest" : F_ROOMS"34-14",
       "southwest" : F_ROOMS"34-12",
       "southeast" : F_ROOMS"32-12",
       "northeast" : F_ROOMS"32-14",

       
    ] ));
}
