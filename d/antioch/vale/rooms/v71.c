#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v70",
   "southwest" : ROOMS+"v73",
   "south" : ROOMS+"v72",
   ]));
}
