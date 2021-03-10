#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"36-11",
       "east" : F_ROOMS"34-11",
       "south" : F_ROOMS"35-10",
       "southeast" : F_ROOMS"34-10",
       "southwest" : F_ROOMS"36-10",
       "north" : F_ROOMS"35-12",
       //"northeast" : F_ROOMS"34-12",
       "northwest" : F_ROOMS"36-12",
    ] ));
}
