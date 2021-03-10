#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v11",
   "east" : ROOMS+"v13",
   "north" : ROOMS+"c3",
   "south" : ROOMS+"v7",
   ]));
}
