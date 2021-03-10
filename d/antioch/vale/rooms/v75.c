#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"shore8",
   "east" : ROOMS+"v76",
   "north" : ROOMS+"v67",
   "south" : ROOMS+"shore6",
   ]));
}
