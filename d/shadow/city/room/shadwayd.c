//Octothorpe (1/8/12)
//Shadow, Shadow Way D

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"shadwayc",
      "east" : ROOMS"eastcross",
   ]));
}