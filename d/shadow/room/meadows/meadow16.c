#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"meadow15",
   "east" : ROAD+"road36",
   "north" : ROOMS+"meadow13",
   ]));
}
