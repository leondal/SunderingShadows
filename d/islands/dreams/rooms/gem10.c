#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "northeast" : ROOMS+"gem13",
   "south" : ROOMS+"gem8",
   "east" : ROOMS+"gem11",
   "southwest" : ROOMS+"gem9",
   ]));
}
