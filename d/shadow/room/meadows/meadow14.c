#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create() {
   ::create();
   set_exits(([
   "east" : ROOMS+"meadow13",
   "north" : ROOMS+"meadow11",
   "south" : ROOMS+"meadow15",
   "southwest" : "/d/darkwood/camps/rooms/orcamp/cpath11",
   ]));
}
