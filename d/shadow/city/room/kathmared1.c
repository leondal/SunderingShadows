//Octothorpe (1/8/12)
//Shadow, Kathmared Street 1

#include <std.h>
#include "../defs.h"
inherit INH+"kathmared";

void create(){
   ::create();
   set_long(::query_long()+"To the southeast an open door leads "+
      "into a %^MAGENTA%^psionic crystal %^RESET%^shop.\n");
   set_exits(([
      "northeast" : ROOMS"kathmared2",
      "southwest" : ROOMS"crossways3",
      "southeast" : ROOMS"psion1"
   ]));
}