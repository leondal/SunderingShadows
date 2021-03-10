#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v79",
   "west" : ROOMS+"shore7",
   "north" : ROOMS+"v75",
   "south" : ROOMS+"shore5",
   "northwest" : ROOMS+"shore8",
   "southeast" : ROOMS+"shore4",
   ]));
}
