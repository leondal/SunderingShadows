#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^One of the %^ORANGE%^huts%^GREEN%^ stands northwest of here, and you see the door"+
   " leading into it to the west.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the west you see a doorway leading into one of"+
   " the %^ORANGE%^huts%^BLUE%^.\n"
   );
   set_exits(([
   "west" : ROOMS+"c41",
   "east" : ROOMS+"c39",
   "north" : ROOMS+"v49",
   "southeast" : ROOMS+"c35",
   ]));
}
