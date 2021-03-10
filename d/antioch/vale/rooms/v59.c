#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^To the northeast is one of the"+
   " %^ORANGE%^huts%^GREEN%^ that are scattered about the vale.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the northeast of"+
   " you is one of the %^ORANGE%^huts%^BLUE%^ that are scattered about the vale.\n"
   );
   set_exits(([
   "south" : ROOMS+"c50",
   "east" : ROOMS+"c45",
   "north" : ROOMS+"v58",
   "west" : ROOMS+"v60",
   ]));
}
