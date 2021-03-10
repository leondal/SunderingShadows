#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "east" : PATH+"road21",
   "southwest" : PATH+"road23",
   ]));
}
