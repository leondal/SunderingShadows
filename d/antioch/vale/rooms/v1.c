#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"rbank4",
   "east" : ROOMS+"v2",
   "north" : ROOMS+"v5",
   "south" : ROOMS+"rbank2",
   ]));
}
