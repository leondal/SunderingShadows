#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v25",
   "west" : ROOMS+"rbank15",
   "north" : ROOMS+"v26",
   "southeast" : ROOMS+"rbank12",
   "south" : ROOMS+"rbank13",
   ]));
}
