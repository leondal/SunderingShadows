#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v10",
   "east" : ROOMS+"v12",
   "north" : ROOMS+"c2",
   "south" : ROOMS+"rbank7",
   ]));
}
