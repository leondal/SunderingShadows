#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"shore6",
   "north" : ROOMS+"shore8",
   "northwest" : ROOMS+"shore9",
   "southeast" : ROOMS+"shore5",
   ]));
}
