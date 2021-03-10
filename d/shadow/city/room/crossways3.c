//Octothorpe (1/5/12)
//Shadow, Crossways Road 3

#include <std.h>
#include "../defs.h"
inherit INH+"crossways";

void create(){
   ::create();
   set_long(::query_long()+"To the northeast an open door leads "+
      "into to the %^BLUE%^psionic portal%^RESET%^.\n");
   set_exits(([
      "northwest" : ROOMS"crossways2",
      "northeast" : ROOMS"psion2",
      "southeast" : ROOMS"crossways4",
   ]));  
}