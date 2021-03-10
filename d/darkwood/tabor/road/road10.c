#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "south" : PATH+"road11",
   "northeast" : PATH+"road9",
   ]));
}
