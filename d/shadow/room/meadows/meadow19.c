#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"meadow20",
   "east" : ROAD+"road39",
   "north" : ROAD+"road38",
   ]));
}
