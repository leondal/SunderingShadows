#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^To the southwest you see one of the many %^ORANGE%^huts%^GREEN%^ that"+
   " are scattered across the clearing.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the southwest"+
   " you notice one of the %^ORANGE%^huts%^BLUE%^ that are scattered about the"+
   " clearing.\n"
   );
   set_exits(([
   "north" : ROOMS+"v45",
   "south" : ROOMS+"c33",
   "west" : ROOMS+"c37",
   "east" : ROOMS+"v43",
   ]));
}
