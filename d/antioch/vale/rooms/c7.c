#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"\nTo the northwest you see one of "+
      "the many huts that are scattered across the clearing.\n"
   );
   set_exits(([
   "north" : ROOMS+"c12",
   "south" : ROOMS+"v24",
   "west" : ROOMS+"c8",
   "east" : ROOMS+"c6"
   ]));
}
