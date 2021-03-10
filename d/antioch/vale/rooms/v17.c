#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v16",
   "southwest" : ROOMS+"v3",
   "north" : ROOMS+"v18",
   ]));
}
