#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v28",
   "west" : ROOMS+"shore3",
   "south" : ROOMS+"shore1",
   "north" : ROOMS+"v80",
   "northwest" : ROOMS+"shore4",
   "southeast" : ROOMS+"rbank16",
   ]));
}
