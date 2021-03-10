#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "east" : PATH+"road20",
   "west" : PATH+"road22",
   ]));
}
