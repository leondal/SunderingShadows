#include <std.h>
#include "../vale.h"
inherit WALL;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_short("%^GREEN%^Along the Wall of Brambles%^RESET%^");
   set_long(::query_long()+"%^GREEN%^There is one of the many %^ORANGE%^huts%^GREEN%^ that're scattered about the clearing"+
   " to the southeast.\n"
   );
   set("night long",query("night long")+"%^BLUE%^You see the back of a %^ORANGE%^hut%^BLUE%^ to the southeast.\n"
   );
   set_smell("default","You can smell the shrubbery here.");
   set_listen("default","You hear bird song in the distance.");
   set_exits(([
   "west" : ROOMS+"c54",
   "south" : ROOMS+"c11",
   "northwest" : ROOMS+"c53",
   ]));
}
