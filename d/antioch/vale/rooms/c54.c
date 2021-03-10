#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^There is a small path leading into"+
   " the forest to the north, it looks like a wide animal trail.\n"
   );
   set("night long",query("night long")+"%^BLUE%^There is a"+
   " path that leads off into the forest to the north, it's very hard to make"+
   " out.\n"
   );
   set_exits(([
   "west" : ROOMS+"v55",
   "east" : ROOMS+"v53",
   "north" : FPATH+"trail1",
   "south" : ROOMS+"c43",
   ]));
}
