#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"29-6",
       "north" : F_ROOMS"30-7",
       "south" : F_ROOMS"30-5",
       "southeast" : F_ROOMS"29-5",
       "northeast" : F_ROOMS"29-7",
      ] ));
}
