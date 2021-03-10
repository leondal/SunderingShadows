#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c22",
   "east" : ROOMS+"c20",
   "south" : ROOMS+"c15",
   "north" : ROOMS+"c23",
   ]));
}
