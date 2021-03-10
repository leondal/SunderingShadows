#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"v34",
   "northwest" : ROOMS+"v36",
   "southwest" : ROOMS+"v33",
   ]));
}
