#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^Directly to the south is one of the many %^ORANGE%^huts%^GREEN%^ that"+
   " are scattered across the clearing.\n");
   set("night long",query("night long")+"%^BLUE%^To the south"+
   " is one of the %^ORANGE%^huts%^BLUE%^ that you noticed are scattered about the"+
   " clearing.\n");
   set_exits(([
   "west" : ROOMS+"v77",
   "east" : ROOMS+"c53",
   "north" : ROOMS+"c51",
   ]));
}
