#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"\nDirectly to the north is one of "+
      "the many huts that are scattered across the clearing.\n"
   );
   set_exits(([
   "west" : ROOMS+"v26",
   "east" : ROOMS+"c7",
   "south" : ROOMS+"v25"
   ]));
}
