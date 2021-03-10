#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"shore2",
   "east" : ROOMS+"v27",
   "north" : ROOMS+"c9",
   "south" : ROOMS+"rbank16",
   ]));
}
