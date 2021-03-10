#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"Directly to the north is one of "+
      "the many %^ORANGE%^huts%^GREEN%^ that are scattered across the clearing.\n"
   );
   set("night long",query("night long")+"%^BLUE%^Directly to the north is one of "+
      "the many %^ORANGE%^huts%^BLUE%^ that are scattered across the clearing.\n"
   );
   set_exits(([
   "west" : ROOMS+"c1",
   "east" : ROOMS+"c3",
   "south" : ROOMS+"v11"
   ]));
}
