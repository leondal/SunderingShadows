#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"meadow14",
   "east" : ROAD+"road35",
   "north" : ROOMS+"meadow12",
   "south" : ROOMS+"meadow16",
   ]));
}
