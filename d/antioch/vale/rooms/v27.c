#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v28",
   "east" : ROOMS+"v26",
   "north" : ROOMS+"c10",
   "south" : ROOMS+"rbank15",
   ]));
}
