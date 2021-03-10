#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"\nDirectly to the east is one of "+
      "the many huts that are scattered across the clearing.\n"
   );
   set_exits(([
   "south" : ROOMS+"v26",
   "west" : ROOMS+"c10",
   "north" : ROOMS+"c55"
   ]));
}
