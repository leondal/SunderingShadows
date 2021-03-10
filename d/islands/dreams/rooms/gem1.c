#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
      set_exits(([
   "north" : ROOMS+"gem3",
   "northwest" : ROOMS+"gem2",
   "northeast" : ROOMS+"gem4",
   ]));
}
