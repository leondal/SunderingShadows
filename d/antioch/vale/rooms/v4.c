#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v5",
   "east" : ROOMS+"v3",
   "north" : ROOMS+"v15",
   "south" : ROOMS+"v2",
   ]));
}
