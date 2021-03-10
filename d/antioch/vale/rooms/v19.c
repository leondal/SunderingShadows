#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v20",
   "east" : ROOMS+"v18",
   "north" : ROOMS+"v32",
   "south" : ROOMS+"v16",
   ]));
}
