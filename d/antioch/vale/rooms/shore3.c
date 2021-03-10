#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"shore2",
   "north" : ROOMS+"shore4",
   "northwest" : ROOMS+"shore5",
   "southeast" : ROOMS+"shore1",
   ]));
}
