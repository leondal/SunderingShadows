#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
  
    set_exits(([
       "west" : F_ROOMS"4-3",
       "east" : F_ROOMS"2-3",
       "north" : F_ROOMS"3-4",
       "south" : F_ROOMS"3-2",
       "southeast" : F_ROOMS"2-2",
       "southwest" : F_ROOMS"4-2",
       "northeast" : F_ROOMS"2-4",
       "northwest" : F_ROOMS"4-4",
    ] ));
}
