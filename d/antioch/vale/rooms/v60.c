#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v61",
   "east" : ROOMS+"v59",
   "northeast" : ROOMS+"v58",
   "south" : ROOMS+"v64",
   ]));
}
