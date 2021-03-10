#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^To the north you see an entrance to one of the many"+
   " %^ORANGE%^huts%^GREEN%^ that are scattered across the clearing.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the north"+
   " you notice an entrance to one of the %^ORANGE%^huts%^BLUE%^ that are scattered"+
   " about the clearing.\n"
   );
   set_exits(([
   "north" : ROOMS+"c44",
   "south" : ROOMS+"c48",
   "west" : ROOMS+"c45",
   "east" : ROOMS+"c47",
   ]));
}
