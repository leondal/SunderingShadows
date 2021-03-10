#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
   set_exits(([
       "west" : F_ROOMS"28-5",
       "east" : F_ROOMS"26-5",
       "north" : F_ROOMS"27-6",
       "south" : F_ROOMS"27-4",
       "southeast" : F_ROOMS"26-4",
       "southwest" : F_ROOMS"28-4",
       "northeast" : F_ROOMS"26-6",
       "northwest" : F_ROOMS"28-6",
    ] ));
}
