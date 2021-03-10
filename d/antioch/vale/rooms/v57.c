#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^To the southeast is one of the"+
   " %^ORANGE%^huts%^GREEN%^ that are scattered about the vale.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the southeast of"+
   " you is one of the %^ORANGE%^huts%^BLUE%^ that are scattered about the vale."
   );
   set_exits(([
   "south" : ROOMS+"v58",
   "east" : ROOMS+"v56",
   ]));
}
