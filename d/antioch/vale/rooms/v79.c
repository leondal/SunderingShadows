#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"shore6",
   "east" : ROOMS+"v78",
   "north" : ROOMS+"v76",
   "south" : ROOMS+"shore4",
   ]));
}
