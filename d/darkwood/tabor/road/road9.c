#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "southwest" : PATH+"road10",
   "east" : PATH+"road8",
   ]));
}
