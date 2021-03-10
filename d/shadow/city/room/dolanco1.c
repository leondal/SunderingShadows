//Octothorpe (1/22/12)
//Shadow, Dolanco Street 1

#include <std.h>
#include "../defs.h"
inherit INH+"dolanco";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"melistelb",
      "east" : ROOMS"dolanco2",
   ]));
}