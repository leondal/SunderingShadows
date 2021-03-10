#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c28",
   "east" : ROOMS+"v38",
   "south" : ROOMS+"c25",
   "north" : ROOMS+"c31",
   ]));
}
