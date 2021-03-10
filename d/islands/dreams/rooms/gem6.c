#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"gem7",
   "north" : ROOMS+"gem12",
   "east" : ROOMS+"gem5",
   "south" : ROOMS+"gem4",
   ]));
}
