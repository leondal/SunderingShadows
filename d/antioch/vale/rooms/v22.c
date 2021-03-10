#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c3",
   "east" : ROOMS+"v21",
   "north" : ROOMS+"v29",
   "south" : ROOMS+"v13",
   ]));
}
