#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^Directly to the east is one of the"+
   " %^ORANGE%^huts%^GREEN%^ that are scattered about the vale.\n"
   );
   set("night long",query("night long")+"%^BLUE%^Directly east of you"+
   " is one of the %^ORANGE%^huts%^BLUE%^ that are scattered about the vale.\n"
   );
   set_exits(([
   "southwest" : ROOMS+"v60",
   "north" : ROOMS+"v57",
   "south" : ROOMS+"v59",
   ]));
}
