#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"To the northwest you see one "+
      "of the many %^ORANGE%^huts%^GREEN%^ that are scattered across the clearing.\n"
   );
   set("night long",query("night long")+"%^BLUE%^Directly to the northwest is one of "+
      "the many %^ORANGE%^huts%^BLUE%^ that are scattered across the clearing.\n"
   );
   set_exits(([
   "north" : ROOMS+"c4",
   "south" : ROOMS+"v12",
   "west" : ROOMS+"c2",
   "east" : ROOMS+"v22"
   ]));
}
