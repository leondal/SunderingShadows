#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^To the southeast you see one of the many %^ORANGE%^huts%^GREEN%^ that"+
   " are scattered across the clearing.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the southeast"+
   " you notice one of the %^ORANGE%^huts%^BLUE%^ that are scattered about the"+
   " clearing."
   );
   set_exits(([
   "north" : ROOMS+"v47",
   "south" : ROOMS+"c34",
   "west" : ROOMS+"c39",
   "east" : ROOMS+"c37",
   ]));
}
