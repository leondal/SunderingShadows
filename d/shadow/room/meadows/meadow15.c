#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"meadow16",
   "north" : ROOMS+"meadow14",
   "west" : "/d/darkwood/camps/rooms/orcamp/cpath11",
   ]));
}
