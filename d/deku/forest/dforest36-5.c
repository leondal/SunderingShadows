#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
  
    set_exits(([
       "west" : F_ROOMS"37-5",
       "east" : F_ROOMS"35-5",
       "north" : F_ROOMS"36-6",
       "south" : F_ROOMS"36-4",
       "southeast" : F_ROOMS"35-4",
       "southwest" : F_ROOMS"37-4",
       "northeast" : F_ROOMS"35-6",
       "northwest" : F_ROOMS"37-6",
    ] ));
}
