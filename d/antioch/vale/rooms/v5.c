#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v6",
   "east" : ROOMS+"v4",
   "north" : ROOMS+"v14",
   "south" : ROOMS+"v1",
   ]));
}
