#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v15",
   "east" : ROOMS+"v17",
   "north" : ROOMS+"v19",
   "south" : ROOMS+"v3",
   ]));
}
