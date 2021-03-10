//Octothorpe (1/8/12)
//Shadow, East Wall Street 4

#include <std.h>
#include "../defs.h"
inherit INH+"eastwall";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"eastwall3",
      "southeast" : ROOMS"eastwall5",
   ]));
}