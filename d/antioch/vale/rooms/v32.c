#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v31",
   "southeast" : ROOMS+"v18",
   "northwest" : ROOMS+"v33",
   "south" : ROOMS+"v19",
   ]));
}
