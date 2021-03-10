#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"c21",
   "south" : ROOMS+"c14",
   "southwest" : ROOMS+"c13",
   "northeast" : ROOMS+"c23",
   ]));
}
