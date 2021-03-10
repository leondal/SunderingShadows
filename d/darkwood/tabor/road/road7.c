#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "west" : PATH+"road8",
   "east" : PATH+"road6",
   ]));
}
