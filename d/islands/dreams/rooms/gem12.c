#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "northwest" : ROOMS+"gem13",
   "south" : ROOMS+"gem6",
   "west" : ROOMS+"gem11",
   "southeast" : ROOMS+"gem5",
   ]));
}
