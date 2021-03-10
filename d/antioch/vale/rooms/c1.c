#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"To the northeast you see one of "+
      "the many %^ORANGE%^huts%^GREEN%^ that are scattered across the clearing.\n"
   );
   set("night long",query("night long")+"%^BLUE%^Directly to the northeast is one of "+
      "the many %^ORANGE%^huts%^BLUE%^ that are scattered across the clearing.\n"
   );
   set_exits(([
   "north" : ROOMS+"c5",
   "south" : ROOMS+"v10",
   "west" : ROOMS+"v23",
   "east" : ROOMS+"c2"
   ]));
}
