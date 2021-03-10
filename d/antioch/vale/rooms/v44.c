#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
    set_long(::query_long()+"There is a small path leading into"+
   " the forest to the east, it looks like an animal trail of some sort."
   );
    set("night long", ::query("night long")+"There is a little"+
   " path that leads off into the forest to the east, it's very hard to make"+
   " out."
   );
   set_exits(([
   "west" : ROOMS+"v45",
   "east" : FPATH+"f28",
   "south" : ROOMS+"v43",
   ]));
}
