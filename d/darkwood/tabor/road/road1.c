#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "north" : "/d/darkwood/tabor/room/math1",
   "south" : PATH+"road2",
   ]));
}
