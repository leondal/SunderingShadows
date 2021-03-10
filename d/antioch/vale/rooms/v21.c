#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v22",
   "east" : ROOMS+"v20",
   "north" : ROOMS+"v30",
   "south" : ROOMS+"v14",
   ]));
}
