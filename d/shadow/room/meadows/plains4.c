#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "east" : ROAD+"road48",
   "west" : ROOMS+"plains5",
   "south" : ROOMS+"plains9",
   "north" : ROOMS+"plains3",
   ]));
}
