#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"shore9",
   "west" : ROOMS+"v72",
   "north" : ROOMS+"v70",
   "southwest" : ROOMS+"shore12",
   "south" : ROOMS+"shore11",
   ]));
}
