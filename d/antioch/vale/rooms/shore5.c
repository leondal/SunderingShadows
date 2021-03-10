#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"shore4",
   "north" : ROOMS+"shore6",
   "northwest" : ROOMS+"shore7",
   "southeast" : ROOMS+"shore3",
   ]));
}
