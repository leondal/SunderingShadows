#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^To the southeast is"+
   " one of the %^ORANGE%^huts%^GREEN%^ that are scattered about the vale.\n"
   );
  set("night long",query("night long")+"%^GREEN%^To "+
   "the southeast is one of the %^ORANGE%^huts%^GREEN%^ that are scattered about the vale.\n"
   );
   set_exits(([
   "west" : ROOMS+"v76",
   "east" : ROOMS+"c52",
   "north" : ROOMS+"v65",
   "south" : ROOMS+"v78",
   ]));
}
