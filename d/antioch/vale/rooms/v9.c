#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v8",
   "east" : ROOMS+"v10",
   "north" : ROOMS+"v23",
   "south" : ROOMS+"rbank9",
   ]));
}
