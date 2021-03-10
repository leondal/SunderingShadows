//Octothorpe (1/8/12)
//Shadow, Kathmared Street 3

#include <std.h>
#include "../defs.h"
inherit INH+"kathmared";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"eastwall3",
      "southwest" : ROOMS"kathmared2",
   ]));
}