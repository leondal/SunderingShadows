//Octothorpe (1/8/12)
//Shadow, Crossways Road 5

#include <std.h>
#include "../defs.h"
inherit INH+"crossways";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"crossways4",
      "southeast" : ROOMS"shadwayc",
   ]));
}