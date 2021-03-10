#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v63",
   "east" : ROOMS+"c50",
   "north" : ROOMS+"v60",
   "south" : ROOMS+"v66",
   ]));
}
