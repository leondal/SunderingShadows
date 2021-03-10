#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c40",
   "east" : ROOMS+"c38",
   "south" : ROOMS+"c35",
   "north" : ROOMS+"v48",
   ]));
}
