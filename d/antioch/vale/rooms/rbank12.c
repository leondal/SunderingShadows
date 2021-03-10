#include <std.h>
#include "../vale.h"
inherit RBANK;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v8",
   "west" : ROOMS+"rbank13",
   "north" : ROOMS+"v25",
   "northwest" : ROOMS+"rbank14",
   "southeast" : ROOMS+"rbank10",
   "south" : ROOMS+"rbank11",
   ]));
}
