#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^There is a small path leading into"+
   " the forest to the north, it looks like an animal trail of some sort.\n"
   );
   set("night long",query("night long")+"%^BLUE%^There is a little"+
   " path that leads off into the forest to the north, it's very hard to make"+
   " out.\n"
   );
   set_exits(([
   "east" : ROOMS+"v72",
   "north" : FPATH+"f61",
   "south" : ROOMS+"v74",
   "northeast" : ROOMS+"v71",
   ]));
}
