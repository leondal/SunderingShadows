#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v9",
   "east" : ROOMS+"v11",
   "north" : ROOMS+"c1",
   "south" : ROOMS+"rbank8",
   ]));
}
