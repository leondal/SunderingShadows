//Octothorpe (1/5/12)
//Shadow, Crossways Road 4

#include <std.h>
#include "../defs.h"
inherit INH+"crossways";

void create(){
   ::create();
   set_long(::query_long()+"To the northeast an open door leads "+
      "into to the %^BLUE%^alchemist %^RESET%^shop.\n");
   set_exits(([
      "northwest" : ROOMS"crossways3",
      "southeast" : ROOMS"shadwayc",
      "northeast" : ROOMS"alchemist"
   ]));
}