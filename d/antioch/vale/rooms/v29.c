#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c4",
   "east" : ROOMS+"v30",
   "north" : ROOMS+"c17",
   "south" : ROOMS+"v22",
   ]));
}
