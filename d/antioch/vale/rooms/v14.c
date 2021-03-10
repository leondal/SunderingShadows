#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v13",
   "east" : ROOMS+"v15",
   "north" : ROOMS+"v21",
   "south" : ROOMS+"v5",
   ]));
}
