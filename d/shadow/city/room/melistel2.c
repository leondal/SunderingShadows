//Octothorpe (1/3/12)
//Shadow, Melistel Avenue 2

#include <std.h>
#include "../defs.h"
inherit INH+"melistel";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"melistel3",
      "south" : ROOMS"melistel1",
   ]));   
}
