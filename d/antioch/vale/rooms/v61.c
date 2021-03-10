#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^There is a small path leading into"+
   " the forest to the west and another leading to the northeast, they look like"+
   " animal trails of some sort.\n"
   );
   set("night long",query("night long")+"%^BLUE%^There is a little"+
   " path that leads off into the forest to the west and another one to the northeast,"+
   " they're very hard to make out.\n"
   );
   set_exits(([
   "west" : FPATH+"f53",
   "east" : ROOMS+"v60",
   "northeast" : FPATH+"f50",
   "south" : ROOMS+"v63",
   "southwest" : ROOMS+"v62",
   ]));
}

