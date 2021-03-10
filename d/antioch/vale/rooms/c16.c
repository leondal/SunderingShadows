#include <std.h>
#include "../vale.h"
inherit CLEARING;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^To the northeast you see one of the many %^ORANGE%^huts%^GREEN%^ that"+
   " are scattered across the clearing, and there is another one to"+
	" the southwest.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the northeast"+
   " you notice one of the %^ORANGE%^huts%^BLUE%^ that are scattered about the"+
   " clearing, and there is another one to the southwest.\n"
   );
   set_exits(([
   "north" : ROOMS+"c20",
   "south" : ROOMS+"c4",
   "west" : ROOMS+"c15",
   "east" : ROOMS+"c17",
   ]));
}
