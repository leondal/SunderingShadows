#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"gem10",
   "north" : ROOMS+"gem13",
   "east" : ROOMS+"gem12",
   "south" : ROOMS+"gem7",
   ]));
}
