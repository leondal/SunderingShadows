#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v21",
   "east" : ROOMS+"v19",
   "north" : ROOMS+"v31",
   "south" : ROOMS+"v15",
   ]));
}
