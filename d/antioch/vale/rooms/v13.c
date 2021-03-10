#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v12",
   "east" : ROOMS+"v14",
   "north" : ROOMS+"v22",
   "south" : ROOMS+"v6",
   ]));
}
