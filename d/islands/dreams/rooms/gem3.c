#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"gem2",
   "north" : ROOMS+"gem7",
   "east" : ROOMS+"gem4",
   "south" : ROOMS+"gem1",
   ]));
}
