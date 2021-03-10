#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "north" : PATH+"road11",
   "south" : PATH+"road13",
   ]));
}
