#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v66",
   "east" : ROOMS+"c51",
   "north" : ROOMS+"c50",
   "south" : ROOMS+"v77",
   ]));
}
