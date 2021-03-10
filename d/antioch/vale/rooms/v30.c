#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v29",
   "east" : ROOMS+"v31",
   "north" : ROOMS+"c18",
   "south" : ROOMS+"v21",
   ]));
}
