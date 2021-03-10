#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c50",
   "east" : ROOMS+"c48",
   "south" : ROOMS+"c51",
   "north" : ROOMS+"c45",
   ]));
}
