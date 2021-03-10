#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^There is a %^ORANGE%^small path%^GREEN%^ leading into"+
   " the forest to the northeast, it looks like a wide animal trail."
   );
   set("night long",query("night long")+"%^GREEN%^There is a"+
   " path that leads off into the forest to the northeast, it's very hard to make"+
   " out.%^RESET%^");
   set_exits(([
   "west" : ROOMS+"v42",
   "northeast" : FPATH+"f26",
   "southeast" : ROOMS+"v40",
   "northwest" : ROOMS+"v43",
   "south" : ROOMS+"v39",
   ]));
}

