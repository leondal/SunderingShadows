#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_short("%^GREEN%^Along the Wall of Brambles%^RESET%^");
   set_long(::query_long()+"%^GREEN%^You see one of the %^ORANGE%^"+
   "huts%^GREEN%^ that are scattered about the clearing to"+
   " the southwest.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the southwest "+
   "you see one of the %^ORANGE%^huts%^BLUE%^ that are"+
   " scattered throughout the clearing.\n"
   );
   set_exits(([
   "west" : ROOMS+"c52",
   "south" : ROOMS+"c54",
   "northwest" : ROOMS+"c51",
   "southeast" : ROOMS+"c55",
   ]));
}
