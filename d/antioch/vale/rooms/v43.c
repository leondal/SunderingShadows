#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c36",
   "southeast" : ROOMS+"v41",
   "north" : ROOMS+"v44",
   "south" : ROOMS+"v42",
   ]));
}
