#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "northeast" : PATH+"road18",
   "west" : PATH+"road20",
   ]));
}
