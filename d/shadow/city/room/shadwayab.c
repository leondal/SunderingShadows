//Octothorpe (1/8/12)
//Shadow, Shadow Way AB

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"shadwaya",
      "east" : ROOMS"shadwayb",
   ]));
}