//Octothorpe (1/21/12)
//Shadow, West Wall 3

#include <std.h>
#include "../defs.h"
inherit INH+"westwall";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"westwall2",
      //"northeast" : ROOMS"",
      "southeast" : ROOMS"westwall4",
   ]));
}