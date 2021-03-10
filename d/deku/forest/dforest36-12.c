#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"37-12",
       "east" : F_ROOMS"35-12",
       "south" : F_ROOMS"36-11",
       "north" : F_ROOMS"36-13",
       "northwest" : F_ROOMS"37-13",
       "southeast" : F_ROOMS"35-11",
       "southwest" : F_ROOMS"37-11",
       //"northeast" : F_ROOMS"35-13",
       
    ] ));
}
