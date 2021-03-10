#include <std.h>
#include "../defs.h"
inherit GEM;

void create()
{
   ::create();
   set_exits(([
   "northwest" : ROOMS+"gem12",
   "west" : ROOMS+"gem6",
   "southwest" : ROOMS+"gem4",
   ]));
}
