#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v7",
   "east" : ROOMS+"v5",
   "north" : ROOMS+"v13",
   "south" : ROOMS+"rbank4",
   ]));
}
