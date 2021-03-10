#include <std.h>
#include "meadow.h"
inherit SHRUB;

void create()
{
   ::create();
   set_exits(([
   "north" : ROOMS+"shrub3",
   "south" : ROAD+"road45",
   "east" : ROOMS+"shrub5",
   "west" : ROOMS+"shrub1",
   ]));
}
