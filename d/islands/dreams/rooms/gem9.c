#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "northeast" : ROOMS+"gem10",
   "east" : ROOMS+"gem8",
   "southeast" : ROOMS+"gem2",
   ]));
}
