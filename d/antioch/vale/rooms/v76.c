#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v75",
   "east" : ROOMS+"v77",
   "north" : ROOMS+"v66",
   "south" : ROOMS+"v79",
   ]));
}
