#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"meadow10",
   "east" : ROAD+"road33",
   "north" : ROOMS+"meadow8",
   "south" : ROOMS+"meadow12",
   ]));
}
