#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank14",
   "west" : ROOMS+"rbank16",
   "north" : ROOMS+"v27",
   "southeast" : ROOMS+"rbank13",
   ]));
}
