#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"\nTo the west you see an "+
      "entrance to one of the many huts that are "+
      "scattered across the clearing.\n"
   );
   set_exits(([
   "north" : ROOMS+"c54",
   "south" : ROOMS+"v27",
   "west" : ROOMS+"c9",
   "east" : ROOMS+"c11"
   ]));
}
