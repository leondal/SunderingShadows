#include <std.h>
#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"c24",
   "south" : ROOMS+"c21",
   "southwest" : ROOMS+"c22",
   "northeast" : ROOMS+"c28",
   ]));
}
