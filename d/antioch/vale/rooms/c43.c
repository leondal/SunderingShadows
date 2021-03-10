#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"c42",
   "west" : ROOMS+"c44",
   "south" : ROOMS+"c47",
   "north" : ROOMS+"v54",
   ]));
}
