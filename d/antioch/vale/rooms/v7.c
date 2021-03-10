#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"rbank7",
   "east" : ROOMS+"v6",
   "north" : ROOMS+"v12",
   "south" : ROOMS+"rbank5",
   ]));
}
