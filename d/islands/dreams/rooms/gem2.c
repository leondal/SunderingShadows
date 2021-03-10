#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "northwest" : ROOMS+"gem9",
   "north" : ROOMS+"gem8",
   "east" : ROOMS+"gem3",
   "southeast" : ROOMS+"gem1",
   ]));
}
