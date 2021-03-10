//Octothorpe (1/22/12)
//Shadow, Dolanco Street 4

#include <std.h>
#include "../defs.h"
inherit INH+"dolanco";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"shadwayb",
      "south" : ROOMS"dolanco3",
   ]));
}