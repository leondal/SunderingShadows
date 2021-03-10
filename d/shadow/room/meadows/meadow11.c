#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"meadow12",
   "north" : ROOMS+"meadow10",
   "south" : ROOMS+"meadow14",
   ]));
}
