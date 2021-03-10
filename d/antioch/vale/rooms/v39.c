#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^There is a small path leading into"+
   " the forest to the southeast, it looks like an animal trail of some sort.\n"
   );
   set("night long",query("night long")+"%^BLUE%^There is a little"+
   " path that leads off into the forest to the southeast, it's very hard to make"+
   " out.\n"
   );
   set_exits(([
   "west" : ROOMS+"c32",
   "southeast" : FPATH+"f21",
   "south" : ROOMS+"v37",
   "north" : ROOMS+"v41",
   "east" : ROOMS+"v40",
   ]));
}

