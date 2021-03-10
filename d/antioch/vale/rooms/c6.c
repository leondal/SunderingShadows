#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c7",
   "east" : ROOMS+"c5",
   "north" : ROOMS+"c13",
   "south" : ROOMS+"v23",
   ]));
}
