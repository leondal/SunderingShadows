#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v24",
   "east" : ROOMS+"c1",
   "north" : ROOMS+"c6",
   "south" : ROOMS+"v9",
   ]));
}
