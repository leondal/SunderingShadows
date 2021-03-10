#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^You see an entrance to one of the "+
      "%^ORANGE%^huts%^GREEN%^ to the east.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the east you see an entrance"+
     " to one of the %^ORANGE%^huts%^BLUE%^.\n"
   );
   set_exits(([
   "north" : ROOMS+"c34",
   "east" : ROOMS+"c30",
   "northwest" : ROOMS+"c35",
   "southeast" : ROOMS+"c28",
   ]));
}
