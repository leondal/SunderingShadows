#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"rbank12",
   "east" : ROOMS+"v9",
   "north" : ROOMS+"v24",
   "south" : ROOMS+"rbank10",
   ]));
}
