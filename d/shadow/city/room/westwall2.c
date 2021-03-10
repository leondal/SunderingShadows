//Octothorpe (1/21/12)
//Shadow, West Wall 2

#include <std.h>
#include "../defs.h"
inherit INH+"westwall";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"westwall1",
      "southeast" : ROOMS"westwall3",
   ]));
}