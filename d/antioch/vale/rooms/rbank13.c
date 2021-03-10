#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank12",
   "north" : ROOMS+"rbank14",
   "northwest" : ROOMS+"rbank15",
   "southeast" : ROOMS+"rbank11",
   ]));
}
