#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"29-7",
       "north" : F_ROOMS"30-8",
       "south" : F_ROOMS"30-6",
       "southeast" : F_ROOMS"29-6",
       "northeast" : F_ROOMS"29-8",
      ] ));
}
