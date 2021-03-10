#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"gem9",
   "north" : ROOMS+"gem10",
   "east" : ROOMS+"gem7",
   "south" : ROOMS+"gem2",
   ]));
}
