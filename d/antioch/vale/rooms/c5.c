#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^Directly to the east is one of "+
      "the many %^ORANGE%^huts%^GREEN%^ that are scattered across the clearing.\n"
   );
   set("night long",query("night long")+"%^BLUE%^Directly to the east is one of "+
      "the many %^ORANGE%^huts%^BLUE%^ that are scattered across the clearing.\n"
   );
   set_exits(([
   "south" : ROOMS+"c1",
   "west" : ROOMS+"c6",
   "north" : ROOMS+"c14"
   ]));
}
