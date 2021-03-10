#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "northeast" : ROOMS+"gem5",
   "north" : ROOMS+"gem6",
   "west" : ROOMS+"gem3",
   "southwest" : ROOMS+"gem1",
   ]));
}
