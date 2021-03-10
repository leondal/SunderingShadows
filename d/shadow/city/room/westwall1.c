//Octothorpe (1/21/12)
//Shadow, West Wall 1

#include <std.h>
#include "../defs.h"
inherit INH+"westwall";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"westcross",
      "southeast" : ROOMS"westwall2",
   ]));
}