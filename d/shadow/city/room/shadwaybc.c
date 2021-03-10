//Octothorpe (1/8/12)
//Shadow, Shadow Way BC

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"shadwayb",
      "east" : ROOMS"shadwayc",
   ]));
}