#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^There is a %^ORANGE%^small path%^GREEN%^ leading into"+
   " the forest to the north, it looks like a wide animal trail."
   );
   set("night long",query("night long")+"%^GREEN%^There is a"+
   " path that leads off into the forest to the north, it's very hard to make"+
   " out.%^RESET%^");
   set_exits(([
   "west" : ROOMS+"v55",
   "east" : ROOMS+"v53",
   "north" : FPATH+"trail1",
   "south" : ROOMS+"c43",
   ]));
}
