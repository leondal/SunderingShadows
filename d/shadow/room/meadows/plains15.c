#include <std.h>
#include "meadow.h"
inherit PLAINS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROAD+"road48",
   "east" : ROOMS+"plains14",
   "south" : ROOMS+"plains16",
   "north" : ROOMS+"plains10",
   ]));
}
