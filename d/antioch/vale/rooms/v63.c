#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"v64",
   "north" : ROOMS+"v61",
   "west" : ROOMS+"v62",
   "south" : ROOMS+"v67",
   ]));
}
