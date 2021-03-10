//Octothorpe (1/8/12)
//Shadow, Kathmared Street 2

#include <std.h>
#include "../defs.h"
inherit INH+"kathmared";

void create(){
   ::create();
   set_long(::query_long()+"To the southeast an open door leads "+
      "into the %^MAGENTA%^psionic portal %^RESET%^shop.\n");
   set_exits(([
      "northeast" : ROOMS"kathmared3",
      "southwest" : ROOMS"kathmared1",
      "southeast" : ROOMS"psion2"
   ]));
}