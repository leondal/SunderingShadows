#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"gem8",
   "north" : ROOMS+"gem11",
   "east" : ROOMS+"gem6",
   "south" : ROOMS+"gem3",
   ]));
}
