#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v4",
   "southwest" : ROOMS+"v2",
   "north" : ROOMS+"v16",
   "northeast" : ROOMS+"v17",
   ]));
}
