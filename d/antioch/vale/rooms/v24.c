#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v25",
   "east" : ROOMS+"v23",
   "north" : ROOMS+"c7",
   "south" : ROOMS+"v8",
   ]));
}
