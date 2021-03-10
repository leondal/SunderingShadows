#include <std.h>
#include "meadow.h"
inherit SHRUB;

void create()
{
   ::create();
   set_exits(([
   "north" : ROOMS+"shrub2",
   "south" : ROAD+"road44",
   "east" : ROOMS+"shrub4",
   ]));
}
