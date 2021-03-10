#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^To the northwest you see one of the many"+
   " %^ORANGE%^huts%^GREEN%^ that"+
   " are scattered across the clearing.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the northwest"+
   " you notice one of the %^ORANGE%^huts%^BLUE%^ that are scattered about the"+
   " clearing.\n"
   );
   set_exits(([
   "north" : ROOMS+"c19",
   "south" : ROOMS+"v30",
   "west" : ROOMS+"c17",
   "east" : ROOMS+"v33",
   ]));
}
