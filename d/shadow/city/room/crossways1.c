//Octothorpe (1/5/12)
//Shadow, Crossways Road 1

#include <std.h>
#include "../defs.h"
inherit INH+"crossways";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"northcross",
      "southeast" : ROOMS"crossways2",
   ]));
}