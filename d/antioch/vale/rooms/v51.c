#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^There is a small path leading into"+
   " the forest to the north, it looks like an %^ORANGE%^animal trail%^GREEN%^ of some sort."+
   " Directly to the south is one of the %^ORANGE%^huts%^GREEN%^ that are scattered about the vale."
   );
   set("night long",query("night long")+"%^GREEN%^There is a little"+
   " path that leads off into the forest to the north, it's very hard to make"+
   " out. Directly south of you is one of the %^ORANGE%^huts%^GREEN%^ that are scattered about the vale."
   );
   set_exits(([
   "west" : ROOMS+"v52",
   "east" : ROOMS+"v50",
   "north" : FPATH+"f42",
   ]));
}
