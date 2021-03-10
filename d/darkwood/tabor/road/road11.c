#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "north" : PATH+"road10",
   "south" : PATH+"road12",
   ]));
}
