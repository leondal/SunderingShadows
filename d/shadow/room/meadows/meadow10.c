#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"meadow9",
   "north" : ROOMS+"meadow7",
   "south" : ROOMS+"meadow11",
   ]));
}
