#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c49",
   "north" : ROOMS+"c46",
   "southwest" : ROOMS+"c51",
   "northeast" : ROOMS+"c47",
   ]));
}
