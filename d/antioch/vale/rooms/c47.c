#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c46",
   "north" : ROOMS+"c43",
   "southwest" : ROOMS+"c48",
   "northeast" : ROOMS+"c42",
   ]));
}
