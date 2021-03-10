#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"c27",
   "south" : ROOMS+"c24",
   "southwest" : ROOMS+"c23",
   "northwest" : ROOMS+"c29",
   "north" : ROOMS+"c30",
   ]));
}
