//Octothorpe (1/5/12)
//Shadow, Crossways Road 2

#include <std.h>
#include "../defs.h"
inherit INH+"crossways";

void create(){
   ::create();
   set_long(::query_long()+"To the northeast an open door leads "+
      "into to the %^BLUE%^psionic crystals %^RESET%^shop.\n");
   set_exits(([
      "northwest" : ROOMS"crossways1",
      "southeast" : ROOMS"crossways3",
	  "northeast" : ROOMS"psion1",
   ]));
}