#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c31",
   "east" : ROOMS+"v39",
   "south" : ROOMS+"v38",
   "north" : ROOMS+"v42",
   ]));
}
