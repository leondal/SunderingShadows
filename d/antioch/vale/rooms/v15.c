#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v14",
   "east" : ROOMS+"v16",
   "north" : ROOMS+"v20",
   "south" : ROOMS+"v4",
   ]));
}
