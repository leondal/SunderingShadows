#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"shore13",
   "north" : ROOMS+"v74",
   "south" : ROOMS+"shore15",
   "northeast" : ROOMS+"shore12",
   ]));
}
