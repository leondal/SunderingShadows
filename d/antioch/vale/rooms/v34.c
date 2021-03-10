#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c19",
   "east" : ROOMS+"v35",
   "north" : ROOMS+"v36",
   "south" : ROOMS+"v33",
   ]));
}
