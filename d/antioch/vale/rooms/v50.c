#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^There is a small path leading into"+
   " the forest to the northeast, it looks like an %^ORANGE%^animal trail%^GREEN%^ of some sort."+
   " Directly to the south is one of the %^ORANGE%^huts%^GREEN%^ that are scattered about the vale,"+
   " there appears to be an entrance into it just south of here."
   );
   set("night long",query("night long")+"%^GREEN%^There is a little"+
   " path that leads off into the forest to the northeast, it's very hard to make"+
   " out. Directly south of you is one of the %^ORANGE%^huts%^GREEN%^ that are scattered about the vale,"+
   " there appears to be an entrance into it just south of here."
   );
   set_exits(([
   "west" : ROOMS+"v51",
   "southeast" : ROOMS+"v48",
   "northeast" : FPATH+"f40",
   "south" : ROOMS+"v49",
   ]));
}
