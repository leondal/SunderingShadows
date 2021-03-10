#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^One of the %^ORANGE%^huts%^GREEN%^"+
   " stands northwest of here, and you see the door"+
   " leading into it to the east.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the east you see a doorway leading into one of"+
   " the %^ORANGE%^huts%^BLUE%^.\n"
   );
   set_exits(([
   "west" : ROOMS+"c43",
   "east" : ROOMS+"c41",
   "north" : ROOMS+"v53",
   "southwest" : ROOMS+"c47",
   ]));
}
