#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"rbank15",
   "west" : ROOMS+"shore1",
   "north" : ROOMS+"rbank12",
   "northwest" : ROOMS+"shore2",
   ]));
}
