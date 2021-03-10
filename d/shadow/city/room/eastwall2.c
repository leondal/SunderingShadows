//Octothorpe (1/8/12)
//Shadow, East Wall Street 2

#include <std.h>
#include "../defs.h"
inherit INH+"eastwall";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"eastwall1",
      "southeast" : ROOMS"eastwall3",
   ]));
}