#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"rbank14",
   "east" : ROOMS+"v24",
   "north" : ROOMS+"c8",
   "south" : ROOMS+"rbank12",
   ]));
}
