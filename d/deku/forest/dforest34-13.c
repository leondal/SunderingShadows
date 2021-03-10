#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"35-13",
       "east" : F_ROOMS"33-13",
       "south" : F_ROOMS"34-12",
       "north" : F_ROOMS"34-14",
       "northwest" : F_ROOMS"35-14",
       "southeast" : F_ROOMS"33-12",
       "northeast" : F_ROOMS"33-14",

       
    ] ));
}
