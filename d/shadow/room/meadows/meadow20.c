#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"meadow19",
   "north" : ROAD+"road37",
   ]));
}
